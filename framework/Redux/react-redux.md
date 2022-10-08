# React-redux

redux 组件暴露 Ref


需要在 connect 时添加： { forwardRef: true }

```js
@connect(
  ({ commonData }) => {
    const { agreeFlag } = commonData || {}
    return {
      agreeFlag,
    }
  },
  {},
  null,
  { forwardRef: true }
)
```
