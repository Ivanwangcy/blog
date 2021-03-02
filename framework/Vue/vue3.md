# Vue 3.0

## 前言

    Vue3.0 正式版已经发布，与 Vue2 相比，性能有较大的提升。 Vue3 通过标识缓存静态节点的方式大大提升了渲染速度，同时将reactive render ref 等方法分离成独立的工具库，使得这些API能够作为工具方法独立使用，为解决数据与业务逻辑的分离痛点，新增 Composition API setup。

    接下来将抽时间对 Vue3.0 源码进行简要的分析，希望这次能够比 2 更加有条理，更加完善

参考：<https://v3.cn.vuejs.org/guide/migration/introduction.html#%E6%A6%82%E8%A7%88>

## reactive

-   将引用类型的数据转换为 proxy 实例，实现数据的劫持，其中 Vue3 中可以劫持的引用类型包括以下几种类型，<font color="red">与 2 相比增加了 集合类型 的数据类型</font>

```js
  const enum TargetType {
    INVALID = 0, // 不可被代理的， 非引用类型
    COMMON = 1, // Object  Array
    COLLECTION = 2 // ES6 集合  Map Set WeakMap WeakSet
  }

  function targetTypeMap(rawType: string) {
    switch (rawType) {
      case 'Object':
      case 'Array':
        return TargetType.COMMON
      case 'Map':
      case 'Set':
      case 'WeakMap':
      case 'WeakSet':
        return TargetType.COLLECTION
      default:
        return TargetType.INVALID
    }
  }
```

-   数据代理的实现方法如下，主要是通过 ES6 中的 Proxy 等 API 对 defineProperty 进行了重构，整体思路是没有太大变化，

```javascript
function createReactiveObject(
    target: Target,
    isReadonly: boolean,
    baseHandlers: ProxyHandler<any>, // Object Array 的代理的配置对象
    collectionHandlers: ProxyHandler<any> // Es6 中集合类型的数据代理配置对象 Map Set WeakMap WeakSet
) {
    if (!isObject(target)) {
        return target;
    }
    // 该对象是一个代理后的对象 Proxy 实例
    // 校验 数据只读性 与函数入参是否一致
    if (
        target[ReactiveFlags.RAW] &&
        !(isReadonly && target[ReactiveFlags.IS_REACTIVE])
    ) {
        return target;
    }
    // 在缓存中查找该对象是否已经被代理
    // readonlyMap  reactiveMap  为两个 weakMap 对象
    const proxyMap = isReadonly ? readonlyMap : reactiveMap;
    const existingProxy = proxyMap.get(target);
    if (existingProxy) {
        return existingProxy;
    }
    // 判断数据类型是否在 允许类型内
    const targetType = getTargetType(target);
    if (targetType === TargetType.INVALID) {
        return target;
    }
    // target 数据的代理 ES6 构造函数 Proxy
    // new Proxy(target, {
    //   get: function get(target, key){},
    //   set: function set(target, key, value){},
    // })
    const proxy = new Proxy(
        target,
        // 区分集合 与 基本数据类型
        targetType === TargetType.COLLECTION ? collectionHandlers : baseHandlers
    );

    // 缓存已经代理过的数据
    proxyMap.set(target, proxy);
    return proxy;
}
```

-   使用 Proxy 使得代码更加简洁

-   **注意**： Vue3 中使用 weakMap 对数据进行缓存有以下两个原因

    -   weakMap 与 Map 的不同： WeakMap 只接受 对象作为键名（null 除外）； weakMap 键名指向的对象不计入垃圾回收机制; （ruanyifeng）

    -   基于以上两点不同，可以得到使用 weakMap 有以下优势： 便于数据的存储与获取，直接将该对象作为键名，proxy 实例作为值即可； 当该对象没有被页面使用后，可被自动回收，不会造成内存泄漏情况。

-   观察 `createReactiveObject` 方法，其中 Proxy 构造函数需要的 set get 方法已经被独立拆分出来，使得该方法扩展性较强，这也是函数柯里化的常见应用。 其中 普通对象的 handler 与 ES6 中新的数据类型的 handler 存在差异

```javascript
export function reactive(target: object) {
  // target 是 readonly 的直接返回，不进行 observe
  if (target && (target as Target)[ReactiveFlags.IS_READONLY]) {
    return target
  }
  return createReactiveObject(
    target,
    false, // isReadonly
    // 普通引用类型的 handler 对象，传递给 Proxy 构造方法
    mutableHandlers,
    // 集合类型的数据处理  set map weakSet weakMap
    mutableCollectionHandlers
  )
}
```

