# dom 操作
## JS控制滚动条的位置
```javascript
// 获取当前元素距离顶部的位置
element.getBoundingClientRect().top; // 当前元素处于滚动元素顶部的位置
scrollElement.scrollTop; // 滚动元素的滚动位置，可以赋值操作（定位）

// JQuery 滚动元素距离顶部的位置
$(".scroller").scrollTop() // 同 scrollTop 可以赋值操作（定位）
```
## 获取隐藏元素的高度
需要增加样式, display为none的使用js改变样式；
```css
.artist-hide{
  position:absolute;
  visibility:hidden;
}
```
```javascript
$(".artist-hide").height();
```
## 根据元素高度判断是否显示更多按钮
需创建两个相同的元素
