# FS API

## watchFile 用法（usage）

```js
//  读取/监听文件内容变化
fs.watchFile(

  // The name of the file to watch
  "example_file.txt",
  
  // The options parameter is used to 
  //modify the behaviour of the method
  {
    // Specify the use of big integers
    // in the Stats object 
    bigint: false,
  
    // Specify if the process should 
    // continue as long as file is
    // watched
    persistent: true,
  
    // Specify the interval between
    // each poll the file
    interval: 4000,
  },
  (curr, prev) => {
    console.log("\nThe file was edited");
  
    // Show the time when the file was modified
    console.log("Previous Modified Time", prev.mtime);
    console.log("Current Modified Time", curr.mtime);
  
    console.log(
      "The contents of the current file are:",
      fs.readFileSync("example_file.txt", "utf8")
    );
    res.write(fs.readFileSync("example_file.txt", "utf8"))
  }
);
  
// Make Changes to the file for the first time
fs.writeFileSync("example_file.txt",
   "File Contents are Edited");
  
// Make Changes to the file for the second time
setTimeout(
  () => fs.writeFileSync("example_file.txt",
          "File Contents are Edited Again"),
  5000
);
```