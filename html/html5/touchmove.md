# touch 事件
# touchmove 事件滑动位置计算
touchstart 计算起始位置
pageX(相对于窗口的水平坐标像素,包括任何滚动偏移量)；
pageY(相对于窗口的水平坐标像素,包括任何滚动偏移量);

```javascript
(function () {
    var el = document.querySelector('.test');
    var startPosition, endPosition, deltaX, deltaY, moveLength;

    el.addEventListener('touchstart', function (e) {
        var touch = e.touches[0];
        startPosition = {
            x: touch.pageX,
            y: touch.pageY
        }
    });

    el.addEventListener('touchmove', function (e) {
        var touch = e.touches[0];
        endPosition = {
            x: touch.pageX,
            y: touch.pageY
        }

        deltaX = endPosition.x - startPosition.x;
        deltaY = endPosition.y - startPosition.y;
        moveLength = Math.sqrt(Math.pow(Math.abs(deltaX), 2) + Math.pow(Math.abs(deltaY), 2));
        console.log(moveLength);
    });
})();
```
console.log出来的moveLength就是你要得到的距离。  

可以参考Zepto的：[touch源码](https://github.com/madrobby/zepto/blob/master/src%2Ftouch.js)
