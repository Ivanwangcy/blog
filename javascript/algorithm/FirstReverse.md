# Results for First Reverse
Have the function FirstReverse(str) take the str parameter being passed and return the string in reversed order. For example: if the input string is "Hello World and Coders" then your program should return the string sredoC dna dlroW olleH.
中文(简体)
让函数 FirstReverse（str）取得传递的str参数，并以相反的顺序返回字符串。例如：如果输入字符串是“Hello World and Coders”，那么你的程序应该返回字符串 sredoC dnaroLW olleH。

```js
function FirstReverse(str) {

  // code goes here  
  return str.split('').reverse().join('');
}

// keep this function call here
FirstReverse(readline());



// 标准解决方案
function FirstReverse(str) {

  var arr = str.split('');
  arr.reverse();
  return arr.join('');
}

// keep this function call here
// to see how to enter arguments in JavaScript scroll down
FirstReverse(readline());
```