#!/bin/bash
cd $RJSC_HOME
cd test/libuv/teststdio
mkdir -p out
cd out
cmake ..
make
#cd $RJSC_HOME
ls -al

