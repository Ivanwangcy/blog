## Mocha 测试框架

### 首先全局安装 Mocha 框架

```sh
npm install mocha -g
```

### 新建测试目录和文件

```sh
mkdir test && cd test && touch test.js
```

测试脚本

```js
describe("描述1", function() {
  describe("描述2", function() {
    it("测试用例描述", function() {
      // 测试用例脚本，测试库的使用
      // assert.equal(-1, [1, 2, 3].indexOf(4)/* 填空题 */) // 只要不是 1，2，3 中的值，都可以通过测试用例
    });
  });
});
```

### Mocha 中使用断言库 -- assert 库

```js
var assert = require("assert");

assert.equal(-1, [1, 2, 3].indexOf(4) /* 填空题 */); // 只要不是 1，2，3 中的值，都可以通过测试用例
```

### Mocha 中使用断言库 -- should 库

```sh
$ npm i -D should
```

创建 mocha 配置文件 test/mocha.opts

```sh
--require should
```

使用 should 测试库

```js
describe("大数相加add方法", function() {
  it('字符串"42329"加上字符串"21532"等于"63861"', function() {
    add("42329", "21532").should.equal("63861");
  });

  it('"843529812342341234"加上"236124361425345435"等于"1079654173767686669"', function() {
    add("843529812342341234", "236124361425345435").should.equal(
      "1079654173767686669"
    );
  });
});
```
