# Fiddler
## 本地项目抓包
* 最简单的方式是使用IP地址访问；
## Chrome 抓包 代理设置
1. 安装代理插件`SwitchyOmega`
2. 新建情景模式，例如：`fiddler`
3. 代理服务器设置：
  * 代理协议 -> HTTP
  * 代理服务器 -> 127.0.0.1
  * 代理端口 -> 8888
## Fiddler 远程代理设置
1. Tools -> Fiddler Options -> Connections 勾选 （Allow remote computers connect）
2. 抓包需要在同一个域中，建议安装360WiFi：
  * 手机代理设置：（点击 连接的 WiFi 名称 高级设置）
  * 手动设置选项：主机名->台式机IP地址 ， 端口：8888
