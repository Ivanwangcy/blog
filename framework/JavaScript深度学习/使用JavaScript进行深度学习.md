# 使用 JavaScript 进行深度学习

为了打造智能化前端，JavaScript 深度学习是前端必知必会的技能。

前端工程师怎么做深度学习，自己设计人工智能的算法模型还是应用成熟的算法模型。

有了深度学习，JavaScript 开发者可以让我们的 Web 应用程序更加智能。

 TensorFlow 的应用案例：

 <https://github.com/tensorflow/tfjs>

 <https://www.tensorflow.org/js/?hl=zh_cn>

## 深度学习的介绍

深度学习相关概念：人工智能、机器学习、深度学习之间的关系。（这些基本概念是非常重要的）

自从2012年产生了一场深度学习革命，使深度神经网络在各方面得到了极速发展，被广泛应用。产生了很多深度学习库，比较成熟的 TensorFlow。

机器学习是人工智能的子领域。人工智能的一些领域采用了与机器学习不同的策略，如符号人工智能。神经网络是机器学习的子领域。机器学习中也存在非神经网络的技术，如决策树。相较于浅层神经网络（具有较少层的神经网络），深度学习是创造与应用深层神经网络（具有大量层的神经网络）的科学与艺术。

人工智能是在某种程度上显示出类似于人类智能的设备。人工智能有许多种技术实现，其中一个子集就是机器学习——让算法在数据中学习。深度学习是机器学习的一个子集，使用多层神经网络来解决最困难的计算机问题。


## 为什么使用 Javascript

使用 JavaScript 的价值和潜力。

## JavaScript 的优势

## 用 convnet 识别图像和音频

### 从向量到张量：图像数据的表示方法

向量 - 一维张量 (TensorFlow 的名字源自张量)
矩阵 - 二维张量
模型 将输入的特征映射到输出目标上的函数。

### 如何理解模型

### 神经网络

神经网络是受人脑神经元连接方式启发而发明出来的一种美妙算法。


## TensorFlow.js 实战

TensorFlow.js 是一个全面、灵活且强大的Javascript 开源深度学习库。


以实战的方式深入了解机器学习。

学习任务的“回归”，预测一个数字。

预测问题是 TensorFlow 的强项 。


### 示例1：使用TensorFlow.js预测细下载任务所需时间

机器学习的整体流程：

获取训练集 -> 将数据转换成张量 -> 创建模型 -> 使用模型拟合数据 -> 针对新数据应用模型

代码清单：

其中包含20个样例，文件大小与下载所需时间一一对应（如：第一个元素0.080MB -> 0.135秒）

```html
<script src='https://cdn.jsdelivr.net/npm/@tensorflow/tfjs@latest'></script>

<script>
const trainData = {
  sizeMB:  [0.080, 9.000, 0.001, 0.100, 8.000, 5.000, 0.100, 6.000, 0.050, 0.500,
            0.002, 2.000, 0.005, 10.00, 0.010, 7.000, 6.000, 5.000, 1.000, 1.000],
  timeSec: [0.135, 0.739, 0.067, 0.126, 0.646, 0.435, 0.069, 0.497, 0.068, 0.116,
            0.070, 0.289, 0.076, 0.744, 0.083, 0.560, 0.480, 0.399, 0.153, 0.149]
};
const testData = {
  sizeMB:  [5.000, 0.200, 0.001, 9.000, 0.002, 0.020, 0.008, 4.000, 0.001, 1.000,
            0.005, 0.080, 0.800, 0.200, 0.050, 7.000, 0.005, 0.002, 8.000, 0.008],
  timeSec: [0.425, 0.098, 0.052, 0.686, 0.066, 0.078, 0.070, 0.375, 0.058, 0.136,
            0.052, 0.063, 0.183, 0.087, 0.066, 0.558, 0.066, 0.068, 0.610, 0.057]
};
console.log(testData.timeSec);
console.log(testData.sizeMB);
  
</script>

```

