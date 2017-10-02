# ES6 Array 数组新增方法
2015年2月20日ECMAScript 第六版正式推出。

## Array.map() 用法 ES5 修改原数组, 并返回更新后的数组
```javascript
var names = ['Alice', 'Emily', 'Kate'];
var newNames = names.map(function(name){
  return "Hello " + name;
});
```
## Array.concat() 合并多个数组
```javascript
var arr = [1,2,3]
arr.concat([4,5,6])
// [1, 2, 3, 4, 5, 6]
## Array.some() 用法 ES5
```javascript

```
## Array.from() 用法 ES6
将对象转换成数组，包括类数组（arguments对象, DOM操作返回的NodeList集合）。
```javascript
var names = {'0':'Alice', '1':'Emily', '2':'Kate', length: 3};
var names = {0:'Alice', 1:'Emily', 2:'Kate', length: 3};
var newArray5 = [].slice.call(names); // ES5 写法
var newArray6 = Array.from(names); // ES6 写法
console.log("%s and %s", newArray5, newArray6);

// 字符串也可以使用Array.from
Array.from('hello')
// ['h', 'e', 'l', 'l', 'o']
```
## Array.of()
```javascript
Array.of(3, 11, 8) // [3,11,8]
```
## Array.find()
# #
