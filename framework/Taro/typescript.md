# 配置 TypeScript

[[翻译] TypeScript 和 JSX 搞基的事](https://github.com/techird/blog/issues/3)


## 安装

```sh
npm i @typescript-eslint/parser typescript
```

## 配置 lint

.eslintrc

```json

{
  "extends": ["taro"],
  "rules": {
    "no-unused-vars": ["error", { "varsIgnorePattern": "Taro" }],
    "react/jsx-filename-extension": [1, { "extensions": [".js", ".jsx", ".tsx"] }],
    "jsx-quotes": ["error", "prefer-double"]
  },
  "parser": "@typescript-eslint/parser",
  "parserOptions": {
    "ecmaFeatures": {
      "jsx": true
    },
    "useJSXTextNode": true,
    "project": "./tsconfig.json"
  }
}

```
tsconfig.json

```sh
{
  "compilerOptions": {
      "target": "es2017",
      "module": "commonjs",
      "removeComments": false,
      "preserveConstEnums": true,
      "moduleResolution": "node",
      "experimentalDecorators": true,
      "noImplicitAny": false,
      "allowSyntheticDefaultImports": true,
      "outDir": "lib",
      "noUnusedLocals": true,
      "noUnusedParameters": true,
      "strictNullChecks": true,
      "sourceMap": true,
      "baseUrl": ".",
      "rootDir": ".",
      "jsx": "preserve",
      "jsxFactory": "Taro.createElement",
      "allowJs": true,
      "resolveJsonModule": true,
      "typeRoots": [
        "node_modules/@types"
      ]
  },
  "exclude": [
    "node_modules",
    "dist"
  ],
  "compileOnSave": false
}


```

## value! 非空验证
