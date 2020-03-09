# vue hack 之强制刷新组件

把一个组件重置到初始状态是一个常见的需求，推荐的做法有两种，一种是父组件重置子组件的 prop，另一种是子组件暴露一个重置的方法供父组件调用。但有些时候，子组件既没有提供重置的方法，也没提供 prop 来重置自己的状态。更重要的是，这个子组件我们还动不了。于是我们就需要一种 hack 的方式来强制子组件重置到初始状态。方法如下：

:: demo
```js

<component v-if="hackReset"></component>
this.hackReset = false
this.$nextTick(() => {
  this.hackReset = true
})
```
::demo

`v-if` 在切换时，元素及它的绑定数据和组件都会被销毁并重建
