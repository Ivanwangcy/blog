# AppState

`AppState` 可以告诉您应用程序是在前台还是后台，并在状态发生变化时通知您。

AppState 经常用于确定处理推送通知时的行为和正确进入的行为。

## App States

* active - App 在前台运行；
* background - 该应用程序在后台运行。用户可能在：
  * 另一个应用程序；
  * 主屏幕上；
  * [Android]在另一个Activity上（即使它是由你的应用推出的）
* inactive - 在前台和后台之间转换以及在不活动区间（例如进入多任务视图或在来电时）发生的状态

有关更多信息，请参阅[Apple的文档](https://developer.apple.com/library/archive/documentation/iPhone/Conceptual/iPhoneOSProgrammingGuide/TheAppLifeCycle/TheAppLifeCycle.html)

