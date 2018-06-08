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

  var newString = "";

  // add each character to newString
  for (var i = str.length - 1; i >= 0; i--) {
    newString = newString + str.charAt(i);
  }

  return newString;
}

FirstReverse(readline());

// 方案 二
function FirstReverse(str) {

  // first we split the string which creates an array of characters, e.g. ['c','a','t']
  // then we call the reverse function on this array
  // and finally we turn the reversed array back into a string using the join function
  return str.split('').reverse().join('');
}

FirstReverse(readline());
```