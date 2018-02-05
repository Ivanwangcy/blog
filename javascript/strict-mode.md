# javascript 严格模式

## 设定严格模式的目的：
- 消除Javascript语法的一些不合理、不严谨之处，减少一些怪异行为;
- 消除代码运行的一些不安全之处，保证代码运行的安全；
- 提高编译器效率，增加运行速度；
- 为未来新版本的Javascript做好铺垫；（ES6+）

## 开启严格模式
应用于全局
```js
 "use strict";
```
应用于函数
```js
function strict () {
  "use strict"
}
```


## 详情参考：
[Javascript 严格模式详解](http://www.ruanyifeng.com/blog/2013/01/javascript_strict_mode.html)
