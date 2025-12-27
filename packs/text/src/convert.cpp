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
#include "convert.hpp"

#include <cuchar>
#include <climits>
#include <clocale>

#if __has_include(<iconv.h>)
#	include <iconv.h>
#	include <bit>
constexpr const char* UTF_32_TYPE = (std::endian::native == std::endian::big) ? "UTF-32BE" : "UTF-32LE";
#	define ICONV_ERR reinterpret_cast<iconv_t>(-1)
#	define USING_ICONV
#endif

#ifdef APP_SYSTEM_IS_MSWIN
#	define WIN32_LEAN_AND_MEAN
#	define WIN32_MEAN_AND_LEAN
#	define NOMINMAX
#	define VC_EXTRALEAN
#	include <windows.h>

#	include <limits>
#endif

namespace txt {
	
	#define SIZE_T_ERR static_cast<size_t>(-1)
	#define SIZE_T_ERR_2 static_cast<size_t>(-2)
	#define SIZE_T_ZERO static_cast<size_t>(0)
	
	std::string utf32_to_utf8(const std::u32string& from) noexcept {
		#ifdef USING_ICONV
		iconv_t i_state;
		i_state = iconv_open("UTF-8", UTF_32_TYPE);
		if( i_state != ICONV_ERR ) {
			auto in_buf = const_cast<char*>(reinterpret_cast<const char*>(from.c_str()));
			size_t in_avail = from.length() * sizeof(char32_t);
			std::string out_str{in_avail+1, '\0', std::string::allocator_type{}};
			auto out_str_size = in_avail;
			auto out_buf = out_str.data();
			size_t out_avail = in_avail;
			
			size_t i_result = iconv(i_state, &in_buf, &in_avail, &out_buf, &out_avail);
			if( i_result != SIZE_T_ERR ) {
				out_str.resize(out_str_size - out_avail);
				iconv_close(i_state);
				return out_str;
			}
			//error
			iconv_close(i_state);
		}
		#endif
		std::string old_locale {std::setlocale(LC_CTYPE, nullptr)};
		std::setlocale(LC_CTYPE, "en_US.utf8");
		
		std::string result{};
		char out[MB_LEN_MAX+1] = {0};
		std::mbstate_t state{};
		
		for(char32_t c : from) {
			size_t rc = std::c32rtomb(out, c, &state);
			if( rc != SIZE_T_ERR && rc != SIZE_T_ZERO ) {
				result += std::string(out, rc);
			}
		}
		
		std::setlocale(LC_CTYPE, old_locale.c_str());
		return result;
	}
	
	std::u32string utf8_to_utf32(const std::string& from) noexcept {
		#ifdef USING_ICONV
		iconv_t i_state;
		i_state = iconv_open(UTF_32_TYPE, "UTF-8");
		if( i_state != ICONV_ERR ) {
			auto in_buf = const_cast<char*>(from.data());
			size_t in_avail = from.length() + 1;
			std::u32string out_str{in_avail, U'\0', std::u32string::allocator_type{}};
			auto out_str_size = in_avail-1;
			auto out_buf = reinterpret_cast<char*>(out_str.data());
			size_t out_avail = in_avail * sizeof(char32_t);
			
			size_t i_result = iconv(i_state, &in_buf, &in_avail, &out_buf, &out_avail);
			if( i_result != SIZE_T_ERR ) {
				out_str.resize(out_str_size - (out_avail / sizeof(char32_t)));
				iconv_close(i_state);
				return out_str;
			}
			//error
			iconv_close(i_state);
		}
		#endif
		std::string old_locale {std::setlocale(LC_CTYPE, nullptr)};
		std::setlocale(LC_CTYPE, "en_US.utf8");
		
		std::u32string result{};
		char32_t new_char;
		std::mbstate_t state{};
		
		const char * ptr = from.c_str();
		const char * end = from.c_str() + from.size() + 1;
		while( size_t rc = std::mbrtoc32(&new_char, ptr, end - ptr, &state) ) { // rc != 0
			if( rc == SIZE_T_ERR || rc == SIZE_T_ERR_2 ) {
				break;
			}
			
			result += new_char;
			ptr += rc;
		}
		
		std::setlocale(LC_CTYPE, old_locale.c_str());
		return result;
	}
	
	std::string utf32_to_utf8(const std::u32string_view& from) noexcept {
		#ifdef USING_ICONV
		iconv_t i_state;
		i_state = iconv_open("UTF-8", UTF_32_TYPE);
		if( i_state != ICONV_ERR ) {
			auto in_buf = const_cast<char*>(reinterpret_cast<const char*>(from.data()));
			size_t in_avail = from.length() * sizeof(char32_t);
			std::string out_str{in_avail+1, '\0', std::string::allocator_type{}};
			auto out_str_size = in_avail;
			auto out_buf = out_str.data();
			size_t out_avail = in_avail;
			
			size_t i_result = iconv(i_state, &in_buf, &in_avail, &out_buf, &out_avail);
			if( i_result != SIZE_T_ERR ) {
				out_str.resize(out_str_size - out_avail);
				iconv_close(i_state);
				return out_str;
			}
			//error
			iconv_close(i_state);
		}
		#endif
		std::string old_locale {std::setlocale(LC_CTYPE, nullptr)};
		std::setlocale(LC_CTYPE, "en_US.utf8");
		
		std::string result{};
		char out[MB_LEN_MAX+1] = {0};
		std::mbstate_t state{};
		
		for(char32_t c : from) {
			size_t rc = std::c32rtomb(out, c, &state);
			if( rc != SIZE_T_ERR && rc != SIZE_T_ZERO ) {
				result += std::string(out, rc);
			}
		}
		
		std::setlocale(LC_CTYPE, old_locale.c_str());
		return result;
	}
	
