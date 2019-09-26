# 用commitlint规范团队的git提交信息

## 安装commitlint

```js
npm install --save-dev  @commitlint/cli
```

## 安装husky

husky是一个git hook的管理工具，实现了大部分的git hook，有兴趣的可以自行google。


```sh
npm install --save-dev husky
```

在package.json中配置husky. hooks

```json
		"hooks": {
			"pre-commit": "lint-staged",
			"commit-msg": "commitlint -E HUSKY_GIT_PARAMS"
		}
	},
```

## 常用配置

.commitlintrc.js

```js
module.exports = {
  parserPreset: {
    parserOpts: {
      headerPattern: /^(\w*)(?:\((.*)\))?:[ ]?(.*)$/,
      headerCorrespondence: ['type', 'scope', 'subject']
    }
  },
  rules: {
    'type-empty': [2, 'never'],
    'type-case': [2, 'always', 'lower-case'],
    'subject-empty': [2, 'never'],
    'type-enum': [2, 'always', [
      'feat',
      'fix',
      'docs',
      'style',
      'refactor',
      'test',
      'chore',
    ]]
  }
}

```
## Commit message格式

```sh
type(scope?): subject  #scope is optional
```
### type
用于说明 commit 的类别，只允许使用下面7个标识。

* `feat`：新功能（feature）
* `fix`：修补bug
* `docs`：文档（documentation）
* `style`： 格式（不影响代码运行的变动）
* `refactor`：重构（即不是新增功能，也不是修改bug的代码变动）
* `test`：增加测试
* `chore`：构建过程或辅助工具的变动

如果 `type` 为 feat 和 fix，则该 commit 将肯定出现在 `Change log` 之中。

### subject

subject 是 commit 目的的简短描述，不超过50个字符，且结尾不加句号（.）。

注意冒号后面有空格。

## 提交示例

```sh
git commit -m "fix: xx bug"
git commit -m "style: xx update"

git commit -m "chore: run tests on travis ci"
git commit -m "fix(server): send cors headers"
git commit -m "feat(blog): add comment section"

...

```
