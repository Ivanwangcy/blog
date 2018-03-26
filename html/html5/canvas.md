# canvas 元素介绍

它有默认宽高 300 * 150，不能用单纯的css 样式设置尺寸，需要用 js 处理。

尽可能花最短的时间完成任务，先不要写代码，要从程序逻辑开始，按照思路转换代码。

* 给 canvas 元素设置一个宽高，宽高和浏览器一样；
  * 获取 canvas 元素；
  * 获取浏览器宽高；
  * 给 canvas 元素设置宽高；

```html
<canvas class="bubble"></canvas>
```

```js
<!-- 获取 canvas 元素 -->
var canvas = document.querySelector('.bubble')
<!-- 获取浏览器宽高； -->
var width = window.innerWidth;
var height = window.innerHeight;


```