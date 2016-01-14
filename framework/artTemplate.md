# artTemplate 模板引擎
[artTemplate](https://github.com/aui/artTemplate)
地址：[https://github.com/aui/artTemplate](artTemplate)
## 循环参数获取: 
{{each data.menu}}
$value 循环后的对象值
$index 循环后的对象索引
{{each menuStorage as value i}}  给值和索引起别名

## 循环嵌套:
{{each data.menu}}
            <li catagoryid="{{$value.id}}" class="line-bottom {{if $index==0}}current{{/if}}">{{$value.name}}       
        {{$countFoodCatagoryTotalSelected($value)}}
       {{each menuStorage as item }} //给$value起别名, 避免覆盖上层循环 $value
            {{if item.id == $value.id}}
                 <i style="display: inline;">{{item.num}}</i>
            {{/if}}
       {{/each}}
      </li>
{{/each}}
