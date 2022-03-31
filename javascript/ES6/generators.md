# 生成器 Generators -- ES6中最具魔力的特性
`Generators` ES6中最具魔力的特性，此特性可以极大地简化代码，它甚至可以帮助你逃离“回调地狱”。

## ES6生成器（Generators）简介
先从一个示例开始：
```javascript
function* quips(name) {
  yield "hello " + name + "!";
  yield "i hope you are enjoying the blog posts";
  if (name.toLowerCase().startsWith("x")) {
    yield "hey, it's cool how your name starts with an X, " + name;
  }
  yield "see you later!";
}

var meow_iter = quips("Xingu");
```

这是一只会说话的猫，这段代码很可能代表着当今互联网上最重要的一类应用。（试着点击[这个链接](http://people.mozilla.org/~jorendorff/demos/meow.html)，与这只猫互动一下，如果你感到有些困惑，回到这里继续阅读）。
这段代码看起来很像一个函数，我们称之为生成器函数，它与普通函数有很多共同点，但是二者有如下区别：  
- 普通函数使用function声明，而生成器函数使用function*声明。  
- 在生成器函数内部，有一种类似return的语法：关键字yield。二者的区别是，普通函数只可以return一次，而生成器函数可以yield多次（当然也可以只yield一次）。在生成器的执行过程中，遇到yield表达式立即暂停，后续可恢复执行状态。  
这就是普通函数和生成器函数之间最大的区别，普通函数不能自暂停，生成器函数可以。  

## 当调用生成器发生了什么?

```javascript
> quips("Ivan");
quips {[[GeneratorStatus]]: "suspended", [[GeneratorReceiver]]: Window}

var meow_iter = quips("Ivan");
> meow_iter
quips {[[GeneratorStatus]]: "suspended", [[GeneratorReceiver]]: Window}
> meow_iter.next();
Object {value: "hello Ivan!", done: false}
> meow_iter.next();
Object {value: "i hope you are enjoying the blog posts", done: false}
> meow_iter.next();
Object {value: "see you later!", done: false}
> meow_iter.next();
Object {value: undefined, done: true}
> meow_iter.next();
```
你大概已经习惯了普通函数的使用方式，当你调用它们时，它们立即开始运行，直到遇到return或抛出异常时才退出执行，作为JS程序员你一定深谙此道。  
生成器调用看起来非常类似：quips("jorendorff")。但是，当你调用一个生成器时，它并非立即执行，而是返回一个已暂停的生成器对象（上述实例代码中的iter）。你可将这个生成器对象视为一次函数调用，只不过立即冻结了，它恰好在生成器函数的最顶端的第一行代码之前冻结了。  
每当你调用生成器对象的.next()方法时，函数调用将其自身解冻并一直运行到下一个yield表达式，再次暂停。  
这也是在上述代码中我们每次都调用iter.next()的原因，我们获得了quips()函数体中yield表达式生成的不同的字符串值。
调用最后一个iter.next()时，我们最终抵达生成器函数的末尾，所以返回结果中done的值为true。抵达函数的末尾意味着没有返回值，所以返回结果中value的值为undefined。  
现在回到[会说话的猫的demo页面](http://people.mozilla.org/~jorendorff/demos/meow.html)，尝试在循环中加入一个yield，会发生什么？  
如果用专业术语描述，每当生成器执行yields语句，生成器的堆栈结构（本地变量、参数、临时值、生成器内部当前的执行位置）被移出堆栈。然而，生成器对象保留了对这个堆栈结构的引用（备份），所以稍后调用.next()可以重新激活堆栈结构并且继续执行。
值得特别一提的是，**生成器不是线程**，在支持线程的语言中，多段代码可以同时运行，通通常导致竞态条件和非确定性，不过同时也带来不错的性能。生成器则完全不同。当生成器运行时，它和调用者处于同一线程中，拥有确定的连续执行顺序，永不并发。与系统线程不同的是，生成器只有在其函数体内标记为yield的点才会暂停。  
现在，我们了解了生成器的原理，领略过生成器的运行、暂停恢复运行的不同状态。那么，这些奇怪的功能究竟有何用处？

## 生成器是迭代器！
