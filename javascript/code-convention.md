# 代码规范(code convention)或者叫编程风格(style guideline)

## 编写可维护的 javascript

-   代码规范 code convention，编程风格 styly guideline
-   检查编程风格的工具，JSInt ,JSHint
-   格式化规则 formatting rule
-   变量提升: 在函数内部首先声明所有变量
-   缩进层级
    -   推荐使用 2 个空格进行一个缩进层级
    -   数组和对象使用尾逗号形式比较好扩展；
    -   行的长度规定在 80 个字符
    -   超出长度时换行，在运算符后面换行，第二行追加两个缩进层级
    -   赋值时，值保持左对齐
    -   不同语义的代码用空行分隔
-   驼峰式命名法
    -   变量以名词为前缀
    -   函数以动词为前缀
    -   不要害怕在命名上多花费时间
    -   命名尽可能短，突出重点
    -   构造函数用大驼峰式，名词命名
-   所有的块语句都应当使用花括号
-   左花括号放在语句末尾
-   禁止使用 with 语句
-   即便未初始化的变量会自动被赋予 undefined 值，但显式地初始化变量依然是明智的选择。如果能够做到这一点，那么当 typeof 操作符返回"undefined"值时，我们就知道被检测的变量还没有被声明，而不是尚未初始化。
-   多数情况下，我们要解析的都是十进制数值，因此始终将 10 作为第二个参数是非常必要的。

## 关键字

-   ES6
-   promise
-   angularjs
-   reactjs
-   webpack
-   JSHint
-   MEAN Stack 全栈
-   Bootstrap UI 组件库
-   hightchars js 图表库
-   gulp javascript 构建工具
-   less sass css 预处理器
-   postcss rework css 后处理器
-   自动化
-   mailling list
-   Nginx
-   redis
-   —just build something！
-   PERL：percentage of easily replaced labors(劳动者可被轻易取代率) 缩写
-   全民教育

## 注意

```javascript
typeof x == "object" && x !== null && alert("x是一个对象");
```

这个例子中,整个表达式的值完全没有被用到,表达式作为了一个单独的语句,目的就是为了有条件的执行最右边的函数.如果这么写的话,你应该使用更常规的写法,以提高可读性和可维护性:

```javascript
if (typeof x == "object" && x !== null) {
    alert("x是一个对象");
}
```
