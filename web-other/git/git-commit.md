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

## 修改提交信息

```sh
git commit --amend
git commit --amend -m "chore: 新的提交信息"
```

## 修改历史提交信息

```sh
# 1.找到要修改SHA位置(git log) 要修改的提交记录，之前的 hash 值

# 2 使用 rebase -i 修改提交记录
$ git rebase -i  32e0a87f      # 指定的SHA位置

# 3 进入编辑页面


# 4.将pick修改为edit 并修改后面的内容并  :wq  保存退出

# 5 追加改动到提交 

$ git commit –-amend -m "fix: 新内容"


# 6 使用 --continue 继续 rebase 回到原来分支

$ git rebase --continue

# 7 强制提交改动，push
$ git push -f  # 推到远程(修改成功了)

```

>> 参考：[git修改commit以前某一次提交的内容](https://blog.csdn.net/it_zhang_PG/article/details/83183952)
