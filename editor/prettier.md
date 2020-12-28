# 团队中使用 Prettier 来统一代码风格

团队开发过程中，每个人用的编辑器不统一，代码书写风格不统一，增加了他人维护和理解的难度。因此我们需要一个工具来做这件事。它不仅适合新项目，同样适用于现有的项目，一行命令就能处理所有文件，方便快捷。还可以结合编辑器，保存代码时自动格式化代码。它可以和 lint 工具形成互补的作用。

## Prettier 是什么

Prettier 是有独特见解的（opinionated）代码格式化工具，它支持各种前端编程语言。

* JavaScript, 包含 [ES6+](https://github.com/tc39/proposals/blob/master/finished-proposals.md)
* [JSX](https://facebook.github.io/jsx/)
* [Flow](https://flow.org/)
* [TypeScript](https://www.typescriptlang.org/)
* CSS, [Less](http://lesscss.org/), and [SCSS](http://sass-lang.com/)
* [JSON](http://json.org/)
* [GraphQL](http://graphql.org/)
* [Markdown](http://commonmark.org/), including [GFM](https://github.github.com/gfm/)

它不仅仅是一个代码格式化工具，还可以定制任何你想要的代码风格。它会把你原先的个性化代码风格，转换成符合规范的代码风格，与他人保持一致。  
它会根据不同情况输出新的代码：

```js
foo(arg1, arg2, arg3, arg4);
```

它正好一行，所以它将保持原样。但是，代码经过不断更新后，我们遇到了这种情况：

```js
foo(reallyLongArg(), omgSoManyParameters(), IShouldRefactorThis(), isThereSeriouslyAnotherOne());
```

突然间，觉得按照以前的格式变得难以阅读，因为这太长了。 Prettier 会为你做这些细致入微的工作：

```js
foo(
  reallyLongArg(),
  omgSoManyParameters(),
  IShouldRefactorThis(),
  isThereSeriouslyAnotherOne()
);
```

Prettier 采用一致的代码风格（即不会影响 AST 的代码格式）跨越整个代码库，因为它通过解析原始代码风格并用自己的规则重新打印解析后的 AST，将最大行长考虑在内，并在必要时封装代码。

## 为什么使用 Prettier

### 组建并实施一套统一的代码风格指南

通常来说，有一套共同的遵守的风格指南对于一个项目和团队来说很有价值，但是要达成一致是一个非常痛苦并收效甚微的过程。人们对编写代码的特定方式感到非常情绪化，没有人喜欢花时间去遵守一套规范来写代码。  
那么为什么选择“ Prettier 的风格指南” 而不是其它的？因为 Prettier 是唯一一个完全自动化的“风格指南”。即使 Prettier 没有按照你喜欢的方式 100％ 编码所有代码，鉴于 Prettier 的独特优势，这是值得“牺牲”的。

### 有助于新成员

使用 Prettier 最大的受益的人是代码库的新成员。有人可能会认为它只适用于编程经验非常有限的人，但我们看到它加速了加入该公司的经验丰富的工程师的上手时间。因为他们之前可能使用了不同的编码风格，或者是来自不同的编程语言的开发者。

### 一些亮点展示

```js
// 源代码1
var a={a:1,b:2}

// 输出
var a = { a: 1, b: 2 }

// 源代码2
var num=1+2+3+4+4

// 输出
var num = 1 + 2 + 3 + 4 + 4

// 源代码3
var str='这是一个亮点展示的'+a.a+'第'+a.b+'个示例'+'这是一个亮点展示的'+a.a+'第'+a.b+'个示例'+'这是一个亮点展示的'+a.a+'第'+a.b+'个示例'+'这是一个亮点展示的'+a.a+'第'+a.b+'个示例';

// 输出
var str =
  '这是一个亮点展示的' +
  a.a +
  '第' +
  a.b +
  '个示例' +
  '这是一个亮点展示的' +
  a.a +
  '第' +
  a.b +
  '个示例' +
  '这是一个亮点展示的' +
  a.a +
  '第' +
  a.b +
  '个示例' +
  '这是一个亮点展示的' +
  a.a +
  '第' +
  a.b +
  '个示例'

  。。。。。
```

更多输出效果可试一下这个 [`playground`](https://prettier.io/playground/)

## 如何应用 Prettier

将 Prettier 应用到自己的项目中，全局安装并保存到 package.json 中，增加依赖关系便于其他人同步：

```sh
## 安装方式
$ npm install --global prettier
$ npm i -D prettier
```

## 使用说明

通过 CLI 运行 Prettier：

```sh
# 设置各种选项 和 需要格式化的文件
prettier [opts] [filename ...]
```

### 选项：

* --write 改写文件，格式化结果体现在文件中
* --print-width 最大行长 (默认 80)
* --tab-width 一个 tab 的长度 （默认 2）
* --use-tabs 是否使用 tab(制表符) （默认 false，不使用 tab 统一用空格）
* --no-semi 在语句结尾处移除分号
* --single-quote JS 代码使用单引号，jsx 属性保留双引号
* --trailing-comma <none|es5|all> 添加尾随逗号，有 3 个选项 (默认 none 不添加)
* --no-bracket-spacing 是否在对象大括号开头结尾增加空格
* --jsx-bracket-same-line jsx 的 `>` 是否放在语句最后面，而不是单独一行
* --require-pragma 是否只格式化 注释带有 `@prettier @format` 标记的文件
* --insert-pragma 格式化文件后是否添加一个 `@format` 注释标记

### 忽略部分代码

有的情况下，某段代码不想被格式化，可以使用注释来加标识跳过。

* js 代码忽略

```js
// prettier-ignore
matrix(
  1, 0, 0,
  0, 1, 0,
  0, 0, 1
)
```

* Jsx 代码忽略

```jsx
{/* prettier-ignore */}
<span     ugly  format=''   ></span>
```

* css 代码忽略

```CSS
/* prettier-ignore */
.my    ugly rule
{

}
```

* Markdown 代码忽略

```md
<!-- prettier-ignore -->
Do   not    format   this
```

### 项目中应用实例：

方便快捷，只需要一条命令即可处理所有文件：

```sh
prettier --write --print-width 100 --tab-width 4 --no-semi '**/*.js' '**/*.jsx'
```

添加到 `package.json` 的 "scripts" 中，使用 npm run 执行：

```js
"scripts": {
  "prettier": "prettier --write --print-width 100 --tab-width 4 --no-semi '**/*.js'",
  ...
}
```

增加配置文件便于维护 `.prettierrc`：

```js
{
  "printWidth": 100,
  "singleQuote": true,
  "tabWidth": 2,
  "trailingComma": "es5",
  "semi": false,
  "bracketSpacing": true,
  "jsxBracketSameLine": false,
  "arrowParens": "avoid"
}
```

命令行可以不用涉及配置信息：

```js
"prettier": "prettier --write '**/*.js"
```

其它团队成员使用时直接执行 prettier 命令

```sh
npm run prettier
```

## 集成编辑器

### Atom

安装 `prettier-atom` 包，使用快捷键 `Ctrl+Alt+F` 格式化当前文件。

### Visual Studio Code

安装 `prettier-vscode` 插件。

:prettier 插件快捷键 ctrl + alt + B 格式化当前文件;

### Webstorm

如果是 2018.1 及以上版本，自带 Prettier 插件。  
其它版本安装参考链接： [https://blog.jetbrains.com/webstorm/2016/08/using-external-tools/](https://blog.jetbrains.com/webstorm/2016/08/using-external-tools/)

## 添加 prettier 徽章：

在自己代码库中添加 `prettier` 徽章，代表遵循规范的象征，既然用了，就要留一个记号，可以告诉别人我使用了 prettier。别人进入你项目主页时就很清晰的知道你用了什么工具。  
在自己的代码库 README.md 中增加如下代码：  
[![code style: prettier](https://img.shields.io/badge/code_style-prettier-ff69b4.svg?style=flat-square)](https://github.com/prettier/prettier)

```md
[![code style: prettier](https://img.shields.io/badge/code_style-prettier-ff69b4.svg?style=flat-square)](https://github.com/prettier/prettier)
```

> 参考链接:

* [prettier 官方网址](https://prettier.io/)
* [prettier github 地址](https://github.com/prettier/prettier)
* [我为什么推荐 Prettier 来统一代码风格](https://kiwenlau.com/2017/10/23/format-code-use-Prettier/)
* [Code Formatting en](https://survivejs.com/maintenance/code-quality/code-formatting/)

## 自动代码格式化

当我们在git中进行提交时，要格式化我们的代码，我们需要安装以下依赖项：

```sh
npm install --save husky lint-staged prettier
```

* `husky` 可以很容易地使用 githooks ，就好像它们是 npm scripts;
* `lint-staged` 允许我们在git中的staged文件上运行脚本。看到这篇关于`[lint-staged的博客文章](https://medium.com/@okonetchnikov/make-linting-great-again-f3890e1ad6b8)`，了解更多信息。
* `prettier` 是我们将在提交之前运行的JavaScript格式化程序。

```js
+ "lint-staged": {
+   "src/**/*.{js,jsx,json,css}": [
+     "prettier --single-quote --write",
+     "git add"
+   ]
+ },
  "scripts": {
+   "precommit": "lint-staged",
```

## ➒➍➌➏➐
