# TypeScript 实战

2020 年最红的技术是什么的话，毫无疑问地要属于 TypeScript，随着 TypeScript 新版本的更新，编写前端代码真是越来越香。

TypeScript 发展至今，已经成为很多大型项目的标配，其提供的静态类型系统，大大增强了代码的可读性、可维护性和代码质量。

## TypeScript 简介

近几年基于 JavaScript 的前端应用呈指数级增长，随着前端技术的广泛应用，Javascript 项目的复杂度逐渐增加变得越来越不好维护，应对前端多变的特性缺乏良好的扩展性，微软专门针对大型 Javascript 项目提出了 TypeScript 语言，为了提供前端项目的可维护性和扩展性。

TypeScript 是 JavaScript 的超集，与现存的 JavaScript 代码有着非常高的兼容性。任何合法的 JavaScript 它都支持。TypeScript 与生俱来的面向对象特性可以帮助我们更加优雅的写代码。

它可以让绝大部分的错误发生在编码阶段，而不是让错误发生在线上！

接下来介绍一下我们在项目开发过程中形成的一些积累分享给大家。

## TypeScript 类型系统

我们首先了解一下基本类型，这些用法很简单只是把原来的变量声明后面加上 `: [对应的基本类型]` 即可。

基本类型：在开发 ts 过程中，比较常用的数据有：string,number,boolean，数组是比较特殊的类型可以使用后缀 `[]`(例如：string[], number[], boolean[])，还可以使用泛型(`Array<string>`, `Array<number>`, `Array<boolean>`)

## TypeScript 的配置项


## 安装

```sh
npm i @typescript-eslint/parser typescript
```

## TypeScript 项目标准工程结构

为了更好的应用 TypeScript，我们应该理解 TypeScript 项目组织中的各项功能。

### TypeScipt 编译选项 tsconfig.json

选项解读，值得注意的地方

```json
{
  "compilerOptions": {
      "target": "es2017", // 编译目标版本
      "module": "commonjs", // 
      "removeComments": false,
      "preserveConstEnums": true,
      "moduleResolution": "node",
      "experimentalDecorators": true,
      "noImplicitAny": false,
      "allowSyntheticDefaultImports": true,
      "outDir": "lib",
      "noUnusedLocals": true,
      "noUnusedParameters": true,
      "strictNullChecks": true,
      "sourceMap": true,
      "baseUrl": ".",
      "rootDir": ".",
      "jsx": "preserve",
      "jsxFactory": "Taro.createElement",
      "allowJs": true,
      "resolveJsonModule": true,
      "typeRoots": [
        "node_modules/@types"
      ]
  },
  "include": [
    "src/**/*",
  ],
  "exclude": [
    "node_modules",
    "dist"
  ],
  "compileOnSave": false
}

```

### 分离关注点

数字数组处理：

```JavaScript
type TransformFunction = (value: number) => number

function doNothing(value: number): number ( // doNothing() 只返回原数据，不进行任何处理
  return value
)

function getNumbers(transform: TransformFunction = doNothing): number[] {
    /** */
}
```
对象数组处理：

```JavaScript
type PluckFunction = (widgets: Widget) => Widget[]

function pluckAll(widgets:  Widget[]):  Widget[] ( // pluckAll() 只返回全部，不进行任何处理
  return widgets
)

// 如果用户没有提供 pluck() 函数，则返回 pluckAll 作为实参的默认值
function assembleWidgets(pluck: PluckFunction = pluckAll): AssembledWidget[] {
    /** */
}
```

泛型恒等函数：

```JavaScript
function identify<T>(value: T):  T ( // 有一个类型参数 T 的泛型恒等函数
  return value
)

// 如果用户没有提供 pluck() 函数，则返回 pluckAll 作为实参的默认值
function assembleWidgets(pluck: PluckFunction = identify): AssembledWidget[] {
    /** */
}
```

### 数值二叉树

```javascript
class NumberBinaryTreeNode {
  value: number
  left: NumberBinaryTreeNode | undefined
  right: NumberBinaryTreeNode | undefined

  constructor(value: number) {
    this.value = value
  }
}

// 泛型二叉树
class BinaryTreeNode<T> {
  value: T
  left: BinaryTreeNode<T> | undefined
  right: BinaryTreeNode<T> | undefined

  constructor(value: T) {
    this.value = value
  }
}
```

