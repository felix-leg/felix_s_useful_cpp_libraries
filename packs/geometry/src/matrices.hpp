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
#ifndef FELIXS_PACK_GEOMETRY_MATRICES_HPP
#define FELIXS_PACK_GEOMETRY_MATRICES_HPP
#include <optional>
#include <array>
#include <stdexcept>
#include <tuple>
#include <type_traits>

#include "vectors.hpp"

namespace mat {
	struct mat2;
	struct mat3;
	struct mat4;
	
	#pragma pack(4)
	
	struct mat2 {
		/*
				| m00 m01 |
				| m10 m11 |
		*/
		union {
			float data[4];
			struct {
				float
				#ifdef GEOMETRY_MATRIX_ROW_MAJOR
					m00, m01, m10, m11
				#else
					m00, m10, m01, m11
				#endif
				;
			};
		};
		static constexpr unsigned char DATA_SIZE = 4;
			
		explicit(false) mat2() noexcept;
		explicit(false) mat2(float _00, float _01, float _10, float _11) noexcept;
		mat2(const mat2& other) = default;
		mat2(mat2&& other) = default;
		
		static mat2 filled(float f) noexcept;
		static mat2 diag(float f0, float f1) noexcept;
		static mat2 one() noexcept;
		static mat2 cols(const ::vec::vec2& c1, const ::vec::vec2& c2) noexcept;
		static mat2 rows(const ::vec::vec2& r1, const ::vec::vec2& r2) noexcept;
		
		mat2& operator=(const mat2& other) = default;
		mat2& operator=(mat2&& other) = default;
		
		mat2& operator+=(const mat2& other) noexcept;
		mat2& operator-=(const mat2& other) noexcept;
		mat2& operator*=(float scalar) noexcept;
		mat2& operator*=(const mat2& other) noexcept;
		[[nodiscard]] mat2 operator-() noexcept;
		[[nodiscard]] ::vec::vec2 operator*(const ::vec::vec2& v) const noexcept;
		friend ::vec::vec2 operator*(const ::vec::vec2& v, const mat2& m) noexcept;
		
		[[nodiscard]] ::vec::vec2 column(unsigned char c) const;
		[[nodiscard]] ::vec::vec2 row(unsigned char r) const;
		void column(unsigned char c, const ::vec::vec2& v);
		void row(unsigned char r, const ::vec::vec2& v);
		float& at(unsigned char row, unsigned char column);
		const float& at(unsigned char row, unsigned char column) const;
		
		[[nodiscard]] mat2 transpose() const noexcept;
		mat2& transposed() noexcept;
		
		[[nodiscard]] float det() const noexcept;
		[[nodiscard]] std::optional<mat2> inv() const noexcept;
	};//! struct mat2
	[[nodiscard]] mat2 operator+(const mat2& a, const mat2& b) noexcept;
	[[nodiscard]] mat2 operator-(const mat2& a, const mat2& b) noexcept;
	[[nodiscard]] mat2 operator*(float scalar, const mat2& m) noexcept;
	[[nodiscard]] mat2 operator*(const mat2& m, float scalar) noexcept;
	[[nodiscard]] mat2 operator*(const mat2& a, const mat2& b) noexcept;
	[[nodiscard]] ::vec::vec2 operator*(const ::vec::vec2& v, const mat2& m) noexcept;
	
	[[nodiscard]] bool operator==(const mat2& a, const mat2& b) noexcept;
	[[nodiscard]] bool operator!=(const mat2& a, const mat2& b) noexcept;
	
	struct mat3 {
		/*
				| m00 m01 m02 |
				| m10 m11 m12 |
				| m20 m21 m22 |
		*/
		union {
			float data[9];
			struct {
				float
				#ifdef GEOMETRY_MATRIX_ROW_MAJOR
					m00, m01, m02, m10, m11, m12, m20, m21, m22
				#else
					m00, m10, m20, m01, m11, m21, m02, m12, m22
				#endif
				;
			};
		};
		static constexpr unsigned char DATA_SIZE = 9;
			
		explicit(false) mat3() noexcept;
		explicit(false) mat3(
			float _00, float _01, float _02,
			float _10, float _11, float _12,
			float _20, float _21, float _22
		) noexcept;
		mat3(const mat3& other) = default;
		mat3(mat3&& other) = default;
		
		static mat3 filled(float f) noexcept;
		static mat3 diag(float f0, float f1, float f2) noexcept;
		static mat3 one() noexcept;
		static mat3 cols(
			const ::vec::vec3& c1, const ::vec::vec3& c2, const ::vec::vec3& c3
		) noexcept;
		static mat3 rows(
			const ::vec::vec3& r1, const ::vec::vec3& r2, const ::vec::vec3& r3
		) noexcept;
		
		mat3& operator=(const mat3& other) = default;
		mat3& operator=(mat3&& other) = default;
		
		mat3& operator+=(const mat3& other) noexcept;
		mat3& operator-=(const mat3& other) noexcept;
		mat3& operator*=(float scalar) noexcept;
		mat3& operator*=(const mat3& other) noexcept;
		[[nodiscard]] mat3 operator-() noexcept;
		[[nodiscard]] ::vec::vec3 operator*(const ::vec::vec3& v) const noexcept;
		friend ::vec::vec3 operator*(const ::vec::vec3& v, const mat3& m) noexcept;
		
