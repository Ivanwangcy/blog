# touches 移动端触屏事件
Click 事件在移动设备上有300ms的延时, 为了获取更好的用户体验, 我们需要使用touch事件. 比较有代表性的实现有 fastclick, zepto的touch模块(有点击穿透的BUG). 一些流行的框架也都封装的touch事件. 开发移动应用, 必须要了解. 
## touchmove 滑动的开关
```javascript
$(window).bind('touchmove',function(e){
  var $element = $(e.target);
     if($element.closest('.address-pop-cont').length <= 0 && !($element.hasClass('.address-pop-cont'))){
       e.preventDefault(); // 阻止一切toucmove事件。.address-pop-cont和他的子类允许滚屏
     }else{
       e.stopImmediatePropagation(); // toucmove 停止传播
     }
  });
$('.address-pop-cont').bind('touchmove',function(e){
       e.stopPropagation(); //
  });
```
