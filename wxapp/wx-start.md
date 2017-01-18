# 微信小程序开发
## Atom 编辑器 语法 插件 安装
- [atom-wx](https://atom.io/packages/atom-wx "atom-wx") 微信小程序语法高亮(atom-wx), 支持 wxml 文件和 wxss 文件
- [wxapp](https://github.com/xiadd/atom-wxapp "wxapp") 微信小程序自动补全
## 微信小程序开发工具

下载地址：   [https://mp.weixin.qq.com/debug/wxadoc/dev/devtools/download.html?t=20161107](https://mp.weixin.qq.com/debug/wxadoc/dev/devtools/download.html?t=20161107)

## 创建小程序

一个小程序包含：一个主应用程序和若干个页面组成；  

主应用程序程序文件固定名称，包括：
- app.js(定义应用程序逻辑，全局属性)；
- app.json(描述页面结构，程序框架信息，导航，标题),
- app.wxss(全局样式，同 css 一样，增加了尺寸单位和样式导入)

### 注册一个应用程序：
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
```

### 注册一个页面，需要在 app.json 中加入引用才能生效；  
每个页面的js, wxml, wxss 文件名称必须相同，不需要单独引用，自动加载；
```javascript
// 注册页面
// 首页逻辑
// pages/index/index.js
Page({
  onLoad() {
    console.log("首页加载完成");
  }
})
```
```HTML
// 首页页面结构
<!-- index.wxml -->
<view class="container">
  <view>
    <swiper indicator-dots="true" vertical="true">
    </swiper>
  </view>
  <text class="content">Hello World</text>
</view>
```
```css
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
## 创建与预览项目
首先需要创建好项目结构，才能在微信Web开发者工具中打开查看，也可以下载微信小程序demo。
1. 添加AppID, 没有可不填，部分功能受限;
2. 添加项目名称英文+数字，不用用中文名；
3. 选择项目目录，并添加项目；
4. 调试代码与google 浏览器类似，支持log输出，不支持浏览器的alert；

## 适配屏幕尺寸 使用 rpx 单位
设计稿基于 750px 的，单位直接使用 rpx, 如：`1px` 边框，使用 `1rpx solid #000`。

## 公共样式应用

在 wxss 文件中可以导入外部公共样式, 通常样式是基于模块的，又不想影响到全局样式，就需要提取出来公共样式。
应用公共样式如下：  

```css
@import "../public.wxss";
```

## 公共模板应用
- 新建一个模板，使用 `wxml` 格式，必须有 `name` 属性，使用 `template` 标签包装：
```html
<!-- template.wxml -->
<template name="template">
  <view> 模板 {{text}} </view>
</template>

```  
- 导入一个模板，使用 import 标签导入模板，src属性指定模板路径：  
```html
<!-- 引用底部模板 -->
<import src="../template/template.wxml"/>

<!-- 使用模板 并传递数据 -->
<template is="template" data="{{...data, text: 'hello template'}}"/>
```
