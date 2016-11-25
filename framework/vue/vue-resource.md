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
