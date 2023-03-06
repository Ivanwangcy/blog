# TypeScript 4.5 正式版发布，大量新特性和功能优化

AI 写作开源模型【SkyChat】 ：让你的项目快速具备 AI 写作能力 >>>>> 
11 月 17 日，微软发布了 TypeScript 4.5 正式版本 ，4.5 正式版本和 RC 版本在功能上并没有什么改动，除了添加关于新 JSDoc 特性的注释 ，不过这个特性也是 RC 版本的新功能，只是当时没有写出来。

TypeScript 4.5 正式版新特性：

实验性功能：在夜间（nightly）版本支持  Node.js 运行 ECMAScript 模块。（Nightly 版本属于测试性质的版本，每天都会发新版，包含最新的功能 / 特性，但同时也会包含最新的 Bug）
从 node_modules 支持 lib
新的 Awaited 类型和对 Promise 对象的优化
模板字符串可以用作判断符
引入 es2022 模块（可以在异步函数之外使用 await）
移除 Conditional Types 的尾部递归
禁用省略型 Import ，加入新的 Import 类型修饰符
现在可以检查一个对象是否有一个私有字段
支持 Import 断言
JSDoc 中的常量断言和默认类型参数
对所有系统的 Node.js 引入 realpathSync.native 函数， 减少项目加载时间（Windows 少了 5-13%） 。
两个新的代码补全功能：重写或实现类中的方法的片段补全、JSX 属性的代码补全
编辑器对未解析的类型会直接展示原名（之前版本是用 any 来代替未解析的类型）。
关于 TypeScript 4.5 的新特性，我们在报导 TypeScript 4.5 RC 版本的时候就已经介绍过一些，包括在夜间版本支持  Node.js 运行 ECMAScript 模块、新的代码片段自动补全功能等，下面笔者再来介绍另外几个新特性：

Awaited 类型 和 Promise 优化
TypeScript 4.5 引入了一种新的实用程序类型： Awaited 类型，这种类型是为了建模，像异步函数（async functions）中的 await 这样的操作，或者是 promise 上的 .then() 方法 ，总体来说就是它们递归展开 promise 的方式。

// A = string
type A = Awaited<Promise<string>>;

// B = number
type B = Awaited<Promise<Promise<number>>>;

// C = boolean | number
type C = Awaited<boolean | Promise<number>>;
该 Awaited 类型有利于建模现有的 API，包括像 Promise.all 、 Promise.race 这些 JavaScript 内置模板。事实上，一些关于 Promise.all 推理的问题是促进了 Awaited 类型的研究，比如这个在 TypeScript 4.4 和更早版本中失败的例子：

eclare function MaybePromise<T>(value: T): T | Promise<T> | PromiseLike<T>;

async function doSomething(): Promise<[number, number]> {
    const result = await Promise.all([
        MaybePromise(100),
        MaybePromise(200)
    ]);

    // Error!
    //
    //    [number | Promise<100>, number | Promise<200>]
    //
    // is not assignable to type
    //
    //    [number, number]
    return result;
}
在 TypeScript 4.5 中， Promise.all 结合 await 的特性以提供更好的推断结果，所以上面的例子是有效的。

 从 node_modules 支持 lib
为了确保 TypeScript 和 JavaScript 能够开箱即用，TypeScript 捆绑了一系列声明文件 (.d .ts 文件)。这些声明文件表示 JavaScript 语言中可用的 api 和标准的浏览器 DOM api。虽然根据文件目标有一些合理的默认值，但是您可以通过在 tsconfig.json 中配置 lib 设置，来挑选程序使用哪些声明文件。

TypeScript 4.5 引入了一种覆盖特定内置库的方法，类似于 @types/support 的工作方式。在决定 TypeScript 应该包含哪些 lib 文件时，它首先会在 node_modules 中寻找一个有作用域的 @typescript/lib-* 包。例如，当在 lib 中包含 dom 选项时，TypeScript 会使用 node_modules/@typescript/lib-dom 中的类型。

然后可以安装一个特定的包来接管给定的库。例如，现在 TypeScript 在 @types/web 上发布 DOM api 版本。如果你想锁定你的项目到一个特定版本的 DOM api，可以添加这个到你的 package.json：

