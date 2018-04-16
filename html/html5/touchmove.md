# touch 事件

## touchmove 事件滑动位置计算

zepto 的 swipe 事件或原生 touch 事件，如何获取移动的距离~  
监听 touchstart 事件， 计算起始位置
pageX(相对于窗口的水平坐标像素,包括任何滚动偏移量)；
pageY(相对于窗口的水平坐标像素,包括任何滚动偏移量);

```javascript
(function() {
  var el = document.querySelector(".test");
  var startPosition, endPosition, deltaX, deltaY, moveLength;

  el.addEventListener("touchstart", function(e) {
    var touch = e.touches[0];
    startPosition = {
      x: touch.pageX,
      y: touch.pageY
    };
  });

  // 每时每刻都想查看滑动距离使用 touchmove
  el.addEventListener("touchmove", function(e) {
    var touch = e.touches[0];
    endPosition = {
      x: touch.pageX,
      y: touch.pageY
    };

    deltaX = endPosition.x - startPosition.x;
    deltaY = endPosition.y - startPosition.y;
    moveLength = Math.sqrt(
      Math.pow(Math.abs(deltaX), 2) + Math.pow(Math.abs(deltaY), 2)
    );
    console.log(moveLength);
  });

  // 只想获取松手时的滑动距离可以直接使用 touchend 事件
  el.addEventListener("touchend", function(e) {
    // console.log(e.changedTouches);
    var touch = e.changedTouches[0];
    endPosition = {
      x: touch.pageX,
      y: touch.pageY
    };

    deltaX = endPosition.x - startPosition.x;
    deltaY = endPosition.y - startPosition.y;
    moveLength = Math.sqrt(
      Math.pow(Math.abs(deltaX), 2) + Math.pow(Math.abs(deltaY), 2)
    );
    console.log(moveLength);
  });
})();
```

## 阻止 touch 事件

```js
document.addEventListener('touchmove', this._preventDefalut, {passive: false})

 var preventTouchmove = function (e) {
    console.log($(e.target), $(e.target).closest('.ctrlSelectmenuWrapper'))
    if (!($(e.target).hasClass('ctrlSelectmenuWrapper') || $(e.target).closest('.ctrlSelectmenuWrapper').length > 0)) {
        console.log($(e.target), $(e.target).closest('.ctrlSelectmenuWrapper'))
        e.preventDefault();
    }
}

var supportsPassive = false;
try {
    var opts = Object.defineProperty({}, 'passive', {
        get: function () {
            supportsPassive = true;
        }
    });
    window.addEventListener("testPassive", null, opts);
    window.removeEventListener("testPassive", null, opts);
} catch (e) { }

window.addEventListener('touchmove', preventTouchmove, supportsPassive ? { passive: true } : false); 

window.removeEventListener('touchmove', preventTouchmove, supportsPassive ? { passive: true } : false)

```

console.log 出来的 moveLength 就是你要得到的距离。

可以参考 Zepto 的：[touch 源码](https://github.com/madrobby/zepto/blob/master/src%2Ftouch.js)

## scrollEnd

```javascript
$(window).scroll(
  _.debounce(
    function() {
      $("#scrollMsg").html("SCROLLING!");
    },
    150,
    { leading: true, trailing: false }
  )
);

$(window).scroll(
  _.debounce(function() {
    $("#scrollMsg").html("STOPPED!");
  }, 150)
);
```


