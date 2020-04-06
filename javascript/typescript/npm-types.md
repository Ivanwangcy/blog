# npm 发布 types

首先 package.json 中需要指定, 如果是 index.d.ts 在根目录则可以不指定:

添加 "types": "index.d.ts" 到你的 package.json


当其他人导入你的包的时候，这句话就告诉了 TS 编译器到哪里去寻找类型定义文件。这里的 .d.ts 文件和 main 入口指向的是一个文件夹，所以通常情况下，你的 package.json 会包含下面两行：

```json
{
...
"main": "dist/index.js",
"types": "dist/index.d.ts"
...
}
```

