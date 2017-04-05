## Virtual Dom
React 和 Vue 2 都使用了 Virtual Dom 技术，Virtual Dom 并不是真正意义上的 DOM，而是一个轻量级的 JavaScript 对象，在状态发生变化时，Virtual Dom 会进行 Diff 运算，来更新只需要被替换的 DOM，而不是全部重绘。与 DOM 操作相比，Virtual Dom 是基于 JavaScript 计算，所以开销会小很多。  
在 Vue2 里，就是通过 Render 函数来实现 Virtual Dom 的。
