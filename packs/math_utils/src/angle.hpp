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
#ifndef FELIXS_PACK_MATH_UTILS_ANGLE_HPP
#define FELIXS_PACK_MATH_UTILS_ANGLE_HPP

#include <compare>

namespace math {

	class angle {
		bool is_deg;
		float value;
		explicit(false) angle(float v, bool d) noexcept;
	public:
		angle(const angle& other) = default;
		angle& operator=(const angle& other) = default;
		
		[[nodiscard]] float as_radians() const noexcept;
		[[nodiscard]] float as_degrees() const noexcept;
		
		angle& operator+=(const angle& other) noexcept;
		angle& operator-=(const angle& other) noexcept;
		angle& operator*=(float mul) noexcept;
		angle& operator/=(float div);
		
		[[nodiscard]] bool operator==(const angle& other) const noexcept;
		[[nodiscard]] bool operator!=(const angle& other) const noexcept;
		friend std::strong_ordering operator<=>(const angle& lhs, const angle& rhs) noexcept;
	
		friend angle operator+(const angle& a, const angle& b) noexcept;
		friend angle operator-(const angle& a, const angle& b) noexcept;
		friend angle operator*(const angle& a, float m) noexcept;
		friend angle operator*(float m, const angle& a) noexcept;
		friend angle operator/(const angle& a, float div);
		friend angle operator-(const angle& a) noexcept;
		
		friend angle degrees(float value) noexcept;
		friend angle radians(float value) noexcept;
		
		/// clamp angle in [0, 360deg]
		[[nodiscard]] angle clamp360() const noexcept;
		/// clamp angle in [-180deg, 180deg]
		[[nodiscard]] angle clamp180() const noexcept;
		
		/// normalize angle in [0, 360deg]
		[[nodiscard]] angle norm360() const noexcept;
		/// normalize angle in [-180deg, 180deg]
		[[nodiscard]] angle norm180() const noexcept;
	};//! class angle
	
	[[nodiscard]] angle operator+(const angle& a, const angle& b) noexcept;
	[[nodiscard]] angle operator-(const angle& a, const angle& b) noexcept;
	[[nodiscard]] angle operator*(const angle& a, float m) noexcept;
	[[nodiscard]] angle operator*(float m, const angle& a) noexcept;
	[[nodiscard]] angle operator/(const angle& a, float div);
	[[nodiscard]] angle operator-(const angle& a) noexcept;
	[[nodiscard]] std::strong_ordering operator<=>(const angle& lhs, const angle& rhs) noexcept;
	
	[[nodiscard]] angle degrees(float value) noexcept;
	[[nodiscard]] angle radians(float value) noexcept;
	
	[[nodiscard]] float sin(const angle& a);
	[[nodiscard]] float cos(const angle& a);
	[[nodiscard]] float tan(const angle& a);
	
	struct arg_mag_t { angle arg; float mag; };
	[[nodiscard]] arg_mag_t arg_mag(float x, float y);

}//! namespace math

#endif //! FELIXS_PACK_MATH_UTILS_ANGLE_HPP
