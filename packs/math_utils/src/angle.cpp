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

#include <cmath>
#include <numbers>
#include <utility>

namespace math {
	
	angle::angle(float v, Unit u) noexcept : unit{u}, value{v} {}
	
	float angle::as_radians() const noexcept {
		switch( unit ) {
			case DEG:
				return (value / 180.0f * std::numbers::pi_v<float>);
			case RAD:
				return value;
			case TURN:
				return (value / 0.5f * std::numbers::pi_v<float>);
		}
		std::unreachable();
	}
	
	float angle::as_degrees() const noexcept {
		switch( unit ) {
			case DEG:
				return value;
			case RAD:
				return (value / std::numbers::pi_v<float> * 180.0f);
			case TURN:
				return (value * 360.0f);
		}
		std::unreachable();
	}
	
	float angle::as_turns() const noexcept {
		switch( unit ) {
			case DEG:
				return value / 360.0f;
			case RAD:
				return (value / std::numbers::pi_v<float> * 2.0f);
			case TURN:
				return value;
		}
		std::unreachable();
	}
	
	angle& angle::operator+=(const angle& other) noexcept {
		switch( unit ) {
			case DEG:
				value += other.as_degrees();
				break;
			case RAD:
				value += other.as_radians();
				break;
			case TURN:
				value += other.as_turns();
				break;
		}
		return *this;
	}
	
	angle& angle::operator-=(const angle& other) noexcept {
		switch( unit ) {
			case DEG:
				value -= other.as_degrees();
				break;
			case RAD:
				value -= other.as_radians();
				break;
			case TURN:
				value -= other.as_turns();
				break;
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
		switch( unit ) {
			case DEG:
				return value == other.as_degrees();
			case RAD:
				return value == other.as_radians();
			case TURN:
				return value == other.as_turns();
		}
		std::unreachable();
	}
	
	bool angle::operator!=(const angle& other) const noexcept {
		return !(*this == other);
	}
	
	bool angle::equal_within(const angle& other, const angle& tolerance) noexcept {
		float tol;
		float diff;
		switch( unit ) {
			case DEG:
				diff = value - other.as_degrees();
				tol = tolerance.as_degrees();
				break;
			case RAD:
				diff = value - other.as_radians();
				tol = tolerance.as_radians();
				break;
			case TURN:
				diff = value - other.as_turns();
				tol = tolerance.as_turns();
				break;
		}
		return std::fabsf(diff) <= std::fabsf(tol);
	}
	
	angle operator+(const angle& a, const angle& b) noexcept {
		switch( a.unit ) {
			case angle::DEG:
				return {a.value + b.as_degrees(), angle::DEG};
			case angle::RAD:
				return {a.value + b.as_radians(), angle::RAD};
			case angle::TURN:
				return {a.value + b.as_turns(), angle::TURN};
		}
		std::unreachable();
	}
	
	angle operator-(const angle& a, const angle& b) noexcept {
		switch( a.unit ) {
			case angle::DEG:
				return {a.value - b.as_degrees(), angle::DEG};
			case angle::RAD:
				return {a.value - b.as_radians(), angle::RAD};
			case angle::TURN:
				return {a.value - b.as_turns(), angle::TURN};
		}
		std::unreachable();
	}
	angle operator*(const angle& a, float m) noexcept {
		return {a.value * m, a.unit};
	}
	
	angle operator*(float m, const angle& a) noexcept {
		return {a.value * m, a.unit};
	}
	
	angle operator/(const angle& a, float div) {
		return {a.value / div, a.unit};
	}
	
	angle operator-(const angle& a) noexcept {
		return {- a.value, a.unit};
	}
	
	std::strong_ordering operator<=>(const angle& lhs, const angle& rhs) noexcept {
		switch( lhs.unit ) {
			case angle::DEG:
				if( lhs.value < rhs.as_degrees() ) {
					return std::strong_ordering::less;
				} else if( lhs.value > rhs.as_degrees() ) {
					return std::strong_ordering::greater;
				}
				return std::strong_ordering::equivalent;
			case angle::RAD:
				if( lhs.value < rhs.as_radians() ) {
					return std::strong_ordering::less;
				} else if( lhs.value > rhs.as_radians() ) {
					return std::strong_ordering::greater;
				}
				return std::strong_ordering::equivalent;
			case angle::TURN:
				if( lhs.value < rhs.as_turns() ) {
					return std::strong_ordering::less;
				} else if( lhs.value > rhs.as_turns() ) {
					return std::strong_ordering::greater;
				}
				return std::strong_ordering::equivalent;
		}
		std::unreachable();
	}
	
	angle degrees(float value) noexcept {
		return {value, angle::DEG};
	}
	
	angle radians(float value) noexcept {
		return {value, angle::RAD};
	}
	
	angle turns(float value) noexcept {
		return {value, angle::TURN};
	}
	
	angle angle::clamp360() const noexcept {
		float nv = value;
		float v360;
		switch( unit ) {
			case DEG:
				v360 = 360.0f;
				break;
			case RAD:
				v360 = 2 * std::numbers::pi_v<float>;
				break;
			case TURN:
				v360 = 1.0f;
				break;
		}
		
		if( nv < 0.0f ) { nv = 0.0f; }
		if( nv > v360 ) { nv = v360; }
		return {nv, unit};
	}
	
	angle angle::clamp180() const noexcept {
		float nv = value;
		float v180;
		switch( unit ) {
			case DEG:
				v180 = 180.0f;
				break;
			case RAD:
				v180 = std::numbers::pi_v<float>;
				break;
			case TURN:
				v180 = 0.5f;
				break;
		}
		
		if( nv < -v180 ) { nv = -v180; }
		if( nv > v180 ) { nv = v180; }
		return {nv, unit};
	}
	
	angle angle::norm360() const noexcept {
		float nv = value;
		float v360;
		switch( unit ) {
			case DEG:
				v360 = 360.0f;
				break;
			case RAD:
				v360 = 2 * std::numbers::pi_v<float>;
				break;
			case TURN:
				v360 = 1.0f;
				break;
		}
		
		while( nv < 0.0f ) {
			nv += v360;
		}
		while( nv > v360 ) {
			nv -= v360;
		}
		return {nv, unit};
	}
	
	angle angle::norm180() const noexcept {
		float nv = value;
		float v180;
		switch( unit ) {
			case DEG:
				v180 = 180.0f;
				break;
			case RAD:
				v180 = std::numbers::pi_v<float>;
				break;
			case TURN:
				v180 = 0.5f;
				break;
		}
		
		while( nv < -v180 ) {
			nv += 2 * v180;
		}
		while( nv > v180 ) {
			nv -= 2 * v180;
		}
		return {nv, unit};
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
