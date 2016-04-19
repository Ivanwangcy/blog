# Webpack 简介
Webpack 是德国开发者Tobias Koppers 开发的模块加载器兼打包工具，在webpack中，它能把各种资源，例如JS（含JSX）、coffee、样式（含less/sass）、图片等都作为模块来使用和处理。因此, Webpack 当中 js 可以引用 css, css 中可以嵌入图片 dataUrl。  
对应各种不同文件类型的资源, Webpack 有对应的模块 loader，比如对ES6的支持babel-loader，vue用的是vue-loader。
## 安装 Webpack
前提：因为webpack是一个基于node的项目，所以首先需要确保你的电脑里面已经安装了node.js，以及npm。  
全局安装 webpack 打包工具 和 webpack-dev-server 开发服务器, 命令如下：
```bash
$ npm i -g webpack webpack-dev-server
```
安装成功后，在命令行输入`$ webpack -h` 即可查看当前安装的版本信息。以及可以使用的指令。  
我们应该将 webapck 安装到当前的项目依赖中，此时就可以使用项目的本这样就可以使用项目本地版本的 Webpack。
```sh
$ npm init # 根据指示回车即可
$ npm install webpack webpack-dev-server --save-dev # 简写 $ npm i webpack webpack-dev-server -D
```
安装完成之后 package.json 的结构如下：
```javascript
安装好之后我们的package.json的目录应该是这样的：
{
  "name": "webpack-tutorials",
  "version": "1.0.0",
  "description": "this is my webpack-tutorials",
  "main": "index.js",
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1"
  },
  "author": "Ivan",
  "license": "MIT",
  "dependencies": {},
  "devDependencies": {
    "webpack": "^1.13.0",
    "webpack-dev-server": "^1.14.1"
  }
}
```
## 开始使用 webpack
开始来用webpack进行我们的第一个打包运行程序吧！  
- 首先创建一个静态页面 index.html 和一个 JS 入口文件 entry.js，运行如下命令：
```bash
$ webpack ./entry.js bundle.js
```
- 再新建一个js文件，使用 `require('./other.js')`，在进行打包，这样可以将多个文件打包成一个`bundle.js`文件；
Webpack 会分析入口文件，解析包含依赖关系的各个文件。这些文件（模块）都打包到bundle.js 。Webpack 会给每个模块分配一个唯一的 id 并通过这个 id 索引和访问模块。在页面启动时，会先执行 entry.js 中的代码，其它模块会在运行 require 的时候再执行。  
## 使用配置文件进行打包
新建 webpack.config.js 文件
```javascript
 // 创建 webpack.config.js 并增加如下内容
 module.exports = {
   entry: './entry.js',
   output: {
     filename: 'bundle.js'
   }
 };
  // 再执行 $ webpack
 // 等同于命令 $ webpack ./entry.js bundle.js
 ```
## webpack 常用命令
```bash
$ webpack # 读取配置文件打包

$ webpack --progress --colors # 美化打包输出

$ webpack --progress --colors --watch # 自动编译，无需每次修改文件手动编译

$ webpack -p # 对打包后的文件进行压缩 压缩产品级别

$ webpack -d # 输出SourceMap, 方便调试

webpack #最基本的启动webpack命令
webpack -w #提供watch方法，实时进行打包更新
webpack -p #对打包后的文件进行压缩
webpack -d #提供SourceMaps，方便调试
webpack --colors #输出结果带彩色，比如：会用红色显示耗时较长的步骤
webpack --profile #输出性能数据，可以看到每一步的耗时
webpack --display-modules #默认情况下 node_modules 下的模块会被隐藏，加上这个参数可以显示这些被隐藏的模块
```

## webpack-dev-server 开发环境服务器
```bash
$ npm i -g webpack-dev-server # 安装服务器
$ webpack-dev-server --progress --colors # 运行服务器
```
