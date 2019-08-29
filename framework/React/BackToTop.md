# 回到顶部的组件

```js
import React, { Component } from 'react';
import styles from './BackToTop.module.scss';
import { Tween_Quad_easeInOut } from '../../../common/lib/Tween';

const raf =
    window.requestAnimationFrame ||
    window.webkitRequestAnimationFrame ||
    function(callback) {
        window.setTimeout(callback, 1000 / 60);
    };

export default class BackToTop extends Component {
    constructor(props) {
        super(props);
        this.state = {
            visible: false
        };

        this.setScrollTop(0);
    }

    scrollEvent = undefined;

    setVisible = visible => {
        this.setState({ visible });
    };
    getCurrentScrollTop = () => {
        const targetNode = this.props.target();
        if (targetNode === window) {
            return (
                window.pageYOffset || document.body.scrollTop || document.documentElement.scrollTop
            );
        }
        return targetNode.scrollTop;
    };

    scrollToTop = e => {
        const scrollTop = this.getCurrentScrollTop();
        const startTime = Date.now();
        const frameFunc = () => {
            const timestamp = Date.now();
            const time = timestamp - startTime;
            this.setScrollTop(Tween_Quad_easeInOut(time, scrollTop, 0, 250));
            // console.log('====================================');
            // console.log('scrollToTop', time);
            // console.log('====================================');
            if (time < 300) {
                raf(frameFunc);
            } else {
                this.setScrollTop(0);
            }
        };
        raf(frameFunc);
        this.props.onClick(e);
    };

    setScrollTop(value) {
        const targetNode = this.props.target();
        if (targetNode === window) {
            document.body.scrollTop = value;
            document.documentElement.scrollTop = value;
            if (value == 0) {
                setTimeout(() => {
                    document.body.scrollTop = value;
                    document.documentElement.scrollTop = value;
                }, 0);
            }
        } else {
            targetNode.scrollTop = value;
        }
    }

    handleScroll = () => {
        const { visibilityHeight } = this.props;
        const scrollTop = this.getCurrentScrollTop();
        this.setVisible(scrollTop > visibilityHeight);
    };

    componentDidMount() {
        this.scrollEvent = this.props.target().addEventListener('scroll', this.handleScroll);
        this.handleScroll();
    }

    componentWillUnmount() {
        if (this.scrollEvent) {
            this.scrollEvent.remove();
        }
    }
    render() {
        const { style } = this.props;
        const { visible } = this.state;

        return (
            <div
                className={styles.backTop}
                onClick={this.scrollToTop}
                style={{ ...style, display: visible ? 'block' : 'none' }}
            />
        );
    }
}

BackToTop.defaultProps = {
    visibilityHeight: 500,
    onClick: () => {},
    target: () => window
};

```
## 缓动动画

```js
    animationSlide(timer, begin, end, cb) {
        let start = 0; // 开始时间
        const duration = 15; //持续时间
        const change = (end ? end : 0) - begin; // 变化量
        const run = () => {
            timer && clearTimeout(timer);
            if (start < duration) {
                start++;
                var top = Math.ceil(Tween_Linear(start, begin, change, duration));
                timer = setTimeout(run, 15);
            } else {
                start = duration;
                clearTimeout(timer);
            }
            cb && top && cb(top);
        };
        run();
    }
```
