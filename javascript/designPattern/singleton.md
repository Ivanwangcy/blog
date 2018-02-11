# Singleton (单例) 模式

Singleton (单例) 模式被熟知的原因是因为它限制了类的实例化次数只能一次. 从经典意义上来说, Singleton 模式, 在该实例不存在的情况下, 可以通过一个方法创建一个类来实现创建类的新实例; 如果实例已经存在, 它会简单返回该对象的引用. Singleton 不同于静态类(或对象), 因为我们可以推迟它们的初始化, 这通常是因为它们需要一些信息, 而这些信息在初始化期间可能无法获得. 对于没有察觉到之前的引用的代码, 它们不会提供方便检索的方法. 这是因为它既不是对象, 也不是由一个 Singleton 返回的"类"; 它是一个结构. 思考一下闭包变量为何实际上并不是闭包, 而提供闭包的函数作用域是闭包. 在 JavaScript 中, Singleton 充当共享资源命名空间, 从全局命名空间中隔离出代码实现, 从而为函数提供单一访问点. 我们可以像如下这样实现一个 Singleton:
https://github.com/Ivanwangcy/ISourcePlayer/blob/master/design-pattern/singleton.js

值得注意的是类的静态实例 (对象) 和 Singleton 之间的区别: 当Singleton 可以作为一个静态的实例实现时, 它也可以延迟构建, 直到需要使用静态实例时, 无需使用资源或内存.

如果我们有一个可以直接被初始化的静态对象, 需要确保执行代码的顺序总是相同的 (例如: 在初始化期间 objCar 需要 objWheel 的情况), 当我们有大量的源文件时, 它并不能伸缩.

Singleton 和静态对象都是有用的, 但是我们不应该以同样的方式过度使用它们, 也不应该过度使用其他模式.   

在实践中, 当在系统中确实需要一个对象来协调其他对象时, Singleton 模式是很有用的. 在这里, 大家可以看到在这个上下文中模式的使用:

https://github.com/Ivanwangcy/ISourcePlayer/blob/master/design-pattern/singleton.js

Singleton 很有使用价值, 通常当发现现在 JavaScript 中需要它的时候, 则表示我们可能需要重新评估我们的设计.

Singleton 的存在往往表明系统中的模块要么是系统紧密耦合, 要么是其逻辑过于分散在代码库的多个部分. 由于一系列的问题: 从隐藏的依赖到创建多个实例的难度, 底层依赖的难度等等, Singleton 的测试会更加困难.
## ES6 单例模式
```js
class Singleton { }

export default new Singleton

```
