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
#include "arithmetic.hpp"

#ifdef APP_COMPILER_IS_MSVC
#include <intrin.h>
#pragma intrinsic(_rotl8, _rotl16, _rotl, _rotl64)
#pragma intrinsic(_rotr8, _rotr16, _rotr, _rotr64)
#endif

namespace cpu {
	
	void rot_left(uint8_t& value, uint8_t count) noexcept {
		count %= 8;
		#ifndef APP_COMPILER_IS_MSVC
		__asm__ volatile (
			".intel_syntax noprefix;"
			"rol al,cl;"
			#ifdef APP_COMPILER_IS_CLANG
			".att_syntax"
			#endif
			: "=a"(value)
			: "a"(value), "c"(count)
			: /* no clobber */
		);
		#else
		value = static_cast<uint8_t>(_rotl8(
			static_cast<unsigned char>(value),
			static_cast<unsigned char>(count)
		));
		#endif
	}
	void rot_left(uint16_t& value, uint8_t count) noexcept {
		count %= 16;
		#ifndef APP_COMPILER_IS_MSVC
		__asm__ volatile (
			".intel_syntax noprefix;"
			"rol ax,cl;"
			#ifdef APP_COMPILER_IS_CLANG
			".att_syntax"
			#endif
			: "=a"(value)
			: "a"(value), "c"(count)
			: /* no clobber */
		);
		#else
		value = static_cast<uint16_t>(_rotl16(
			static_cast<unsigned short>(value),
			static_cast<unsigned char>(count)
		));
		#endif
	}
	void rot_left(uint32_t& value, uint8_t count) noexcept {
		count %= 32;
		#ifndef APP_COMPILER_IS_MSVC
		__asm__ volatile (
			".intel_syntax noprefix;"
			"rol eax,cl;"
			#ifdef APP_COMPILER_IS_CLANG
			".att_syntax"
			#endif
			: "=a"(value)
			: "a"(value), "c"(count)
			: /* no clobber */
		);
		#else
		value = static_cast<uint32_t>(_rotl(
			static_cast<unsigned int>(value),
			static_cast<int>(count)
		));
		#endif
	}
	void rot_left(uint64_t& value, uint8_t count) noexcept {
		count %= 64;
		#ifndef APP_COMPILER_IS_MSVC
		__asm__ volatile (
			".intel_syntax noprefix;"
			"rol rax,cl;"
			#ifdef APP_COMPILER_IS_CLANG
			".att_syntax"
			#endif
			: "=a"(value)
			: "a"(value), "c"(count)
			: /* no clobber */
		);
		#else
		value = static_cast<uint64_t>(_rotl64(
			static_cast<unsigned __int64>(value),
			static_cast<int>(count)
		));
		#endif
	}
	
	void rot_right(uint8_t& value, uint8_t count) noexcept {
		count %= 8;
		#ifndef APP_COMPILER_IS_MSVC
		__asm__ volatile (
			".intel_syntax noprefix;"
			"ror al,cl;"
			#ifdef APP_COMPILER_IS_CLANG
			".att_syntax"
			#endif
			: "=a"(value)
			: "a"(value), "c"(count)
			: /* no clobber */
		);
		#else
		value = static_cast<uint8_t>(_rotr8(
			static_cast<unsigned char>(value),
			static_cast<unsigned char>(count)
		));
		#endif
	}
	void rot_right(uint16_t& value, uint8_t count) noexcept {
		count %= 16;
		#ifndef APP_COMPILER_IS_MSVC
		__asm__ volatile (
			".intel_syntax noprefix;"
			"ror ax,cl;"
			#ifdef APP_COMPILER_IS_CLANG
			".att_syntax"
			#endif
			: "=a"(value)
			: "a"(value), "c"(count)
			: /* no clobber */
		);
		#else
		value = static_cast<uint16_t>(_rotr16(
			static_cast<unsigned short>(value),
			static_cast<unsigned char>(count)
		));
		#endif
	}
	void rot_right(uint32_t& value, uint8_t count) noexcept {
		count %= 32;
		#ifndef APP_COMPILER_IS_MSVC
		__asm__ volatile (
			".intel_syntax noprefix;"
			"ror eax,cl;"
			#ifdef APP_COMPILER_IS_CLANG
			".att_syntax"
			#endif
			: "=a"(value)
			: "a"(value), "c"(count)
			: /* no clobber */
		);
		#else
		value = static_cast<uint32_t>(_rotr(
			static_cast<unsigned int>(value),
			static_cast<int>(count)
		));
		#endif
	}
	void rot_right(uint64_t& value, uint8_t count) noexcept {
		count %= 64;
		#ifndef APP_COMPILER_IS_MSVC
		__asm__ volatile (
			".intel_syntax noprefix;"
			"ror rax,cl;"
			#ifdef APP_COMPILER_IS_CLANG
			".att_syntax"
			#endif
			: "=a"(value)
			: "a"(value), "c"(count)
			: /* no clobber */
		);
		#else
		value = static_cast<uint64_t>(_rotr64(
			static_cast<unsigned __int64>(value),
			static_cast<int>(count)
		));
		#endif
	}
	
} //! namespace cpu
