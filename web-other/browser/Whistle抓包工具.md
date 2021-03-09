# 更好用的前端调试工具 Whistle

## 前言

随着公司软件版权的问题 Charles 抓包工具不能用了，那么有什么好的替代方案吗？那就是 Whistle。 Whistle 是一款『跨平台 web 调试代理工具』，可以用来查看和修改 HTTP、HTTPS、Websocket 的请求和响应等很多强大的功能。只需 node 环境，通过 npm 命令行安装和启动，操作起来简单，很容易上手。

Whistle 完全开源，可以放心使用。

## 快速上手

### 安装 Whistle

```sh
# 默认官方网址安装
$ npm install -g whistle 

# 国内可以使用淘宝镜像
$ npm install whistle -g --registry=https://registry.npm.taobao.org

# 需管理员权限
$ sudo npm install -g whistle 
```

### 启动 Whistle

```sh
w2 run
```

![whistle-run](/assets/whistle-run.jpg)

浏览器打开 8899 的端口URL即可进入 web 版配置页面。

### Web 浏览器代理配置

使用 SwitchyOmega 插件配置代理：
![whistle-proxy](/assets/whistle-proxy.jpg)

再次访问配置页面，即可看到抓包数据：
![whistle-record](/assets/whistle-record.jpg)

## 开启 HTTPS 抓包

![whistle-https](/assets/whistle-https.jpg)

点击图中二维码下载证书，双击安装：

![whistle-ca](/assets/whistle-ca.jpg)

## 线上代码映射到本地

![whistle-mapping](/assets/whistle-mapping.jpg)

配置完映射的文件，Ctrl + S 保存，刷新一下目标网址即可成功映射。

## 其它代理方式

## 全局代理

Mac: System Preferences > Network > Advanced > Proxies > HTTP or HTTPS

## 移动端代理

移动端需要与电脑连接同一个 Wi-Fi 进行代理，以 Android 为例：

扫码安装 HTTPS 根证书：

![whistle-mobile](/assets/whistle-mobile.jpeg)

看起来是不是很简单，用起来很顺畅，非常好用无烦恼(传统的桌面应用 charles,fiddler 要配置很久,还总出问题)。
