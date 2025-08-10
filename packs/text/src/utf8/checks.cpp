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
#include "checks.hpp"

#include "../db.hpp"
#include "iter.hpp"
#include <cstdint>

namespace utf8 {
	
	constexpr uint8_t alpha_bit = 1;
	constexpr uint8_t digit_bit = 2;
	constexpr uint8_t lower_bit = 4;
	constexpr uint8_t upper_bit = 8;
	constexpr uint8_t title_bit = 16;
	constexpr uint8_t print_bit = 32;
	constexpr uint8_t space_bit = 64;
	constexpr uint8_t numeric_bit = 128;
	
	bool is_alpha(const char* test_char) noexcept {
		if( *test_char == 0 ) return false;
		auto c32 = read_utf8(test_char);
		using namespace txt::database;
		uint8_t bits = static_cast<uint8_t>(read_entry_i(char_class_table, CHAR_CLASS_SIZE, c32));
		return (bits & alpha_bit) != 0;
	}
	
	bool is_ascii(const char* test_char) noexcept {
		auto c32 = read_utf8(test_char);
		return ( c32 >= 0 && c32 < 128 );
	}
	
	bool is_digit(const char* test_char) noexcept {
		if( *test_char == 0 ) return false;
		auto c32 = read_utf8(test_char);
		using namespace txt::database;
		uint8_t bits = static_cast<uint8_t>(read_entry_i(char_class_table, CHAR_CLASS_SIZE, c32));
		return (bits & digit_bit) != 0;
	}
	
	bool is_lower_case(const char* test_char) noexcept {
		if( *test_char == 0 ) return false;
		auto c32 = read_utf8(test_char);
		using namespace txt::database;
		uint8_t bits = static_cast<uint8_t>(read_entry_i(char_class_table, CHAR_CLASS_SIZE, c32));
		return (bits & lower_bit) != 0;
	}
	
	bool is_numeric(const char* test_char) noexcept {
		if( *test_char == 0 ) return false;
		auto c32 = read_utf8(test_char);
		using namespace txt::database;
		uint8_t bits = static_cast<uint8_t>(read_entry_i(char_class_table, CHAR_CLASS_SIZE, c32));
		return (bits & numeric_bit) != 0;
	}
	
	bool is_print(const char* test_char) noexcept {
		if( *test_char == 0 ) return false;
		auto c32 = read_utf8(test_char);
		using namespace txt::database;
		uint8_t bits = static_cast<uint8_t>(read_entry_i(char_class_table, CHAR_CLASS_SIZE, c32));
		return (bits & print_bit) != 0;
	}
	
	bool is_space(const char* test_char) noexcept {
		if( *test_char == 0 ) return false;
		auto c32 = read_utf8(test_char);
		using namespace txt::database;
		uint8_t bits = static_cast<uint8_t>(read_entry_i(char_class_table, CHAR_CLASS_SIZE, c32));
		return (bits & space_bit) != 0;
	}
	
	bool is_title_case(const char* test_char) noexcept {
		if( *test_char == 0 ) return false;
		auto c32 = read_utf8(test_char);
		using namespace txt::database;
		uint8_t bits = static_cast<uint8_t>(read_entry_i(char_class_table, CHAR_CLASS_SIZE, c32));
		return (bits & title_bit) != 0;
	}
	
	bool is_upper_case(const char* test_char) noexcept {
		if( *test_char == 0 ) return false;
		auto c32 = read_utf8(test_char);
		using namespace txt::database;
		uint8_t bits = static_cast<uint8_t>(read_entry_i(char_class_table, CHAR_CLASS_SIZE, c32));
		return (bits & upper_bit) != 0;
	}
	
};//! namespace utf8
