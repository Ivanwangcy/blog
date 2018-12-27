# React Router

2018年 12月 13日截止，目前最新的React Router V4，与常规的静态路由存在很大差异。这样使路由更像是一个组件，使用更加灵活可以动态创建路由。

## 基本用法

## 子路由的嵌套

## 结合 Redux 

使用 中间件 `react-router-redux`

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
