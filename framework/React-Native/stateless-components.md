## 无状态组件的基本结构
```javascript
import React from 'react'
import {
  View,
  Text,
  StyleSheet,
} from 'react-native'


export default function Header (props){
  return (
    <View style={styles.header}>
      <Text style={styles.headerText}>{props.title}</Text>
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
