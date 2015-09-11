#git 分支
##创建分支
```shell
$ git branch testing 新建一个 testing 分支
```
##查看分支
```shell
$ git branch
  iss53
* master
  testing
  ```
注意看 master 分支前的` * `字符：它表示当前所在的分支。
##合并分支
```shell
$ git checkout master
$ git merge iss53
/////////
Auto-merging README
Merge made by the 'recursive' strategy.
 README | 1 +
 1 file changed, 1 insertion(+)
```
##遇到冲突时的分支合并
##删除分支
