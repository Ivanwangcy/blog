# Redux 介绍

Redux 是一种状态管理器，是一个“可预测化状态的 JavaScript 容器”，相当于计算机的控制总线。Redux 使用单向数据流。我们把可变数据称为状态，也是应用的状态。
Rdux 中的 store, action, reducer：

* store 是应用程序的状态（数据）；
* action 触发状态改变的条件；
* reducer 是一个纯函数，是 action 的订阅者，接收当前状态，触发 action，返回修改后的状态；
  Redux 负责把它们连接起来。

引用   了纯函数 reducer ,按照给定的 actions 对 store 进行修改，状态改变后视图也随之改变。

## 安装

```sh
# npm 安装
$ npm i redux
$ npm i react-redux
```

```javascript
import { createStore } from "redux";

// 创建一个 store
let store = {
  state: 0 // 默认状态
};

// 创建一个 reducer, 由 action 触发
function counter(state = store.state.state, action) {
  switch (action.type) {
    case "INCREMENT":
      return state + 1;
    case "DECREMENT":
      return state - 1;
    default:
      return state;
  }
}

// 初始化 store
const store = createStore(counter)
```

## 前端为什么需要状态管理库

## Redux 的状态注入方式
全局注册所有状态，局部组件使用 connect 连接，映射特定的状态注入成属性，进行分治管理。 
