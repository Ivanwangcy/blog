## 开发注意事项
- 重复的组件，要给 key, key 必须保证唯一，要不会影响渲染和性能问题；
- Text 是有背景色的，如果外层容器边框有圆角，会遮挡边框，需设置 backgroundColor: transparent;（背景透明）
- Touchable 组件，里面只能是独立的组件，不能超过一个，一个以上需嵌套在一个 View 中。
- Image 当容器，可以实现背景图效果。新增ImageBackground
- Text 文本内容被状态改变时，产生页面布局错乱时，要设置等宽字体 fontFamily: 'Helvetica'，List中的 Text 如果不设置等宽字体容易发生闪退；
- View 作为父容器，内容较多或者包含 List —— 长列表等情况下，不设置 flex，会导致样式错乱，部分子组件高度无法撑开。
- 
