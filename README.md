# clang-study

c言語の勉強

## Docker で C言語を動作させる

``` terminal
$ docker build -t alpine:exec-c .
$ docker run -v "$PWD"/sample_program:/home --rm -ti alpine:exec-c
6a333c246e82:# cd /home
6a333c246e82:# gcc hello.c
6a333c246e82:# ./a.out
Hello world
```
