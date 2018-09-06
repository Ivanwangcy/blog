# SectionList

## scrollToLocation()

section list 没有 ScrollToTop 方法可以使用它来模拟一个：

```js
try {
  this.refs.sectionList.scrollToLocation({
    animated: true / false, // 是否使用动画
    sectionIndex: 0,
    itemIndex: 0,
    viewPosition: 0,
    viewOffset: 0
  });
} catch (err) {}
```

## getItemLayout()

为了提高 SectionList 性能，需要设置 `getItemLayout`。

## 获取可视区域的组件

使用这个方法可以监听可视区域的变化 `onViewableItemsChanged`，对此做出一些性能优化。