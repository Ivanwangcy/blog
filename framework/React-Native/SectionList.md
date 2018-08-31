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
