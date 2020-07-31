# Taro 动态注入 reducer

## reducerInjectors.js

```js
import invariant from 'invariant';
import isEmpty from 'lodash/isEmpty';
import isFunction from 'lodash/isFunction';
import isString from 'lodash/isString';

import checkStore from './checkStore';
import createReducer from '../reducers';
import { history } from '../configureStore';

export function injectReducerFactory(store, isValid) {
  return function injectReducer(key, reducer) {
    if (!isValid) checkStore(store);

    invariant(
      isString(key) && !isEmpty(key) && isFunction(reducer),
      'injectReducer: Expected `reducer` to be a reducer function'
    );

    // Check `store.injectedReducers[key] === reducer` for hot reloading when a key is the same but a reducer is different
    if (
      Reflect.has(store.injectedReducers, key) &&
      store.injectedReducers[key] === reducer
    ) {
      return;
    }

    store.injectedReducers[key] = reducer; // eslint-disable-line no-param-reassign
    store.replaceReducer(createReducer(history, store.injectedReducers));
  };
}

export default function getInjectors(store) {
  checkStore(store);

  return {
    injectReducer: injectReducerFactory(store, true)
  };
}

```

## injectReducer.js

```js
import React from 'react';
// import PropTypes from 'prop-types';
import hoistNonReactStatics from 'hoist-non-react-statics';

import getInjectors from './reducerInjectors';
import store from '../configureStore';

/**
 * Dynamically injects a reducer
 *
 * @param {string} key A key of the reducer
 * @param {function} reducer A reducer that will be injected
 *
 */
export default ({ key, reducer }) => WrappedComponent => {
  const getWrappedComponentName = () => {
    if (WrappedComponent.displayName) {
      const reg = /\b(\w*)\)*$/;
      const displayName = reg.exec(WrappedComponent.displayName)[1];
      return displayName;
    }

    return WrappedComponent.name || 'Component';
  };

  class ReducerInjector extends React.Component {
    static WrappedComponent = WrappedComponent;

    static displayName = getWrappedComponentName(WrappedComponent);

    componentWillMount() {
      const { injectReducer } = this.injectors;
      injectReducer(key, reducer);
    }

    injectors = getInjectors(store);

    render() {
      return <WrappedComponent {...this.props} />;
    }
  }

  return hoistNonReactStatics(ReducerInjector, WrappedComponent);
};

```
