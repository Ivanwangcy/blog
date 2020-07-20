# webpack面试题


## 谈谈你对webpack的看法

webpack是一个模块打包工具，可以使用它管理项目中的模块依赖，并编译输出模块所需的静态文件。它可以很好地管理、打包开发中所用到的HTML,CSS,JavaScript和静态文件（图片，字体）等，让开发更高效。对于不同类型的依赖，webpack有对应的模块加载器，而且会分析模块间的依赖关系，最后合并生成优化的静态资源。

webpack的基本功能和工作原理？
代码转换：TypeScript 编译成 JavaScript、SCSS 编译成 CSS 等等
文件优化：压缩 JavaScript、CSS、HTML 代码，压缩合并图片等
代码分割：提取多个页面的公共代码、提取首屏不需要执行部分的代码让其异步加载
模块合并：在采用模块化的项目有很多模块和文件，需要构建功能把模块分类合并成一个文件
自动刷新：监听本地源代码的变化，自动构建，刷新浏览器
代码校验：在代码被提交到仓库前需要检测代码是否符合规范，以及单元测试是否通过
自动发布：更新完代码后，自动构建出线上发布代码并传输给发布系统。

## webpack构建过程

从entry里配置的module开始递归解析entry依赖的所有module
每找到一个module，就会根据配置的loader去找对应的转换规则
对module进行转换后，再解析出当前module依赖的module
这些模块会以entry为单位分组，一个entry和其所有依赖的module被分到一个组Chunk
最后webpack会把所有Chunk转换成文件输出
在整个流程中webpack会在恰当的时机执行plugin里定义的逻辑

## webpack打包原理

将所有依赖打包成一个bundle.js，通过代码分割成单元片段按需加载

## 什么是webpack，与gulp,grunt有什么区别

webpack是一个模块打包工具，可以递归地打包项目中的所有模块，最终生成几个打包后的文件。
区别：webpack支持代码分割，模块化（AMD,CommonJ,ES2015），全局分析

## 什么是entry,output?

entry 入口，告诉webpack要使用哪个模块作为构建项目的起点，默认为./src/index.js
output 出口，告诉webpack在哪里输出它打包好的代码以及如何命名，默认为./dist

## 什么是loader，plugins?

loader是用来告诉webpack如何转换某一类型的文件，并且引入到打包出的文件中。
plugins(插件)作用更大，可以打包优化，资源管理和注入环境变量
什么是bundle,chunk,module?
bundle是webpack打包出来的文件，chunk是webpack在进行模块的依赖分析的时候，代码分割出来的代码块。module是开发中的单个模块

## 如何自动生成webpack配置？

可以用一些官方脚手架

webpack-cli
vue-cli
// 首先安装
npm install -g @vue/cli
// 新建项目hello
vue create hello
复制代码
nuxt-cli
// 确保安装了npx,npx在npm5.2.0默认安装了
// 新建项目hello
npx create-nuxt-app hello
复制代码
webpack如何配置单页面和多页面的应用程序？
单个页面
module.exports = {
    entry: './path/to/my/entry/file.js'
}
复制代码
多页面应用程序
module.entrys = {
    entry: {
        pageOne: './src/pageOne/index.js',
        pageTwo: './src/pageTwo/index.js'
    }
}
复制代码
webpack-dev-server和http服务器如nginx有什么区别？
webpack-dev-server使用内存来存储webpack开发环境下的打包文件，并且可以使用模块热更新，相比传统http服务器开发更加简单高效

## 什么是模块热更新？

webpack的一个功能，可以使代码修改后不用刷新浏览器就自动更新，高级版的自动刷新浏览器

## dev-server是怎么跑起来的

webpack-dev-server支持两种模式来自动刷新页面

iframe模式（页面放在iframe中，当发送改变时重载） 无需额外配置，只要以这种格式url访问即可。http://localhost:8080/webpack-dev-server/index.html
inline模式（将webpack-dev-server的客户端入口添加到bundle中） inline模式下url不用发生变化，但启动inline模式分两种情况
// 以命令行启动webpack-dev-server有两种方式
// 方式1 在命令行中添加--inline命令
// 方式2 在webpack-config.js添加devServer:{inline: true}
// 以node.js API启动有两种方式
// 方式1 添加webpack-dev-server/client?http://localhost:8080/到webpack配置的entry入口点
config.entry.app.unshift("webpack-dev-server/client?http://localhost:8080/");
// 将<script src="http://localhost:8080/webpack-dev-server.js"></script>添加到html文件中
复制代码

## 使用过webpack里面哪些plugin和loader

loader

babel-loader: 将ES6+转移成ES5-
css-loader,style-loader：解析css文件，能够解释@import url()等
file-loader：直接输出文件，把构建后的文件路径返回，可以处理很多类型的文件
url-loader：打包图片
// url-loader增强版的file-loader，小于limit的转为Base64,大于limit的调用file-loader
npm install url-loader -D
// 使用
module.exports = {
    module: {
        rules: [{
            test: /\.(png|jpg|gif)$/,
            use: [{
                loader: 'url-loader',
                options: {
                    outputPath: 'images/',
                    limit: 500 //小于500B的文件打包出Base64格式，写入JS
                }
            }]
        }]
    }
}
复制代码

## plugins

