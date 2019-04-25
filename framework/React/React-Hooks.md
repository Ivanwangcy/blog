# React Hooks

16.8 正式版发布以后，增加了 Hook 功能，可以投入生产中了。 Hook 是 React 16.8 中的新增功能。它允许我们在不编写类的情况下使用 state 和其他 React 功能。（貌似可以替代高阶组件）

## 用法

### useState 状态钩子
```js
import React, { useState } from 'react';

function Example() {
  // Declare a new state variable, which we'll call "count"
  const [count, setCount] = useState(0);

  return (
    <div>
      <p>You clicked {count} times</p>
      <button onClick={() => setCount(count + 1)}>
        Click me
      </button>
    </div>
  );
}
```

### useEffect
```js
import React, { useState, useEffect } from 'react';

function Example() {
  const [count, setCount] = useState(0);

  useEffect(() => {
    document.title = `You clicked ${count} times`;
  });

  return (
    <div>
      <p>You clicked {count} times</p>
      <button onClick={() => setCount(count + 1)}>
        Click me
      </button>
    </div>
  );
}
```
## 应用
