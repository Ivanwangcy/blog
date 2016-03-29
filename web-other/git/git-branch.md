# git 分支
## 创建分支
```bash
$ git branch testing 新建一个 testing 分支
```
## 查看分支
```bash
$ git branch
  iss53
* master
  testing
  ```
注意看 master 分支前的` * `字符：它表示当前所在的分支。
## 合并分支
```bash
$ git checkout master // 切到 master
$ git merge iss53  // 合并 iss53 分支
/////////
Auto-merging README
Merge made by the 'recursive' strategy.
 README | 1 +
 1 file changed, 1 insertion(+)
```
## 遇到冲突时的分支合并
## 删除分支
```bash
$ git branch -d testing // 删除分支 testing
```
## 其它 相关参考
```bash
$ git rebase # 变基
$ git merge # 合并
```
