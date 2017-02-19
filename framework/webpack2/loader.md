## Loader 加载器配置
```js
module: {
  rules: [
    {
      test: /\.css$/,
      use: [
        {
          loader: "style-loader"
        },
        {
          loader: "css-loader",
          options: {
            modules: true
          }
        }
      ]
    },
    {
        test: /\.jsx$/,
        loader: "babel-loader", // Do not use "use" here
        options: {
          // ...
        }
      }
  ]
},
```# ##


 # #