-   reactive 用于实现一个引用类型数据的 代理，

    -   Proxy 可以劫持的对象属性与方法包括 get set has deleteProperty ownKeys 等 13 种拦截操作

    -   has 拦截 `property in proxy` 操作

    -   deleteProperty 拦截 delete proxy[key] 操作，返回一个布尔值

    -   ownKeys(target) 返回该对象所有自身属性的属性名，返回一个数组

-   因此其中的 `mutableHandlers` 参数配置如下

```javascript
export const mutableHandlers: ProxyHandler<object> = {
    get,
    set,
    deleteProperty,
    has,
    ownKeys,
};
```

-   而对于集合类型的数据 Vue3 只劫持了 getter 方法, 拦截操作 `mutableCollectionHandlers` 如下

```javascript
export const mutableCollectionHandlers: ProxyHandler<CollectionTypes> = {
    get: createInstrumentationGetter(false, false),
};
```

-   接下来就要看看 vue3 在拦截操作中对数据做了怎样的处理，

-   vue3 中 根据该对象是否是只读，是否是浅代理为 getter setter handler 定义了工厂函数用于生成该 handler

    -   get: const get = /_#**PURE**_/ createGetter()

    -   set: const set = /_#**PURE**_/ createSetter()

-   `createGetter` 方法如下，在阅读该方法前还要先看几个枚举的定义

```javascript
// 要在在 proxy 实例上挂载的属性
export const enum ReactiveFlags {
  SKIP = '__v_skip',
  IS_REACTIVE = '__v_isReactive',
  IS_READONLY = '__v_isReadonly',
  RAW = '__v_raw'
}
```

-   接下来就是正题，生成一个 getter 方法

```javascript
function createGetter(isReadonly = false, shallow = false) {
  // 返回一个 get 方法
  return function get(target: Target, key: string | symbol, receiver: object) {
  	// 第一步就是要将 __v_isReactive 属性挂载到 proxy 实例上，用于标志这个对象是否一个代理过的 proxy 实例
    if (key === ReactiveFlags.IS_REACTIVE) {
      return !isReadonly
    }
    // 将 __v_isReadonly 属性挂载到 该 proxy 实例上，用于标志该 实例是否一个 readonly 的代理对象
    else if (key === ReactiveFlags.IS_READONLY) {
      return isReadonly
    }

    // __v_raw 将要被代理的 引用类型数据挂载到该属性下，用于标志该 proxy 实例是否代理过引用类型数据，同时用于从 proxy 实例上获取源是对象
    else if (
      key === ReactiveFlags.RAW &&
      receiver === (isReadonly ? readonlyMap : reactiveMap).get(target)
    ) {
      return target
    }

    // 数据类型判断
    const targetIsArray = isArray(target)
    // Reflect.get 当 key 属性 部署了 getter 方法，则其中的 this 指向 receiver
    // const Obj = {
    //   get val(){
    //     return this.name
    //   }
    // }

    // arrayInstrumentations 代理了数组上的方法： includex indexOf lastIndexOf; push pop shift unshift splice;
    if (targetIsArray && hasOwn(arrayInstrumentations, key)) {
      return Reflect.get(arrayInstrumentations, key, receiver)
    }

    // 获取对象上的值
    const res = Reflect.get(target, key, receiver)

    if (
      isSymbol(key)
        ? builtInSymbols.has(key as symbol)
        : key === `__proto__` || key === `__v_isRef`
    ) {
      return res
    }

    // 对非只读的数据进行依赖收集
    if (!isReadonly) {
      track(target, TrackOpTypes.GET, key)
    }

    //  浅数据代理 直接返回该数据，不再进行递归的 代理
    if (shallow) {
      return res
    }

    //  如果获取到的值 已经通过 ref 代理过，直接返回该值  （ref 之后讲解）
    if (isRef(res)) {
      // ref unwrapping - does not apply for Array + integer key.
      const shouldUnwrap = !targetIsArray || !isIntegerKey(key)
      return shouldUnwrap ? res.value : res
    }

    if (isObject(res)) {
      // 递归的进行 数据劫持
      return isReadonly ? readonly(res) : reactive(res)
    }
    // 不是引用类型直接返回
    return res
  }
}
```

