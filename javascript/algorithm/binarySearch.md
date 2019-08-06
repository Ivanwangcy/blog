# 二分查找实现方式

```js
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
