# 【深入vue】为什么Vue3.0不再使用defineProperty实现数据监听？（修订版）


## 导 读

vue3.0中，响应式数据部分弃用了Object.defineProperty，使用Proxy来代替它。本文将主要通过以下方面来分析为什么vue选择弃用Object.defineProperty。

1. Object.defineProperty真的无法监测数组下标的变化吗？

2. 分析vue2.x中对数组Observe部分源码

3. 对比Object.defineProperty和Proxy






一 无法监控到数组下标的变化？

在一些技术博客上看到过这样一种说法，认为 Object.defineProperty 有一个缺陷是无法监听数组变化：

无法监控到数组下标的变化，导致直接通过数组的下标给数组设置值，不能实时响应。所以vue才设置了7个变异数组（push、pop、shift、unshift、splice、sort、reverse）的 hack 方法来解决问题。
Object.defineProperty的第一个缺陷,无法监听数组变化。 然而Vue的文档提到了Vue是可以检测到数组变化的，但是只有以下八种方法,vm.items[indexOfItem] = newValue这种是无法检测的。

这种说法是有问题的，事实上，Object.defineProperty 本身是可以监控到数组下标的变化的，只是在 Vue 的实现中，从性能/体验的性价比考虑，放弃了这个特性。

下面我们通过一个例子来为 Object.defineProperty 正名：

function defineReactive(data, key, value) {
  Object.defineProperty(data, key, {
    enumerable: true,
    configurable: true,
     get: function defineGet() {
      console.log(`get key: ${key} value: ${value}`)
      return value
    },
     set: function defineSet(newVal) {
      console.log(`set key: ${key} value: ${newVal}`)
      value = newVal
    }
  })
}

function observe(data) {
  Object.keys(data).forEach(function(key) {
    defineReactive(data, key, data[key])
  })
}

let arr = [1, 2, 3]
observe(arr)

上面代码对数组arr的每个属性通过 Object.defineProperty 进行劫持，下面我们对数组arr进行操作，看看哪些行为会触发数组的 getter 和 setter 方法。

1. 通过下标获取某个元素和修改某个元素的值



可以看到，通过下标获取某个元素会触发 getter 方法, 设置某个值会触发 setter 方法。

接下来，我们再试一下数组的一些操作方法，看看是否会触发。

2. 数组的 push 方法



push 并未触发 setter 和 getter 方法，数组的下标可以看做是对象中的 key ，这里push 之后相当于增加了下索引为3的元素，但是并未对新的下标进行 observe ，所以不会触发。

3.数组的 unshift 方法



我擦，发生了什么？

 unshift 操作会导致原来索引为0，1，2，3的值发生变化，这就需要将原来索引为0，1，2，3的值取出来，然后重新赋值，所以取值的过程触发了 getter ，赋值时触发了 setter 。

下面我们尝试通过索引获取一下对应的元素：



只有索引为0，1，2的属性才会触发 getter 。

这里我们可以对比对象来看，arr数组初始值为[1, 2, 3]，即只对索引为0，1，2执行了 observe 方法，所以无论后来数组的长度发生怎样的变化，依然只有索引为0，1，2的元素发生变化才会触发，其他的新增索引，就相当于对象中新增的属性，需要再手动 observe 才可以。

4. 数组的 pop 方法



当移除的元素为引用为2的元素时，会触发 getter 。



删除了索引为2的元素后，再去修改或获取它的值时，不会再触发 setter 和 getter 。

这和对象的处理是同样的，数组的索引被删除后，就相当于对象的属性被删除一样，不会再去触发 observe。

到这里，我们可以简单的总结一下结论。

Object.defineProperty 在数组中的表现和在对象中的表现是一致的，数组的索引就可以看做是对象中的 key。

1. 通过索引访问或设置对应元素的值时，可以触发 getter 和 setter 方法
2. 通过 push 或 unshift 会增加索引，对于新增加的属性，需要再手动初始化才能被observe。
3. 通过 pop 或 shift 删除元素，会删除并更新索引，也会触发 setter 和 getter 方法。
所以，Object.defineProperty 是有监控数组下标变化的能力的，只是vue2.x放弃了这个特性。


