# 用commitlint规范团队的git提交信息

## 安装commitlint

```js
npm install --save-dev commitlint
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
