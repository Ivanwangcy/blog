# node-sass and Nodejs 6.0

## Error: Missing binding
node_modules/node-sass/vendor/darwin-x64-48/binding.node. 1no suitable image found. Did find:
node_modules/node-sass/vendor/darwin-x64-node-0.12/binding.node: truncated mach-o error: segment \_\_TEXT extends to 864256 which is past end of file 179563  

## Found bindings for the following environments:  
- OS X 64-bit with Node.js 6.x
This usually happens because your environment has changed since running npm install.  

## Steps to solve problem
> Run `npm rebuild node-sass` to build the binding for your current environment.
