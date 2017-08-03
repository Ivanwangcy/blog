## 定位系统
```js
navigator.geolocation.getCurrentPosition(
 (position) => {
   alert(JSON.stringify(position));
   console.log(position);
   this.setState({position})
 },
 (error) => console.error(error),
 {enableHighAccuracy: true, timeout: 20000, maximumAge: 1000}
);
```
