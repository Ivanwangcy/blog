# 开始使用 Webpack
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
