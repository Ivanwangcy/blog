# Solutions for Longest Word

统计出一段英文中最长的单词解决方案：

```js


function LongestWord(sen) {
  // code goes here
  var arr = sen.match(/[a-z0-9]+/gi)
  
  return arr.sort(function(curr, next){
      return next.length - curr.length
  })[0];
}

// keep this function call here
LongestWord('this is some sort of sentence');
// output: "sentence"


// 参考：标准解决方案
function LongestWord(sen) {

  // we use the regex match function which searches the string for the
  // pattern and returns an array of strings it finds
  // in our case the pattern we define below returns words with
  // only the characters a through z and 0 through 9, stripping away punctuation
  // e.g. "hello$% ##all" becomes [hello, all]
  var arr = sen.match(/[a-z0-9]+/gi);

  // the array sort function takes a function as a parameter
  // which is used to compare each element in the array to the
  // next element in the array
  var sorted = arr.sort(function(a, b) {
    return b.length - a.length;
  });

  // this array now contains all the words in the original
  // string but in order from longest to shortest length
  // so we simply return the first element
  return sorted[0];
}

LongestWord("the $$$longest# word is coderbyte");
```