# localStorage 和 sessionStorage 区别

## localStorage 和 sessionStorage 无痕模式处理

```js
var sessionStorageEnabled = false;
try {
    sessionStorage.setItem('1', '1');
    sessionStorageEnabled = true;
} catch (e) {

}
var localStorageEnabled = false;
try {
    localStorage.setItem('1', '1');
    localStorageEnabled = true;
} catch (e) {


}
/**
 * 替换sessionStorage
 * 替换目的： 防止iPhone Safari无痕模式使用本地存储时报错；统一进行JSON.stringify()序列化，减少使用时的代码输入
 */
var sessionstore = {
    data: {},
    getItem: function (key) {
        if (sessionStorageEnabled) {
            return JSON.parse(sessionStorage.getItem(key)=='undefined' ? '{}':sessionStorage.getItem(key));
        } else {
            return sessionstore.data[key];
        }
    },
    setItem: function (key, value) {
        if (sessionStorageEnabled) {
            sessionStorage.setItem(key, JSON.stringify(value));
        } else {
            sessionstore.data[key] = value;
        }
    },
    removeItem: function (key) {
        if (sessionStorageEnabled) {
            sessionStorage.removeItem(key);
        } else {
            delete sessionstore.data[key];
        }
    }
};
var localstore = {
    data: {},
    getItem: function (key) {
        if (localStorageEnabled) {
            return JSON.parse(localStorage.getItem(key));
        } else {
            return localstore.data[key];
        }
    },
    setItem: function (key, value) {
        if (localStorageEnabled) {
            localStorage.setItem(key, JSON.stringify(value));
        } else {
            localstore.data[key] = value;
        }
    },
    removeItem: function (key) {
        if (localStorageEnabled) {
            localStorage.removeItem(key);
        } else {
            delete localstore.data[key];
        }
    }
};
export {
    sessionstore,
    localstore
}

```