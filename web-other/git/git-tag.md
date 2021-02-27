# git tag 打标签

## 增加标签

```bash
$ git tag -a V1.0 -m "Version 1.0"  // 新建标签并增加标签说明
$ git tag -a V2.2 8645692 -m "add tag" // 给指定版本增加标签
```

## 查看标签

```bash
$ git tag  // 查看所有标签
$ git show V2.2   // 查看标签详情
$ git tag -l "V2.*" // 列出 'V2.' 开头的标签

$ git checkout -f V2.0 # 强制更新到标签 V2.0

```

## 提交标签到远程服务器上

```bash
$ git push origin --tags
```

## 删除标签

```bash
$ git tag -d V1.0.1  # 删除标签的命令

$ git push origin :refs/tags/V1.0.1  # 删除远程服务器的标签

```
