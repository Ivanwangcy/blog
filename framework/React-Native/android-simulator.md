# Adroid 开发环境

- 安装 Android Studio
- 打开项目工程文件 build.gradle

## 调试

### 访问App内的开发菜单

Android模拟器用是Command⌘ + M（windows上可能是F1或者F2）。双击 R reload 文件。

## Android 特有组件

## ViewPagerAndroid 轮播图组件

## ToastAndroid

## Android 真机调试

在设备上运行您的应用
您在设备上运行应用之前，必须在设备上启用 USB debugging。您可以在 Settings > Developer options 中找到该选项。

注：在运行 Android 4.2 及更新版本的设备上，Developer options 默认情况下处于隐藏状态。如需将其显示出来，请转到 Settings > About phone 并点按 Build number 七次。返回上一屏幕即可找到 Developer options。

对设备完成设置并通过 USB 连接后，您可以使用上述 Gradle 安装任务或 adb 工具安装您的应用：

```sh
adb -d install path/to/your_app.apk
```

所有构建的 APK 均保存在 project_name/module_name/build/outputs/apk/ 中。

如果无法加载 js 文件，执行下面的命令即可：

```sh
adb reverse tcp:8081 tcp:8081
```

>参考链接：

- [RunningOnDevice](https://developer.android.com/studio/build/building-cmdline.html#RunningOnDevice)
- [running-on-devlice-android](https://reactnative.cn/docs/0.50/running-on-device-android.html)