		[[nodiscard]] ::vec::vec3 column(unsigned char c) const;
		[[nodiscard]] ::vec::vec3 row(unsigned char r) const;
		void column(unsigned char c, const ::vec::vec3& v);
		void row(unsigned char r, const ::vec::vec3& v);
		float& at(unsigned char row, unsigned char column);
		const float& at(unsigned char row, unsigned char column) const;
		
		[[nodiscard]] mat3 transpose() const noexcept;
		mat3& transposed() noexcept;
		
		[[nodiscard]] float det() const noexcept;
		[[nodiscard]] std::optional<mat3> inv() const noexcept;
	};//! struct mat3
	[[nodiscard]] mat3 operator+(const mat3& a, const mat3& b) noexcept;
	[[nodiscard]] mat3 operator-(const mat3& a, const mat3& b) noexcept;
	[[nodiscard]] mat3 operator*(float scalar, const mat3& m) noexcept;
	[[nodiscard]] mat3 operator*(const mat3& m, float scalar) noexcept;
	[[nodiscard]] mat3 operator*(const mat3& a, const mat3& b) noexcept;
	[[nodiscard]] ::vec::vec3 operator*(const ::vec::vec3& v, const mat3& m) noexcept;
	
	[[nodiscard]] bool operator==(const mat3& a, const mat3& b) noexcept;
	[[nodiscard]] bool operator!=(const mat3& a, const mat3& b) noexcept;
	
	struct mat4 {
		/*
				| m00 m01 m02 m03 |
				| m10 m11 m12 m13 |
				| m20 m21 m22 m23 |
				| m30 m31 m32 m33 |
		*/
		union {
			float data[16];
			struct {
				float
				#ifdef GEOMETRY_MATRIX_ROW_MAJOR
					m00, m01, m02, m03,
					m10, m11, m12, m13,
					m20, m21, m22, m23,
					m30, m31, m32, m33
				#else
					m00, m10, m20, m30,
					m01, m11, m21, m31,
					m02, m12, m22, m32,
					m03, m13, m23, m33
				#endif
				;
			};
		};
		static constexpr unsigned char DATA_SIZE = 16;
			
		explicit(false) mat4() noexcept;
		explicit(false) mat4(
			float _00, float _01, float _02, float _03,
			float _10, float _11, float _12, float _13,
			float _20, float _21, float _22, float _23,
			float _30, float _31, float _32, float _33
		) noexcept;
		mat4(const mat4& other) = default;
		mat4(mat4&& other) = default;
		
		static mat4 filled(float f) noexcept;
		static mat4 diag(float f0, float f1, float f2, float f3) noexcept;
		static mat4 one() noexcept;
		static mat4 cols(
			const ::vec::vec4& c1, const ::vec::vec4& c2,
			const ::vec::vec4& c3, const ::vec::vec4& c4
		) noexcept;
		static mat4 rows(
			const ::vec::vec4& r1, const ::vec::vec4& r2,
			const ::vec::vec4& r3, const ::vec::vec4& r4
		) noexcept;
		
		mat4& operator=(const mat4& other) = default;
		mat4& operator=(mat4&& other) = default;
		
		mat4& operator+=(const mat4& other) noexcept;
		mat4& operator-=(const mat4& other) noexcept;
		mat4& operator*=(float scalar) noexcept;
		mat4& operator*=(const mat4& other) noexcept;
		[[nodiscard]] mat4 operator-() noexcept;
		[[nodiscard]] ::vec::vec4 operator*(const ::vec::vec4& v) const noexcept;
		friend ::vec::vec4 operator*(const ::vec::vec4& v, const mat4& m) noexcept;
		
		[[nodiscard]] ::vec::vec4 column(unsigned char c) const;
		[[nodiscard]] ::vec::vec4 row(unsigned char r) const;
		void column(unsigned char c, const ::vec::vec4& v);
		void row(unsigned char r, const ::vec::vec4& v);
		float& at(unsigned char row, unsigned char column);
		const float& at(unsigned char row, unsigned char column) const;
		
		[[nodiscard]] mat4 transpose() const noexcept;
		mat4& transposed() noexcept;
		
		[[nodiscard]] float det() const noexcept;
		[[nodiscard]] std::optional<mat4> inv() const noexcept;
	};//! struct mat4
	[[nodiscard]] mat4 operator+(const mat4& a, const mat4& b) noexcept;
	[[nodiscard]] mat4 operator-(const mat4& a, const mat4& b) noexcept;
	[[nodiscard]] mat4 operator*(float scalar, const mat4& m) noexcept;
	[[nodiscard]] mat4 operator*(const mat4& m, float scalar) noexcept;
	[[nodiscard]] mat4 operator*(const mat4& a, const mat4& b) noexcept;
	[[nodiscard]] ::vec::vec4 operator*(const ::vec::vec4& v, const mat4& m) noexcept;
	
	[[nodiscard]] bool operator==(const mat4& a, const mat4& b) noexcept;
	[[nodiscard]] bool operator!=(const mat4& a, const mat4& b) noexcept;
	
	#pragma pack()
}//! namespace mat

#endif /* ! FELIXS_PACK_GEOMETRY_MATRICES_HPP */
