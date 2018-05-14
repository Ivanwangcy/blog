# Pull Request

fork 别人的仓库后，需要进行拉请求操作，更新和提交到远程仓库。

1.  把 fork 的仓库克隆到本地进行修改

```sh
$ git clone https://github.com/xxxx/xxx.git # 克隆到本地
$ cd xxx # 进入仓库根目录
$ git remote # 输出 ogrin
$ git remote -v # 列出仓库来源的 URL
# origin	https://github.com/xxx/xxx.git (fetch)
# origin	https://github.com/xxx/xxx.git (push)
```

2.  添加一个远程仓库，用于同步内容，引用 fork 的原仓库地址：`git remote add <shortname> <url>`

```sh
git remote add originUpstream https://github.com/xx.git

# 实际的例子演示
$ git remote add ar https://github.com/enaqx/awesome-react.git

# 这时再使用 git remote -v 会多出两个链接
> git remote -v
# ar	https://github.com/enaqx/awesome-react.git (fetch)
# ar	https://github.com/enaqx/awesome-react.git (push)
# origin	https://github.com/Ivanwangcy/awesome-react.git (fetch)
# origin	https://github.com/Ivanwangcy/awesome-react.git (push)
```

3.  更新远程仓库，从引用的 fork 源仓库地址同步内容

```sh
$ git remote update ar
```

4.  直接从远程仓库的分支 pull(拉取) 数据

```sh
git pull ar master
```

5.  基于远程仓库的分支进行 rebase(变基) 操作

```sh
git rebase ar/master
```

6.  本地已修改数据，提交到自己 fork 的仓库

```sh
$ git push origin master
```

7.  在线上(github)自己的仓库中，新建一个 Pull Request，等待远程仓库接收
