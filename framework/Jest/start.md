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

将以下部分添加到package.json：

```json
{
  "scripts": {
    "test": "jest"
  }
}
```

最后，运行 `npm test`，Jest 将打印此消息：

```sh
PASS  ./sum.test.js
✓ adds 1 + 2 to equal 3 (5ms)
```

你刚刚使用 Jest 成功编写了第一个测试！

该测试使用expect和toBe来测试两个值完全相同。要了解Jest可以测试的其他内容，请参阅 `[Using Matchers](https://jestjs.io/docs/en/using-matchers)`。


[http://www.cnblogs.com/Wolfmanlq/p/8012847.html](http://www.cnblogs.com/Wolfmanlq/p/8012847.html)