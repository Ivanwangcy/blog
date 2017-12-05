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

  // 属性
  horizontal={this.state.horizontal}
  alwaysBounceVertical={false}
  overScrollMode={'never'}
  bounces={false} // 禁用 滚动头尾 回弹效果
  scrollEnabled={true}
  refreshing={false}
/>
```
