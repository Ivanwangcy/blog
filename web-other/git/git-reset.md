# 还原暂存区，撤销 add 操作 -- Undo add

```sh
# 暂存操作
$ git add . 添加暂存区
$ git reset . 撤销上面操作
```

## 还原本地仓库，撤销 commit 操作 -- Undo a commit and redo

```sh
$ git commit -m "comment"
git reset --soft HEAD^ 撤销上一次提交
```

## 回滚到指定版本

```bash
$ git reset --hard 78af61c # 还原远程代码 // 强制还原，无记录
$ git reset --hard HEAD~3  # <!-- 会将最新的3次提交全部重置，就像没有提交过一样。 -->
$ git push -f # 强制提交回滚操作

# 其它回滚操作
$ git revert
```

## 撤销一次合并 merge

1. 查看 merge 操作的上一个版本号
2. git reset --hard 版本号 回滚到 merge 之前的状态

- 示例

误将 dev 合并到了 master 分支，现要回滚 merge 操作
⑴ 首先 git reflog
ee0ee93 HEAD@{0}: merge dev: Merge made by the ‘recursive’ strategy.
7335548 HEAD@{1}: checkout: moving from dev to master
可以看到需要回滚到 7335548 这个提交记录上

⑵ 执行 git reset –hard 7335548
再次查看提交记录：
7335548 HEAD@{0}: reset: moving to 7335548
ee0ee93 HEAD@{1}: merge dev: Merge made by the ‘recursive’ strategy.

## 回滚 commit

```sh
# 只Reset最后一次commit
git reset --mixed HEAD^

# Reset最后2次commit
git reset --mixed HEAD~2

# 依次类推，Reset最后N次commit
git reset --mixed HEAD~N

# 如果可以丢弃commit内容，可以直接使用 --hard 参数替换 --mixed
```
