# React 代码组织方式探索

为什么要用 flux 数据流管理。

## 使用 eventEmitter 发布订阅模式

一个反例，EventEmitter应用：
**为什么不是一个好例子**

* 容易产生数据流紊乱（不是一定会产生，只是容易产生）
* 数据属于 Component 本身，业务逻辑不好剥离，Component 难以复用

## flux 数据流管理

## Container&Presentational Components 模式

Container components 模式是一款很棒的 React 模式：

* 分离了数据获取和数据渲染的逻辑；
* 数据渲染部分都交给展示性组件，展示组建对需要的数据结构有具体的要求，而 PropTypes 能够很好地满足这个要求。
* 可以通过PropTypes 来限制 props 数据格式。如果 props 格式出错，就会报错。