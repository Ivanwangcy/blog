# Iterator ES6 迭代器

# forEach ES5 数组内建的 forEach 方法

缺点：不能使用 break 语句中断循环，也不能使用 return 语句返回到外层函数。

```JavaScript
// for 循环
for(var index =0; index < myArray.length; index++){
  console.log(myArray[index]);
}

// foreach 循环
myArray.forEach(function(value){
    console.log(value);
});
```

# for-in

for-in 循环用来遍历对象属性。  
for-in 是为普通对象设计的，你可以遍历得到字符串类型的键，因此不适用于数组遍历。

```JavaScript
for(var index in myArray){// 千万别这样做
  console.log(myArray[index]);
}
```

# for-of

标准委员会在 ES6 中增加了一种新的循环语法来解决目前的问题。

* 这是最简洁、最直接的遍历数组元素的语法
* 这个方法避开了 for-in 循环的所有缺陷
* 与 forEach()不同的是，它可以正确响应 break、continue 和 return 语句

```JavaScript
for(var value of myArray){
  console.log(value);
}
for(var value of myArray){
  if(value == 11){
    value = 12;
  }
  console.log(value);
}
```

## 使用 for-of 遍历 jQuery 对象：

```javascript
// 因为jQuery对象与数组相似
// 可以为其添加与数组一致的迭代器方法
jQuery.prototype[Symbol.iterator] = Array.prototype[Symbol.iterator];
var contentList = $(".content");
for (var element of contentList) {
  console.log(element);
}
```
