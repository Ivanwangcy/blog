# React Native 历史演进

React Native起源于2013年夏天的一次黑客马拉松项目。
React，这个用于构建用户界面的JavaScript库，就是React Native的核心。

React具有声明式、异步、响应式的特性：

- 声明式编程：就是你编写代码描述想要做什么，而不是怎么做。只需告诉React，你希望应用长成什么样。
- 异步 async
- 响应式
- 组件化开发：Facebook宣称，“用了React，你只需要开发组件”。开发一整套组件，再把它们拼装成应用。

## React Native 工作原理

原生代码与JavaScript代码通过桥接层进行交互，这是一个异步的批量串行处理过程。桥接层介于原生层和JavaScript代码之间，正如它的名称一样，它的作用很像桥（bridge）。

## iOS 开发日志：

- style layout : react native 组件默认都是相对定位(relative)的，flex 布局。所以不需要写 display 和 posistion，因此需要使用 absolute (绝对定位)的时候，都是相对父组件的定位。
- Dimensions 使用Dimensions.get('window') 获取 屏幕的尺寸 {width, height};
- 重复的组件，要给 key, key 必须保证唯一，要不会影响渲染和性能问题；
- Text 是有背景色的，如果外层容器边框有圆角，会遮挡边框，需设置 backgroundColor: transparent;（背景透明）
- Touchable 组件，里面只能是独立的组件，不能超过一个，一个以上需嵌套在一个 View 中。
- Image 当容器，可以实现背景图效果。新增ImageBackground
- Image 纯色图标可以使用 tintColor: '#999', 改变图片背景色
- fontFamily 文本内容被状态改变时，产生页面布局错乱时，要设置等宽字体 fontFamily: 'Helvetica'，List中的 Text 如果不设置等宽字体容易发生闪退；(新版应该没有此问题)
- View 作为父容器，内容较多或者包含 List —— 长列表等情况下，不设置 flex，会导致样式错乱，部分子组件高度无法撑开。
- Animated time 动画，串行动画
- onLayout 函数获取，组件的宽高，使用 onLayout 事件，获取最终渲染组件的实际尺寸。
- Touchable 组件包裹原生的组件View，不能是自定义组件
- borderBottomWidth:   使用 `StyleSheet.hairlineWidth` 解决0.5像素的边框在plus上的灰色bug
- automaticallyAdjustContentInsets bool

如果滚动视图放在一个导航条或者工具条后面的时候，iOS系统是否要自动调整内容的范围。默认值为true。（译注：如果你的ScrollView或ListView的头部出现莫名其妙的空白，尝试将此属性置为false）

- 使用 lodash/`debounce` 防止点击过快，延迟处理。适用于点击事件，输入事件等

- ScrollView vs FlatList onScroll 滚动问题，FlatList 支持手势滑动，可以实时获取 e.nativeEvent.contentOffset.y 的位置， `FlatList` 继承自 `PureComponent` 性能更优越(它们都可以设置 scrollEventThrottle={1} 不会错过每一帧滚动条位置，但是有性能损耗，减少使用，scrollEventThrottle={16}是比较标准的值，可以保持 每秒 60帧的速率运行, `60fps` 刷新频率)

- ScrollView 默认的overflow 是 hidden，如果想显示超出部分可以使用 overflow: 'visible'；
- 无需分页加载，下拉刷新等功能，还是建议使用 `ScrollView` ，滚动动画可以使用，`Animated.ScrollView`
- 如果想让组件高度自适应，达到最大高度时出现滚动条，类似于 css 的 (overflow: scroll, overflow-y: scroll)可以使用下面的布局方式：(内容高度不超过300 是实际高度，超过300部分隐藏，滚动显示)

```html
<View style={{maxHeight: 300}}>
  <ScrollView>
    {列表或者长内容}
  </ScrollView>
</View>
```

- ScrollView 隐藏滚动条样式，showsHorizontalScrollIndicator={false} 不显示横向滚动条，showsVerticalScrollIndicator={false} 垂直滚动条样式隐藏。
- 图文混排，块级元素，需要用View包裹在一起，使用 `alignSelf` 控制自身的布局方式。例如：

