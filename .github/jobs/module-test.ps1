param([string]$name='')

New-Item build-$name -ItemType Directory -ea 0
cd build-$name
cmake -DCMAKE_BUILD_TYPE=Debug -S ../packs/$name/
ctest


