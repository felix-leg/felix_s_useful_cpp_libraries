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
#include "split.hpp"

#include <algorithm>
#include <functional>
#include <iterator>
#include <type_traits>

namespace txt {
	
	std::vector<std::string> split(
		const std::string_view& source,
		const std::string_view& sep
	) noexcept {
		std::vector<std::string> output;
		
		auto left = source.begin();
		auto right = source.end();
		auto sep_search = std::boyer_moore_searcher(sep.begin(), sep.end());
		while( left != right ) {
			auto found = std::search(left, right, sep_search);
			output.emplace_back(left, found);
			auto dist = static_cast<std::string_view::size_type>(std::distance(found, right));
			if( dist > sep.length() ) {
				left = std::next(found, sep.length());
			} else {
				if( dist == sep.length() ) {
					output.emplace_back("");
				}
				left = std::next(found, dist);
			}
		}
		
		return output;
	}
	
	std::vector<std::string> split(
		const std::string_view& source,
		const char sep
	) noexcept {
		std::vector<std::string> output;
		
		std::remove_const<decltype(source.npos)>::type left = 0;
		std::remove_const<decltype(source.npos)>::type found;
		while( left != source.npos ) {
			found = source.find(sep, left);
			if( found == source.npos ) {
				output.emplace_back(source.begin() + left, source.end());
				left = found;
			} else {
				output.emplace_back(source.begin() + left, source.begin() + found);
				left = found + 1;
			}
		}
		
		return output;
	}
	
	std::vector<std::string_view> split_sv(
		const std::string_view& source,
		const std::string_view& sep
	) noexcept {
		std::vector<std::string_view> output;
		
		auto left = source.begin();
		auto right = source.end();
		auto sep_search = std::boyer_moore_searcher(sep.begin(), sep.end());
		while( left != right ) {
			auto found = std::search(left, right, sep_search);
			output.emplace_back(left, found);
			auto dist = static_cast<std::string_view::size_type>(std::distance(found, right));
			if( dist > sep.length() ) {
				left = std::next(found, sep.length());
			} else {
				if( dist == sep.length() ) {
					output.emplace_back("");
				}
				left = std::next(found, dist);
			}
		}
		
		return output;
	}
	
	std::vector<std::string_view> split_sv(
		const std::string_view& source,
		const char sep
	) noexcept {
		std::vector<std::string_view> output;
		
		std::remove_const<decltype(source.npos)>::type left = 0;
		std::remove_const<decltype(source.npos)>::type found;
		while( left != source.npos ) {
			found = source.find(sep, left);
			if( found == source.npos ) {
				output.emplace_back(source.begin() + left, source.end());
				left = found;
			} else {
				output.emplace_back(source.begin() + left, source.begin() + found);
				left = found + 1;
			}
		}
		
		return output;
	}
	
} //! namespace txt
