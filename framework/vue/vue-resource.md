## Vue Resource

This will send request data as application/x-www-form-urlencoded content type.
```javascript
this.$http.post('/api', data, {
   emulateJSON: true
})
```
Or use FormData

var formData = new FormData();
formData.append('foo', 'bar');
```javascript
this.$http.post('/api', formData)
```
## vue resource 全局设置
```javascript
import VueResource from 'vue-resource'

Vue.use(VueResource)

store.commit('LOADING', true)
Vue.http.interceptors.push((request, next) => {
  // 请求前的处理逻辑

  next((response) => {

    return response
  })
})
```
## get 请求
入参要写到 params 中，或者拼字符串的方式
```javascript
var params = {phone: this.mobile}
this.$http.get('/uri', {params: params})

// or 字符串拼参数，复杂参数 需要 encodeURI
this.$http.get('/uri?phone=' + this.mobile)

// or ES6 字符串插值
this.$http.get(`/uri?phone=${this.mobile}`)
.then((response) => {
  try {
    console.log(response.data.);
  } catch (e) { }
}, (error) => {
  console.log(error);
})
```
## post 请求
参数直接放到第二位入参即可
```javascript
var params = {phone: this.mobile}
this.$http.post('/uri', params)
.then((response) => {
  try {
    console.log(response.data);
  } catch (e) { }
}, (error) => {
  console.log(error);
})
```
