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
#include "primitives.hpp"

#include <cstdlib>
#include <cmath>
#include <cfenv>
#include <limits>
#include <charconv>
#include <system_error>
#include <utility>

#if __has_include(<stdckdint.h>)
	#define HAS_CKDINT
	#include <stdckdint.h>
#else
	#warning Checked aritmetic operations are not available on your system
#endif

typedef bool _Bool; // for <stdckdint.h>

ConversionError::ConversionError(const ConversionError::Type err_type, const std::string message)
	: description("Conversion error: " + message), error_type{err_type} {}

const char* ConversionError::what() const noexcept {
	return description.c_str();
}



const unsigned char UByte::max_value = std::numeric_limits<unsigned char>::max();
const signed char SByte::min_value = std::numeric_limits<signed char>::min();
const signed char SByte::max_value = std::numeric_limits<signed char>::max();

const unsigned short UShort::max_value = std::numeric_limits<unsigned short>::max();
const signed short Short::min_value = std::numeric_limits<signed short>::min();
const signed short Short::max_value = std::numeric_limits<signed short>::max();

const unsigned int UInt::max_value = std::numeric_limits<unsigned int>::max();
const signed int Int::min_value = std::numeric_limits<signed int>::min();
const signed int Int::max_value = std::numeric_limits<signed int>::max();

const unsigned long ULong::max_value = std::numeric_limits<unsigned long>::max();
const signed long Long::min_value = std::numeric_limits<signed long>::min();
const signed long Long::max_value = std::numeric_limits<signed long>::max();

const unsigned long long ULongLong::max_value = std::numeric_limits<unsigned long long>::max();
const signed long long LongLong::min_value = std::numeric_limits<signed long long>::min();
const signed long long LongLong::max_value = std::numeric_limits<signed long long>::max();

signed char SByte::abs(signed char x) {
	return (x < 0 ? -x : x);
}
signed short Short::abs(signed short x) {
	return (x < 0 ? -x : x);
}
signed int Int::abs(signed int x) {
	return std::abs(x);
}
signed long Long::abs(signed long x) {
	return std::labs(x);
}
signed long long LongLong::abs(signed long long x) {
	return std::llabs(x);
}

#define THE_SET() \
	THE_FN(signed char, SByte, false) \
	THE_FN(unsigned char, UByte, true) \
	THE_FN(signed short, Short, false) \
	THE_FN(unsigned short, UShort, true) \
	THE_FN(signed int, Int, false) \
	THE_FN(unsigned int, UInt, true) \
	THE_FN(signed long, Long, false) \
	THE_FN(unsigned long, ULong, true) \
	THE_FN(signed long long, LongLong, false) \
	THE_FN(unsigned long long, ULongLong, true)

#ifdef HAS_CKDINT
	#define THE_FN(type, ns, is_unsigned) type ns::add_wrapped(type a, type b) noexcept { \
		type r; \
		[[maybe_unused]] bool ov = ckd_add(&r, a, b); \
		return r; \
	}
#else
	#define THE_FN(type, ns, is_unsigned) type ns::add_wrapped(type a, type b) noexcept { \
		return a + b; \
	}
#endif

THE_SET()

#undef THE_FN
#ifdef HAS_CKDINT
	#define THE_FN(type, ns, is_unsigned) type ns::sub_wrapped(type a, type b) noexcept { \
		type r; \
		[[maybe_unused]] bool ov = ckd_sub(&r, a, b); \
		return r; \
	}
#else
	#define THE_FN(type, ns, is_unsigned) type ns::sub_wrapped(type a, type b) noexcept { \
		return a - b; \
	}
#endif

THE_SET()

#undef THE_FN
#ifdef HAS_CKDINT
	#define THE_FN(type, ns, is_unsigned) type ns::add_clamped(type a, type b) noexcept { \
		type r; \
		bool ov = ckd_add(&r, a, b); \
		if( ov ) { \
			if constexpr ( is_unsigned ) { \
				return ns::max_value; \
			} else { \
				if( a < 0 && b < 0 ) { \
					return ns::min_value; \
				} else { \
					return ns::max_value; \
				} \
			} \
		} \
		return r; \
	}
#else
	#define THE_FN(type, ns, is_unsigned) type ns::add_clamped(type a, type b) noexcept { \
		return a + b; \
	}
#endif

THE_SET()

