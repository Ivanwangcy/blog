# 开始使用 Webpack
全局安装 webpack 打包工具 和 webpack-dev-server 开发测试服务器
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
