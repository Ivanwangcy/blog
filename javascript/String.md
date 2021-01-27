# String 类型

## 字符串遍历

```js
// 字符串可以使用 `for of` 遍历
for (let char of str) {
    console.log(char.charCode());
}
```

检验一个字符的 code 码，如果是非英文，汉字之类的作为 2 个字符

```js
// 字数统计
function wordCount(str) {
    var len = 0;
    for (let char of str) {
        if (char.charCodeAt() > 127) {
            len += 2;
        } else {
            len++;
        }
    }
    return len;
}
```

## ASCII 码

- 大写字母 A-Z 对应的 ASCII 码值是 65-90
- 小写字母 a-z 对应的 ASCII 码值是 97-122

```ts
// 将字母转为 ASCII 码

let str1: string = "A"
str.charCodeAt() // 65

let str2: string = "a";
str2.charCodeAt(); // 97

// 将 ASCII 码转为对应字母
let num1: number = 97;
String.fromCharCode(num1) // 'a'

let num2: number = 100;
String.fromCharCode(num2) // 'd'
```
