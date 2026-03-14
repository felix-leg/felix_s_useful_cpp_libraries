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
#include "iter.hpp"

namespace utf16 {
	
	uint8_t count_bit_length(const char* c_begin) noexcept {
		const uint16_t c = *reinterpret_cast<const uint16_t*>(c_begin);
		if( c <= 0xD7FF ) return 2;
		if( c >= 0xE000 ) return 2;
		if((c & 0xFC00) == 0xD800) return 4;
		if((c & 0xFC00) == 0xDC00) return 0; //invalid position
		return 0;
	}
	
	uint8_t count_code_length(const char16_t* c_begin) noexcept {
		const uint16_t c = *reinterpret_cast<const uint16_t*>(c_begin);
		if( c <= 0xD7FF ) return 1;
		if( c >= 0xE000 ) return 1;
		if((c & 0xFC00) == 0xD800) return 2;
		if((c & 0xFC00) == 0xDC00) return 0; //invalid position
		return 0;
	}
	
	bool is_utf16_begin(const char* c_begin) noexcept {
		return count_bit_length(c_begin) != 0;
	}
	
	bool is_utf16_begin(const char16_t* c_begin) noexcept {
		return count_code_length(c_begin) != 0;
	}
	
	char32_t read_utf16(const char16_t* c_begin) noexcept {
		uint8_t c_size = count_code_length(c_begin);
		if( c_size == 0 ) return unicode::RUNE_INVALID;
		
		uint32_t result = 0;
		const uint16_t* c = reinterpret_cast<const uint16_t*>(c_begin);
		if( c_size == 1 ) {
			result = static_cast<uint32_t>( *c );
		} else if( c_size == 2 ) {
			result = static_cast<uint32_t>( c[0] & 0x03FF ) << 10;
			result |= static_cast<uint32_t>( c[1] & 0x03FF );
		}
		
		if( result > 0x10FFFF ) return unicode::RUNE_INVALID;
		return static_cast<char32_t>(result);
	}
	
	void write_utf16(char32_t c, char16_t* out) noexcept {
		out[0] = out[1] = out[2] = u'\0';
		if( c <= 0xD7FF ) {
			out[0] = static_cast<char16_t>( c );
		} else if( c >= 0xE000 && c <= 0xFFFF ) {
			out[0] = static_cast<char16_t>( c );
		} else {
			out[0] = 0xD800 | static_cast<char16_t>( (c >> 10) & 0x03FF );
			out[1] = 0xDC00 | static_cast<char16_t>( c & 0x03FF );
		}
	}
	
	//------------------- Forward Iterator
	
	ForwardUTF16Iterator::ForwardUTF16Iterator(const char16_t* c, const char16_t* last) noexcept
		: c_ptr{c}, c_last{last} {}
	ForwardUTF16Iterator::ForwardUTF16Iterator(const std::u16string& s) noexcept :
		c_ptr{s.c_str()}, c_last{s.c_str() + s.length()} {}
ForwardUTF16Iterator::ForwardUTF16Iterator(const std::u16string_view& s) noexcept :
		c_ptr{s.data()}, c_last{s.data() + s.size()} {}
	
	char32_t ForwardUTF16Iterator::operator*() const noexcept {
		return read_utf16(c_ptr);
	}
	
	const char16_t* ForwardUTF16Iterator::position() const noexcept {
		return c_ptr;
	}
	
	bool ForwardUTF16Iterator::operator==(const ForwardUTF16Iterator& other) const noexcept {
		return c_ptr == other.c_ptr;
	}
	
	bool ForwardUTF16Iterator::operator!=(const ForwardUTF16Iterator& other) const noexcept {
		return c_ptr != other.c_ptr;
	}
	
	bool ForwardUTF16Iterator::operator!=(const UTF16Sentinel&) const noexcept {
		return (*c_ptr != 0) && (c_ptr < c_last);
	}
	
	ForwardUTF16Iterator& ForwardUTF16Iterator::operator++() noexcept {
		c_ptr += count_code_length(c_ptr);
		if( c_ptr > c_last ) c_ptr = c_last;
		return *this;
	}
	
	ForwardUTF16Iterator ForwardUTF16Iterator::operator++(int) noexcept {
		ForwardUTF16Iterator before{c_ptr, c_last};
		c_ptr += count_code_length(c_ptr);
		if( c_ptr > c_last ) c_ptr = c_last;
		return before;
	}
	
	//------------------- Backward Iterator
	
	const char16_t* BackwardUTF16Iterator::shift_back(const char16_t* c) noexcept {
		while( ! is_utf16_begin(c) ) {
			c -= 1;
		}
		return c;
	}
	
	BackwardUTF16Iterator::BackwardUTF16Iterator(const char16_t* first, const char16_t* c) noexcept
		: c_ptr{c}, c_first{first} {}
	BackwardUTF16Iterator::BackwardUTF16Iterator(const std::u16string& s) noexcept :
		c_ptr{shift_back(s.c_str() + s.length() - 1)}, c_first{s.c_str()} {}
BackwardUTF16Iterator::BackwardUTF16Iterator(const std::u16string_view& s) noexcept :
		c_ptr{shift_back(s.data() + s.size() - 1)}, c_first{s.data()} {}
	
	char32_t BackwardUTF16Iterator::operator*() const noexcept {
		return read_utf16(c_ptr);
	}
	
	const char16_t* BackwardUTF16Iterator::position() const noexcept {
		return c_ptr;
	}
	
	bool BackwardUTF16Iterator::operator==(const BackwardUTF16Iterator& other) const noexcept {
		return c_ptr == other.c_ptr;
	}
	
	bool BackwardUTF16Iterator::operator!=(const BackwardUTF16Iterator& other) const noexcept {
		return c_ptr != other.c_ptr;
	}
	
	bool BackwardUTF16Iterator::operator!=(const UTF16Sentinel&) const noexcept {
		return (c_ptr >= c_first);
	}
	
	BackwardUTF16Iterator& BackwardUTF16Iterator::operator++() noexcept {
		if( c_ptr > c_first ) {
			c_ptr = shift_back(c_ptr - 1);
		} else {
			c_ptr = c_first - 1;
		}
		return *this;
	}
	
	BackwardUTF16Iterator BackwardUTF16Iterator::operator++(int) noexcept {
		BackwardUTF16Iterator before{c_first, c_ptr};
		if( c_ptr > c_first ) {
			c_ptr = shift_back(c_ptr - 1);
		} else {
			c_ptr = c_first - 1;
		}
		return before;
	}
	
} //! namespace utf16
