## 回滚到指定版本
```shell
$ git reset --hard 78af61c 还原远程代码 // 强制还原，无记录
$ git reset --hard HEAD~3   <!-- 会将最新的3次提交全部重置，就像没有提交过一样。 -->
$ git push -f 强制提交回滚操作
$ git revert
```
