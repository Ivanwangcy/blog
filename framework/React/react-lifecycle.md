# React Components 生命周期
## React Components 3种状态：
1. Mounted React渲染完成：React 组件(Components) 被render解析生成对应的DOM节点并被插入浏览器的DOM结构的一个过程；
2. Update 重新渲染：一个 Mounted 的 React Components 被重新 render 的过程；
3. Unmounted 销毁：一个 Mounted 的 React Comonents 对应的 DOM 节点 从 DOM 结构中移除的过程；
## 每一个状态React都封装了对应的hook函数；
### Mounted 装配
1. getDefaultProps() 获取组件默认属性
1. setInitialState() 初始化组件状态
2. comonentWillMount() 组件将要渲染
3. render() 组件开始渲染
4. comonentDidMount() 组件渲染完成
### Updating 更新，接收新数据
1. comonentWillReceiveProps() 将要接收新属性
2. shouldComonentUpdate() 是否应该更新组件
3. componentWillUpdate() 将要更新组件
4. render() 重新渲染组件
5. componentDidUpdate() 组件更新完成

### Unmounting 卸载
1. componentWillUnmount() 组件销毁, 卸载