html-webpack-plugin: 压缩html
const HtmlWebpackPlugin = require('html-webpack-plugin')
module.exports = {
  //...
  plugins: [
    new HtmlWebpackPlugin({
      filename: 'index.html', // 配置输出文件名和路径
      template: './public/index.html', // 配置要被编译的html文件
      hash: true,
      // 压缩 => production 模式使用
      minify: {
        removeAttributeQuotes: true, //删除双引号
        collapseWhitespace: true //折叠 html 为一行
      }
    })
  ]
}
复制代码
clean-webpack-plugin: 打包器清理源目录文件，在webpack打包器清理dist目录
npm install clean-webpack-plugin -D
// 修改webpack.config.js
const cleanWebpackPlugin=require('clean-webpack-plugin')
module.exports = {
    plugins: [new cleanWebpackPlugin(['dist'])]
}
复制代码
webpack中babel的实现
安装 npm i -D @babel-preset-env @babel-core babel-loader

@babel-preset-env：可以让我们灵活设置代码目标执行环境
@babel-core: babel核心库
babel-loader: webpack的babel插件，让我们可以在webpack中运行babel
配置.babelrc

{
    "presets": ['@babel/preset-env']
}
复制代码
配置webpack.config.js

module.exports = {
    entry: './src/index.js',
    output: {
        path: path.resolve(__dirname, 'dist'),
        filename: 'bundle.js'
    },
    module: {
        rules: [{
            test: /\.js$/,
            exclude: /node_modules/,
            use: {loader: 'babel-loader'}
        }]
    }
}
复制代码
提取公用代码
module.exports = {
    optimization: {
        splitChunks: {
            common: {
                // 抽离公共代码
                chunks: 'initial',
                name: 'common', // 打包后的文件名
                minChunks: 2, // 最小引用2次
                minSize: 0 // 超出0字节就生成一个新包
            },
            styles: {
                // 抽离公用代码
                name: 'styles',
                test: /\.css$/,
                chunks: 'all',
                minChunks: 2,
                enforce: true
            },
            vender: {
                // 抽离第三方插件
                test: /node_modules/,
                chunks: 'initial',
                name: 'vendor', // 打包后的文件名
                priority: 10 // 设置优先级，防止与自定义公共代码提取时被覆盖，不进行打包
            }
        }
    }
}
复制代码
什么是长缓存？在webpack中如何做到长缓存优化？
浏览器在用户访问页面的时候，为了加快加载速度会对用户访问的静态资源进行存储，但是每一次代码升级或更新都需要浏览器下载新的代码，最简单方便的方式就是引入新的文件名称。
webpack中可以在output中指定chunkhash，并且分离经常更新的代码和框架代码。通过NameModulesPlugin或HashedModuleIdsPlugin使再次打包文件名不变。
什么是Tree-shaking？CSS可以Tree-shaking？
Tree-shaking是指在打包中取出那些引入了但在代码中没有被用到的死代码。webpack中通过uglifysPlugin来Tree-shaking JS。CSS需要使用purify-CSS

## 继承 8种

原型链继承
重点：子的原型对象为new一个父的实例 Child.prototype = new Parent();
缺点：多个实例对引用类型的操作会被篡改
借用构造函数继承
重点：在子构造函数内部调用父构造函数 Parent.call(this)
缺点：无法实现复用，不能继承原型属性/方法
组合继承
重点：使用原型链继承共享的属性和方法，通过借用构造函数继承实例属性
function Child(name,age){
    // 继承属性
    Parent.call(this, name)
    this.age=age
}
// 继承方法
Child.prototype = new Parent()
Child.prototype.constructor = Child;
复制代码
缺点：无论在什么情况都会调用两次父构造函数，一次是创建子类型原型，另一次是在子构造函数内部
原型式继承
重点：执行对给定对象的浅复制
function object(obj){
    function F(){}
    F.prototype=obj
    return new F();
}
var person1=object(person);
复制代码
在ES5中Object.create()可替换上面的方法object() var person1 = Object.create(person);

缺点：原型链继承多个实例的引用类型属性指向相同，存在篡改的可能；无法传递参数
寄生式继承
重点：在原型式继承的基础上，增强对象，返回构造函数
function createAnother(obj){
    var clone=object(obj);
    // ES5中用这个
    // var clone=Object.create(obj);
    // 增强对象
    clone.sayHi=function(){};
    return clone;
}
var person1=createAnother(person)
复制代码
缺点：同原型式继承
寄生组合式继承
重点：结合构造函数传递参数和寄生模式实现继承
// 借用构造函数增强子类实例属性（支持传参和避免篡改）
function Child(name,age){
    // 继承属性
    Parent.call(this, name)
    this.age=age
}
function inheritPrototype(Child, Parent){
    var prototype=Object.create(Parent.prototype);
    prototype.constructor=Child;
    Child.prototype=prototype;
}
// 将父类原型指向子类，这样子类就能使用父类原型链的属性/方法
inheritPrototype(Child, Parent);
复制代码
优点：只调用一次构造函数，原型链不变，是最成熟的

混入方式继承多个方式
重点：利用Object.assign将父类原型上的方法拷贝到子类原型上，这样子类实例实例就可以使用父类的方法

Object.assign(Child.prototype, Parent.prototype);
Child.prototype.constructor=Child;
复制代码
ES6类 extends
重点：使用extends表明继承自哪个父类，并且在子类构造函数中必须使用super，可以看做是Parent.call(this,value)

class Parent{
    constructor(value){
        this.val=value
    }
}
class Child extends Parent{
    constructor(value){
        super(value)
        this.val = value
    }
}
复制代码
>> 参考文献：前端面试之webpack面试常见问题: https://juejin.im/post/5c6cffde6fb9a049d975c8c1
