## react native 中的组件
### View
### Text
```javascript
<Text
  numberOfLines={2}
  // 多出部分使用省略号替代，设置省略号的位置,
  // head 头部
  // middle 中间
  // tail 尾部 默认
  ellipsizeMode={'head'/'middle'/'tail'/'clip'}
  onPress={() => {'点击事件'}}
></Text>
```
### Image
```javascript
let pic = {
  uri: 'https://img30.360buyimg.com/o2o/s550x550_jfs/t778/239/281536622/380091/e3814007/549bd507Nbf119e44.jpg'
}

<Image source={pic} style={{width: 193, height: 110}}/>

// require加载图片 带有宽高属性，返回数据源对象，包含 uri
<Image source={require('xx.png')} />
```
### TextInput
```javascript
<TextInput
  style={{height: 40}}
  placeholder="input your name"
  onChangeText={(text) => this.setState({text})}
/>

<TextInput
  editable={true} // 是否可编辑
  maxLength={40}  // 最大长度
  multiline={true/false} // 是否允许多行显示
  numberOfLines={4} // 最大行数
/>

```
### ScrollView
带有滚动条，可以下拉刷新。
### ListView
列表渲染，上拉加载，
### Toucheable 组件
###
