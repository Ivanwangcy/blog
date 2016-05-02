# 在 `Macbook` 搭建开发环境
首先安装 `Node.js` 环境, 并配置好环境变量

1. 创建 `package.json` 文件
```sh
$ npm init -y
```

## 必须执行的两步骤
2. 安装 webpack 和 webpack-dev-server;
```sh
$ npm i -g webpack webpack-dev-server
```
3. 安装 `extract-text-webpack-plugin` 插件，`html-loader` loader工具;
```sh
$ npm install --local webpack webpack-dev-server extract-text-webpack-plugin html-loader --save-dev
```

## 只需配置过一次，不需重复执行
4. 新建 `index.static.html` 文件; （略）
5. 新建 `webpack.config.js` 文件;
```javascript
var fs = require('fs'); // 文件API
var ExtractTextPlugin = require('extract-text-webpack-plugin'); // webpack 插件

// 开发分支路径
var publicPath = "./html/new/";

var tplEntris = [];  // 读取模版文件
fs.readdirSync(publicPath + "app/layout").reduce(function (o, filename) {
    tplEntris.push(publicPath + "app/layout/" + filename);
  }, {});
  tplEntris.unshift("./index-static.html");
  module.exports = {
    entry: tplEntris,
    devServer: {
      hot: true,
      inline: true,
      //其实很简单的，只要配置这个参数就可以了, 代理服务器地址
      proxy: {
        '/client': {
            target: 'http://xxx.xx.com',
            secure: false
        }
      }
    },
    module: {
        loaders: [{
          test: /\.html$/,
          loader: ExtractTextPlugin.extract('html') // 提取所有模版文件
        }]
      },
      plugins: [
      new ExtractTextPlugin(publicPath + "index.html") // 合并到首页，虚拟的文件
    ]

  };

```
6. 创建脚本, 增加至 `package.json` 中;
```javascript
"scripts": {
  "dev": "webpack-dev-server"
}
```
## 最后一步启动
7. 启动;
```sh
$ npm run dev
```
