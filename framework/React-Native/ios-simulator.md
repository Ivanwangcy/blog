## 启动 iPhone 模拟器

### react-native 命令启动
```sh
$ react-native run-ios
```
### 在Xcode中，手动启动 IOS 项目
1. 导入现有项目，选择目录 ios/XXX.xcodeproj
2. 选择设备，模拟器或者(`自己的手机`)
3. 点击启动键
## 快捷键
- `Ctrl + R` Reload 应用
- `Ctrl + D` 打开开发调试菜单
- `Shift + CMD + H` 回到主屏幕
- `Shift + CMD + H H` 切换应用，展开开启的应用列表，选择指定的应用进行关闭
## 真机调试
首先需要一个 开发者账号：  
- XCode 菜单 -> Preferences... (快捷键 cmd + ,)
- 选择 accounts -> `+` -> add Apple ID
- 输入 账户名和密码，就是登录 App Store 的同一个账户
新建/打开一个项目：  
- 点击项目根节点 -> General;
- 设置 Bundle Identifier; (打包的唯一标识)
- 设置 Team;（上面的 apple ID）
