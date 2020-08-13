# git merge 合并

```bash
$ git checkout other # 切换分支
$ git merge master # 将master分支合并到当前分支, master 分支不变

$ git checkout master # 切到主干分支
$ git merge other # 将其他分支合并到主干分支中
```

## 合并为一次提交记录

正常的 merge 会自动合并，加上 --squash 可以合并成一次性的提交记录 --注：squash(压缩)

```sh
# 合并分支为一次提交，需要重新 commit
$ git merge --squash <分支名>
```
