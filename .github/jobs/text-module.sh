#!/usr/bin/bash

git_home="$1"

mkdir -p "$git_home/build/text"
cd "$git_home/build/text"
cmake -G Ninja "$git_home/packs/text/"
ninja
./the_test
return $?
