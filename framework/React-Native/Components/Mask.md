# Mask 组件

Mask 蒙层是最常用的组件之一，非常适合做组件化，这里实现了最基本的功能：
* 覆盖全屏；
* 标准的透明度；
* 支持点击操作；

```js
import React from 'react';
import { View, TouchableWithoutFeedback, StyleSheet } from 'react-native';

export default ({onPress}) => {
  return (
    <TouchableWithoutFeedback onPress={onPress}>
      <View style={styles.mask} />
    </TouchableWithoutFeedback>
  )
}

const styles = StyleSheet.create({
  mask: {
    ...StyleSheet.absoluteFillObject,
    backgroundColor: 'rgba(0, 0, 0, 0.3)'
  }
});

```
