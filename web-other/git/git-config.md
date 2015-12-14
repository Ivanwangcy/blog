#git配置
git config [–local|–global|–system] -l

--local 仓库级别的
--global 全局的
--system 系统级别的

```shell
$ git config --global user.name "John Doe"    //配置用户名
$ git config --global user.email johndoe@example.com    //配置邮箱
$ git config --global credential.helper store   //保存密码
$ git config --global --list  //查看配置信息
```
