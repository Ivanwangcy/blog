# git diff 版本比较
```shell
$ git diff  // 查看本地修改记录(未加入暂存区的修改)
$ git diff --cached // 查看暂存区的修改
$ git diff
```
## 两个版本进行比较（指定文件）
$ git diff HEAD 7917dad -- branches/webapp/v1.1/html/new/app/view/goodsDetails.js
