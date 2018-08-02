# 利用节流和防抖优化页面性能

防抖和节流是前端性能优化的常用手段，在 React Native 中同样非常适用。尤其要是追求媲美原生的极致体验，那就更不可少了。

## 举例说明一些场景

- 搜索框，用户在输入过程中会频繁调用搜索接口，需要给个延迟，等用户真正输入完再调接口，如果不进行优化会：
  - 对用户的影响：用户体验差，额外消耗用户浏量，耗费手机内存；
  - 对公司的影响埋点数据不准确，增加服务器负担，不必要的渲染影响页面性能；
- 交互按钮，过快点击会重复执行按钮逻辑，比如，点击按钮后会创建一个弹层，点击过快后会创建两个弹层，严重影响用户体验和页面性能；
- 如果点击按钮会发起请求，会频繁调用接口，增加服务器压力。比如：
  - 提单按钮，用户手速比较快出现了重复的订单；
  - 加车按钮，快速且持续的加/减购物车，会造成加车动画卡顿，渲染慢，接口调用太频繁会报错；
- 跳转页面的组件，如果点快了，会出现两个新开页面（在这里吐槽一下商城的入口球，快速点击到家入口球会进入两次到家首页重叠在一起，返回一次还是到家首页，我们在做埋点统计的时候就发现了这个问题，出现了重复的首页埋点，其它入口球或者跳转页面的按钮同样有这种问题），这种情况下一定要做限制；
- 手势操作和滚动条事件的实时监听会对性能有影响，对一些低端手机不友好存在丢帧问题。

**React Native 中的滚动条组件（ScrollView, ListView, FlatList, SectionList 等）都提供了节流的功能，只需设置 `scrollEventThrottle` 属性**

> scrollEventThrottle 属性说明：将控制滚动时滚动事件触发的频率（以毫秒为单位的时间间隔）。`较小的数字`会为跟踪滚动位置的代码提供更高的准确性，但由于通过桥接层发送的数据量过大会导致滚动性能问题。JS 运行循环同步到屏幕刷新率时，不会注意到 1-16 之间的值有所不同。如果不需要精确的滚动位置跟踪，请将此值设置得较高以限制通过桥接层发送的数据量。默认值为零，这会导致每次滚动视图时滚动事件仅发送一次。（值越小越精确，如果追求动画效果需要设置 1 - 16，`使用 1 可以确保不会遗漏任何事件，滚动位置取值精确；使用 16 1000ms/60fps= 16ms 最佳效果，每秒钟刷新 60 次`）

## 防抖和节流函数的使用

- `debounce` : 防抖函数，控制一个函数在触发的指定周期内只允许调用一次；
- `throttle` : 在函数持续执行过程中减少执行的频率；

目前 lodash 是比较流行的函数库，它对防抖和节流封装的非常好。以 lodash 函数库为例。
首先需求安装 [lodash](https://github.com/lodash/lodash) 代码库：

```sh
npm i -S lodash
```

导入函数：

```js
// 可以采用不同的加载方式
// 解构方式导入 debounce, throttle，会加载整个函数库，如果项目中大量使用 lodash 函数这样导入很方便
import { debounce, throttle } from "lodash";

// 只导入防抖和节流函数，这样可以减少代码体积，lodash 其它函数不会被打包
import debounce from "lodash/debounce";
import throttle from "lodash/throttle";
```

具体的用法很简单，debounce/throttle 用法一样，throttle 就是使用 debounce 实现的，一般情况只传两个参数即可：

- func (Function): 需要限制的函数
- [wait=0](number): 需要延迟的毫秒数

- [options={}](Object): 其它选项（可以不传）
  - options 选项中的 leading 默认 false， 开始延时之前调用函数；
  - options 选项中的 trailing 默认 true, 延时时间过后调用函数；

在必要的地方使用 debounce/throttle 封装一下函数即可：

```js
<TouchableWithoutFeedback
    onPress={debounce(() => {
      this.handlePress();
    }, 200, {leading: false, trailing: true}/* 默认值 */).bind(this)}
  >
</TouchableWithoutFeedback>

<TouchableWithoutFeedback
    onPress={throttle(() => {
      this.handlePress();
    }, 200, {leading: true, trailing: true}/* 默认值 */).bind(this)}
  >
</TouchableWithoutFeedback>
```
