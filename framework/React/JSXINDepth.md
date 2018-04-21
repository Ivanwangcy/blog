# 深入理解 JSX

基本上，JSX只是为 `React.createElement(component，props，... children)` 函数提供语法糖。JSX代码：

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

为了解决这个问题，我们将 `hello` 重命名为 `Hello` ，并在引用它时使用`<Hello />`：

```js
import React from 'react';

// Correct! This is a component and should be capitalized:
function Hello(props) {
  // Correct! This use of <div> is legitimate because div is a valid HTML tag:
  return <div>Hello {props.toWhat}</div>;
}

function HelloWorld() {
  // Correct! React knows <Hello /> is a component because it's capitalized.
  return <Hello toWhat="World" />;
}
```

## 运行时选择类型

您不能使用常规的表达式作为 React 元素类型。如果您确实想使用常规的表达式来指示元素的类型，请将其首先分配给大写变量。

当你想渲染一个基于 props 的不同组件时，通常会出现这种情况：

```js
import React from 'react';
import { PhotoStory, VideoStory } from './stories';

const components = {
  photo: PhotoStory,
  video: VideoStory
};

function Story(props) {
  // Wrong! JSX type can't be an expression.
  return <components[props.storyType] story={props.story} />;
}
```

为了解决这个问题，我们首先将类型赋值给一个大写的变量：

```js
import React from 'react';
import { PhotoStory, VideoStory } from './stories';

const components = {
  photo: PhotoStory,
  video: VideoStory
};

function Story(props) {
  // Correct! JSX type can be a capitalized variable.
  const SpecificStory = components[props.storyType];
  return <SpecificStory story={props.story} />;
}
```

## JSX 中的 Props

有几种不同的方式可以在JSX中指定 props。

### JavaScript 表达式作为 Props

可以将任何 JavaScript 表达式作为 props 传递，方法是使用 `{}` 表示它。例如，在这个 JSX 中：

```js
<MyComponent foo={1 + 2 + 3 + 4} />
```

对于 `MyComponent` ，`props.foo` 的值将为`10`，因为表达式 `1 + 2 + 3 + 4` 会被计算。

如果语句和 `for` 循环不是 JavaScript 中的表达式，那么它们不能直接在 JSX 中使用。相反，你可以把它们放在外围的代码中。例如：

```js
function NumberDescriber(props) {
  let description;
  if (props.number % 2 == 0) {
    description = <strong>even</strong>;
  } else {
    description = <i>odd</i>;
  }
  return <div>{props.number} is an {description} number</div>;
}
```

您可以在相应章节中了解有关 `[条件渲染](https://reactjs.org/docs/conditional-rendering.html)` 和 `[循环](https://reactjs.org/docs/lists-and-keys.html)` 的更多信息。

### String 字面量

你可以传递一个字符串作为 props。这两个JSX表达式是等价的：

```js
<MyComponent message="hello world" />

<MyComponent message={'hello world'} />
```

当你传递一个字符串时，它的值是`HTML-unescaped`(转义的)。所以这两个JSX表达式是等价的：

```js
<MyComponent message="&lt;3" />

<MyComponent message={'<3'} />
```

这种行为通常不相关。这里只提到完整性。

### Props 默认为 "true"

如果您没有为 props 传递任何值，则默认为 `true` 。这两个JSX表达式是等价的：

```js
<MyTextBox autocomplete />

<MyTextBox autocomplete={true} />
```

一般来说，我们不推荐使用ES6对象的简写 `{foo}`，因为它可能与`{foo：foo}`而不是`{foo：true}`混淆。上面那种方式就正好符合 HTML 标准。

### 拓展属性

如果你已经有 props 作为一个对象，并且你想用 JSX 传递它，你可以使用`...`作为“spread” 操作符来传递整个 props 对象。这两个组件是等价的：

```js
function App1() {
  return <Greeting firstName="Ben" lastName="Hector" />;
}

function App2() {
  const props = {firstName: 'Ben', lastName: 'Hector'};
  return <Greeting {...props} />;
}
```

你也可以选择你的组件将使用的特定 props，同时使用拓展运算符传递所有其它 props。

```js
const Button = props => {
  const { kind, ...other } = props;
  const className = kind === "primary" ? "PrimaryButton" : "SecondaryButton";
  return <button className={className} {...other} />;
};

const App = () => {
  return (
    <div>
      <Button kind="primary" onClick={() => console.log("clicked!")}>
        Hello World!
      </Button>
    </div>
  );
};
```

在上面的示例中， `kind` prop 安全地被使用，并且不会传递到DOM中的 `<button>` 元素。

所有其他 props 都通过`...other`对象,使得这个组件非常灵活。你可以看到它传递了一个 `onClick` 和 `children` 属性。

拓展属性可能很有用，但它们还可以轻松地将不必要的 porps 传递给不关心它们的组件或将无效的 HTML 属性传递给 DOM。我们建议谨慎使用这种语法。

## JSX 中的 children

