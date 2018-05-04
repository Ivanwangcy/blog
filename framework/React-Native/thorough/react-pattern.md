# React 代码组织方式探索

为什么要用 flux 数据流管理。

## eventEmitter

一个反例，EventEmitter应用：
**为什么不是一个好例子**

* 容易产生数据流紊乱（不是一定会产生，只是容易产生）
* 数据属于 Component 本身，业务逻辑不好剥离，Component 难以复用
