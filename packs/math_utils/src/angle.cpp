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
#include "angle.hpp"

#include <numbers>
#include <cmath>

namespace math {
	
	angle::angle(float v, bool d) noexcept : is_deg{d}, value{v} {}
	
	float angle::as_radians() const noexcept {
		if( is_deg ) {
			return (value / 180.0f * std::numbers::pi_v<float>);
		} else {
			return value;
		}
	}
	
	float angle::as_degrees() const noexcept {
		if( is_deg ) {
			return value;
		} else {
			return (value / std::numbers::pi_v<float> * 180.0f);
		}
	}
	
	float angle::as_turns() const noexcept {
		if( is_deg ) {
			return value / 360.0f;
		} else {
			return (value / std::numbers::pi_v<float> * 2.0f);
		}
	}
	
	angle& angle::operator+=(const angle& other) noexcept {
		if( is_deg ) {
			value += other.as_degrees();
		} else {
			value += other.as_radians();
		}
		return *this;
	}
	
	angle& angle::operator-=(const angle& other) noexcept {
		if( is_deg ) {
			value -= other.as_degrees();
		} else {
			value -= other.as_radians();
		}
		return *this;
	}
	
	angle& angle::operator*=(float mul) noexcept {
		value *= mul;
		return *this;
	}
	
	angle& angle::operator/=(float div) {
		value /= div;
		return *this;
	}
	
	bool angle::operator==(const angle& other) const noexcept {
		if( is_deg ) {
			return value == other.as_degrees();
		} else {
			return value == other.as_radians();
		}
	}
	
	bool angle::operator!=(const angle& other) const noexcept {
		return !(*this == other);
	}
	
	bool angle::equal_within(const angle& other, const angle& tolerance) noexcept {
		float tol;
		float diff;
		if( is_deg ) {
			diff = value - other.as_degrees();
			tol = tolerance.as_degrees();
		} else {
			diff = value - other.as_radians();
			tol = tolerance.as_radians();
		}
		return std::fabsf(diff) <= std::fabsf(tol);
	}
	
	angle operator+(const angle& a, const angle& b) noexcept {
		if( a.is_deg ) {
			return {a.value + b.as_degrees(), true};
		} else {
			return {a.value + b.as_radians(), false};
		}
	}
	
	angle operator-(const angle& a, const angle& b) noexcept {
		if( a.is_deg ) {
			return {a.value - b.as_degrees(), true};
		} else {
			return {a.value - b.as_radians(), false};
		}
	}
	angle operator*(const angle& a, float m) noexcept {
		return {a.value * m, a.is_deg};
	}
	
	angle operator*(float m, const angle& a) noexcept {
		return {a.value * m, a.is_deg};
	}
	
	angle operator/(const angle& a, float div) {
		return {a.value / div, a.is_deg};
	}
	
	angle operator-(const angle& a) noexcept {
		return {- a.value, a.is_deg};
	}
	
	std::strong_ordering operator<=>(const angle& lhs, const angle& rhs) noexcept {
		if( lhs.is_deg ) {
			if( lhs.value < rhs.as_degrees() ) {
				return std::strong_ordering::less;
			} else if( lhs.value > rhs.as_degrees() ) {
				return std::strong_ordering::greater;
			}
			return std::strong_ordering::equivalent;
		} else {
			if( lhs.value < rhs.as_radians() ) {
				return std::strong_ordering::less;
			} else if( lhs.value > rhs.as_radians() ) {
				return std::strong_ordering::greater;
			}
			return std::strong_ordering::equivalent;
		}
	}
	
	angle degrees(float value) noexcept {
		return {value, true};
	}
	
	angle radians(float value) noexcept {
		return {value, false};
	}
	
	angle turns(float value) noexcept {
		return {360.0f * value, true};
	}
	
	angle angle::clamp360() const noexcept {
		float nv = value;
		float v360;
		if( is_deg ) {
			v360 = 360.0f;
		} else {
			v360 = 2 * std::numbers::pi_v<float>;
		}
		
		if( nv < 0.0f ) { nv = 0.0f; }
		if( nv > v360 ) { nv = v360; }
		return {nv, is_deg};
	}
	
	angle angle::clamp180() const noexcept {
		float nv = value;
		float v180;
		if( is_deg ) {
			v180 = 180.0f;
		} else {
			v180 = std::numbers::pi_v<float>;
		}
		
		if( nv < -v180 ) { nv = -v180; }
		if( nv > v180 ) { nv = v180; }
		return {nv, is_deg};
	}
	
	angle angle::norm360() const noexcept {
		float nv = value;
		float v360;
		if( is_deg ) {
			v360 = 360.0f;
		} else {
			v360 = 2 * std::numbers::pi_v<float>;
		}
		
		while( nv < 0.0f ) {
			nv += v360;
		}
		while( nv > v360 ) {
			nv -= v360;
		}
		return {nv, is_deg};
	}
	
	angle angle::norm180() const noexcept {
		float nv = value;
		float v180;
		if( is_deg ) {
			v180 = 180.0f;
		} else {
			v180 = std::numbers::pi_v<float>;
		}
		
		while( nv < -v180 ) {
			nv += 2 * v180;
		}
		while( nv > v180 ) {
			nv -= 2 * v180;
		}
		return {nv, is_deg};
	}
	
	float sin(const angle& a) {
		return std::sin(a.as_radians());
	}
	
	float cos(const angle& a) {
		return std::cos(a.as_radians());
	}
	
	float tan(const angle& a) {
		return std::tan(a.as_radians());
	}
	
	arg_mag_t arg_mag(float x, float y) {
		return { radians(std::atan2(y,x)), std::hypot(x,y) };
	}

}//! namespace math
