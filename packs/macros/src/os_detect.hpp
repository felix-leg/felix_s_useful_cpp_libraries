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
#define OS_HAS_BEEN_DETECTED 0

// Linux
#if (OS_HAS_BEEN_DETECTED == 0) && ( defined(linux) || defined(__linux) || defined(__linux__) || defined(__gnu_linux__) )
	#undef OS_HAS_BEEN_DETECTED
	#define OS_HAS_BEEN_DETECTED 1
	#define APP_SYSTEM_IS_LINUX
#endif

//MAC OS
#if (OS_HAS_BEEN_DETECTED == 0) && ( defined(macintosh) || defined(Macintosh) || (defined(__APPLE__) && defined(__MACH__)) )
	#undef OS_HAS_BEEN_DETECTED
	#define OS_HAS_BEEN_DETECTED 1
	#define APP_SYSTEM_IS_MACOS
#endif

//Windows
#if (OS_HAS_BEEN_DETECTED == 0) && ( defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__) )
	#undef OS_HAS_BEEN_DETECTED
	#define OS_HAS_BEEN_DETECTED 1
	#define APP_SYSTEM_IS_MSWIN
#endif

#undef OS_HAS_BEEN_DETECTED
