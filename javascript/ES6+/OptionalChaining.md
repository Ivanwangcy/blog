# ES2020 链判断运算符

OptionalChaining


```js

const firstName = message?.body?.user?.firstName ?? 'default';



```

## babel 插件

- 安装依赖：

```js
@babel/plugin-proposal-optional-chaining // 可选链
@babel/plugin-proposal-nullish-coalescing-operator // 双问号
```

- 插件配置：

然后在.babelrc或者babel.config.js中这加入2个插件(plugins属性放在JSON顶层)：

```js

{
 "plugins": [
    "@babel/plugin-proposal-nullish-coalescing-operator",
    "@babel/plugin-proposal-optional-chaining"
  ]
}

```

参考链接：

>> https://www.cnblogs.com/teamemory/p/12531958.html

>> https://es6.ruanyifeng.com/?search=%E9%93%BE&x=0&y=0#docs/object#%E9%93%BE%E5%88%A4%E6%96%AD%E8%BF%90%E7%AE%97%E7%AC%A6