#undef THE_FN
#ifdef HAS_CKDINT
	#define THE_FN(type, ns, is_unsigned) type ns::sub_clamped(type a, type b) noexcept { \
		type r; \
		bool ov = ckd_sub(&r, a, b); \
		if( ov ) { \
			if constexpr ( is_unsigned ) { \
				return 0; \
			} else { \
				if( a < 0 && b > 0 ) { \
					return ns::min_value; \
				} else { \
					return ns::max_value; \
				} \
			} \
		} \
		return r; \
	}
#else
	#define THE_FN(type, ns, is_unsigned) type ns::sub_clamped(type a, type b) noexcept { \
		return a - b; \
	}
#endif

THE_SET()

#undef THE_FN
#define THE_FN(type, ns, is_unsigned) std::string ns::to_bin(type n, bool pad) { \
	constexpr auto out_size = 8 * sizeof(type); \
	char output[ out_size + 1 ] = {0}; \
	bool neg; \
	if constexpr( is_unsigned ) { \
		neg = false; \
	} else { \
		if( n < 0 ) { neg = true; n = -n; } \
		else { neg = false; } \
	} \
	auto result = std::to_chars(output, output + sizeof(output), n, 2); \
	if( result.ec == std::errc{} ) { \
		std::string out_str{output}; \
		if( pad ) { \
			while( out_str.length() < out_size ) { \
				out_str = "0" + out_str; \
			} \
		} \
		if constexpr( is_unsigned ) { \
			return out_str; \
		} else { \
			return (neg ? "-" : "") + out_str; \
		} \
	} else { \
		throw ConversionError{ ConversionError::OTHER, std::make_error_code(result.ec).message() }; \
	} \
 }

THE_SET()

#undef THE_FN
#define THE_FN(type, ns, is_unsigned) std::string ns::to_oct(type n) { \
	constexpr auto out_size = 4 * sizeof(type); \
	char output[ out_size + 1 ] = {0}; \
	auto result = std::to_chars(output, output + sizeof(output), n, 8); \
	if( result.ec == std::errc{} ) { \
		return std::string{output}; \
	} else { \
		throw ConversionError{ ConversionError::OTHER, std::make_error_code(result.ec).message() }; \
	} \
 }

THE_SET()

#undef THE_FN
#define THE_FN(type, ns, is_unsigned) std::string ns::to_dec(type n) { \
	constexpr auto out_size = 4 * sizeof(type); \
	char output[ out_size + 1 ] = {0}; \
	auto result = std::to_chars(output, output + sizeof(output), n, 10); \
	if( result.ec == std::errc{} ) { \
		return std::string{output}; \
	} else { \
		throw ConversionError{ ConversionError::OTHER, std::make_error_code(result.ec).message() }; \
	} \
 }

THE_SET()

#undef THE_FN
#define THE_FN(type, ns, is_unsigned) std::string ns::to_hex(type n, bool pad) { \
	constexpr auto out_size = 2 * sizeof(type); \
	char output[ out_size + 1 ] = {0}; \
	bool neg; \
	if constexpr( is_unsigned ) { \
		neg = false; \
	} else { \
		if( n < 0 ) { neg = true; n = -n; } \
		else { neg = false; } \
	} \
	auto result = std::to_chars(output, output + sizeof(output), n, 16); \
	if( result.ec == std::errc{} ) { \
		std::string out_str{output}; \
		if( pad ) { \
			while( out_str.length() < out_size ) { \
				out_str = "0" + out_str; \
			} \
		} \
		if constexpr( is_unsigned ) { \
			return out_str; \
		} else { \
			return (neg ? "-" : "") + out_str; \
		} \
	} else { \
		throw ConversionError{ ConversionError::OTHER, std::make_error_code(result.ec).message() }; \
	} \
 }

THE_SET()

#undef THE_FN

#define FROM_STRING(type, base) \
	type output; \
	auto result = std::from_chars(text.c_str(), text.c_str() + text.length(), output, base); \
	if( result.ec == std::errc{} ) { \
		return output; \
	} else if( result.ec == std::errc::invalid_argument ) { \
		throw ConversionError{ ConversionError::NOT_A_TYPE, "String is not a " #type }; \
	} else if( result.ec == std::errc::result_out_of_range ) { \
		throw ConversionError{ ConversionError::OUT_OF_RANGE, "String is out of range for " #type " type" }; \
	} else { \
		throw ConversionError{ ConversionError::OTHER, std::make_error_code(result.ec).message() }; \
	}

#define THE_FN(type, ns, is_unsigned) type ns::from_bin(const std::string& text) { \
	FROM_STRING(type, 2) \
 }

THE_SET()

#undef THE_FN
#define THE_FN(type, ns, is_unsigned) type ns::from_oct(const std::string& text) { \
	FROM_STRING(type, 8) \
 }

