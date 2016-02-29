# 唤起 App 协议问题
## 目前问题：
Android系统不能正常唤起客户端，目前测试到的有三星note3, s5 以上版本默认浏览器，使用现有协议无法打开app，如果用户未安装app则会跳转一个错误页面。其它高版本的手机也会有这个问题。现有协议使用的是scheme，Android和iPhone通用。iPhone手机目前未发现问题。

## 问题原因：
Android 平台默认浏览器（Chrome），从25及以后版本不再支持通过JS触发（非用户点击），设置iframe src地址等来触发scheme跳转。

## 解决方案：
Android提供了更智能的Intent协议，使用这种协议可以解决上述问题。如果手机能匹配到相应的APP，则会直接打开，如没有安装，则会跳到手机默认的应用商店。intent比scheme相对完善的一点是，提供一个打开失败去向的URL选项。
参考链接： https://developer.chrome.com/multidevice/android/intents
chrome 25以上版本使用：intent:开头的协议可以解决。

**希望提供一个intent协议与H5进行联调，评估一下会有哪些问题：是否影响埋点统计，有多大工作量，对以前版本有没有影响。。。**
