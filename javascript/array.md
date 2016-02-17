# Array 数组对象
Array 是JavaScript最常用的内置对象之一。Array 可以作为一个构造函数，生成新的数组。
*通常使用对象字面量来生成一个数组对象，不推荐使用构造函数。*
```javascript
var arr = [1, 2];
```
# Array对象的 静态方法

## isArray方法

Array.isArray方法用来判断一个值是否为数组。它可以弥补typeof运算符的不足。
```javascript
var a = [1, 2, 3];

typeof a // "object"
Array.isArray(a) // true
```
上面代码表示，typeof运算符只能显示数组的类型是Object，而Array.isArray方法可以对数组返回true。
# Array对象的 实例方法
Array实例对象的方法，都是数组实例才能使用。如果不想创建实例，只是想单纯调用这些方法，可以写成[].method.call(调用对象，参数) 的形式，或者Array.prototype.method.call(调用对象，参数)的形式。
## valueOf方法，toString方法

valueOf方法返回数组本身。
```javascript
var a = [1, 2, 3];
a.valueOf() // [1, 2, 3]
```
toString 方法返回数组的字符串形式。
```javascript
var a = [1, 2, 3];
a.toString() // "1,2,3"

var a = [1, 2, 3, [4, 5, 6]];
a.toString() // "1,2,3,4,5,6"
```
## push方法，pop方法
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
