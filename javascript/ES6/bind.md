## 函数绑定语法
## ES6 可以使用箭头函数 `=>`
```javascript
var arr = [1,2,3,4,5];

arr.map((value) => {
  return Math.pow(value, 2);
})


onSubmitUser={() => this.handleSubmitUser}
```
## ES7 this 绑定方法
使用`::`绑定函数的上下文。
```javascript
// React 事件绑定写法
onSubmitUser={::this.handleSubmitUser}
```