二  vue对数组的observe做了哪些处理？

vue的 Observer 类定义在 core/observer/index.js 中



可以看到，vue的 Observer 对数组做了单独的处理。




hasProto 是判断数组的实例是否有 __proto__ 属性，如果有 __proto__ 属性就会执行 protoAugment 方法，将 arrayMethods 重写到原型上。 hasProto 定义如下。



arrayMethods 是对数组的方法进行重写，定义在 core/observer/array.js 中, 下面是这部分源码的分析。

/*
 * not type checking this file because flow doesn't play well with
 * dynamically accessing methods on Array prototype
 */

import { def } from '../util/index'

// 复制数组构造函数的原型，Array.prototype也是一个数组。
const arrayProto = Array.prototype
// 创建对象，对象的__proto__指向arrayProto，所以arrayMethods的__proto__包含数组的所有方法。
export const arrayMethods = Object.create(arrayProto)

// 下面的数组是要进行重写的方法
const methodsToPatch = [
  'push',
  'pop',
  'shift',
  'unshift',
  'splice',
  'sort',
  'reverse'
]

/**
 * Intercept mutating methods and emit events
 */
// 遍历methodsToPatch数组，对其中的方法进行重写
methodsToPatch.forEach(function (method) {
  // cache original method
  const original = arrayProto[method]
  // def方法定义在lang.js文件中，是通过object.defineProperty对属性进行重新定义。
  // 即在arrayMethods中找到我们要重写的方法，对其进行重新定义
  def(arrayMethods, method, function mutator (...args) {
    const result = original.apply(this, args)
    const ob = this.__ob__
    let inserted
    switch (method) {
      // 上面已经分析过，对于push，unshift会新增索引，所以需要手动observe
      case 'push':
      case 'unshift':
        inserted = args
        break
      // splice方法，如果传入了第三个参数，也会有新增索引，所以也需要手动observe
      case 'splice':
        inserted = args.slice(2)
        break
    }
    // push，unshift，splice三个方法触发后，在这里手动observe，其他方法的变更会在当前的索引上进行更新，所以不需要再执行ob.observeArray
    if (inserted) ob.observeArray(inserted)
    // notify change
    ob.dep.notify()
    return result
  })
})


三 Object.defineProperty VS Proxy

上面已经知道 Object.defineProperty 对数组和对象的表现是一致的，那么它和 Proxy 对比存在哪些优缺点呢？

1. Object.defineProperty只能劫持对象的属性，而Proxy是直接代理对象。

由于 Object.defineProperty 只能对属性进行劫持，需要遍历对象的每个属性，如果属性值也是对象，则需要深度遍历。而 Proxy 直接代理对象，不需要遍历操作。

2. Object.defineProperty对新增属性需要手动进行Observe。

由于 Object.defineProperty 劫持的是对象的属性，所以新增属性时，需要重新遍历对象，对其新增属性再使用 Object.defineProperty 进行劫持。

也正是因为这个原因，使用vue给 data 中的数组或对象新增属性时，需要使用 vm.$set 才能保证新增的属性也是响应式的。

下面看一下vue的 set 方法是如何实现的，set方法定义在 core/observer/index.js ，下面是核心代码。

/**
 * Set a property on an object. Adds the new property and
 * triggers change notification if the property doesn't
 * already exist.
 */
export function set (target: Array<any> | Object, key: any, val: any): any {
  // 如果target是数组，且key是有效的数组索引，会调用数组的splice方法，
  // 我们上面说过，数组的splice方法会被重写，重写的方法中会手动Observe
  // 所以vue的set方法，对于数组，就是直接调用重写splice方法
  if (Array.isArray(target) && isValidArrayIndex(key)) {
    target.length = Math.max(target.length, key)
    target.splice(key, 1, val)
    return val
  }
  // 对于对象，如果key本来就是对象中的属性，直接修改值就可以触发更新
  if (key in target && !(key in Object.prototype)) {
    target[key] = val
    return val
  }
  // vue的响应式对象中都会添加了__ob__属性，所以可以根据是否有__ob__属性判断是否为响应式对象
  const ob = (target: any).__ob__
  // 如果不是响应式对象，直接赋值
  if (!ob) {
    target[key] = val
    return val
  }
  // 调用defineReactive给数据添加了 getter 和 setter，
  // 所以vue的set方法，对于响应式的对象，就会调用defineReactive重新定义响应式对象，defineReactive 函数
  defineReactive(ob.value, key, val)
  ob.dep.notify()
  return val
}

