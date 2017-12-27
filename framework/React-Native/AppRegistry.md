# AppRegistry
## 注册应用程序入口
AppRegistry.registerComponent('DaojiaRN', () => DaojiaRN)

## setWrapperComponentProvider
注册一个与根元素同级别的组件，对外部提供接口，强制更新子元素，可以做 全局的 Toast alert 等。
例如：
- [https://github.com/magicismight/react-native-root-siblings](https://github.com/magicismight/react-native-root-siblings)
- [https://github.com/magicismight/react-native-root-toast](https://github.com/magicismight/react-native-root-toast)
