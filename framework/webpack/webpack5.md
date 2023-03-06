# Webpack 5

Webpack5 正式发布以后，前端工程化会迈向一个新的阶段。但是大部分的工程脚手架还未升级到 Webpack5。

## Webpack 新特性

- Federated Module
- 持久化缓存
- 

> webpack 中文参考文档：<webpack.docschina.org>
> webpack 配置指南：<https://github.com/yuhaoju/webpack-config-handbook>
> 深入浅出 webpack：<https://xbhub.gitee.io/wiki/webpack>
> [精读《Webpack5 新特性 - 模块联邦》](https://github.com/dt-fe/weekly/blob/v2/144.%E7%B2%BE%E8%AF%BB%E3%80%8AWebpack5%20%E6%96%B0%E7%89%B9%E6%80%A7%20-%20%E6%A8%A1%E5%9D%97%E8%81%94%E9%82%A6%E3%80%8B.md)
> Webpack 5 新特性： <https://blog.csdn.net/xiangzhihong8/article/details/109046517> <https://www.jianshu.com/p/7148d29cee46>


webpack——webpack5新特性（启动、持久化缓存、资源模块、URIs、moduleIds和chunkIds、tree shaking、nodeJs的polyfill被移除、模块联邦）



【重学webpack系列——webpack5.0】
1-15节主要讲webpack的使用，当然，建议结合《webpack学完这些就够了》一起学习。
从16节开始，专攻webpack原理，只有深入原理，才能学到webpack设计的精髓，从而将技术点运用到实际项目中。
可以点击上方专栏订阅哦。

以下是本节正文：

1. webpack5有哪些新特性(面试题)
启动命令

持久化缓存

资源模块

URIs

moduleIds & chunkIds的优化

更智能的tree shaking

nodeJs的polyfill脚本被移除

模块联邦

2. 新特性1——启动命令
webpack4启动devServer，用的命令是webpack-dev-server
webpack5启动devServer，用的命令是webpack serve
3.新特性2——持久化缓存
webpack5相对于webpack4，后面几次打包会比首次打包时间可能会快80%，因为webpack5中可以配置cache（默认值为false），配置了之后，会将缓存存放在cacheDirectory中，第二次编译的时候会去读取缓存。

webpack会缓存生成的webpack模块和chunk,来改善构建速度
缓存在webpack5中默认开启，缓存默认是在内存里,但可以对cache进行设置
webpack 追踪了每个模块的依赖，并创建了文件系统快照。此快照会与真实文件系统进行比较，当检测到差异时，将触发对应模块的重新构建
module.exprots = {
	...
    cache: {
        type: 'memory', // 'memory' | 'filesystem'
        cacheDirectory: path.resolve(__dirname, 'node_modules/.cache/webpack')
    }
}
1
2
3
4
5
6
7
4.新特性3——资源模块
资源模块是一种模块类型，它允许使用资源文件（字体，图标等）而无需配置额外 loader
raw-loader => asset/source 导出资源的源代码
file-loader => asset/resource 发送一个单独的文件并导出 URL
url-loader => asset/inline 导出一个资源的 data URI
asset 在导出一个 data URI 和发送一个单独的文件之间自动选择。之前通过使用 url-loader，并且配置资源体积限制实现。当然asset也可以进行配置，根据配置来生成。
资源模块目前是实验性API，在webpack的配置文件中需要配置一下，启动资源模块这个实验性API
experiments: { // 启用实验性支持
    asset: true, // 支持asset
},
1
2
3
const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');
module.exports = {
    module:{
        rules: [
            {
              test: /\.png$/,
              type: 'asset/resource'
            },
            {
              test: /\.ico$/,
              type: 'asset/inline' // 会生成一个base64字符串，写了asset/inline就固定是base64了，不会因为大小来决定是否生成base64还是文件。如果要有大小阈值，那么type就写成asset，然后去加一个配置，如下面.jpg的使用方法
            },
            {
              test: /\.txt$/,
              type: 'asset/source' // 相当于以前的raw-loader
            },
            {
              test: /\.jpg$/,
              type: 'asset', // 单纯写asset，那么就可以进行配置，通过parser配置
              parser: {
                dataUrlCondition: {
                  maxSize: 8 * 1024
                }
              }
            },
        ]
    },
    experiments: { // 启用实验性支持
      asset: true, // 支持asset
    },
}
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
5.新特性4——URIs
Webpack 5 支持在请求中处理协议
支持data 支持 Base64 或原始编码,MimeType可以在module.rule中被映射到加载器和模块类型
这是一个实验性的 api
5.1 使用举例
import data from “data:text/javascript, export default 'title'”;
console.log(data)
1
2
6.新特性5——moduleIds 和 chunkIds 的优化
首先：
module：每一个文件其实都可以称一个 module
chunk：webpack 打包最终生成的代码块，代码块会生成文件（bundle），一般来说一个 bundle 对应一个 chunk
然后，对于 moduleIds 和 chunkIds 的类型有如下几种：
[外链图片转存失败,源站可能有防盗链机制,建议将图片保存下来直接上传(img-vAQK6gzf-1629215686789)(./_image/2021-08-17/2021-08-17-21-27-52@2x.png)]
其中，natural 其实就是 webpack5 以前生产环境模式下的默认模式，
其中，named 其实就是 webpack 以前和现在开发环境下的模式
其中，size 是根据模块大小来生成数字 id，用的很少
最后，deterministic 是 webpack5 新增的模式，也是 webpack5 生产环境下默认的模式，代表根据文件名称生成短 hash。
webpack5 要新增 deterministic 的原因（面试点）：
以前，不管是 natural 这类是按照顺序来命名产生的文件的，这就有一个问题，如果原先产出的文件是 1 2 和 3，后来我 2 相关的代码删掉了，这时候产出的 1 不变，但是 3 就变成 2 了，这样我 3 这个文件就不能利用缓存了。如果按照 webpack5 的话，去掉一个 2，产出的依旧是 1 和 3，那么 1 和 3 都可以从缓存中去读取，这样就大大加快了打包速度。



7.新特性6——移除 Node.js 的 polyfill
webpack5 以前，webpack 会包含 nodejs 核心模块的 polyfill，这样的话，比如安装了一个crypto模块，那么就可以直接使用，因为 node 的polyfill会自动启动。
现在，webpack5 移除了 nodejs 的 polyfill，无法再直接使用类似crypto的模块了。如果你想要使用类似crypto的 nodejs 核心模块，那么可以在 webpack 配置文件的resolve中配置fallback，配置了就可以使用了。如果不需要引用，将其置为 false 就可以了
开启了 fallback，也就是用了 node 核心模块的 polyfill，打包文件的体积会变大。
module.exports = {
    ...
    resolve: {
        fallback:  {
            "crypto": require.resolve("crypto-browserify"), // 如果不需要，那么就直接改为 false 就可以了
            "buffer": require.resolve("buffer"),
            "stream":require.resolve("stream-browserify")
        }
    }
}
1
2
3
4
5
6
7
8
9
10
8.新特性7——tree-shaking 进行了升级
tree-shaking 是用于打包时候剔除没有用到的代码，以达到减小体积，缩短 http 请求时间，起到一定效果的页面优化。
webpack5 以前，tree-shaking 比较简单，主要是找import进来的变量是否在这个模块内出现过，出现过则不剔除，不出现过则剔除。并且用于 esModule 中
webpack5，可以进行根据作用域之间的关系进行优化。比如：
a.js 中到处了两个方法 a 和 b，在 index.js 中引入了 a.js 到处的 a 方法，没有引用 b 方法。那么 webpack4 打包出来的结果包含了 index.js 和 a.js 的内容，包含了没有用到的 b 方法。但是 webpack5 的 treeshaking，会进行作用域分析，打包结果只有 index 和 a 文件中的 a 方法，没有用到的 b 方法是不会被打包进来的。
所以：webpack4 的 treeshaking 是关注 import 了某个库的什么模块，那么我就打包什么；webpack5 更精细化，直接分析到哪些变量有效地用到了，那么我就打包哪些变量。
所谓的“有效”只的就是活代码。而非死代码，类似引用了但是没有使用，这就是死代码，是需要剔除的。
9. 模块联邦Module Federation
9.1模块联邦是什么(面试点)
比如我们在开发两个应用A和B，A应用需要引用B应用，假设这两个应用是两个人开发的，都处于开发阶段，那么这时候就可以通过webpack的模块联邦Module Federation，将B应用暴露出去，然后A应用引用B应用。这样就不需要每次B应用build完了给A，直接可以同步开发。

使用模块联邦，每个应用块都应该是一个独立的构建，这些构建都将编译成容器，容器可以被其他应用或容器使用，引用模块的引用者成为host，一个被引用的容器成为remote。

有点类似微前端，其实微前端方案中确实也有模块联邦的方案。

然后面试官可能会继续问模块联邦或者问微前端。

9.2 为什么会有模块联邦
模块联邦主要是为了不同开发小组共同开发一个或多个应用。
场景举例：
应用将被划分为更小的应用块，一个应用块，可以是比如头部导航或者侧边栏的前端组件，也可以是数据获取逻辑的逻辑组件
每个应用快由不同组开发
应用或应用快共享其他应用块或库
9.3 模块联邦核心概念
使用模块联邦，每个应用块都应该是一个独立的构建，这些构建都将编译成容器
容器可以被其他应用或容器使用
引用模块的引用者成为host，一个被引用的容器成为remote
remote暴露给host，host则可以使用这些暴露的模块，这些模块被称为remote模块
[外链图片转存失败,源站可能有防盗链机制,建议将图片保存下来直接上传(img-BUMqX0Uv-1629442062265)(C:\Users\yuhua7\AppData\Roaming\Typora\typora-user-images\image-20210818141807511.png)]

9.4 webpack5中模块联邦的使用配置
9.4.1基本使用：
前置条件：多个应用，假设有应用A和应用B，并且是A引用B

那么这里就有两个概念：
B是remote，需要暴露出去
A是host，需要引用B
第一步：在A和B的webpack中引入模块联邦的插件

const ModuleFederationPlugin = require("webpack/lib/container/ModuleFederationPlugin");
1
第二步：在A和B的webpack中使用模块联邦插件

module.exports = {
    ...
    plugins: [
        new ModuleFederationPlugin({
            // 关键就是这里的配置
        })
    ]
}

这里的配置有哪些？

字段	类型	含义
name	string	必传值，即输出的模块名，被远程引用时路径为n a m e / {name}/name/{expose}
library	object	声明全局变量的方式，name为umd的name
filename	string	构建输出的文件名
remotes	object	远程引用的应用名及其别名的映射，使用时以key值作为name
exposes	object	被远程引用时可暴露的资源路径及其别名
shared	object	与其他应用之间可以共享的第三方依赖，使你的代码中不用重复加载同一份依赖
第三步：先看remote，即被暴露出去的B：

filename: "remoteEntry.js" 构建输出的文件名,也就是打包出来的文件名

name: "remote" name是必须的配置，标识输出的模块名，被远程引用时路径为n a m e / {name}/name/{expose}

exposes: {} 被远程引用时可暴露的资源路径及其别名

exposes的键值对，决定了暴露的内容
key为暴露的组件名称，但是要写成路径，这个路径是代表当前remote容器根路径下的NewsList（相对于remote容器根路径）
exposes: { // 被远程引用时可暴露的资源路径及其别名
    "./NewsList": "./src/NewsList", // 这里的key虽然说是暴露的组件，但是key还是要写成路径的形式。这个路径的意思是代表当前remote容器根路径下的NewsList（相对于remote容器根路径）
},
代码：

const ModuleFederationPlugin = require("webpack/lib/container/ModuleFederationPlugin");
module.exports = {
    ...
    plugins: [
        // 下面这个插件的作用就是，这个项目打包后会产出名字为${filename}的文件，并且这个容器叫做${name}，同时会向外提供${exposes}的key对应的那些组件,value是向外提供的组件在当前项目中是哪个组件
        // 另外，这个remote打包的产物，并不会覆盖项目的output.filename。两者是独立的。output中配置的会打包出来成为项目的产出，跟我们普通的打包一样，这个remote容器的文件remoteEntry.js也会打包出来，是专门用来给别人使用的。
        new ModuleFederationPlugin({
            filename: "remoteEntry.js", // 构建输出的文件名,也就是打包出来的文件名
            name: "remote", // name是必须的配置，标识输出的模块名，被远程引用时路径为${name}/${expose}
            exposes: { // 被远程引用时可暴露的资源路径及其别名
                "./NewsList": "./src/NewsList", // 这里的key虽然说是暴露的组件，但是key还是要写成路径的形式。这个路径的意思是代表当前remote容器根路径下的NewsList（相对于remote容器根路径）
            },
        })
    ]
}

第四步：再看host，即引用remote的应用A：

filename: "remoteEntry.js" 构建输出的文件名,也就是打包出来的文件名，这个名字个remote一样没事的，因为服务不一样
name: "host" name是必须的配置，标识输出的模块名，被远程引用时路径为n a m e / {name}/name/{expose}
remotes: {} 远程引用的应用名及其别名的映射
key作为远程应用的别名，用在使用远程应用的时候
value表示远程应用(remote容器)的地址:
地址格式：远程模块的name@url地址
代码：

new ModuleFederationPlugin({ // 使用模块联邦插件并配置
    filename: "remoteEntry.js", // 构建输出的文件名,也就是打包出来的文件名，这个名字个remote一样没事的，因为服务不一样
    name: "host", // name是必须的配置，标识输出的模块名，被远程引用时路径为${name}/${expose}
    remotes: {  // 远程引用的应用名及其别名的映射，使用时以key作为名字,也就是别名
        remoteY:'remote@http://localhost:3000/remoteEntry.js'// 远程引用remote容器。注意：格式是`远程模块的name@url地址`
    },
})

第五步：在A应用(host)中引用远程容器B(remote)

import动态加载远程组件，引用remoteY/NewsList,这个remoteY就是webpack配置的remotes中的key，也就是别名，/NewsList就是远程那个组件配置的webpack中exposes下的key(重点)
返回的就是一个组件RemoteNewsList，按照普通组件使用即可
// 引用远程容器(组件)，返回的就是一个组件RemoteNewsList
const RemoteNewsList = React.lazy(() => import('remoteY/NewsList')); // 动态加载远程组件，引用'remoteY/NewsList',这个`remoteY`就是webpack配置的remotes中的key，也就是别名，`/NewsList`就是远程那个组件配置的webpack中exposes下的key

const App = () => (
  <div>
    <h2>本地组件Sliders</h2>
    <Sliders />
    <React.Suspense fallback={<div>加载中</div>}>
      <RemoteNewsList/>
    </React.Suspense>
  </div>
);

注意点：

A项目引用B，那么A是host，B是远程容器
B用exposes暴露组件，A中remotes引用组件
如果AB共享某个库，那么shared在A中配置，也就是说共享的内容是在host中配置的
9.4.2特性配置:
shared:

当当前项目作为host的时候，引用远程容器，远程容器的shared配置中的内容会复用当前项目的内容
plugins: [
    ...
    new ModuleFederationPlugin({
        filename: "remoteEntry.js", 
        name: "host", 
        remotes: { 
            remoteX:'remote@http://localhost:6886/remoteEntry.js'
        },
        shared: { // 当当前项目作为host的时候，引用远程容器，远程容器的react和react-dom会复用当前项目的react和react-dom
            react: { singleton: true}, // 如果有一个容器已经引用了react了，那么另外一个容器就会复用react
            'react-dom': {singleton: true} // 如果有一个容器已经引用了react了，那么另外一个容器就会复用react
        }
    })

双向依赖:

A应用可以引用B的模块，B也可以引用A的模块，模块联邦的依赖共享是可以双向的
当A引用B时候，A就是host，B就是remote；当B引用A时候，B就是host，A就是remote
    // A应用
	plugins: [
        new HtmlWebpackPlugin({
            template:'./public/index.html'
        }),
        new ModuleFederationPlugin({
            filename: "remoteEntry.js",
            name: "remote",
+            remotes: {
+                host: "host@http://localhost:8000/remoteEntry.js"
+            },
            exposes: {
                "./NewsList": "./src/NewsList",
            },
            shared:{
                react: { singleton: true },
                "react-dom": { singleton: true }
              }
          })
    ]
    // B应用
    plugins: [
        new HtmlWebpackPlugin({
            template: './public/index.html'
        }),
        new ModuleFederationPlugin({
            filename: "remoteEntry.js",
            name: "host",
            remotes: {
                remote: "remote@http://localhost:3000/remoteEntry.js"
            },
+           exposes: {
+                "./Slides": "./src/Slides",
+           },
            shared:{
                react: { singleton: true },
                "react-dom": { singleton: true }
              }
        })
    ]


多个remote：

remote是一个对象，可以有多个键值对，每个key就是引用的模块，无论这个模块来源于哪个应用，只要是被暴露出来的就可以
plugins: [
        new ModuleFederationPlugin({
            filename: "remoteEntry.js",
            name: "all",
+           remotes: {
+               remote: "remote@http://localhost:3000/remoteEntry.js",
+               host: "host@http://localhost:8000/remoteEntry.js",
+           },
            shared:{
                react: { singleton: true },
                "react-dom": { singleton: true }
              }
          })
    ]

9.4.2 demo代码:
A应用
// webpack.config.js
let path = require("path");
let webpack = require("webpack");
let HtmlWebpackPlugin = require("html-webpack-plugin");
const ModuleFederationPlugin = require("webpack/lib/container/ModuleFederationPlugin"); // 需要引入模块联邦的插件
module.exports = {
    mode: "development",
    entry: "./src/index.js",
    output: {
        // publicPath: "http://localhost:3000/",
        path: path.resolve(__dirname, 'dist'),
        filename: 'main.js'
    },
    devServer: {
        port: 3000
    },
    module: {
        rules: [
            {
                test: /\.jsx?$/,
                use: {
                    loader: 'babel-loader',
                    options: {
                        presets: ["@babel/preset-react"]
                    },
                },
                exclude: /node_modules/,
            },
        ]
    },
    plugins: [
        new HtmlWebpackPlugin({
            template:'./public/index.html'
        }),
        // 下面这个插件的作用就是，这个项目打包后会产出名字为${filename}的文件，并且这个容器叫做${name}，同时会向外提供${exposes}的key对应的那些组件,value是向外提供的组件在当前项目中是哪个组件
        // 另外，这个remote打包的产物，并不会覆盖项目的output.filename。两者是独立的。output中配置的会打包出来成为项目的产出，跟我们普通的打包一样，这个remote容器的文件remoteEntry.js也会打包出来，是专门用来给别人使用的。
        new ModuleFederationPlugin({ // 使用模块联邦插件并配置
            filename: "remoteEntry.js", // 构建输出的文件名,也就是打包出来的文件名
            name: "remote", // name是必须的配置，标识输出的模块名，被远程引用时路径为${name}/${expose}
            exposes: { // 被远程引用时可暴露的资源路径及其别名
                "./NewsList": "./src/NewsList", // 这里的key虽然说是暴露的组件，但是key还是要写成路径的形式。这个路径的意思是代表当前remote容器根路径下的NewsList（相对于remote容器根路径）
            },
            remotes: { 
                remoteX:'host@http://localhost:6886/remoteEntry.js'
            },
            shared: { // 当当前项目作为host的时候，引用远程容器，远程容器的react和react-dom会复用当前项目的react和react-dom
                react: { singleton: true}, // 如果有一个容器已经引用了react了，那么另外一个容器就会复用react
                'react-dom': {singleton: true} // 如果有一个容器已经引用了react了，那么另外一个容器就会复用react
            }
        })
    ]
}
/*
    A项目引用B，那么A是host，B是远程容器
    1. B用exposes暴露组件，A中remotes引用组件
    2. 如果AB共享某个库，那么shared在A中配置，也就是说共享的内容是在host中配置的

*/ 


// App.js
import React from "react";
import Sliders from './Sliders';
// 引用远程容器(组件)，返回的就是一个组件RemoteNewsList
const RemoteNewsList = React.lazy(() => import('remoteY/NewsList')); // 动态加载远程组件，引用'remote/NewsList',这个`remote`就是webpack配置的remotes中的key，也就是别名，`/NewsList`就是远程那个组件配置的webpack中exposes下的key
const App = () => (
  <div>
    <h2>本地组件Sliders</h2>
    <Sliders />
    <React.Suspense fallback={<div>加载中</div>}>
      <RemoteNewsList/>
    </React.Suspense>
  </div>
);

export default App;

B应用
// webpack.config.js
let path = require("path");
let webpack = require("webpack");
let HtmlWebpackPlugin = require("html-webpack-plugin");
const ModuleFederationPlugin = require("webpack/lib/container/ModuleFederationPlugin"); // 需要引入模块联邦的插件
module.exports = {
    mode: "development",
    entry: "./src/index.js",
    output: {
        // publicPath: "http://localhost:3000/",
        path: path.resolve(__dirname, 'dist'),
        filename: 'main.js'
    },
    devServer: {
        port: 3000
    },
    module: {
        rules: [
            {
                test: /\.jsx?$/,
                use: {
                    loader: 'babel-loader',
                    options: {
                        presets: ["@babel/preset-react"]
                    },
                },
                exclude: /node_modules/,
            },
        ]
    },
    plugins: [
        new HtmlWebpackPlugin({
            template:'./public/index.html'
        }),
        // 下面这个插件的作用就是，这个项目打包后会产出名字为${filename}的文件，并且这个容器叫做${name}，同时会向外提供${exposes}的key对应的那些组件,value是向外提供的组件在当前项目中是哪个组件
        // 另外，这个remote打包的产物，并不会覆盖项目的output.filename。两者是独立的。output中配置的会打包出来成为项目的产出，跟我们普通的打包一样，这个remote容器的文件remoteEntry.js也会打包出来，是专门用来给别人使用的。
        new ModuleFederationPlugin({ // 使用模块联邦插件并配置
            filename: "remoteEntry.js", // 构建输出的文件名,也就是打包出来的文件名
            name: "remote", // name是必须的配置，标识输出的模块名，被远程引用时路径为${name}/${expose}
            exposes: { // 被远程引用时可暴露的资源路径及其别名
                "./NewsList": "./src/NewsList", // 这里的key虽然说是暴露的组件，但是key还是要写成路径的形式。这个路径的意思是代表当前remote容器根路径下的NewsList（相对于remote容器根路径）
            },
            remotes: { 
                remoteX:'host@http://localhost:6886/remoteEntry.js'
            },
            shared: { // 当当前项目作为host的时候，引用远程容器，远程容器的react和react-dom会复用当前项目的react和react-dom
                react: { singleton: true}, // 如果有一个容器已经引用了react了，那么另外一个容器就会复用react
                'react-dom': {singleton: true} // 如果有一个容器已经引用了react了，那么另外一个容器就会复用react
            }
        })
    ]
}
/*
    A项目引用B，那么A是host，B是远程容器
    1. B用exposes暴露组件，A中remotes引用组件
    2. 如果AB共享某个库，那么shared在A中配置，也就是说共享的内容是在host中配置的

*/ 


// App.js
import React from "react";
import NewsList from './NewsList';
const RemoteSliders = React.lazy(() => import("remoteX/Sliders"))
const App = () => (
  <div>
    <h2>本地组件NewsList</h2>
    <NewsList />
    <React.Suspense fallback={<div>加载中</div>}>
      <RemoteSliders/>
    </React.Suspense>
  </div>
);

export default App;
模块联邦面试题可能会问到实现原理、数据传输等问题，这个我专门会写一个微前端专题。

最后，分享webpack5变更链接：changelog-v5/README.md at master · webpack/changelog-v5 · GitHub
————————————————
版权声明：本文为CSDN博主「俞华」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_17175013/article/details/119769033