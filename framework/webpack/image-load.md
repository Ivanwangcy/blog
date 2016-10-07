# 文件加载 url loader
配置文件增加loader项
```JavaScript
{
  test: /\.(png|jpg)$/,
  loader: 'url?limit=8192'  // a62c984802de06712d886d0a3e779603.png
  loader: 'url?limit=8192&name=images/[hash:6].[ext]' // a62c98.png
  loader: 'url?limit=192&name=icon/[name].[ext]' // filename.png
}

// 其他配置方式， 加载图片
  {
    test: /\.(png|jpg|gif|svg)$/,
    loader: 'url',
    query: {
      limit: 8192,
      name: '[name].[ext]?[hash:6]'
    }
  },
```
## 参数选项
- limit 图片大小限制在 8192 字节（8KB）及以内的，直接转换成base64编码字符串。可以根据情况任意调节大小；
- hash 文件hash值，会随着文件内容不同而变化可以指定文件名称的hash长度，如：[hash:6]6位长度的16进制编码，默认为32位16进制编码如（a62c984802de06712d886d0a3e779603.png）；
- name 文件原名输出；
- ext 文件的扩展名；
