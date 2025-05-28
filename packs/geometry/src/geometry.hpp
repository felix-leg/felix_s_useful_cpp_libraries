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
#ifndef FELIXS_PACK_GEOMETRY
#define FELIXS_PACK_GEOMETRY
#include <optional>
#include <array>
#include <stdexcept>
#include <tuple>
#include <type_traits>

namespace vec {
	struct bvec2;
	struct bvec3;
	struct bvec4;
	
	struct vec2;
	struct vec3;
	struct vec4;
}

namespace mat {
	struct mat2;
	struct mat3;
	struct mat4;
}

namespace vec {
	
	struct Dim4D {};
	struct Dim3D {};
	struct Dim2D {};
	template <class T> concept a2dDim = std::is_base_of_v<Dim2D,T>;
	template <class T> concept a3dDim = std::is_base_of_v<Dim3D,T>;
	template <class T> concept a4dDim = std::is_base_of_v<Dim4D,T>;
	struct _x final : public Dim2D , public Dim3D , public Dim4D {
		static constexpr unsigned char dim_no = 0;
	};
	struct _y final : public Dim2D , public Dim3D , public Dim4D {
		static constexpr unsigned char dim_no = 1;
	};
	struct _z final : public Dim3D , public Dim4D {
		static constexpr unsigned char dim_no = 2;
	};
	struct _w final : public Dim4D {
		static constexpr unsigned char dim_no = 3;
	};
	
	#pragma pack(1)
	
	struct bvec2 {
		bool x, y;
		
		bvec2() = delete;
		explicit bvec2(bool _x, bool _y) noexcept;
		bvec2(const bvec2& other) = default;
		bvec2(bvec2&& other) = default;
		
		bvec2& operator=(const bvec2& other) = default;
		bvec2& operator=(bvec2&& other) = default;
		
		bool all() const noexcept;
		bool any() const noexcept;
		bool none() const noexcept;
	};//! struct bvec2
	bvec2 operator&&(const bvec2& a, const bvec2& b) noexcept;
	bvec2 operator||(const bvec2& a, const bvec2& b) noexcept;
	bvec2 operator!(const bvec2& b) noexcept;
	
	struct bvec3 {
		bool x, y, z;
		
		bvec3() = delete;
		explicit bvec3(bool _x, bool _y, bool _z) noexcept;
		bvec3(const bvec3& other) = default;
		bvec3(bvec3&& other) = default;
		
		bvec3& operator=(const bvec3& other) = default;
		bvec3& operator=(bvec3&& other) = default;
		
		bool all() const noexcept;
		bool any() const noexcept;
		bool none() const noexcept;
	};//! struct bvec3
	bvec3 operator&&(const bvec3& a, const bvec3& b) noexcept;
	bvec3 operator||(const bvec3& a, const bvec3& b) noexcept;
	bvec3 operator!(const bvec3& b) noexcept;
	
	struct bvec4 {
		bool x, y, z, w;
		
		bvec4() = delete;
		explicit bvec4(bool _x, bool _y, bool _z, bool _w) noexcept;
		bvec4(const bvec4& other) = default;
		bvec4(bvec4&& other) = default;
		
		bvec4& operator=(const bvec4& other) = default;
		bvec4& operator=(bvec4&& other) = default;
		
		bool all() const noexcept;
		bool any() const noexcept;
		bool none() const noexcept;
	};//! struct bvec4
	bvec4 operator&&(const bvec4& a, const bvec4& b) noexcept;
	bvec4 operator||(const bvec4& a, const bvec4& b) noexcept;
	bvec4 operator!(const bvec4& b) noexcept;
	
	#pragma pack(4)
	
	struct vec2 {
		union {
			float data[2];
			struct { float x, y; };
		};
		
		explicit(false) vec2() noexcept;
		explicit(false) vec2(float _x, float _y) noexcept;
		vec2(const vec2& other) = default;
		vec2(vec2&& other) = default;
		
		vec2& operator=(const vec2& other) = default;
		vec2& operator=(vec2&& other) = default;
		
		template<a2dDim dim1, a2dDim dim2>
		std::tuple<const float,const float> swizzle2_out() const noexcept {
			return {data[dim1::dim_no], data[dim2::dim_no]};
		}
		
		template<a2dDim dim1, a2dDim dim2, a2dDim dim3>
		std::tuple<const float,const float,const float> swizzle3_out() const noexcept {
			return {data[dim1::dim_no], data[dim2::dim_no], data[dim3::dim_no]};
		}
		
		template<a2dDim dim1, a2dDim dim2, a2dDim dim3, a2dDim dim4>
		std::tuple<const float,const float,const float,const float> swizzle4_out() const noexcept {
			return {data[dim1::dim_no], data[dim2::dim_no], data[dim3::dim_no], data[dim4::dim_no]};
		}
		
