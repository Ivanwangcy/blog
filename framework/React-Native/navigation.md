## React Native 路由导航系统
react-navigation  

[https://github.com/aksonov/react-native-router-flux](https://github.com/aksonov/react-native-router-flux)
## tabs 用法
```js
<Scene key='tabbar' tabs hideNavBar initial
  tabBarStyle={styles.tabBarStyle}
  labelStyle={styles.labelStyle}
  activeTintColor='#39ac69'
  activeBackgroundColor='#ddd'
  gestureEnabled={true}
  >
  <Scene key='home' tabBarLabel='首页' icon={TabIcon} iconType="home" component={Home} title='tab #1' initial hideNavBar></Scene>
  <Scene key='discover' tabBarLabel='福利' icon={TabIcon} iconType="discover" component={Content} title='tab #2'></Scene>
  <Scene key='cart' tabBarLabel='购物车' icon={TabIcon} iconType="cart" component={Content} title='tab #3'></Scene>
  <Scene key='order' tabBarLabel='订单' icon={TabIcon} iconType="order" component={Content} title='tab #4'></Scene>
  <Scene key='my' tabBarLabel='我的' icon={TabIcon} iconType="my" component={Content} title='tab #5'></Scene>
</Scene>

const styles = StyleSheet.create({
  tabBarStyle: {
    backgroundColor: '#eee',
    paddingBottom: 0,
  },
  labelStyle: {
    fontSize: 10,
  }
})
```
## 性能
