# Fiddler
简介：
## 本地项目抓包，启动fiddler，默认代理端口为8888
* 使用localhost无法抓包，最简单的方式是使用IP地址访问；cmd->ipconfig 查看本机IP地址
## Chrome 抓包 代理设置
1. 安装代理插件`SwitchyOmega`
2. 新建情景模式，例如：`fiddler`
3. 代理服务器设置：
  * 代理协议 -> HTTP
  * 代理服务器 -> 127.0.0.1
  * 代理端口 -> 8888
## Fiddler 工具栏
1. 气泡按钮：给请求增加注释；
2. Replay: 重新发送当前请求，回放请求；
3. × 叉子图标：清空监控面板，删除当前请求，Ctrl+X删除全部，清空请求列表，还可以进行过滤；
4. Go按钮：调试Debug，请求前后增加断点调试；
5. Stream模式切换；
6. Decode 解压请求；
7. Keep All Session 保存会话数量选择；
8. Any Process: 过滤请求；
9. Find: 查找请求；
10. Save：保存会话；
11. 相机图标：保存截图；
12. 时钟图标：计时器；
13. Browser: 快速启动浏览器；
14. Clear Cache: 清除浏览器缓存；
15. Text Wizard: 编码/解码，帮助我们编码和解码一些文本内容；；
16. Tearoff: 在新窗口展开控制面板；
17. MSDN Search ：MSDN搜索；
## Fiddler 状态栏
1. 控制台 输入 `help` 打开帮助；
2. Capturing: 控制Fiddler是否工作；
3. All Process: 过滤请求（会话）来源；
4. 数字: 当前会话数量和选择的数量；
5. 选择一个会话，显示会话信息；
## 监控面板的使用
监控面板是Fiddler最核心的功能之一  
1. 记录来自服务器端请求的会话（文件请求和静态资源请求），并展示会话列表；
2. HTTP状态码；
3. 协议Protocol；
4. Host 主机域名；
5. ServerIP 服务器IP；
6. 会话URL;
## 控制面板
上半部分是所有请求信息，下面是所有响应信息；
1. Statistics 数据统计，性能指标；
  * 重要的数据指标->RTT数据往返时间，请求到响应的时间；
  * show chart 展示图表；以饼图的形式更直观的查看；
2. Inspectors 对请求进行解包；
  * 点开后可以查看请求和响应的详细内容；
  * User-Agent: 用户请求浏览器信息；
  * 当前浏览器请求所携带的cookies；
  * 发送请求所在域 Referers，和来源Origin；
3. AutoResponses **文件代理非常实用的功能**；
4. Composer **前后端接口联调功能**；
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

## 使用本地文件调试线上代码（改变响应参数）
打开 `AutoResponses` 面板
1. 勾选上面3个选项：`√` Enable rules `√` Unmatched requests passthrough `√` Enable Latency；
2. 将左侧需要需要拦截的URL拖入右侧列表；
3. 在 Rule Editor 栏修改指向，可以指定其他链接也可以指向本地文件；
4. 编辑后保存，重新进入当前页面或者重新请求；
## 利用控制台筛选
在下边命令行直接筛选抓包数据。
```bash
>200 Body大于200的请求
<200 Body小于200的请求
```
## HTTPS 抓包
Tools -> Fiddler Options -> 选项中勾选 Decrypt HTTPS traffic 安装证书即可；
