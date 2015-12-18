# touches 移动端触屏事件

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