### 字符串链表

```javascript
class StringLinkedListNode {
  value: string
  next: StringLinkedListNode | undefined

  constructor(value: string) {
    this.value = value
  }
}

// 泛型链表
class LinkedListNode<T> {
  value: T
  next: LinkedListNode<T> | undefined

  constructor(value: T) {
    this.value = value
  }
}

// 可以迭代的链表完整实现

type IteratorResult<T> = {
  done: boolean
  value: T
}

interface Iterator<T> {
  next(): IteratorResult<T>
}

class LinkedListIterator<T> implements Iterator<T> {
  private head: LinkedListNode<T>
  private current: LinkedListNode<T> | undefined

  constructor(head: LinkedListNode<T>) {
    this.head
    this.current
  }

  next(): IteratorResult<T> {
    if(!this.current) {
      return { done: true, value: this.head.value }
    }

    const result: T: this.current.value
    this.current = this.current.next
    return { done: false, value: result }
  }
}

interface IterableIterator<T> extends Iterator<T> {
    [Symbol.iterator](): IterableIterator<T>;
}
// 生成器链表迭代器 
function* linkedListIterator<T>(head: LinkedListNode): IterableIterator<T> {
  let current: LinkedListNode<T> | undefined = head
  while (current) {
    yield current.value // 在遍历链表过程中，交出每个值
    current = current.next
  }
}

class LinkedListNode<T> implements Iterable<T> {
  value: T
  next: LinkedListNode<T> | undefined

  constructor(value: T) {
    this.value = value
  }

  // Symbol.iterator 是 TypeScript 特有语法，预示着当前对象可以使用 for ... of 遍历
  [Symbol.iterator](): Iterator<T> { 
    return linkedListIterator(this)
  }
}
```

## 


### 配置 lint

.eslintrc

```json
{
    "extends": ["taro"],
    "rules": {
        "no-unused-vars": ["error", { "varsIgnorePattern": "Taro" }],
        "react/jsx-filename-extension": [
            1,
            { "extensions": [".js", ".jsx", ".tsx"] }
        ],
        "jsx-quotes": ["error", "prefer-double"]
    },
    "parser": "@typescript-eslint/parser",
    "parserOptions": {
        "ecmaFeatures": {
            "jsx": true
        },
        "useJSXTextNode": true,
        "project": "./tsconfig.json"
    }
}
```

## 有用的工具

### 接口类型生成 TypeScript 插件 - Paste JSON as Code

安装这个 VSCode 插件可以将接口返回的数据，自动转换成类型定义接口文件。

- 将 JSON 串复制到剪贴板， Ctrl + Shift + P 找到命令：Paste JSON to Types

```js
var obj = {
  "a":1,
  "b":2,
  "c":3
}

// Paste JSON to Types 
export interface TopLevel {
  a: number;
  b: number;
  c: number;
}

```

- 将 JSON 文件转换成 TS 文件：

打开 JSON 文件使用 命令 Open quicktype for JSON

![JsonToType](/assets/JsonToType.jpg)


### 5.1 TypeScript 演练场

TypeScript 开发团队提供了一款非常实用的在线代码编辑工具——TypeScript 演练场
地址：https://www.typescriptlang.org/zh/play
左侧编写 TS 代码，右侧自动生成编译后的代码；
可以自主选择 TypeScript 编译版本；
版本列表最后一项是一个特殊版本 “Nightly” 即 “每日构建版本”，想尝试最新功能可以试试；
支持 TypeScript 大部分配置项和编译选项，可以模拟本地环境，查看代码片段的输出结果；
### 5.2 JSDoc Generator 插件

