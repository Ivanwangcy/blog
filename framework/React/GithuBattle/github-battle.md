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
```javascript
var ProfilePic = function (props) {
  return <img src={'https://photo.fb.com/' + props.username} />
}
var ProfileLink = function (props) {
  return (
    <a href={'https://www.fb.com/' + props.username}>
      {props.username}
    </a>
  )
}
var Avatar = function (props) {
  return (
    <div>
      <ProfilePic username={props.username} />
      <ProfileLink username={props.username} />
    </div>
  )
}
<Avatar username="tylermcginnis" />

// 无状态组件
function HelloWorld (props) {
  return (
    <div>Hello {props.name}</div>
  )
}
ReactDOM.render(<HelloWorld name='Tyler' />, document.getElementById('app'))
```

## component and container
组件与容器，组件的最小单元，容器是多个组件组成的一大块儿。
## 公用组件与私有组件
```javascript
var React = require('react');
function FriendItem (props) {
  return <li>{props.friend}</li>
}
function FriendsList (props) {
  return (
    <h1>Friends:</h1>
    <ul>
      {props.friends.map((friend, index) => <FriendItem friend={friend} key={friend} />)}
    </ul>
  )
}
module.exports = FriendsList
```
## 样式对象
## 默认属性
## 初始化状态
## 嵌套组件
```javascript
this.props.children
```
## 纯函数，无状态组件
## 路由
## 事件绑定bind，this 作用域
## Promise，axios 异步请求