THE_SET()

#undef THE_FN
#define THE_FN(type, ns, is_unsigned) type ns::from_dec(const std::string& text) { \
	FROM_STRING(type, 10) \
 }

THE_SET()

#undef THE_FN
#define THE_FN(type, ns, is_unsigned) type ns::from_hex(const std::string& text) { \
	FROM_STRING(type, 16) \
 }

THE_SET()

#undef THE_FN

#undef FROM_STRING
#define FROM_STRING(type, base) \
	type output; \
	auto result = std::from_chars(text.c_str(), text.c_str() + text.length(), output, base); \
	if( result.ec == std::errc{} ) { \
		return output; \
	} else { \
		return default_value; \
	}

#define THE_FN(type, ns, is_unsigned) type ns::from_bin(const std::string& text, type default_value) noexcept { \
	FROM_STRING(type, 2) \
 }

THE_SET()

#undef THE_FN
#define THE_FN(type, ns, is_unsigned) type ns::from_oct(const std::string& text, type default_value) noexcept { \
	FROM_STRING(type, 8) \
 }

THE_SET()

#undef THE_FN
#define THE_FN(type, ns, is_unsigned) type ns::from_dec(const std::string& text, type default_value) noexcept { \
	FROM_STRING(type, 10) \
 }

THE_SET()

#undef THE_FN
#define THE_FN(type, ns, is_unsigned) type ns::from_hex(const std::string& text, type default_value) noexcept { \
	FROM_STRING(type, 16) \
 }

THE_SET()

#undef THE_FN
#undef FROM_STRING

#define ROUND_FN(r_type, type, one, ten) \
	r_type scale = one; \
	if( zero_cut > 0 ) { \
		scale = std::pow(ten, static_cast<r_type>(zero_cut)); \
	} \
	int old_r_mode = std::fegetround(); \
	switch( r_mode ) { \
		case RoundMode::NEAREST: std::fesetround(FE_TONEAREST); break; \
		case RoundMode::DOWN: std::fesetround(FE_DOWNWARD); break; \
		case RoundMode::UP: std::fesetround(FE_UPWARD); break; \
		case RoundMode::ZERO: std::fesetround(FE_TOWARDZERO); break; \
		default: break; \
	} \
	real = std::rint(real / scale) * scale; \
	std::fesetround(old_r_mode); \
	return static_cast<type>(real);
#define THE_FN(type, ns, is_unsigned) \
 type ns::round_real_fm(float real, RoundMode r_mode, unsigned int zero_cut) noexcept { \
	 ROUND_FN(float, type, 1.0f, 10.0f) \
 } \
 type ns::round_real_f(float real, unsigned int zero_cut) noexcept { \
	 return ns::round_real_fm(real, RoundMode::DEFAULT, zero_cut); \
 } \
 type ns::round_real_dm(double real, RoundMode r_mode, unsigned int zero_cut) noexcept { \
	 ROUND_FN(double, type, 1.0, 10.0) \
 } \
 type ns::round_real_d(double real, unsigned int zero_cut) noexcept { \
	 return ns::round_real_dm(real, RoundMode::DEFAULT, zero_cut); \
 } \
 type ns::round_real_lm(long double real, RoundMode r_mode, unsigned int zero_cut) noexcept { \
	 ROUND_FN(long double, type, 1.0l, 10.0l) \
 } \
 type ns::round_real_l(long double real, unsigned int zero_cut) noexcept { \
	 return ns::round_real_lm(real, RoundMode::DEFAULT, zero_cut); \
 }

THE_SET()

#undef THE_FN
#undef ROUND_FN

#undef THE_SET


const float Float::epsilon = std::numeric_limits<float>::epsilon();
const double Double::epsilon = std::numeric_limits<double>::epsilon();
const long double LongDouble::epsilon = std::numeric_limits<long double>::epsilon();

const float Float::pos_inf = std::numeric_limits<float>::infinity();
const double Double::pos_inf = std::numeric_limits<double>::infinity();
const long double LongDouble::pos_inf = std::numeric_limits<long double>::infinity();

