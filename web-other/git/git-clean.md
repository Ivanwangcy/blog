# git clean
清除未在版本控制的文件。
```bash
$ git clean -n # 列出将要被清除的文件和目录
$ git clean -f # 清除文件
$ git clean -df # 清除文件和目录

# 与 git checkout -f 结合使用
$ git checkout -f # 还原已经修改的文件（未加入暂存区，未提交的）
```
## Oh-my-zsh alias
```sh
$ gclean  # 等于 git clean -fd
```
