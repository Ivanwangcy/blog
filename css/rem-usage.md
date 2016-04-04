# Rem 应用
## 预备知识：
- html 根元素的默认字体大小为16px, 所有浏览器统一是这个值, 可以使用以下方法获取浏览器的预设值:
```javascript
window.getComputedStyle(window.document.documentElement)['font-size']; // 获取浏览器预设置的 font-size
```
```css
html{
  font-size: 16px; /* 设置默认值 */
}
```
- viewport 设置
```html
<meta name="viewport"
content="
 height = [pixel_value | device-height] ,
 width = [pixel_value | device-width ] ,
 initial-scale = float_value ,
 minimum-scale = float_value ,
 maximum-scale = float_value ,
 user-scalable = [yes | no] ,
 target-densitydpi = [dpi_value | device-dpi | high-dpi | medium-dpi | low-dpi]
 "
/>
```
## 使用 rem 方式一
首先设置 viewport 属性固定的缩放比例. 不允许用户手动缩放.
```html
<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, minimum-scale=1, user-scalable=no">
```
尝试设置html的font-size, 适配各种尺寸的屏幕

```javascript
document.getElementsByTagName('html')[0].style.fontSize="62.5%"; // => 10px  但是10px PC端不支持, 可以再乘以 2;
// 例如: 设计稿宽 750px width: 37.5rem;
// 固定值, 不会适配各种屏幕, 和现在的作法一样 是等价的, 只是把单位 从 px 统一转换为  rem 按照设计稿计算为: 设计像素/20;
//
// 为了凑整 使用
 document.getElementsByTagName('html')[0].style.fontSize="125%";// =>  20px  rem 按照设计稿计算为: 设计像素/20/ 再除以2;
 // 例如: 设计稿宽 750px width: 18.75rem;
 console.log(getComputedStyle(window.document.documentElement)['font-size']); // 获取浏览器预设置的 font-size
 document.getElementsByTagName('html')[0].style.fontSize="312.5%";// =>  50px  rem 按照设计稿计算为: 设计像素/100, 可以更好的计算rem;
//  例如: 设计稿宽 750px width: 7.5rem;
//
//  如果要适配 各个屏幕, 计算思路: 50/16 * (window.innerWidth/375) 获取百分比 再 * 16 = 像素值 , 简化后html的font-size 像素值 = window.innerWidth/7.5;
 document.getElementsByTagName('html')[0].style.fontSize= 50/16 * (window.innerWidth/375) * 100 + "%"; // 获取百分比思路, 计算过程清晰
 document.documentElement.style.fontSize = window.innerWidth / 7.5 + "px"; // 同上 简化后
 // 这样就可以在项目中直接使用设计稿的样式来设置所有元素的rem属性, 设计稿尺寸/100 = *rem;
 @function px2rem($px){
     $rem : 100;
     @return ($px/$rem) + rem;
 }
```
[参考网易新闻的设计](http://3g.163.com/touch/all?version=v_standard)
## 使用 rem 方式二 动态设置屏幕缩放比例, 和 根元素 font-size 大小
```javascript
var meta = document.createElement("meta");
meta.setAttribute("name", "viewport");
var dpr = window.devicePixelRatio;
 meta.setAttribute('content', 'initial-scale=' + 1/dpr + ', maximum-scale=' + 1/dpr + ', minimum-scale=' + 1/dpr + ', user-scalable=no'); // 动态设置 缩放比例
window.document.head.appendChild(meta);
document.addEventListener('DOMContentLoaded', function(e) {
        document.getElementsByTagName('html')[0].style.fontSize=window.innerWidth/10+'px'; // 动态设置 根元素 字体大小
},false);
// 适配各种屏幕, 计算 rem 值比较麻烦, 如果使用预处理css程序就非常简便了, 例如: sass, less, stylus;
// 像素更精确 rem = 设计像素/75 固定的基数 75
@function px2rem($px){
    $rem : 75;
    @return ($px/$rem) + rem;
}
```
[参考淘宝的作法](https://m.taobao.com/#index)
## 使用 rem 方式三 结合使用以上两种方式 **像素值最贴近设计稿**
```javascript
var meta = document.createElement("meta");
meta.setAttribute("name", "viewport");
var dpr = window.devicePixelRatio;
 meta.setAttribute('content', 'initial-scale=' + 1/dpr + ', maximum-scale=' + 1/dpr + ', minimum-scale=' + 1/dpr + ', user-scalable=no'); // 动态设置 缩放比例
window.document.head.appendChild(meta);
document.addEventListener('DOMContentLoaded', function(e) {
        document.getElementsByTagName('html')[0].style.fontSize=window.innerWidth / 7.5 + 'px'; // 动态设置 根元素 字体大小
},false);
// 适配各种屏幕, 计算 rem 值比较麻烦, 如果使用预处理css程序就非常简便了, 例如: sass, less, stylus;
// 像素更精确 rem = 设计像素/75 固定的基数 75
@function px2rem($px){
    $rem : 100;
    @return ($px/$rem) + rem;
}

让 html font-size 更小点 可以使用
document.getElementsByTagName('html')[0].style.fontSize=window.innerWidth / 75 + 'px'; // 动态设置 根元素 字体大小

($px/10) + "rem";
```
