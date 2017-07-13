# Ajax 核心API

## ajax 跨域请求
用jquery ajax的jsonp方式去跨域提交数据时，如果数据量太大的话会出现400 bad request。因为jsonp的跨域形式是通过url传参，而url传参又有一定数量的限制，所以造成这样的难题。  
即使把ajax的type申明为post也不管用，在网上找了很多资料，目前我能想到的就是用iframe方式提交，但这样略麻烦。  
使用jsonp, 但是不能使用post, 数据量也比较小， 大数据可以使用 `iframe` 的解决办法。  
ajax处于安全考虑是有同域的限制，你是否有另外一个域的控制权，如果有的话，那在那个域下面放置一个crossdomian.xml文件就能解决你所遇到的问题。
```xml
<?xml version="1.0"?>

<cross-domain-policy>

<allow-access-from domain="*" />

</cross-domain-policy>
```
创建一个XML文件复制上面的代码即可。如果看不到代码请使用搜索引擎搜索crossdomain.xml
 
 ## XMLHttpRequest
 ```js
     // 处理JSON Data
    var encodeFormData = function(data) {
      if (!data) return ""; // Always return a string
      var pairs = []; // To hold name=value pairs

      for(var name in data) { // For each name

        if (!data.hasOwnProperty(name)) continue; // Skip inherited
        if (typeof data[name] === "function") continue; // Skip methods
        var value = data[name];
        // value==undefined同时包含了undefined和null的判断
        value = ( (value==undefined) ?'':value).toString(); // Value as string
        name = encodeURIComponent(name.replace(" ", "+")); // Encode name
        value = encodeURIComponent(value.replace(" ", "+")); // Encode value
        pairs.push(name + "=" + value); // Remember name=value pair
      }

      return pairs.join('&'); // Return joined pairs separated with &
    }
    
      var request = new XMLHttpRequest();
      request.open("POST", document.location.protocol + "//log-o2o.jd.com/v1/logging");
      request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
      request.send(encodeFormData({key: '',key2: '', key3: '',}));
 ```
