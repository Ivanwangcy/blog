# 二维码

源码地址：<https://github.com/soldair/node-qrcode>

```js
  QRCode.toDataURL(this.imgUrl, { errorCorrectionLevel: 'L' }, (_err, url) => {
    console.log(url)
    const image = new Image()
    image.src = url
    this.$refs.qrCode.innerHTML = ''
    image.width = 180
    image.height = 180
    this.$refs.qrCode.append(image)
  })
```
