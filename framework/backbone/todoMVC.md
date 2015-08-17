# todoMVC演示
## Todos应用程序的架构, 需如下功能：
* 描述单 todo 项的 Todo 模型；
* 存储和持久化 todo 项的 TodoList 集合；
* 创建 todo 项；
* 展示 todo 列表；
* 编辑现有 todo 项；
* 标记一个 todo 项完状态（completed）；
* 删除一个 todo 项；
* 过滤所有已完成（或未完成）todo 列表；

## 静态HTML
### HTML头部
```html
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width,initial-scale=1.0">
    <title>Backbone.js Todos</title>

    <!-- CSS -->
    <link rel="stylesheet" href="css/todos.css" media="screen" title="no title" charset="utf-8">
  </head>
```
### 应用程序HTML代码
```html
    <div id="todoapp">
      <header>
        <h1>Todos</h1>
        <input id="new-todo" type="text" name="name" placeholder="What needs to be done?">
      </header>
      <section id="main">
        <input id="toggle-all" type="checkbox" name="name">
        <label for="toggle-all">Mark all as complete</label>
        <ul id="todo-list"> </ul>
      </section>
      <footer>
        <a id="clear-completed">Clear completed</a>
        <div id="todo-count"> </div>
      </footer>

    </div>
    <div id="instructions">
      Double-click to edit a todo.
    </div>
    <div id="credits">
      Created by Ivan
      <br>
    </div>
```
###JavaScript脚本
```html
  <!-- Scripts -->
    <script src="lib/underscore.js" charset="utf-8"></script>
    <script src="lib/zepto.js" charset="utf-8"></script>
    <script src="lib/backbone.js" charset="utf-8"></script>
    <script src="lib/backbone.localStorage.js" charset="utf-8"></script>
    <script src="js/todos.js" charset="utf-8"></script>
```
###Template 模板
```html
<!-- item-template -->
    <script type="text/template" id="item-template">
      <div class="view">
        <input id="checkItem" class="toggle" type="checkbox" name="name" <%= done ? "checked" : "" %> />
        <label><%- title %></label>
        <a class="destroy"></a>
      </div>
      <input class="edit" type="text" name="name" value="<%- title %>">
    </script>

    <!-- stats-template -->
    <script type="text/template" id="stats-template">
      <% if (done) { %>
        <a id="clear-completed">Clear <%= done %> completed <%= done == 1 ? 'item' : 'items'%></a>
      <% } %>
      <div class="todo-count"><strong><%= remaining %> <%= remaining == 1 ? 'item' : 'items' %></strong>
      </div>
    </script>
```
##CSS设计
```css

```
