# 创建全局弹窗的方法

## 使用 Modal

原生组件性能好一些，但是在 Android 手机上有 bug，屏幕底部到导航菜单的，例如新出的全面屏手机。

## 自定义绝对定位组件

如果在组件内部弹窗绝对定位的组件，弹出范围只能在父组件内部；

## 创建根组件的兄弟节点

```js
// 核心代码
class StaticContainer extends Component {

  static defaultProps = {
    shouldUpdate: true
  }

  static propTypes = {
    shouldUpdate: PropTypes.bool.isRequired
  }

  shouldComponentUpdate(nextProps) {
    return nextProps.shouldUpdate;
  }

  render() {
    const child = this.props.children;
    return child === null || child === false ? null : Children.only(child);
  }
}

// 在顶级容器，添加组件
AppRegistry.setWrapperComponentProvider(function() {
  return class RootSiblingWrapper extends Component {
    static displayName = 'RootSiblingWrapper';
    _sibling = null;

    constructor(props) {
      super(props);
      trigger = this._update;
    }

    componentWillUnmount() {
      trigger = null;
    }

    _update = (element, callback) => {
      if(React.isValidElement(element) || element === null) {
        this._sibling = element;
        this.forceUpdate(callback);
      }
    };

    render() {
      let sibling = this._sibling;
      return (
        <View style={styles.container}>
          <StaticContainer shouldUpdate={false}>{this.props.children}</StaticContainer>
          {sibling ? <StaticContainer shouldUpdate={true}>{sibling}</StaticContainer> : null}
        </View>
      );
    }
  };
});
```