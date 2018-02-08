## Webpack 插件 `Tapable V0.2` 应用与源码分析
`Tapable` 是什么？ 是一个用于 webpack 的插件体系结构中的内部核心库。webpack 中有很多Tapable 的实例类，它们都继承或者混合自 Tapable，这些实例提供了各种事件钩子可以附加到自定义插件中。总之，Tapable 可以说是短小精湛。遍布在 webpack 的每个角落。

## 首先看看 `Tapable 官方 API` 的解释
Tapable是一个小型库，允许你添加和应用插件到一个 javascript 模块。 它可以被继承或混合到其他模块。 它类似于NodeJS 的 `EventEmitter` 类，专注于自定义事件的触发和执行。 但是，除此之外，Tapable 允许您通过回调参数访问事件的“发布者” 或 “生产者”。

## Tapable有四组成员函数：
- plugin(name:string, handler: function)：它允许自定义插件注册到 Tapable 实例的事件中，这类似于 EventEmitter 的 on() 方法 ，当信号/事件发生时，用于注册处理程序/监听器来执行某些操作。
- apply(...pluginInstances: (AnyPlugin|function)[])：AnyPlugin 应该是一个类（或者很少的情况下是对象）具有一个 apply 方法，或者是有一些注册代码的内部的一个函数。这个方法是应用到插件的定义，以便真正的事件监听器能够注册到 Tapable 实例的注册表中。
- applyPlugins*(name:string, ...)：该 Tapable 实例可以申请使用这些功能的特定哈希下的所有插件。这组方法像 EventEmitter 的 `emit()` 方法，控制事件触发时可以定位于各种策略。
- mixin(pt: Object)：一种简单的方法来扩展 Tapable 的原型进行混合而不是直接继承它。

## 不同的 applyPlugins* 方法包括以下功能示例：
- 插件可以连续运行。
- 插件可以并行运行。
- 插件可以一个接一个地运行，但是要从前一个插件（瀑布）获取输入。
- 插件可以异步运行。
- 在特定条件下退出插件的运行：也就是说，一旦一个插件返回非 undefined
，跳出运行流程并 return 该插件的返回。这听起来像 EventEmitter 的 `once()`，但是完全不同。

## Webpack 中应用 Tapalbe 的范例:
Webpack 的 Tapable 实例之一 `Compiler` 负责编译 webpack 配置对象并返回一个编译实例。编译实例运行时，将创建所需的 bundles (捆绑包)。

`请参阅下面的简化版本，了解如何使用Tapable：`

**node_modules/webpack/lib/Compiler.js**
```js

var Tapable = require("tapable");

function Compiler() {
    Tapable.call(this);
}

Compiler.prototype = Object.create(Tapable.prototype);

```
现在在编译器上编写一个插件。
我定制，plugin.js

function CustomPlugin() {}
CustomPlugin.prototype.apply = function(compiler) {
  compiler.plugin('emit', pluginFunction);
}
编译器在在其生命周期的适当点执行插件

node_modules /的WebPack / LIB / Compiler.js

this.apply*("emit",options) // will fetch all plugins under 'emit' name and run them.
