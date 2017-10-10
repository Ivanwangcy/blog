# ES6 Object 新增的实例函数
## Object.assign() merge 对象, 合并(融合)多个对象
```javascript
Object.assign({}, {a:1}, {b:2});
// Object {a: 1, b: 2}
Object.assign({a:1}, {b:2});
// Object {a: 1, b: 2}
Object.assign({a:1}, {b:2}, {c:3}, {a:11});
// Object {a: 11, b: 2, c: 3}
```
