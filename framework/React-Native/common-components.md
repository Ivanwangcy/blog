## react native 中的组件
### View
### Text
### Image
```javascript
let pic = {
  uri: 'https://img30.360buyimg.com/o2o/s550x550_jfs/t778/239/281536622/380091/e3814007/549bd507Nbf119e44.jpg'
}

<Image source={pic} style={{width: 193, height: 110}}/>
```
### TextInput
```javascript
<TextInput
  style={{height: 40}}
  placeholder="input your name"
  onChangeText={(text) => this.setState({text})}
/>
```
### ScrollView
### ListView
