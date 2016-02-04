## ES6 新增语法
## let 关键字
```javascript
let param = 123;
```
## const 关键字
## 函数式声明
```javascript
let add = x => x+x;
```
## 扩展运算符
扩展运算符（spread）是三个点（...）。它好比rest参数的逆运算，将一个数组转为用逗号分隔的参数序列。
```javascript
console.log(...[1,2,3]);
// 1 2 3
```
### 替代数组的apply方法
由于扩展运算符可以展开数组，所以不再需要apply方法，将数组转为函数的参数了。
```javascript
// ES5的写法
Math.max.apply(null, [14, 3, 77])

// ES6的写法
Math.max(...[14, 3, 77])

// 等同于
Math.max(14, 3, 77);
```
