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
