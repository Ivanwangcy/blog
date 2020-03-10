# 微信小程序转换Taro

```sh
taro convert
```

## 小程序多端适配文件

文件示例：

```js
index.weapp.js
index.swan.js
index.jd.js
index.tt.js
index.h5.js
```

## 小程序多端适配

```js
if(process.env.TARO_ENV === 'weapp'){

}
if(process.env.TARO_ENV === 'swan'){

}
if(process.env.TARO_ENV === 'tt'){

}
if(process.env.TARO_ENV === 'jd'){

}
if(process.env.TARO_ENV === 'h5'){

}
```
