# 微信小程序转 Taro

参考文档：https://taro-docs.jd.com/taro/docs/taroize.html


## 注意事项

小程序代码不够规范会导致转换后无法运行

* 相对路径需要加 './'，如果不加转换后就会在 node_modules 中找且找不到报错；
* 小程序代码中重复导入一个文件1次以上，转换后会报错；
* 如果是带表达式的事件监听需要手动修改函数，如下:（因此写原生小程序时要避免这样写）
```js

// 原生写法
catch:tap="{{flag ? 'handleTap' : ''}}"

// Taro Convert 
onTap={flag ? 'handleTap' : ''} 

// to 手动修改后
onTap={flag ? this.handleTap : ''}
```
