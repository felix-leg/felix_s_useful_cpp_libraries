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

#include "quaternions.hpp"

#include <utility>
#include <cmath>

namespace quat {
	
	Quaternion::Quaternion() noexcept : x{0.0f}, y{0.0f}, z{0.0f}, w{0.0f} {}
	
	Quaternion::Quaternion(float _x, float _y, float _z, float _w) noexcept :
		x{_x}, y{_y}, z{_z}, w{_w} {}
	
	Quaternion::Quaternion(const ::vec::vec3& v, float s) noexcept :
		x{v.x}, y{v.y}, z{v.z}, w{s} {}
	
	Quaternion::Quaternion(float s) noexcept : x{0.0f}, y{0.0f}, z{0.0f}, w{s} {}
	
	Quaternion& Quaternion::operator+=(const Quaternion& other) noexcept {
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
		return *this;
	}
	
	Quaternion& Quaternion::operator-=(const Quaternion& other) noexcept {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;
		return *this;
	}
	
	Quaternion& Quaternion::operator*=(const Quaternion& other) noexcept {
		float _x = x * other.w + y * other.z - z * other.y + w * other.x;
		float _y = y * other.w + z * other.x + w * other.y - x * other.z;
		float _z = z * other.w + w * other.z + x * other.y - y * other.x;
		float _w = w * other.w - x * other.x - y * other.y - z * other.z;
		
		x = _x; y = _y; z = _z; w = _w;
		return *this;
	}
	
	Quaternion& Quaternion::operator*=(float t) noexcept {
		x *= t;
		y *= t;
		z *= t;
		w *= t;
		return *this;
	}
	
	Quaternion& Quaternion::operator/=(const Quaternion& other) {
		*this *= other.inv().value();
		return *this;
	}
	Quaternion& Quaternion::operator/=(float t) {
		*this *= Quaternion(t).inv().value();
		return *this;
	}
	
	Quaternion operator+(const Quaternion& lhs, const Quaternion& rhs) noexcept {
		return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w};
	}
	
	Quaternion operator-(const Quaternion& lhs, const Quaternion& rhs) noexcept {
		return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w};
	}
	
	Quaternion operator*(const Quaternion& lhs, const Quaternion& rhs) noexcept {
		return Quaternion(
			lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y + lhs.w * rhs.x,
			lhs.y * rhs.w + lhs.z * rhs.x + lhs.w * rhs.y - lhs.x * rhs.z,
			lhs.z * rhs.w + lhs.w * rhs.z + lhs.x * rhs.y - lhs.y * rhs.x,
			lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z
		);
	}
	
	Quaternion operator*(const Quaternion& lhs, float t) noexcept {
		return {lhs.x * t, lhs.y * t, lhs.z * t, lhs.w * t};
	}
	
	Quaternion operator*(float t, const Quaternion& rhs) noexcept {
		return {rhs.x * t, rhs.y * t, rhs.z * t, rhs.w * t};
	}
	
	Quaternion operator/(const Quaternion& lhs, const Quaternion& rhs) {
		return lhs * rhs.inv().value();
	}
	
	Quaternion operator/(const Quaternion& lhs, float t) {
		return lhs * Quaternion(t).inv().value();
	}
	
	bool Quaternion::operator==(const Quaternion& other) const noexcept {
		return (x==other.x) && (y==other.y) && (z==other.z) && (w==other.w);
	}
	
	bool Quaternion::operator!=(const Quaternion& other) const noexcept {
		return (x!=other.x) || (y!=other.y) || (z!=other.z) || (w!=other.w);
	}
	
	Quaternion Quaternion::conj() const noexcept {
		return {-x, -y, -z, w};
	}
	
	float Quaternion::mag() const noexcept {
		return std::sqrt(x*x + y*y + z*z + w*w);
	}
	
	float Quaternion::norm() const noexcept {
		return x*x + y*y + z*z + w*w;
	}
	
	std::optional<Quaternion> Quaternion::inv() const noexcept {
		float denom = x*x + y*y + z*z + w*w;
		if( denom == 0.0f ) {
			return std::nullopt;
		}
		return Quaternion(-x/denom, -y/denom, -z/denom, w/denom);
	}
	
	Quaternion rotation_as_quat(const ::vec::vec3& a, float theta) noexcept {
		float s = std::sin(theta/2.0f);
		float c = std::cos(theta/2.0f);
		return {s * a.x, s * a.y, s * a.z, c};
	}
	
	::vec::vec3 rotate(const Quaternion& rot, const ::vec::vec3& v) {
		Quaternion vq{v.x, v.y, v.z, 0.0f};
		auto result = (rot * vq) / rot;
		return ::vec::vec3(result.x, result.y, result.z);
	}
	
	Quaternion combine_rotations(const Quaternion& prev, const Quaternion& next) noexcept {
		return next * prev;
	}
	
	::mat::mat3 as_mat3(const Quaternion& q) noexcept {
		return {
			1 - 2 * q.y * q.y - 2 * q.z * q.z, 2 * (q.x * q.y - q.w * q.z), 2 * (q.x * q.z + q.w * q.y),
			2 * (q.x * q.y + q.w * q.z), 1 - 2 * q.x * q.x - 2 * q.z * q.z, 2 * (q.y * q.z - q.w * q.x),
			2 * (q.x * q.z - q.w * q.y), 2 * (q.y * q.z + q.w * q.x), 1 - 2 * q.x * q.x - 2 * q.y * q.y
		};
	}
	
	::mat::mat4 as_mat4(const Quaternion& q) noexcept {
		return {
			1 - 2 * q.y * q.y - 2 * q.z * q.z, 2 * (q.x * q.y - q.w * q.z), 2 * (q.x * q.z + q.w * q.y), 0.0f,
			2 * (q.x * q.y + q.w * q.z), 1 - 2 * q.x * q.x - 2 * q.z * q.z, 2 * (q.y * q.z - q.w * q.x), 0.0f,
			2 * (q.x * q.z - q.w * q.y), 2 * (q.y * q.z + q.w * q.x), 1 - 2 * q.x * q.x - 2 * q.y * q.y, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		};
	}
	
};//! namespace quat
