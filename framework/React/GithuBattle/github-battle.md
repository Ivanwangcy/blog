# Github Battle
一个简单 React 单页应用实例, 涵盖一些 React 基础用法.
## 具备的基础知识
- NPM
- Webpack
- First React Component (会写Hello World!) React 基础
## getting start 开始搭建环境
- 安装环境
```sh
$ npm init -y
$ npm install --save react react-dom react-router && npm install --save-dev html-webpack-plugin webpack webpack-dev-server babel-{core,loader} babel-preset-{react,es2015,react-hmre, stage-0}

$ npm install axios # 基于 Promise的 http 请求
```
## pure function, stateless component
使用纯函数渲染无状态的 `React` 组件。它不处理Ajax请求，只接收 状态(state)和属性(props)。
## component and container
组件与容器，组件的最小单元，容器是多个组件组成的一大块儿。 
