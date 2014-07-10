#!/bin/bash
cd $RJSC_HOME
mkdir -p $RJSC_OUT/libuv
cd $RJSC_OUT/libuv
../../lib/libuv/configure --prefix=/opt/js $RJSC_CFG_HOSTTARGET
cd $RJSC_HOME

