# git blame 查找修改者
该命令可以显示出文件中每一行的作者。
```bash
$ git blame -- README.md  # 指定文件查找
$ git blame -n -- README.md  # -n 显示行号
$ git blame -e -- README.md  # -e 显示邮箱
```
