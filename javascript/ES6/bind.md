# 函数绑定语法
## ES5 的 bind 函数
```javascript
// 这里的 this 默认是指向 `window`, 使用bind(this)改变作用域, 用于保留当前对象的上下文.
setInterval(function(){
  this.xxx();
}.bind(this), 1000);
```
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
