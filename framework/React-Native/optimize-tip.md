# React Native 开发性能优化

## 减少无效render
  * 利用 shouldComponentUpdate 生命周期进行处理

如下面的demo中，当新的 props.event.id 与当前的 props.event.id 相等时，不重新render.

```js

class Base extends Component {
    shouldComponentUpdate(nextProps) {
        return this.props.event.id !== nextProps.event.id;
    }
    // other code
}


```

* 使用 PureComponent

PureComponent 会在 shouldComponentUpdate 对数据进行浅比较，当数据相同时，返回false.

* 避免将所有的 props 都传递给子组件，尽量只传递子组件需要的props.

如在使用PureComponent进行浅比较时，组件自身所需要的props没有发生变化,却因为其它无用props导致重新渲染。

## 无状态组件使用函数式组件替代

React会面向这种无状态的组件进行一些专门的优化，比如避免无意义的检查或内存分配。所以建议大家尽可能在项目中使用无状态组件，而如果使用无状态组件，建议使用函数式的方式去定义。

```js
function Base(props) {
    return (<h1>Hello, {props.name}</h1>)
}
```

##  采用 inlineRequire 的方案，实现按需加载

预先定义模块对象，赋值为null，在使用时候判断对象是否为null，如果为null，则做真正的require，进行模块加载。

```js

export default class Base extends Component {
    someEvent = () => {
        SomeComponent = require('../SomeComponent')
    }
}

```

## 数组动态创建的子组件的情况，为每个子组件添加唯一的key属性值


Keys可以在某些元素被增加或删除的时候帮助React识别哪些元素发生了变化。

因此应当给数组中的每一个元素赋予一个确定的标识，这影响React的diff算法的复杂度

## 图片优化


1.对图片的大小压缩,服务端下发适合控件大小的图片，避免下发过大的图片

2.ios中适时调用清除图片缓存的API(列表滑动、页面返回,tab切换等)

## 避免一次性过多渲染数据

FlatList 设置 initialNumToRender, 最好刚刚够填满一个屏幕，这样保证了用最短的时间给用户呈现可见的内容.

## 属性传递优化

1. 函数传递优化

避免在组件的props中使用bind(this)或者使用匿名函数，这会导致每次render，都会创建一个新函数，这样即使数据本身没有发生变化，组件的props被改变，导致重新渲染。

不好的写法:
```js
class Base extends Component {
    handlePress(e) {
        //code
    }
    render() {
        return (
            <View>
                <Button onPress={() => {alert('按钮')}}>按钮1</JDButton>
                <Button onPress={this.handlePress.bind(this)}>按钮2</JDButton>
            </View>
        )
    }
}
```

good

在contsrutor中对进行统一绑定，或使用箭头函数

```js
class Base extends Component {
    constructor() {
        super();
        this.showMore = this.showMore.bind(this);
    }
    showMore(e) {
        //code
    }
    handlePress = (e) => {
        //code
    }
    render() {
        return (
            <View>
                <Button onPress={this.handlePress}>按钮</JDButton>
                <Button onPress={this.showMore}>按钮</JDButton>
            </View>
        )
    }
}
```
 
