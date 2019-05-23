# pointerEvent 属性使用

pointerEvents 是字符串类型的属性, 可以取值 none,box-none,box-only,auto. 

1. none 发生在本组件与本组件的子组件上的触摸事件都会交给本组件的父组件处理. 
2. box-none 发生在本组件显示范围内,但不是子组件显示范围内的事件交给本组件,在子组件显示范围内交给子组件处理 
3. box-only 发生在本组件显示范围内的触摸事件将全部由本组件处理,即使触摸事件发生在本组件的子组件显示范围内 
4. auto 视组件的不同而不同,并不是所有的子组件都支持box-none和box-only两个值,使用时最好测试下

```js
// 禁用组件的手势操作
     <View pointerEvents="none">
       <Text
         style={this.props.style}>
         {this.props.children}
       </Text>
    </View>
```
