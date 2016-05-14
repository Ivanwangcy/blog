# React.js Fundamentals Curriculum React 基础全部课程
## 课程简介
- 了解更多React程序信息。[click here](http://reactjsprogram.com/)
- 课程源码地址：https://github.com/ReactjsProgram/react-fundamentals-curriculum
## 课程目标
创建一个基于[天气预报API](http://openweathermap.org/api)的天气APP。
## 预备知识
- Declarative 声明式编程
－ Unidirectional Dateflow 单向数据流
－ Composition 组合
－ Explicit Mutations 显性变化
－ "It's just javascript" 它只是 javascript
### React 使用声明式函数编程 (declarative)
- 特点：
  1. 减少副作用；(Reduce Side Effects)
  2. 减少可变性；(Minimize Mutability)
  3. 代码更具可读性；(More Readable Code)
  4. 更少的Bug; (Less Bugs)
与命令式函数的区别：[声明式编程和命令式编程的比较](http://web.jobbole.com/42178/)
```javascript

// Imperative (How) 如何去做，关注怎样实现
var numbers = [1,8,7,2,6,3];
var total = 0;
for (var i = 0; i < numbers.length; i++) {
  total += numbers[i];
}

// declarative (What) 想要什么，关注结果，让计算机处理过程
var numbers = [1,8,7,2,6,3];
var total = numbers.reduce(function(previous, current){
  return previous + current;
});
```
###  回调函数使用 `bind(this)`
```javascript
var listItems = this.props.items.map(function(item, index){
  return (
    <li style={styles.listGroup}>
      <button style={styles.removeItem}
        onClick={this.props.remove.bind(null, index)}
        />
      <span>
        {item}
      </span>
    </li>
  )
}.bind(this)); // 改变 this 指向，指定上下文为当前对象
```
## `React` 开发环境集成
* React
* React Router
* Webpack
* Babel
* Axios

### React Router
```javascript
  <Router history={hashHistory}>
    <Route path="/" component={Main} />
    <IndexRoute component={Home} />
    <Route path="playerOne" header="Player One" component={PromptContainer} />
    <Route path="playerTwo/:playerOne" component={PromptContainer} />
    <Route path="battle" component={ConfirmBattleContainer} />
    <Route path="results" component={ResultsContainer} />
  </Router>
```
### Webpack
Webpack 配置文件 `webpack.config.js`
```javascript
var HtmlWebpackPlugin = require('html-webpack-plugin');
var HtmlWebpackPluginConfig = new HtmlWebpackPlugin({
  template: __dirname + '/app/index.html',
  filename:'index.html',
  inject: 'body'
});

module.exports = {
  entry: {
    './app/index.js'
  },
  output: {
    path: __dirname + '/dist',
    filename: 'index_bundle.js'
  },
  module: {
    loaders: {
      {
        test: /\.js$/,
        include: __dirname + '/app',
        loader: 'babel-loader'
      },
      {
        test: /\.css$/,
        loader: "style-loader!css-loader"
      }
    }
  },
  plugins: [
    HtmlWebpackPluginConfig
  ]
};
```
### Babel
Babel 配置文件 `.babelrc`
```javascript
{
  presets: [
    'es2015',
    'react'
  ]
}
```
### Axios
HTTP Requests API 类似于 jQuery.Ajax
```javascript
function getRepos(username){
  return axios.get('https://api.github.com/users/' + username + '/repos' + param + '&per_page=100');
}
```
