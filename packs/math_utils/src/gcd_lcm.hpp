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
#ifndef FELIXS_PACK_MATH_UTILS_GCD_LCM_HPP
#define FELIXS_PACK_MATH_UTILS_GCD_LCM_HPP
#include <forward_list>
#include <cstdint>
#include <concepts>
#include <initializer_list>

namespace math {
	
	namespace details {
		
		class GCD_Calculator final {
		private:
			std::forward_list<unsigned long long> values;
			unsigned long long values_num = 0;
			enum {
				I8, U8,
				I16, U16,
				I32, U32,
				I64, U64
			} return_type;
			union {
				int8_t *i8; uint8_t *u8;
				int16_t *i16; uint16_t *u16;
				int32_t *i32; uint32_t *u32;
				int64_t *i64; uint64_t *u64;
			} return_ptr;
			void return_value(unsigned long long val) noexcept;
		public:
			GCD_Calculator(int8_t& ret_val) noexcept; GCD_Calculator(uint8_t& ret_val) noexcept;
			GCD_Calculator(int16_t& ret_val) noexcept; GCD_Calculator(uint16_t& ret_val) noexcept;
			GCD_Calculator(int32_t& ret_val) noexcept; GCD_Calculator(uint32_t& ret_val) noexcept;
			GCD_Calculator(int64_t& ret_val) noexcept; GCD_Calculator(uint64_t& ret_val) noexcept;
			
			void add(int8_t val) noexcept; void add(uint8_t val) noexcept;
			void add(int16_t val) noexcept; void add(uint16_t val) noexcept;
			void add(int32_t val) noexcept; void add(uint32_t val) noexcept;
			void add(int64_t val) noexcept; void add(uint64_t val) noexcept;
			
			void compute() noexcept;
		};//! class GCD_Calculator
		
	};//! namespace details
	
	template<std::integral Int>
	Int gcd(std::initializer_list<Int> i_list) noexcept {
		Int return_value;
		details::GCD_Calculator calc{return_value};
		
		for(auto value : i_list) {
			calc.add(value);
		}
		calc.compute();
		
		return return_value;
	}
	
} //! namespace math

#endif //! FELIXS_PACK_MATH_UTILS_GCD_LCM_HPP
