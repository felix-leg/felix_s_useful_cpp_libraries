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
#ifndef FELIXS_PACK_CPU_PREFETCH_HPP
#define FELIXS_PACK_CPU_PREFETCH_HPP

namespace cpu {
	
	/**
	  * Prefetch data into caches.
	  *
	  * Loads data pointed by `data` to cpu cache
	  * for faster access. Level T0 is the fastest.
	  */
	void prefetch_T0(const unsigned char* data) noexcept;
	void prefetch_T1(const unsigned char* data) noexcept;
	void prefetch_T2(const unsigned char* data) noexcept;
	void prefetch_NTA(const unsigned char* data) noexcept;
	
	/**
	  * Loads `data` to cpu cache with intention to change its contents.
	  */
	void prefetch_for_write(const unsigned char* data) noexcept;
	
} //! namespace cpu

#endif //! FELIXS_PACK_CPU_PREFETCH_HPP
