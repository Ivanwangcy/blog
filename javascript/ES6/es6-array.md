# ES6
2015年2月20日ECMAScript 第六版正式推出。

## Array.map() 用法 ES5
```javascript
var names = ['Alice', 'Emily', 'Kate'];
var newNames = names.map(function(name){
  return "Hello " + name;
});
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
##
