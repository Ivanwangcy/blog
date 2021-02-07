# TypeScript

2020 年最红的技术是什么的话，毫无疑问地要属于 TypeScript，随着 TypeScript 新版本的更新，编写前端代码真是越来越对味。

## TypeScript 简介

近几年基于 JavaScript 的前端应用呈指数级增长，随着前端技术的广泛应用，Javascript 项目的复杂度逐渐增加变得越来越不好维护，应对前端多变的特性缺乏良好的扩展性，微软专门针对大型 Javascript 项目提出了 TypeScript 语言，为了提供前端项目的可维护性和扩展性。

TypeScript 是 JavaScript 的超集，与现存的 JavaScript 代码有着非常高的兼容性。任何合法的 JavaScript 它都支持。TypeScript 与生俱来的面向对象特性可以帮助我们更加优雅的写代码。

## 配置 TypeScript

[[翻译] TypeScript 和 JSX 搞基的事](https://github.com/techird/blog/issues/3)

## 安装

```sh
npm i @typescript-eslint/parser typescript
```

## TypeScript 项目标准工程结构

为了更好的应用 TypeScript，我们应该理解 TypeScript 项目组织中的各项功能。

### TypeScipt 编译选项 tsconfig.json

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
