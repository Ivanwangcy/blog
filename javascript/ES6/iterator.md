# Iterator ES6 迭代器
# forEach ES5数组内建的forEach方法
缺点：不能使用break语句中断循环，也不能使用return语句返回到外层函数。
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
for-in循环用来遍历对象属性。  
for-in是为普通对象设计的，你可以遍历得到字符串类型的键，因此不适用于数组遍历。
```JavaScript
for(var index in myArray){// 千万别这样做
  console.log(myArray[index]);
}
```
# for-of
标准委员会在ES6中增加了一种新的循环语法来解决目前的问题。  
- 这是最简洁、最直接的遍历数组元素的语法
- 这个方法避开了for-in循环的所有缺陷
- 与forEach()不同的是，它可以正确响应break、continue和return语句
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
