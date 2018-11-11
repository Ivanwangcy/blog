## FlatList

基本用法

```js
state = {
  data: genItemData(30),
  debug: false,
  horizontal: false,
  filterText: '',
  fixedHeight: true,
  logViewable: false,
  virtualized: true,
};

// 滚动条动画
let handleScroll = Animated.event(
  [{
    nativeEvent: {
      contentOffset: {
        y: this.props.settle.animatedScrollY
      }
    }
  }],
  {
    useNativeDriver: true, // 如果使用 true 需要用 原生的 list, Animated.FlatList
    listener: (event, gestureState) => {
      event.persist() // 保留 nativeEvent 事件对象，加上这句 才可以获取到 nativeEvent

      if (event.nativeEvent.contentOffset.y>= 40) {
        this.props.settle.headerShow = true
      } else {
        this.props.settle.headerShow = false
      }
    }
  }
)

<FlatList
  HeaderComponent={HeaderComponent}
  FooterComponent={FooterComponent}
  SeparatorComponent={SeparatorComponent}
  data={filteredData}
  debug={this.state.debug}
  disableVirtualization={!this.state.virtualized}
  getItemLayout={this.state.fixedHeight ?
    this._getItemLayout :
    undefined
  }
  key={(this.state.horizontal ? 'h' : 'v') +
    (this.state.fixedHeight ? 'f' : 'd')
  }
  legacyImplementation={false}
  numColumns={1} // 横向排列数量，默认 1，必须高度相同设置2 时 每行显示两列元素
  onRefresh={this._onRefresh}
  onViewableItemsChanged={this._onViewableItemsChanged}
  ref={this._captureRef}
  renderItem={this._renderItemComponent}
  shouldItemUpdate={this._shouldItemUpdate}
  viewabilityConfig={VIEWABILITY_CONFIG}
  onEndReachedThreshold={1}
  onEndReached={({ distanceFromEnd }) => {
    console.log('on end reached ', distanceFromEnd)
  }}
  automaticallyAdjustContentInsets={false}
  onScroll={handleScroll}
  scrollEventThrottle={1} // Use 1 here to make sure no events are ever missed
  scrollEventThrottle={16} // 16ms 1000ms/60fps= 16ms 最佳效果，每秒钟刷新 60 次

  // 属性
  horizontal={this.state.horizontal}
  alwaysBounceVertical={false}
  overScrollMode={'never'}
  bounces={false} // 禁用 滚动头尾 回弹效果
  scrollEnabled={true}
  refreshing={false}
/>
```

## 可视区域判断
```js

  handleItemsInViewPort = ({ changed, viewableItems }) => {
    let { setCurrentActivityIndex } = this.props.fullPromotion;

    let changedItem = changed[0];
    if(changedItem.isViewable) {
      setCurrentActivityIndex(changedItem.index);
    }
    // viewableItems.forEach(item => {
      // setCurrentActivityIndex(changed);
    // });
  };

  handleItemsOutViewPort = ({ changed, viewableItems }) => {
  }

  getViewabilityConfigCallbackPairs = () => {

    return [
      {
        viewabilityConfig: {
          minimumViewTime: 500,
          viewAreaCoveragePercentThreshold: inViewAreaCoverage
        },
        onViewableItemsChanged: this.handleItemsInViewPort
      },
      {
        viewabilityConfig: {
          minimumViewTime: 500,
          // itemVisiblePercentThreshold: 100,
          viewAreaCoveragePercentThreshold: outViewAreaCoverage
        },
        onViewableItemsChanged: this.handleItemsOutViewPort
      }
    ];
  };
// 不支持 scrollToIndex
```

## NOTE 

* 可以使用 scrollToIndex 跳到指定的元素索引位置，index 跳到的条目，viewPosition 控制当前条目显示在flatList 的位置，0.5 为flatList 中间，0 为首位，1 为末位，开发过程中有个bug：componentDidUpdate 内执行scrollToIndex 最后一个元素无法跳过去，（临时解决方案，在最后面添加一个空元素占位）；

* 触底判断，正常的分页加载可以使用 onEndReached 函数监听到底加载新数据，但是如果要是触底后执行其它操作这个函数就不够准确，可以使用 onContentSizeChange 获取滚动区域的高度或者宽度，再判断滚动条当前的位置是否到达或者超出滚动区域高度。

## 性能提升
设置 `getItemLayout` 可以提升列表性能，可以指定渲染的列表项高度；
视窗大小属性设置
使用占位图可以解决白色问题