const float Float::neg_inf = - std::numeric_limits<float>::infinity();
const double Double::neg_inf = - std::numeric_limits<double>::infinity();
const long double LongDouble::neg_inf = - std::numeric_limits<long double>::infinity();

const float Float::qNaN = std::numeric_limits<float>::quiet_NaN();
const double Double::qNaN = std::numeric_limits<double>::quiet_NaN();
const long double LongDouble::qNaN = std::numeric_limits<long double>::quiet_NaN();

const float Float::sNaN = std::numeric_limits<float>::signaling_NaN();
const double Double::sNaN = std::numeric_limits<double>::signaling_NaN();
const long double LongDouble::sNaN = std::numeric_limits<long double>::signaling_NaN();

float Float::abs(float x) {
	return std::fabsf(x);
}
double Double::abs(double x) {
	return std::fabs(x);
}
long double LongDouble::abs(long double x) {
	return std::fabsl(x);
}

bool Float::is_nan(float x) {
	return std::isnan(x);
}
bool Double::is_nan(double x) {
	return std::isnan(x);
}
bool LongDouble::is_nan(long double x) {
	return std::isnan(x);
}

bool Float::is_inf(float x) {
	return std::isinf(x);
}
bool Double::is_inf(double x) {
	return std::isinf(x);
}
bool LongDouble::is_inf(long double x) {
	return std::isinf(x);
}

bool Float::is_normal(float x) {
	return std::isnormal(x);
}
bool Double::is_normal(double x) {
	return std::isnormal(x);
}
bool LongDouble::is_normal(long double x) {
	return std::isnormal(x);
}

bool Float::is_same_value(float a, float b) {
	if( Float::is_nan(a) && Float::is_nan(b) ) {
		return true;
	}
	if( Float::is_inf(a) && Float::is_inf(b) ) {
		if( a > 0.0f && b > 0.0f ) { //Positive infinity
			return true;
		}
		if( a < 0.0f && b < 0.0f ) { //Negative infinity
			return true;
		}
		return false;
	}
	// Normal values
	return a == b;
}
bool Double::is_same_value(double a, double b) {
	if( Double::is_nan(a) && Double::is_nan(b) ) {
		return true;
	}
	if( Double::is_inf(a) && Double::is_inf(b) ) {
		if( a > 0.0 && b > 0.0 ) { //Positive infinity
			return true;
		}
		if( a < 0.0 && b < 0.0 ) { //Negative infinity
			return true;
		}
		return false;
	}
	// Normal values
	return a == b;
}
bool LongDouble::is_same_value(long double a, long double b) {
	if( LongDouble::is_nan(a) && LongDouble::is_nan(b) ) {
		return true;
	}
	if( LongDouble::is_inf(a) && LongDouble::is_inf(b) ) {
		if( a > 0.0l && b > 0.0l ) { //Positive infinity
			return true;
		}
		if( a < 0.0l && b < 0.0l ) { //Negative infinity
			return true;
		}
		return false;
	}
	// Normal values
	return a == b;
}

float Float::min(float a, float b) noexcept {
	return (a < b ? a : b);
}
double Double::min(double a, double b) noexcept {
	return (a < b ? a : b);
}
long double LongDouble::min(long double a, long double b) noexcept {
	return (a < b ? a : b);
}

float Float::max(float a, float b) noexcept {
	return (a > b ? a : b);
}
double Double::max(double a, double b) noexcept {
	return (a > b ? a : b);
}
long double LongDouble::max(long double a, long double b) noexcept {
	return (a > b ? a : b);
}

#define ROUND_FN(type, one, ten) \
	type scale = one; \
	if( dot_cut != 0 ) { \
		scale = std::pow(ten, static_cast<type>(dot_cut)); \
	} \
	int old_r_mode = std::fegetround(); \
	switch( r_mode ) { \
		case RoundMode::NEAREST: std::fesetround(FE_TONEAREST); break; \
		case RoundMode::DOWN: std::fesetround(FE_DOWNWARD); break; \
		case RoundMode::UP: std::fesetround(FE_UPWARD); break; \
		case RoundMode::ZERO: std::fesetround(FE_TOWARDZERO); break; \
		default: break; \
	} \
	real = std::rint(real * scale) / scale; \
	std::fesetround(old_r_mode); \
	return real;

float Float::round_m(float real, RoundMode r_mode, int dot_cut) noexcept {
	ROUND_FN(float, 1.0f, 10.0f)
}
float Float::round(float real, int dot_cut) noexcept {
	return Float::round_m(real, RoundMode::DEFAULT, dot_cut);
}

