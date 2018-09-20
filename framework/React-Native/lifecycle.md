# 生命周期函数

- constructor(props) 构造函数
- componentWillMount 组件将被挂载，挂载前执行, _V16.3 以后将废弃_
- shouldComponentUpdate
- componentDidMount
- componentDidUpdate

## React v16.3 以后去掉了以下三个生命周期

- componentWillMount
- componentWillReceiveProps
- componentWillUpdate

同时为了弥补失去上面三个周期的不足又加了两个:

- static getDerivedStateFromProps
- getSnapshotBeforeUpdate

>>参考：
>>>>[关于React v16.3 新生命周期](https://juejin.im/post/5aca20c96fb9a028d700e1ce)