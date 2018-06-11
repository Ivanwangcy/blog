# 高阶组件 Higher-Order Components

高阶组件（HOC）是 React 中用于重用组件逻辑的高级技术。 HOC本身不是 React API 的一部分。它们是从 React 的组合特性中产出的一种模式。

具体而言，高阶组件是一个接收组件并返回新组件的函数。

```js
const EnhancedComponent = higherOrderComponent(WrappedComponent);
```
## 属性劫持
