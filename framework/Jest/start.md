# Jest

## 安装

使用 npm 安装：

```sh
npm install --save-dev jest
```

使用 yarn 安装：

```sh
yarn add --dev jest
```

让我们开始编写一个两个数字相加的函数的测试。首先，创建一个 `sum.js` 文件：

```js
function sum(a, b) {
  return a + b;
}

// ES5 导出
module.exports = sum;

// OR ES6 导出
export default sum;
```

然后，创建一个名为 `sum.test.js` 的文件。这将包含我们的实际测试：

```js
const sum = require('./sum');

test('adds 1 + 2 to equal 3', () => {
  expect(sum(1, 2)).toBe(3);
});
```