# React 组件热更新
安装（已经安装了 webpack, React, (hjs-webpack) 的前提）
```sh
$ npm i -D babel-preset-react-hmre
```
配置 `.babelrc` 文件如下
```javascript
{
  "presets": ["es2015", "stage-0", "react"],
  "env": {
    "development": {
      "presets": ["react-hmre"]
    }
  }
}
```
启动热更新
```sh

# 增加参数， 使 process.env.NODE_ENV === development
$ NODE_ENV=development webpack-dev-server

$ NODE_ENV=development hjs-dev-server # 启动服务器 默认端口 3000
```
