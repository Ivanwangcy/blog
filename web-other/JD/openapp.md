# 唤起 App 的实现
使用`a`标签，添加 `href` 跳转链接的方式打开。  
首先定义一个公用方法，传人点击唤起app的a标签对象，等待埋点文件加载完成后，增加唤起app的链接到href属性。如果是三星chrome浏览器使用intent协议打开。其它Android手机和iphone使用scheme协议打开，其中Android手机需要使用iframe 作为承接页，给a标签增加target 属性，值为iframe的name属性。  

打开app是传递的参数需要使用encodeURIComponent进行编码。  
分享链接无法打开app，一般从微信中分享的链接都会带有`from=singlemessage&isappinstalled=0`这样的参数，关键在于from=singlemessage这个参数阻止了唤起app，把它去掉就可以打开app了。isappinstalled参数是用来区分是否为app应用中分享。`0`为微信内部分享，`1`为其它app应用程序中分享出来的链接。
链接格式如下：  
http://xxxxx.xx.com/xxx/xxx.html?from=singlemessage&isappinstalled=0  
http://xxxxx.xx.com/xxx/xxx.html?isappinstalled=0
