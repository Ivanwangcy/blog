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


// 标准答案解决方案
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