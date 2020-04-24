# 前端获取IP地址

可以利用WebRTC(Chrome/Firefox):


```js
//创建RTCPeerConnection接口
let conn = new RTCPeerConnection({
		iceServers: []
	}) 
let noop = function(){}
conn.onicecandidate = function(ice){
	if (ice.candidate){
		//使用正则获取ip
		let ip_regex = /([0-9]{1,3}(\.[0-9]{1,3}){3}|[a-f0-9]{1,4}(:[a-f0-9]{1,4}){7})/
		let ip_addr = ip_regex.exec(ice.candidate.candidate)[1];
		console.log(ip_addr)
		conn.onicecandidate = noop
	}
}
//随便创建一个叫狗的通道(channel)
conn.createDataChannel('dog')
//创建一个SDP协议请求
conn.createOffer(conn.setLocalDescription.bind(conn),noop)
```

>>参考链接：
>>> <https://www.zhihu.com/question/20675353>
>>> <https://blog.csdn.net/aminwangaa/article/details/91879057>
