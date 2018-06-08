# Letter Capitalize

Using the JavaScript language, have the function LetterCapitalize(str) take the str parameter being passed and capitalize the first letter of each word. Words will be separated by only one space.

## Sample Test Cases

```js
Input:"hello world"

Output:"Hello World"


Input:"i ran there"

Output:"I Ran There"
```

```js
function LetterCapitalize(str) {

  // code goes here  
  return str.replace(/\b[a-z]/gi, function(char){
      return char.toUpperCase()
  });
}

// keep this function call here
LetterCapitalize(readline());
```