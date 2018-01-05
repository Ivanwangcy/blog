# git 提交
## 增加别名（Oh-my-zsh 自带这些别名）
```sh
$ gaa == git add --all

$ gc == git commit -v  # 冗长的显示信息，可以查看到自己改了什么，确保准确无误
$ gc! == git commit -v --amend # 修改提交信息
$ gca == git commit -v -a # 增加缓存区
$ gca! == git commit -v -a --amend # 增加并提交信息

$ gcs == git commit -S
```
## git commit summary and description
使用命令行 或者在 vim 编辑器中输入描述，回车代表标题结束
```sh
git commit -m "summary" -m "description"
```
还可以使用 github 客户端分别输入：Summary 和 Description
