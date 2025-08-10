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
#include "iter.hpp"

namespace utf8 {
	
	std::string_view ltrim(std::string_view text) noexcept {
		ForwardUTF8Iterator it{text};
		UTF8Sentiel end_it{};
		for(; it != end_it; ++it) {
			if( ! utf8::is_space(it.position()) ) {
				return std::string_view(it.position(), text.data() + text.size());
			}
		}
		return std::string_view("");
	}
	
	std::string_view rtrim(std::string_view text) noexcept {
		BackwardUTF8Iterator it{text};
		UTF8Sentiel end_it{};
		const char* before = nullptr;
		for(; it != end_it; ++it) {
			if( ! utf8::is_space(it.position()) ) {
				return std::string_view(text.data(), (before != nullptr ? before : (text.data() + text.size())));
			} else {
				before = it.position();
			}
		}
		return std::string_view("");
	}
	
	std::string_view trim(std::string_view text) noexcept {
		ForwardUTF8Iterator fit{text};
		UTF8Sentiel end_fit{};
		BackwardUTF8Iterator bit{text};
		UTF8Sentiel end_bit{};
		
		const char* view_begin = nullptr;
		const char* view_end = nullptr;
		
		for(; fit != end_fit; ++fit) {
			if( ! utf8::is_space(fit.position()) ) {
				view_begin = fit.position();
				break;
			}
		}
		if( view_begin == nullptr ) { return std::string_view(""); }
		
		for(; bit != end_bit; ++bit) {
			if( ! utf8::is_space(bit.position()) ) {
				break;
			} else {
				view_end = bit.position();
			}
		}
		
		return std::string_view(view_begin, (view_end != nullptr ? view_end : (text.data() + text.size())));
	}
	
} //! namespace utf8
