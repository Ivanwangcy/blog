## Vue 模板语法

## Vue 模板指令
### 条件指令 v-if, v-else, v-else-if
### 外部 style 文件
```html
<style src="style.css"></style>
```
### 预处理样式语言
```html
<style lang="scss"> </style>
<style lang="less"> </style>
<style lang="styl"> </style>

```

### 局部样式

```html
<!-- Add "scoped" attribute to limit CSS to this component only -->
<!-- scoped 代表内部样式，不会影响全局 -->
<style lang="scss" scoped> </style>
```

### 非字符串属性
使用 :props=xxx
### 动画，过渡
<transition></transition>
### 自定义指令
v-xxx
### template 在 v-if 条件组中应用
>> 因为 v-if 是一个指令，需要将它添加到一个元素上。但是如果我们想切换多个元素呢？此时我们可以把一个 <template> 元素当做包装元素，并在上面使用 v-if。最终的渲染结果不会包含 <template> 元素。
```html
<template v-if="ok">
  <h1>Title</h1>
  <p>Paragraph 1</p>
  <p>Paragraph 2</p>
</template>
```
