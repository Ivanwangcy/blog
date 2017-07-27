# React 组件
## 传统的组件创建方法
```javascript
var Btn = React.createClass({
  render: function() {
    return <button>按钮</button>;
  }
})
```
## 使用 ES6 创建组件
```javascript
import React, {Component} from 'react';

class MapContainer extends Component {
  render() {
    return <div>地图</div>;
  }
}
```
## 无状态组件
```javascript
function ListView() {
  return <div>列表</div>;
}

import React, { PureComponent } from 'react'

// React 16 纯函数写法
class PureComponent extends PureComponent {
  render() {
    return (
      <View style={styles.container}>
        <JDText>Hello, PureComponent</JDText>
      </View>
    )
  }
}
```
