# React 组件

## 传统的组件创建方法

```javascript
var Btn = React.createClass({
  render: function() {
    return <button>按钮</button>;
  }
});
```

## 使用 ES6 创建组件

```javascript
import React, { Component } from "react";

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

// 使用箭头函数更简洁
export default (props) => {
  return <div>无状态组件<div>
}

```

## 纯组件

```javascript
import React, { PureComponent } from "react";

// React 16 纯组件用法
class PureComponent extends PureComponent {
  render() {
    return (
      <View style={styles.container}>
        <JDText>Hello, PureComponent</JDText>
      </View>
    );
  }
}
```
## 高阶组件

function
