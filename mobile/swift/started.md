# Swift 入门
```javascript
//: Playground - noun: a place where people can play

import UIKit

var str = "Hello, playground"

print(str);

let arr = [1,2,3];
print(arr);

print(5*6);
print(5%6);

/*循环 5-9 包含9 */
for num in 5...9{
    print(num)
}

/*循环 5-9 不包含9 */
for num in 5..<9{
    print(num)
}

var fruits = ["apple", "banana", "orange"]

for n in 0..<fruits.count{
    print(fruits[n])
}

let age = 131

if age > 130 || age < 1 {
  print("Age is out of range")
}

let str1 = "Hello"
// var str1 = "Hello"
// error let 声明 是不可变的，可变的使用 var
str1 += " World"

print(str1)

func doSomething(){
    print("doSomething")
}

doSomething()

func getString() -> String{
    return "Hi"
}
print(getString())

```
