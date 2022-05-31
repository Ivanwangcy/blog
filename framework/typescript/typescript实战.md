# Type Script 实战

- 深入编译原理：如何把 TypeScript 编译为 JavaScript

## 装饰器

使用装饰器可以是代码更清晰，封装复杂逻辑对外提供简单的接口。

## 枚举

枚举在什么情况下使用

## 命名空间


## 常见问题解决方案

```js
delete item.value
// TS Error: The operand of a 'delete' operator must be optional.ts(2790)

// 解决方案： 
 delete (item as any).value

```

## 配置信息