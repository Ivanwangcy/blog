# webpack 插件
## open-browser-webpack-plugin
1. 安装
```sh
$ npm install --save-dev open-browser-webpack-plugin #
```
2. webpack 配置文件中使用
```javascript
var OpenBrowserPlugin = require('open-browser-webpack-plugin');

module.exports = {
  entry: path.resolve(__dirname, 'lib/entry.js'),
  output: {
    path: __dirname + "/bundle/",
    filename: "bundle.js"
  },
  plugins: [
    new OpenBrowserPlugin({ url: 'http://localhost:3000' })
  ]
};
```
