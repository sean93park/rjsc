#!/bin/bash
cd $RJSC_HOME
mkdir -p out/libuv
cd out/libuv
../../lib/libuv/configure --prefix=/opt/js --host=i686-pc-linux-gnu --target=arm-bcm2708hardfp-linux-gnueabi
cd $RJSC_HOME