double Double::round_m(double real, RoundMode r_mode, int dot_cut) noexcept {
	ROUND_FN(float, 1.0, 10.0)
}
double Double::round(double real, int dot_cut) noexcept {
	return Double::round_m(real, RoundMode::DEFAULT, dot_cut);
}

long double LongDouble::round_m(long double real, RoundMode r_mode, int dot_cut) noexcept {
	ROUND_FN(long double, 1.0l, 10.0l)
}
long double LongDouble::round(long double real, int dot_cut) noexcept {
	return LongDouble::round_m(real, RoundMode::DEFAULT, dot_cut);
}

#undef ROUND_FN

#define CMP_DEF(type, ns, zero, one) \
	namespace ns { \
		Cmp::Cmp(Cmp::Method m, type a, type r) noexcept : method{m}, abs_v{a}, rel_v{r} {}; \
		Cmp::Cmp() noexcept : Cmp(EXACT, zero, zero) {}; \
		Cmp Cmp::exact() noexcept { return Cmp{EXACT, zero, zero}; } \
		Cmp Cmp::abs(type abs_value) noexcept { return Cmp{ABSOLUTE, abs_value, zero}; } \
		Cmp Cmp::rel(type rel_value) noexcept { return Cmp{RELATIVE, zero, rel_value}; } \
		Cmp Cmp::abs_rel(type abs_value, type rel_value) noexcept \
			{ return Cmp{ABS_REL, abs_value, rel_value}; } \
		Cmp Cmp::gen(type gen_value) noexcept { return Cmp{GENERAL, gen_value, zero}; } \
		bool Cmp::compare(type a, type b) const noexcept { \
			switch( method ) { \
				case EXACT: return (a == b); \
				case ABSOLUTE: return (ns::abs(a-b) <= abs_v); \
				case RELATIVE: return (ns::abs(a-b) <= (rel_v * ns::max(ns::abs(a), ns::abs(b)))); \
				case ABS_REL: return (ns::abs(a-b) <= ns::max(abs_v, rel_v * ns::max(ns::abs(a), ns::abs(b)))); \
				case GENERAL: return (ns::abs(a-b) <= abs_v * ns::max(one, ns::max(ns::abs(a), ns::abs(b)))); \
			} \
			std::unreachable(); \
		} \
	}

CMP_DEF(float, Float, 0.0f, 1.0f)
CMP_DEF(double, Double, 0.0, 1.0)
CMP_DEF(long double, LongDouble, 0.0l, 1.0l)

#undef CMP_DEF

#define TO_STRING(form_name) \
		char output[50] = {0}; \
		auto result = std::to_chars(output, output + 50, n, std::chars_format::form_name); \
		if( result.ec == std::errc{} ) { \
			return std::string{&output[0]}; \
		} else { \
			throw ConversionError{ ConversionError::OTHER, std::make_error_code(result.ec).message() }; \
		}

#define TO_STRING_P(form_name) \
		char output[50] = {0}; \
		auto result = std::to_chars(output, output + 50, n, std::chars_format::form_name, precision); \
		if( result.ec == std::errc{} ) { \
			return std::string{&output[0]}; \
		} else { \
			throw ConversionError{ ConversionError::OTHER, std::make_error_code(result.ec).message() }; \
		}

#define TO_SCI(type, fn_name) \
	std::string fn_name(type n) { TO_STRING(scientific) } \
	std::string fn_name(type n, int precision) { TO_STRING_P(scientific) }

TO_SCI(float, Float::to_scientific)
TO_SCI(double, Double::to_scientific)
TO_SCI(long double, LongDouble::to_scientific)

#undef TO_SCI

#define TO_GEN(type, fn_name) \
	std::string fn_name(type n) { TO_STRING(general) } \
	std::string fn_name(type n, int precision) { TO_STRING_P(general) }

TO_GEN(float, Float::to_general)
TO_GEN(double, Double::to_general)
TO_GEN(long double, LongDouble::to_general)

#undef TO_GEN

#define TO_FIX(type, fn_name)  \
	std::string fn_name(type n) { TO_STRING(fixed) } \
	std::string fn_name(type n, int precision) { TO_STRING_P(fixed) }

TO_FIX(float, Float::to_fixed)
TO_FIX(double, Double::to_fixed)
TO_FIX(long double, LongDouble::to_fixed)

#undef TO_FIX

