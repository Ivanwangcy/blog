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
    hide: PropTypes.bool
  }

  // 定义默认属性
  static defaultProps = {
    text: "Hello World",
    hide: true
  }

  // 初始化，构造函数
  constructor (props) {
    super(props) // 继承属性，赋值操作

    // 默认状态
    this.state = {
      title: '',
    }

    // 自定义函数
    clickHandle () {
      // 改变状态使用 setState
      this.setState({
        title: 'clickHandle'
      })

      // 异步更新状态，状态
      this.setState((prevState, props) => ({
        title: prevState.title + props.title
      }))

      // 不同的状态分别设置不会被覆盖
      this.setState({
        state1: 'state1'
      })
      
      // 不会影响 state1
      this.setState({
        state2: 'state2'
      })
    }

    render () {
      return (
        <div>{text}</div>
      )
    }

    // 渲染完成
    componentDidMount() {

    }

    // 销毁
    componentWillUnmount() {

    }
  }
}
```#
 #
# #
