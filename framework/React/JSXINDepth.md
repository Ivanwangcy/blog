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

如果你想测试一些特定的JSX如何转换成JavaScript，你可以尝试`[在线的 Babel 编译器](https://babeljs.io/repl/#?presets=react&code_lz=GYVwdgxgLglg9mABACwKYBt1wBQEpEDeAUIogE6pQhlIA8AJjAG4B8AEhlogO5xnr0AhLQD0jVgG4iAXyJA)`。

## 指定 React 元素类型

JSX标签的第一部分决定了 React 元素的类型。

大写字母表示 JSX 标签引用了 React 组件。这些标签会被编译为对指定变量的直接引用，因此如果使用 JSX `<Foo />` 表达式，则 `Foo` 必须位于当前作用域内。

### React 必须在当前文件范围内引用

由于 JSX 编译是对 `React.createElement` 的调用，因此 `React` 库也必须始终位于 JSX 代码的范围内。

例如，即使 `React` 和 `CustomButton` 没有直接从 JavaScript 代码中引用，这个代码中的两个导入都是必需的：

```js
import React from 'react'; // React 必须引入
import CustomButton from './CustomButton'; // JSX 标签必须引入

function WarningButton() {
  // return React.createElement(CustomButton, {color: 'red'}, null);
  return <CustomButton color="red" />;
}
```

如果您不使用 JavaScript bundler 程序并从 `<script>` 标记加载 React，则 `React` 已经在全局的范围内。

## JSX 使用点符号

你也可以在 JSX 中使用点符号来引用React组件。如果你有一个导出许多 React 组件的单个模块，这很方便。例如，如果 `MyComponents.DatePicker` 是一个组件，您可以直接从 JSX 使用它：

```js
import React from 'react';

const MyComponents = {
  DatePicker: function DatePicker(props) {
    return <div>Imagine a {props.color} datepicker here.</div>;
  }
}

function BlueDatePicker() {
  return <MyComponents.DatePicker color="blue" />;
}
```

## 用户自定义的组件必须使用大写

当元素类型以小写字母开头时，它指向一个内置组件，如`<div>`或`<span>`，并产生一个传递给 `React.createElement` 的字符串 `'div'` 或 `'span'`。以大写字母（如`<Foo />`）开头的类型编译为 `React.createElement(Foo)` 并对应于 JavaScript 文件中定义或导入的组件。

我们建议用大写字母命名组件。如果您确实有一个以小写字母开头的组件，请在将它用于JSX之前将其分配给大写变量。

例如，这段代码不会按预期运行：

```js
import React from 'react';

// Wrong! This is a component and should have been capitalized:
function hello(props) {
  // Correct! This use of <div> is legitimate because div is a valid HTML tag:
  return <div>Hello {props.toWhat}</div>;
}

function HelloWorld() {
  // Wrong! React thinks <hello /> is an HTML tag because it's not capitalized:
  return <hello toWhat="World" />;
}
```