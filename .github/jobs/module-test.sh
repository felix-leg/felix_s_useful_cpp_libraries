#!/usr/bin/bash

name="$1"

mkdir -p "build-$name"
cd "build-$name"
cmake -G Ninja "../packs/$name/"
ninja
#./the_test
ctest
exit $?
