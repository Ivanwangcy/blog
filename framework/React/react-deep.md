# 深入理解 React

## React 事件机制

React 基于 `Virtual DOM` 实现了一个 `SyntheticEvent` (合成事件)层，我们所定义的事件处理器会接收一个 `SyntheticEvent` 对象的实例。

React 底层主要对合成事件做了两件事：时间委托和自动绑定。