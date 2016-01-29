# git tag 打标签
# 增加标签
```git
$ git tag -a V1.0 -m "Version 1.0"  // 新建标签并增加标签说明
$ git tag -a V2.2 8645692 -m "add tag" // 给指定版本增加标签
```
# 查看标签
```git
$ git tag  // 查看所有标签
$ git show V2.2   // 查看标签详情
$ git tag -l "V2.*" // 列出 'V2.' 开头的标签
```
