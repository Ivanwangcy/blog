# npm 命令
```bash
$ npm init # 初始化package.json

$ npm install jquery --save # 安装 jquery 并保存到 package.json npm install == npm i
$ npm update jquery # 更新到最新版本的 jquery 库
$ npm remove jquery --save # 删除jquery库，并更新 package.json npm remove == npm r

$ npm ls # 列出当前安装的了所有包
```
## npm install 详解
当你为你的模块安装一个依赖模块时，正常情况下你得先安装他们（在模块根目录下npm install module-name），然后连同版本号手动将他们添加到模块配置文件package.json中的依赖里（dependencies）。  
* -save和save-dev可以省掉你手动修改package.json文件的步骤。
```bash
npm install module-name -save # 自动把模块和版本号添加到dependencies部分
npm install module-name -save-dev # 自动把模块和版本号添加到devdependencies部分

# 简写 全局安装（同时安装多个包 空格隔开）
npm i -g webpack webpack-dev-server
```
至于配置文件区分这俩部分，是用于区别开发依赖模块和产品依赖模块，devDepandencies主要是配置测试框架， 例如jshint、mocha。

## npm package.json 配置
### scripts 配置运行 命令
```javascript
"scripts": {
    "test": "echo \"Error: no test specified\" && exit 1",
    "dev": "webpack-dev-server --devtool eval --progress --colors",
    "deploy": "NODE_ENV=production webpack -p"
  }
```
执行配置的命令
```bash
$ npm test # 执行测试命令

$ npm run dev # 使用 npm run 执行自定义命令
$ npm run deploy
```
