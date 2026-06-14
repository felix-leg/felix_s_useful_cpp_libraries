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
#ifndef FELIXS_PACK_GEOMETRY_QUATERNIONS_HPP
#define FELIXS_PACK_GEOMETRY_QUATERNIONS_HPP
#include <optional>
#include <array>
#include <stdexcept>
#include <tuple>
#include <type_traits>

#include "vectors.hpp"
#include "matrices.hpp"

namespace quat {
	
	#pragma pack(4)
	struct Quaternion {
		union {
			float data[4];
			struct { float x, y, z, w; };
		};
		
		explicit(false) Quaternion() noexcept;
		explicit(false) Quaternion(float _x, float _y, float _z, float _w) noexcept;
		explicit(false) Quaternion(const ::vec::vec3& v, float s) noexcept;
		explicit(false) Quaternion(float s) noexcept;
		Quaternion(const Quaternion& other) = default;
		Quaternion(Quaternion&& other) = default;
		Quaternion& operator=(const Quaternion& other) = default;
		Quaternion& operator=(Quaternion&& other) = default;
		
		Quaternion& operator+=(const Quaternion& other) noexcept;
		Quaternion& operator-=(const Quaternion& other) noexcept;
		Quaternion& operator*=(const Quaternion& other) noexcept;
		Quaternion& operator*=(float t) noexcept;
		Quaternion& operator/=(const Quaternion& other);
		Quaternion& operator/=(float t);
		
		bool operator==(const Quaternion& other) const noexcept;
		bool operator!=(const Quaternion& other) const noexcept;
		
		/// conjugate
		Quaternion conj() const noexcept;
		/// magnitude
		float mag() const noexcept;
		/// norm = squared magnitude
		float norm() const noexcept;
		/// inverse
		std::optional<Quaternion> inv() const noexcept;
	};//! class Quaternion
	#pragma pack()
	
	[[nodiscard]] Quaternion operator+(const Quaternion& lhs, const Quaternion& rhs) noexcept;
	[[nodiscard]] Quaternion operator-(const Quaternion& lhs, const Quaternion& rhs) noexcept;
	[[nodiscard]] Quaternion operator*(const Quaternion& lhs, const Quaternion& rhs) noexcept;
	[[nodiscard]] Quaternion operator*(const Quaternion& lhs, float t) noexcept;
	[[nodiscard]] Quaternion operator*(float t, const Quaternion& rhs) noexcept;
	[[nodiscard]] Quaternion operator/(const Quaternion& lhs, const Quaternion& rhs);
	[[nodiscard]] Quaternion operator/(const Quaternion& lhs, float t);
	
	[[nodiscard]] Quaternion rotation_as_quat(const ::vec::vec3& a, float theta) noexcept;
	[[nodiscard]] ::vec::vec3 rotate(const Quaternion& rot, const ::vec::vec3& v);
	[[nodiscard]] Quaternion combine_rotations(const Quaternion& prev, const Quaternion& next) noexcept;
	[[nodiscard]] ::mat::mat3 as_mat3(const Quaternion& q) noexcept;
	[[nodiscard]] ::mat::mat4 as_mat4(const Quaternion& q) noexcept;
	
};//! namespace quat

namespace std {
	
	inline float abs(const quat::Quaternion& q) {
		return q.mag();
	}
	
};//! namespace std

#endif /* ! FELIXS_PACK_GEOMETRY_QUATERNIONS_HPP */
