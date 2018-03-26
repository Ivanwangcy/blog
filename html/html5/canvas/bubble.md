# 使用 canvas 开发 bubble 示例

它有默认宽高 300 * 150，不能用单纯的css 样式设置尺寸，需要用 js 处理。

尽可能花最短的时间完成任务，先不要写代码，要从程序逻辑开始，按照思路转换代码。

* 给 canvas 元素设置一个宽高，宽高和浏览器一样；
  * 获取 canvas 元素；
  * 获取浏览器宽高；
  * 给 canvas 元素设置宽高；
  * 当浏览器宽高发生变化时重新设置 canvas 宽高；
* 如何利用 canvas 绘制图形

```html
<canvas class="bubble"></canvas>
```

```js
//  获取 canvas 元素
var canvas = document.querySelector('.bubble')
//  获取浏览器宽高
var width,height;
var setSize = function () {
  width = window.innerWidth;
  height = window.innerHeight;
  canvas.width = width;
  canvas.height = height;
}
setSize()
window.onresize = setSize


var context = canvas.getContext('2d')
```

确保`1秒钟60帧`动画非常流畅。