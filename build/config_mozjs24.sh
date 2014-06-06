#!/bin/bash
# nsprpub
cd $RJSC_HOME
mkdir -p out/nsprpub
cd out/nsprpub
../../lib/mozjs24/nsprpub/configure --prefix=/opt/js \
--host=i686-pc-linux-gnu --target=arm-bcm2708hardfp-linux-gnueabi
# js24
cd $RJSC_HOME
mkdir -p out/mozjs24
cd out/mozjs24
../../lib/mozjs24/js/src/configure --prefix=/opt/js \
--disable-shared-js --enable-threadsafe \
--host=i686-pc-linux-gnu --target=arm-bcm2708hardfp-linux-gnueabi \
--with-nspr-prefix=$RJSC_HOME/out/nsprpub/dist \
--with-nspr-cflags=-I$RJSC_HOME/out/nsprpub/dist/include/nspr \
--with-nspr-libs=$RJSC_HOME/out/nsprpub/dist/lib/libnspr4.a
cd $RJSC_HOME