		template<a2dDim dim1, a2dDim dim2>
		std::tuple<float&,float&> swizzle2_in() noexcept {
			static_assert(!std::is_same_v<dim1,dim2>, "Can't assign to the same dimension twice");
			
			return std::tie(data[dim1::dim_no], data[dim2::dim_no]);
		}
		
		[[nodiscard]] vec3 to_vec3(float z = 0.0f) const noexcept;
		[[nodiscard]] vec4 to_vec4(float z = 0.0f, float w = 1.0f) const noexcept;
		[[nodiscard]] vec4 to_vec4(float z = 0.0f, bool is_point = true) const noexcept;
		
		vec2& operator+=(const vec2& other) noexcept;
		vec2& operator-=(const vec2& other) noexcept;
		vec2& operator*=(float scalar) noexcept;
		vec2& operator/=(float scalar);
		[[nodiscard]] vec2 operator-() const noexcept;
		
		bool operator==(const vec2& other) const noexcept;
		bool operator!=(const vec2& other) const noexcept;
		
		[[nodiscard]] float length() const noexcept;
		[[nodiscard]] float length_sq() const noexcept;
		[[nodiscard]] vec2 normalized() const;
		vec2& normalize();
	};//! struct vec2
	[[nodiscard]] vec2 operator+(const vec2& a, const vec2& b) noexcept;
	[[nodiscard]] vec2 operator-(const vec2& a, const vec2& b) noexcept;
	[[nodiscard]] vec2 operator*(const vec2& v, float s) noexcept;
	[[nodiscard]] vec2 operator*(float s, const vec2& v) noexcept;
	[[nodiscard]] vec2 operator/(const vec2& v, float s);
	
	struct vec3 {
		union {
			float data[3];
			struct { float x, y, z; };
		};
		
		explicit(false) vec3() noexcept;
		explicit(false) vec3(float _x, float _y, float _z) noexcept;
		vec3(const vec3& other) = default;
		vec3(vec3&& other) = default;
		
		vec3& operator=(const vec3& other) = default;
		vec3& operator=(vec3&& other) = default;
		
		template<a3dDim dim1, a3dDim dim2>
		std::tuple<const float,const float> swizzle2_out() const noexcept {
			return {data[dim1::dim_no], data[dim2::dim_no]};
		}
		
		template<a3dDim dim1, a3dDim dim2, a3dDim dim3>
		std::tuple<const float,const float,const float> swizzle3_out() const noexcept {
			return {data[dim1::dim_no], data[dim2::dim_no], data[dim3::dim_no]};
		}
		
		template<a3dDim dim1, a3dDim dim2, a3dDim dim3, a3dDim dim4>
		std::tuple<const float,const float,const float,const float> swizzle4_out() const noexcept {
			return {data[dim1::dim_no], data[dim2::dim_no], data[dim3::dim_no], data[dim4::dim_no]};
		}
		
		template<a3dDim dim1, a3dDim dim2>
		std::tuple<float&,float&> swizzle2_in() noexcept {
			static_assert(!std::is_same_v<dim1,dim2>, "Can't assign to the same dimension twice");
			
			return std::tie(data[dim1::dim_no], data[dim2::dim_no]);
		}
		
		template<a3dDim dim1, a3dDim dim2, a3dDim dim3>
		std::tuple<float&,float&,float&> swizzle3_in() noexcept {
			static_assert(!std::is_same_v<dim1,dim2>, "Can't assign to the same dimension twice");
			static_assert(!std::is_same_v<dim1,dim3>, "Can't assign to the same dimension twice");
			static_assert(!std::is_same_v<dim3,dim2>, "Can't assign to the same dimension twice");
			
			return std::tie(data[dim1::dim_no], data[dim2::dim_no], data[dim3::dim_no]);
		}
		
		[[nodiscard]] vec4 to_vec4(float w = 1.0f) const noexcept;
		[[nodiscard]] vec4 to_vec4(bool is_point = true) const noexcept;
		[[nodiscard]] vec2 xy() const noexcept;
		[[nodiscard]] vec2 xz() const noexcept;
		[[nodiscard]] vec2 yz() const noexcept;
		[[nodiscard]] vec2 yx() const noexcept;
		[[nodiscard]] vec2 zx() const noexcept;
		void xy(const vec2& source) noexcept;
		void xz(const vec2& source) noexcept;
		void yz(const vec2& source) noexcept;
		void yx(const vec2& source) noexcept;
		void zx(const vec2& source) noexcept;
		
		vec3& operator+=(const vec3& other) noexcept;
		vec3& operator-=(const vec3& other) noexcept;
		vec3& operator*=(float scalar) noexcept;
		vec3& operator/=(float scalar);
		[[nodiscard]] vec3 operator-() const noexcept;
		
