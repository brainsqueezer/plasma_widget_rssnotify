#!/bin/sh

KDEDIR=`kde4-config --prefix`
cmake . -DCMAKE_INSTALL_PREFIX=$KDEDIR
