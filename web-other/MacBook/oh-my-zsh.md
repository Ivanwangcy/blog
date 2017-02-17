# Oh-My-zsh 命令行操作
## 配置 profile
```sh
$ cd ~
$ cat .zshrc # 查看配置信息
$ vim .zshrc # 编辑配置文件
```
## 更换主题  
```
编辑 `.zshrc`   
ZSH_THEME="robbyrussell"   ## 指定主题
或者  随机主题
ZSH_THEME="random" # (...please let it be pie... please be some pie..)
```
## 安装 oh-my-zsh
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
