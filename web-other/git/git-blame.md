# git blame 查找修改者
该命令可以显示出文件中每一行的作者。可以快速定位某块代码是谁修改的。
```bash
$ git blame -- README.md  # 指定文件查找
$ git blame -n -- README.md  # -n 显示行号
$ git blame -e -- README.md  # -e 显示邮箱

# 查找指定行号的修改记录
$ git blame -L <start>[,<end>] # 结束行号可以不写，默认为文件结尾
$ git blame -L 10,15 -n -- branches\\webapp\\v1.1\\html\\new\\app\\view\\Settlement.js # 查看10-15行的修改记录
```
