# npm 命令
## npm 帮助
```sh
$ npm help # 帮助  npm命令列表
$ npm help <command> # 帮助  打开网页版帮助

$ npm <command> -h # 帮助 命令行学习工具

# 各个命令的简单用法
$ npm -l
```
## npm init 初始化
```bash

$ npm init # 初始化package.json 根据提示回车即可

$
```
## 安装与更新包,模块
```sh
$ npm install jquery --save # 安装 jquery 并保存到 package.json npm install == npm i

$ npm install jquery backbone underscore --save # 安装包并保存到 package.json npm install == npm i

$ npm unistall --global jquery #卸载

$ npm update jquery # 更新到最新版本的 jquery 库

$ npm update --save # 更新所有本地仓库 并 更新 package.json

$ npm remove jquery --save # 删除jquery库，并更新 package.json npm remove == npm r

$ npm ls # 列出当前安装的了所有包
```
## npm install 详解
当你为你的模块安装一个依赖模块时，正常情况下你得先安装他们（在模块根目录下npm install module-name），然后连同版本号手动将他们添加到模块配置文件package.json中的依赖里（dependencies）。  
* -save和save-dev可以省掉你手动修改package.json文件的步骤。
```bash
$ npm install module-name --save # 自动把模块和版本号添加到dependencies部分
$ npm install module-name --save-dev # 自动把模块和版本号添加到devdependencies部分

# 简单的写法：安装 webpack 的缩写形式，如下
$ npm i webpack -S   # –save：模块名将被添加到dependencies，可以简化为参数-S。
$ npm i webpack -D   # –save-dev: 模块名将被添加到devDependencies，可以简化为参数-D。

# 安装多个包用空格隔开
$ npm install babel-loader babel-core babel-preset-es2015 babel-preset-react --save-dev
# 安装 package.json 依赖包
$ npm install  # 安装 package.json 里面的 dependencies 依赖包

$ npm install --only=dev  # 安装 package.json 里面的 devdependencies 部分的依赖包
$ npm install --dev # 同上，已废弃建议使用上面的
# 简写 全局安装（同时安装多个包 空格隔开）
npm i -g webpack webpack-dev-server
```
至于配置文件区分这俩部分，是用于区别开发依赖模块和产品依赖模块，devDepandencies主要是配置测试框架， 例如jshint、mocha。
## npm 自身升级
```sh
$ npm --version # 查看NPM版本
$ npm install -g npm@3.7.2 # 安装指定版本的 NPM
$ npm install npm@latest -g # 更新到最新版本
```
## npm package.json 配置
### scripts 配置运行 命令
```javascript
"scripts": {
    "test": "echo \"Error: no test specified\" && exit 1",
    "dev": "webpack-dev-server --devtool eval --progress --colors",
    "deploy": "NODE_ENV=production webpack -p"
  }
```
## npm dedupe 去重, 重新计算依赖关系
```bash
$ npm dedupe
```

## 执行配置的命令
```bash
$ npm test # 执行测试命令

$ npm run dev # 使用 npm run 执行自定义命令
$ npm run deploy
```
