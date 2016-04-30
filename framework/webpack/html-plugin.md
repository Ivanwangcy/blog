# webpack 生成HTML插件
链接[https://github.com/ampedandwired/html-webpack-plugin](https://github.com/ampedandwired/html-webpack-plugin)
## 安装
```sh
$ npm install html-webpack-plugin --save-dev # 保存到开发环境依赖
```
# 基本用法
这个 plugin 将生成`html5`文档结构。`script` 标签插入body中。在webpack.config.js中加入如下代码：
```javascript
var HtmlWebpackPlugin = require('html-webpack-plugin');
var webpackConfig = {
  entry: 'index.js',
  output: {
    path: 'dist',
    filename: 'index_bundle.js'
  },
  plugins: [new HtmlWebpackPlugin()]
};
```
运行`webpack`命令后生成如下HTML代码：
```html
<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    <title>Webpack App</title>
  </head>
  <body>
    <script src="index_bundle.js"></script>
  </body>
</html>
```
## Configuration 配置选项
可以进行一系列的配置，支持如下的配置信息

- title: 用来生成页面的 title 元素
- filename: 输出的 HTML 文件名，默认是 index.html, 也可以直接配置带有子目录。
- template: 模板文件路径，支持加载器，比如 html!./index.html
- inject: true | 'head' | 'body' | false  ,注入所有的资源到特定的 template 或者 templateContent 中，如果设置为 true 或者 body，所有的 javascript 资源将被放置到 body 元素的底部，'head' 将放置到 head 元素中。
- favicon: 添加特定的 favicon 路径到输出的 HTML 文件中。
- minify: {...} | false , 传递 [html-minifier](https://github.com/kangax/html-minifier#options-quick-reference) 选项给 minify 输出
- hash: true | false, 如果为 true, 将添加一个唯一的 webpack 编译 hash 到所有包含的脚本和 CSS 文件，对于解除 cache 很有用。
- cache: true | false，如果为 true, 这是默认值，仅仅在文件修改之后才会发布文件。
- showErrors: true | false, 如果为 true, 这是默认值，错误信息会写入到 HTML 页面中
- chunks: 允许只添加某些块 (比如，仅仅 unit test 块)
- chunksSortMode: 允许控制块在添加到页面之前的排序方式，支持的值：'none' | 'default' | {function}-default:'auto'
- excludeChunks: 允许跳过某些块，(比如，跳过单元测试的块)
下面的示例演示了如何使用这些配置。
## 编写自定义模板
如果默认生成的 HTML 文件不适合你的需要看，可以创建自己定义的模板。方便的方式是通过 inject 选项，然后传递给定制的 HTML 文件。html-webpack-plugin 将会自动注入所有需要的 CSS, js, manifest 和 favicon 文件到标记中。
```javascript
plugins: [
  new HtmlWebpackPlugin({
    title: 'Custom template',
    template: 'my-index.html', // Load a custom template
    inject: 'body' // Inject all scripts into the body
  })
]
```
my-index.html 文件

```html
<!DOCTYPE html>
<html>
  <head>
    <meta http-equiv="Content-type" content="text/html; charset=utf-8"/>
    <title><%= htmlWebpackPlugin.options.title %></title>
  </head>
  <body>
  </body>
</html>
```
## 过滤块
可以使用 chunks 来限定特定的块。
```javascript
plugins: [
  new HtmlWebpackPlugin({
    chunks: ['app']
  })
]
```
还可以使用 excludeChunks 来排除特定块。
```javascript
plugins: [
  new HtmlWebpackPlugin({
    excludeChunks: ['dev-helper']
  })
]
```
