#This is free and unencumbered software released into the public domain.
#
#Anyone is free to copy, modify, publish, use, compile, sell, or
#distribute this software, either in source code form or as a compiled
#binary, for any purpose, commercial or non-commercial, and by any
#means.
#
#In jurisdictions that recognize copyright laws, the author or authors
#of this software dedicate any and all copyright interest in the
#software to the public domain. We make this dedication for the benefit
#of the public at large and to the detriment of our heirs and
#successors. We intend this dedication to be an overt act of
#relinquishment in perpetuity of all present and future rights to this
#software under copyright law.
#
#THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
#EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
#MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
#IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
#OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
#ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
#OTHER DEALINGS IN THE SOFTWARE.
#
#For more information, please refer to <https://unlicense.org>
#
param([string]$name='')

#New-Item build-$name -ItemType Directory -ea 0
#cd build-$name

cd packs/$name

conan install . --build=missing -s build_type=Debug
ls
cmake --preset conan-default -G "Visual Studio 17 2022" #-G Ninja
ctest --build-and-test . build/Debug --build-generator "Visual Studio 17 2022" #Ninja
cd build/Debug
ctest --output-on-failure

#cmake -DCMAKE_BUILD_TYPE=Debug -S ../packs/$name/
#ctest --build-and-test ../packs/$name/ . --build-generator Ninja
#	Ninja Multi-Config
#	Visual Studio 18 2026
#ctest --output-on-failure #-C Debug
#if ($LASTEXITCODE -ne 0) {
#	cat compile_result.txt
#}
#tree
return $LASTEXITCODE

