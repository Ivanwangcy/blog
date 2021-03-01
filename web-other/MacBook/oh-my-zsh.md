# Oh-My-zsh 命令行操作

Oh-My-Zsh 是一个用于管理 ZSH 配置的开源社区驱动框架。它捆绑了大量有用的功能，帮手，插件，主题以及一些让你大声呼喊的东西......

## 配置 profile

```sh
# 查看配置文件
$ cd ~
$ cat .zshrc # 查看配置信息
$ vim .zshrc # 编辑配置文件
$ source .zshrc # 使配置文件生效
```

## 更换主题

```sh
# 编辑 `.zshrc`
ZSH_THEME="robbyrussell"   ## 指定主题
# 或者  随机主题
ZSH_THEME="random" # (...please let it be pie... please be some pie..) 随机的主题不喜欢，可以使用 source ~/.zshrc 重新载入主题
```

## 安装  oh-my-zsh

[install](./term2.md)

## Oh-My-zsh git

```sh
#### 常用
$ g # => git

$ gst # 等于 git status 查看状态
$ gss # 等于 git status -s 简化的 git 状态
$ gcmsg "message" # 等于 git commit -m "说明"
$ ga # => git add
$ gaa # 等于 git add --all
$ gp # 等于 git push
$ gl # 等于 git pull
$ gco # 等于 git checkout
$ glg # 等于 git log --stat --max-count = 10  Ctrl + Z 退出
$ glog # 等于 git log --oneline --decorate --color --graph
```

## 查询端口占用情况并杀掉进程

```sh
# 查询端口
$ sudo lsof -i:1099

COMMAND   PID         USER   FD   TYPE             DEVICE SIZE/OFF NODE NAME
java    19493 xxx   26u  IPv6 0xecf06017998c199b      0t0  TCP *:rmiregistry (LISTEN)
java    19493 xxx   84u  IPv6 0xecf06017a3df351b      0t0  TCP localhost:rmiregistry->localhost:52791 (ESTABLISHED)
idea    85025 xxx   97u  IPv4 0xecf060179e4f80a3      0t0  TCP localhost:52791->localhost:rmiregistry (ESTABLISHED)

# 杀死d端口对应进程 杀进程
$ sudo kill 19493 
```

## 另一种方式

- 打开启动台》其他》活动监视器
- 活动监视器选中相应想停止的进程或者程序，点击左上角的×，就可以

[iTerm 2 && Oh My Zsh【DIY教程——亲身体验过程】](https://www.jianshu.com/p/7de00c73a2bb)
