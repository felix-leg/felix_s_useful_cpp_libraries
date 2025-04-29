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
	
	angle angle::clamp360() const noexcept {
		float nv = as_degrees();
		if( nv < 0.0f ) { nv = 0.0f; }
		if( nv > 360.0f ) { nv = 360.0f; }
		return {nv, true};
	}
	
	angle angle::clamp180() const noexcept {
		float nv = as_degrees();
		if( nv < -180.0f ) { nv = -180.0f; }
		if( nv > 180.0f ) { nv = 180.0f; }
		return {nv, true};
	}
	
	angle angle::norm360() const noexcept {
		float nv = as_degrees();
		while( nv < 0.0f ) {
			nv += 360.0f;
		}
		while( nv > 360.0f ) {
			nv -= 360.0f;
		}
		return {nv, true};
	}
	
	angle angle::norm180() const noexcept {
		float nv = as_degrees();
		while( nv < -180.0f ) {
			nv += 360.0f;
		}
		while( nv > 180.0f ) {
			nv -= 360.0f;
		}
		return {nv, true};
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
