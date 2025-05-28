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
#ifndef FELIXS_PACK_GEOMETRY_TRANSFORM
#define FELIXS_PACK_GEOMETRY_TRANSFORM
#include "geometry.hpp"

namespace transform {
	
	/// 2x2 matrix for 2D rotation around the origin
	[[nodiscard]] mat::mat2 rotation_m2(float theta) noexcept;
	/// 3x3 matrix for 2D translation
	[[nodiscard]] mat::mat3 translation_m3(float x, float y) noexcept;
	[[nodiscard]] mat::mat3 translation_m3(const vec::vec2& v) noexcept;
	
	/// 3x3 matrix for 3D rotation around the x axis
	[[nodiscard]] mat::mat3 rotation_m3_x(float theta) noexcept;
	/// 3x3 matrix for 3D rotation around the y axis
	[[nodiscard]] mat::mat3 rotation_m3_y(float theta) noexcept;
	/// 3x3 matrix for 3D rotation around the z axis
	[[nodiscard]] mat::mat3 rotation_m3_z(float theta) noexcept;
	/// 3x3 matrix for 3D rotation around arbitrary `a` axis
	[[nodiscard]] mat::mat3 rotation_m3_a(vec::vec3 a, float theta) noexcept;
	
	/// 3x3 matrix for mirror by normal `n`
	[[nodiscard]] mat::mat3 mirror_m3(vec::vec3 n) noexcept;
	/// 3x3 matrix of "inside-out"ing around normal `n`
	[[nodiscard]] mat::mat3 involution_m3(vec::vec3 n) noexcept;
	
	/// 3x3 matrix of an uniform scale
	[[nodiscard]] mat::mat3 scale_m3(float s) noexcept;
	/// 3x3 matrix of a non-uniform scale
	[[nodiscard]] mat::mat3 scale_m3(float sx, float sy, float sz) noexcept;
	[[nodiscard]] mat::mat3 scale_m3(const vec::vec3& v) noexcept;
	/// 3x3 matrix of a scale along a vector `a` with a factor `s`
	[[nodiscard]] mat::mat3 scale_m3(const vec::vec3& a, float s) noexcept;
	
	/// 3x3 matrix of a skew along `in_dir` vector by `theta` with `perp` vector as side vector
	[[nodiscard]] mat::mat3 skew_m3(float theta, const vec::vec3& in_dir, const vec::vec3& perp) noexcept;
	
	/// 4x4 matrix for 3D translation
	[[nodiscard]] mat::mat4 translation_m4(float x, float y, float z) noexcept;
	[[nodiscard]] mat::mat4 translation_m4(const vec::vec3& v) noexcept;
	
	/// 4x4 matrix for 3D rotation around the x axis
	[[nodiscard]] mat::mat4 rotation_m4_x(float theta) noexcept;
	/// 4x4 matrix for 3D rotation around the y axis
	[[nodiscard]] mat::mat4 rotation_m4_y(float theta) noexcept;
	/// 4x4 matrix for 3D rotation around the z axis
	[[nodiscard]] mat::mat4 rotation_m4_z(float theta) noexcept;
	/// 4x4 matrix for 3D rotation around arbitrary `a` axis
	[[nodiscard]] mat::mat4 rotation_m4_a(vec::vec3 a, float theta) noexcept;
	
	/// 4x4 matrix for mirror by normal `n`
	[[nodiscard]] mat::mat4 mirror_m4(vec::vec3 n) noexcept;
	/// 4x4 matrix of "inside-out"ing around normal `n`
	[[nodiscard]] mat::mat4 involution_m4(vec::vec3 n) noexcept;
	
	/// 4x4 matrix of an uniform scale
	[[nodiscard]] mat::mat4 scale_m4(float s) noexcept;
	/// 4x4 matrix of a non-uniform scale
	[[nodiscard]] mat::mat4 scale_m4(float sx, float sy, float sz) noexcept;
	[[nodiscard]] mat::mat4 scale_m4(const vec::vec3& v) noexcept;
	/// 4x4 matrix of a scale along a vector `a` with a factor `s`
	[[nodiscard]] mat::mat4 scale_m4(const vec::vec3& a, float s) noexcept;
	
	/// 4x4 matrix of a skew along `in_dir` vector by `theta` with `perp` vector as side vector
	[[nodiscard]] mat::mat4 skew_m4(float theta, const vec::vec3& in_dir, const vec::vec3& perp) noexcept;
	
} //! namespace transform

#endif //FELIXS_PACK_GEOMETRY_TRANSFORM

