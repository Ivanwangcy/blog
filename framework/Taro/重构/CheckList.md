# 重构的代码

去除重复、冗余代码：
CDN 图片资源 URL 公共前缀提取；
组件复用，子包的组件放入子包中；
公用代码梳理，去除无用的功能重复的；
移除：autobind-decorator 减少包体积 <https://github.com/andreypopp/autobind-decorator>
<https://juejin.cn/post/6844903698146181134> Google JavaScript 代码风格指南

- 类型文件统一放入 types 目录管理；
- Redux 状态统一管理在 store 目录下：
- actiontype 要使用字符串不要用 symbol； 参考：<https://cn.redux.js.org/docs/recipes/ReducingBoilerplate.html>
- 列表组件要写 map 必须增加 key 不要用index
- 代码需要优化的不管谁写的都要想办好改进一下，改不好没关系。杜绝别人的代码不敢动，自己的代码别人不敢改；
- 开发需求时必须考虑多端的问题，只有单平台需要屏蔽其它平台，多平台需要适配。
- ref 是一种反模式，一般用于调用 ref 对象的原生方法，自定义类不建议使用。
