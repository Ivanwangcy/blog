# React Native 颠覆原生, 跨平台新趋势
[官方教程](https://facebook.github.io/react-native/docs/getting-started.html)

## Dependencies for Mac + iOS
You will need Xcode, node.js, the React Native command line tools, and Watchman.  
We recommend installing node and watchman via `Homebrew`.
```sh
brew install node
brew install watchman
```
Node comes with npm, which lets you install the React Native command line interface.
```sh
npm install -g react-native-cli
```
If you get a permission error, try with sudo: `sudo npm install -g react-native-cli`.

If you get error Cannot find module 'npmlog', try this before: `curl -0 -L http://npmjs.org/install.sh | sudo sh`.

The easiest way to install Xcode is via the `Mac App Store`.

## Testing your React Native Installation
Use the React Native command line tools to generate a new React Native project called "AwesomeProject", then run `react-native run-ios` inside the newly created folder.
```sh
react-native init AwesomeProject
cd AwesomeProject
react-native run-ios
```
You should see your new app running in the iOS Simulator shortly. react-native run-ios is just one way to run your app - you can also run it directly from within Xcode or Nuclide.

## Modifying your app
Now that you have successfully run the app, let's modify it.

- Open `index.ios.js` in your text editor of choice and edit some lines.
- Hit `Command⌘ + R`in your iOS Simulator to reload the app and see your change!
## That's it!
Congratulations! You've successfully run and modified your first React Native app.
## Mac + Android
# 
 #
