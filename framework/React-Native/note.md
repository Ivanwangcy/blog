## React Native 历史演进
React Native起源于2013年夏天的一次黑客马拉松项目。  
React，这个用于构建用户界面的JavaScript库，就是React Native的核心。  

React具有声明式、异步、响应式的特性：
- 声明式编程：就是你编写代码描述想要做什么，而不是怎么做。只需告诉React，你希望应用长成什么样。
- 异步 async
- 响应式
-  组件化开发：Facebook宣称，“用了React，你只需要开发组件”。开发一整套组件，再把它们拼装成应用。
## React Native 工作原理
原生代码与JavaScript代码通过桥接层进行交互，这是一个异步的批量串行处理过程。桥接层介于原生层和JavaScript代码之间，正如它的名称一样，它的作用很像桥（bridge）。
##
## 开发日志：
- 重复的组件，要给 key, key 必须保证唯一，要不会影响渲染和性能问题；
- Text 是有背景色的，如果外层容器边框有圆角，会遮挡边框，需设置 backgroundColor: transparent;（背景透明）
- Touchable 组件，里面只能是独立的组件，不能超过一个，一个以上需嵌套在一个 View 中。
- Image 当容器，可以实现背景图效果。新增ImageBackground
- Text 文本内容被状态改变时，产生页面布局错乱时，要设置等宽字体 fontFamily: 'Helvetica'，List中的 Text 如果不设置等宽字体容易发生闪退；
- View 作为父容器，内容较多或者包含 List —— 长列表等情况下，不设置 flex，会导致样式错乱，部分子组件高度无法撑开。
- Animated time 动画，串行动画
- layout 函数获取，组件的宽高
- Touchable 组件包裹原生的组件View，不能是自定义组件
- borderBottomWidth:   使用 `StyleSheet.hairlineWidth` 解决0.5像素的边框在plus上的灰色bug
- automaticallyAdjustContentInsets bool
如果滚动视图放在一个导航条或者工具条后面的时候，iOS系统是否要自动调整内容的范围。默认值为true。（译注：如果你的ScrollView或ListView的头部出现莫名其妙的空白，尝试将此属性置为false）
- 使用 lodash/`debounce` 防止点击过快，延迟处理。适用于点击事件，输入事件等
- ScrollView vs FlatList onScroll 滚动问题，FlatList 支持手势滑动，可以实时获取 e.nativeEvent.contentOffset.y 的位置， `FlatList` 继承自 `PureComponent` 性能更优越(它们都可以设置 scrollEventThrottle={1} 不会错过每一帧滚动条位置，但是有性能损耗，减少使用，scrollEventThrottle={16}是比较标准的值，可以保持 每秒 60帧的速率运行, `60fps` 刷新频率)
- 无需分页加载，下拉刷新等功能，还是建议使用 `ScrollView` ，滚动动画可以使用，`Animated.ScrollView`
- 如果想让组件高度自适应，达到最大高度时出现滚动条，类似于 css 的 (overflow: scroll, overflow-y: scroll)可以使用下面的布局方式：(内容高度不超过300 是实际高度，超过300部分隐藏，滚动显示)
```jsx
<View style={{maxHeight: 300}}>
  <ScrollView>
    {列表或者长内容}
  </ScrollView>
</View>
```
