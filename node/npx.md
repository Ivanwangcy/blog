# npx npm 包的执行器

npm 可执行的包，命令行工具等可以使用 npx 命令直接使用无需在本地全局安装。

[npx github 地址](https://github.com/npm/npx)

## 以 create-react-app 为例

传统的方式是：
```sh
# 先全局安装 create-react-app 包会把 create-react-app 加入到环境变量
npm i -g create-react-app
# 再创建项目
create-react-app my-app
```

使用 npx 只需一步：

```sh
npx create-react-app my-app
```
