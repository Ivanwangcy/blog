## document title

## source url
[https://github.com/gaearon/react-document-title](https://github.com/gaearon/react-document-title)
## install
```sh
$ npm install --save react-document-title
```
## example
```js
var HomePage = React.createClass({
  render: function () {
    // Use "Home" while this component is mounted
    return (
      <DocumentTitle title='Home'>
        <h1>Home, sweet home.</h1>
      </DocumentTitle>
    );
  }
});
```
