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

if(CMAKE_HOST_WIN32)
	list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../cmake")
endif()

set(HOST_DEF "")
set(HOST_ARCH "")

if(CMAKE_HOST_APPLE)
	set(HOST_DEF "APP_SYSTEM_IS_MACOS")
endif()
if(CMAKE_HOST_LINUX)
	set(HOST_DEF "APP_SYSTEM_IS_LINUX")
endif()
if(CMAKE_HOST_WIN32)
	set(HOST_DEF "APP_SYSTEM_IS_MSWIN")
endif()

if(CMAKE_SIZEOF_VOID_P EQUAL "8")
	set(HOST_ARCH "APP_ARCH_IS_64BIT")
else()
	set(HOST_ARCH "APP_ARCH_IS_32BIT")
endif()

set(COMPILER_DEF "")
set(COMPILER_FLAGS "")

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	set(COMPILER_DEF "APP_COMPILER_IS_GCC")
	set(COMPILER_FLAGS "-Wall;-Wextra")
endif()
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	set(COMPILER_DEF "APP_COMPILER_IS_CLANG")
	set(COMPILER_FLAGS "-Wall;-Wextra")
endif()
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	set(COMPILER_DEF "APP_COMPILER_IS_MSVC")
	set(COMPILER_FLAGS "/permissive;/W4;/utf-8;/wd5030")
endif()

function(set_target_env_options Target)
	target_compile_definitions(${Target} PRIVATE ${HOST_DEF} ${COMPILER_DEF} ${HOST_ARCH})
	target_compile_options(${Target} PRIVATE "${COMPILER_FLAGS}")
endfunction()

function(register_test Name Cmd)
	set(Cfg "")
	set(Prefix "")
	if(CMAKE_HOST_WIN32)
		set(Cfg "--config Debug")
		set(Prefix "Debug\\")
	endif()
	add_test(NAME "main_${Name}" COMMAND "${Prefix}${Cmd}")
	add_test(NAME "build_${Name}"
		COMMAND
			"${CMAKE_COMMAND}"
			--build "${CMAKE_BINARY_DIR}"
			--target "${Cmd}"
			${Cfg}
	)
	set_tests_properties("main_${Name}" PROPERTIES DEPENDS "build_${Name}" )
endfunction()

