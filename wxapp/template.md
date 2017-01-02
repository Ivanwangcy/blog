## template 模板使用
### 定义模板
- 创建 template 文件夹
- template.wxml
- template.wxss
### 引用模板
```html
<import src="../../template/template.wxml" />
<template is="template" data="{{...item}}"></template>
```
### 模板样式引用
```css
@@import "./template/template.wxss"
```
