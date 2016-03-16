# 唤起 App 的实现
使用`a`标签，添加 `href` 跳转链接的方式打开。  
首先定义一个公用方法，传人点击唤起app的a标签对象，等待埋点文件加载完成后，增加唤起app的链接到href属性。如果是三星chrome浏览器使用intent协议打开。其它Android手机和iphone使用scheme协议打开，其中Android手机需要使用iframe 作为承接页，给a标签增加target 属性，值为iframe的name属性。
