# 操作cookie
```javascript
/*
 * 用途 ：获取指定名称的cookie的值
 * 调用 ：util.getCookie(name)
 * 参数 ：name —— 参数名字
 * return 存值
 */
function getCookie(objName){
    var arrStr = document.cookie.split("; ");
    for(var i = 0;i < arrStr.length;i ++){
        var temp = arrStr[i].split("=");
        if(temp[0] == objName) return decodeURIComponent((temp[1]||'').trim());
    }
    return '';
}
/*
 * 用途 ：添加 cookie
 * 调用 ：util.getCookie(name,value,time)
 * 参数 ：name —— 键名 , value —— 键值 , time —— 时间
 */
function addCookie(name,value,age_of_hours){
    var str = name + "=" + encodeURIComponent(value) + ";path=/;";
    if(arguments.length>2){
        str += "Max-Age=" + age_of_hours * 3600;
    }
    document.cookie = str;
}
/*
 * 用途 ：删除cookie
 * 调用 ：util.delCookie(name)
 * 参数 ：name —— 键名
 */
function delCookie(name){
    document.cookie = name + "=;path=/;Max-Age=-1";
}
```
