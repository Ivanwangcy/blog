# Context API 用法

通过组件树传递数据，而不想每一级都手动下传 `prop` ，React 的 "context" 可以做到这一点。用法很简单：

## 父组件定义 context 
```js
  static childContextTypes = {
    color: PropTypes.string
  }
  getChildContext = () => {
    return {color: "purple"}; // 指定属性值
  }
```

## 子组件获取 context (任意子组件)
```js
  static contextTypes = {
    color: PropTypes.string
  }
  
  render() {
    return (
      <View style={{backgroundColor: this.context.color}}>
        {this.props.children}
      </View>
    );
  }
```
