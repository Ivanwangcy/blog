# git 配置

```bash
git config [–-local|–-global|–-system] -l
```

--local 仓库级的<br>
--global 全局级的<br>
--system 系统级的

```bash
$ git config --global user.name "John Doe"    //配置用户名
$ git config --global user.email johndoe@example.com    //配置邮箱
$ git config --local user.name "John Doe"    //配置用户名
$ git config --local user.email johndoe@example.com    //配置邮箱
$ git config --global credential.helper store   //保存密码
$ git config --global --list  //查看配置信息
$ git config --local -l  //查看当前配置信息
```

## 查看配置信息

```sh
#查看全部配置信息, 重复的变量名采用最后一个
$ git config --list
$ git config --local --list

#查看指定的配置信息, 直接输入变量名
$ git config user.name
```

## 删除配置项

```bash
$ git config --global --unset configname
```
