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
## 自定义 CSS 样式名称

```js
/**
 * Copyright (c) 2015-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

 'use strict';

 const loaderUtils = require('loader-utils');
 
 module.exports = function getLocalIdent(
   context,
   localIdentName,
   localName,
   options
 ) {
   // Use the filename or folder name, based on some uses the index.js / index.module.(css|scss|sass) project style
   const fileNameOrFolder = context.resourcePath.match(
     /index\.module\.(css|scss|sass)$/
   )
     ? '[folder]'
     : '[name]';
   // Create a hash based on a the file location and class name. Will be unique across a project, and close to globally unique.
   const hash = loaderUtils.getHashDigest(
     context.resourcePath + localName,
     'md5',
     'base64',
     5
   );
   // Use loaderUtils to find the file or folder name
   const className = loaderUtils.interpolateName(
     context,
     fileNameOrFolder + '_' + localName + '__' + hash,
     options
   );
   
   // remove the .module that appears in every classname when based on the file.
   return className.replace('.module_', '_');
 };
```
