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
#ifndef FELIXS_PACK_TEXT_UTILS_ITER16_HPP
#define FELIXS_PACK_TEXT_UTILS_ITER16_HPP
#include <cstdint>
#include <iterator>
#include <string>
#include <string_view>

#include "../unicode.hpp"

namespace utf16 {
	
	/**
	  * Counts the length in bytes of an utf16 character.
	  *
	  * `c_begin` must point at the beginning of a character,
	  * or else the function return 0.
	  */
	[[nodiscard]] uint8_t count_bit_length(const char* c_begin) noexcept;
	
	/**
	  * Counts the length in code points of an utf16 character.
	  *
	  * `c_begin` must point at the beginning of a character,
	  * or else the function return 0.
	  */
	[[nodiscard]] uint8_t count_code_length(const char16_t* c_begin) noexcept;
	
	/**
	  * Checks if the byte at `c_begin` starts an UTF-16 character
	  */
	[[nodiscard]] bool is_utf16_begin(const char* c_begin) noexcept;
	[[nodiscard]] bool is_utf16_begin(const char16_t* c_begin) noexcept;
	
	
	[[nodiscard]] char32_t read_utf16(const char16_t* c_begin) noexcept;
	/// Write character `c` into a 3 element table `out` encoded in UTF-16
	void write_utf16(char32_t c, char16_t* out) noexcept;
	
	using UTF16Sentinel = std:: default_sentinel_t;
	
	class ForwardUTF16Iterator {
	private:
		const char16_t* c_ptr;
		const char16_t* c_last;
	public:
		using difference_type = std::ptrdiff_t;
		using value_type = char32_t;
		using iterator_category = std::forward_iterator_tag;
		
		explicit(false) ForwardUTF16Iterator(const char16_t* c, const char16_t* last) noexcept;
		explicit(true) ForwardUTF16Iterator(const std::u16string& s) noexcept;
		explicit(true) ForwardUTF16Iterator(const std::u16string_view& s) noexcept;
		
		char32_t operator*() const noexcept; // *it
		const char16_t* position() const noexcept;
		bool operator==(const ForwardUTF16Iterator& other) const noexcept; // i == j
		bool operator!=(const ForwardUTF16Iterator& other) const noexcept; // i != j
		bool operator!=(const UTF16Sentinel&) const noexcept;
		
		ForwardUTF16Iterator& operator++() noexcept; // ++it
		ForwardUTF16Iterator operator++(int) noexcept; // it++
	};
	
	class BackwardUTF16Iterator {
	private:
		const char16_t* c_ptr;
		const char16_t* c_first;
		const char16_t* shift_back(const char16_t* c) noexcept;
	public:
		using difference_type = std::ptrdiff_t;
		using value_type = char32_t;
		using iterator_category = std::forward_iterator_tag;
		
		explicit(false) BackwardUTF16Iterator(const char16_t* first, const char16_t* c) noexcept;
		explicit(true) BackwardUTF16Iterator(const std::u16string& s) noexcept;
		explicit(true) BackwardUTF16Iterator(const std::u16string_view& s) noexcept;
		
		char32_t operator*() const noexcept; // *it
		const char16_t* position() const noexcept;
		bool operator==(const BackwardUTF16Iterator& other) const noexcept; // i == j
		bool operator!=(const BackwardUTF16Iterator& other) const noexcept; // i != j
		bool operator!=(const UTF16Sentinel&) const noexcept;
		
		BackwardUTF16Iterator& operator++() noexcept; // ++it
		BackwardUTF16Iterator operator++(int) noexcept; // it++
	};
	
} //! namespace utf16

#endif //! FELIXS_PACK_TEXT_UTILS_ITER16_HPP
