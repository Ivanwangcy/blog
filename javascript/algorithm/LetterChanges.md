# Letter Changes

Using the JavaScript language, have the function LetterChanges(str) take the str parameter being passed and modify it using the following algorithm. Replace every letter in the string with the letter following it in the alphabet (ie. c becomes d, z becomes a). Then capitalize every vowel in this new string (a, e, i, o, u) and finally return this modified string.

```js
function LetterChanges(str) {
  var upperStr = str
    .replace(/[a-z]/gi, function(char) {
      return char === "z" || char === "Z"
        ? "a"
        : String.fromCharCode(char.charCodeAt() + 1);
    })
    .replace(/a|e|i|o|u/gi, function(char) {
      return char.toUpperCase();
    });

  return upperStr;
}
```

解决方案：
This challenge requires you to change every letter in the string to the letter following it in the alphabet, so a becomes b, z becomes a, etc. Once every letter is changed, we then need to capitalize only the vowels, namely: a, e, i, o, u.

We will be changing the letters by using their respective ASCII values and adding 1 to them in order to get the next letter in the alphabet. ASCII values are just numbers that are assigned to each character in a sequential order, for example, the ASCII code for the letter a is 97 and b is 98. What we'll do is convert a letter to its ASCII number, add 1 to it, then convert this new number back into a character using a built-in character function.
