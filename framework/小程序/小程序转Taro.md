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

## 目录结构

```js
├── dist                                编译结果目录
|   ├── weapp                           微信平台编译目录
|   ├── swan                            百度平台编译目录
|   ├── jd                              京东平台编译目录
|   ├── ...                             其它平台编译目录
├── config                              配置目录
|   ├── dev.js                          开发时配置
|   ├── index.js                        默认配置
|   └── prod.js                         打包时配置
├── src                                 源码目录
|   ├── assets                          公共资源目录（内含图标等资源）
|   ├── components                      公共组件目录
|   |   └── Btn                         公共组件 Btn 目录
|   |       ├── Btn.tsx                 公共组件 Btn 逻辑
|   |       └── Btn.scss                公共组件 Btn 样式
|   ├── pages                           页面文件目录
|   |   └── index                       index 页面目录
|   |       ├── components              index 页面的独有组件目录
|   |       |   └── Banner              index 页面的 Banner 组件目录
|   |       |       ├── Banner.tsx      index 页面的 Banner 组件逻辑
|   |       |       └── Banner.scss     index 页面的 Banner 组件样式
|   |       ├── index.js                index 页面逻辑
|   |       └── index.scss              index 页面样式
|   ├── subpackages                     分包目录（项目过大时建议分包）
|   |   └── profile                     一个叫 profile 的分包目录
|   |       └── pages                   该分包的页面文件目录
|   |           └── index               该分包的页面 index 目录（其下结构与主包的页面文件一致）
|   ├── utils                           项目辅助类工具目录
|   |   └── api.js                      比如辅助类 api 等
|   ├── store                           Redux 状态管理
|   |   ├── reducers                    Redux Reducers
|   |   └── actions                     Redux Actions
|   ├── app.scss                        项目总通用样式
|   ├── types                           项目 TS 类型声明
|   └── app.config.js                   项目入口配置文件
|   └── app.js                          项目主入口文件
└── package.json                        依赖管理包信息
```