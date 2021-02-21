# form 表单

## Form 表单的属性:

-   action 表单提交地址;
-   method get/post;
-   enctype 默认为 application/x-www-form-urlencoded , 上传文件时使用 multipart/form-data;
-   target 提交到指定容器, 指向一个 iframe 的 name;

## input text

```html
<input
    type="text"
    name="userName"
    placeholder="请输入您的姓名"
    maxlength="10"
    required
/>
```

## input number

```html
<input
    name="age"
    type="number"
    max="199"
    min="0"
    step="2"
    maxlength="3"
    pattern="/\d+/"
    placeholder="请输入您的年龄"
/>
```

## input file

```html
<!-- 多选 -->
<input class="f-hidden" type="file" name="images" id="upload-images" multiple />
```
