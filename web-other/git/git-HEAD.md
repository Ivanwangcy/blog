## git 提交历史分支指向
```sh
# 切换自定义分支
$ git checkout master # 最新的分支
$ git checkout other # 其它分支

# 切换到标签分支
$ git checkout V2.0 # 创建好的 标签名称

# 切换历史分支
$ git checkout HEAD # 无变化，HEAD 代表当前分支
$ git checkout HEAD^ # 当前分支的上一个分支（上一次提交历史）
$ git checkout HEAD~1 # 当前分支的上一个分支（上一次提交历史） 同上
$ git checkout HEAD~2 # 当前分支的前两个分支（倒数第三次提交历史）
$ git checkout HEAD~3 # 当前分支的前三个分支（倒数第四次提交历史）
$ git checkout HEAD~<num> # 当前分支的前n个分支（倒数第n次提交历史）以此类推

```
