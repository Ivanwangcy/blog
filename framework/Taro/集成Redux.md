# 集成Redux

## 异步 action

```js
// // 异步的action
// export function asyncAdd () {
//   return dispatch => {
//     setTimeout(() => {
//       dispatch(add())
//     }, 2000)
//   }
// }
```

## action 嵌套

```js
export function asyncAction () {
  return (dispatch, getState) => {
    dispatch(otherAction(params))
  }
}
```
