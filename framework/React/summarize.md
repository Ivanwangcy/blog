# React 开发入门

React 13 年面世（13 年 5 月开源），距今有 5 年多了，从热门开始走向成熟，拥有了非常完善的生态圈，覆盖范围广，支持浏览器端和 Native 端。起步也越来越简单，官方文档很完善。

* Web 端：使用 create-react-app 创建一个 React 项目
* Naitve 端：react-native-cli 创建一个 React Native 项目

## 使用 React 需要了解的技术

* JS, CSS, HTML 基础知识
* ES6 标准
* JSX 语法
* 函数式编程概念
* nodejs/npm 基础

## React 组件

创建一个 React 组件，Web 应用和 React Native 应用的区别在于挂载到应用程序的方式不同，组件集不同。Web 组件可以直接使用 html 标签，Native 组件必须从 react-native 包中导入，通常是大驼峰命名。

```js
// 使用 ES6 class
class Welcome extends React.Component {
  render() {
    return <h1>Hello, {this.props.name}</h1>;
  }
}

// 使用 函数创建 无状态组件
function Welcome(props) {
  return <h1>Hello, {props.name}</h1>;
}
```

> [React 快速入门](https://reactjs.org/tutorial/tutorial.html) > [谈一谈创建 React Component 的几种方式](https://segmentfault.com/a/1190000008402834)

### React 组件的生命周期

最新的 React 16.3 生命周期图谱：
![react_lifecircle](/images/react_lifecircle.png)

* constructor(props, context)： React 组件的构造函数，创建时调用一次，主要用于初始化状态（可以通过接收的属性  创建状态）。自定义代码之前必须先调用 `super` 函数。**不可以在这里执行异步的初始化状态，例如异步请求。**
* componentWillMount：组件挂载之前调用一次，这个方法不要再使用了，不要在这里设置状态。16.3 版本以后从生命周期中移除了。
* componentDidMount：组件挂载之后调用一次，可以在这里更新状态，执行异步请求。确保只进行一次 `setState`，如果真的需要  设置  多次  setState，需要在 setState 完成后的回调函数中执行。`setState({}, ()=> {状态更新完成后再执行其他操作})`
* render： render 函数是一个 React 组件必不可少的核心函数，它要返回真正要挂载到应用程序的内容，可以返回 null  表示没有可视内容。**不要在 render 里面修改 state**。
* componentWillReceiveProps(nextProps) 父组件 render 时会调用子组件的该函数。不管属性  有无变化都会被调用，所有最好在这里  进行属性检查，比较与上次的属性是否发生了变化，可以通过变化的属性去更新自己的状态。由于在这里设置状态会  有副作用，V16.3 开始使用 `getDerivedStateFromProps` 来代替该属性。
* getDerivedStateFromProps：在组件实例化以及接收新 props 后调用，它应该返回一个对象来更新状态，或者返回 null 来表示新的道具不需要任何状态更新，如果 props 相同可以减少不必要的 render。
* shouldComponentUpdate：接收到新属性或新状态时调用该函数。在这里判断是否应该更新组件。默认返回：true 是否有变化都会执行 render 函数。为了减少不必要的渲染可以在这里加判断来优化性能。
* componentWillUpdate：组件将要更新，shouldComponentUpdate 返回 true 或者调用 forceUpdate 之后会被调用，不要在这里操作状态，V16.3 后 将其移除。
* componentDidUpdate：除了首次 render 之后调用 componentDidMount，其它 render 结束之后都是调用 componentDidUpdate。
* componentWillUnmount：组件被卸载的时候调用。一般在 componentDidMount 里面注册的事件需要在这里删除，或者一些定时器在这里移除。

### 纯函数 Functional stateless components

通常不需要维护状态，也不需要添加生命周期方法的纯展示型组件可以使用函数的方式创建 React 组件，保持代码的简洁性。

```js
// 完整的例子
import React from "react";
const Button = ({ day, increment }) => {
  return (
    <div>
      <button onClick={increment}>Today is {day}</button>
    </div>
  );
};

Button.propTypes = {
  day: PropTypes.string.isRequired,
  increment: PropTypes.func.isRequired
};
```

### 纯组件 PureComponent

合理使用 PureComponent 能够有效提高 React 应用开发性能。它比普通的 Component 组件多了一层  状态和属性的浅比较。默认的 shouldComponentUpdate 一直返回 true。PureComponent 返回：

```js
!shallowEqual(prevProps, nextProps) || !shallowEqual(inst.state, nextState);
```

由于浅比较是比较指针的异同，所以通常会结合 `[immutable.js](https://github.com/facebook/immutable-js)` 使用，immutable.js 会在每次对原对象进行添加，删除，修改使返回新的对象实例。任何对数据的修改都会导致数据指针的变化。

什么时候需要自己写 shouldComponentUpdate 的实现：

> 只有经过测量，发现有了 shouldComponentUpdate 后组件的渲染速度确实有可察觉的提升，你才应该用它。

参考：

> [React PureComponent 使用指南](http://wulv.site/2017-05-31/react-purecomponent.html) > [PureComponent 的作用及一些使用陷阱](https://www.jianshu.com/p/33cda0dc316a) > [什么时候要在 React 组件中写 shouldComponentUpdate？](http://www.infoq.com/cn/news/2016/07/react-shouldComponentUpdate)

## Container Component 模式

使用容器（Container）组件可以更好的进行数据获取和数据渲染的逻辑分离，进行业务开发的时候也可以进行业务代码和 UI 代码分离。这样做能够更好的定位问题。还可以加入状态管理工具进行更细致的拆分。

一般情况下，开发一个页面首先会采用 Container Components 模式实现。

```js
class CommentListContainer extends React.Component {
  constructor(props) {
    super(props);
    this.state = { result: [] };
  }

  componentDidMount() {
    // 接收上一个页面传递的参数，请求当前页面的数据
    // 请求完成后更新状态
  }

  render() {
    // 将状态传递给具体的展示组件
    return <CommentList comments={this.state.comments} />;
  }
}
```

## 组件间通信

* 父子组件之间用 props 传递数据;
* 父组件更新子组件的状态，通过 ref 属性，访问组件实例，调用子组件的方法。注意：不要滥用 ref，要特定场景下使用，比如：点击父组件控制子组件的显示和隐藏，或者调用子组件的原生方法等等；
* 页面之间使用路由来传递数据；
* 框架类组件，通过特定的 props name 或者 children 接收子组件；

## HOC（Higher Order Component，高阶组件）

高阶组件就是一个 React 组件包裹着另外一个 React 组件。

高阶组件的两种实现方式： Props Proxy (PP) 和 Inheritance Inversion (II)

### Props Proxy

Props Proxy (PP) 的最简实现：

```js
function ppHOC(WrappedComponent) {
  return class PP extends React.Component {
    render() {
      return <WrappedComponent {...this.props} />;
    }
  };
}
```

使用 Props Proxy 可以做什么？

* 操作 props
* 通过 Refs 访问到组件实例
* 提取 state
* 用其他元素包裹 WrappedComponent

### Inheritance Inversion

Inheritance Inversion (II) 的最简实现：

```js
function iiHOC(WrappedComponent) {
  return class Enhancer extends WrappedComponent {
    render() {
      return super.render();
    }
  };
}
```

你可以用 Inheritance Inversion 做什么？

* 渲染劫持（Render Highjacking）
  * 在由 render输出的任何 React 元素中读取、添加、编辑、删除 props
  * 读取和修改由 render 输出的 React 元素树
  * 有条件地渲染元素树
  * 把样式包裹进元素树（就像在 Props Proxy 中的那样）
* 操作 state

理解了高阶组件能够更好的运用 Redux, Mobx, Flux 等状态管理工具。

> [深入理解 React 高阶组件](https://zhuanlan.zhihu.com/p/24776678?group_id=802649040843051008)

## 使用状态管理工具 Redux/Mobx

复杂的页面通过属性传递数据过于麻烦，深层的子组件向上更新更加不容易 ，单纯的使用  观察者模式，更新状态难以避免不必要的渲染，并且事件多了难以维护，不利于多人协作开发。因此我们需要一个能全局或者某个大的业务模块内的状态管理器。

> [https://github.com/reactjs/redux](https://github.com/reactjs/redux)
> [https://github.com/mobxjs/mobx](https://github.com/mobxjs/mobx)