```js

// 训练集 
const trainData = {
      // 文件大小 
      sizeMB: [
        0.080, 9.000, 0.001, 0.100, 8.000, 5.000, 0.100, 6.000, 0.050, 0.500, 0.002, 2.000, 0.005, 10.00, 0.010, 7.000, 6.000, 5.000, 1.000, 1.000
      ]，
      // 下载文件所需时间
      timeSec: [
        0.135, 0.739, 0.067, 0.126, 0.646, 0.435,0.069, 0.497, 0.068, 0.116, 0.070, 0.289, 0.076, 0.744,0.083,0.560, 0.480, 0.399,0.153,0.149
      ]
  }

  // 测试集
  const testData = {
      sizeMB: [
        5.000, 0.200, 0.001, 9.000, 0.002, 0.020, 0.008, 4.000, 0.001, 1.000, 0.005, 0.080, 0.800, 0.200, 0.050, 7.000, 0.005, 0.002, 8.000, 0.008
      ]，
      timeSec: [
    0.425, 0.098, 0.052, 0.686, 0.066, 0.078, 0.070, 0.375, 0.058, 0.136,0.052, 0.063, 0.183, 0.087, 0.066, 0.558, 0.066, 0.068, 0.610, 0.057
    ]
  }
  
```

### 增加点状图表展示

使用点状图表绘制数据，展示变化趋势。

### 将数据转换成张量

```js
    trainXs = tf.tensor2d(trainData.sizeMB, [20, 1]);
    trainYs = tf.tensor2d(trainData.timeSec, [20, 1]);
    testXs = tf.tensor2d(testData.sizeMB, [20, 1]);
    testYs = tf.tensor2d(testData.timeSec, [20, 1]);
```

### 构建线性回归模型

```js
const model = tf.sequential();
model.add(tf.layers.dense({inputShape: [1], units: 1}))
```

具体代码示例：参考链接：<https://codepen.io/bileschi/pen/JaOOpO>

```js
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8"/>
    <meta content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no, viewport-fit=cover" name="viewport"/>
    <script src='https://cdn.jsdelivr.net/npm/@tensorflow/tfjs@latest'></script>
    <script src="https://cdn.plot.ly/plotly-latest.min.js"></script>
  </head>

<body>
    <p> Simple plot of hardcoded input data <p>
    <div id="dataSpace" class="plots"></div>


  <script>
    const trainData = {
      sizeMB:  [0.080, 9.000, 0.001, 0.100, 8.000, 5.000, 0.100, 6.000, 0.050, 0.500,
                0.002, 2.000, 0.005, 10.00, 0.010, 7.000, 6.000, 5.000, 1.000, 1.000],
      timeSec: [0.135, 0.739, 0.067, 0.126, 0.646, 0.435, 0.069, 0.497, 0.068, 0.116,
                0.070, 0.289, 0.076, 0.744, 0.083, 0.560, 0.480, 0.399, 0.153, 0.149]
    };
    const testData = {
      sizeMB:  [5.000, 0.200, 0.001, 9.000, 0.002, 0.020, 0.008, 4.000, 0.001, 1.000,
                0.005, 0.080, 0.800, 0.200, 0.050, 7.000, 0.005, 0.002, 8.000, 0.008],
      timeSec: [0.425, 0.098, 0.052, 0.686, 0.066, 0.078, 0.070, 0.375, 0.058, 0.136,
                0.052, 0.063, 0.183, 0.087, 0.066, 0.558, 0.066, 0.068, 0.610, 0.057]
    };
    console.log(testData.timeSec);
    console.log(testData.sizeMB);
      
    trainXs = tf.tensor2d(trainData.sizeMB, [20, 1]);
    trainYs = tf.tensor2d(trainData.timeSec, [20, 1]);
    testXs = tf.tensor2d(testData.sizeMB, [20, 1]);
    testYs = tf.tensor2d(testData.timeSec, [20, 1]);

    ////
    // Data Markers
    ////
    const dataTraceTrain = {
      x: trainData.sizeMB,
      y: trainData.timeSec,
      name: 'trainData',
      mode: 'markers',
      type: 'scatter',
      marker: {symbol: "circle", size: 8}
    };
    const dataTraceTest = {
      x: testData.sizeMB,
      y: testData.timeSec,
      name: 'testData',
      mode: 'markers',
      type: 'scatter',
      marker: {symbol: "triangle-up", size: 10}
    };


    Plotly.newPlot('dataSpace', [dataTraceTrain, dataTraceTest], {
      width: 700,
      title: 'File download duration',
      xaxis: {
        title: 'size (MB)'
      },
      yaxis: {
        title: 'time (sec)'
      }
    });
  </script>
</body>
</html>
```


