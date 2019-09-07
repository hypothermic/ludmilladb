#!/bin/sh

rm -rf ./build
rm ./src/ludmilladb

mkdir -p ./build
glib-compile-resources --generate-source --target ./build/res.gresource.c ./res/res.gresource.xml
./autogen.sh
autoreconf -i
./configure
make
./src/ludmilladb
make maintainer-clean