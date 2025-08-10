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
#ifndef FELIXS_PACK_TEXT_UTILS_ITER_HPP
#define FELIXS_PACK_TEXT_UTILS_ITER_HPP
#include <cstdint>
#include <iterator>
#include <string>
#include <string_view>

#include "../unicode.hpp"

namespace utf8 {
	
	/**
	  * Counts the length in bytes of an utf8 character.
	  *
	  * `c_begin` must point at the beginning of a character,
	  * or else the function return 0.
	  */
	[[nodiscard]] uint8_t count_length(const char* c_begin) noexcept;
	
	/**
	  * Checks if the byte at `c_begin` starts an UTF-8 character
	  */
	[[nodiscard]] bool is_utf8_begin(const char* c_begin) noexcept;
	
	
	[[nodiscard]] char32_t read_utf8(const char* c_begin) noexcept;
	/// Write character `c` into a 5 element table `out` encoded in UTF-8
	void write_utf8(char32_t c, char* out) noexcept;
	
	using UTF8Sentiel = std:: default_sentinel_t;
	
	class ForwardUTF8Iterator {
	private:
		const char* c_ptr;
		const char* c_last;
	public:
		using difference_type = std::ptrdiff_t;
		using value_type = char32_t;
		using iterator_category = std::forward_iterator_tag;
		
		explicit(false) ForwardUTF8Iterator(const char* c, const char* last) noexcept;
		explicit(true) ForwardUTF8Iterator(const std::string& s) noexcept;
		explicit(true) ForwardUTF8Iterator(const std::string_view& s) noexcept;
		
		char32_t operator*() const noexcept; // *it
		const char* position() const noexcept;
		bool operator==(const ForwardUTF8Iterator& other) const noexcept; // i == j
		bool operator!=(const ForwardUTF8Iterator& other) const noexcept; // i != j
		bool operator!=(const UTF8Sentiel&) const noexcept;
		
		ForwardUTF8Iterator& operator++() noexcept; // ++it
		ForwardUTF8Iterator operator++(int) noexcept; // it++
	};
	
	class BackwardUTF8Iterator {
	private:
		const char* c_ptr;
		const char* c_first;
		const char* shift_back(const char* c) noexcept;
	public:
		using difference_type = std::ptrdiff_t;
		using value_type = char32_t;
		using iterator_category = std::forward_iterator_tag;
		
		explicit(false) BackwardUTF8Iterator(const char* first, const char* c) noexcept;
		explicit(true) BackwardUTF8Iterator(const std::string& s) noexcept;
		explicit(true) BackwardUTF8Iterator(const std::string_view& s) noexcept;
		
		char32_t operator*() const noexcept; // *it
		const char* position() const noexcept;
		bool operator==(const BackwardUTF8Iterator& other) const noexcept; // i == j
		bool operator!=(const BackwardUTF8Iterator& other) const noexcept; // i != j
		bool operator!=(const UTF8Sentiel&) const noexcept;
		
		BackwardUTF8Iterator& operator++() noexcept; // ++it
		BackwardUTF8Iterator operator++(int) noexcept; // it++
	};
	
} //! namespace utf8

#endif //! FELIXS_PACK_TEXT_UTILS_ITER_HPP
