# npm 包发布

```sh
$ npm publish .

$ npm owner add  # 增加发布者权限

npm adduser --registry=http://registry.x.xx.com --scope=@xx

npm login

```

使用 nrm 安装多个源

```sh
# 1. 安装nrm管理多个源
npm install -g nrm --registry=http://registry.xxx.com

# 2. 添加其它私源
nrm add npm2 http://registry.xxxx.com

# 3. 切换到其他源
nrm use npm2

```
