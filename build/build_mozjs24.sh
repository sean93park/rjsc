#!/bin/bash
# nsprpub
cd $RJSC_HOME
cd out/nsprpub
make -j4
# js24
cd $RJSC_HOME
cd out/mozjs24
make -j4
cd $RJSC_HOME

