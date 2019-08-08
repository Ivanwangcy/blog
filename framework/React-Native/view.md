## 布局/容器组件 View
## 使用 onLayout 获取 View 的实际尺寸 
```js
onLayout = (e) => {
  this.setState({
    imageWidth: e.nativeEvent.layout.width,
  })
}

<View onLayout={onLayout}></View>
```
## 使用 UIManager.measure 获取原生组件的属性

```js
UIManager.measure(
                    
                    
      findNodeHandle(node),
      (x, y, width, height, pageX, pageY) => {
       // other             
      }
```
