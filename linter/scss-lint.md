## scss-lint
安装
1- 安装 homebrew;
2- `brew install ruby`
3- `[sudo] gem install scss_lint`
4- Atom editor install `apm install linter-scss-lint`

## 配置文件 .scss-lint.yml

## Automated Migration

```sh
If you have many instances of division, you may want to take a look at the automatic migration tool provided by Sass, as thoughtfully pointed out by @Andreas in the comments.

# Install the tool globally using npm
npm install -g sass-migrator
# Run the codemod on all .scss files recursively from the working directory
sass-migrator division **/*.scss

# OR

# Use npx to install temporarily and immediately run (similar to above)

```

```sh
npx --yes sass-migrator division **/*.scss
```
