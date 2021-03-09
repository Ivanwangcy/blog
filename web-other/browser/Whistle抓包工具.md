# 更好用的前端调试工具 Whistle

## 前言

随着公司软件版权的问题 Charles 抓包工具不能用了，那么有什么好的替代方案吗？那就是 Whistle。 Whistle 是一款『跨平台 web 调试代理工具』，可以用来查看和修改 HTTP、HTTPS、Websocket 的请求和响应等很多强大的功能。只需 node 环境，通过 npm 命令行安装和启动，操作起来简单，很容易上手。

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

浏览器打开 8899 的端口URL即可进入 web 版页面。

### Web 浏览器代理配置

使用 SwitchyOmega 插件配置代理：
![whistle-proxy](/assets/whistle-proxy.jpg)