		bool operator==(const vec3& other) const noexcept;
		bool operator!=(const vec3& other) const noexcept;
		
		[[nodiscard]] float length() const noexcept;
		[[nodiscard]] float length_sq() const noexcept;
		[[nodiscard]] vec3 normalized() const;
		vec3& normalize();
	};//! struct vec3
	[[nodiscard]] vec3 operator+(const vec3& a, const vec3& b) noexcept;
	[[nodiscard]] vec3 operator-(const vec3& a, const vec3& b) noexcept;
	[[nodiscard]] vec3 operator*(const vec3& v, float s) noexcept;
	[[nodiscard]] vec3 operator*(float s, const vec3& v) noexcept;
	[[nodiscard]] vec3 operator/(const vec3& v, float s);
	
	struct vec4 {
		union {
			float data[4];
			struct { float x, y, z, w; };
		};
		
		explicit(false) vec4(bool is_point = true) noexcept;
		explicit(false) vec4(float _x, float _y, float _z, float _w) noexcept;
		vec4(const vec4& other) = default;
		vec4(vec4&& other) = default;
		vec4(const vec3& v3, float _w) noexcept;
		
		vec4& operator=(const vec4& other) = default;
		vec4& operator=(vec4&& other) = default;
		
		template<a4dDim dim1, a4dDim dim2>
		std::tuple<const float,const float> swizzle2_out() const noexcept {
			return {data[dim1::dim_no], data[dim2::dim_no]};
		}
		
		template<a4dDim dim1, a4dDim dim2, a4dDim dim3>
		std::tuple<const float,const float,const float> swizzle3_out() const noexcept {
			return {data[dim1::dim_no], data[dim2::dim_no], data[dim3::dim_no]};
		}
		
		template<a4dDim dim1, a4dDim dim2, a4dDim dim3, a4dDim dim4>
		std::tuple<const float,const float,const float,const float> swizzle4_out() const noexcept {
			return {data[dim1::dim_no], data[dim2::dim_no], data[dim3::dim_no], data[dim4::dim_no]};
		}
		
		template<a4dDim dim1, a4dDim dim2>
		std::tuple<float&,float&> swizzle2_in() noexcept {
			static_assert(!std::is_same_v<dim1,dim2>, "Can't assign to the same dimension twice");
			
			return std::tie(data[dim1::dim_no], data[dim2::dim_no]);
		}
		
		template<a4dDim dim1, a4dDim dim2, a4dDim dim3>
		std::tuple<float&,float&,float&> swizzle3_in() noexcept {
			static_assert(!std::is_same_v<dim1,dim2>, "Can't assign to the same dimension twice");
			static_assert(!std::is_same_v<dim1,dim3>, "Can't assign to the same dimension twice");
			static_assert(!std::is_same_v<dim3,dim2>, "Can't assign to the same dimension twice");
			
			return std::tie(data[dim1::dim_no], data[dim2::dim_no], data[dim3::dim_no]);
		}
		
		template<class dim1, class dim2, class dim3, class dim4>
		std::tuple<float&,float&,float&,float&> swizzle4_in() noexcept {
			static_assert(!std::is_same_v<dim1,dim2>, "Can't assign to the same dimension twice");
			static_assert(!std::is_same_v<dim1,dim3>, "Can't assign to the same dimension twice");
			static_assert(!std::is_same_v<dim1,dim4>, "Can't assign to the same dimension twice");
			static_assert(!std::is_same_v<dim3,dim2>, "Can't assign to the same dimension twice");
			static_assert(!std::is_same_v<dim3,dim4>, "Can't assign to the same dimension twice");
			static_assert(!std::is_same_v<dim2,dim4>, "Can't assign to the same dimension twice");
			
			return std::tie(data[dim1::dim_no], data[dim2::dim_no], data[dim3::dim_no], data[dim4::dim_no]);
		}
		
		[[nodiscard]] vec3 xyz() const noexcept;
		
		vec4& operator+=(const vec4& other) noexcept;
		vec4& operator-=(const vec4& other) noexcept;
		vec4& operator*=(float scalar) noexcept;
		vec4& operator/=(float scalar);
		[[nodiscard]] vec4 operator-() const noexcept;
		
		bool operator==(const vec4& other) const noexcept;
		bool operator!=(const vec4& other) const noexcept;
		
		[[nodiscard]] float length() const noexcept;
		[[nodiscard]] float length_sq() const noexcept;
		[[nodiscard]] vec4 normalized() const;
		vec4& normalize();
	};//! struct vec4
	[[nodiscard]] vec4 operator+(const vec4& a, const vec4& b) noexcept;
	[[nodiscard]] vec4 operator-(const vec4& a, const vec4& b) noexcept;
	[[nodiscard]] vec4 operator*(const vec4& v, float s) noexcept;
	[[nodiscard]] vec4 operator*(float s, const vec4& v) noexcept;
	[[nodiscard]] vec4 operator/(const vec4& v, float s);
	
