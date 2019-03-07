# 定时器优化

关于 setTimeout 的问题，可以使用 requestAnimationFrame 和 Promise.resolve 代替。用法：
```js
requestAnimationFrame(() => console.log(1));
Promise.resolve().then(() => console.log(2));
```