在包含开始标记和结束标记的JSX表达式中，这些标记之间的内容作为特殊的 prop ： `props.children` 传递。有几种不同的方式来传递孩子：

### 字符串文字

您可以在开始标签和结束标签之间放置一个字符串，`props.children` 只是该字符串。这对于许多内置的HTML元素很有用。例如：

```js
<MyComponent>Hello world!</MyComponent>
```

这是有效的 JSX， `MyComponent` 中的 `props.children` 只是字符串 `“Hello world！”`。 HTML 是非转义的，所以你通常可以编写 JSX，就像你以这种方式编写HTML一样：

```js
<div>This is valid HTML &amp; JSX at the same time.</div>
```

JSX在行的开头和结尾删除空格，它也删除空行。
与标签相邻的新行被删除;发生在字符串文字中间的新行会压缩为一个空格。所以这些都呈现相同的内容：

```js
<div>Hello World</div>

<div>
  Hello World
</div>

<div>
  Hello
  World
</div>

<div>

  Hello World
</div>
```

### JSX Children

您可以提供更多的JSX元素作为孩子。这对于显示嵌套组件很有用：

```js
<MyContainer>
  <MyFirstComponent />
  <MySecondComponent />
</MyContainer>
```

您可以将不同类型的子项混合在一起，以便您可以将字符串文字与JSX子项一起使用。这是JSX与HTML相似的另一种方式，因此这是有效的JSX和有效的HTML：

```js
<div>
  Here is a list:
  <ul>
    <li>Item 1</li>
    <li>Item 2</li>
  </ul>
</div>
```

React组件也可以返回一组元素：

```js
render() {
  // No need to wrap list items in an extra element!
  return [
    // Don't forget the keys :)
    <li key="A">First item</li>,
    <li key="B">Second item</li>,
    <li key="C">Third item</li>,
  ];
}
```

### 作为 children 的 JavaScript 表达式

您可以将任何JavaScript表达式作为子项传递，方法是将其放置在 `{}` 中。例如，这些表达式是等价的：

```js
<MyComponent>foo</MyComponent>

<MyComponent>{'foo'}</MyComponent>
```

这通常用于呈现任意长度的 JSX 表达式列表。例如，这呈现一个 HTML 列表：

```js
function Item(props) {
  return <li>{props.message}</li>;
}

function TodoList() {
  const todos = ['finish doc', 'submit pr', 'nag dan to review'];
  return (
    <ul>
      {todos.map((message) => <Item key={message} message={message} />)}
    </ul>
  );
}
```
JavaScript表达式可以与其他类型的 `children` 混合使用。这通常用于替代字符串模板：

```js
function Hello(props) {
  return <div>Hello {props.addressee}!</div>;
}
```

## 函数作为 Children

通常，插入到 JSX 中的 JavaScript 表达式将评估为一个字符串，一个 React 元素或这些东西的列表。

然而，`props.children` 的工作方式与任何其它 props 一样，它可以传递任何类型的数据，而不仅仅是 React 知道如何渲染的类型。

例如，如果你有一个自定义组件，你可以让它作为 props.children 进行回调：

```js
// Calls the children callback numTimes to produce a repeated component
function Repeat(props) {
  let items = [];
  for (let i = 0; i < props.numTimes; i++) {
    items.push(props.children(i));
  }
  return <div>{items}</div>;
}

function ListOfTenThings() {
  return (
    <Repeat numTimes={10}>
      {(index) => <div key={index}>This is item {index} in the list</div>}
    </Repeat>
  );
}
```

传递给自定义组件的子项可以是任何东西，只要该组件将它们转换为 React 在呈现之前可以理解的内容即可。这种用法并不常见，但如果您想要扩展 JSX 的功能，它就可以工作。

## Booleans, Null, and Undefined 将被忽略

`false`, `null`, `undefined`, 和 `true` 是有效的 children。他们根本不被渲染，这些 JSX 表达式都将呈现相同的事物：

```js
<div />

<div></div>

<div>{false}</div>

<div>{null}</div>

<div>{undefined}</div>

<div>{true}</div>
```

这有助于有条件地呈现 React 元素。如果 `showHeader` 为 `true` ，则此 JSX 仅呈现`<Header />`：

```js
<div>
  {showHeader && <Header />}
  <Content />
</div>
```

有一个要注意的地方是，一些 `“falsy”` 的值。如数字 `‘0’`，仍然由 React 渲染。例如，这段代码不会像您所期望的那样工作，因为 `props.messages` 是一个空数组时将会输出`0`：

```js
 // 0
<div>
  {props.messages.length &&
    <MessageList messages={props.messages} />
  }
</div>
```

为了解决这个问题，确保 `&&` 之前的表达式总是布尔值：

```js
<div>
  {props.messages.length > 0 &&
    <MessageList messages={props.messages} />
  }
</div>
```

相反，如果您希望输出中出现 `false`，`true` ，`null` 或 `undefined` 等值，则必须先将其转换为字符串：

```js
<div>
  My JavaScript variable is {String(myVariable)}.
</div>
```