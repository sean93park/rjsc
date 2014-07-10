#!/bin/bash
# nsprpub
cd $RJSC_HOME
cd $RJSC_OUT/nsprpub
make -j4
# js24
cd $RJSC_HOME
cd $RJSC_OUT/mozjs24
make -j4
cd $RJSC_HOME

