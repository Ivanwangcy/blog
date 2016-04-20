# 生成器 Generators -- ES6中最具魔力的特性
`Generators` ES6中最具魔力的特性，此特性可以极大地简化代码，它甚至可以帮助你逃离“回调地狱”。

# ES6生成器（Generators）简介
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
