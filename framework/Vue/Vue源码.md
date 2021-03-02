# vue 源码分析

### vue 源码可以分为两部分，页面渲染，实现数据的响应式

-   为了实现数据的响应式，`Vue` 劫持了数据的 `get set value ` 等属性

### 数据劫持

-   其中数据劫持 `Vue 2` 主要通过 `defineProperty` 实现, `Vue 3 ` 主要通过 `Es6 Proxy` 实现

#### Object.defineProperty

-   `javascript` 中*引用类型* 中获取属性会触发 `get` 方法，设置属性的值会触发 `set` 方法。基于这点我们就能在触发这些操作中对数据进行额外的处理。

```javascript
const descriptor = {
    configurable: false, // 属性是否可配置（delete 操作）
    enumerable: false, // 该属性是否可枚举
    get: () => {
        // 获取 target[key] 时调用的方法
    },
    set: (val) => {
        // target[key] = val 时调用的方法
    },
};

const descriptor2 = {
    // value 属性可以是 对象 数值 函数
    value: (arg) => {
        // 可以劫持原型方法
    },
};

Object.defineProperty(target, key, descriptor);
// descriptor 为一个配置对象
// target 为需要劫持的引用类型数据
// key 为被劫持的某引用类型上的属性（键名）
```

-   **注意：** `value` 描述符不能与 `get set` 同时出现

#### Proxy

-   Es6 中的新 API 可以完全替代 defineProperty 的工作，使数据的劫持更加简单

```javascript
const handler = {
    get: (target, key) => {
        // 与defineProperty 不同，要被劫持的属性在这里进行设置
    },

    set: (target, key, value) => {
        // 同时 与 defineProperty 存在差异
    },
};

const proxy = new Proxy(target, handler);
// target 为被需要进行数据劫持的引用类型
// handler 为配置对象
```

### 发布订阅模式

-   发布订阅模式也可以叫做观察者模式，他定义对象间的一种一对多的依赖关系，当一个对象的状态发生变化，所有依赖他的对象都将得到通知。在 js 开发中，一般用事件模型来代替传统的 发布-订阅模式。 **可以实现对象间的解耦**。

-   谁是发布者，谁是订阅者？

    -   发布者要有一个缓存列表，用于存放回调函数，用于通知订阅者

    -   `vue` 中 `Dep` 类用于实例化一个发布者，而订阅者实际上就是 `vue` 的 `dom` 渲染方法，由 `Watcher` 类实例化生成。

    -   `Vue` 通过观察者模式实现数据与页面之间的的响应式变化（当数据更新，触发页面的更新)。

#### EventEmitter

-   设置两个类 `Dep`、 `Watcher` 分别用于生成发布者，与订阅者。

```javascript
let id = 0
// 事件存储
// Dep 用于对 Watcher 进行管理
class Dep{
	constructor(){
		this.id = ++id
		this.subs = []
	}

	// 收集订阅者（这里就是指收集 Watcher 实例对象）
	addSub(sub){
		this.subs.push(sub)
	}

	// 通知订阅者 （这里就是指触发 Watcher 实例对象上定义的回调函数）
	notify(){
		let subs = this.subs.slice()

		// 排序
		subs = subs.sort((a, b) => {
			a.id - b.id
		})
		subs.forEach(sub => {
			// Watcher 实例对象上的 update 方法用于执行指定的操作
			sub.update()
		})
	}
}

// 用于实例化生成指定的 回调方法以及想要的操作
class Watcher{
	constructor(vm, expressFn){
		// 实例化时指定想要的操作，即 expressFn 回调函数，以及回调函数所必须的作用域（vm） 等参数
		this.vm = vm
	    this.expressFn = expressFn
	}

	update(){
		// 在特定作用域下执行回调函数
		this.expressFn.call(this.vm)
	}
}

function defineReaction(){
	//
	const dep = new Dep()

	// 添加事件
	const watcher = new Watcher(
		//...
		vm: null,
		expressFn: () => {
			console.log('数据更新了')
		}
	)

	dep.addSub(watcher)

	dep.notify()
}

defineReaction()
```

### 数据的劫持

-   `Vue` 实例化时需要传入一个配置对象，该对象中包含页面的挂载的根节点，以及数据对象（`data、 computed、 watch、 methods...`）

-   `get set `

```javascript
class Vue {
    constructor(options) {
        this.$data = options.data;

        this.initState();
    }

    initState() {
        // 用于实现 Data 对象的劫持
        for (let key in this.$data) {
            Object.defineProperty(this, key, {
                get: () => {
                    return this.$data[key];
                },
                set: (newVal) => {
                    this.$data[key] = newVal;
                },
            });
        }
    }
}
const options = {
    el: "#app",
    data: {
        msg: "PB",
    },
};
const vm = new Vue(options);

console.log(vm.msg);
// 'PB'
```

