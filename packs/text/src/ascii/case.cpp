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
#include "case.hpp"

namespace ascii {
	
	char to_upper(char from_c) noexcept {
		if( from_c == 0 ) return 0;
		if( from_c >= 97 && from_c <= 122) return from_c - 32;
		return from_c;
	}
	
	char to_lower(char from_c) noexcept {
		if( from_c == 0 ) return 0;
		if( from_c >= 65 && from_c <= 90) return from_c + 32;
		return from_c;
	}
	
	char to_title(char from_c) noexcept {
		return to_upper(from_c);
	}
	
	std::string to_upper(const std::string_view& from_string) noexcept {
		std::string result{};
		result.reserve(from_string.size());
		for(char from_c : from_string) {
			result += to_upper(from_c);
		}
		return result;
	}
	
	std::string to_lower(const std::string_view& from_string) noexcept {
		std::string result{};
		result.reserve(from_string.size());
		for(char from_c : from_string) {
			result += to_lower(from_c);
		}
		return result;
	}
	
	std::string to_title(const std::string_view& from_string) noexcept {
		std::string result{};
		result.reserve(from_string.size());
		for(char from_c : from_string) {
			result += to_title(from_c);
		}
		return result;
	}
	
}
