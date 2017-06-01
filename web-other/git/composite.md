## 综合应用
## 撤销与回滚操作
当代码提交错误，或者提错分支等操作时需要还原代码时可以根据情景进行下列撤销与回滚操作。

- `git checkout -- <file_name>` 撤销本地修改，还原到 master
- `git reset -- <file_name>` 撤销添加暂存区，恢复到 add 之前的状态
- `git reset --soft HEAD^` 撤销最后一次提交，恢复至暂存区，到 add 之后的状态，撤销提交同时保留修改的内容，可以继续上一次修改进行操作
- `git revert <commit_id>` 回滚某一次提交并还原修改的内容，需重新 push ，适合无效提交需回滚，不关心修改的内容，提交的内容都还原
- `git reset --hard <commit_id> && git push -f` 强制还原至此次提交，并清除之后提交的历史记录 **慎用**

## 查看日志，提交历史记录
- git log 查看日志， `ctrl + Z` 退出
