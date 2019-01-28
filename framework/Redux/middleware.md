# Middleware
```js
import { createStore, applyMiddleware } from 'redux';
import createReducer from './reducers';
import ReduxThunk from 'redux-thunk';  // 异步的 action 中间件

let store = createStore(createReducer(), applyMiddleware(thunk));

```
