#!/usr/bin/bash

git-home="$(cd .. && pwd)"

pwd
ls

mkdir -p "build-text"
cd "build-text"
cmake -G Ninja "$git_home/packs/text/"
ninja
./the_test
return $?
