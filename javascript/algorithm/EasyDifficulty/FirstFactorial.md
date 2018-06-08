# Factorial 阶乘

Have the function FirstFactorial(num) take the num parameter being passed and return the factorial of it (e.g. if num = 4, return (`4 * 3 * 2 * 1`)). For the test cases, the range will be between 1 and 18 and the input will always be an integer.

使函数FirstFactorial（num）取得传递的num参数并返回它的阶乘（例如，如果num = 4，则返回（`4 * 3 * 2 * 1`））。对于测试用例，范围在1到18之间，输入始终为整数。

```js
function FirstFactorial(num) {

  // code goes here  
  function factorial(num){
      if (num === 0 || num === 1) return 1;

      return num * factorial(num - 1)
  }

  return factorial(num);
}

// keep this function call here
FirstFactorial(10);

```

## 标准解决方案一

In the code below, we create a new variable called factorial which we will use to store our temporary values as we loop. In our loop, we start at 1 and increment until we reach our variable num.

在下面的代码中，我们创建了一个名为factorial的新变量，我们将循环使用它来存储临时值。在我们的循环中，我们从1开始，直到达到变量 num。

```js
function FirstFactorial(num) {

  var factorial = 1;

  for (var i = 1; i <= num; i++) {  
    // multiply each number between 1 and num  
    // factorial = 1 * 1 = 1
    // factorial = 1 * 2 = 2
    // factorial = 2 * 3 = 6
    // factorial = 6 * 4 = 24
    // ...
    factorial = factorial * i;
  }

  return factorial;
}

FirstFactorial(4);
```

## 标准解决方案二

It is also possible to create a recursive function to calculate the factorial. A recursive function calls itself some number of times until it reaches a condition that terminates the function calls. A factorial function can be represented by the following recursive terms:

```js
1! = 1
2! = 1! * 2
3! = 2! * 3
4! = 3! * 4
5! = 4! * 5
...
```

We can see that each factorial relies on the previous factorial, and then it multiplies that number by the current number. We'll convert these recursive terms into the following function:

```js
function FirstFactorial(num) {

  // our factorial function
  function factorial(n) {

    // terminate the recursion once we hit zero
    if (n===0) { return 1; }

    // otherwise keep calling the function recursively
    else { return factorial(n-1) * n; }

  }

  return factorial(num);
}

FirstFactorial(4);
```