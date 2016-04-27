## ES6 新增语法简介
## let 关键字
```javascript
let param = 123;
```
## const 关键字
## 函数式声明 箭头函数
```javascript
let add = x => x + x;
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
### 合并数组
扩展运算符提供了数组合并的新写法。
```javascript
// ES5
[1, 2].concat(more)
// ES6
[1, 2, ...more]

var arr1 = ['a', 'b'];
var arr2 = ['c'];
var arr3 = ['d', 'e'];

// ES5的合并数组
arr1.concat(arr2, arr3));
// [ 'a', 'b', 'c', 'd', 'e' ]

// ES6的合并数组
[...arr1, ...arr2, ...arr3]
// [ 'a', 'b', 'c', 'd', 'e' ]
```
### 拆分字符串
扩展运算符还可以将字符串转为真正的数组。
```javascript
[...'hello']
// [ "h", "e", "l", "l", "o" ]
```
## 推荐阅读：
[ECMAScript 6入门](http://es6.ruanyifeng.com/)
