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

#include <algorithm>
#include <cctype>
#include "checks.hpp"

namespace txt {
	
	std::u32string ltrim(std::u32string_view text) noexcept {
		for(size_t i=0; i<text.length(); ++i) {
			if( ! is_space(text[i]) ) {
				text.remove_prefix(i);
				return std::u32string(text);
			}
		}
		return U"";
	}
	
	std::u32string rtrim(std::u32string_view text) noexcept {
		for(size_t i=text.length(); i>0; --i) {
			if( ! is_space(text[i-1]) ) {
				text.remove_suffix(text.length() - i);
				return std::u32string(text);
			}
		}
		return U"";
	}
	
	std::u32string trim(std::u32string_view text) noexcept {
		size_t i;
		
		for(i=0; i<text.length(); ++i) {
			if( ! is_space(text[i]) ) {
				text.remove_prefix(i);
				break;
			}
		}
		if( i == text.length() ) { return U""; }
		
		for(i=text.length(); i>0; --i) {
			if( ! is_space(text[i-1]) ) {
				text.remove_suffix(text.length() - i);
				break;
			}
		}
		
		return std::u32string(text);
	}
	
	std::string ltrim(std::string_view text) noexcept {
		for(size_t i=0; i<text.length(); ++i) {
			if( ! std::isspace(text[i]) ) {
				text.remove_prefix(i);
				return std::string(text);
			}
		}
		return "";
	}
	
	std::string rtrim(std::string_view text) noexcept {
		for(size_t i=text.length(); i>0; --i) {
			if( ! std::isspace(text[i-1]) ) {
				text.remove_suffix(text.length() - i);
				return std::string(text);
			}
		}
		return "";
	}
	
	std::string trim(std::string_view text) noexcept {
		size_t i;
		
		for(i=0; i<text.length(); ++i) {
			if( ! std::isspace(text[i]) ) {
				text.remove_prefix(i);
				break;
			}
		}
		if( i == text.length() ) { return ""; }
		
		for(i=text.length(); i>0; --i) {
			if( ! std::isspace(text[i-1]) ) {
				text.remove_suffix(text.length() - i);
				break;
			}
		}
		
		return std::string(text);
	}
	
} //! namespace txt
