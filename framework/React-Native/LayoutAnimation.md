# LayoutAnimation

可以在 setState 之前执行动画，适用于页面创建时的过渡动画。

```js
更新页面时用
componentWillUpdate() {
    // spring, easeInEaseOut, linear
    LayoutAnimation.easeInEaseOut();
  }
```
