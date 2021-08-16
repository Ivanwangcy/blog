# 生成 SSH 密钥并绑定 GitHub

mac 终端命令输入：

```sh
ssh-keygen -t rsa -C ‘xx@xx.com’
```

授权到 github

```sh
ssh -T git@github.com
```

github 设置SSH key 的位置：头像下拉选项->Setting->SSH and GPG keys -> new SSH key
将文件全部内容复制到github: `/Users/xxx/.ssh/id_rsa.pub`
