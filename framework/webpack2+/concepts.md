# Webpack 基本原理分析

## webpack 核心概念
其核心， Webpack 是现代 JavaScript 应用程序的静态模块打包程序。当webpack处理您的应用程序时，它会递归地构建一个依赖关系图，其中包含应用程序需要的每个模块，然后将所有这些模块打包到一个或多个包中。

> [在此处](https://webpack.js.org/concepts/modules/)了解有关 JavaScript 模块和 webpack 模块的更多信息。

它是[令人难以置信的可配置](https://webpack.js.org/configuration/)，但要开始您只需要了解四个核心概念：
* Entry
* Output
* Loaders
* Plugins

本文档旨在对这些概念进行高级概述，同时提供指向具体概念特定用例的链接。

### Entry
**入口点(entry point)** 指示 `webpack` 应使用哪个模块开始构建其内部依赖关系图。进入入口点后，webpack 会找出哪些是入口点依赖的其它模块和库（直接或间接）。

然后处理每个依赖项并将其输出到名为bundles的文件中。

你可以通过在 [webpack configuration](https://webpack.js.org/configuration/) 中配置 `entry` 属性来指定入口点（或多个入口点）。

以下是 `entry` 配置的最简单示例：
`webpack.config.js`
```js
module.exports = {
  entry: './path/to/my/entry/file.js'
};
```
你可以根据应用程序的需要以各种方式配置条目属性。在[entry points](https://webpack.js.org/concepts/entry-points/)部分了解更多信息。

### Output
output 属性告诉 webpack 在哪里发出它创建的 `bundles` 以及如何命名这些文件。您可以在配置文件中指定 `output` 字段来配置此部分过程：
`webpack.config.js`
```js
const path = require('path');

module.exports = {
  entry: './path/to/my/entry/file.js',
  output: {
    path: path.resolve(__dirname, 'dist'),
    filename: 'my-first-webpack.bundle.js'
  }
};
```
在上面的示例中，我们使用 `output.filename` 和 `output.path` 属性来告诉 webpack 我们的包的名称以及我们希望将其发送到的位置。

output 属性具有[更多可配置的功能](https://webpack.js.org/configuration/output/)，如果您想了解更多关于output属性背后的概念，可以在概念部分阅读更多内容。

### Loaders

加载器使 webpack 能够处理的不仅仅是 JavaScript 文件（webpack 本身只能理解 JavaScript）。
通过将它们转换为 webpack 可以处理的有效[模块 modules](https://webpack.js.org/concepts/modules/)，它们使你能够利用 webpack 捆绑各种文件的功能。

实质上，webpack加载器将所有类型的文件转换为可包含在应用程序的依赖关系图中的模块（并最终成为一个包）。

    请注意，webpack 能够 `import` 任何类型的模块，例如 导入 `.css` 文件是 webpack 特有的功能，可能不受其他打包程序或任务运行程序的支持。我们认为这种语言的扩展是有保证的，因为它允许开发人员构建更准确的依赖关系图。

在高层次上， `loader` 在你的 webpack 配置中有两个目的：

* `test` 属性标识哪些文件或哪类文件集应该被转换。
* `use` 属性指示应该使用哪个加载器进行转换。

`webpack.config.js`
```js
const path = require('path');

const config = {
  entry: './path/to/my/entry/file.js',
  output: {
    path: path.resolve(__dirname, 'dist'),
    filename: 'my-first-webpack.bundle.js'
  },
  module: {
    rules: [
      { test: /\.txt$/, use: 'raw-loader' }
    ]
  }
};

module.exports = config;
```

上面的配置为具有两个必需属性( `test` 和 `use` )的单个模块定义了一个 `rules` 属性。这告诉webpack的编译器如下：

> “嘿，webpack 编译器，当你遇到一个解析为 `require() / import` 语句内部包含 '.txt' 的文件的路径时，在将它添加到 `bundle` 之前，使用 `raw-loader` 进行转换。”

    重要的是要记住，在webpack配置中定义规则时，您需要在 `module.rules` 下定义它们，而不是 `rules` 。为了你好，如果这样不正确的做法，webpack 将 '吼你(yell at you)'。

[学习更多的 loaders](https://webpack.js.org/concepts/loaders)

### Plugins

参考：
[https://webpack.js.org](https://webpack.js.org)
[webpack原理与实战](https://github.com/gwuhaolin/blog/issues/4)
