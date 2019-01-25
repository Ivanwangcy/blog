# ES6 Array 数组新增方法

2015 年 2 月 20 日 ECMAScript 第六版正式推出。一起来回顾一下 ES5 的函数，函数式编程会经常用到。

## Array.map() 数组映射

用法 ES5 修改原数组, 并返回更新后的数组

```javascript
var names = ['Alice', 'Emily', 'Kate'];
var newNames = names.map(function(name) {
  return 'Hello ' + name;
});
```

## Array.concat() 合并多个数组

```javascript
var arr = [1,2,3]
arr.concat([4,5,6])
// [1, 2, 3, 4, 5, 6]

```
## Array.some() 用法 ES5
```js

```

## Array.from() 用法 ES6 新增

将对象转换成数组，包括类数组（arguments 对象, DOM 操作返回的 NodeList 集合）。

```javascript
var names = { '0': 'Alice', '1': 'Emily', '2': 'Kate', length: 3 };
var names = { 0: 'Alice', 1: 'Emily', 2: 'Kate', length: 3 };
var newArray5 = [].slice.call(names); // ES5 写法
var newArray6 = Array.from(names); // ES6 写法
console.log('%s and %s', newArray5, newArray6);

// 字符串也可以使用Array.from
Array.from('hello');
// ['h', 'e', 'l', 'l', 'o']
```

## Array.of() 转换数组

```javascript
Array.of(3, 11, 8); // [3,11,8]
```

## Array.find() 查找

## Array.reduce() 数组求和/汇总函数

```js
// 循环次数 == arr.length - 1
// accumulator 初始为 数组第一个值
// nextValue 初始为 数组第二个值
Array.reduce((accumulator, nextValue) => {
  return accumulator + nextValue;
});
```

## Array.sort() 排序

```js
```
## Array.find()

```js
```
## Array.findIndex()

```js
let findIndex = [0, '1', 1, 2,3,4].findIndex(value => {
    console.log(value);
   return value === 1; // 为 true 时立即返回，其余数据不再遍历
});
```

## 创建连续的数组

```js
[...Array(1000)].map((v, k) => k + 1)
// output: [ 1, 2, 3, 4, 5, 6, ..., 1000]

Array(10).fill(5);
// output [5, 5, 5, 5, 5, 5, 5, 5, 5, 5]

// 类似的字符串方法：
'5'.repeat(10) // "5555555555"
```
