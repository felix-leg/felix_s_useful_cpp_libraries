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
#ifndef FELIXS_PACK_PRIMITIVES
#define FELIXS_PACK_PRIMITIVES

#include <string>
#include <exception>

class ConversionError : public std::exception {
	private:
		const std::string description;
	public:
		enum Type {
			NOT_A_TYPE,
			OUT_OF_RANGE,
			OTHER
		};
		const Type error_type;
		ConversionError(const Type err_type, const std::string message);
		const char* what() const noexcept override;
};

enum class RoundMode {
	NEAREST,
	DOWN,
	UP,
	ZERO,
	
	DEFAULT
};


#define THE_SET(type) \
	/* to... */ \
	[[nodiscard]] std::string to_bin(type n, bool pad = false); \
	[[nodiscard]] std::string to_oct(type n); \
	[[nodiscard]] std::string to_dec(type n); \
	[[nodiscard]] std::string to_hex(type n, bool pad = false); \
	/* from... */ \
	[[nodiscard]] type from_bin(const std::string& text); \
	[[nodiscard]] type from_oct(const std::string& text); \
	[[nodiscard]] type from_dec(const std::string& text); \
	[[nodiscard]] type from_hex(const std::string& text); \
	/* from... with default */ \
	[[nodiscard]] type from_bin(const std::string& text, type default_value) noexcept; \
	[[nodiscard]] type from_oct(const std::string& text, type default_value) noexcept; \
	[[nodiscard]] type from_dec(const std::string& text, type default_value) noexcept; \
	[[nodiscard]] type from_hex(const std::string& text, type default_value) noexcept; \
	/* wrap/clamp add and sub */ \
	[[nodiscard]] type add_wrapped(type a, type b) noexcept; \
	[[nodiscard]] type sub_wrapped(type a, type b) noexcept; \
	[[nodiscard]] type add_clamped(type a, type b) noexcept; \
	[[nodiscard]] type sub_clamped(type a, type b) noexcept; \
	/* rounding */ \
	[[nodiscard]] type round_real_fm(float real, RoundMode r_mode, unsigned int zero_cut = 0) noexcept; \
	[[nodiscard]] type round_real_f(float real, unsigned int zero_cut = 0) noexcept; \
	[[nodiscard]] type round_real_dm(double real, RoundMode r_mode, unsigned int zero_cut = 0) noexcept; \
	[[nodiscard]] type round_real_d(double real, unsigned int zero_cut = 0) noexcept; \
	[[nodiscard]] type round_real_lm(long double real, RoundMode r_mode, unsigned int zero_cut = 0) noexcept; \
	[[nodiscard]] type round_real_l(long double real, unsigned int zero_cut = 0) noexcept;


namespace SByte {
	THE_SET(signed char)
	[[nodiscard]] signed char abs(signed char x);
	
	extern const signed char min_value;
	extern const signed char max_value;
}

namespace UByte {
	THE_SET(unsigned char)
	
	constexpr unsigned char min_value = 0;
	extern const unsigned char max_value;
}

namespace Short {
	THE_SET(signed short)
	[[nodiscard]] signed short abs(signed short x);
	
	extern const signed short min_value;
	extern const signed short max_value;
}

namespace UShort {
	THE_SET(unsigned short)
	
	constexpr unsigned short min_value = 0;
	extern const unsigned short max_value;
}

namespace Int {
	THE_SET(signed int)
	[[nodiscard]] signed int abs(signed int x);
	
	extern const signed int min_value;
	extern const signed int max_value;
}

namespace UInt {
	THE_SET(unsigned int)
	
	constexpr unsigned int min_value = 0;
	extern const unsigned int max_value;
}

namespace Long {
	THE_SET(signed long)
	[[nodiscard]] signed long abs(signed long x);
	
	extern const signed long min_value;
	extern const signed long max_value;
}

namespace ULong {
	THE_SET(unsigned long)
	
	constexpr unsigned long min_value = 0;
	extern const unsigned long max_value;
}

namespace LongLong {
	THE_SET(signed long long)
	[[nodiscard]] signed long long abs(signed long long x);
	
	extern const signed long long min_value;
	extern const signed long long max_value;
}

namespace ULongLong {
	THE_SET(unsigned long long)
	
	constexpr unsigned long long min_value = 0;
	extern const unsigned long long max_value;
}

#undef THE_SET


#define THE_SET(type) \
	[[nodiscard]] type abs(type x); \
	[[nodiscard]] bool is_nan(type x); \
	[[nodiscard]] bool is_inf(type x); \
	[[nodiscard]] bool is_normal(type x); \
	[[nodiscard]] bool is_same_value(type a, type b); \
	\
	[[nodiscard]] std::string to_scientific(type n); \
	[[nodiscard]] std::string to_general(type n); \
	[[nodiscard]] std::string to_fixed(type n); \
	[[nodiscard]] std::string to_hex(type n); \
	\
	[[nodiscard]] std::string to_scientific(type n, int precision); \
	[[nodiscard]] std::string to_general(type n, int precision); \
	[[nodiscard]] std::string to_fixed(type n, int precision); \
	[[nodiscard]] std::string to_hex(type n, int precision); \
	\
	[[nodiscard]] type from_scientific(const std::string& text); \
	[[nodiscard]] type from_general(const std::string& text); \
	[[nodiscard]] type from_fixed(const std::string& text); \
	[[nodiscard]] type from_hex(const std::string& text); \
	\
	[[nodiscard]] type from_scientific(const std::string& text, type default_value) noexcept; \
	[[nodiscard]] type from_general(const std::string& text, type default_value) noexcept; \
	[[nodiscard]] type from_fixed(const std::string& text, type default_value) noexcept; \
	[[nodiscard]] type from_hex(const std::string& text, type default_value) noexcept; \
	\
	/* min/max */ \
	[[nodiscard]] type max(type a, type b) noexcept; \
	[[nodiscard]] type min(type a, type b) noexcept; \
	/* rounding */ \
	[[nodiscard]] type round(type real, int dot_cut = 0) noexcept; \
	[[nodiscard]] type round_m(type real, RoundMode r_mode, int dot_cut = 0) noexcept; \
	/** Smallest difference between values */ \
	extern const type epsilon; \
	/** Positive infinity */ \
	extern const type pos_inf; \
	/** Negative infinity */ \
	extern const type neg_inf; \
	/** Quiet not-a-number */ \
	extern const type qNaN; \
	/** Signaling not-a-number; */ \
	extern const type sNaN; \
	\
	/** Compares two numbers with specifed method */ \
	class Cmp { \
		enum Method { \
			EXACT, ABSOLUTE, RELATIVE, ABS_REL, GENERAL \
		} method; \
		type abs_v; \
		type rel_v; \
		explicit Cmp(Method m, type a, type r) noexcept; \
	public: \
		Cmp() noexcept; \
		static Cmp exact() noexcept; \
		static Cmp abs(type abs_value) noexcept; \
		static Cmp rel(type rel_value) noexcept; \
		static Cmp abs_rel(type abs_value, type rel_value) noexcept; \
		static Cmp gen(type gen_value) noexcept; \
		\
		bool compare(type a, type b) const noexcept; \
	};

namespace Float {
	
	THE_SET(float)
	
} //! Float

namespace Double {
	
	THE_SET(double)
	
} //! Double

namespace LongDouble {
	
	THE_SET(long double)
	
} //! LongDouble

#undef THE_SET


#endif //! FELIXS_PACK_PRIMITIVES