```html
// 这里的mergin 不起作用，可以使用 空格代替
<Text>
<View><Text>特殊文字（需要背景，边框，边距，圆角等）<Text></View>其它文字
</Text>
<Text>
<View><Image>特殊文字（需要背景，边框，边距，圆角等）<Image></View>其它文字
</Text>
```

- Model 绝对定位组件是相对于父级定位的，如果想要达到fixed效果，要在根节点下使用绝对定位，或者使用MODEL 模式窗口组件。
- Alert.alert 样式问题，待。。。。
- ScrollView or FlatList 横向滚动时，需要明确指定高度，否则渲染时可能出现显示不全等样式问题
- Image 平铺方式，作为背景图，拉伸撑满整个容器使用，拉伸至容器的宽高，图片会变形 resizeMode='stretch'，默认 cover 使图像保持宽高比，超出部分裁剪掉，contain 使图像保持宽高比，不会超出容器，图像都会包含在容器中，多余的空间补白，repeat 重复平铺

- shoundupdate 合理使用减少渲染次数。froceupdate 强制更新组件
- 键盘遮挡输入框的问题：根据键盘展开/收起事件，使用 merginBottom 将输入框位置顶起；

```js
componentWillUnmount() { // 离开时要记得 移除键盘事件监听
  super.componentWillUnmount();
  this.keyboardDidShowListener.remove();
  this.keyboardDidHideListener.remove();
}

componentWillMount() {
  this.keyboardDidShowListener = Keyboard.addListener(
    'keyboardDidShow',
    this._keyboardDidShow.bind(this) // 键盘弹起时处理
  );
  this.keyboardDidHideListener = Keyboard.addListener(
    'keyboardDidHide',
    this._keyboardDidHide.bind(this) // 键盘收起时处理
  );
}

_keyboardDidShow(e) {
  this.setState({
    keyboardHeight: e.startCoordinates.height // 键盘实际的高度
  });
}

_keyboardDidHide(e) {
  this.setState({
    keyboardHeight: 0
  });
}
```

## Android 端出现的问题

- 安卓发现一个布局bug，和背景图片溢出的bug类似，当内容需要多行显示，加了maxHeight和overflow: 'hidden'安卓不起作用，内容超出了maxHeight，需要加上 backgroundColor: 'transparent'
- 安卓下Picker问题：给Picker加一个唯一的key，每次setState()时都使用不一样的key，例如 key=_.uniqueId( )
- 安卓兼容性处理： ios顶部的用于显示信号、时间、电池容量的部分，大约占位20px，RN IOS会将这一部分和页面内容重叠，所以一般会加20px的留白。RN ANDROID则将一部分隔离开了，因此device_styles.js中添加了一个值：nav_top_padding，如果需要留白，统一使用(device_styles.nav_top_padding||0)。  尤其是以下类型的页面需要用到：首页地址栏(假设以后UI需要针对这里做细节调整)、自定义导航的页面(例如门店、结算、收银台等)。

- 模拟器上可能会出现背景图片最底部的一条线显示不全，真机上测试ok。目前仅测试了小米手机，具体出现这个问题时，不要在模拟器上纠结，看看真机，真机ok就ok。

- 安卓上line-height处理错误。安卓上文本会显示在靠下方的位置。解决方法：如果是单行文本，尽量将行高和font-size设置为差距不大的值，例如font-sise是12px，实际期望的行高是44px，那么就将行高设置14或16，然后设置一个paddingTop。 如果是多行文本，可使用？？？？

- 使用css sprites做背景图时，容器上加个background-color可以解决背景图片溢出的bug。 使用overflow:hidden无效

- 当只给View设置部分border，例如只设置borderLeft、borderTop时，给这个View添加borderRadius会导致这个元素消失。 解决：common/device/styles.js中提供函数compatibleRemoveBorderRadius( )，这个函数判断了如果是安卓，borderRadius会设置为0

- 溢出部分被隐藏的bug：使用绝对定位将元素定位到父元素之外，正常情况下，父元素不设置overflow:hidden的话，子元素应该可见，但安卓上不可见。 仅在以下情况满足时出现这个bug：父元素样式中包含：zIndex border background-color 或父元素属性上含onLayout [参考：](https://github.com/facebook/react-native/issues/12534)
