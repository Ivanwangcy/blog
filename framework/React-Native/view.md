## 布局/容器组件 View
## 获取 View 的实际尺寸
```js
onLayout = (e) => {
  this.setState({
    imageWidth: e.nativeEvent.layout.width,
  })
}

<View onLayout={onLayout}></View>
```
