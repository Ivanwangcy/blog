# 数组操作
## split
## join
## reverse
# 示例
## 合并两个数组
如果需要合并两个数组，可以结合使用push()和apply()方法。
```javascript
var a = [1,2,3];
var b = [4,5,6];

// 利用apply方法 合并方式a在前b在后，如果需要可以改变a与b的顺序
Array.prototype.push.apply(a, b); // 写法一
[].push.apply(a, b); // 写法二
a.push.apply(a, b); // 写法三
```
