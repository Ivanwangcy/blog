# Webpack 插件 `Tapable` 应用与原理分析
`Tapable` 是什么？ Tapable是一个可以绑定和应用的插件库，也是是一个用于 webpack 的插件体系结构中的内部核心库。webpack 中有很多 Tapable 的实例类，它们都继承或者混合（mixin）自 Tapable，这些实例提供了各种事件钩子可以附加到自定义插件中。总之，Tapable 可以说是短小精湛。贯穿于 webpack 的每个角落。

## 首先看看 Webpack 官方的说明
Tapable是一个小型库，允许你添加和应用插件到一个 javascript 模块。 它可以被继承或混合到其他模块。 它类似于NodeJS 的 `EventEmitter` 类，专注于自定义事件的触发和执行。 但是，除此之外，Tapable 允许您通过回调参数访问事件的“发布者” 或 “生产者”。

### Tapable有四组成员函数：
- plugin(name:string, handler: function)：它允许自定义插件注册到 Tapable 实例的事件中，这类似于 EventEmitter 的 on() 方法 ，当信号/事件发生时，用于注册处理程序/监听器来执行某些操作。
- apply(...pluginInstances: (AnyPlugin|function)[])：AnyPlugin 应该是一个类（或者很少的情况下是对象）具有一个 apply 方法，或者是有一些注册代码的内部的一个函数。这个方法是应用到插件的定义，以便真正的事件监听器能够注册到 Tapable 实例的注册表中。
- applyPlugins*(name:string, ...)：该 Tapable 实例可以申请使用这些功能的特定哈希下的所有插件。这组方法像 EventEmitter 的 `emit()` 方法，控制事件触发时可以定位于各种策略。
- mixin(pt: Object)：一种简单的方法来扩展 Tapable 的原型进行混合而不是直接继承它。

### 不同的 applyPlugins* 方法包括以下功能示例：
- 插件可以连续运行。
- 插件可以并行运行。
- 插件可以一个接一个地运行，但是要从前一个插件（瀑布）获取输入。
- 插件可以异步运行。
- 在特定条件下退出插件的运行：也就是说，一旦一个插件返回非 undefined
，跳出运行流程并 return 该插件的返回。这听起来像 EventEmitter 的 `once()`，但是完全不同。

