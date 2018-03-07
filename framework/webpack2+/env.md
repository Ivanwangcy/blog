## Webpack Environment Variables

```js
// 这个在 npm run dev 和 npm run build 时候是不同的
var TARGET = process.env.npm_lifecycle_event

// 如果 `npm run dev`
TARGET === 'dev' // true
// 如果 `npm run build`
TARGET === 'build' // true
```

>参考：[Discovering the NPM Lifecycle Event](https://medium.com/@brianhan/use-this-npm-variable-as-a-flag-for-your-build-scripts-31069f5e2e57)