#define TO_HEX(type, fn_name) \
	std::string fn_name(type n) { TO_STRING(hex) } \
	std::string fn_name(type n, int precision) { TO_STRING_P(hex) }

TO_HEX(float, Float::to_hex)
TO_HEX(double, Double::to_hex)
TO_HEX(long double, LongDouble::to_hex)

#undef TO_HEX

#undef TO_STRING
#undef TO_STRING_P

#define FROM_STRING(type, form_mask) \
	type output; \
	auto result = std::from_chars(text.c_str(), text.c_str() + text.size(), output, std::chars_format::form_mask); \
	if( result.ec == std::errc{} ) { \
		return output; \
	} else if( result.ec == std::errc::invalid_argument ) { \
		throw ConversionError{ ConversionError::NOT_A_TYPE, "String is not a " #type }; \
	} else if( result.ec == std::errc::result_out_of_range ) { \
		throw ConversionError{ ConversionError::OUT_OF_RANGE, "String is out of range for " #type " type" }; \
	} else { \
		throw ConversionError{ ConversionError::OTHER, std::make_error_code(result.ec).message() }; \
	}

#define FROM_STRING_FMT_0(type) \
	type output; \
	auto result = std::from_chars(text.c_str(), text.c_str() + text.size(), output, std::chars_format::scientific); \
	if( result.ec != std::errc{} ) { \
		result = std::from_chars(text.c_str(), text.c_str() + text.size(), output, std::chars_format::fixed); \
	} \
	if( result.ec == std::errc{} ) { \
		return output; \
	} else if( result.ec == std::errc::invalid_argument ) { \
		throw ConversionError{ ConversionError::NOT_A_TYPE, "String is not a " #type }; \
	} else if( result.ec == std::errc::result_out_of_range ) { \
		throw ConversionError{ ConversionError::OUT_OF_RANGE, "String is out of range for " #type " type" }; \
	} else { \
		throw ConversionError{ ConversionError::OTHER, std::make_error_code(result.ec).message() }; \
	}

#define FROM_STRING_D(type, form_mask) \
	type output; \
	auto result = std::from_chars(text.c_str(), text.c_str() + text.size(), output, std::chars_format::form_mask); \
	if( result.ec == std::errc{} ) { \
		return output; \
	} else { \
		return default_value; \
	}

#define FROM_STRING_D_FMT_0(type) \
	type output; \
	auto result = std::from_chars(text.c_str(), text.c_str() + text.size(), output, std::chars_format::scientific); \
	if( result.ec != std::errc{} ) { \
		result = std::from_chars(text.c_str(), text.c_str() + text.size(), output, std::chars_format::fixed); \
	} \
	if( result.ec == std::errc{} ) { \
		return output; \
	} else { \
		return default_value; \
	}

#define FROM_SCI(type, fn_name) \
	type fn_name(const std::string& text) { FROM_STRING(type, scientific) } \
	type fn_name(const std::string& text, type default_value) noexcept { FROM_STRING_D(type, scientific) }

FROM_SCI(float, Float::from_scientific)
FROM_SCI(double, Double::from_scientific)
FROM_SCI(long double, LongDouble::from_scientific)

#undef FROM_SCI
#define FROM_FIX(type, fn_name) \
	type fn_name(const std::string& text) { FROM_STRING(type, fixed) } \
	type fn_name(const std::string& text, type default_value) noexcept { FROM_STRING_D(type, fixed) }

FROM_FIX(float, Float::from_fixed)
FROM_FIX(double, Double::from_fixed)
FROM_FIX(long double, LongDouble::from_fixed)

#undef FROM_FIX
#define FROM_GEN(type, fn_name) \
	type fn_name(const std::string& text) { FROM_STRING_FMT_0(type) } \
	type fn_name(const std::string& text, type default_value) noexcept { FROM_STRING_D_FMT_0(type) }

FROM_GEN(float, Float::from_general)
FROM_GEN(double, Double::from_general)
FROM_GEN(long double, LongDouble::from_general)

#undef FROM_GEN
#define FROM_HEX(type, fn_name) \
	type fn_name(const std::string& text) { FROM_STRING(type, hex) } \
	type fn_name(const std::string& text, type default_value) noexcept { FROM_STRING_D(type, hex) }

FROM_HEX(float, Float::from_hex)
FROM_HEX(double, Double::from_hex)
FROM_HEX(long double, LongDouble::from_hex)

#undef FROM_HEX

#undef FROM_STRING
#undef FROM_STRING_FMT_0

