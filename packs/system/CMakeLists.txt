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
cmake_minimum_required(VERSION 3.5...4.0.0)
# C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(System VERSION 0.1.0 LANGUAGES CXX)

find_package(Boost 1.83 COMPONENTS unit_test_framework REQUIRED)
enable_testing()

include("../system_detect.cmake")

#the library
add_library(tested_lib
	"src/memory.hpp" "src/memory.cpp"
	"src/recycle.hpp" "src/recycle.cpp"
	"src/info.hpp" "src/info.cpp"
)
target_include_directories(tested_lib PRIVATE "${CMAKE_SOURCE_DIR}/src")
target_compile_options(tested_lib PRIVATE "-Wall")
set_target_env_options(tested_lib)
if(LINUX)
	find_package(PkgConfig REQUIRED)
	pkg_search_module(GIO2 REQUIRED "gio-2.0")
	pkg_search_module(GOBJ2 REQUIRED "gobject-2.0")
	
	target_link_libraries(tested_lib ${GIO2_LIBRARIES} ${GOBJ2_LIBRARIES})
	target_link_directories(tested_lib PRIVATE ${GIO2_LIBRARY_DIRS} ${GOBJ2_LIBRARY_DIRS})
	target_link_options(tested_lib PRIVATE ${GIO2_LDFLAGS} ${GOBJ2_LDFLAGS})
	
	target_include_directories(tested_lib PRIVATE ${GIO2_INCLUDE_DIRS} ${GOBJ2_INCLUDE_DIRS})
	target_compile_options(tested_lib PRIVATE ${GIO2_CFLAGS} ${GOBJ2_CFLAGS})
endif()
target_sources(tested_lib PRIVATE FILE_SET "incl" TYPE HEADERS
	FILES
	"src/enable_fast_GPU.hpp"
)

#the test
add_executable(the_test "test/os_test.cpp")
target_link_libraries(the_test PRIVATE tested_lib Boost::unit_test_framework)
target_compile_options(the_test PRIVATE "-Wall")
set_target_env_options(the_test)

add_test(NAME "main_test" COMMAND "the_test")
add_test(NAME "build_test"
	COMMAND
		"${CMAKE_COMMAND}"
		--build "${CMAKE_BINARY_DIR}"
		--target "the_test"
)
set_tests_properties("main_test" PROPERTIES DEPENDS "build_test")
