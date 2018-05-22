# Promise 异步编程

```js
function myAsyncFunction(url) {
  return new Promise((resolve, reject) => {
    const xhr = new XMLHttpRequest();
    xhr.open("GET", url);
    xhr.onload = () => resolve(xhr.responseText);
    xhr.onerror = () => reject(xhr.statusText);
    xhr.send();
  })
    .then(successMessage => {
      // successMessage is whatever we passed in the resolve(...) function above.
      // It doesn't have to be a string, but if it is only a succeed message, it probably will be.
      console.log("Yay! ", successMessage);
    })
    .catch(error => {
      console.log(error);
    });
}
```

## 对比 $.Deferred()

* 更加清晰易懂
* 内置对象性能更好
