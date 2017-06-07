## Animated
### Animated.View
```js
import React from 'react'
import { Animated, Easing, StyleSheet, Text, View, } from 'react-native'

export default class FadeInView extends React.Component {
  state: any
  
  construtor (props) {
    super(props)
    this.state = {
      fadeAnim: new Animated.Value(0) // opacity 0
    }
  }
  
  componentDidMount () {
    Animated.timing(
      this.state.fadeAnim, 
      {
        toValue: 1,  // 0 - 1
        duration: 2000
      }
    ).start()
  }
  
  render () {
    return (
      <Animated.View
        style={{
          opacity: this.state.FadeAnim
        }}>
        {this.props.children}
      </Animated.View>
    )
  }
}

```
