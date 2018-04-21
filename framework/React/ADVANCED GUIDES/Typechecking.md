# 使用 PropTypes 进行类型检查

> Note:
> 自 React v15.5 以后，React.PropTypes 已经进入了一个不同的包。请改用 prop-types 库。
> React 官方提供了一个 `[codemod script](https://reactjs.org/blog/2017/04/07/react-v15.5.0.html#migrating-from-reactproptypes)` 来自动化转换。

随着您的应用程序的增长，您可以通过类型检查来捕捉大量错误。对于某些应用程序，您可以使用JavaScript扩展（如Flow或TypeScript）来检查整个应用程序。但即使你不使用这些，React也有一些内置的类型检测功能。要在组件的道具上运行类型检查，可以指定特殊的 `propTypes` 属性：

## PropTypes