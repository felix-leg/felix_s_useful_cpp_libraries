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
#include "memory.hpp"

#ifdef APP_SYSTEM_IS_MSWIN
#     define WIN32_LEAN_AND_MEAN
#     define WIN32_MEAN_AND_LEAN
#     define NOMINMAX
#     define VC_EXTRALEAN
#     include <windows.h> //for GlobalMemoryStatusEx
#else
#     include <fstream> //for std::ifstream
#     include <string> //for std::string
#     include <cstdio> //for std::sscanf
#     include <cstring> //for std::strncmp
#endif

namespace memory {
	
	unsigned long long get_free_RAM() noexcept {
		#ifndef APP_SYSTEM_IS_MSWIN
		std::ifstream meminfo{"/proc/meminfo"};
		const char searched[] = "MemAvailable:";
		char line_buf[256];
		unsigned long long value = 0ull;
		std::string line{""};
		
		while( meminfo ) {
			std::getline(meminfo, line);
			
			if( std::sscanf(line.c_str(), "%255s %llu kB", line_buf, &value) == 2 ) {
				if( std::strncmp(searched, line_buf, sizeof(searched) - 1) == 0 ) {
					//Found!
					return KB(value);
				}
			}
		}
		return 0ull; //not found
		
		#else /* APP_SYSTEM_IS_MSWIN */
		
		MEMORYSTATUSEX statex;
		statex.dwLength = sizeof (statex);
		if( GlobalMemoryStatusEx (&statex) == 0 ) {
			return 0ull; //not found
		}
		return statex.ullAvailPhys;
		#endif
	}
	
	unsigned long long get_total_RAM() noexcept {
		#ifndef APP_SYSTEM_IS_MSWIN
		std::ifstream meminfo{"/proc/meminfo"};
		const char searched[] = "MemTotal:";
		char line_buf[256];
		unsigned long long value = 0ull;
		std::string line{""};
		
		while( meminfo ) {
			std::getline(meminfo, line);
			
			if( std::sscanf(line.c_str(), "%255s %llu kB", line_buf, &value) == 2 ) {
				if( std::strncmp(searched, line_buf, sizeof(searched) - 1) == 0 ) {
					//Found!
					return KB(value);
				}
			}
		}
		return 0ull; //not found
		
		#else /* APP_SYSTEM_IS_MSWIN */
		
		MEMORYSTATUSEX statex;
		statex.dwLength = sizeof (statex);
		if( GlobalMemoryStatusEx (&statex) == 0 ) {
			return 0ull; //not found
		}
		return statex.ullTotalPhys;
		#endif
	}
	
	
} //! namespace memory
