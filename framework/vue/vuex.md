## Vuex 概述
Vuex 是一个状态管理模式的框架或者叫类库。它适合中到大型的单页项目。Vuex 是基于 Flux 的数据管理架构, 专为Vue量身定制。它主要帮我们更好地组织代码，以及把应用内的的状态保持在可维护、可理解的状态。  
如果你不太理解 Vue.js 应用里的状态是什么意思的话，你可以想象一下你此前写的 Vue 组件里面的 data 字段。

### Vuex 把状态分成**组件内部状态**和**应用级别状态**：

- 组件内部状态：仅在一个组件内使用的状态(data 字段)
- 应用级别状态：多个组件共用的状态  

举个例子：比如说有一个父组件，它有两个子组件。这个父组件可以用 props 向子组件传递数据，这条数据通道很好理解。

那如果这两个子组件相互之间需要共享数据呢?  
或者子组件需要向父组件传递数据呢?  
这两个问题在应用体量较小的时候都好解决，只要用自定义事件即可。  

### 但是随着应用规模的扩大：

- 追踪这些事件越来越难了。这个事件是哪个组件触发的？谁在监听它？
- 业务逻辑遍布各个组件，导致各种意想不到的问题。
- 由于要显式地分发和监听事件，父组件和子组件强耦合。

### Vuex 要解决的就是这些问题，Vuex 背后有四个核心的概念：

- The State Tree 状态树: 包含所有应用级别状态的对象
- Getters: 在组件内部获取 store 中状态的函数
- Mutations: 修改状态的事件回调函数
- Actions: 组件内部用来分发 mutations 事件的函数
- Modules: 按模块拆分多个状态树 -- 默认情况下vuex是单一的状态树(state)，如果项目足够大，一颗树显得太臃肿，可以按模块划分成多个独立的状态树(state)。每个 state 都会维护一套由(state, Getters, Mutations, Actions)组成的状态树。

## The State Tree
## Actions
## Mutations
## Getters

## modules
```javascript
const moduleA = {
  state: { ... },
  mutations: { ... },
  actions: { ... },
  getters: { ... }
}

const moduleB = {
  state: { ... },
  mutations: { ... },
  actions: { ... }
}

const store = new Vuex.Store({
  modules: {
    a: moduleA,
    b: moduleB
  }
})

store.state.a // -> moduleA's state
store.state.b // -> moduleB's state
```
