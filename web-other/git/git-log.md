# log日志
---
`git log`命令显示从最近到最远的提交日志
```shell
$ git log --pretty=oneline // 单行显示日志
$ git log --stat // 列出各个版本间的改动及行数
$ git log --stat -n (-n,-1,-2 需要显示的条目数量) // 显示简要的增改行数统计
```

### 查看提交历史，设置样式并增加别名
```shell
$ git log
$ git config --global alias.lg "log --color --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit"   // 定义历史记录格式的别名, 以后只需 git lg 即可
$ git lg  // 使用上面的别名
$ git lg -5 // 只显示5条提交记录
```
