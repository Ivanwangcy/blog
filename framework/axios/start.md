# axios 

## request 

## interceptor 拦截器
```
// Add a response interceptor
axios.interceptors.response.use(function (response) {
  // Do something with response data
  let code = response.data.code
  if (response.data.code === '-10') {
    router.push('/login')
  } else if (code !== '0') {
    Toast({
      message: response.data.msg || '出错了'
    })
  }
  return response
})
```
## Post 请求 需要引用 qs.stringify()

```js

import qs from 'qs';

         axios({
                method: type || 'GET',
                url: `${apiPath}?_jdrandom=` + new Date().getTime(),
                params: type == 'POST' ? undefined : params,
                data: qs.stringify(params),
                timeout: params.timeout || 9999,
                cancelToken: cancelTokenSource.token
            })
                .then(res => {
                    key && state.setItem(key, res.resp);
                    resolve(res || {});
                })
                .catch(error => {
                    error = error || {};
                    reject(error || {});
                });

```
