# JSON 用法
`JSON` 已经逐渐替代XML被全世界的开发者广泛使用。本文深入讲解JavaScript中使用 JSON 对象的一些细节问题。首先简单回顾一下 JSON 和 JavaScript：

* 不是所有的合法的JSON都是有效的JavaScript；
* JSON只是一个文本格式；
* JSON中的数字是十进制。

JSON 是非常常用的工具，可以互相转换对象与JSON串。

## JSON.stringify 实例

* 过滤值为 null 的属性

```js
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
