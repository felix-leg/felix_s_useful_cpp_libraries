#pragma once
#ifndef FELIXS_PACK_MATH_UTILS_NUMBERS_HPP
#define FELIXS_PACK_MATH_UTILS_NUMBERS_HPP

#include <type_traits>

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
				return t;
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

#endif //! FELIXS_PACK_MATH_UTILS_NUMBERS_HPP