{
 "dependencies": {
    "@typescript/lib-dom": "npm:@types/web"
  }
}
从 TypeScript 4.5 开始，依赖管理器的锁文件（lockfile）会确保使用的 DOM 类型的版本完全相同。

模板字符串可以用作判断符
TypeScript 4.5 可以缩小具有模板字符串类型的值，也可以将模板字符串类型识别为判断符。比如下面这组代码，以前会报错，在 4.5 可以成功进行类型检查：

export interface Success {
    type: `${string}Success`;
    body: string;
}

export interface Error {
    type: `${string}Error`;
    message: string;
}

export function handler(r: Success | Error) {
    if (r.type === "HttpSuccess") {
        // 'r' has type 'Success'
        let token = r.body;
    }
}
有关此功能的更多信息，请参阅启用该特性的项。

--module es2022
TypeScript 现在支持一个新 module 设置：  es2022 ，es2022 的主要特性是顶层的 await ，意味着可以在异步函数之外使用 await 。

禁用省略型导入
在某些情况下，TypeScript 无法检测到你正在使用导入，比如：

import { Animal } from "./animal.js";

eval("console.log(new Animal().isDangerous())");
在 TypeScript 4.5 中，你可以启用一个名为  preserveValueImports 的新标志，以防止 TypeScript 从 JavaScrip 输出中剥离任何导入的值。

此问题详情可点此参阅。

私有字段检查
TypeScript 4.5 支持 ECMAScript 提议，用于检查对象是否具有私有字段。现在可以编写一个具有 #private 字段的类， 并使用 in 运算符查看另一个对象是否具有相同的字段 。

class Person {
    #name: string;
    constructor(name: string) {
        this.#name = name;
    }

    equals(other: unknown) {
        return other &&
            typeof other === "object" &&
            #name in other && // <- this is new!
            this.#name === other.#name;
    }
}
导入断言（Import Assertions）
TypeScript 4.5 支持导入断言，这是运行时用来确保导入具有预期格式的语法。

import obj from "./something.json" assert { type: "json" };
这些断言的内容不会被 TypeScript 检查，因为它们特定于主机，只是让浏览器和运行时可以处理它们 (可能还会出错)。

// TypeScript is fine with this.
// But your browser? Probably not.
import obj from "./something.json" assert {
    type: "fluffy bunny"
};
动态 import () 调用还可以通过第二个参数使用 import 断言，第二个参数的预期类型是由一个名为 ImportCallOptions 的新类型定义的，目前只接受 assert 属性。

const obj = await import("./something.json", {
    assert: { type: "json" }
})
JSDoc 中的常量断言和默认类型参数
TypeScript 4.5 为 JSDoc 支持带来了一些额外的表现力，其中一个是 const 断言，可以通过在字面量后面写 const 来获得更精确、更不可变的类型。

// type is { prop: string }
let a = { prop: "hello" };

// type is { readonly prop: "hello" }
let b = { prop: "hello" } as const;
在 JavaScript 文件中，现在可以使用 JSDoc 类型断言来实现相同的功能：

// type is { prop: string }
let a = { prop: "hello" };

// type is { readonly prop: "hello" }
let b = /** @type {const} */ ({ prop: "hello" });
JSDoc 类型断言的注释以 /** @type {TheTypeWeWant} */ 开头，后面跟着一个圆括号表达式：

/** @type {TheTypeWeWant} */` (someExpression)
TypeScript 4.5 为 JSDoc 添加了默认类型参数，这意味着在 TypeScript 中有以下类型声明：

type Foo<T extends string | number = number> = { prop: T };
可以在 JavaScript 中重写为以下的 @typedef 声明：

/**
 * @template {string | number} [T=number]
 * @typedef Foo
 * @property prop {T}
 */

// or

/**
 * @template {string | number} [T=number]
 * @typedef {{ prop: T }} Foo
 */
有关 TypeScript 4.5 的更多详尽信息，可查看微软发布博客原文。

本文引用地址：<https://www.oschina.net/news/169492/typescript-4-5-released>