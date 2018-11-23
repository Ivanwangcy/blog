# 使用编程方式操作颜色色值

## rgb 与 hex(16进制) 色值转换

```js
let color = '#47b34f'

function hexToRGB(colorStr) {
  let color = parseInt((colorStr + '').replace('#', ''), 16);
  
  return `rgb(${color >> 16}, ${color >> 8 & 0x00ff}, ${color & 0x0000ff})`
}

let rgb = hexToRGB(color); => "rgb(71, 179, 79)"

function rgbToHex(colorStr) {
  let [r, g, b] = value.match(/\d+/g)
  
  return `#${(r << 16 | g << 8 | b).toString(16)}`;
}

let hex = rgbToHex(rgb)
```
