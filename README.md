rjsc
======
Rubus Javascript console for Raspiberry Pi

- Simple javascript console made from spidermonkey and libuv

### how to build

* run setenv for settings environment variables
```
$ . /build/setenv
```
* building test helloworld to check cross compilation for raspberry pi
```
$ cd test/helloworld
$ make
$ scp helloworld rpi@IP_ADDR_RPI:/home/pi/.
$ ssh pi@IP_ADDR_RPI
$ ./helloworld
```

* build libuv
```
TBD
```
* build spidermonkey
```
TBD
```





