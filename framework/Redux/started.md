# Redux 介绍
Redux 是一个状态管理器，相当于计算机的控制总线。
## 安装
```sh
$ npm i redux
$ npm i react-redux
```
```javascript
import { createStore } from 'redux'

// 创建一个 reducer
function counter(state = 0, action) {
  switch (action.type) {
    case 'INCREMENT':
      return state + 1;
    case 'DECREMENT':
      return state - 1;
    default:
      return state;
  }
}
```
