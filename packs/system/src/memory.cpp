#include "memory.hpp"

#ifdef APP_SYSTEM_IS_MSWIN
#     define WIN32_LEAN_AND_MEAN
#     define NOMINMAX
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
		#define SEARCHED "MemAvailable:"
		char line_buf[256];
		unsigned long long value = 0ull;
		std::string line{""};
		
		while( meminfo ) {
			std::getline(meminfo, line);
			
			if( std::sscanf(line.c_str(), "%255s %llu kB", line_buf, &value) == 2 ) {
				if( std::strncmp(SEARCHED, line_buf, sizeof(SEARCHED) - 1) == 0 ) {
					//Found!
					return KB(value);
				}
			}
		}
		return 0ull; //not found
		#undef SEARCHED
		
		#else
		
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
		#define SEARCHED "MemTotal:"
		char line_buf[256];
		unsigned long long value = 0ull;
		std::string line{""};
		
		while( meminfo ) {
			std::getline(meminfo, line);
			
			if( std::sscanf(line.c_str(), "%255s %llu kB", line_buf, &value) == 2 ) {
				if( std::strncmp(SEARCHED, line_buf, sizeof(SEARCHED) - 1) == 0 ) {
					//Found!
					return KB(value);
				}
			}
		}
		return 0ull; //not found
		#undef SEARCHED
		
		#else
		
		MEMORYSTATUSEX statex;
		statex.dwLength = sizeof (statex);
		if( GlobalMemoryStatusEx (&statex) == 0 ) {
			return 0ull; //not found
		}
		return statex.ullTotalPhys;
		#endif
	}
	
	
} //! namespace memory
