# Decorators 装饰器模式
装饰器用于包装一个函数。
```javascript
function caculate(times){
  let num = 0;
  while(num < times) num++;
  console.log(num);
}

function log(fn){
  return function(...args){
    const start = Date.now();
    fn(...args);
    const used = Date.now()-start;
    console.log(`call ${fn.name}(${args}) used ${used} ms`);
  };
}

var decorators = log(caculate);
decorators(1000);
decorators(10000);

```
