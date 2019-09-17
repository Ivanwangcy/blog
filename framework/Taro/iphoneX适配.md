# 判断是否为iPhone X

```js
    Taro.getSystemInfo({
      success: (res)=> {
        console.log(res.model)
        let isIPX = res.model.indexOf('iPhone X') >= 0 ? true : false;//判断是否为iPhone X
        wx.setStorageSync("isIPX", isIPX);
      }
    })
```

底部的 空白区域 为 `68rpx`

## 其它相关 API
```js
// 同步存储 API
import Taro from '@tarojs/taro'

Taro.setStorageSync('key', 'value')

import Taro from '@tarojs/taro'

const data = Taro.getStorageSync('key')

import Taro from '@tarojs/taro'

// 获取系统信息同步接口。
const res = Taro.getSystemInfoSync()
console.log(res.model)
console.log(res.pixelRatio)
console.log(res.windowWidth)
console.log(res.windowHeight)
console.log(res.language)
console.log(res.version)
console.log(res.platform)

```
