# alias 别名
```sh
# 设置别名
$ git config --global alias.st "status"
$ git config --global alias.aa "add --all"
$ git aa  <==> git add --all
$ git config --global alias.c "commit -v"
$ git config --global alias.cmsg "commit -m"
$ git config --global alias.cam "commit -am"
$ git config --global alias.cm "checkout master"
$ git config --global alias.p "push"
$ git config --global alias.l "pull"
$ git config --global alias.cl "config --list"
$ git config --global alias.count "shortlog -sn"
$ git config --global alias.lg "log --stat --color"
$ git config --global alias.lgg "log --graph --color"
$ git config --global alias.lgga "log --graph --decorate --all"
$ git config --global alias.lgm "log --graph --max-count=10"
$ git config --global alias.lgp "log --stat --color -p"

# 删除别名设置
$ git config --global --unset alias.gaa
```
