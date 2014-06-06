rjsc
======
"Rubus Javascript Shell Cab" for Raspiberry Pi

- Simple Javascript Shell made from spidermonkey and libuv.
- Planned to be the basic building block for JavaScript programming world.
- It's in design and prototyping with simple scripts

### preparing the source
```
$ git clone git@github.com:sean93park/rjsc.git
$ cd rjsc
$ git submodule update --init
```

### how to build

* run setenv for settings environment variables
```
$ . ./build/setenv
```

* building test helloworld to check cross compilation for raspberry pi
```
$ cd test/helloworld
$ make
$ scp helloworld rpi@IP_ADDR_RPI:/home/pi/.
$ ssh pi@IP_ADDR_RPI
$ ./helloworld
```

* preparations for one time
```
$ ./build/prepare.sh
```

* configure sub modules for raspberry pi
```
$ ./build/config_libuv.sh
$ ./build/config_mozjs24.sh
```

* build libuv
```
$ ./build/build_libuv.sh
```

* build spidermonkey
```
$ ./build/build_mozjs24.sh
```





