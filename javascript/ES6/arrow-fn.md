# Arrow Funciotn => 箭头函数
```javascript
var fn = () => {
  console.log("aaaa");
}

// 返回对象简写
var func = () => ({ a: 1, b: 2 });
func(); // Object {a: 1, b: 2}

// 返回基本类型 简写
var arrow = x => x * x; // x 为参数, return x * x
arrow(5); // 25
```
