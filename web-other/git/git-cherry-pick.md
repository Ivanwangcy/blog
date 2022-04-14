# git cherry-pick 用法

可以随意挑选一个提交记录，合并到其他分支。

```sh
# 摘取多个提交记录
$ git cherry-pick A^..B
```

单个commit只需要git cherry-pick commitid

多个commit 只需要git cherry-pick commitid1..commitid100

注意，不包含第一个commitid ， 即  git cherry-pick (commitid1..commitid100]

```sh
# 一个提交
$ git cherry-pick e3a3a034e
# 多个提交
$ git cherry-pick ba51861..023sb6f299849a1f
```
