# Taro 升级

## Taro V1 to V2

## Taro 3.0

使用 React 语法开发。

- 引入 React 库；

```js
import React, { Component } from 'react'
import { View, Text } from '@tarojs/components'

export default class Index extends Component {
  state = {
    msg: 'Hello World！'
  }
  componentWillUnmount () { }

  componentDidShow () { }

  componentDidHide () { }

  render () {
    return (
      <View className='index'>
        <Text>{this.state.msg}</Text>
      </View>
    )
  }
}
```

## Vue/Vue3 支持

```js
<template>
  <view class="index">
    <text>{{msg}}</text>
  </view>
</template>

<script>
export default {
  data () {
    return {
      msg: 'Hello World！'
    }
  },
  created () {},
  onShow () {},
  onHide () {}
}
</script>
```

## 多端转换支持

Taro 方案的初心就是为了打造一个多端开发的解决方案。

目前 Taro 3 可以支持转换到 微信/京东/百度/支付宝/字节跳动/QQ 小程序 以及 H5 端。

## Taro UI 组件库

<https://taro-ui.jd.com/#/docs/introduction>

## 常见错误

- 使用 Taro 3.0 版本写微信小程序写类组件控制台输出：
  
`MiniProgramError Super expression must either be null or a function`

需要更新写法：

React.Component 代替 Taro.Component

- [问题描述：const taro = Taro；执行taro.getNetworkType({})报错]

Taro 版本统一，保持所有库都是一个版本；不一致时，删除所有包和 lock 文件，重新安装。
