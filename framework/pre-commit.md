# pre-commit

提交代码钩子函数库，可以配置提交前先执行的 npm 命令。

[pre-commit github 地址](https://github.com/observing/pre-commit)

## 用法

```sh
# package.json

...

    "pre-commit": {
        "run": [
            "build"
        ],
        "silent": false,
        "colors": true
    }
```
