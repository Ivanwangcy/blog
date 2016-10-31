## Vue Router 路由

安装Vue 路由。
```sh
$ npm install --save vue-router
# or use yarn
$ yarn add vue-router
```
## 路由使用，创建路由
```javascript

import Vue from 'vue'
import Router from 'vue-router'

Vue.use(Router)

// 导入页面
import HomeView from '../views/HomeView.vue'
import AboutView from '../views/AboutView'
import UserDetailView from '../components/UserDetailView'

export default new Router({
  model: 'history',
  scrollBehavior: () => ({y: 0}),
  routes: [
    { path: '/home', component: HomeView},
    { path: '/user/:storeid/:orgcode', name: 'user', component: AboutView},
    { path: '/detail', component: UserDetailView},
    {path: '*', redirect: 'home'}
  ]
})
```
## 路由的匹配和跳转
### js 代码切换路由 ， 类似于 goto()
```javascript

// 字符串
router.push('home')

// 对象
router.push({ path: 'home' })

// 命名的路由
router.push({ name: 'user', params: { userId: 123 }})

// 带查询参数，变成 /register?plan=private
router.push({ path: 'register', query: { plan: 'private' }})

// 复杂路由，综合使用
router.push({ name: 'user', params: { userId: 123 }, query: {channel: "jd"}})




```

### vue 模板 切换路由, 使用 router-link 跳转目标路由的链接声明
```javascript

// 使用 router-link 跳转目标路由的链接声明

// vue template 应用

<!-- 字符串 -->
<router-link to="home">Home</router-link>
<!-- 渲染结果 -->
<a href="home">Home</a>

<!-- 使用 v-bind 的 JS 表达式 -->
<router-link v-bind:to="'home'">Home</router-link>

<!-- 不写 v-bind 也可以，就像绑定别的属性一样 -->
<router-link :to="'home'">Home</router-link>

<!-- 同上 -->
<router-link :to="{ path: 'home' }">Home</router-link>

<!-- 命名的路由 -->
<router-link :to="{ name: 'user', params: { userId: 123 }}">User</router-link>

<!-- 带查询参数，下面的结果为 /register?plan=private -->
<router-link :to="{ path: 'register', query: { plan: 'private' }}">Register</router-link>

```
### JSX 模板路由应用
```javascript
// 字符串
<router-link to='home'>

// 表达式, 动态路由
<router-link to={this.path}>

// JSX 语法 综合应用
<router-link to={{name: "user", params: {storeid: value.id, orgcode: "daojia"}, query: { channel: 'daojia', hide: true} }}>
```

## 页面内部获取路由信息，参数获取

使用组件内的 this.$route (路由信息对象)

### 常用属性：

- this.$route.params => 路由参数信息，一个 key/value 对象，包含了 动态片段 和 全匹配片段，如果没有路由参数，就是一个空对象。
- this.$route.query => 一个 key/value 对象，表示 URL 查询参数。例如，对于路径 /foo?user=1，则有 $route.query.user == 1，如果没有查询参数，则是个空对象。
- $route.path 匹配的全路径
- $route.hash 路由hash值， 不带 ‘#’
- $route.fullPath 完整的 URL
- $route.matched 已经配置的所有路由，一个数组
- $route.name 当前路由的名称，如果有值得话，是命名路由
```javascript
console.log(this.$route.params);
console.log(this.$route.query);
```
## Vue Router 实例用法
```javascript
// 导入 vue 和 vue-router
import Vue from 'vue'
import Router from 'vue-router'

// 使用路由
Vue.use(Router)

import HomeView from '../views/HomeView.vue'
import AboutView from '../views/AboutView'
import UserDetailView from '../components/UserDetailView'

// 创建路由
export default new Router({
  model: 'history',
  scrollBehavior: () => ({y: 0}), // 路由滚动行为
  routes: [
    { path: '/home', component: HomeView},
    { path: '/user/:storeid/:orgcode', name: 'user', component: AboutView},
    { path: '/detail', component: UserDetailView},
    {path: '*', redirect: 'home'}
  ]
})

```
## scrollBehavior 滚动行为详解
使用前端路由，当切换到新路由时，想要页面滚到顶部，或者是保持原先的滚动位置，就像重新加载页面那样。 vue-router 能做到，而且更好，它让你可以自定义路由切换时页面如何滚动。


## 路由懒加载 按需加载
当打包构建应用时，Javascript 包会变得非常大，影响页面加载。如果我们能把不同路由对应的组件分割成不同的代码块，然后当路由被访问的时候才加载对应组件，这样就更加高效了。

结合 Vue 的 异步组件 和 Webpack 的 code splitting feature, 轻松实现路由组件的懒加载。

我们要做的就是把路由对应的组件定义成异步组件：
```javascript
const Foo = resolve => {
  // require.ensure 是 Webpack 的特殊语法，用来设置 code-split point
  // （代码分块）
  require.ensure(['./Foo.vue'], () => {
    resolve(require('./Foo.vue'))
  })
}
```
这里还有另一种代码分块的语法，使用 AMD 风格的 require，于是就更简单了：
```javascript
const Foo = resolve => require(['./Foo.vue'], resolve)
```
