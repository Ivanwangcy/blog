## 什么是tree shaking?
简单说就是消除unused code.   
 
作者：顾轶灵
链接：https://www.zhihu.com/question/41922432/answer/93068390
来源：知乎
著作权归作者所有，转载请联系作者获得授权。

看了一篇 rollup.js 作者解释 tree-shaking 的文章：Tree-shaking versus dead code elimination。

在 JS 中的这种 tree-shaking 是他命名的。webpack 中应该是类似的做法，就先说说 rollup.js。

首先，rollup.js 的 tree-shaking 不光是模块级别的，但是也仅处理了顶层 AST。（比 CommonJS/AMD 的按需打包稍细，但不深入 AST 更深层的部分）。Tree-shaking 是无用代码移除（DCE, dead code elimination）的一个方法，但和传统的方法不太一样。Tree-shaking 找到需要的代码，灌入最终的结果；传统 DCE 找到执行不到的代码，从 AST 里清除。（在我看来传统的这种方式更应该被称为 tree-shaking，即摇一下把 AST 中的 dead branch 给抖下来。）作者还用了一个和 DCE 相对应的说法：Live code inclusion。这种方式在目前流行的模块式开发、最后通过 entry 打包出 bundle 的模式下，才有实际意义。

有人总结了一个定义：DCE 消灭不可能执行的代码，tree-shaking 消灭没有用到的代码。作者表示这个定义可以接受。但他表示，因为 tree-shaking 还不完善，所以建议使用中最好先用 rollup.js 再过 UglifyJS。
