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
