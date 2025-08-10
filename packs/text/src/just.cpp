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
#include "just.hpp"

namespace txt {
	
	#define ALLOC std::basic_string<char>::allocator_type()
	
	std::string ljust(const std::string& str, unsigned short length, char filler) noexcept {
		if( str.length() >= length ) {
			return str;
		}
		std::string fill_str{length - str.length(), filler, ALLOC};
		return str + fill_str;
	}
	
	std::string ljust(const std::string_view& str, unsigned short length, char filler) noexcept {
		if( str.size() >= length ) {
			return std::string(str.data(), str.size());
		}
		std::string fill_str{length - str.size(), filler, ALLOC};
		return std::string(str.data(), str.size()) + fill_str;
	}
	
	std::string rjust(const std::string& str, unsigned short length, char filler) noexcept {
		if( str.length() >= length ) {
			return str;
		}
		std::string fill_str{length - str.length(), filler, ALLOC};
		return fill_str + str;
	}
	
	std::string rjust(const std::string_view& str, unsigned short length, char filler) noexcept {
		if( str.size() >= length ) {
			return std::string(str.data(), str.size());
		}
		std::string fill_str{length - str.size(), filler, ALLOC};
		return fill_str + std::string(str.data(), str.size());
	}
	
	std::string center(const std::string& str, unsigned short length, char filler) noexcept {
		if( str.length() >= length ) {
			return str;
		}
		auto diff = length - str.length();
		auto l_space_size = diff / 2;
		auto r_space_size = diff - l_space_size;
		
		std::string l_space{l_space_size, filler, ALLOC};
		std::string r_space{r_space_size, filler, ALLOC};
		return l_space + str + r_space;
	}
	
	std::string center(const std::string_view& str, unsigned short length, char filler) noexcept {
		if( str.size() >= length ) {
			return std::string(str.data(), str.size());
		}
		auto diff = length - str.size();
		auto l_space_size = diff / 2;
		auto r_space_size = diff - l_space_size;
		
		std::string l_space{l_space_size, filler, ALLOC};
		std::string r_space{r_space_size, filler, ALLOC};
		return l_space + std::string(str.data(), str.size()) + r_space;
	}
	
} // !namespace txt
