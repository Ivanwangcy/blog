# 掌握 JavaScript 异步编程

## 异步

异步编程是 JavaScript 的核心。如何最大限度地利用 JavaScript 异步性这一特点是我们必须掌握的技能。有了异步可以大大提升 JS 的性能，因此在我们代码中到处都能看到异步的程序，有显式也有隐式的。不过异步

### 事件轮询（Event Loop）

在 ES6 以前 js 本身没有内建的异步概念，js 的异步执行取决于它的宿主环境，所有的宿主环境都有一个共同的机制就是：当每次调用 js 引擎时，可以 `随着时间的推移` 执行你的程序的多个代码块儿，每个代码块儿的执行相当于一个在不停的安排`事件`。不同的代码块儿由宿主环境来进行同步执行或者分配到一个异步事件队列中，按照先进先出的顺序不断的添加和执行，这称为“事件轮询（Event Loop）”。

我们先通过一段代码来形成一个 `事件轮询` 的概念:

```js
// `eventLoop`是一个像队列一样的数组（先进先出）
var eventLoop = [];
var event;

// “永远”执行
while (true) {
  // 执行一个"tick"
  if (eventLoop.length > 0) {
    // 在队列中取得下一个事件
    event = eventLoop.shift();

    // 现在执行下一个事件
    try {
      event();
    } catch (err) {
      reportError(err);
    }
  }
}
```

有一个通过 while 循环来表现的持续不断的循环，这个循环的每一次迭代称为一个 `tick` 。在每一个 `tick` 中，如果队列中有一个事件在等待，它就会被取出执行。这些事件就是你的函数回调。

需要注意的是 `setTimeout(...)`，不会将你的回调放入到事件轮询队列中，它设置了一个定时器，当定时器超时的时候才会放入队列中，在未来的某个 tick 中将被取出执行。即使是 setTimeout(..., 0)也不会立即加入队列，最快也要 4ms 以后。（取决于宿主环境的计时器精确度）

## 回调

在 JavaScript 语言中回调是最基础的异步模式。它的最大好处是给我们提供了一个 [`Callback Hell(回调地域)`](http://callbackhell.com/)，然后才有了 Promise 和 Async/Await。

一般回调函数都是延迟执行，回调执行时机由第三方控制：

```js
// A
ajax( "..", function(..){
	// C
} );
// B
```

或者是自己控制，固定的写法：

```js
// A
setTimeout(function() {
  // C
}, 1000);
// B
```

如果多层嵌套就容易造成混乱。为了避免这种混乱可以采用一种分离回调设计：

```js
function success(data) {
  console.log(data);
}

function failure(err) {
  console.error(err);
}

ajax("http://some.url.1", success, failure);
```

ES6 的 Promise 的 API 使用的就是这种分离回调设计。

NodeJS 提供了另一种回调设计模式是“错误优先风格” —— nodejs 的 `error-first callback style`。
