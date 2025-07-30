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
#include "info.hpp"

#ifdef APP_SYSTEM_IS_MACOS
	#include <sys/param.h>
	#include <sys/sysctl.h>
#endif

#ifdef APP_SYSTEM_IS_LINUX
	#include <unistd.h>
#endif

#ifdef APP_SYSTEM_IS_MSWIN
	#define WIN32_LEAN_AND_MEAN
	#define WIN32_MEAN_AND_LEAN
	#define NOMINMAX
	#define VC_EXTRALEAN
	#include <windows.h>
#endif

uint32_t get_num_of_CPU_cores() noexcept {
	#ifdef APP_SYSTEM_IS_MSWIN
		SYSTEM_INFO sysinfo;
		GetSystemInfo(&sysinfo);
		return static_cast<uint32_t>(sysinfo.dwNumberOfProcessors);
	#endif
	#ifdef APP_SYSTEM_IS_LINUX
		//WARNING: can return -1
		int count = sysconf(_SC_NPROCESSORS_ONLN);
		return count > 0 ? static_cast<uint32_t>(count) : 1;
	#endif
	#ifdef APP_SYSTEM_IS_MACOS
		//XXX un-tested
		int nm[2];
		u_int count;
		size_t len = sizeof(count);

		nm[0] = CTL_HW;
		nm[1] = HW_AVAILCPU;
		sysctl(nm, 2, &count, &len, NULL, 0);

		if (count < 1) {
			//Try something else
			nm[1] = HW_NCPU;
			sysctl(nm, 2, &count, &len, NULL, 0);
			if (count < 1) {
				count = 1;
			}
		}
		return static_cast<uint32_t>(count);
	#endif
}
