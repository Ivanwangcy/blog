# Webpack Concepts

其核心， Webpack 是现代 JavaScript 应用程序的静态模块打包程序。当webpack处理您的应用程序时，它会递归地构建一个依赖关系图，其中包含应用程序需要的每个模块，然后将所有这些模块打包到一个或多个包中。

> [在此处](https://webpack.js.org/concepts/modules/)了解有关 JavaScript 模块和 webpack 模块的更多信息。

它是[令人难以置信的可配置](https://webpack.js.org/configuration/)，但要开始您只需要了解四个核心概念：
* Entry
* Output
* Loaders
* Plugins

本文档旨在对这些概念进行高级概述，同时提供指向具体概念特定用例的链接。

## Entry
**入口点(entry point)**指示 webpack 应使用哪个模块开始构建其内部依赖关系图。进入入口点后，webpack 会找出哪些是入口点依赖的其它模块和库（直接或间接）。
