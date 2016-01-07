# log日志
---
`git log`命令显示从最近到最远的提交日志
```shell
$ git log --pretty=oneline
```

### 查看提交历史，设置样式并增加别名
```shell
$ git log
$ git config --global alias.lg "log --color --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit"  定义历史记录格式的别名, 以后只需 git lg 即可
```
