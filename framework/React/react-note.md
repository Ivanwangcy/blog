# React 实战经验

* React 解决了前端的哪些痛点？

  * 首先解决了模板问题，和 backbone 进行比较代码实现的差异
  * 调试方便，可以打断点
  * 不需要操作DOM 做局部更新
  * 包含类型检测
  * 框架稳定，能够集成各种类库完善生态圈

* React 开发技巧
* React 生态圈
* React 有哪些坑

## 组件分类：

* 纯展示性组件，（无状态组件）逻辑少，样式复杂一些；
* 接入性组件， （container容器型组件），聚合多个小组件；
* 交互性组件，（按钮，图片等），包含自身状态有交互逻辑和样式，比纯组件复杂一些；
* 功能性组件 （路由，过渡动画等，比较抽象，无渲染内容）；

## 渲染机制

* 声明式
* 响应式

尽量不要让技术掌握在少数人手里。