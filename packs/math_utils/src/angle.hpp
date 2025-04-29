#pragma once
// ::remove
#ifndef PACK_MATH_UTILS
#define PACK_MATH_UTILS
// ::else
// ::guard_start
// ::end

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

// ::remove
#endif //! PACK_MATH_UTILS
// ::else
// ::guard_end
// ::end
