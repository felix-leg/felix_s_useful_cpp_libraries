#!/usr/bin/bash


mkdir -p "build-text"
cd "build-text"
cmake -G Ninja "../packs/text/"
ninja
./the_test
return $?
