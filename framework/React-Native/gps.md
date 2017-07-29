## 定位系统
```js
navigator.geolocation.getCurrentPosition(
 (position) => {
   alert(JSON.stringify(position));
   console.log(position);
   this.setState({position})
 },
 (error) => console.error(error)
);
```
