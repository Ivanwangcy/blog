# dom 操作
# JS控制滚动条的位置
```javascript
// 获取当前元素距离顶部的位置
element.getBoundingClientRect().top; // 当前元素处于滚动元素顶部的位置
scrollElement.scrollTop; // 滚动元素的滚动位置，可以赋值操作（定位）

// JQuery 滚动元素距离顶部的位置
$(".scroller").scrollTop() // 同 scrollTop 可以赋值操作（定位）
```
