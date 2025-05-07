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
#ifndef FELIXS_PACK_SYSTEM_MEMORY_HPP
#define FELIXS_PACK_SYSTEM_MEMORY_HPP

namespace memory {
	
	[[nodiscard]] unsigned long long get_free_RAM() noexcept;
	[[nodiscard]] unsigned long long get_total_RAM() noexcept;
	
	constexpr unsigned long long KB(unsigned long long kb_m) {
		return kb_m * 1024ull;
	}
	constexpr unsigned long long MB(unsigned long long mb_m) {
		return mb_m * 1024ull * 1024ull;
	}
	constexpr unsigned long long GB(unsigned long long gb_m) {
		return gb_m * 1024ull * 1024ull * 1024ull;
	}
	constexpr unsigned long long TB(unsigned long long tb_m) {
		return tb_m * 1024ull * 1024ull * 1024ull * 1024ull;
	}
	
	constexpr double as_KB(unsigned long long kb_m) {
		return kb_m / static_cast<double>(1024ull);
	}
	constexpr double as_MB(unsigned long long mb_m) {
		return mb_m / static_cast<double>(1024ull * 1024ull);
	}
	constexpr double as_GB(unsigned long long gb_m) {
		return gb_m / static_cast<double>(1024ull * 1024ull * 1024ull);
	}
	constexpr double as_TB(unsigned long long tb_m) {
		return tb_m / static_cast<double>(1024ull * 1024ull * 1024ull * 1024ull);
	}
	
} //! namespace memory

#endif //! FELIXS_PACK_SYSTEM_MEMORY_HPP

