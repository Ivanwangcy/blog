# git rebase 变基

## 使用 `rebase` 而非 `merge` 来拉取上游修改

```bash
$ git checkout other # 切换到当前分支 other

$ git merge master  # 将 master 分支 合并的当前分支 other

$ git checkout master # 切到主干分支
$ git rebase other  # 将 other 分支 变基到 master 主干分支中
```

-   将 other 分支上的所有提交记录，增加到 master 主干分支，给 master 一个清晰的历史记录；

-   当你在 other 分支提交过很多次后：
    -   如果用 merge 合并的主干分支，那么只能给 master 增加一条合并记录，你所有的提交明细都没有了。
    -   相反使用 rebase 变基到 master 主干分支，你的所有提交记录都转给了 master，提交的每条记录都清晰可见。
-   如果 master 为最新修改，那就先合并的自己的分支，再 rebase 到主干分支。
-   如果你想让 "master" 主干分支历史看起来像没有经过任何合并一样，可以使用 git rebase;
-   使用 git rebase 操作自己的分支就像操作主干分支一样;
-   使用 git merge 操作分支，结果会产生一个新的"合并的提交"(merge commit);
-   在 rebase 的过程中，也许会出现冲突(conflict). 在这种情况，Git 会停止 rebase 并会让你去解决 冲突；在解决完冲突后，用"git-add"命令去更新这些内容的索引(index), 然后，你无需执行 git-commit,只要执行:

```sh
$ git rebase --continue # git add 后 继续 rebase
```

- 冲突标记<<<<<<< （7 个<）与=======之间的内容是当前分支或者我的修改，=======与>>>>>>>之间的内容是其它分支或别人的修改, 包裹合并过来的内容。

## 在执行 `git rebase` 后解决合并冲突

```sh
# rebase 变基
$ git rebase --abort  # 完全取消这次变基, 终止后会回到rebase开始之前的状态
$ git rebase --skip  # 完全忽略该提交

$ rm -fr "D:/workspace/blog/.git/rebase-apply" # 删除这次 变基 rebase
```$$

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
