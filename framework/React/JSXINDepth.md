# 深入理解 JSX

基本上，JSX只是为 React.createElement（component，props，... children）函数提供语法糖。JSX代码：

```js
<MyButton color="blue" shadowSize={2}>
  Click Me
</MyButton>
```

编译成：

```js
React.createElement(
  MyButton,
  {color: 'blue', shadowSize: 2},
  'Click Me'
)
```

如果没有 `children` ，也可以使用标签的自闭合形式：

```js
<div className="sidebar" />
```

编译成：

```js
React.createElement(
  'div',
  {className: 'sidebar'},
  null
)
```

## 指定 React 元素类型

JSX标签的第一部分决定了 React 元素的类型。

大写字母表示 JSX 标签引用了 React 组件。这些标签会被编译为对指定变量的直接引用，因此如果使用 JSX `<Foo />` 表达式，则 Foo 必须位于当前作用域内。

### React 必须在当前文件范围内引用

由于 JSX 编译是对 React.createElement 的调用，因此 React 库也必须始终位于 JSX 代码的范围内。

```js
import React from 'react'; // React 必须引入
import CustomButton from './CustomButton'; // JSX 标签必须引入

function WarningButton() {
  // return React.createElement(CustomButton, {color: 'red'}, null);
  return <CustomButton color="red" />;
}
```