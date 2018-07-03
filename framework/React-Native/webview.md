# WebView 组件

利用 WebView 组件实现 H5 与 RN 交互功能。

```js
onMessage = event => {
  // 监听 H5 消息获取数据
  let stringData = event.nativeEvent.data;
  let messageData;
  try {
    messageData = JSON.parse(stringData);
    if (messageData.title) {
      this.setState({
        title: messageData.title
      })
    }
  } catch (e) { }
};

// 插入脚本，获取 H5 title 示例
let getTitleCode =
  Platform.OS == 'ios'
    ? 'window.postMessage(JSON.stringify({title: document.title}))'
    : '__REACT_WEB_VIEW_BRIDGE.postMessage(JSON.stringify({title: document.title}))';
let code = `
    setTimeout(
      function(){
        ${getTitleCode}
    }, 200);
  `;

<WebView
  injectedJavaScript={code}
  source={{ uri: args }}
  style={styles.webViewContainer}
  onMessage={this.onMessage}
  automaticallyAdjustContentInsets={false}
  messagingEnabled={true}
  onError={() => {
    this.setState({
      error: true
    });
  }}
/>
```