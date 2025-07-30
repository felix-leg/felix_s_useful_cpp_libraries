/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <https://unlicense.org>

*/
#define COMPILER_HAS_BEEN_DETECTED 0

//Clang
#if (COMPILER_HAS_BEEN_DETECTED == 0) && defined(__clang__)
	#undef COMPILER_HAS_BEEN_DETECTED
	#define COMPILER_HAS_BEEN_DETECTED 1
	#define APP_COMPILER_IS_CLANG
#endif

//GCC
#if (COMPILER_HAS_BEEN_DETECTED == 0) && ( defined(__GNUC__) && !defined(__clang__) && !defined(__ICC) && !defined(__CUDACC__) && !defined(__LCC__) )
	#undef COMPILER_HAS_BEEN_DETECTED
	#define COMPILER_HAS_BEEN_DETECTED 1
	#define APP_COMPILER_IS_GCC
#endif

//MSVC
#if (COMPILER_HAS_BEEN_DETECTED == 0) && ( defined(_MSC_VER) && !defined(__clang__) )
	#undef COMPILER_HAS_BEEN_DETECTED
	#define COMPILER_HAS_BEEN_DETECTED 1
	#define APP_COMPILER_IS_MSVC
#endif


// 32/64 bit
#if defined(_WIN64) || defined(__x86_64__) || defined(_M_X64) || defined(__64BIT__) || defined(__powerpc64__) || defined(__ppc64__)
	#define APP_ARCH_IS_64BIT
#else
	#define APP_ARCH_IS_32BIT
#endif

#undef COMPILER_HAS_BEEN_DETECTED
