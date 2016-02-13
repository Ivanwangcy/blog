# webpack 加载 css 文件
1. 安装 css-loader and style-loader, 他们需要安装到本地，可以保存包package.json中；
```bash
$ npm install css-loader style-loader --save
```
2. 加载css和style库
```javascript
  // 代码中引用
  require("!style!css!./style.css");

  // webpack 打包时自动载入
  require("./style.css");

  // webpack.config.js 增加如下代码
  module: {
    loaders: [
      {
        test: /\.css$/, loader: "style!css"
      }
    ]
  }
```
