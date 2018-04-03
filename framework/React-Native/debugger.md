## React Native 代码调试

- [http://localhost:8081/debugger-ui](http://localhost:8081/debugger-ui) google 浏览器访问链接
- 模拟器中 开启远程调试
- Source 菜单 开启 Pause On Caught Exceptions
- `CMD + Alt + j` 打开控制台
- 代码增加断点  `debugger`
- 打印日志 console.log(),可以在浏览器中打印日志，console.warn())可以在模拟器中输出信息，对象需要使用JSON.stingify转换成字符串才能输出内容;
- 刷新页面, 可以输入日志，进入断点

## show 检查元素

在调试菜单中可以，开启页面元素审查，点选组件查看样式尺寸等信息;

## 模拟器调试

- iOS `cmd + D` 唤起调试菜单，`cmd + R` 重新载入
- Android `cmd + M` 唤起调试菜单，`R + R` 点击两次 `R`

## 真机调试
可以摇晃手机唤起 debugger 菜单；
