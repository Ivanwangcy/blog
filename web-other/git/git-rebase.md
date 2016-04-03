# git rebase 变基
## 使用 `rebase` 而非 `merge` 来拉取上游修改
```bash
$ git checkout other # 切换到当前分支 other

$ git merge master  # 将 master 分支 合并的当前分支 other

$ git checkout master # 切到主干分支
$ git rebase other  # 将 other 分支 变基到 master 主干分支中
```
* 将other分支上的所有提交记录，增加到master 主干分支，给 master 一个清晰的历史记录；
* 当你在other分支提交过很多次后：
  * 如果用 merge 合并的主干分支，那么只能给master增加一条合并记录，你所有的提交明细都没有了。  
  * 相反使用 rebase 变基到master主干分支，你的所有提交记录都转给了master，提交的每条记录都清晰可见。
* 如果master为最新修改，那就先合并的自己的分支，再rebase到主干分支。
## 在执行 `git rebase` 后解决合并冲突
```bash
$ git rebase --abort  # 完全取消这次变基
$ git rebase --skip  # 完全忽略该提交

$ rm -fr "D:/workspace/blog/.git/rebase-apply" # 删除这次 变基 rebase
```
