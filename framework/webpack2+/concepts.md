# Webpack 工作原理

Webpack 的核心是现代 JavaScript 应用程序的静态模块打包程序。当 webpack 处理您的应用程序时，它会递归地构建一个依赖关系图，其中包含应用程序需要的每个模块，然后将所有这些模块打包到一个或多个包中。

Webpack 以其使用简单著称，但是其内部实现是非常复杂的，要想灵活应用或者深入理解，一定要知道它的运行原理。

> webpack是一个打包模块化js的工具，可以通过loader转换文件，通过plugin扩展功能。

## webpack 核心概念

在了解 Webpack 工作原理前，需要掌握几个核心概念，以方便后续的理解。

> [在此处](https://webpack.js.org/concepts/modules/)了解有关 JavaScript 模块和 webpack 模块的更多信息。

它的[可配置是令人难以置信的](https://webpack.js.org/configuration/)，但要开始您只需要了解四个核心概念：

* Entry 入口
* Output 输出
* Loaders 模块加载转换器
* Plugins 扩展插件

本文档旨在对这些概念进行高级概述，同时提供指向具体概念特定用例的链接。

### Entry

**入口点(entry point)** 指示 `webpack` 应使用哪个模块开始构建其内部依赖关系图。进入入口点后，webpack 会找出哪些是入口点依赖的其它模块和库（直接或间接）。

然后处理每个依赖项并将其输出到名为 bundles 的文件中。

你可以通过在 [webpack configuration](https://webpack.js.org/configuration/) 中配置 `entry` 属性来指定入口点（或多个入口点）。

以下是 `entry` 配置的最简单示例：
`webpack.config.js`

```js
module.exports = {
  entry: "./path/to/my/entry/file.js"
};
```

你可以根据应用程序的需要以各种方式配置条目属性。在[entry points](https://webpack.js.org/concepts/entry-points/)部分了解更多信息。

### Output

output 属性告诉 webpack 在哪里发出它创建的 `bundles` 以及如何命名这些文件。您可以在配置文件中指定 `output` 字段来配置此部分过程：
`webpack.config.js`

```js
const path = require("path");

module.exports = {
  entry: "./path/to/my/entry/file.js",
  output: {
    path: path.resolve(__dirname, "dist"),
    filename: "my-first-webpack.bundle.js"
  }
};
```

在上面的示例中，我们使用 `output.filename` 和 `output.path` 属性来告诉 webpack 我们的包的名称以及我们希望将其发送到的位置。

output 属性具有[更多可配置的功能](https://webpack.js.org/configuration/output/)，如果您想了解更多关于 output 属性背后的概念，可以在概念部分阅读更多内容。

### Loaders

加载器使 webpack 能够处理的不仅仅是 JavaScript 文件（webpack 本身只能理解 JavaScript）。通过将它们转换为 webpack 可以处理的有效[模块 modules](https://webpack.js.org/concepts/modules/)，它们使你能够利用 webpack 捆绑各种文件的功能。

实质上，webpack 加载器将所有类型的文件转换为可包含在应用程序的依赖关系图中的模块（并最终成为一个包）。

    请注意，webpack 能够 `import` 任何类型的模块，例如 导入 `.css` 文件是 webpack 特有的功能，可能不受其他打包程序或任务运行程序的支持。我们认为这种语言的扩展是有保证的，因为它允许开发人员构建更准确的依赖关系图。

在高层次上， `loader` 在你的 webpack 配置中有两个目的：

* `test` 属性标识哪些文件或哪类文件集应该被转换。
* `use` 属性指示应该使用哪个加载器进行转换。

`webpack.config.js`

```js
const path = require("path");

const config = {
  entry: "./path/to/my/entry/file.js",
  output: {
    path: path.resolve(__dirname, "dist"),
    filename: "my-first-webpack.bundle.js"
  },
  module: {
    rules: [{ test: /\.txt$/, use: "raw-loader" }]
  }
};

module.exports = config;
```

上面的配置为具有两个必需属性( `test` 和 `use` )的单个模块定义了一个 `rules` 属性。这告诉 webpack 的编译器如下：

> “嘿，webpack 编译器，当你遇到一个解析为 `require() / import` 语句内部包含 '.txt' 的文件的路径时，在将它添加到 `bundle` 之前，使用 `raw-loader` 进行转换。”

    重要的是要记住，在webpack配置中定义规则时，您需要在 `module.rules` 下定义它们，而不是 `rules` 。为了你好，如果这样不正确的做法，webpack 将 '吼你(yell at you)'。

[学习更多的 loaders](https://webpack.js.org/concepts/loaders)

### Plugins

虽然 `loader` 用于转换某些类型的模块，但可以利用插件执行更广泛的任务。插件的范围从捆绑优化和缩小到定义类似环境的变量。[插件接口(plugin interface)](https://webpack.js.org/api/plugins/)非常强大，可以用来处理各种各样的任务。大部分插件都可以通过选项进行定制。为了使用插件，你需要 require() 它并将其添加到 `plugins` 数组中。由于您可以在配置中多次使用插件以实现不同目的，因此您需要通过使用 `new` 运算符调用它来创建它的实例。

`webpack.config.js`

```js
const HtmlWebpackPlugin = require("html-webpack-plugin"); //installed via npm
const webpack = require("webpack"); //to access built-in plugins
const path = require("path");

const config = {
  entry: "./path/to/my/entry/file.js",
  output: {
    path: path.resolve(__dirname, "dist"),
    filename: "my-first-webpack.bundle.js"
  },
  module: {
    rules: [{ test: /\.txt$/, use: "raw-loader" }]
  },
  plugins: [
    new webpack.optimize.UglifyJsPlugin(),
    new HtmlWebpackPlugin({ template: "./src/index.html" })
  ]
};

module.exports = config;
```

有很多 webpack 提供的插件。查看我们的[插件列表](https://webpack.js.org/plugins/)以获取更多信息。

在 webpack 配置中使用插件很简单 - 但是，有很多值得进一步探索的用例。

## Webpack 的执行流程

Webpack 的执行流程是一个串行的过程，从启动到结束会依次执行以下流程：

* 初始化参数：从配置文件和 Shell 语句中读取与合并参数，得出最终的参数；
* 开始编译：用上一步得到的参数初始化 Compiler 对象，加载所有配置的插件，执行对象的 run 方法开始执行编译；
* 确定入口：根据配置中的 entry 找出所有的入口文件；
* 编译模块：从入口文件出发，调用所有配置的 Loader 对模块进行翻译，再找出该模块依赖的模块，再递归本步骤直到所有入口依赖的文件都经过了本步骤的处理；
* 完成模块编译：在经过第 4 步使用 Loader 翻译完所有模块后，得到了每个模块被翻译后的最终内容以及它们之间的依赖关系；
* 输出资源：根据入口和模块之间的依赖关系，组装成一个个包含多个模块的 Chunk，再把每个 Chunk 转换成一个单独的文件加入到输出列表，这步是可以修改输出内容的最后机会；
* 输出完成：在确定好输出内容后，根据配置确定输出的路径和文件名，把文件内容写入到文件系统。在以上过程中，Webpack 会在特定的时间点广播出特定的事件，插件在监听到感兴趣的事件后会执行特定的逻辑，并且插件可以调用 Webpack 提供的 API 改变 Webpack 的运行结果。

参考：
[https://webpack.js.org](https://webpack.js.org)
[webpack 原理与实战](https://github.com/gwuhaolin/blog/issues/4)