### 依赖收集

-   依赖收集是指将页面所使用到的数据收集到观察者中，用于实现数据更新==> 视图更新的过程

-   在什么时机收集依赖？

    -   当数据被使用时才有被观察的必要，即当 获取数据时进行依赖收集比较合理。

    -   因此在进行数据劫持的`get`方法中进行依赖收集

-   **注意：只有引用类型的数据才能被劫持**

-   **由于数组的一些方法不会改变数组，因此不会触发观者者，因此需要通过 `value` 进行数组的方法劫持**

```javascript
// 需要劫持的方法
const methodsToPatch = [
    "push",
    "pop",
    "shift",
    "unshift",
    "splice",
    "sort",
    "reverse",
];

// 数组原型（用于实现数组方法的默认行为）
const arrayProto = Array.prototype;

// 劫持后的方法
const arrayMethods = Object.create(arrayProto);

methodsToPatch.forEach((method) => {
    // 用于实现数组方法的默认行为
    let original = arrayProto[method];
    Object.defineProperty(arrayMethods, method, {
        value: (...args) => {
            const result = original.apply(this, args);

            let inserted;
            // 如果是插入数组的新值也需要进行依赖收集
            switch (method) {
                case "push":
                case "unshift":
                    inserted = args;
                    break;
                case "splice":
                    inserted = args.slice(2);
                    break;
            }
            if (inserted) {
                console.log("数组数据插入");
            }
            // 数据变化，通知观察者
            console.log("数组数据变化了");
            // 返回数组方法的默认返回值
            return result;
        },
    });
});

// 然后再通过 value 方法拦截数组上
function copyAugment(target, src, keys) {
    for (let i = 0, l = keys.length; i < l; i++) {
        const key = keys[i];
        Object.defineProperty(target, key, {
            value: src[key],
        });
    }
}
const arr = [1];
copyAugment(arr, arrayMethods, methodsToPatch);
arr.push(2);
```

-   依赖收集

```javascript
// 定义一个类用于实现依赖收集
class Observe{
	constructor(value){
		this.value = value
		// 挂载一个发布者实例对象，用于通知相应的观察者
		this.dep = new Dep()
		// 将该对象挂载到被收集的数据对象上，便于扩展操作
		value.__ob__ = this

		// 依赖收集
		if(Array.isArray(value)){
			// 数组要进行遍历
			for(let i = 0; l = value.length; i< l; i++){
				observe(value[i])
			}

			// 进行数组方法的劫持
			copyAugment(value, arrayMethods, methodsToPatch)
		}else{
			this.walk(value)
		}
	}

	walk(value){
		for(let key in value){
			defineReactive(value, key)
		}
	}

}

// 真正的依赖收集方法
function defineReactive(target, key){
	const dep = new Dep()

	const property = Object.getOwnPropertyDescriptor(target, key)

	// 由于数据劫持，因此需要执行我们设定的 target 上的 get set 操作
	const getter = property.get
	const setter = property.set

	Object.defineProperty(target, key, {
		get: ()=>{
			// 在这里进行依赖收集
			dep.addSub()

			return getter.call(this)
		},
		set: newVal=>{
			// 数据更新触发 观察者
			dep.notify()

			return setter.call(this, newVal)
		}
	})
}

// 定义一个方法用于依赖收集
function observe(value){
	let ob

	// 判断数据类型
	if(value === null || typeof obj !== 'object'){
		return
	}
	// 已经收集过的不在收集
	if(value.__ob__){
		ob = value.__ob__
	}else{
		ob = new Observe(value)
	}
	return ob
}
```

### 在什么时机创建订阅者 watcher?

-   当数据被使用的时候，创建订阅者才有意义，而数据被指用的时候就是数据被渲染的时候，因此在数据被渲染到页面之前创建一个订阅者是比较合理的,还有一个原因是，在数据被渲染的时候，我们才能知道，数据更新后应该进行什么样的操作才能刷新成我们想要的页面

    -   `Vue` 在 `mountComponent` 方法中实例化一个 订阅者

```javascript
// updateComponent  为页面刷新方法

new Watcher(
    vm,
    updateComponent,
    noop,
    {
        before() {
            if (vm._isMounted && !vm._isDestroyed) {
                callHook(vm, "beforeUpdate");
            }
        },
    },
    true /* isRenderWatcher */
);
```

## 页面的渲染

-   `Vue` 通过什么策略将数据渲染到页面上的，

### **patch**

-   将 vnode 渲染到真实 dom 上

### \_render

-   生成一个 vnode
