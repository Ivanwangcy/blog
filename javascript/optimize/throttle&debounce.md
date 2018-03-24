# 节流与防抖

节流与防抖 `throttle & debounce`，是比较常用的函数执行优化，它们可以限制函数的执行频率。比如一些函数触发频率过高导致的响应速度跟不上触发频率，出现延迟，假死或卡顿的现象，就可以用到它们。但是它们二者是有区别的，可以根据不同场景来选择用哪个。下面来逐一介绍它们的用法和特点。（以 `lodash` 的实现为例）

## 节流 throttle

throttle 函数持续执行在一个周期内，控制执行的间隔时间。

## 防抖 debounce

debounce 确保在一定时间内，函数被触发多次后，只执行一次函数。适合用于，频繁点击，输入文字，滚动条等DOM事件或者其它UI交互事件。
当我们是触控板、鼠标滚轮、或者拖动滚动条等操作，可以轻松触发每秒 30 次事件。但是在智能手机上，每秒可触发上百次。
使用 debounce 和不使用的对比图：

![debounce](/Users/ivan/workspace/blog/images/debounce.webp)

### lodash.debounce 函数说明

创建一个防抖的函数，它会延迟执行 `func`，直到 `wait` 指定的时间（毫秒）后才调用 `func`。或者在浏览器的下一帧率被调用(wait 传 0 的情况，chorme 浏览器的 4ms延迟)。debounce 函数还有 `cancel` 的功能，它可以取消 `func` 的延迟调用。可以使用 `flush` 方法立即调用`func`。提供一个 `options` 告诉debounce 是在等待时间前/后调用，默认是在等待时间后被调用。

debounce 函数的 3 个入参和 3 个辅助方法：

* func 延迟调用的函数；
* wait 延迟的时间；
* options 一些选项：
  * leading 是否在延迟时间之前调用；
  * trailing 是否在延迟时间之后调用；
  * maxWait 最大延迟调用时间；
* cancel 取消延迟调用；
* flush 立即调用函数；

```js
_.debounce(func, wait, options)
```