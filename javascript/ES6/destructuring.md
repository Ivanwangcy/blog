# 变量的解构赋值
## 数组解构
```javascript
  scores = [3, 8];
  // [3, 8]
  let [winningIndex, losingIndex] = scores[0] > scores[1] ? [0,1] : [1,0];
  winningIndex
  // 1
  losingIndex
  // 0

  let [a, [b, c]] = [1, [2, 3]]
```
## 对象解构
```js
  console.clear()
  
  let {a, b} = {a: 1, b: 2}

  let {a: {c, d}, e} = {a: {c: 3, d: 4}, e: 5}

  console.log(a, b, c, d, e); // 1, 2, 3, 4
```
