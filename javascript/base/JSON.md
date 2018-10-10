# JSON 用法

JSON 是非常常用的工具，可以互相转换对象与JSON串。

## 实例
```js
过滤值为 null 的属性
var obj = {
  a : 1,
  b : { c : null, d: '5' }
};

var tracer = function (key, value){
  console.log('Key: ', key);
  console.log('Value: ', value);
	if(!value) return;
  return value;
};

JSON.stringify(obj, tracer);
```
