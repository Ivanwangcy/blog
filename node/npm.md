# npm 介绍

npm（最初是Node Package Manager的缩写）是JavaScript编程语言的包管理器。它是JavaScript运行时环境 Node.js 的默认包管理器。npm 的本质是一个源码分发平台，可以在官网上面发布和下载包资源。

## npm 应用

### npm 帮助

```sh
$ npm help # 帮助  npm命令列表
$ npm help <command> # 帮助  打开网页版帮助

$ npm <command> -h # 帮助 命令行学习工具

# 各个命令的简单用法
$ npm -l
```

### npm init 初始化

```bash
$ npm init # 初始化package.json 根据提示回车即可
```

### NPM 常用命令：

```sh
$ npm –v  查看npm版本；
$ npm –l  查看各个命令的简单用法；
$ npm init -y  创建一个package.json包结构, 直接生成默认包；
$ npm install <package name> 本地安装模块；
	–save：模块名将被添加到dependencies，可以简化为参数-S。
	–save-dev: 模块名将被添加到devDependencies，可以简化为参数-D。
$ npm run 可以运行package.json 里面的脚本scripts；（很重要）
$ npm info jquery 查看指定包名的模块具体信息；
$ npm search <key> 使用关键字搜索一个包；
$ npm list  # 列出当前项目所有模块和依赖模块；
$ npm ls # 同上
$ npm ls lodash  # 查看包的依赖 树

# 查看 包信息
$ npm view «package-name» versions
$ npm view webpack versions
$ npm view «package-name» dist-tags
$ npm view webpack dist-tags
# { latest: '1.12.9', beta: '2.0.1-beta' }
```

### 安装与更新包,模块

```sh
$ npm install jquery --save # 安装 jquery 并保存到 package.json npm install == npm i

$ npm install jquery backbone underscore --save # 安装包并保存到 package.json npm install == npm i

$ npm uninstall --global jquery #卸载

$ npm update # 更新当前项目中的模块

$ npm update -g # 更新全局的模块

$ npm update jquery # 更新到最新版本的 jquery 库

$ npm update --save # 更新所有本地仓库 并 更新 package.json

$ npm remove jquery --save # 删除jquery库，并更新 package.json npm remove == npm r

$ npm ls # 列出当前安装的了所有包
$ npm ls -gl  # 同上

$ npm ls -g  # 列出全局安装的所有模块
```

### npm install 详解

当你为你的模块安装一个依赖模块时，正常情况下你得先安装他们（在模块根目录下 npm install module-name），然后连同版本号手动将他们添加到模块配置文件 package.json 中的依赖里（dependencies）。

* -save 和 save-dev 可以省掉你手动修改 package.json 文件的步骤。

```bash
$ npm install module-name --save # 自动把模块和版本号添加到dependencies部分
$ npm install module-name --save-dev # 自动把模块和版本号添加到devdependencies部分

# 简单的写法：安装 webpack 的缩写形式，如下
$ npm i webpack -S   # –save：模块名将被添加到dependencies，可以简化为参数-S。
$ npm i webpack -D   # –save-dev: 模块名将被添加到devDependencies，可以简化为参数-D。

# 安装多个包用空格隔开
$ npm install babel-loader babel-core babel-preset-es2015 babel-preset-react --save-dev
# 安装 package.json 依赖包
$ npm install  # 安装 package.json 里面的 dependencies 依赖包

$ npm install --only=dev  # 安装 package.json 里面的 devdependencies 部分的依赖包
$ npm install --dev # 同上，已废弃建议使用上面的
# 简写 全局安装（同时安装多个包 空格隔开）
$ npm i -g webpack webpack-dev-server

# 同样的前缀可以使用 大括号 简写 安装
$ npm install --save-dev {babel,css,style,postcss,url,file}-loader # ==> babel-loader css-loader ...
```

至于配置文件区分这俩部分，是用于区别开发依赖模块和产品依赖模块，devDepandencies 主要是配置测试框架， 例如 jshint、mocha。

### npm 安装 不同版本

install 命令总是安装模块的最新版本，如果要安装模块的特定版本，可以在模块名后面加上@和版本号。

```sh
$ npm install sax@latest
$ npm install sax@0.1.1
$ npm install sax@">=0.1.0 <0.2.0"

$ npm install --save vue@">=2.0.0-rc.1"

# 例如: 安装rc版的vue,  -- Vue 2.0 候选版本（Release Candidate）, 也可以叫`预览版`
# 使用 view命令查看 tags 找到vue 2.0 对应的 tag
$ npm view vue dist-tags
# { latest: '1.0.27', csp: '1.0.27-csp', next: '2.0.0-rc.7' }
$ npm install --save vue@next
```

### npm 自身升级

```sh
$ npm --version # 查看NPM版本
$ npm install -g npm@3.7.2 # 安装指定版本的 NPM
$ npm install npm@latest -g # 更新到最新版本
```

### npm package.json 配置 scripts 运行 命令

```javascript
"scripts": {
    "test": "echo \"Error: no test specified\" && exit 1",
    "dev": "webpack-dev-server --devtool eval --progress --colors",
    "deploy": "NODE_ENV=production webpack -p"
  }
```

### npm dedupe 去重, 重新计算依赖关系

```bash
$ npm dedupe
```

### 执行配置的命令

```bash
"scripts" : {"test" : "node testfile.js"}
$ npm test # 执行测试命令


$ npm start # 启动一个项目
$ npm run dev # 使用 npm run 执行自定义命令
$ npm run deploy
```

### 其它命令

```sh
$ npm shrinkwrap  # 锁定依赖版本
$ npm outdated # 查看 package.json 中依赖的包结构
```

### 版本控制
