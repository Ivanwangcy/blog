# React Native 历史演进

React Native 起源于 2013 年夏天的一次黑客马拉松项目。
React，这个用于构建用户界面的 JavaScript 库，就是 React Native 的核心。

React 具有声明式、异步、响应式的特性：

* 声明式编程：就是你编写代码描述想要做什么，而不是怎么做。只需告诉 React，你希望应用长成什么样。
* 异步 async
* 响应式
* 组件化开发：Facebook 宣称，“用了 React，你只需要开发组件”。开发一整套组件，再把它们拼装成应用。

## React Native 工作原理

原生代码与 JavaScript 代码通过桥接层进行交互，这是一个异步的批量串行处理过程。桥接层介于原生层和 JavaScript 代码之间，正如它的名称一样，它的作用很像桥（bridge）。

## iOS 开发日志：

* style layout : react native 组件默认都是相对定位(relative)的，flex 布局。所以不需要写 display 和 posistion，因此需要使用 absolute (绝对定位)的时候，都是相对父组件的定位。
* Dimensions 使用 Dimensions.get('window') 获取 屏幕的尺寸 {width, height};
* 重复的组件，要给 key, key 必须保证唯一，要不会影响渲染和性能问题；
* Text 是有背景色的，如果外层容器边框有圆角，会遮挡边框，需设置 backgroundColor: transparent;（背景透明）
* Touchable 组件，里面只能是独立的组件，不能超过一个，一个以上需嵌套在一个 View 中。
* Image 当容器，可以实现背景图效果。新增 ImageBackground
* Image 纯色图标可以使用 tintColor: '#999', 改变图片背景色
* fontFamily 文本内容被状态改变时，产生页面布局错乱时，要设置等宽字体 fontFamily: 'Helvetica'，List 中的 Text 如果不设置等宽字体容易发生闪退；(新版应该没有此问题)
* View 作为父容器，内容较多或者包含 List —— 长列表等情况下，不设置 flex，会导致样式错乱，部分子组件高度无法撑开。
  - Animated time 动画，串行动画
* onLayout 函数获取，组件的宽高，使用 onLayout 事件，获取最终渲染组件的实际尺寸。
* Touchable 组件包裹原生的组件 View，不能是自定义组件
* borderBottomWidth: 使用 `StyleSheet.hairlineWidth` 解决 0.5 像素的边框在 plus 上的灰色 bug
* automaticallyAdjustContentInsets bool

如果滚动视图放在一个导航条或者工具条后面的时候，iOS 系统是否要自动调整内容的范围。默认值为 true。（译注：如果你的 ScrollView 或 ListView 的头部出现莫名其妙的空白，尝试将此属性置为 false）

-  使用 lodash/`debounce` 防止点击过快，延迟处理。适用于点击事件，输入事件等

* ScrollView vs FlatList onScroll 滚动问题，FlatList 支持手势滑动，可以实时获取 e.nativeEvent.contentOffset.y 的位置， `FlatList` 继承自 `PureComponent` 性能更优越(它们都可以设置 scrollEventThrottle={1} 不会错过每一帧滚动条位置，但是有性能损耗，减少使用，scrollEventThrottle={16}是比较标准的值，可以保持 每秒 60 帧的速率运行, `60fps` 刷新频率)

* ScrollView 默认的 overflow 是 hidden，如果想显示超出部分可以使用 overflow: 'visible'；
* 无需分页加载，下拉刷新等功能，还是建议使用 `ScrollView` ，滚动动画可以使用，`Animated.ScrollView`
* 如果想让组件高度自适应，达到最大高度时出现滚动条，类似于 css 的 (overflow: scroll, overflow-y: scroll)可以使用下面的布局方式：(内容高度不超过 300 是实际高度，超过 300 部分隐藏，滚动显示)

```html
<View style={{maxHeight: 300}}>
  <ScrollView>
    {列表或者长内容}
  </ScrollView>
</View>
```

* ScrollView 隐藏滚动条样式，showsHorizontalScrollIndicator={false} 不显示横向滚动条，showsVerticalScrollIndicator={false} 垂直滚动条样式隐藏。
* 图文混排，块级元素，需要用 View 包裹在一起，使用 `alignSelf` 控制自身的布局方式。例如：

