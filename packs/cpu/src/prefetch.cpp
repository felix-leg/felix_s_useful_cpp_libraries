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
#include "prefetch.hpp"

#ifdef APP_COMPILER_IS_MSVC
#include <intrin.h>
#endif

namespace cpu {
	
	void prefetch_T0(const unsigned char* data) noexcept {
		#ifndef APP_COMPILER_IS_MSVC
		__asm__ volatile (
			".intel_syntax noprefix;"
			"prefetcht0 byte ptr [rax];"
			#ifdef APP_COMPILER_IS_CLANG
			".att_syntax"
			#endif
			: /* no output */
			: "a"(data)
			: /* no clobber */
		);
		#else
		_mm_prefetch( reinterpret_cast<const char *>( data ), _MM_HINT_T0 );
		#endif
	}
	
	void prefetch_T1(const unsigned char* data) noexcept {
		#ifndef APP_COMPILER_IS_MSVC
		__asm__ volatile (
			".intel_syntax noprefix;"
			"prefetcht1 byte ptr [rax];"
			#ifdef APP_COMPILER_IS_CLANG
			".att_syntax"
			#endif
			: /* no output */
			: "a"(data)
			: /* no clobber */
		);
		#else
		_mm_prefetch( reinterpret_cast<const char *>( data ), _MM_HINT_T1 );
		#endif
	}
	
	void prefetch_T2(const unsigned char* data) noexcept {
		#ifndef APP_COMPILER_IS_MSVC
		__asm__ volatile (
			".intel_syntax noprefix;"
			"prefetcht2 byte ptr [rax];"
			#ifdef APP_COMPILER_IS_CLANG
			".att_syntax"
			#endif
			: /* no output */
			: "a"(data)
			: /* no clobber */
		);
		#else
		_mm_prefetch( reinterpret_cast<const char *>( data ), _MM_HINT_T2 );
		#endif
	}
	
	void prefetch_NTA(const unsigned char* data) noexcept {
		#ifndef APP_COMPILER_IS_MSVC
		__asm__ volatile (
			".intel_syntax noprefix;"
			"prefetchnta byte ptr [rax];"
			#ifdef APP_COMPILER_IS_CLANG
			".att_syntax"
			#endif
			: /* no output */
			: "a"(data)
			: /* no clobber */
		);
		#else
		_mm_prefetch( reinterpret_cast<const char *>( data ), _MM_HINT_NTA );
		#endif
	}
	
	void prefetch_for_write(const unsigned char* data) noexcept {
		#ifndef APP_COMPILER_IS_MSVC
		__asm__ volatile (
			".intel_syntax noprefix;"
			"prefetchw byte ptr [rax];"
			#ifdef APP_COMPILER_IS_CLANG
			".att_syntax"
			#endif
			: /* no output */
			: "a"(data)
			: /* no clobber */
		);
		#else
		_m_prefetchw( reinterpret_cast<const void *>( data ) );
		#endif
	}
	
} //! namespace cpu