	std::u32string utf8_to_utf32(const std::string_view& from) noexcept {
		#ifdef USING_ICONV
		iconv_t i_state;
		i_state = iconv_open(UTF_32_TYPE, "UTF-8");
		if( i_state != ICONV_ERR ) {
			auto in_buf = const_cast<char*>(from.data());
			size_t in_avail = from.length() + 1;
			std::u32string out_str{in_avail, U'\0', std::u32string::allocator_type{}};
			auto out_str_size = in_avail-1;
			auto out_buf = reinterpret_cast<char*>(out_str.data());
			size_t out_avail = in_avail * sizeof(char32_t);
			
			size_t i_result = iconv(i_state, &in_buf, &in_avail, &out_buf, &out_avail);
			if( i_result != SIZE_T_ERR ) {
				out_str.resize(out_str_size - (out_avail / sizeof(char32_t)));
				iconv_close(i_state);
				return out_str;
			}
			//error
			iconv_close(i_state);
		}
		#endif
		std::string old_locale {std::setlocale(LC_CTYPE, nullptr)};
		std::setlocale(LC_CTYPE, "en_US.utf8");
		
		std::u32string result{};
		char32_t new_char;
		std::mbstate_t state{};
		
		const char * ptr = from.data();
		const char * end = from.data() + from.size() + 1;
		while( size_t rc = std::mbrtoc32(&new_char, ptr, end - ptr, &state) ) { // rc != 0
			if( rc == SIZE_T_ERR || rc == SIZE_T_ERR_2 ) {
				break;
			}
			
			result += new_char;
			ptr += rc;
		}
		
		std::setlocale(LC_CTYPE, old_locale.c_str());
		return result;
	}
	
	#ifdef APP_SYSTEM_IS_MSWIN
	std::wstring utf8_to_mswin(const std::string& from) noexcept {
		return utf8_to_mswin(static_cast<std::string_view>(from));
	}
	
	std::wstring utf8_to_mswin(std::string_view from) noexcept {
		constexpr DWORD kFlags = MB_ERR_INVALID_CHARS;
		bool partial = false;
		int from_size;
		if( from.size() > static_cast<size_t>(std::numeric_limits<int>::max()) ) {
			from_size = std::numeric_limits<int>::max();
			partial = true;
			while( from_size > 0 && (from[from_size] & 0x80 != 0) ) {
				--from_size;
			}
		} else {
			from_size = static_cast<int>(from.size());
		}
		
		int required_size = MultiByteToWideChar(
			CP_UTF8, kFlags, from.data(), from_size,
			nullptr, 0
		);
		if( required_size > 0 ) {
			std::wstring result{static_cast<size_t>(required_size), L'\0', std::wstring::allocator_type{}};
			int status = MultiByteToWideChar(
				CP_UTF8, kFlags, from.data(), static_cast<int>(from.size()),
				result.data(), required_size
			);
			if( status == 0 ) { //error
				return L"";
			} else {
				if( partial ) {
					from.remove_prefix(from_size);
					return result + utf8_to_mswin(from);
				}
				return result;
			}
		} else { //conversion error
			return L"";
		}
	}
	
	std::string mswin_to_utf8(const std::wstring& from) noexcept {
		return mswin_to_utf8(static_cast<std::wstring_view>(from));
	}
	
	std::string mswin_to_utf8(const wchar_t* from_ptr, size_t from_size) noexcept {
		return mswin_to_utf8(std::wstring_view(from_ptr, from_size));
	}
	
	std::string mswin_to_utf8(std::wstring_view from) noexcept {
		constexpr DWORD kFlags = WC_ERR_INVALID_CHARS;
		bool partial = false;
		DWORD from_size;
		if( from.size() > static_cast<size_t>(std::numeric_limits<DWORD>::max()) ) {
			from_size = std::numeric_limits<DWORD>::max();
			partial = true;
			while( from_size > 0 && (from[from_size] & 0xFC == 0xDC) ) {
				--from_size;
			}
		} else {
			from_size = static_cast<DWORD>(from.size());
		}
		
		int required_size = WideCharToMultiByte(
			CP_UTF8, kFlags, from.data(), from_size,
			nullptr, 0, nullptr, nullptr
		);
		if( required_size > 0 ) {
			std::string result{static_cast<size_t>(required_size), '\0', std::string::allocator_type{}};
			int status = WideCharToMultiByte(
				CP_UTF8, kFlags, from.data(), from_size,
				result.data(), required_size, nullptr, nullptr
			);
			if( status == 0 ) {//error
				return "";
			} else {
				if( partial ) {
					from.remove_prefix(from_size);
					return result + mswin_to_utf8(from);
				}
				return result;
			}
		} else { //conversion error
			return "";
		}
	}
	#endif
	
}//! namespace txt
