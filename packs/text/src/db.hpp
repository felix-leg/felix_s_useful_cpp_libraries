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
#pragma once
#ifndef FELIXS_PACK_TEXT_UTILS_DB_HPP
#define FELIXS_PACK_TEXT_UTILS_DB_HPP
#include <cstdint>
#include <cstddef>
#include <map>
#include <string>

#include "unicode.hpp"

namespace txt::database {
	
	#pragma pack(4)
	struct DbEntryInt {
		uint32_t left;
		uint32_t right;
		int32_t value;
		
		bool is_end_value() const noexcept;
	};
	struct DbEntryFloat {
		uint32_t left;
		uint32_t right;
		float value;
		
		bool is_end_value() const noexcept;
	};
	#pragma pack()
	
	constexpr size_t UPPER_SIZE = 1170uz;
	constexpr size_t LOWER_SIZE = 1151uz;
	constexpr size_t TITLE_SIZE = 1153uz;
	constexpr size_t CHAR_CLASS_SIZE = 559325uz;
	constexpr size_t ASCII_CLASS_SIZE = 128uz;
	
	extern DbEntryInt upper_table[UPPER_SIZE];
	extern DbEntryInt lower_table[LOWER_SIZE];
	extern DbEntryInt title_table[TITLE_SIZE];
	extern DbEntryInt char_class_table[CHAR_CLASS_SIZE];
	extern uint8_t ascii_class_table[ASCII_CLASS_SIZE];
	
	extern std::map<unicode::Rune, std::u32string> upper_map;
	extern std::map<unicode::Rune, std::u32string> lower_map;
	extern std::map<unicode::Rune, std::u32string> title_map;
	
	int32_t read_entry_i(DbEntryInt* table, size_t max_size, unicode::Rune search, int32_t default_value = 0) noexcept;
	float read_entry_f(DbEntryFloat* table, size_t max_size, unicode::Rune search, float default_value = 0.0f) noexcept;
	
} //! namespace txt::database

#endif //! FELIXS_PACK_TEXT_UTILS_DB_HPP
