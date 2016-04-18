# Webpack 简介
Webpack 是德国开发者Tobias Koppers 开发的模块加载器兼打包工具，在webpack中，它能把各种资源，例如JS（含JSX）、coffee、样式（含less/sass）、图片等都作为模块来使用和处理。因此, Webpack 当中 js 可以引用 css, css 中可以嵌入图片 dataUrl。  
对应各种不同文件类型的资源, Webpack 有对应的模块 loader，比如对ES6的支持babel-loader，vue用的是vue-loader。
## 开始使用 Webpack
全局安装 webpack 打包工具 和 webpack-dev-server 开发服务器
```bash
$ npm i -g webpack webpack-dev-server
```
## 文件打包 bundle.js
```bash
$ webpack ./entry.js bundle.js
```
## 配置 webpack.config.js 文件
```javascript
 // 创建 webpack.config.js 并增加如下内容
 module.exports = {
   entry: './entry.js',
   output: {
     filename: 'bundle.js'
   }
 };
 ```
 再执行 `$ webpack` <==> `$ webpack ./entry.js bundle.js`  

## webpack 命令
```bash
$ webpack # 读取配置文件打包

$ webpack --progress --colors # 美化打包输出

$ webpack --progress --colors --watch # 自动编译，无需每次修改文件手动编译

$ webpack -p # 压缩产品级别

$ webpack -d # 输出SourceMap
```

## webpack-dev-server 开发环境服务器
```bash
$ npm i -g webpack-dev-server # 安装服务器
$ webpack-dev-server --progress --colors # 运行服务器
```
