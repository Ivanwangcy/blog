# Simple Adding

Have the function SimpleAdding(num) add up all the numbers from 1 to num. For example: if the input is 4 then your program should return 10 because 1 + 2 + 3 + 4 = 10. For the test cases, the parameter num will be any number from 1 to 1000.

让函数 SimpleAdding（num）将从 1 到 num 的所有数字相加。例如：如果输入是 4，那么你的程序应该返回 10，因为 1 + 2 + 3 + 4 = 10。对于测试用例，参数 num 将是从 1 到 1000 的任何数字。

```js
function SimpleAdding(num) {
  // code goes here
  var arr = new Array(num + 1);
  return arr
    .join(",")
    .split(",")
    .reduce(function(total, item, index) {
      return Number(total) + index;
    });
}

// keep this function call here
SimpleAdding(readline());
```
## 标准方案一
This challenge requires you to add up all the numbers from 1 to a given argument. For example, if the parameter num is 4, your program should add up 1 + 2 + 3 + 4 and return 10. This will be pretty simple to write out as a loop. We'll maintain a variable and keep adding to it as we loop from 1 to num.

```js
function SimpleAdding(num) {
  var answer = 0;

  // loop from 1 to num
  for (var i = 1; i <= num; i++) {
    answer = answer + i;
  }

  return answer;
}

SimpleAdding(4);
```
## 方案二

There is also a very clever way to calculate the sum of the numbers 1 + 2 + 3 + .... The sum of the first N natural numbers is equal to n(n+1)/2 (see [proof](https://en.wikipedia.org/wiki/1_%2B_2_%2B_3_%2B_4_%2B_%E2%8B%AF) and why this is so).

```js
function SimpleAdding(num) {
  return (num * (num + 1)) / 2;
}

SimpleAdding(4);
```
