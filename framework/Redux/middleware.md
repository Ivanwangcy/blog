# Redux middleware

Redux 借鉴了 Koa 的 middleware 思想，目的是为了增强 dispatch，给你一次改变 action 的机会。

## 常用中间件

### redux-thunk 异步中间件

```js
import { createStore, applyMiddleware } from 'redux';
import createReducer from './reducers';
import ReduxThunk from 'redux-thunk';  // 异步的 action 中间件

let store = createStore(createReducer(), applyMiddleware(thunk));

```
### redux-persist

https://github.com/rt2zz/redux-persist

redux 持久化插件

### redux-saga

https://github.com/redux-saga/redux-saga
