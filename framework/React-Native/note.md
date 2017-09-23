## React Native 历史演进
React Native起源于2013年夏天的一次黑客马拉松项目。  
React，这个用于构建用户界面的JavaScript库，就是React Native的核心。  

React具有声明式、异步、响应式的特性：
- 声明式编程：就是你编写代码描述想要做什么，而不是怎么做。只需告诉React，你希望应用长成什么样。
- 异步 async
- 响应式
## React Native 工作原理
原生代码与JavaScript代码通过桥接层进行交互，这是一个异步的批量串行处理过程。桥接层介于原生层和JavaScript代码之间，正如它的名称一样，它的作用很像桥（bridge）。

## 开发日志：
- 重复的组件，要给 key, key 必须保证唯一，要不会影响渲染和性能问题；
- Text 是有背景色的，如果外层容器边框有圆角，会遮挡边框，需设置 backgroundColor: transparent;（背景透明）
- Touchable 组件，里面只能是独立的组件，不能超过一个，一个以上需嵌套在一个 View 中。
- Image 当容器，可以实现背景图效果。新增ImageBackground
- Text 文本内容被状态改变时，产生页面布局错乱时，要设置等宽字体 fontFamily: 'Helvetica'，List中的 Text 如果不设置等宽字体容易发生闪退；
- View 作为父容器，内容较多或者包含 List —— 长列表等情况下，不设置 flex，会导致样式错乱，部分子组件高度无法撑开。
- Animated time 动画，串行动画
- layout 函数获取，组件的宽高
