# 变量的解构赋值
## 数组解构
```javascript
scores = [3, 8];
// [3, 8]
  var [winningIndex, losingIndex] = scores[0] > scores[1] ? [0,1] : [1,0];
winningIndex
// 1
losingIndex
// 0
```
## 对象解构
