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
#include "iter.hpp"

namespace utf8 {
	
	std::string to_upper(const char* from_c) noexcept {
		if( *from_c == 0 ) return "";
		using namespace txt::database;
		auto c = read_utf8(from_c);
		c += read_entry_i(upper_table, UPPER_SIZE, c);
		char out[5];
		write_utf8(c, out);
		return std::string(out);
	}
	
	std::string to_lower(const char* from_c) noexcept {
		if( *from_c == 0 ) return "";
		using namespace txt::database;
		auto c = read_utf8(from_c);
		c += read_entry_i(lower_table, LOWER_SIZE, c);
		char out[5];
		write_utf8(c, out);
		return std::string(out);
	}
	
	std::string to_title(const char* from_c) noexcept {
		if( *from_c == 0 ) return "";
		using namespace txt::database;
		auto c = read_utf8(from_c);
		c += read_entry_i(title_table, TITLE_SIZE, c);
		char out[5];
		write_utf8(c, out);
		return std::string(out);
	}
	
	std::string to_upper(const std::string_view& from_string) noexcept {
		std::string result{};
		result.reserve(from_string.size() * 4);
		ForwardUTF8Iterator it{from_string};
		UTF8Sentiel end_it{};
		using namespace txt::database;
		for(; it != end_it; ++it) {
			if( upper_map.contains( *it ) ) {
				char out[5];
				for(auto c32: upper_map[ *it ]) {
					write_utf8(c32, out);
					result += std::string(out);
				}
			} else {
				result += to_upper(it.position());
			}
		}
		return result;
	}
	
	std::string to_lower(const std::string_view& from_string) noexcept {
		std::string result{};
		result.reserve(from_string.size() * 4);
		ForwardUTF8Iterator it{from_string};
		UTF8Sentiel end_it{};
		using namespace txt::database;
		for(; it != end_it; ++it) {
			if( lower_map.contains( *it ) ) {
				char out[5];
				for(auto c32: lower_map[ *it ]) {
					write_utf8(c32, out);
					result += std::string(out);
				}
			} else {
				result += to_lower(it.position());
			}
		}
		return result;
	}
	
	std::string to_title(const std::string_view& from_string) noexcept {
		std::string result{};
		result.reserve(from_string.size() * 4);
		ForwardUTF8Iterator it{from_string};
		UTF8Sentiel end_it{};
		using namespace txt::database;
		for(; it != end_it; ++it) {
			if( title_map.contains( *it ) ) {
				char out[5];
				for(auto c32: title_map[ *it ]) {
					write_utf8(c32, out);
					result += std::string(out);
				}
			} else {
				result += to_title(it.position());
			}
		}
		return result;
	}
	
}