```html
// 这里的mergin 不起作用，可以使用 空格代替
<Text>
<View><Text>特殊文字（需要背景，边框，边距，圆角等）<Text></View>其它文字
</Text>
<Text>
<View><Image>特殊文字（需要背景，边框，边距，圆角等）<Image></View>其它文字
</Text>
```

* Model 绝对定位组件是相对于父级定位的，如果想要达到 fixed 效果，要在根节点下使用绝对定位，或者使用 MODEL 模式窗口组件。
* Alert.alert 样式问题，待。。。。
* ScrollView or FlatList 横向滚动时，需要明确指定高度，否则渲染时可能出现显示不全等样式问题
* Image 平铺方式，作为背景图，拉伸撑满整个容器使用，拉伸至容器的宽高，图片会变形 resizeMode='stretch'，默认 cover 使图像保持宽高比，超出部分裁剪掉，contain 使图像保持宽高比，不会超出容器，图像都会包含在容器中，多余的空间补白，repeat 重复平铺

- shoundupdate 合理使用减少渲染次数。froceupdate 强制更新组件

* 键盘遮挡输入框的问题：根据键盘展开/收起事件，使用 merginBottom 将输入框位置顶起；

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
    keyboardHeight: e.startCoordinates ? e.startCoordinates.height : 216 // 键盘实际的高度， Android 不支持 startCoordinates 属性，可以写死
  });
}

_keyboardDidHide(e) {
  this.setState({
    keyboardHeight: 0
  });
}
```

## Android 端出现的问题

* 安卓发现一个布局 bug，和背景图片溢出的 bug 类似，当内容需要多行显示，加了 maxHeight 和 overflow: 'hidden'安卓不起作用，内容超出了 maxHeight，需要加上 backgroundColor: 'transparent'
* 安卓下 Picker 问题：给 Picker 加一个唯一的 key，每次 setState()时都使用不一样的 key，例如 key=\_.uniqueId( )
* 安卓兼容性处理： ios 顶部的用于显示信号、时间、电池容量的部分，大约占位 20px，RN IOS 会将这一部分和页面内容重叠，所以一般会加 20px 的留白。RN ANDROID 则将一部分隔离开了，因此 device_styles.js 中添加了一个值：nav_top_padding，如果需要留白，统一使用(device_styles.nav_top_padding||0)。 尤其是以下类型的页面需要用到：首页地址栏(假设以后 UI 需要针对这里做细节调整)、自定义导航的页面(例如门店、结算、收银台等)。

* 模拟器上可能会出现背景图片最底部的一条线显示不全，真机上测试 ok。目前仅测试了小米手机，具体出现这个问题时，不要在模拟器上纠结，看看真机，真机 ok 就 ok。

* 安卓上 line-height 处理错误。安卓上文本会显示在靠下方的位置。解决方法：如果是单行文本，尽量将行高和 font-size 设置为差距不大的值，例如 font-sise 是 12px，实际期望的行高是 44px，那么就将行高设置 14 或 16，然后设置一个 paddingTop。

* 使用 css sprites 做背景图时，容器上加个 background-color 可以解决背景图片溢出的 bug。 使用 overflow:hidden 无效

* 当只给 View 设置部分 border，例如只设置 borderLeft、borderTop 时，给这个 View 添加 borderRadius 会导致这个元素消失。 解决：common/device/styles.js 中提供函数 compatibleRemoveBorderRadius( )，这个函数判断了如果是安卓，borderRadius 会设置为 0

* 溢出部分被隐藏的 bug：使用绝对定位将元素定位到父元素之外，正常情况下，父元素不设置 overflow:hidden 的话，子元素应该可见，但安卓上不可见。 仅在以下情况满足时出现这个 bug：父元素样式中包含：zIndex border background-color 或父元素属性上含 onLayout [参考：](https://github.com/facebook/react-native/issues/12534)

- Android Text 文本被截断或者被省略的问题，font family 要用无衬线字体， 中文使用 Sans Serif，更合适：https://github.com/react-native-training/react-native-fonts;

- Android 小米手机，字体会被截断，一行显示多个文本标签，最后一个会变成省略号，需要给最后一个加上 flex, 控制其宽度；

- Android Text 标签不能嵌套其它类型的标签，例如 Image, View, Touchbale\* 等；

  * 嵌入 Image 在 Android 系统是允许的只是在不同机型产生的效果不一样，Bug 较多无法兼顾。
  * View, Touchbale\* 属于容器类组件在 Android 系统中会直接报错，需要判断平台再做相应处理，为 Android 降级，某些需求无法满足产品需要和产品测试确认问题；

- Andorid Text 标签不会自动撑开容器，有时会上边缘显示不全，需要增加行高，行高比字体大 2 个像素比较适宜；

- Andorid Text 如果带点击效果，要在外面加 View 扩大点击范围；

- Andorid Text 标签 Bug 较多，提取了一些共性到 DJText 组件中，没有特殊需求 建议大家直接使用 DJText 标签。 DJText: 支持所有 Text 的属性和样式，用法完全相同，默认是单行文本(大部分都是单行显示得)，如果多行文本不限制行数增加属性 numberOfLines={0}；

- Android TextInput 标签默认有下划线，文本不居中，提取了 DJTextInput 组件；

- Android FlatList 分页加载 onEndReachedThreshold 属性设置 0 时不会执行分页加载，推荐设置 {0.1}；

- Android 不支持获取键盘高度，可以写一个固定的高度；
- Android 不支持阴影效果，可以使用边框或者背景图代替；
- Android 使用 map 返回的组件列表某个条件创建组件，不满足就返回 null 在 Android 会有问题，可以使用 forEach 遍历 再 push 到一个新数组，例如：Picker 传 null 组件，系统会报错，示例代码如下：

```js
let pickerItem = selectedTimeList.map((item, index) => {
  return item ? <Picker.Item /> : null; // 如果返回 null 是不允许的
  return !!item && <Picker.Item />; // 这样返回 undefined 也是不允许的
});

