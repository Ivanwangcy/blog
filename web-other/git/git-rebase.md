# git rebase 变基
1. 使用 `rebase` 而非 `merge` 来拉取上游修改
```bash
$ git checkout other # 切换到当前分支 other

$ git merge master  # 将 master 分支 合并的当前分支 other

$ git checkout master # 切到主干分支
$ git rebase other  # 将 other 分支 变基到 master 主干分支中

```
2. 在执行 `git rebase` 后解决合并冲突
```bash
$ git rebase --abort  # 完全取消这次变基
$ git rebase --skip  # 完全忽略该提交

$ rm -fr "D:/workspace/blog/.git/rebase-apply" # 删除这次 变基 rebase
```
