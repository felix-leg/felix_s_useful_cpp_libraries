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

#include "../db.hpp"

namespace utf32 {
	
	char32_t to_upper(char32_t from_c) noexcept {
		if( from_c == 0 ) return 0;
		using namespace txt::database;
		return from_c + read_entry_i(upper_table, UPPER_SIZE, from_c);
	}
	
	char32_t to_lower(char32_t from_c) noexcept {
		if( from_c == 0 ) return 0;
		using namespace txt::database;
		return from_c + read_entry_i(lower_table, LOWER_SIZE, from_c);
	}
	
	char32_t to_title(char32_t from_c) noexcept {
		if( from_c == 0 ) return 0;
		using namespace txt::database;
		return from_c + read_entry_i(title_table, TITLE_SIZE, from_c);
	}
	
	std::u32string to_upper(const std::u32string_view& from_string) noexcept {
		std::u32string result{};
		result.reserve(from_string.size());
		using namespace txt::database;
		for(char32_t from_c : from_string) {
			if( upper_map.contains(from_c) ) {
				result += upper_map[from_c];
			} else {
				result += to_upper(from_c);
			}
		}
		return result;
	}
	
	std::u32string to_lower(const std::u32string_view& from_string) noexcept {
		std::u32string result{};
		result.reserve(from_string.size());
		using namespace txt::database;
		for(char32_t from_c : from_string) {
			if( lower_map.contains(from_c) ) {
				result += lower_map[from_c];
			} else {
				result += to_lower(from_c);
			}
		}
		return result;
	}
	
	std::u32string to_title(const std::u32string_view& from_string) noexcept {
		std::u32string result{};
		result.reserve(from_string.size());
		using namespace txt::database;
		for(char32_t from_c : from_string) {
			if( title_map.contains(from_c) ) {
				result += title_map[from_c];
			} else {
				result += to_title(from_c);
			}
		}
		return result;
	}
	
}
