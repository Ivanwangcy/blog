# 配置webpack-dev-server
## 安装
```sh
$ npm install -g webpack-dev-server
```
## 启动
```sh
$ webpack-dev-server # 直接启动

```
## 结合 webpack 配置文件
```javascript
devServer: {
  port:8080, // 端口号
  hot: true, // 热替换，自动刷新
  inline: true, // 可以手动刷新
  host: '0.0.0.0', // 配置host 允许使用， IP 地址访问
  // noInfo: true, // 是否显示启动信息
  quiet: true, // 是否冗长的日志信息
  contentBase: './', // 服务器根目录
  //其实很简单的，只要配置这个参数就可以了, 代理服务器地址
  proxy: {
    '/client': { // 代理接口，路由
        target: 'http://xxx.xx.com', // 代理域名
        secure: false, // true 可以访问HTTPS, false 是 http
        changeOrigin: true // 改变请求来源，true 可以跨域
    }
  }
},
```
