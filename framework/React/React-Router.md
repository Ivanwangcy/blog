# React Router

2018年 12月 13日截止，目前最新的React Router V4，与常规的静态路由存在很大差异。这样使路由更像是一个组件，使用更加灵活可以动态创建路由。

## 基本用法和路由配置

使用的库：

- https://github.com/ReactTraining/history
- https://github.com/ReactTraining/react-router
- https://github.com/reduxjs/react-redux
- https://github.com/supasate/connected-react-router
- https://github.com/CJY0208/react-router-cache-route

### HashRouter
### BrowserRouter

## 子路由的嵌套

## 结合 Redux 

使用 中间件 `react-router-redux`，https://github.com/reactjs/react-router-redux 已废弃

```js
import { ConnectedRouter } from 'react-router-redux';


```
## Switch

## Redirect

## 路由传参数

```js
pushPath('/foo?a=b')
// store:
{ location: '/foo?a=b' }


pushPath({ pathname: '/foo', query: { a: 'b' } })
// store:
{ location: { pathname: '/foo', query: { a: 'b' } } }


history.push('/foo?a=b')
// store:
{ location: { pathname: '/foo', query: { a: 'b' } } }


<Link to='/foo?a=b'>
// store:
{ location: { pathname: '/foo', query: { a: 'b' } } }
```
## connected-react-router

React Router v4 Redux 插件，官方建议使用它代替 react-router-redux [connected-react-router 仓库地址](https://github.com/supasate/connected-react-router)

## 用法：

* 自定义 history 对象，暴露 history api，可以从其它地方使用路由跳转方法。
```js
import { createBrowserHistory,createHashHistory } from 'history';
export const history = createBrowserHistory({
  basename: '', // The base URL of the app (see below)
  forceRefresh: false, // Set true to force full page refreshes
  keyLength: 6, // The length of location.key
  // A function to use to confirm navigation with the user (see below)
  getUserConfirmation: (message, callback) => callback(window.confirm(message))
});

// or 
export const history = createHashHistory({
  basename: '', // The base URL of the app (see below)
  hashType: 'noslash', // The hash type to use (see below)
  // hashType: 'slash', // The hash type to use (see below)
  // A function to use to confirm navigation with the user (see below)
  getUserConfirmation: (message, callback) => callback(window.confirm(message))
});

```

## 状态缓存 redux-persist 持久化数据

[redux-persist](https://github.com/rt2zz/redux-persist)
