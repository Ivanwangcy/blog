# 微信小程序开发
## Atom 编辑器 语法 插件 安装
- [atom-wx](https://atom.io/packages/atom-wx "atom-wx") 微信小程序语法高亮(atom-wx), 支持 wxml 文件和 wxss 文件
- [wxapp](https://github.com/xiadd/atom-wxapp "wxapp") 微信小程序自动补全
## 微信小程序开发工具

下载地址： [https://mp.weixin.qq.com/debug/wxadoc/dev/devtools/download.html?t=20161107](https://mp.weixin.qq.com/debug/wxadoc/dev/devtools/download.html?t=20161107)

## 创建小程序
```javascript

// 注册程序
// app.js
// nothing to do
//
App({
  onLaunch() {
      // App Launch
      console.log("小程序初始化");
  }

  onShow() {
    // App show
    console.log("小程序显示");
  }

  onHide() {
    // App hide
    console.log("小程序隐藏");
  }
})

// app.json
// 配置页面
{
  "pages": [
    "pages/index/index" // 首页
  ]
}

// 注册页面
// 首页逻辑
// pages/index/index.js
Page({
  onLoad() {
    console.log("首页加载完成");
  }
})

// 首页页面结构
<!-- index.wxml -->
<view class="container">
  <view>
    <swiper indicator-dots="true" vertical="true">
    </swiper>
  </view>
  <text class="content">Hello World</text>
</view>

// 首页页面样式
/* index.wxss */
.container{
    background: #ff0;
    display: flex;
    align-items: center;
    justify-content: center;
    flex-direction:row;
    width:100vw;
    height: 100vh;
}

```
