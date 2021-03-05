# TypeScript 实战

2020 年最红的技术是什么的话，毫无疑问地要属于 TypeScript，随着 TypeScript 新版本的更新，编写前端代码真是越来越香。

TypeScript 发展至今，已经成为很多大型项目的标配，其提供的静态类型系统，大大增强了代码的可读性和可维护性。

## TypeScript 简介

近几年基于 JavaScript 的前端应用呈指数级增长，随着前端技术的广泛应用，Javascript 项目的复杂度逐渐增加变得越来越不好维护，应对前端多变的特性缺乏良好的扩展性，微软专门针对大型 Javascript 项目提出了 TypeScript 语言，为了提供前端项目的可维护性和扩展性。

TypeScript 是 JavaScript 的超集，与现存的 JavaScript 代码有着非常高的兼容性。任何合法的 JavaScript 它都支持。TypeScript 与生俱来的面向对象特性可以帮助我们更加优雅的写代码。

接下来介绍一下我们在项目开发过程中形成的一些积累分享给大家。

## TypeScript 的配置项


## 安装

```sh
npm i @typescript-eslint/parser typescript
```

## TypeScript 项目标准工程结构

为了更好的应用 TypeScript，我们应该理解 TypeScript 项目组织中的各项功能。

### TypeScipt 编译选项 tsconfig.json

选项解读，值得注意的地方

```sh
{
  "compilerOptions": {
      "target": "es2017",
      "module": "commonjs",
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
  "exclude": [
    "node_modules",
    "dist"
  ],
  "compileOnSave": false
}

```

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

## 接口类型生成 TypeScript 插件 - Paste JSON as Code

安装这个 VSCode 插件可以将接口返回的数据，自动转换成 类型定义接口文件。

- 将 JSON 串复制到剪贴板， Ctrl + Shift + P 找到命令：Paste JSON to Types

```js
var obj = {
  a:1,
  b:2,
  c:3
}

// Paste JSON to Types 
export interface TopLevel {
  a: number;
  b: number;
  c: number;
}

```

- 将 JSON 文件转换成成 TS 文件：

打开 JSON 文件使用 命令 Open quicktype for JSON

![JsonToType](/assets/JsonToType.jpg)

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