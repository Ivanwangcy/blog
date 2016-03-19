# Fiddler
简介：
## 本地项目抓包，启动fiddler，默认代理端口为8888
* 最简单的方式是使用IP地址访问；
## Chrome 抓包 代理设置
1. 安装代理插件`SwitchyOmega`
2. 新建情景模式，例如：`fiddler`
3. 代理服务器设置：
  * 代理协议 -> HTTP
  * 代理服务器 -> 127.0.0.1
  * 代理端口 -> 8888

## Fiddler 远程代理设置
1. Tools -> Fiddler Options -> Connections 勾选 ->（Allow remote computers connect）
2. 抓包需要在同一个域中，建议安装360WiFi：
  * 手机代理设置：（点击 连接的 WiFi 名称 高级设置）
  * 手动设置选项：主机名->台式机IP地址 ， 端口：8888

## Fiddler URL 过滤 (抓包过滤)
1. 切换 Filters 面板
2. Use Filters
3. Request Headers
4. Show only if URL contains (勾选)
5. 需要过滤的关键字

## 搜索和过滤当前的 Sessions (Search and Filter Sessions)
1. Edit -> Find Sessions
2. Find 关键字
3. 勾选 Select matches

## Select Parent or Child Session

1. To select the parent session (the most recent request to the URL specified in the selected session's Referer header):

* Select a session in the Web Sessions List.

* Press P.

2. To select all child sessions (the later requests to the URL specified in the selected session's Referer header):

* Select a session in the Web Sessions List.

* Press C.

## 使用本地文件调试代码（改变响应参数）
AutoResponses 面板
1. 勾选上面3个选项：`√` Enable rules `√` Unmatched requests passthrough `√` Enable Latency；
2. 将左侧需要需要拦截的URL拖入右侧列表；
3. 在 Rule Editor 栏修改指向，可以指定其他链接也可以指向本地文件；
4. 编辑后保存，重新进入当前页面或者重新请求；
## 筛选
在下边命令行直接筛选抓包数据。
```bash
>200 Body大于200的请求
<200 Body小于200的请求
```