如果使用的是 vscode 编辑器直接搜索（ JSDoc Generator 插件）插件地址：https://marketplace.visualstudio.com/items?itemName=crystal-spider.jsdoc-generator 安装成功后，使用 Ctrl + Shift + P 打开命令面板，可以进行如下操作可以自动生成带有 TypeScript 声明类型的文档注释：
选择 Generate JSDoc 为当前光标处代码生成文档注释；
选择Generate JSDoc for the current file 为当前文件生成文档注释；
### 5.3 代码格式化工具
VSCode 仅提供了基本的格式化功能，如果需要定制更加详细的格式化规则可以安装专用的插件来实现。我们使用 Prettier 功能非常强大（推荐使用），它是目前最流行的格式化工具： https://prettier.io/，同时也提供了一个在线编辑器：https://prettier.io/playground/
5.4 模块导入自动归类和排序
在多人协作开发时代码越来越复杂，一个文件需要导入很多模块，每个人都会加加着加着就有点乱了，绝对路径的、相对路径的，自定义模块、公用模块顺序和类别都是混乱的，模块导入过多还会出现重复的。引入 TypeScript 之后检查更加严格，导入的不规范会有错误提示，如果只靠手动优化工作量大且容易出错。VSCode 编辑器提供了按字母顺序自动排序和归类导入语句的功能，直接按下快捷键“Shift + Alt + O”即可优化。也可以通过右键菜单“Source Action” 下的 “Organize Imports” 选项来进行优化导入语句。
### 5.5 启用 CodeLens

CodeLens 是一项特别好用的功能，它能够在代码的位置显示一些可操作项，例如：
显示函数、类、方法和接口等被引用的次数以及被哪些代码引用；
显示接口被实现的次数以及谁实现了该接口；
VSCode 已经内置了 CodeLens 功能，只需要在设置面板开启，找到TypeScript 对应的 Code Lens 两个相关选项并勾选上：
开启后的效果，出现引用次数，点击 references 位置可以查看哪里引用了：

## any 类型

声明一个变量为任意值之后，编译器无法帮助你进行类型检测和代码提示。


## void 类型

在TypeScript 中，可以使用 void 关键字表示没有任何返回值的函数。

## 枚举的使用

我们在使用枚举时候通常是这样：

```ts
enum StateEnum {
  OPENED,
  CLOSED
}

const  strategyState = StateEnum.OPENED
```

但是我们发现编译后代码量反而增加了

```js
var StateEnum;
(function (StateEnum) {
    StateEnum[StateEnum["OPENED"] = 0] = "OPENED";
    StateEnum[StateEnum["CLOSED"] = 1] = "CLOSED";
})(StateEnum || (StateEnum = {}));
const strategyState = StateEnum.OPENED;
```

这样视乎看起来并没有什么好处还不如直接写一个常量对象。例如这样：

```js
const StateEnum = {
  OPENED: 0,
  CLOSED: 1,
}
```

这样又回到了传统的 javascript ，那么我们有什么更好的方法呢？TypeScript 也给我们带来了性能提升的一个小技巧是使用`常量枚举`：

```js
// 常量枚举
const enum Tristate {
  False,
  True,
  Unknown
}

const lie = Tristate.False;
```

ts 编译后的结果：

```js
const lie = 0 /* False */; // 只剩下这一句了
```

## 接口定义

使用 `interface` 关键字定义一个接口

## 命名空间与模块

namespace

## value! 非空验证

## TypeScript 类型推导

## 贡献类型文件

发布到 npm

- 与你的npm包捆绑在一起
- 发布到 npm 上的 @types organization

## JSDOC

## 使用装饰器进行 AOP

在 TypeScript 中，装饰器是最好用的功能之一。它是一段代码在不改变类的内部实现的情况下，改变一个类的行为。通过装饰器可以避免继承带来的副作用，优于继承方式。

使用装饰器需要设置 tsconfig 配置文件：

```json
"experimentalDecorators": true
```

## TypeScript 编译原理

TypeScript 编译器由几个关键部分组成：

- Scanner 扫描器
- Parser 解析器
- Binder 绑定器
- Checker 检查器
- Emitter 发射器

推荐的工具：

[一个用于 TypeScript 和 JavaScript 的在线编辑器](https://www.typescriptlang.org/zh/play)，可以实时看到我们的 ts 代码编译结果。

※ 定制一款在线 TS 类型生成。

```js
let a = 10 // to let a: number = 10
```
