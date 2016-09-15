# Write a Dockerfile
```sh
# Make a new directory by typing following command and pressing `return`
$ mkdir mydockerbuild && cd $_

# Create a Dockerfile in the directory by typing `touch Dockerfile` and pressing RETURN.
$ touch Dockerfile
$ vim Dockerfile

```
## Check your work, your file should look like this:
```sh
FROM docker/whalesay:latest
RUN apt-get -y update && apt-get install -y fortunes
CMD /usr/games/fortune -a | cowsay
```
## Now build your new images:
```sh
$ docker build -t docker-whale .
```
## Run your new docker-whale
```sh
$ docker run docker-whale
```
