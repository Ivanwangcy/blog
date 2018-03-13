## 使用 Git LFS 模式上传大文件
* 安装步骤
https://github.com/git-lfs/git-lfs/wiki/Installation

* 使用教程
https://github.com/git-lfs/git-lfs/wiki/Tutorial

```sh
# 安装成功后 执行
$ git lfs install
$ git lfs track 'largefies' # 提交大文件
# 生成 .gitattributes 文件
$ git lfs track # 查看已添加的大文件

$ git add .gitattributes largefies # 添加 配置文件和大文件 or (git add .)全部添加
$ git commit -m "提交备注"
$ git push
```
