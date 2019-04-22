# 添加CSS模块样式表


[adding-a-css-modules-stylesheet](https://facebook.github.io/create-react-app/docs/adding-a-css-modules-stylesheet)

使用 create-react-app 并且 react-scripts@2.0.0 以上。同时兼容的 常规 css 和 css modules 写法：

```js
import React, { Component } from 'react';
import styles from './Button.module.css'; // Import css modules stylesheet as styles
import './another-stylesheet.css'; // Import regular stylesheet

class Button extends Component {
  render() {
    // reference as a js object
    return <button className={styles.error}>Error Button</button>;
  }
}
```
