# 定时器的使用
## setInterval and clearInterval
```javascript
var arr = [];

// 将多个定时器存放在数组中
arr.push(
  setInterval(
    function(){
      console.log(1);
    }, 1000)
  );
arr.push(
  setInterval(
    function(){
      console.log(2);
    }, 1000)
  );

// 清除全部定时器
arr.map(clearInterval);
```
 
# 
 #