## Webpack 中应用 Tapalbe 的范例:
Webpack 的 Tapable 实例之一 [`Compiler`](https://webpack.js.org/api/compiler) 负责编译 webpack 配置对象并返回一个  `Compilation ` 实例。编译实例运行时，将创建所需的 bundles (捆绑包)。

`请参阅下面的简化版本，了解如何使用Tapable：`

**node_modules/webpack/lib/Compiler.js**
```js

var Tapable = require("tapable");

function Compiler() {
      //传入作用域，调用Tapable的构造函数
    Tapable.call(this);
}

//复制一份Tapable的原型
Compiler.prototype = Object.create(Tapable.prototype);
Compiler.prototype.constructor = Compiler;

```
现在在编译器上编写一个插件。  
**my-custom-plugin.js**

```js
function CustomPlugin() {}
CustomPlugin.prototype.apply = function(compiler) {
  compiler.plugin('emit', pluginFunction);
}
```

编译器在在其生命周期的适当位置执行插件  
**node_modules/webpack/lib/Compiler.js**

```js
this.apply*("emit",options) // will fetch all plugins under 'emit' name and run them.
```
## Tapable 的函数
**plugin**
```js
    void plugin(names: string|string[], handler: Function)
```
事件绑定函数，参数说明  
`names`: 需要监听的事件名称，可以传入事件名称集合（同时绑定多个事件），也可以传入单个事件名称  
`handler`: 事件的处理函数

**applyPlugins**
```js
    void applyPlugins(name: string, args: any...)
```
触发事件 `name` ，传入参数 `args` ，并行的调用所有注册在事件 `name` 上的处理函数

**applyPluginsWaterfall**
```js
    any applyPluginsWaterfall(name: string, init: any, args: any...)
```
触发事件 `name` ，串行的调用注册在事件 `name` 上的处理函数（先入先出），最先执行的处理函数传入 `init` 和 `args` ，后续的处理函数传入前一个处理函数的返回值和 `args` ，函数最终返回最后一个处理函数的返回结果

**applyPluginsAsync**
```
    void applyPluginsAsync(
        name: string,
        args: any...,
        callback: (err?: Error) -> void
    )
```
触发事件 `name` ，串行的调用注册在事件 `name` 上的处理函数（先入先出），倘若某一个处理函数报错，则执行传入的 `callback(err)` ，后续的处理函数将不被执行，否则最后一个处理函数调用 `callback `。

插件注册此类事件，处理函数需要调用 `callback` ，这样才能保证监听链的正确执行

> 参考 [Tapable中文文档](https://www.jianshu.com/p/c71393db6287)

## Tapable 的基本用法, 可以看出它采用了发布订阅模式，并且增加了多种处理机制
```js
const Tapable = require('tapable') // 导入库引用

let tapable = new Tapable()

// 0
tapable.plugin('options', (options) => {
  return options
})
// 1
tapable.plugin('options', (options) => {
  console.log(1, this.options)
  return {b: 2}
})

// 2
tapable.plugin('options', (options) => {
  console.log(2, this.options)
  return { c: 3 }
})

// 3
tapable.plugin('options', (options) => {
  console.log(3, this.options)
})

tapable.applyPlugins('options', {a: 1}) // 顺序执行，各自输出
// 1 { a: 1 }
// 2 { a: 1 }
// 3 { a: 1 }

tapable.applyPluginsWaterfall('options', {a: 1}) // 顺序执行，前一输出作为下一次输入
// 1 { a: 1 }
// 2 { b: 2 }
// 3 { c: 3 }

tapable.applyPluginsBailResult('options', {a: 1}) // 执行到返回非 undefined 的函数终止
// 没有输出
// 3 和 0 调换位置 输出：
// 3 { a: 1 }
// 1 { a: 1 }

```
## Tapable 的源码实现
使用最基本的发布订阅模式，一个事件列表，一个注册器，一个触发器。其中用到了很多 `apply` 和 `call`， 咋一看各种方法都大同小异, 没有多少复杂的东西。但是它能够在webpack中应用的那么广，真的是不可思议。
- 构造函数初始化插件列表
- mixin 混合所有原型方法到一个新类，使用了for in 循环复制属性，应该是属性较少比较单一，不需要过多的判断和优化，虽然forin性能很差，但是只有最适合的才是最好的。
- plugin 函数，负责注册插件，插件名称可以是数组或者多维数组，递归调用。直到不为数组的情况下再添加到插件列表里。非常适合应用于 webpack 的配置文件，它包含很多层级的配置项。
- apply 这个apply 和 通常使用的函数原型 apply 不是一回事，是应用一组插件类的方法。比如：webpack 的各种插件(CommonsChunkPlugin，extract-text-webpack-plugin，html-webpack-plugin，......)都提供了 apply 方法。
- hasPlugins 判断是否为注册过的事件，有点奇怪这个函数在 Tapable 内部没有被应用，每个 applyPlugins* 都自己进行的 plugin 是否存在的判断；

每个函数的用法有相关文档也说的很清楚了，主要来看看每种 applyPlugins 的差异。看源码这些函数都使用的 for 循环，觉得使用数组的 forEach 会更简洁一些。具体原因应该是考虑兼容性问题，代码写的比较早或者是书写习惯问题，不需要纠结谁好谁坏，大神也是人，哈哈。
### applyPlugins* 触发一个插件
- applyPlugins 简单的插件应用触发器实现
下面是我之前写的 trigger 对比, 缺少参数的可扩展性。Tapable 提供了，applyPlugins，applyPlugins(0-2)，我写的相当于 applyPlugins1，只支持一种参数形式。Tapable 是为外部提供的接口，需要支持各种场景。
```js
this.trigger = function (name, data) {
  if (this.events[name]) {
    this.events[name].forEach((callback) => {
      callback.call(this, data)
    })
  }
}
```
- applyPluginsWaterfall 比前面的触发器多了一个返回值，调用这个函数时要传一个 init 初始化的参数（不传也是可以的会, 是 undefined），把 init 作为第一个注册函数的入参，再把函数返回值作为下一个函数的入参，以此类推，直到最后一个函数执行完的返回值，作为 applyPluginsWaterfall 的返回值。  
关键的不同点：
```js
var current = init;
	for 循环 {
		args[0] = current;
		current = 函数调用返回值;
	}
	return current;
```
- applyPluginsBailResult 另一种函数处理方式，执行函数时，只要返回值不为 `undefined`，就会直接返回这个返回值，剩余的函数不再执行。
```js
var result = plugins[i].apply(this, args);
if(typeof result !== "undefined") {
	return result;
}
```

其它函数都要执行 callback 进行回调，具体应用场景比较复杂，我也没搞太清楚，看代码也不容易理解。可以看看 Tapable 新版的源码，定义了很多钩子函数，和这个差异很大，比这个还要复杂得多，原理应该是相通的，需要多去研究研究。有时间一定要看新版的源码。  
**以上 都是 针对 Tapable V0.2 版本。下面介绍一下 新版的 Tapable。**

## 新版 Tapable 的介绍
新版的 Tapable 库暴露了许多 `Hook` 类，可以用来为插件创建钩子。
```js
const {
	SyncHook,
	SyncBailHook,
	SyncWaterfallHook,
	SyncLoopHook,
	AsyncParallelHook,
	AsyncParallelBailHook,
	AsyncSeriesHook,
	AsyncSeriesBailHook,
	AsyncSeriesWaterfallHook
 } = require("tapable");
```
### 基本用法
所有的Hook构造函数都有一个可选的参数，它是一个参数名字列表。
```js
const hook = new SyncHook(["arg1", "arg2", "arg3"]);
```
最好的做法是在一个 `hooks` 属性中公开一个类的所有钩子：
```js
class Car {
	constructor() {
		this.hooks = {
			accelerate: new SyncHook(["newSpeed"]),
			break: new SyncHook(),
			calculateRoutes: new AsyncParallelHook(["source", "target", "routesList"])
		};
	}

	/* ... */
}
```
其他人就可以使用这些钩子：
```js
const myCar = new Car();

// 使用 tap 方法注册一个插件/事件(EventEmitter.on) 等同于 0.2版本的 plugins
myCar.hooks.break.tap("WarningLampPlugin", () => warningLamp.on());

// 执行 call 来触发钩子函数的调用
myCar.hooks.break.call()
```
它需要传递一个名字来标识这个插件/原因。  

你可能会收到参数：
```js
myCar.hooks.accelerate.tap("LoggerPlugin", newSpeed => console.log(`Accelerating to ${newSpeed}`));
```
对于同步挂钩，`tap` 是添加插件的唯一有效方法。异步钩子也支持异步插件：
```js
myCar.hooks.calculateRoutes.tapPromise("GoogleMapsPlugin", (source, target, routesList) => {
	// return a promise
	return google.maps.findRoute(source, target).then(route => {
		routesList.add(route);
	});
});

myCar.hooks.calculateRoutes.tapAsync("BingMapsPlugin", (source, target, routesList, callback) => {
	bing.findRoute(source, target, (err, route) => {
		if(err) return callback(err);
		routesList.add(route);
		// 执行回调函数
		callback();
	});
});

// 你仍然可以使用同步插件
myCar.hooks.calculateRoutes.tap("CachedRoutesPlugin", (source, target, routesList) => {
	const cachedRoute = cache.get(source, target);
	if(cachedRoute)
		routesList.add(cachedRoute);
})
```
这个类声明了那些钩子，现在需要调用它们：
```js
class Car {
	/* ... */

	setSpeed(newSpeed) {
		this.hooks.accelerate.call(newSpeed);
	}

	useNavigationSystemPromise(source, target) {
		const routesList = new List();
		return this.hooks.calculateRoutes.promise(source, target, routesList).then(() => {
			return routesList.getRoutes();
		});
	}

	useNavigationSystemAsync(source, target, callback) {
		const routesList = new List();
		this.hooks.calculateRoutes.callAsync(source, target, routesList, err => {
			if(err) return callback(err);
			callback(null, routesList.getRoutes());
		});
	}
}
```
Hook 将以最有效的方式运行插件来编译一个方法。它根据以下内容生成代码：
- 注册插件的数量（无 none，一个 one，更多 more）
- 注册插件的方式（同步 sync，异步 async，promise）
- 触发器执行的方式（同步 sync，异步 async，promise）
- 参数的数量
- 是否使用拦截器
### 拦截器
所有钩子都提供额外的拦截 API：
```js
myCar.hooks.calculateRoutes.intercept({
	call: (source, target, routesList) => {
		console.log("Starting to calculate routes");
	},
	tap: (tapInfo) => {
		// tapInfo = { type: "promise", name: "GoogleMapsPlugin", fn: ... }
		console.log(`${tapInfo.name} is doing it's job`);
		return tapInfo; // may return a new tapInfo object -- 可能会返回一个新的tapInfo对象
	}
})
```
**call:** `(...args) => void` 添加到拦截器的 `call` 将触发钩子的触发器, 你可以访问钩子参数。
**tap:** `(tap: Tap) => void` 当你的拦截器插入钩子时，触发器会触发。提供的是Tap对象。点击对象不能改变。


持续更新中。。。。。。
