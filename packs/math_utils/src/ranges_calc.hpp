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
#ifndef FELIXS_PACK_MATH_UTILS_RANGES_CALC_HPP
#define FELIXS_PACK_MATH_UTILS_RANGES_CALC_HPP

#include <type_traits>
#include <limits>

namespace math {
	
	namespace details {
		bool is_inf(float t);
		bool is_inf(double t);
		bool is_inf(long double t);
	};
	
	/**
		* A function similar to std::clamp from <algorithm>
		* but avoids dangling reference problem, and
		* is useful for numeric values
	  */
	template<typename T>
	T clamp_value(T value, T lo, T hi) {
		if( hi < lo ) {
			return clamp_value(value, hi, lo);
		}
		return ((value < lo) ? lo : ((value > hi) ? hi : value));
	}
	
	template<typename T>
	bool is_in_range(T value, T lo, T hi) {
		if( hi < lo ) {
			return is_in_range(value, hi, lo);
		}
		return (value < lo ? false : (value > hi ? false : true));
	}
	
	///Linear interpolation between two values
	template<typename ValueType, typename FactorType = double>
	ValueType lerp(ValueType a, ValueType b, FactorType t)
	{
		if( a > b ) {
			return lerp(b, a, FactorType(1) - t);
		}
		if constexpr (std::is_floating_point_v<FactorType>) {
			if( details::is_inf(t) ) {
				if constexpr (std::is_floating_point_v<ValueType>) {
					return t;
				} else {
					if( t > FactorType(0) ) {
						return std::numeric_limits<ValueType>::max();
					} else {
						return std::numeric_limits<ValueType>::min();
					}
				}
			}
		}
		
		return static_cast<ValueType>(a*(FactorType(1) - t) + b*t);
	}
	
	///map one range to another
	template<typename FromType, typename ToType>
	ToType map_range(
		FromType value,
		FromType fromStart,
		FromType fromEnd,
		ToType toStart,
		ToType toEnd
	) {
		double pos;
		if constexpr (std::is_floating_point_v<FromType>) {
			if( details::is_inf(value) ) {
				pos = value;
			} else {
				pos = ( value - fromStart ) / static_cast<double>( fromEnd - fromStart );
			}
		} else {
			pos = ( value - fromStart ) / static_cast<double>( fromEnd - fromStart );
		}
		return lerp<ToType, double>(toStart, toEnd, pos);
	}
	
} //! namespace math

#endif //! FELIXS_PACK_MATH_UTILS_RANGES_CALC_HPP