	#pragma pack()
	
	[[nodiscard]] float dot(const vec2& a, const vec2& b) noexcept;
	[[nodiscard]] float dot(const vec3& a, const vec3& b) noexcept;
	[[nodiscard]] float dot(const vec4& a, const vec4& b) noexcept;
	
	[[nodiscard]] vec3 cross(const vec3& a, const vec3& b) noexcept;
	
	[[nodiscard]] std::optional<float> cos(const vec2& a, const vec2& b) noexcept;
	[[nodiscard]] std::optional<float> cos(const vec3& a, const vec3& b) noexcept;
	[[nodiscard]] std::optional<float> cos(const vec4& a, const vec4& b) noexcept;
	
	[[nodiscard]] std::optional<float> sin(const vec3& a, const vec3& b) noexcept;
	
	[[nodiscard]] std::optional<float> theta(const vec2& a, const vec2& b) noexcept;
	[[nodiscard]] std::optional<float> theta(const vec3& a, const vec3& b) noexcept;
	[[nodiscard]] std::optional<float> theta(const vec4& a, const vec4& b) noexcept;
	
	/// Scalar triple product [a,b,c]
	[[nodiscard]] float triple(const vec3& a, const vec3& b, const vec3& c) noexcept;
	
	/// a_{||b} = part of <projected> that is parallel to <onto>
	[[nodiscard]] std::optional<vec2> projection(const vec2& projected, const vec2& onto) noexcept;
	[[nodiscard]] std::optional<vec3> projection(const vec3& projected, const vec3& onto) noexcept;
	[[nodiscard]] std::optional<vec4> projection(const vec4& projected, const vec4& onto) noexcept;
	
	/// a_{_|_b} = part of <rejected> that is perpendicular to <from>
	[[nodiscard]] std::optional<vec2> rejection(const vec2& rejected, const vec2& from) noexcept;
	[[nodiscard]] std::optional<vec3> rejection(const vec3& rejected, const vec3& from) noexcept;
	[[nodiscard]] std::optional<vec4> rejection(const vec4& rejected, const vec4& from) noexcept;
	
	
	enum CwOp {
		LESS, LESS_EQ, GREATER, GREATER_EQ, EQ, NOT_EQ
	};
	
	[[nodiscard]] bvec2 is(const vec2& a, CwOp op, const vec2& b) noexcept;
	[[nodiscard]] vec2 mul(const vec2& a, const vec2& b) noexcept;
	[[nodiscard]] vec2 div(const vec2& a, const vec2& b);
	
	[[nodiscard]] bvec3 is(const vec3& a, CwOp op, const vec3& b) noexcept;
	[[nodiscard]] vec3 mul(const vec3& a, const vec3& b) noexcept;
	[[nodiscard]] vec3 div(const vec3& a, const vec3& b);
	
	[[nodiscard]] bvec4 is(const vec4& a, CwOp op, const vec4& b) noexcept;
	[[nodiscard]] vec4 mul(const vec4& a, const vec4& b) noexcept;
	[[nodiscard]] vec4 div(const vec4& a, const vec4& b);
	
}//! namespace vec

namespace mat {
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
		::vec::vec2 operator*(const ::vec::vec2& v) const noexcept;
		
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
		::vec::vec3 operator*(const ::vec::vec3& v) const noexcept;
		
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
	};//! struct mat2
	[[nodiscard]] mat3 operator+(const mat3& a, const mat3& b) noexcept;
	[[nodiscard]] mat3 operator-(const mat3& a, const mat3& b) noexcept;
	[[nodiscard]] mat3 operator*(float scalar, const mat3& m) noexcept;
	[[nodiscard]] mat3 operator*(const mat3& m, float scalar) noexcept;
	[[nodiscard]] mat3 operator*(const mat3& a, const mat3& b) noexcept;
	
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
		::vec::vec4 operator*(const ::vec::vec4& v) const noexcept;
		
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
	};//! struct mat2
	[[nodiscard]] mat4 operator+(const mat4& a, const mat4& b) noexcept;
	[[nodiscard]] mat4 operator-(const mat4& a, const mat4& b) noexcept;
	[[nodiscard]] mat4 operator*(float scalar, const mat4& m) noexcept;
	[[nodiscard]] mat4 operator*(const mat4& m, float scalar) noexcept;
	[[nodiscard]] mat4 operator*(const mat4& a, const mat4& b) noexcept;
	
	[[nodiscard]] bool operator==(const mat4& a, const mat4& b) noexcept;
	[[nodiscard]] bool operator!=(const mat4& a, const mat4& b) noexcept;
	
	#pragma pack()
}//! namespace mat


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


#endif //FELIXS_PACK_GEOMETRY

