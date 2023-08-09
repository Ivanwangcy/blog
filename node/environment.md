# Node 环境变量配置

## windows


## MacBook OS X and Linux

1. 创建一个全局包的目录
```sh
$ mkdir "${HOME}/.npm-packages"
```
2. 指定`npm`安装全局包的存储位置。
```sh
# 创建／编辑 .npmrc 文件
$ vim ~/.npmrc

# 按键 i ，再增加如下内容 esc>:wq
prefix=${HOME}/.npm-packages
```
3. 确保 `npm install --global` 可以安装到新建的目录。再给终端配置文件`.bashrc/.zshrc` ,如：`vim ~/.zshrc`增加如下内容：
[oh-my-zsh安装](../web-other/MacBook/oh-my-zsh.md)
```sh
NPM_PACKAGES="${HOME}/.npm-packages"

PATH="$NPM_PACKAGES/bin:$PATH"

# Unset manpath so we can inherit from /etc/manpath via the `manpath` command
unset MANPATH # delete if you already modified MANPATH elsewhere in your config
export MANPATH="$NPM_PACKAGES/share/man:$(manpath)"

```
4. 使配置文件生效
```sh
$ source ~/.zshrc
```
