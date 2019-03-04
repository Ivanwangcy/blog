# 旧项目使用 React 新版本新特性
如果是旧项目中使用一些新特性，需要安装这个库，来补充。

`react-lifecycles-compat`
```sh
# Yarn
yarn add react-lifecycles-compat

# NPM
npm install react-lifecycles-compat --save
```
使用polyfill，使新的生命周期与旧版本的React一起使用

```js
import React from 'react';
import {polyfill} from 'react-lifecycles-compat';

class ExampleComponent extends React.Component {
  static getDerivedStateFromProps(nextProps, prevState) {
    // Normally this method would only work for React 16.3 and newer,
    // But the polyfill will make it work for older versions also!
  }

  getSnapshotBeforeUpdate(prevProps, prevState) {
    // Normally this method would only work for React 16.3 and newer,
    // But the polyfill will make it work for older versions also!
  }

  // render() and other methods ...
}

// Polyfill your component so the new lifecycles will work with older versions of React:
polyfill(ExampleComponent);

export default ExampleComponent;
```
