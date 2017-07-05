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
