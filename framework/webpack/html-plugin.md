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
- title: 生成的html文档的标题；
- filename: 生成的html文件的名称，同时支持创建子目录(eg: assets/admin.html)；
- template: 使用模板的路径， 支持loaders。(html!./index.html)
