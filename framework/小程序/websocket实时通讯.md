# 微信小程序通过websocket实现实时语音识别

> 之前在研究百度的实时语音识别，并应用到了微信小程序中，写篇文章分享一下。


先看看完成的效果吧

前置条件

申请百度实时语音识别key  百度AI接入指南


创建小程序

设置小程序录音参数

在index.js中输入

yaml 代码解读复制代码  const recorderManager = wx.getRecorderManager()
  const recorderConfig = { 
    duration: 600000, 
    frameSize: 5, //指定当录音大小达到5KB时触发onFrameRecorded
    format: 'PCM', 
    //文档中没写这个参数也可以触发onFrameRecorded的回调，不过楼主亲测可以使用
    sampleRate: 16000, 
    encodeBitRate: 96000, 
    numberOfChannels: 1 
  }

使用websocket连接
javascript 代码解读复制代码  linkSocket() {
    let _this = this
    //这里的sn是百度实时语音用于排查日志，这里我图方便就用时间戳了
    let sn = new Date().getTime()
    wx.showLoading({
      title: '识别中...'
    })
    recorderManager.start(recorderConfig)
    //开启链接
    wx.connectSocket({
      url: 'wss://vop.baidu.com/realtime_asr?sn=' + sn,
      protocols: ['websocket'],
      success() {
        console.log('连接成功')
        _this.initEventHandle()
      }
    })
  },

  //监听websocket返回的数据
  initEventHandle() {
    let _this = this
    wx.onSocketMessage((res) => {
      let result = JSON.parse(res.data.replace('\n',''))
      if(result.type == 'MID_TEXT'){
        _this.tran(result.result, 'value')
        _this.setData({
          textDis: 'none',
          value: result.result,
        })
      }
      if(result.type == 'FIN_TEXT'){
        let value = _this.data.text
        let tranStr = value + result.result
        _this.tran(tranStr, 'text')
        _this.setData({
          value: '',
          valueEn: '',
          textDis: 'block',
          text: tranStr,
        })
      }
    })
    wx.onSocketOpen(() => 
      //发送数据帧
      _this.wsStart()
      console.log('WebSocket连接打开')
    })
    wx.onSocketError(function (res) {
      console.log('WebSocket连接打开失败')
    })
    wx.onSocketClose(function (res) {
      console.log('WebSocket 已关闭！')
    })
  },

发送开始、音频数据、结束帧
javascript 代码解读复制代码  wsStart() {
    let config = {
      type: "START",
      data: {
        appid: XXXXXXXXX,//百度实时语音识别appid
        appkey: "XXXXXXXXXXXXXXXXXX",//百度实时语音识别key
        dev_pid: 15372,
        cuid: "cuid-1",
        format: "pcm",
        sample: 16000
      }
    }
    wx.sendSocketMessage({
      data:JSON.stringify(config),
      success(res){
        console.log('发送开始帧成功')
      }
    })
  },

  wsSend(data){
    wx.sendSocketMessage({
      data:data,
      success(res){
        console.log('发送数据帧成功')
      }
    })
  },

  wsStop(){
    let _this = this
    this.setData({
      click: true,
    })
    let config = {
      type: "FINISH"
    }
    wx.hideLoading()
    recorderManager.stop()
    wx.sendSocketMessage({
      data:JSON.stringify(config),
      success(res){
        console.log('发送结束帧成功')
      }
    })
  },

小程序录音回调
javascript 代码解读复制代码  onShow: function () {
    let _this = this
    recorderManager.onFrameRecorded(function (res){
      let data = res.frameBuffer
      _this.wsSend(data)
    })

    recorderManager.onInterruptionBegin(function (res){
      console.log('录音中断')
      _this.wsStopForAcc()
    })

    recorderManager.onStop(function (res){
      console.log('录音停止')
    })
  },
  
  wsStopForAcc(){
    let _this = this
    this.setData({
      click: true,
    })
    let config = {
      type: "FINISH"
    }
    wx.sendSocketMessage({
      data:JSON.stringify(config),
      success(res){
        wx.hideLoading()
        console.log('发送结束帧成功')
      }
    })
  },

作者：yiyou12138
链接：https://juejin.cn/post/6862523847012024334
来源：稀土掘金
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

<https://juejin.cn/post/6862523847012024334>

