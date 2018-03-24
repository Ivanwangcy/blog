# 节流与防抖

节流与防抖 `throttle & debounce`，是比较常用的函数执行优化，它们可以限制函数的执行频率。比如一些函数触发频率过高导致的响应速度跟不上触发频率，出现延迟，假死或卡顿的现象，就可以用到它们。但是它们二者是有区别的，可以根据不同场景来选择用哪个。下面来逐一介绍它们的用法和特点。

## 防抖 debounce

函数防抖就是让某个函数在上一次执行后，满足等待某个时间内不再触发此函数后再执行，而在这个等待时间内再次触发此函数，等待时间会重新计算。debounce 确保在一定时间内，函数被触发多次后，只执行一次。适合用于，频繁点击，输入文字，DOM事件或者其它UI交互事件。

使用 debounce 和不使用的对比图：

![debounce](/images/debounce.webp)

### debounce 的基本实现

```js
var debounce = function (func, threshold, execAsap) {
  var timeout;
  return function debounced () {
    var obj = this, args = arguments;
    function delayed () {
        if (!execAsap)
            func.apply(obj, args);
        timeout = null;
    };

    if (timeout)
        clearTimeout(timeout);
    else if (execAsap)
        func.apply(obj, args);

    timeout = setTimeout(delayed, threshold || 100);
  };
}
```

### lodash.debounce 函数说明

[lodash 的实现](https://github.com/lodash/lodash/blob/master/debounce.js)使用了的函数式编程，并增加了一些扩展。

```js
_.debounce(func, wait, options)

```

创建一个防抖的函数，它会延迟执行 `func`，直到 `wait` 指定的时间（毫秒）后才调用 `func`。或者在浏览器的下一帧率被调用(不传的情况下使用 requestAnimationFrame, 16ms 执行一次)。或者是 wait 传 0 的情况，相对于，setTimeout(func, 0)，chorme 浏览器有 4ms延迟。debounce 函数还有 `cancel` 的功能，它可以取消 `func` 的延迟调用。可以使用 `flush` 方法立即调用`func`。提供一个 `options` 告诉debounce 是在等待时间前/后调用，默认是在等待时间后被调用。

debounce 函数的 3 个入参和 3 个辅助方法：

* func 延迟调用的函数；
* wait 延迟的时间，可不传会使用 RAF；
* options 一些选项：
  * leading 是否在延迟时间之前调用；
  * trailing 是否在延迟时间之后调用；
  * maxWait 最大延迟调用时间；
* cancel 取消延迟调用；
* flush 立即调用函数；

使用示例：

```js
jQuery(element).on('click', debounce(handleClick, 300, {
  'leading': true,
  'trailing': false
}))

// 使用debounce 函数注意 this 指向问题：
let handleClick = debounce(() => {
  this.id
  // ...

}, 300, { 'leading': true, 'trailing': false })

<div onClick={handleClick.bind(this)}></div>

// or
<div onClick={debounce(this.handleClick, 500).bind(this)}></div>
```

它把具体实现分解成一个个函数来执行：

```js
function debounce() {
  // ...

  // 主函数如下，隐藏了实现细节
  function debounced(...args) {
    // ...

    const isInvoking = shouldInvoke(time) // 是否应该调用函数

    if (isInvoking) {
      if (timerId === undefined) {
        return leadingEdge(lastCallTime) // 延迟计算之前调用函数
      }
      if (maxing) {
        // Handle invocations in a tight loop.
        timerId = startTimer(timerExpired, wait)
        return invokeFunc(lastCallTime) // 延迟计算结束后调用函数
      }
    }

    if (timerId === undefined) {
      timerId = startTimer(timerExpired, wait) // 重新开启一个延迟计算
    }
    return result
  }

  debounced.cancel = cancel
  debounced.flush = flush
  debounced.pending = pending

  return debounced
}
```

## 节流 throttle

throttle 函数持续执行在一个周期内，控制执行的间隔时间。每间隔某个时间去执行某函数，避免函数的过多执行，这个方式就叫函数节流。当我们是触控板、鼠标滚轮、或者拖动滚动条等操作，可以轻松触发每秒 30 次事件。但是在智能手机上，每秒可触发上百次。可以使用 `throttle` 来限制每秒触发的次数。

### throttle 的实现

在 lodash 中 debounce 已经实现的防抖和节流的功能。

```js
function throttle(func, wait, options) {
  // 一些参数校验
  // ...

  return debounce(func, wait, {
    'leading': leading,
    'maxWait': wait,
    'trailing': trailing
  });
}
```

## 项目中应用 debounce and throttle

```sh
npm i -S lodash
```

```js
// 全部导入
import _ from 'lodash'

// 解构导入
import {
  throttle,
  debounce
} from 'lodash';

// 或者单个导入
import throttle from 'lodash/throttle'

import debounce from 'lodash/debounce'

```

> 参考链接：[通过示例理解防抖和节流](https://css-tricks.com/debouncing-throttling-explained-examples/)