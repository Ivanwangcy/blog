# 唤起 App 协议问题

## 目前问题：

Android 系统不能正常唤起客户端，目前测试到的有三星 note3, s5 以上版本默认浏览器，使用现有协议无法打开 app，如果用户未安装 app 则会跳转一个错误页面。其它高版本的手机也会有这个问题。现有协议使用的是 scheme，Android 和 iPhone 通用。iPhone 手机目前未发现问题。

## 问题原因：

Android 平台默认浏览器（Chrome），从 25 及以后版本不再支持通过 JS 触发（非用户点击），设置 iframe src 地址等来触发 scheme 跳转。

## 解决方案：

Android 提供了更智能的 Intent 协议，使用这种协议可以解决上述问题。如果手机能匹配到相应的 APP，则会直接打开，如没有安装，则会跳到手机默认的应用商店。intent 比 scheme 相对完善的一点是，提供一个打开失败去向的 URL 选项。
参考链接： https://developer.chrome.com/multidevice/android/intents  
chrome 25 以上版本使用：intent:开头的协议可以解决。

## 注意：

**希望提供一个 intent 协议与 H5 进行联调，评估一下会有哪些问题：是否影响埋点统计，有多大工作量，对以前版本有没有影响。。。**

## 开心消消乐打开 app 的示例(它不支持在微信中打开)

```javascript
var mobileAppInstall = (function () {
    var ua = navigator.userAgent;
    var redirectTimeout;

    function getChromeIntent(url, fallback_url) {
        return (
            "intent://xxl.happyelements.com#Intent" +
            ";scheme=" +
            url +
            ";package=com.happyelements.AndroidAnimal" +
            ";S.browser_fallback_url=" +
            encodeURIComponent(fallback_url) +
            ";end"
        );
    }

    var appInstall = {
        isChrome: ua.match(/Chrome\/([\d.]+)/) || ua.match(/CriOS\/([\d.]+)/),
        isAndroid: ua.match(/(Android);?[\s\/]+([\d.]+)?/),
        timeoutDuration: 500,
        iosVersion: iOSversion(),
        chromeVersion: chromeVersion(),
        /**
         * 尝试跳转appurl,如果跳转失败，进入h5url
         * @param {Object} appurl 应用地址
         * @param {Object} h5url  http地址
         */
        open: function (appurl, h5url) {
            try {
                appInstall.addTimeout(h5url);
                appInstall.openApp(appurl);
                redirectHelp = false;
                $("help").onclick = function () {
                    appInstall.openApp(appurl, h5url);
                };
            } catch (e) {}
        },
        openApp: function (appurl) {
            setTimeout(function () {
                appInstall.openAppByFrame(appurl);
                if (appInstall.iosVersion && appInstall.iosVersion[0] >= 9) {
                    window.location = appurl;
                }
                if (
                    appInstall.isChrome &&
                    appInstall.isAndroid &&
                    appInstall.chromeVersion &&
                    appInstall.chromeVersion > 18
                ) {
                    window.location = appurl;
                }
            }, appInstall.timeoutDuration);
        },
        openH5: function (h5url) {
            dc.redirect(h5url, true);
        },
        openAppByFrame: function (appurl) {
            var iframe = document.createElement("iframe");
            iframe.style.display = "none";
            iframe.style.border = "none";
            iframe.style.width = "1px";
            iframe.style.height = "1px";
            iframe.src = appurl;
            document.body.appendChild(iframe);
        },
        openInChrome: function (appurl, h5url) {
            location.replace(getChromeIntent(appurl, h5url));
        },
        addTimeout: function (h5url) {
            var begin = Date.now();
            var redirectTimeoutDuration = appInstall.timeoutDuration + 500;
            redirectTimeout = setTimeout(function () {
                if (appInstall.iosVersion && appInstall.iosVersion[0] >= 9) {
                    if (Date.now() - begin < redirectTimeoutDuration + 100) {
                        return;
                    }
                }
                h5url && appInstall.openH5(h5url);
            }, redirectTimeoutDuration);
            window.addEventListener(
                "pagehide",
                function () {
                    clearTimeout(redirectTimeout);
                },
                false
            );
            window.addEventListener(
                "blur",
                function () {
                    clearTimeout(redirectTimeout);
                },
                false
            );
        },
    };
    return appInstall;
})();
```
