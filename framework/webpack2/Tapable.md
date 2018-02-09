# Webpack 插件 `Tapable V0.2` 应用与原理分析
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

每个函数的用法有相关文档也说的很清楚了，主要来看看每种 applyPlugins 的差异。看源码这些函数都使用的 for 循环，觉得使用数组的 forEach 会更简洁一些。具体原因应该是考虑兼容性问题，代码写的比较早或者是书写习惯问题，总之不需要纠结谁好谁不好，适合的才是最好的。
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

其它函数都要执行 callback 进行回调，具体应用场景比较复杂，我也没搞太清楚，看代码也不容易理解。可以看看 Tapable 新版的源码，定义了很多钩子函数，和这个差异很大，比这个还要复杂得多，原理应该是相通的，需要多去研究研究。有时间一定要看新版的源码，再来分析一下。
