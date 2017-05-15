## Fetch API
```javascript
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
```