在 set 方法中，对 target 是数组和对象做了分别的处理，target 是数组时，会调用重写过的 splice 方法进行手动 Observe 。

对于对象，如果 key 本来就是对象的属性，则直接修改值触发更新，否则调用 defineReactive 方法重新定义响应式对象。

如果采用 proxy 实现，Proxy 通过 set(target, propKey, value, receiver) 拦截对象属性的设置，是可以拦截到对象的新增属性的。



不止如此，Proxy 对数组的方法也可以监测到，不需要像上面vue2.x源码中那样进行 hack。



完美！！！

3. Proxy支持13种拦截操作，这是defineProperty所不具有的

get(target, propKey, receiver)：拦截对象属性的读取，比如proxy.foo和proxy['foo']。

set(target, propKey, value, receiver)：拦截对象属性的设置，比如proxy.foo = v或proxy['foo'] = v，返回一个布尔值。

has(target, propKey)：拦截propKey in proxy的操作，返回一个布尔值。

deleteProperty(target, propKey)：拦截delete proxy[propKey]的操作，返回一个布尔值。

ownKeys(target)：拦截Object.getOwnPropertyNames(proxy)、Object.getOwnPropertySymbols(proxy)、Object.keys(proxy)、for...in循环，返回一个数组。该方法返回目标对象所有自身的属性的属性名，而Object.keys()的返回结果仅包括目标对象自身的可遍历属性。

getOwnPropertyDescriptor(target, propKey)：拦截Object.getOwnPropertyDescriptor(proxy, propKey)，返回属性的描述对象。

defineProperty(target, propKey, propDesc)：拦截Object.defineProperty(proxy, propKey, propDesc）、Object.defineProperties(proxy, propDescs)，返回一个布尔值。

preventExtensions(target)：拦截Object.preventExtensions(proxy)，返回一个布尔值。

getPrototypeOf(target)：拦截Object.getPrototypeOf(proxy)，返回一个对象。

isExtensible(target)：拦截Object.isExtensible(proxy)，返回一个布尔值。

setPrototypeOf(target, proto)：拦截Object.setPrototypeOf(proxy, proto)，返回一个布尔值。如果目标对象是函数，那么还有两种额外操作可以拦截。

apply(target, object, args)：拦截 Proxy 实例作为函数调用的操作，比如proxy(...args)、proxy.call(object, ...args)、proxy.apply(...)。

construct(target, args)：拦截 Proxy 实例作为构造函数调用的操作，比如new proxy(...args)。


4. 新标准性能红利

Proxy 作为新标准，长远来看，JS引擎会继续优化 Proxy，但 getter 和 setter 基本不会再有针对性优化。

5. Proxy兼容性差



可以看到，Proxy对于IE浏览器来说简直是灾难。

并且目前并没有一个完整支持 Proxy 所有拦截方法的Polyfill方案，有一个google编写的 proxy-polyfill （https://github.com/GoogleChrome/proxy-polyfill）也只支持了 get，set，apply，construct 四种拦截，可以支持到IE9+和Safari 6+。


四 总结

1. Object.defineProperty 对数组和对象的表现一直，并非不能监控数组下标的变化，vue2.x中无法通过数组索引来实现响应式数据的自动更新是vue本身的设计导致的，不是 defineProperty 的锅。

2. Object.defineProperty 和 Proxy 本质差别是，defineProperty 只能对属性进行劫持，所以出现了需要递归遍历，新增属性需要手动 Observe 的问题。

3. Proxy 作为新标准，浏览器厂商势必会对其进行持续优化，但它的兼容性也是块硬伤，并且目前还没有完整的polyfill方案。


参考

https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Proxy

https://segmentfault.com/a/1190000015783546

https://zhuanlan.zhihu.com/p/35080324

http://es6.ruanyifeng.com/#docs/proxy
