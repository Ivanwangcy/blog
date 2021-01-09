# Lottie Web

web 端支持 Lottie 动画。

[源码地址](https://github.com/airbnb/lottie-web)

## 安装

```sh
npm i lottie-web
```

## React 中使用示例

```js

import lottie from 'lottie-web';

const anim = lottie.loadAnimation({
            wrapper: this.animationContainer,
            animType: 'html',
            renderer:'canvas',
            loop: true,
            prerender: true,
            autoplay: true,
            // animationData: loading  // json 数据， 与 path 二选一
            path: '/Lottie/res/WeAccept.json'// the path to the animation json 请求 json 服务器端地址，外部资源有跨域问题
        });
        
        anim.addEventListener('complete', () => {
            console.log('animation 动画播放完成');
          });
        anim.addEventListener('data_ready', () => {
            console.log('animation 数据加载完成');
          });
        
        // 动画承载组件
        <div
                    style={{ width: '100%', height: '200px', backgroundColor: '#fff', position: 'relative' }}
                    ref={component => (this.animationContainer = component)}
                />
```

## 参考教程

<https://imweb.io/topic/5b23a850d4c96b9b1b4c4efe>