-   以上就是 get 方法的劫持过程，其中数组方法的劫持 `arrayInstrumentations` 分为两部分，

    -   数组中的值不会发生变化: `[includes, indexOf, lastIndexOf ]`，

    ```javascript
    ;(['includes', 'indexOf', 'lastIndexOf'] as const).forEach(key => {
    	// 先获取 数组原型上的方法
      const method = Array.prototype[key] as any
      arrayInstrumentations[key] = function(this: unknown[], ...args: unknown[]) {
      // 获取 数组代理前的原始数据
        const arr = toRaw(this)
        for (let i = 0, l = this.length; i < l; i++) {
          track(arr, TrackOpTypes.GET, i + '') // 依赖收集
        }
        // 执行数组方法本身的功能
        const res = method.apply(arr, args)
        if (res === -1 || res === false) {
          // if that didn't work, run it again using raw values.
          return method.apply(arr, args.map(toRaw))
        } else {
          return res
        }
      }
    })
    ```

    -   会改变数组中值的方法 `[ pop, push, shift, unshift, splice ]`

    ```javascript
    ;(['push', 'pop', 'shift', 'unshift', 'splice'] as const).forEach(key => {
      const method = Array.prototype[key] as any
      arrayInstrumentations[key] = function(this: unknown[], ...args: unknown[]) {
        pauseTracking()
        const res = method.apply(this, args)
        resetTracking()
        return res
      }
    })
    ```

-   createSetter 方法 用于生成一个 set 方法

```javascript
function createSetter(shallow = false) {
  // 返回一个 setter 方法
  return function set(
    target: object,
    key: string | symbol,
    value: unknown,
    receiver: object
  ): boolean {
    // 先缓存旧值
    const oldValue = (target as any)[key]
    if (!shallow) {
      // 获取 该 Proxy 实例代理的 原始对象
      value = toRaw(value)
      // 旧的值 经过 ref ，则将该值的 value 属性更新
      if (!isArray(target) && isRef(oldValue) && !isRef(value)) {
        oldValue.value = value
        return true
      }
    }
    // 浅代理的情况下 不用对这个属性做任何处理，
    else {
    }

    // 校验 key 的合法性，数组不能超长，对象要存在
    const hadKey =
      isArray(target) && isIntegerKey(key)
        ? Number(key) < target.length
        : hasOwn(target, key)

    // Reflect.set 设置对象属性，
    const result = Reflect.set(target, key, value, receiver)
    // don't trigger if target is something up in the prototype chain of original
    if (target === toRaw(receiver)) {
      if (!hadKey) {
        // 新添加的属性 触发 add 操作，
        trigger(target, TriggerOpTypes.ADD, key, value)
      } else if (hasChanged(value, oldValue)) {
      	// 数据更新 触发 set 操作
        trigger(target, TriggerOpTypes.SET, key, value, oldValue)
      }
    }
    return result
  }
}
```

-   经过以上对 setter getter 方法的分析，能够得到，在进行数据获取时，对数据进行代理，并进行依赖收集，添加观察者（track），在数据添加或者更新时对数据进行更新，同时触发(trigger)观察者

-   <font color="red">因此 setter 的主要功能就是 触发观察者，getter 的主要功能就是进行依赖收集添加观察者</font>

#### effect

-   vue3 将发布订阅放在 effect 中，用于实现 发布订阅模式

-   其中两个重要的方法为 track: 依赖收集，添加订阅者, trigger：发布消息，触发订阅者

-   track 方法如下：

    -   其中 targetMap 为一个 weakMap 用于缓存所有被代理数据的订阅者集合

    -   dep 为一个 Set 集合用于缓存被代理数据指定属性的订阅者(副作用方法)

