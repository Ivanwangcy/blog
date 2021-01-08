# git 分支

## 创建分支

```bash
<<<<<<< HEAD
git branch testing # 新建一个 testing 分支
```

## 操作分支

```
* 查看分支：git branch

* 创建分支：git branch <name>

# * 切换分支：
$ git checkout <name>

# * 创建+切换分支：

$ git checkout -b <name>

```

=======
$ git branch testing 新建一个 testing 分支

$ git branch -b testing # 创建分支并切换到创建的分支
```

>>>>>>> master
## 查看分支

```bash
$ git branch
  iss53
* master
  testing
<<<<<<< HEAD
```

注意看 master 分支前的`*`字符：它表示当前所在的分支。
=======
  ```
注意看 master 分支前的` * `字符：它表示当前所在的分支。
>>>>>>> master

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
<<<<<<< HEAD
# 删除分支 testing
$ git branch -d testing

# 删除远程分支
git push origin --delete dev20181018
```

## 直接删除远程分支

```sh
// 例如 删除远程分支名 branch
$ git push origin :branch
To git@github.com:xxx/xxx.git
- [deleted] branch
=======
$ git branch -d testing // 删除分支 testing
$ git push origin :testing // 提交远程分支，同步删除
>>>>>>> master
```

## 其它 相关参考

```bash
git rebase # 变基
git merge # 合并
```

## 提交分支

```bash
git push origin gh-pages
```
