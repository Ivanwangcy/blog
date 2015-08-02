#String.trim函数
```javascript
String.prototype.trim= function(){  
    // 用正则表达式将前后空格  
    // 用空字符串替代
    // 替换首尾空格
    return this.replace(/(^\s*)|(\s*$)/g, "");  
}
```
