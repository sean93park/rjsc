#!/bin/bash
# nsprpub
cd $RJSC_HOME
mkdir -p $RJSC_OUT/nsprpub
cd $RJSC_OUT/nsprpub
../../lib/mozjs24/nsprpub/configure --prefix=/opt/js $RJSC_CFG_HOSTTARGET
# js24
cd $RJSC_HOME
mkdir -p $RJSC_OUT/mozjs24
cd $RJSC_OUT/mozjs24
../../lib/mozjs24/js/src/configure --prefix=/opt/js \
--disable-shared-js --enable-threadsafe \
$RJSC_CFG_HOSTTARGET \
--with-nspr-prefix=$RJSC_HOME/$RJSC_OUT/nsprpub/dist \
--with-nspr-cflags=-I$RJSC_HOME/$RJSC_OUT/nsprpub/dist/include/nspr \
--with-nspr-libs=$RJSC_HOME/$RJSC_OUT/nsprpub/dist/lib/libnspr4.a
cd $RJSC_HOME