```javascript
// 依赖收集
export function track(target: object, type: TrackOpTypes, key: unknown) {
    // 判断是否能进行依赖收集，不允许； 不存在订阅者，请思考什么时机才能不直接 return?
    if (!shouldTrack || activeEffect === undefined) {
        return;
    }
    // 获取该对象的 订阅者 Map
    let depsMap = targetMap.get(target);
    // 该对象不存在订阅者旧新建一个订阅者 并缓存 到集合
    if (!depsMap) {
        targetMap.set(target, (depsMap = new Map()));
    }

    // 获取该对象订阅者 集合Map 指定 key 的订阅者
    let dep = depsMap.get(key);
    // 该 key 不存在订阅者 新建一个订阅者 并缓存
    if (!dep) {
        depsMap.set(key, (dep = new Set()));
    }
    // 该订阅者没有定义副作用，添加副作用
    if (!dep.has(activeEffect)) {
        dep.add(activeEffect);
        // 将订阅者 set 集合缓存到 副作用 对象上
        activeEffect.deps.push(dep);
        if (__DEV__ && activeEffect.options.onTrack) {
            activeEffect.options.onTrack({
                effect: activeEffect,
                target,
                type,
                key,
            });
        }
    }
}
```

-   trigger 方法如下

```javascript
export function trigger(
  target: object,
  type: TriggerOpTypes,
  key?: unknown,
  newValue?: unknown,
  oldValue?: unknown,
  oldTarget?: Map<unknown, unknown> | Set<unknown>
) {
  const depsMap = targetMap.get(target)
  // 没有经过收集 直接返回
  if (!depsMap) {
    return
  }

  // 定义一个集合 用于存储副作用对象
  const effects = new Set<ReactiveEffect>()
  // 定义一个add 方法用于将新的 副作用对象 压入 集合中
  const add = (effectsToAdd: Set<ReactiveEffect> | undefined) => {
    if (effectsToAdd) {
      effectsToAdd.forEach(effect => {
        if (effect !== activeEffect || effect.allowRecurse) {
          effects.add(effect)
        }
      })
    }
  }


  // 根据不同的 数据操作类型 进行副作用收集

  // 1： 清除数据，收集所有的副作用方法到 effects
  if (type === TriggerOpTypes.CLEAR) {
    depsMap.forEach(add)
  }

  // 数组长度的变化
  else if (key === 'length' && isArray(target)) {
    depsMap.forEach((dep, key) => {
      if (key === 'length' || key >= (newValue as number)) {
        add(dep)
      }
    })
  }

  // 数据更新，数据添加 数据删除，将该数据下的副作用方法收集到 effects
  else {
    // schedule runs for SET | ADD | DELETE
    if (key !== void 0) {
      add(depsMap.get(key))
    }

    // also run for iteration key on ADD | DELETE | Map.SET
    switch (type) {
      case TriggerOpTypes.ADD:
        if (!isArray(target)) {
          add(depsMap.get(ITERATE_KEY))
          if (isMap(target)) {
            add(depsMap.get(MAP_KEY_ITERATE_KEY))
          }
        } else if (isIntegerKey(key)) {
          // new index added to array -> length changes
          add(depsMap.get('length'))
        }
        break
      case TriggerOpTypes.DELETE:
        if (!isArray(target)) {
          add(depsMap.get(ITERATE_KEY))
          if (isMap(target)) {
            add(depsMap.get(MAP_KEY_ITERATE_KEY))
          }
        }
        break
      case TriggerOpTypes.SET:
        if (isMap(target)) {
          add(depsMap.get(ITERATE_KEY))
        }
        break
    }
  }

  // 执行effects 中的副作用方法
  const run = (effect: ReactiveEffect) => {
    if (__DEV__ && effect.options.onTrigger) {
      effect.options.onTrigger({
        effect,
        target,
        key,
        type,
        newValue,
        oldValue,
        oldTarget
      })
    }
    if (effect.options.scheduler) {
      effect.options.scheduler(effect)
    } else {
      effect()
    }
  }

  effects.forEach(run)
}
```

-   到这里数据更新触发该数据对应的副作用方法已经结束，但是在 track 方法中存在一个判断, 由于 activeEffect 初始值是 undefined 因此目前为止，所有的数据都不会被 track, Vue3 是在什么时机才允许进行依赖收集的呢？

```javascript
if (!shouldTrack || activeEffect === undefined) {
    return;
}
```

-   **要解决这个疑问就要考虑一下 以上操作发生的时机，目前为止，当触发数据 getter 时才进行依赖收集，但是谁来触发 数据的 getter 操作呢? 答案是显而易见的，<font color="red">只有页面渲染时用到的数据才会触发数据的 getter 操作，因此 vue 是在该数据要被渲染时才允许依赖收集，否则不会触发 getter, 自然依赖收集也无从谈起; 同时也只有在数据渲染的时候我们才能知道这个数据应该有什么样的副作用方法（具体的渲染 DOM 方法）</font>**

#### render
