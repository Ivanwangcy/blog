# Results for First Reverse

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