## React Component 结构 `^V15.5.0`
```javascript
import React, { Component } from 'react'

import {
  Text,
  View
} from 'react-native' // ReactNative 组件

import PropTypes from 'prop-types' // 属性枚举

// 定义并导出组件
export default class MyComponent extends Component {

  // 定义属性
  static propTypes = {
    text: PropTypes.string.isRequired,
    hide: PropTypes.bool,
  }
}
```
