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
#ifndef FELIXS_PACK_TEXT_UTILS__CASE_32
#define FELIXS_PACK_TEXT_UTILS__CASE_32
#include <string>
#include <string_view>

namespace utf32 {
	
	[[nodiscard]] char32_t to_upper(char32_t from_c) noexcept;
	[[nodiscard]] char32_t to_lower(char32_t from_c) noexcept;
	[[nodiscard]] char32_t to_title(char32_t from_c) noexcept;
	[[nodiscard]] std::u32string to_upper(const std::u32string_view& from_string) noexcept;
	[[nodiscard]] std::u32string to_lower(const std::u32string_view& from_string) noexcept;
	[[nodiscard]] std::u32string to_title(const std::u32string_view& from_string) noexcept;
	
}

#endif //! FELIXS_PACK_TEXT_UTILS__CASE_32
