# React Native 性能

使用 React Native 替代基于 WebView 的框架来开发 App 的一个强有力的理由，就是为了使 App 可以达到`每秒 60 帧`（足够流畅），并且能有类似原生 App 的外观和手感。因此我们也尽可能地优化 React Native 去实现这一目标，使开发者能集中精力处理 App 的业务逻辑，而不用费心考虑性能。但是，总还是有一些地方有所欠缺，以及在某些场合 React Native 还不能够替你决定如何进行优化（用原生代码写也无法避免），因此人工的干预依然是必要的。我们尽力提供非常流畅的的 UI 性能，但有时这是不可能的。

本文的目的是教给你一些基本的知识，来帮你排查性能方面的问题，以及探讨这些问题产生的原因和推荐的解决方法。

## 关于“帧”你所需要知道的

老一辈人常常把电影称为“移动的画”，是因为视频中逼真的动态效果其实是一种幻觉，这种幻觉是由一组静态的图片以一个稳定的速度快速变化所产生的。我们把这组图片中的每一张图片叫做一帧，而每秒钟显示的帧数直接的影响了视频（或者说用户界面）的流畅度和真实感。iOS 设备提供了每秒 60 的帧率，这就留给了开发者和UI系统大约 `16.67ms` 来完成生成一张静态图片（帧）所需要的所有工作。如果在这分派的 `16.67ms` 之内没有能够完成这些工作，就会引发‘丢帧’的后果，使界面表现的不够流畅。

下面要讲的事情可能更为复杂：请先调出你应用的开发菜单，打开 `Show FPS Monitor`. 你会注意到有两个不同的帧率.
![PerfUtil.png](/images/PerfUtil.png)

## JS 帧率（JavaScript线程）

对于大多数React Native应用程序，你的业务逻辑将在 JavaScript 线程上运行。这是React应用所在的线程，也是发生API调用，以及处理触摸事件等操作的线程。更新数据到原生支持的视图是批量进行的，并且在事件循环每进行一次的时候被发送到原生端，这一步通常会在一帧时间结束之前处理完（如果一切顺利的话）。如果JavaScript线程有一帧没有及时响应，就被认为发生了一次丢帧。 例如，你在一个复杂应用的根组件上调用了`this.setState`，从而导致一次开销很大的子组件树的重绘，可想而知，这可能会花费200ms也就是整整12帧的丢失。此时，任何由JavaScript控制的动画都会卡住。只要卡顿超过100ms，用户就会明显的感觉到。

这种情况经常发生在Navigator的切换过程中：当你push一个新的路由时，JavaScript需要绘制新场景所需的所有组件，以发送正确的命令给原生端去创建视图。由于切换是由JavaScript线程所控制，因此经常会占用若干帧的时间，引起一些卡顿。有的时候，组件会在 `componentDidMount` 函数中做一些额外的事情，这甚至可能会导致页面切换过程中多达一秒的卡顿。

另一个例子是触摸事件的响应：如果你正在JavaScript线程处理一个跨越多个帧的工作，你可能会注意到 `TouchableOpacity` 的响应被延迟了。这是因为JavaScript线程太忙了，不能够处理主线程发送过来的原始触摸事件。结果 `TouchableOpacity` 就不能及时响应这些事件并命令主线程的页面去调整透明度了。

## UI帧率 (主线程)

很多人已经注意到 NavigatorIOS 的性能比 Navigator 更好。原因是转换的动画完全在主线程上完成，因此它们不会被 JavaScript 线程中的掉帧所影响。

同样，当JavaScript线程卡住的时候，你仍然可以欢快的上下滚动 ScrollView，因为 ScrollView 运行在主线程之上（尽管滚动事件会被分发到JS线程，但是接收这些事件对于滚动这个动作来说并不必要）。

## 性能问题的常见原因

### 在开发模式下运行（`dev = true`）

在开发模式下运行时，JavaScript线程性能会受到很大影响。这是不可避免的：在运行时需要做更多的工作来为您提供良好的警告和错误消息，例如验证propTypes和其他各种断言。始终确保在[发布版本](https://facebook.github.io/react-native/docs/running-on-device#building-your-app-for-production)中测试性能。

### 使用 `console.log` 语句

运行打包应用程序时，这些语句可能会在 JavaScript 线程中造成严重的性能瓶颈。这包括调试库（如`redux-logger`）的调用，因此请确保在捆绑之前将其删除。你也可以使用这个 [babel plugin](https://babeljs.io/docs/en/babel-plugin-transform-remove-console/)来删除所有的 `consolog.*` 调用。你需要先用 npm 安装它 (`npm i babel-plugin-transform-remove-console --save`)，然后再编辑项目目录下的 `.babelrc`文件，如下所示：

```js
{
  "env": {
    "production": {
      "plugins": ["transform-remove-console"]
    }
  }
}
```

这会自动删除项目（生产）版本中的所有 `console.*` 调用。

### ListView 初始化渲染太慢或者大型长列表滚动性能太差

改用新的FlatList或SectionList组件。除了简化API之外，新的列表组件还具有显着的性能增强，主要的是对于任意数量的行几乎不变的内存使用。

如果您的FlatList渲染缓慢，请确保您已经实施了getItemLayout，以通过跳过对渲染项目的测量来优化渲染速度。

### 当重新渲染几乎没有变化的视图时，JS FPS 帧率严重降低

如果你使用的是 ListView ，则必须提供一个 `rowHasChanged` 函数，该函数可以通过快速定位是否需要重新渲染行来减少大量工作。如果您使用不可变的数据结构，这将与一致性检查同样简单。

同样的，你可以实现shouldComponentUpdate函数来指明在什么样的确切条件下，你希望这个组件得到重绘。如果你编写的是纯粹的组件（返回值完全由props和state所决定），你可以利用PureComponent来为你做这个工作。再强调一次，不可变的数据结构在提速方面非常有用 —— 当你不得不对一个长列表对象做一个深度的比较，它会使重绘你的整个组件更加快速，而且代码量更少。

### 使用动画改变图片的尺寸时，UI线程掉帧

在iOS上，每次调整Image组件的宽度或者高度，都需要重新裁剪和缩放原始图片。这个操作开销会非常大，尤其是大的图片。比起直接修改尺寸，更好的方案是使用`transform: [{scale}]`的样式属性来改变尺寸。比如当你点击一个图片，要将它放大到全屏的时候，就可以使用这个属性。

### Touchable系列组件不能很好的响应

有些时候，如果我们有一项操作与点击事件所带来的透明度改变或者高亮效果发生在同一帧中，那么有可能在onPress函数结束之前我们都看不到这些效果。比如在onPress执行了一个setState的操作，这个操作需要大量计算工作并且导致了掉帧。对此的一个解决方案是将onPress处理函数中的操作封装到requestAnimationFrame中：

```js
handleOnPress() {
  // 谨记在使用requestAnimationFrame、setTimeout以及setInterval时
  // 要使用TimerMixin（其作用是在组件unmount时，清除所有定时器）
  this.requestAnimationFrame(() => {
    this.doExpensiveAction();
  });
}
```

## Unbundling + inline requires (分拆与内联导入)