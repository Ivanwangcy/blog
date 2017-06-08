# alias 别名
```sh
# 设置别名
$ git config --global alias.st "status"
$ git config --global alias.aa "add --all"
$ git aa  <==> git add --all
$ git config --global alias.cm "commit -m"
$ git config --global alias.acm "commit -am"
$ git config --global alias.p "push"
$ git config --global alias.l "pull"

# 删除别名设置
$ git config --global --unset alias.gaa
```
