## git checkout
## git discard change
```bash
# 撤销 某个文件的修改
$ git checkout  -- branches/webapp/v1.1/html/new/lib/common/utility.js

$ git checkout -f # 强制撤销当面所有修改（新增文件除外）

$ git checkout master    # 取出master版本的head。
$ git checkout tag_name    # 在当前分支上 取出 tag_name 的版本
$ git checkout  master -- file_name  # 放弃当前对文件file_name的修改
$ git checkout  commit_id -- file_name  # 取文件file_name的 在commit_id是的版本。commit_id为 git commit 时的sha值。
$ git checkout master -- file_name1 file_name2 file_name3 # ... 检出多个文件使用 空格分割
$ git checkout master -- dir_name # 检出一个路径下的所有文件
$ git checkout -- hello.js # 撤销文件修改
# 这条命令把hello.rb从HEAD中签出.
```
