# 二分顺序查找实现

函数search实现在一个已排序的数字类型数组中查找指定数字的功能。
search函数语法为
var idx = search(arr, dst);
使用举例如下：
var arr = [1, 2, 4, 6, 7, 9, 19,20, 30, 40, 45, 47]；
var idx = search(arr, 45)； // 执行后idx值等于10
请给出函数search的代码实现，要求不能使用Array的原型方法，且算法时间复杂度低于O(n)。


## 使用二分查找
```javascript
function search(arr,dst){
  if(dst < arr[0] || dst > arr[arr.length - 1])return -1;
  var idx = -1,
      left = 0,
      right = arr.length;
  while (left <= right) {
    var center = Math.floor((left + right) / 2);
    console.log(arr[center] + ":" + center);
    if(dst == arr[center]){
      idx = center;
      break;
    }
    dst < arr[center] ? right = center - 1 : left = center + 1;
  }
  return idx;
}
var arr = [1, 2, 4, 6, 7, 9, 19,20, 30, 40, 45, 47 , 50, 55, 60, 70];
var idx = search(arr, 100);
```
## 随机打乱字符串
```javascript
  function randomStr(str){
    var arr = str.split(""),
      newStr = "",
      len = arr.length,
      index;
    while (len > 0) {
      var index = Math.floor(Math.random() * len);
      newStr += arr.splice(index, 1);
      len--;
    }
    alert(newStr);
  }

  randomStr("Hello World!");
```
## 随机打乱数组
```javascript
function shuffle(arr){
  var length = arr.length,
    shuffleArr = []; // 或者使用 Array(length)
    for(var i = 0, rand; i < length; i ++){
      rand = Math.floor(Math.random() * i);
      if(rand !== i) shuffleArr[i] = shuffleArr[rand];
      shuffleArr[rand] = arr[i];
      console.log(rand, shuffleArr);
    }
    return shuffleArr;
}
var newArr = shuffle([1,2,3,4,5,6,7,8]);
```
## 1+2+3+4+ ... + n 求1-n的和
```javascript
  // 方法一
  function sum(num){
    if(num == 0){
      return 0;
    }
    // return num + sum(num - 1);
    // 方法二, 还可以用 arguments.callee
    return num + arguments.callee(num - 1);
  }

  // 方法三 使用命名函数表达式来实现递归 -- 推荐
  var sum = (function f(num){
    if(num == 0){
      return 0;
    }
    return num + f(num - 1); // 第一种方法, 还可以用 arguments.callee
  });
  console.log(sum(100));

// 第二种方法命名函数表达式
  var sum = (function f(num){
    if(num == 0){
      return 0;
    }

    return num + f(num - 1);
  });
  console.log(sum(100));
```
## 数字加千分符(23123456.78 -> 23,123,456.78)
```javascript
// 方法1：利用数组反转
function operatorReverse(num){
  if(!num) return;
  num = num.toString();
  var numArr = num.split('.');
  var reverseWholeNum = numArr[0].split("").reverse().join("");
  var formatReverseWholeNum = reverseWholeNum.replace(/(\d{3})/gi, "$1,");
  if(formatReverseWholeNum.endsWith(",")){
    formatReverseWholeNum = formatReverseWholeNum.slice(0,-1);
  }
  var formatNum = formatReverseWholeNum.split("").reverse().join("") + (numArr[1] ? "." + numArr[1] : "");
  console.log(formatNum);
}
operatorReverse('123346346454567');

// 方法2：遍历字符
function operatorChar(num){
  if(!num) return;
  num = num.toString();
  var numArr = num.split('.'); //
  var wholeNum = numArr[0];
  var formatWholeNum = "";
  var frontCount = wholeNum.length%3;
  var formatNum = "";
  console.log(frontCount);
  for(var i = 0; i < wholeNum.length; i++){
    formatWholeNum += wholeNum.charAt(i);
    if(frontCount == 0 &&
      i%3 == 2 &&
      i != wholeNum.length -1){
      formatWholeNum += ",";
    }
    else if(frontCount != 0 &&
        (i == frontCount - 1 ||
          (i + (3-frontCount))%3 == 2 &&
          i != wholeNum.length - 1)){
      formatWholeNum += ",";
    }
  }
  if(numArr[1]){
    formatNum = formatWholeNum + "." + numArr[1];
  }else {
    formatNum = formatWholeNum;
  }
  console.log(formatNum);
}
operatorChar('12345678.12333');

```
# #
