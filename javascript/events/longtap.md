# 简单的长按事件监听
使用touch事件处理, 未松手超过 750毫秒, 视为长按;
```javascript
handleLongtap: function(newitem){
  var This = this,
    listItem = newitem || $('.order-list-item'),
    isLongtap = false,
    timer;
    // console.log(listItem);
  listItem.bind('touchstart', function(event){
    // event.preventDefault();
    var $item = $(event.currentTarget);
    This.orderId = $item.attr("orderid");
    // console.log(This.orderId);
    timer = setTimeout( function() {
				isLongtap = true;  // 长按
        // alert("长按删除订单");
        This.popupConfirm($item);
		}, 750 );
    // console.log('touchstart');
  }).bind('touchmove touchend tap', function(event){
    clearTimeout(timer);
    isLongtap = false;
    // console.log(event.type);
  });
```
