# 工作中常见问题
## 无痕浏览
无痕模式下不支持sessionStorage 和 localStorage, 需要异常检测。
```javascript
var sessionStorageEnabled = false;
try{
    sessionStorage.setItem('1','1');
    sessionStorageEnabled = true;
} catch(e){ }
```
## tap 与 click

## 动态获取当前URL
```javascript
location.protocol + '//' + location.host + location.pathname + location.hash
```
