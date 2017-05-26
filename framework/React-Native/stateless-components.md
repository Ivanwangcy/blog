## 无状态组件的基本结构
```javascript
import React from 'react'
import {
  View,
  Text,
  StyleSheet,
} from 'react-native'

import {
  JDDevice,
} from 'jdreact-core-lib'


export default function Header (props){
  return (
    <View style={styles.header}>
      <View style={styles.headerLine}></View>
      <Text style={styles.headerText}>{props.floorTitle}</Text>
    </View>
  )
}

var styles = StyleSheet.create({
  header: {
    height: 50,
    justifyContent: 'center',
    alignItems: 'stretch',
    borderColor: '#e7e9e4',
    borderBottomWidth: 0.5
  },
  headerLine: {
    position: 'absolute',
    width: JDDevice.width * 0.6,
    left: JDDevice.width * 0.2,
    top: 24,
    borderTopWidth: 0.5,
    borderColor: '#333'
  },
  headerText: {
    alignSelf: 'center',
    color: '#333',
    fontSize: 17,
    padding: 5,
    fontWeight: 'bold',
    backgroundColor: '#fff',
  }
})

```
