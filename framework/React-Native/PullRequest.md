## Pull Request Code
- 首先 `fork` 官方代码
- clone 自己 fork 后的仓库
```sh

# 克隆自己的仓库
$ git clone https://github.com/Ivanwangcy/react-native.git

# 查看远程仓库来源标识
$ git remote -v
# facebook	https://github.com/facebook/react-native.git (fetch)
# facebook	https://github.com/facebook/react-native.git (push)
# origin	https://github.com/Ivanwangcy/react-native.git (fetch)
# origin	https://github.com/Ivanwangcy/react-native.git (push)

# 拉去最新修改
$ git remote update facebook

# 合并到自己的仓库 master 分支
$ git pull facebook master

# 最新代码提交到自己仓库
$ git push
```
