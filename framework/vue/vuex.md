## vuex 是一个状态管理模式的框架或者叫类库。它适合中到大型的单页项目。

Vuex 要解决的就是这些问题，Vuex 背后有四个核心的概念：

- state 状态树: 包含所有应用级别状态的对象
- Getters: 在组件内部获取 store 中状态的函数
- Mutations: 修改状态的事件回调函数
- Actions: 组件内部用来分发 mutations 事件的函数
- Modules: 按模块拆分多个状态树 -- 默认情况下vuex是单一的状态树(state)，如果项目足够大，一颗树显得太臃肿，可以按模块划分成多个独立的状态树(state)。每个 state 都会维护一套由(state, Getters, Mutations, Actions)组成的状态树。

## state 状态
## actions
## mutations
## getters

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
