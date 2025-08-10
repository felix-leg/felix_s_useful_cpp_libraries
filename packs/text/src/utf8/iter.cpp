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

namespace utf8 {
	
	uint8_t count_length(const char* c_begin) noexcept {
		const uint8_t c = *reinterpret_cast<const uint8_t*>(c_begin);
		if( c < 0b1000'0000 ) return 1;
		if( (c & 0b1110'0000) == 0b1100'0000 ) return 2;
		if( (c & 0b1111'0000) == 0b1110'0000 ) return 3;
		if( (c & 0b1111'1000) == 0b1111'0000 ) return 4;
		return 0;
	}
	
	bool is_utf8_begin(const char* c_begin) noexcept {
		return count_length(c_begin) != 0;
	}
	
	char32_t read_utf8(const char* c_begin) noexcept {
		uint8_t c_size = count_length(c_begin);
		if( c_size == 0 ) return unicode::RUNE_INVALID;
		
		uint32_t result = 0;
		if( c_size == 1 ) {
			result = static_cast<uint32_t>( *c_begin );
		} else if( c_size == 2 ) {
			if( (c_begin[1] & 0b1100'0000) != 0b1000'0000 ) return unicode::RUNE_INVALID;
			result = static_cast<uint32_t>(c_begin[0] & 0b0001'1111) << 6;
			result |= static_cast<uint32_t>(c_begin[1] & 0b0011'1111);
		} else if( c_size == 3 ) {
			if( (c_begin[1] & 0b1100'0000) != 0b1000'0000 ) return unicode::RUNE_INVALID;
			if( (c_begin[2] & 0b1100'0000) != 0b1000'0000 ) return unicode::RUNE_INVALID;
			result = static_cast<uint32_t>(c_begin[0] & 0b0000'1111) << 12;
			result |= static_cast<uint32_t>(c_begin[1] & 0b0011'1111) << 6;
			result |= static_cast<uint32_t>(c_begin[2] & 0b0011'1111);
		} else if( c_size == 4 ) {
			if( (c_begin[1] & 0b1100'0000) != 0b1000'0000 ) return unicode::RUNE_INVALID;
			if( (c_begin[2] & 0b1100'0000) != 0b1000'0000 ) return unicode::RUNE_INVALID;
			if( (c_begin[3] & 0b1100'0000) != 0b1000'0000 ) return unicode::RUNE_INVALID;
			result = static_cast<uint32_t>(c_begin[0] & 0b0000'0111) << 18;
			result |= static_cast<uint32_t>(c_begin[1] & 0b0011'1111) << 12;
			result |= static_cast<uint32_t>(c_begin[2] & 0b0011'1111) << 6;
			result |= static_cast<uint32_t>(c_begin[3] & 0b0011'1111);
		}
		
		if( result > 0x10FFFF ) return unicode::RUNE_INVALID;
		return static_cast<char32_t>(result);
	}
	
	void write_utf8(char32_t c, char* out) noexcept {
		out[0] = out[1] = out[2] = out[3] = out[4] = '\0';
		uint8_t* u8o = reinterpret_cast<uint8_t*>(out);
		uint32_t c8 = static_cast<uint32_t>(c);
		
		if( c <= 0x007F ) {
			u8o[0] = static_cast<uint8_t>(c8);
		} else if( c >= 0x0080 && c <= 0x07FF ) {
			u8o[0] = 0b1100'0000 | static_cast<uint8_t>((c >> 6) & 0b0001'1111);
			u8o[1] = 0b1000'0000 | static_cast<uint8_t>(c & 0b0011'1111);
		} else if( c >= 0x0800 && c <= 0xFFFF ) {
			u8o[0] = 0b1110'0000 | static_cast<uint8_t>((c >> 12) & 0b0000'1111);
			u8o[1] = 0b1000'0000 | static_cast<uint8_t>((c >> 6) & 0b0011'1111);
			u8o[2] = 0b1000'0000 | static_cast<uint8_t>(c & 0b0011'1111);
		} else if( c >= 0x010000 && c <= 0x10FFFF ) {
			u8o[0] = 0b1111'0000 | static_cast<uint8_t>((c >> 18) & 0b0000'0111);
			u8o[1] = 0b1000'0000 | static_cast<uint8_t>((c >> 12) & 0b0011'1111);
			u8o[2] = 0b1000'0000 | static_cast<uint8_t>((c >> 6) & 0b0011'1111);
			u8o[3] = 0b1000'0000 | static_cast<uint8_t>(c & 0b0011'1111);
		}
	}
	
	//------------------- Forward Iterator
	
	ForwardUTF8Iterator::ForwardUTF8Iterator(const char* c, const char* last) noexcept : c_ptr{c}, c_last{last} {}
	ForwardUTF8Iterator::ForwardUTF8Iterator(const std::string& s) noexcept :
		c_ptr{s.c_str()}, c_last{s.c_str() + s.length()} {}
ForwardUTF8Iterator::ForwardUTF8Iterator(const std::string_view& s) noexcept :
		c_ptr{s.data()}, c_last{s.data() + s.size()} {}
	
	char32_t ForwardUTF8Iterator::operator*() const noexcept {
		return read_utf8(c_ptr);
	}
	
	const char* ForwardUTF8Iterator::position() const noexcept {
		return c_ptr;
	}
	
	bool ForwardUTF8Iterator::operator==(const ForwardUTF8Iterator& other) const noexcept {
		return c_ptr == other.c_ptr;
	}
	
	bool ForwardUTF8Iterator::operator!=(const ForwardUTF8Iterator& other) const noexcept {
		return c_ptr != other.c_ptr;
	}
	
	bool ForwardUTF8Iterator::operator!=(const UTF8Sentiel&) const noexcept {
		return (*c_ptr != 0) && (c_ptr < c_last);
	}
	
	ForwardUTF8Iterator& ForwardUTF8Iterator::operator++() noexcept {
		c_ptr += count_length(c_ptr);
		if( c_ptr > c_last ) c_ptr = c_last;
		return *this;
	}
	
	ForwardUTF8Iterator ForwardUTF8Iterator::operator++(int) noexcept {
		ForwardUTF8Iterator before{c_ptr, c_last};
		c_ptr += count_length(c_ptr);
		if( c_ptr > c_last ) c_ptr = c_last;
		return before;
	}
	
	//------------------- Backward Iterator
	
	const char* BackwardUTF8Iterator::shift_back(const char* c) noexcept {
		while( ! is_utf8_begin(c) ) {
			c -= 1;
		}
		return c;
	}
	
	BackwardUTF8Iterator::BackwardUTF8Iterator(const char* first, const char* c) noexcept : c_ptr{c}, c_first{first} {}
	BackwardUTF8Iterator::BackwardUTF8Iterator(const std::string& s) noexcept :
		c_ptr{shift_back(s.c_str() + s.length() - 1)}, c_first{s.c_str()} {}
BackwardUTF8Iterator::BackwardUTF8Iterator(const std::string_view& s) noexcept :
		c_ptr{shift_back(s.data() + s.size() - 1)}, c_first{s.data()} {}
	
	char32_t BackwardUTF8Iterator::operator*() const noexcept {
		return read_utf8(c_ptr);
	}
	
	const char* BackwardUTF8Iterator::position() const noexcept {
		return c_ptr;
	}
	
	bool BackwardUTF8Iterator::operator==(const BackwardUTF8Iterator& other) const noexcept {
		return c_ptr == other.c_ptr;
	}
	
	bool BackwardUTF8Iterator::operator!=(const BackwardUTF8Iterator& other) const noexcept {
		return c_ptr != other.c_ptr;
	}
	
	bool BackwardUTF8Iterator::operator!=(const UTF8Sentiel&) const noexcept {
		return (c_ptr >= c_first);
	}
	
	BackwardUTF8Iterator& BackwardUTF8Iterator::operator++() noexcept {
		if( c_ptr > c_first ) {
			c_ptr = shift_back(c_ptr - 1);
		} else {
			c_ptr = c_first - 1;
		}
		return *this;
	}
	
	BackwardUTF8Iterator BackwardUTF8Iterator::operator++(int) noexcept {
		BackwardUTF8Iterator before{c_first, c_ptr};
		if( c_ptr > c_first ) {
			c_ptr = shift_back(c_ptr - 1);
		} else {
			c_ptr = c_first - 1;
		}
		return before;
	}
	
} //! namespace utf8
