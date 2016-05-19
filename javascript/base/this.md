# this 指向
匿名回调函数中的this指向 window, 如果让其this指向外部函数可以在外部函数声明变量。
```javascript
xxx: function(){
  var This = this;
  function(){
    This.xxx; // 调用外部函数方法或者变量
  }
}
```
还有一种方式是使用ES5的bind函数改变引用。
```javascript
xxx: function(){
  function(){
    this.xxx; // 调用外部函数方法或者变量
  }.bind(this);
}
```
# Implicit Binding 隐式绑定
# 
