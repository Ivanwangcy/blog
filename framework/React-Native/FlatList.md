## FlatList

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
  numColumns={1}
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
