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
#include "gcd_lcm.hpp"

#include <algorithm>

namespace math {
	
	namespace details {
		
		GCD_Calculator::GCD_Calculator(int8_t& ret_val) noexcept {
			return_type = I8; return_ptr.i8 = &ret_val;
		}
		GCD_Calculator::GCD_Calculator(uint8_t& ret_val) noexcept {
			return_type = U8; return_ptr.u8 = &ret_val;
		}
		GCD_Calculator::GCD_Calculator(int16_t& ret_val) noexcept {
			return_type = I16; return_ptr.i16 = &ret_val;
		}
		GCD_Calculator::GCD_Calculator(uint16_t& ret_val) noexcept {
			return_type = U16; return_ptr.u16 = &ret_val;
		}
		GCD_Calculator::GCD_Calculator(int32_t& ret_val) noexcept {
			return_type = I32; return_ptr.i32 = &ret_val;
		}
		GCD_Calculator::GCD_Calculator(uint32_t& ret_val) noexcept {
			return_type = U32; return_ptr.u32 = &ret_val;
		}
		GCD_Calculator::GCD_Calculator(int64_t& ret_val) noexcept {
			return_type = I64; return_ptr.i64 = &ret_val;
		}
		GCD_Calculator::GCD_Calculator(uint64_t& ret_val) noexcept {
			return_type = U64; return_ptr.u64 = &ret_val;
		}
		
		void GCD_Calculator::return_value(unsigned long long val) noexcept {
			switch( return_type ) {
				case I8:
					*(return_ptr.i8) = static_cast<int8_t>(val);
					break;
				case U8:
					*(return_ptr.u8) = static_cast<uint8_t>(val);
					break;
				case I16:
					*(return_ptr.i16) = static_cast<int16_t>(val);
					break;
				case U16:
					*(return_ptr.u16) = static_cast<uint16_t>(val);
					break;
				case I32:
					*(return_ptr.i32) = static_cast<int32_t>(val);
					break;
				case U32:
					*(return_ptr.u32) = static_cast<uint32_t>(val);
					break;
				case I64:
					*(return_ptr.i64) = static_cast<int64_t>(val);
					break;
				case U64:
					*(return_ptr.u64) = static_cast<uint64_t>(val);
					break;
			}
		}
		
		void GCD_Calculator::add(int8_t val) noexcept {
			if( val == 0 ) return;
			if( val < 0 ) {
				values.push_front(static_cast<unsigned long long>(-val));
			} else {
				values.push_front(static_cast<unsigned long long>(val));
			}
			++values_num;
		}
		void GCD_Calculator::add(uint8_t val) noexcept {
			if( val == 0 ) return;
			values.push_front(static_cast<unsigned long long>(val));
			++values_num;
		}
		void GCD_Calculator::add(int16_t val) noexcept {
			if( val == 0 ) return;
			if( val < 0 ) {
				values.push_front(static_cast<unsigned long long>(-val));
			} else {
				values.push_front(static_cast<unsigned long long>(val));
			}
			++values_num;
		}
		void GCD_Calculator::add(uint16_t val) noexcept {
			if( val == 0 ) return;
			values.push_front(static_cast<unsigned long long>(val));
			++values_num;
		}
		void GCD_Calculator::add(int32_t val) noexcept {
			if( val == 0 ) return;
			if( val < 0 ) {
				values.push_front(static_cast<unsigned long long>(-val));
			} else {
				values.push_front(static_cast<unsigned long long>(val));
			}
			++values_num;
		}
		void GCD_Calculator::add(uint32_t val) noexcept {
			if( val == 0 ) return;
			values.push_front(static_cast<unsigned long long>(val));
			++values_num;
		}
		void GCD_Calculator::add(int64_t val) noexcept {
			if( val == 0 ) return;
			if( val < 0 ) {
				values.push_front(static_cast<unsigned long long>(-val));
			} else {
				values.push_front(static_cast<unsigned long long>(val));
			}
			++values_num;
		}
		void GCD_Calculator::add(uint64_t val) noexcept {
			if( val == 0 ) return;
			values.push_front(static_cast<unsigned long long>(val));
			++values_num;
		}
		
		void GCD_Calculator::compute() noexcept {
			if( values.empty() ) {
				return_value(0);
				return;
			}
			
			while( true ) {
				if( values_num == 1 ) {
					return_value(values.front());
					return;
				}
				
				auto min_val = *(std::min_element(values.begin(), values.end()));
				std::forward_list<unsigned long long> next_values;
				values_num = 0;
				bool add_min_again = false;
				
				for(auto value : values) {
					auto next_val = value % min_val;
					if( next_val == 0 ) {
						continue;
					} else {
						add_min_again = true;
					}
					next_values.push_front(next_val);
					++values_num;
				}
				if( add_min_again ) {
					next_values.push_front(min_val);
					++values_num;
				}
				if( next_values.empty() ) {
					return_value(min_val);
					return;
				}
				values.swap(next_values);
			}
		}
		
	};
	
} //! namespace math
