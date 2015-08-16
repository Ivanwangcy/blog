#todoMVC演示
##Todos应用程序的架构, 需如下功能：
* 描述单 todo 项的 Todo 模型；
* 存储和持久化 todo 项的 TodoList 集合；
* 创建 todo 项；
* 展示 todo 列表；
* 编辑现有 todo 项；
* 标记一个 todo 项完状态（completed）；
* 删除一个 todo 项；
* 过滤所有已完成（或未完成）todo 列表；
```html
    <div class="todoapp">
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
    <div id="credits">
      Created by Ivan
      <br>
    </div>
```
