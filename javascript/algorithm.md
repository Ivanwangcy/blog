## 算法示例

## 二分顺序查找实现

函数 search 实现在一个已排序的数字类型数组中查找指定数字的功能。
search 函数语法为
var idx = search(arr, dst);
使用举例如下：
var arr = [1, 2, 4, 6, 7, 9, 19,20, 30, 40, 45, 47]；
var idx = search(arr, 45)； // 执行后 idx 值等于 10
请给出函数 search 的代码实现，要求不能使用 Array 的原型方法，且算法时间复杂度低于 O(n)。

## 使用二分查找

复杂度 = O(logn)

```javascript
// 有序的数组，查找对应的值
function search(arr, dst) {
  // 如果小于首位/大于末位数，就直接返回 -1 无法匹配
  if (dst < arr[0] || dst > arr[arr.length - 1]) return -1;
  var idx = -1, // 默认值为 -1 如果找不到
    left = 0, 
    right = arr.length;
  while (left <= right) {
    var center = Math.floor((left + right) / 2);
    console.log(arr[center] + ":" + center);
    if (dst == arr[center]) {
      idx = center;
      break;
    }
    dst < arr[center] ? (right = center - 1) : (left = center + 1);
  }
  return idx;
}

function search2(arr, dst) {
  var index = -1;
  var left = 0;
  var right = arr.length - 1;

  if (dst < arr[0] || dst > arr[right]) return index;

  while (left <= right) {
    var center = (left + right) >> 1;
    console.log(arr[center] + ":" + center);
    if (dst === arr[center]) {
      index = center;
      break;
    }

    dst < arr[center] ? (right = center - 1) : (left = center + 1);
  }

  return index;
}

// 优化的简单写法
var binarySearch=(arr, item)=> {
    var low = 0;
    var high = arr.length - 1;
    while(low <= high){
	var mid = (low + high) >> 1;
	var guess = arr[mid];
	if(guess == item) return mid;
	guess > item ? high = mid -1 : low = mid + 1;
  }
  return -1;	
}

var arr = [1, 2, 4, 6, 7, 9, 19, 20, 30, 40, 45, 47, 50, 55, 60, 70];
var idx = search(arr, 100);
```

## 随机打乱字符串

```javascript
function randomStr(str) {
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
function shuffle(arr) {
  var length = arr.length,
    shuffleArr = []; // 或者使用 Array(length)
  for (var i = 0, rand; i < length; i++) {
    rand = Math.floor(Math.random() * i);
    if (rand !== i) shuffleArr[i] = shuffleArr[rand];
    shuffleArr[rand] = arr[i];
    console.log(rand, shuffleArr);
  }
  return shuffleArr;
}
var newArr = shuffle([1, 2, 3, 4, 5, 6, 7, 8]);
```

## 1+2+3+4+ ... + n 求 1-n 的和

```javascript
// 方法一
function sum(num) {
  if (num == 0) {
    return 0;
  }
  // return num + sum(num - 1);
  // 方法二, 还可以用 arguments.callee
  return num + arguments.callee(num - 1);
}

// 第二种方法命名函数表达式
var sum = function f(num) {
  if (num == 0) {
    return 0;
  }

  return num + f(num - 1);
};
console.log(sum(100));

// 方法三 使用命名函数表达式来实现递归 -- 推荐
var sum = function f(num) {
  if (num == 0) {
    return 0;
  }
  return num + f(num - 1); // 第一种方法, 还可以用 arguments.callee
};
console.log(sum(100));

// 不使用递归
// 第四种 使用数组
var sum3 = function(num) {
  var arr = new Array(num + 1);
  return arr
    .join(",")
    .split(",")
    .reduce(function(total, item, index) {
      return Number(total) + index;
    });
};

console.log(sum3(3));

// 使用 循环
function sum4(num) {
  if (num === 0 || num === 1) {
    return num;
  } else {
    var curr = num;
    var total = 0;
    while (curr--) {
      total += curr;
    }
    return total + num;
  }
}

console.log(sum4(100));
```

## 数字加千分符(23123456.78 -> 23,123,456.78)

```javascript
// 方法1：利用数组反转
function operatorReverse(num) {
  if (!num) return;
  num = num.toString();
  var numArr = num.split(".");
  var reverseWholeNum = numArr[0]
    .split("")
    .reverse()
    .join("");
  var formatReverseWholeNum = reverseWholeNum.replace(/(\d{3})/gi, "$1,");
  if (formatReverseWholeNum.endsWith(",")) {
    formatReverseWholeNum = formatReverseWholeNum.slice(0, -1);
  }
  var formatNum =
    formatReverseWholeNum
      .split("")
      .reverse()
      .join("") + (numArr[1] ? "." + numArr[1] : "");
  console.log(formatNum);
}
operatorReverse("123346346454567");

// 方法2：遍历字符
function operatorChar(num) {
  if (!num) return;
  num = num.toString();
  var numArr = num.split("."); //
  var wholeNum = numArr[0];
  var formatWholeNum = "";
  var frontCount = wholeNum.length % 3;
  var formatNum = "";
  console.log(frontCount);
  for (var i = 0; i < wholeNum.length; i++) {
    formatWholeNum += wholeNum.charAt(i);
    if (frontCount == 0 && i % 3 == 2 && i != wholeNum.length - 1) {
      formatWholeNum += ",";
    } else if (
      frontCount != 0 &&
      (i == frontCount - 1 ||
        ((i + (3 - frontCount)) % 3 == 2 && i != wholeNum.length - 1))
    ) {
      formatWholeNum += ",";
    }
  }
  if (numArr[1]) {
    formatNum = formatWholeNum + "." + numArr[1];
  } else {
    formatNum = formatWholeNum;
  }
  console.log(formatNum);
}
operatorChar("12345678.12333");

// 方法3
var test1 = "1234567890";
var format = test1.replace(/\B(?=(\d{3})+(?!\d))/g, ",");
console.log(format);
// 1,234,567,890
```

## 大数相加

超过 14 位的数字相加会出现精度损失，解决方案参考：

```js
const add2 = (x, y) => {
  x = "" + x;
  y = "" + y;

  if (/\D/.test(x + y)) {
    return NaN;
  }

  let output = "";
  let carry = "";
  let zero = "0000000000000000000000";

  const split = str => (zero + str).split(/(?=\d{14}$)/);
  const remove_left_zero = str => ("" + str).replace(/^0+/, "");

  while (x.length > 0 || y.length > 0 || carry.length > 0) {
    let tx = split(x);
    let ty = split(y);
    let ta = split(
      parseInt(tx[1] || 0, 10) +
        parseInt(ty[1] || 0, 10) +
        parseInt(carry || 0, 10)
    );
    output = ta[1] + output;
    carry = ta[0];
    x = remove_left_zero(tx[0]);
    y = remove_left_zero(ty[0]);
    carry = remove_left_zero(carry);
  }

  return remove_left_zero(output);
};
```
