## React Native 中的样式
创建样式使用 json 对象，样式名称使用驼峰式命名，尺寸大小没有单位（px等），View 默认为flexbox布局.
```javascript
// 创建样式对象
const styles = StyleSheet.create({
  container: {
    flex: 1, // 外容器设置 1 相当于整个屏幕的大小
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#F5FCFF',
    fontSize: 20,
    textAlign: 'center',
    margin: 10,
  },  
  bigblue: {
    color: 'blue',
    fontWeight: 'bold',
    fontSize: 30
  },
  red: {
    color: '#F00'
  }
})

// 行内样式
  <View style={{width: 50, height: 50, backgroundColor: 'powderblue'}}></View>

  // 通过 StyleSheet 设置样式
  <Text style={styles.red}>just red</Text>
  <Text style={styles.bigblue}>just bigblue</Text>
  // 相同的样式， 后面会覆盖前面
  <Text style={[styles.bigblue, styles.red]}>bigblue, then red</Text>
  <Text style={[styles.red, styles.bigblue]}>red, then bigblue</Text>
```
# #
