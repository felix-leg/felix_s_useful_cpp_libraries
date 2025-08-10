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
#include "trim.hpp"

#include "checks.hpp"

namespace utf32 {
	
	std::u32string_view ltrim(std::u32string_view text) noexcept {
		for(size_t i=0; i<text.length(); ++i) {
			if( ! utf32::is_space(text[i]) ) {
				text.remove_prefix(i);
				return text;
			}
		}
		return std::u32string_view(U"");
	}
	
	std::u32string_view rtrim(std::u32string_view text) noexcept {
		for(size_t i=text.length(); i>0; --i) {
			if( ! utf32::is_space(text[i-1]) ) {
				text.remove_suffix(text.length() - i);
				return text;
			}
		}
		return std::u32string_view(U"");
	}
	
	std::u32string_view trim(std::u32string_view text) noexcept {
		size_t i;
		
		for(i=0; i<text.length(); ++i) {
			if( ! utf32::is_space(text[i]) ) {
				text.remove_prefix(i);
				break;
			}
		}
		if( i == text.length() ) { return std::u32string_view(U""); }
		
		for(i=text.length(); i>0; --i) {
			if( ! utf32::is_space(text[i-1]) ) {
				text.remove_suffix(text.length() - i);
				break;
			}
		}
		
		return text;
	}
	
} //! namespace utf32
