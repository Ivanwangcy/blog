# Array 数组对象

Array 是 JavaScript 最常用的内置对象之一。Array 可以作为一个构造函数，生成新的数组。
_通常使用对象字面量来生成一个数组对象，不推荐使用构造函数。_

```javascript
var arr = [1, 2];
```

# Array 对象的 静态方法

## isArray 方法

Array.isArray()方法用来判断一个值是否为数组。它可以弥补 typeof 运算符的不足。

```javascript
var a = [1, 2, 3];

typeof a; // "object"
Array.isArray(a); // true

// 实现
function isArray(arr) {
  return toString.call(arr) === "[object Array]";
}
```

上面代码表示，typeof 运算符只能显示数组的类型是 Object，而 Array.isArray 方法可以对数组返回 true。

# Array 对象的 实例方法

Array 实例对象的方法，都是数组实例才能使用。如果不想创建实例，只是想单纯调用这些方法，可以写成[].method.call(调用对象，参数) 的形式，或者 Array.prototype.method.call(调用对象，参数)的形式。

## valueOf 方法，toString 方法

valueOf 方法返回数组本身。

```javascript
var a = [1, 2, 3];
a.valueOf(); // [1, 2, 3]
```

toString 方法返回数组的字符串形式。

```javascript
var a = [1, 2, 3];
a.toString(); // "1,2,3"

var a = [1, 2, 3, [4, 5, 6]];
a.toString(); // "1,2,3,4,5,6"
```

## push()方法，pop()方法

`push()`向`Array`的末尾添加若干元素，`pop()`则把`Array`的最后一个元素删除掉：

```javascript
var arr = [1, 2];
arr.push("A", "B"); // 返回Array新的长度: 4
arr; // [1, 2, 'A', 'B']
arr.pop(); // pop()返回'B'
arr; // [1, 2, 'A']
arr.pop();
arr.pop();
arr.pop(); // 连续pop 3次
arr; // []
arr.pop(); // 空数组继续pop不会报错，而是返回undefined
arr; // []
```

## unshift()和 shift()方法

使用`unshift()`方法，往`Array`的头部添加若干元素，`shift()`方法则把`Array`的第一个元素删掉：

```javascript
var arr = [1, 2];
arr.unshift("A", "B"); // 返回Array新的长度: 4
arr; // ['A', 'B', 1, 2]
arr.shift(); // 'A'
arr; // ['B', 1, 2]
arr.shift();
arr.shift();
arr.shift(); // 连续shift 3次
arr; // []
arr.shift(); // 空数组继续shift不会报错，而是返回undefined
arr; // []
```

## slice 方法

Array.slice 截取数组在 JavaScript 中，Array 对象的 slice(start[,end])方法返回数组从下标[start,end)的部分（不包含下标为 end 的元素）如果没有指定 end 参数，则从 start 开始到数组结尾的部分，slice()方法不改变原数组，如果要删除数组的一部分，可以使用 splice()方法。  
参数：

1. start:开始截取的数组下标，如果 start 是负数，表明从数组尾部开始计算。
2. end:结束截取的数组下标，如果 end 是负数，表明从数组尾部开始计算。

```javascript
// 不改变原数组
var friends = ["Spencer", "Rowan", "Mikenzi", "Alex"];
friends.slice(0, 3); // 返回新数组
friends.slice(0, 3);
friends.slice(0, 3);
```

## splice 方法

Array.splice(start,delete_count,value,...) 插入、删除、替换数组.  
参数：

1. start:开始插入和（或）删除的数组元素的下标。
2. delete_count:结束截取的数组下标，如果 end 是负数，表明从数组尾部开始计算。
3. value,...：要插入数组的元素。
4. 返回：如果从数组中删除了元素，则返回的是被删除的元素的数组

```javascript
// 删除指定位置数组元素
var arr = [1, 2, 3, 4, 5, 6, 7];
arr.splice(3, 1); // remove 4, 并 return 修改后的数组
console.log(arr); // [1, 2, 3, 5, 6, 7]
```

## 数组遍历

```javascript
[].forEach(function(value, index) {
  console.log(value, index);
});
```

## filter() 函数, 数组过滤

```javascript
function isBigEnough(value) {
  return value >= 10;
}
var filtered = [12, 5, 8, 130, 44].filter(isBigEnough);
// filtered is [12, 130, 44]
```

## reduce() 函数, 数组分解融合

```javascript
var numbers = [5, 4, 7, 3, 1];
var total = numbers.reduce(function(previous, current) {
  return previous + current;
});

console.log(total);
```

reduce() 声明式函数，特点：

1. 减少副作用；(Reduce Side Effects)
2. 减少可变性；(Minimize Mutability)
3. 代码更具可读性；(More Readable Code)
4. 更少的 Bug; (Less Bugs)

## join

## reverse

# 示例

## 合并两个数组

如果需要合并两个数组，可以结合使用 push()和 apply()方法。

```javascript
var a = [1, 2, 3];
var b = [4, 5, 6];

// 利用apply方法 合并方式a在前b在后，如果需要可以改变a与b的顺序
Array.prototype.push.apply(a, b); // 写法一
[].push.apply(a, b); // 写法二
a.push.apply(a, b); // 写法三
```
