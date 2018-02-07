## Webpack 插件 Tapable V0.2 源码分析
Tapable是一个小型库，允许你添加和应用插件到一个javascript模块。 它可以被继承或混合到其他模块。 它类似于NodeJS的EventEmitter类，专注于自定义事件发射和操作。 但是，除此之外，Tapable允许您通过回调参数访问事件的“排放者”或“生产者”。
