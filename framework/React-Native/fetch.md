## Fetch API
```javascript
// 默认 GET 请求
function getDataAsync () {
  return fetch('http://www.xx.com/')
    .then((response) => response.json())
    .then((responseJson) => {
      return responseJson.xx;
    })
    .catch((error) => {
      console.error(error);
    })
}

// POST 请求
fetch('http://localhost:8888/oauth2/token',
{
  method: 'POST',
  headers: {
    'Content-Type': 'application/x-www-form-urlencoded;charset=UTF-8'
  },
  body: qs.stringify({ // 使用 qs
    grant_type: 'password',
    username: 'user_name',
    password: "user_password"
  })
})

// POST 请求
// 自定义 参数转换方法
const searchParams = Object.keys(params).map((key) => {
  return encodeURIComponent(key) + '=' + encodeURIComponent(params[key]);
}).join('&').replace(/%20/g,'+');

fetch(url, {
  method: 'POST',
  headers: {
    'Content-Type': 'application/x-www-form-urlencoded;charset=UTF-8'
  },
  body: searchParams
})
```
 
# #axios
```sh
$ npm i -S axios
```
