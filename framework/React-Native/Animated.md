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
## transform 动画

```js
state = {
  animatedValue: new Animated.ValueXY({x: 0, y: posTop})
}

// Animate the movement
   Animated.timing(this.state.animatedValue, {
     duration,
     easing: Easing.linear,
     toValue: {
       x: newX,
       y: newY,
     }
   }).start(() => {
     // Animate again after current animation finished
     // 动画完成之后的处理
     this.animate();
   });

style: {
  transform: animatedValue.getTranslateTransform()
}
```

## Animated.timing
 
# 
 #
 #
 #
