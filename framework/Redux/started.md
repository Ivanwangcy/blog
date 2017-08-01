# Redux 介绍
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
