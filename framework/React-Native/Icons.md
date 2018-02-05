## 图标资源 - 组件化管理

## react native 中图片组件的使用参考链接：
[https://reactnative.cn/docs/0.51/images.html](https://reactnative.cn/docs/0.51/images.html)

## 统一图标入口
```js
let icons = {
  /**
   * [通用图标]
   * @type {[png]}
   */
  // 箭头图标
  FowordArrow: require('./common/FowordArrow.png'),
  // 问号图标，说明文案
  Help: require('./common/help.png'),
  // 定位图标 （结算页在用）
  // SettlePosition: require('./common/SettlePosition.png'),
  // 统一弹窗 关闭按钮图标
  X: require('./common/X.png'),


  /**
   * [结算图标]
   * @type {[png]}
   */
   OrderMark: require('./settlement/OrderMark.png'),
   SettlePosition: require('./settlement/address.png')


   /**
    * [CDN 图标]
    * @type {[png]}
    */

}

export default icons
```