// 解决方案
let arr = [];
selectedTimeList.forEach((item, index) => {
  if (item) arr.push(<Picker.Item />);
});
```

* Modal 组件在 Android 环境 app 切后台时不消失，也关不掉的问题，需要使用 AppState 状态判断前后台切换处理。

* 跳页面组件不能加样式，会卡死；

* Modal 组件内部获取组件状态需要 使用 onLayout 监听是否处于显示状态，隐藏时改变状态是无效的。

* FlatList 做列表元素定位功能很强大，可替代 ScrollView;

* 当 带有滚动条的组件 如：ScrollView，\*List，内部包含 TextInput 组件时需要使用：
  keyboardDismissMode，keyboardShouldPersistTaps 属性设置交互的方案；

* UIManager.measure获取组件高度在android获取不到解决方法:

```js
UIManager.measure(findNodeHandle(this.refs.moreCoupon),(x,y,width,height,pageX,pageY)=>{})
```

该方法获取组件高度在android中不起作用，需要在this.refs.moreCoupon组件的View中加上removeClippedSubviews={false}或者style={{opacity: 1}}，不然获取不到x,y,width,height,pageX,pageY（参考京东到家门店主页搜索框右边领券按钮）

## 2018 年9月开发问题记录

1. SectionList包在ScrollView里面：（问题缺少真正嵌套数据才能发现）
    如果给SectionList高度，那只能SectionList滑动，ScrollView时而能滑动，时而不能滑动。
    如果SectionList滑动的时候把ScrollView的scrollEnabled设置成false，SectionList和ScrollView都不能
    如果SectionList和ScrollView都设置成flex:1或者同一个高度，能解决货架层上推下拉问题，但是在android手机下SectionList不能检测到是否已经滑动底部(JDReact团队也提到过，事实确实这样)
2. SectionList如果一次性数据下发太多，渲染会卡死
3. Android 手势支持的不太好，导致上拉下拉出现一些问题；
4. FlatList 使用 scrollToIndex 跳到最后一条数据时跳不过去，解决方法是在最后面添加一个空白元素占位；
5. 一些文字类点击事件不敏感，需要增加高度和padding扩大点击范围；
6. 图片和文字横向排列时要用 flex 控制垂直居中比较准确，不需要自己加样式调整位置（例如加padding,margin，绝对定位等）；
7. 使用 ref 时一定要进行异常处理，否则会出现系统错误，造成卡死闪退等严重问题；
8. 图片圆角处理有View包裹时都，图片需要加圆角属性安卓才能起作用
9. UI 设计反复被修改（如果存在争议要留好证据）
10. 横向纵向滚动条都隐藏掉，UI 会找 Bug; 属性设置为 false showsHorizontalScrollIndicator and showsVerticalScrollIndicator