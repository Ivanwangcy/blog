# 定位API
获取当前位置信息
```javascript
navigator.geolocation.getCurrentPosition(function(position){
  console.log(position)
});
//监听地址变化
navigator.geolocation.watchPosition(function(position){
  console.log(position)
});
```
