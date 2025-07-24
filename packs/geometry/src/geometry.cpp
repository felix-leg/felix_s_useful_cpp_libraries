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

#include "geometry.hpp"

#include <utility>

// SIMD support
#if __has_include(<simd>)
#	include <simd>
#	define NS(T) std::T
#	define HAS_SIMD
#elif __has_include(<experimental/simd>)
#	include <experimental/simd>
#	define NS(T) std::experimental::T
#	define HAS_SIMD
#endif

#ifdef HAS_SIMD
namespace simd {
	using NS(fixed_size_simd);
	using NS(memory_alignment_v);
	using NS(reduce);
	
	constexpr auto aligned = NS(vector_aligned); //data is aligned simd-frendly
	constexpr auto unaligned = NS(element_aligned);//data is aligned arbitrary
}
#	define SIMD_ALIGN(T) alignas(::simd::memory_alignment_v<T>)
# define SIMD_INIT2(var,val1,val2) var[0] = (val1); var[1] = (val2)
# define SIMD_INIT3(var,val1,val2,val3) var[0] = (val1); var[1] = (val2); var[2] = (val3)
# define SIMD_INIT4(var,val1,val2,val3,val4) var[0] = (val1); var[1] = (val2); var[2] = (val3); var[3] = (val4)
#	undef NS
#endif

namespace vec {
	
bvec2::bvec2(bool _x, bool _y) noexcept : x{_x}, y{_y} {}

vec2::vec2() noexcept : x{0.0f}, y{0.0f} {}
vec2::vec2(float _x, float _y) noexcept : x{_x}, y{_y} {}

bool bvec2::all() const noexcept {
	return x && y;
}
bool bvec2::any() const noexcept {
	return x || y;
}
bool bvec2::none() const noexcept {
	return !(x || y);
}

vec3 vec2::to_vec3(float z) const noexcept {
	return vec3{x, y, z};
}
vec4 vec2::to_vec4(float z, float w) const noexcept {
	return vec4{x, y, z, w};
}
vec4 vec2::to_vec4(float z, bool is_point) const noexcept {
	return vec4{x, y, z, is_point ? 1.0f : 0.0f};
}

vec2& vec2::operator+=(const vec2& other) noexcept {
	x += other.x;
	y += other.y;
	return *this;
}
vec2& vec2::operator-=(const vec2& other) noexcept {
	x -= other.x;
	y -= other.y;
	return *this;
}
vec2& vec2::operator*=(float scalar) noexcept {
	x *= scalar;
	y *= scalar;
	return *this;
}
vec2& vec2::operator/=(float scalar) {
	x /= scalar;
	y /= scalar;
	return *this;
}

vec2 vec2::operator-() const noexcept {
	return vec2{-x, -y};
}
vec2 operator+(const vec2& a, const vec2& b) noexcept {
	return vec2{a.x + b.x, a.y + b.y};
}
vec2 operator-(const vec2& a, const vec2& b) noexcept {
	return vec2{a.x - b.x, a.y - b.y};
}
vec2 operator*(const vec2& v, float s) noexcept {
	return vec2{v.x * s, v.y * s};
}
vec2 operator*(float s, const vec2& v) noexcept {
	return v * s;
}
vec2 operator/(const vec2& v, float s) {
	return vec2{v.x / s, v.y / s};
}

bool vec2::operator==(const vec2& other) const noexcept {
	return (x == other.x) && (y == other.y);
}
bool vec2::operator!=(const vec2& other) const noexcept {
	return (x != other.x) || (y != other.y);
}

float vec2::length() const noexcept {
	return std::sqrt(x*x + y*y);
}
float vec2::length_sq() const noexcept {
	return x*x + y*y;
}
vec2 vec2::normalized() const {
	return *this / length();
}
vec2& vec2::normalize() {
	float l = length();
	x /= l;
	y /= l;
	return *this;
}

bvec2 is(const vec2& a, CwOp op, const vec2& b) noexcept {
	switch(op) {
		case LESS:
			return bvec2(a.x < b.x, a.y < b.y);
		case LESS_EQ:
			return bvec2(a.x <= b.x, a.y <= b.y);
		case GREATER:
			return bvec2(a.x > b.x, a.y > b.y);
		case GREATER_EQ:
			return bvec2(a.x >= b.x, a.y >= b.y);
		case EQ:
			return bvec2(a.x == b.x, a.y == b.y);
		case NOT_EQ:
			return bvec2(a.x != b.x, a.y != b.y);
		default:
			std::unreachable();
	}
}

bvec2 operator&&(const bvec2& a, const bvec2& b) noexcept {
	return bvec2(a.x && b.x, a.y && b.y);
}
bvec2 operator||(const bvec2& a, const bvec2& b) noexcept {
	return bvec2(a.x || b.x, a.y || b.y);
}
bvec2 operator!(const bvec2& b) noexcept {
	return bvec2( ! b.x, ! b.y);
}

vec2 mul(const vec2& a, const vec2& b) noexcept {
	return vec2(a.x * b.x, a.y * b.y);
}
vec2 div(const vec2& a, const vec2& b) {
	return vec2(a.x / b.x, a.y / b.y);
}

std::optional<vec2> projection(const vec2& projected, const vec2& onto) noexcept {
	float b_len = onto.length_sq();
	if( b_len == 0.0f ) return {};
	
	return (dot(projected, onto) / b_len ) * onto;
}
std::optional<vec2> rejection(const vec2& rejected, const vec2& from) noexcept {
	return projection(rejected, from).transform([&rejected](const vec2& r){ return rejected - r; });
}

bvec3::bvec3(bool _x, bool _y, bool _z) noexcept : x{_x}, y{_y}, z{_z} {}

vec3::vec3() noexcept : x{0.0f}, y{0.0f}, z{0.0f} {}
vec3::vec3(float _x, float _y, float _z) noexcept : x{_x}, y{_y}, z{_z} {}

bool bvec3::all() const noexcept {
	return (x && y) && (y && z);
}
bool bvec3::any() const noexcept {
	return (x || y) || (y || z);
}
bool bvec3::none() const noexcept {
	return ! any();
}

vec4 vec3::to_vec4(float w) const noexcept {
	return vec4{x, y, z, w};
}
vec4 vec3::to_vec4(bool is_point) const noexcept {
	return vec4{x, y, z, is_point ? 1.0f : 0.0f};
}
vec2 vec3::xy() const noexcept {
	return vec2(x,y);
}
vec2 vec3::xz() const noexcept {
	return vec2(x,z);
}
vec2 vec3::yz() const noexcept {
	return vec2(y,z);
}
vec2 vec3::yx() const noexcept {
	return vec2(y,x);
}
vec2 vec3::zx() const noexcept {
	return vec2(z,x);
}

void vec3::xy(const vec2& source) noexcept {
	x = source.x;
	y = source.y;
}
void vec3::xz(const vec2& source) noexcept {
	x = source.x;
	z = source.y;
}
void vec3::yz(const vec2& source) noexcept {
	y = source.x;
	z = source.y;
}
void vec3::yx(const vec2& source) noexcept {
	y = source.x;
	x = source.y;
}
void vec3::zx(const vec2& source) noexcept {
	z = source.x;
	x = source.y;
}

vec3& vec3::operator+=(const vec3& other) noexcept {
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}
vec3& vec3::operator-=(const vec3& other) noexcept {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}
vec3& vec3::operator*=(float scalar) noexcept {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}
vec3& vec3::operator/=(float scalar) {
	x /= scalar;
	y /= scalar;
	z /= scalar;
	return *this;
}

vec3 vec3::operator-() const noexcept {
	return vec3{-x, -y, -z};
}
vec3 operator+(const vec3& a, const vec3& b) noexcept {
	return vec3{a.x + b.x, a.y + b.y, a.z + b.z};
}
vec3 operator-(const vec3& a, const vec3& b) noexcept {
	return vec3{a.x - b.x, a.y - b.y, a.z - b.z};
}
vec3 operator*(const vec3& v, float s) noexcept {
	return vec3{v.x * s, v.y * s, v.z * s};
}
vec3 operator*(float s, const vec3& v) noexcept {
	return v * s;
}
vec3 operator/(const vec3& v, float s) {
	return vec3{v.x / s, v.y / s, v.z / s};
}

bool vec3::operator==(const vec3& other) const noexcept {
	return (x == other.x) && (y == other.y) && (z == other.z);
}
bool vec3::operator!=(const vec3& other) const noexcept {
	return (x != other.x) || (y != other.y) || (z != other.z);
}

float vec3::length() const noexcept {
	return std::sqrt(x*x + y*y + z*z);
}
float vec3::length_sq() const noexcept {
	return x*x + y*y + z*z;
}
vec3 vec3::normalized() const {
	return *this / length();
}
vec3& vec3::normalize() {
	float l = length();
	x /= l;
	y /= l;
	z /= l;
	return *this;
}

bvec3 is(const vec3& a, CwOp op, const vec3& b) noexcept {
	switch(op) {
		case LESS:
			return bvec3(a.x < b.x, a.y < b.y, a.z < b.z);
		case LESS_EQ:
			return bvec3(a.x <= b.x, a.y <= b.y, a.z <= b.z);
		case GREATER:
			return bvec3(a.x > b.x, a.y > b.y, a.z > b.z);
		case GREATER_EQ:
			return bvec3(a.x >= b.x, a.y >= b.y, a.z >= b.z);
		case EQ:
			return bvec3(a.x == b.x, a.y == b.y, a.z == b.z);
		case NOT_EQ:
			return bvec3(a.x != b.x, a.y != b.y, a.z != b.z);
		default:
			std::unreachable();
	}
}

bvec3 operator&&(const bvec3& a, const bvec3& b) noexcept {
	return bvec3(a.x && b.x, a.y && b.y, a.z && b.z);
}
bvec3 operator||(const bvec3& a, const bvec3& b) noexcept {
	return bvec3(a.x || b.x, a.y || b.y, a.z || b.z);
}
bvec3 operator!(const bvec3& b) noexcept {
	return bvec3(! b.x, ! b.y, ! b.z);
}

vec3 mul(const vec3& a, const vec3& b) noexcept {
	return vec3(a.x * b.x, a.y * b.y, a.z * b.z);
}
vec3 div(const vec3& a, const vec3& b) {
	return vec3(a.x / b.x, a.y / b.y, a.z / b.z);
}

std::optional<vec3> projection(const vec3& projected, const vec3& onto) noexcept {
	float b_len = onto.length_sq();
	if( b_len == 0.0f ) return {};
	
	return (dot(projected, onto) / b_len ) * onto;
}
std::optional<vec3> rejection(const vec3& rejected, const vec3& from) noexcept {
	return projection(rejected, from).transform([&rejected](const vec3& r){ return rejected - r; });
}

bvec4::bvec4(bool _x, bool _y, bool _z, bool _w) noexcept : x{_x}, y{_y}, z{_z}, w{_w} {}

vec4::vec4(bool is_point) noexcept : x{0.0f}, y{0.0f}, z{0.0f}, w{is_point ? 1.0f : 0.0f} {}
vec4::vec4(float _x, float _y, float _z, float _w) noexcept : x{_x}, y{_y}, z{_z}, w{_w} {}
vec4::vec4(const vec3& v3, float _w) noexcept : x{v3.x}, y{v3.y}, z{v3.z}, w{_w} {}

bool bvec4::all() const noexcept {
	return ((x && y) && (y && z)) && (z && w);
}
bool bvec4::any() const noexcept {
	return ((x || y) || (y || z)) || (z || w);
}
bool bvec4::none() const noexcept {
	return ! any();
}

vec3 vec4::xyz() const noexcept {
	return vec3{x, y, z};
}

vec4& vec4::operator+=(const vec4& other) noexcept {
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}
vec4& vec4::operator-=(const vec4& other) noexcept {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}
vec4& vec4::operator*=(float scalar) noexcept {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	w *= scalar;
	return *this;
}
vec4& vec4::operator/=(float scalar) {
	x /= scalar;
	y /= scalar;
	z /= scalar;
	w /= scalar;
	return *this;
}

vec4 vec4::operator-() const noexcept {
	return vec4{-x, -y, -z, -w};
}
vec4 operator+(const vec4& a, const vec4& b) noexcept {
	return vec4{a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}
vec4 operator-(const vec4& a, const vec4& b) noexcept {
	return vec4{a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
}
vec4 operator*(const vec4& v, float s) noexcept {
	return vec4{v.x * s, v.y * s, v.z * s, v.w * s};
}
vec4 operator*(float s, const vec4& v) noexcept {
	return v * s;
}
vec4 operator/(const vec4& v, float s) {
	return vec4{v.x / s, v.y / s, v.z / s, v.w / s};
}

bool vec4::operator==(const vec4& other) const noexcept {
	return (x == other.x) && (y == other.y) && (z == other.z) && (w == other.w);
}
bool vec4::operator!=(const vec4& other) const noexcept {
	return (x != other.x) || (y != other.y) || (z != other.z) || (w != other.w);
}

float vec4::length() const noexcept {
	return std::sqrt(x*x + y*y + z*z + w*w);
}
float vec4::length_sq() const noexcept {
	return x*x + y*y + z*z + w*w;
}
vec4 vec4::normalized() const {
	return *this / length();
}
vec4& vec4::normalize() {
	float l = length();
	x /= l;
	y /= l;
	z /= l;
	w /= l;
	return *this;
}

bvec4 is(const vec4& a, CwOp op, const vec4& b) noexcept {
	switch(op) {
		case LESS:
			return bvec4(a.x < b.x, a.y < b.y, a.z < b.z, a.w < b.w);
		case LESS_EQ:
			return bvec4(a.x <= b.x, a.y <= b.y, a.z <= b.z, a.w <= b.w);
		case GREATER:
			return bvec4(a.x > b.x, a.y > b.y, a.z > b.z, a.w > b.w);
		case GREATER_EQ:
			return bvec4(a.x >= b.x, a.y >= b.y, a.z >= b.z, a.w >= b.w);
		case EQ:
			return bvec4(a.x == b.x, a.y == b.y, a.z == b.z, a.w == b.w);
		case NOT_EQ:
			return bvec4(a.x != b.x, a.y != b.y, a.z != b.z, a.w != b.w);
		default:
			std::unreachable();
	}
}

bvec4 operator&&(const bvec4& a, const bvec4& b) noexcept {
	return bvec4(a.x && b.x, a.y && b.y, a.z && b.z, a.w && b.w);
}
bvec4 operator||(const bvec4& a, const bvec4& b) noexcept {
	return bvec4(a.x || b.x, a.y || b.y, a.z || b.z, a.w || b.w);
}
bvec4 operator!(const bvec4& b) noexcept {
	return bvec4(! b.x, ! b.y, ! b.z, ! b.w);
}

vec4 mul(const vec4& a, const vec4& b) noexcept {
	return vec4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}
vec4 div(const vec4& a, const vec4& b) {
	return vec4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
}

std::optional<vec4> projection(const vec4& projected, const vec4& onto) noexcept {
	float b_len = onto.length_sq();
	if( b_len == 0.0f ) return {};
	
	return (dot(projected, onto) / b_len ) * onto;
}
std::optional<vec4> rejection(const vec4& rejected, const vec4& from) noexcept {
	return projection(rejected, from).transform([&rejected](const vec4& r){ return rejected - r; });
}

float dot(const vec2& a, const vec2& b) noexcept {
	return (a.x * b.x + a.y * b.y);
}
float dot(const vec3& a, const vec3& b) noexcept {
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
float dot(const vec4& a, const vec4& b) noexcept {
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}

vec3 cross(const vec3& a, const vec3& b) noexcept {
	return vec3{ a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x };
}

std::optional<float> cos(const vec2& a, const vec2& b) noexcept {
	float l = a.length() * b.length();
	if( l == 0.0f ) {
		return {}; //no value
	} else {
		return dot(a,b) / l;
	}
}
std::optional<float> theta(const vec2& a, const vec2& b) noexcept {
	return cos(a,b).transform([](float c){ return std::acos(c); });
}

std::optional<float> cos(const vec3& a, const vec3& b) noexcept {
	float l = a.length() * b.length();
	if( l == 0.0f ) {
		return {}; //no value
	} else {
		return dot(a,b) / l;
	}
}
std::optional<float> sin(const vec3& a, const vec3& b) noexcept {
	float l = a.length() * b.length();
	if( l == 0.0f ) {
		return {}; //no value
	} else {
		return cross(a,b).length() / l;
	}
}
std::optional<float> theta(const vec3& a, const vec3& b) noexcept {
	return cos(a,b).transform([](float c){ return std::acos(c); });
}

std::optional<float> cos(const vec4& a, const vec4& b) noexcept {
	float l = a.length() * b.length();
	if( l == 0.0f ) {
		return {}; //no value
	} else {
		return dot(a,b) / l;
	}
}
std::optional<float> theta(const vec4& a, const vec4& b) noexcept {
	return cos(a,b).transform([](float c){ return std::acos(c); });
}

float triple(const vec3& a, const vec3& b, const vec3& c) noexcept {
	return dot(cross(a,b),c);
}


	
};//! namespace vec


#ifndef HAS_SIMD

float minor_from_m2(const mat::mat2& m, unsigned char i, unsigned char j) {
	return m.at( (1-i)+1, (1-j)+1 );
}
float minor_from_m3(const mat::mat3& m, unsigned char i, unsigned char j) {
	mat::mat2 result;
	unsigned char chosen_n = 0;
	unsigned char chosen_k = 0;
	for(unsigned char n = 0; n<3; ++n) {
		if( n == i ) continue;
		chosen_k = 0;
		for(unsigned char k = 0; k<3; ++k) {
			if( k == j ) continue;
			
			result.at(chosen_n+1, chosen_k+1) = m.at(n+1,k+1);
			
			++chosen_k;
		}
		++chosen_n;
	}
	
	return result.det();
}
float minor_from_m4(const mat::mat4& m, unsigned char i, unsigned char j) {
	mat::mat3 result;
	unsigned char chosen_n = 0;
	unsigned char chosen_k = 0;
	for(unsigned char n = 0; n<4; ++n) {
		if( n == i ) continue;
		chosen_k = 0;
		for(unsigned char k = 0; k<4; ++k) {
			if( k == j ) continue;
			
			result.at(chosen_n+1, chosen_k+1) = m.at(n+1,k+1);
			
			++chosen_k;
		}
		++chosen_n;
	}
	
	return result.det();
}

float perm_sign(unsigned char i, unsigned char j) {
	if( ((i+j) % 2) == 0 ) {
		return 1.0f;
	} else {
		return -1.0f;
	}
}

#endif //!HAS_SIMD


namespace mat {

mat2::mat2() noexcept :
	#ifdef GEOMETRY_MATRIX_ROW_MAJOR
	m00{0.0f}, m01{0.0f}, m10{0.0f}, m11{0.0f}
	#else
	m00{0.0f}, m10{0.0f}, m01{0.0f}, m11{0.0f}
	#endif
	{}

mat2::mat2(float _00, float _01,
					 float _10, float _11)
		noexcept :
		#ifdef GEOMETRY_MATRIX_ROW_MAJOR
		m00{_00}, m01{_01}, m10{_10}, m11{_11}
		#else
		m00{_00}, m10{_10}, m01{_01}, m11{_11}
		#endif
		{}

mat2 mat2::filled(float f) noexcept {
	return mat2(f, f, f, f);
}
mat2 mat2::diag(float f0, float f1) noexcept {
	return mat2(f0, 0.0f,
							0.0f, f1);
}
mat2 mat2::one() noexcept {
	return mat2(1.0f, 0.0f, 0.0f, 1.0f);
}
mat2 mat2::cols(const ::vec::vec2& c1, const ::vec::vec2& c2) noexcept {
	return mat2(c1.x, c2.x,
							c1.y, c2.y);
}
mat2 mat2::rows(const ::vec::vec2& r1, const ::vec::vec2& r2) noexcept {
	return mat2(r1.x, r1.y,
							r2.x, r2.y);
}

mat2& mat2::operator+=(const mat2& other) noexcept {
	for(unsigned char i=0; i<DATA_SIZE; ++i) {
		data[i] += other.data[i];
	}
	return *this;
}
mat2& mat2::operator-=(const mat2& other) noexcept {
	for(unsigned char i=0; i<DATA_SIZE; ++i) {
		data[i] -= other.data[i];
	}
	return *this;
}
mat2& mat2::operator*=(float scalar) noexcept {
	for(unsigned char i=0; i<DATA_SIZE; ++i) {
		data[i] *= scalar;
	}
	return *this;
}
mat2 mat2::operator-() noexcept {
	return {
		-m00, -m01,
		-m10, -m11
	};
}
mat2 operator+(const mat2& a, const mat2& b) noexcept {
	mat2 result;
	for(unsigned char i=0; i<mat2::DATA_SIZE; ++i) {
		result.data[i] = a.data[i] + b.data[i];
	}
	return result;
}
mat2 operator-(const mat2& a, const mat2& b) noexcept {
	mat2 result;
	for(unsigned char i=0; i<mat2::DATA_SIZE; ++i) {
		result.data[i] = a.data[i] - b.data[i];
	}
	return result;
}
mat2 operator*(float scalar, const mat2& m) noexcept {
	return m * scalar;
}
mat2 operator*(const mat2& m, float scalar) noexcept {
	mat2 result;
	for(unsigned char i=0; i<mat2::DATA_SIZE; ++i) {
		result.data[i] = m.data[i] * scalar;
	}
	return result;
}

bool operator==(const mat2& a, const mat2& b) noexcept {
	for(unsigned char i=0; i<mat2::DATA_SIZE; ++i) {
		if( a.data[i] != b.data[i] ) return false;
	}
	return true;
}
bool operator!=(const mat2& a, const mat2& b) noexcept {
	for(unsigned char i=0; i<mat2::DATA_SIZE; ++i) {
		if( a.data[i] != b.data[i] ) return true;
	}
	return false;
}

mat2& mat2::operator*=(const mat2& other) noexcept {
	*this = *this * other;
	return *this;
}
mat2 operator*(const mat2& a, const mat2& b) noexcept {
	mat2 out;
	for(unsigned char r=1; r<= 2; ++r) {
		for(unsigned char c=1; c<= 2; ++c) {
			auto v = vec::mul( a.row(r), b.column(c) );
			out.at(r,c) = v.x + v.y;
		}
	}
	return out;
}

::vec::vec2 mat2::operator*(const ::vec::vec2& v) const noexcept {
	::vec::vec2 out;
	
	#ifdef HAS_SIMD
	typedef simd::fixed_size_simd<float, 2> Sv;
	
	Sv sv{v.data, simd::unaligned};
	Sv col1; SIMD_INIT2(col1, m00, m01);
	Sv col2; SIMD_INIT2(col2, m10, m11);
	
	out.x = simd::reduce(sv * col1);
	out.y = simd::reduce(sv * col2);
	#else
	out.x = m00 * v.x + m01 * v.y;
	out.y = m10 * v.x + m11 * v.y;
	#endif
	
	return out;
}

::vec::vec2 operator*(const ::vec::vec2& v, const mat2& m) noexcept {
	::vec::vec2 out;
	
	#ifdef HAS_SIMD
	typedef simd::fixed_size_simd<float, 2> Sv;
	
	Sv sv{v.data, simd::unaligned};
	Sv col1; SIMD_INIT2(col1, m.m00, m.m10);
	Sv col2; SIMD_INIT2(col2, m.m01, m.m11);
	
	out.x = simd::reduce(sv * col1);
	out.y = simd::reduce(sv * col2);
	#else
	out.x = m.m00 * v.x + m.m10 * v.y;
	out.y = m.m01 * v.x + m.m11 * v.y;
	#endif
	
	return out;
}

::vec::vec2 mat2::column(unsigned char c) const {
	if( c == 1 ) {
		return ::vec::vec2(m00, m10);
	} else if( c == 2 ) {
		return ::vec::vec2(m01, m11);
	} else {
		throw std::out_of_range("c");
	}
}
::vec::vec2 mat2::row(unsigned char r) const {
	if( r == 1 ) {
		return ::vec::vec2(m00, m01);
	} else if( r == 2 ) {
		return ::vec::vec2(m10, m11);
	} else {
		throw std::out_of_range("r");
	}
}
void mat2::column(unsigned char c, const ::vec::vec2& v) {
	if( c == 1 ) {
		m00 = v.x;
		m10 = v.y;
	} else if( c == 2 ) {
		m01 = v.x;
		m11 = v.y;
	} else {
		throw std::out_of_range("c");
	}
}
void mat2::row(unsigned char r, const ::vec::vec2& v) {
	if( r == 1 ) {
		m00 = v.x;
		m01 = v.y;
	} else if( r == 2 ) {
		m10 = v.x;
		m11 = v.y;
	} else {
		throw std::out_of_range("r");
	}
}

float& mat2::at(unsigned char row, unsigned char column) {
	unsigned char i = 0;
	#ifdef GEOMETRY_MATRIX_ROW_MAJOR
	i = (column-1) * 2 + (row-1);
	#else
	i = (row-1) * 2 + (column-1);
	#endif
	if( i >= DATA_SIZE ) {
		throw std::out_of_range("");
	}
	return data[i];
}
const float& mat2::at(unsigned char row, unsigned char column) const {
	unsigned char i = 0;
	#ifdef GEOMETRY_MATRIX_ROW_MAJOR
	i = (column-1) * 2 + (row-1);
	#else
	i = (row-1) * 2 + (column-1);
	#endif
	if( i >= DATA_SIZE ) {
		throw std::out_of_range("");
	}
	return data[i];
}

mat2 mat2::transpose() const noexcept {
	return mat2(m00, m10, m01, m11);
}
mat2& mat2::transposed() noexcept {
	std::swap(m01, m10);
	return *this;
}

float mat2::det() const noexcept {
	#ifdef HAS_SIMD
	typedef simd::fixed_size_simd<float, 2> Mv;
	Mv pair1; SIMD_INIT2(pair1, m00, m01);
	Mv pair2; SIMD_INIT2(pair2, m11, m10);
	return simd::reduce(pair1 * pair2);
	#else
	float result = 0.0f;
	for(unsigned char j=0; j<2; ++j) {
		result += at(1,j+1) * perm_sign(0, j) * minor_from_m2(*this, 0, j);
	}
	return result;
	#endif
}

std::optional<mat2> mat2::inv() const noexcept {
	float this_det = det();
	if( this_det == 0.0f ) {
		return std::nullopt;
	}
	mat2 result{
		m11, -m01,
		-m10, m00
	};
	return result * (1.0f / this_det);
}
	
};//! namespace mat


namespace mat {

mat3::mat3() noexcept :
	#ifdef GEOMETRY_MATRIX_ROW_MAJOR
	m00{0.0f}, m01{0.0f}, m02{0.0f},
	m10{0.0f}, m11{0.0f}, m12{0.0f},
	m20{0.0f}, m21{0.0f}, m22{0.0f}
	#else
	m00{0.0f}, m10{0.0f}, m20{0.0f},
	m01{0.0f}, m11{0.0f}, m21{0.0f},
	m02{0.0f}, m12{0.0f}, m22{0.0f}
	#endif
	{}

mat3::mat3(float _00, float _01, float _02,
					 float _10, float _11, float _12,
					 float _20, float _21, float _22)
		noexcept :
		#ifdef GEOMETRY_MATRIX_ROW_MAJOR
		m00{_00}, m01{_01}, m02{_02},
		m10{_10}, m11{_11}, m12{_12},
		m20{_20}, m21{_21}, m22{_22}
		#else
		m00{_00}, m10{_10}, m20{_20},
		m01{_01}, m11{_11}, m21{_21},
		m02{_02}, m12{_12}, m22{_22}
		#endif
		{}

mat3 mat3::filled(float f) noexcept {
	return mat3(f, f, f, f, f, f, f, f, f);
}
mat3 mat3::diag(float f0, float f1, float f2) noexcept {
	return mat3(f0, 0.0f, 0.0f,
							0.0f, f1, 0.0f,
							0.0f, 0.0f, f2);
}
mat3 mat3::one() noexcept {
	return mat3(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
}
mat3 mat3::cols(const ::vec::vec3& c1, const ::vec::vec3& c2, const ::vec::vec3& c3) noexcept {
	return mat3(c1.x, c2.x, c3.x,
							c1.y, c2.y, c3.y,
							c1.z, c2.z, c3.z);
}
mat3 mat3::rows(const ::vec::vec3& r1, const ::vec::vec3& r2, const ::vec::vec3& r3) noexcept {
	return mat3(r1.x, r1.y, r1.z,
							r2.x, r2.y, r2.z,
							r3.x, r3.y, r3.z);
}

mat3& mat3::operator+=(const mat3& other) noexcept {
	for(unsigned char i=0; i<DATA_SIZE; ++i) {
		data[i] += other.data[i];
	}
	return *this;
}
mat3& mat3::operator-=(const mat3& other) noexcept {
	for(unsigned char i=0; i<DATA_SIZE; ++i) {
		data[i] -= other.data[i];
	}
	return *this;
}
mat3& mat3::operator*=(float scalar) noexcept {
	for(unsigned char i=0; i<DATA_SIZE; ++i) {
		data[i] *= scalar;
	}
	return *this;
}
mat3 mat3::operator-() noexcept {
	return {
		-m00, -m01, -m02,
		-m10, -m11, -m12,
		-m20, -m21, -m22
	};
}
mat3 operator+(const mat3& a, const mat3& b) noexcept {
	mat3 result;
	for(unsigned char i=0; i<mat3::DATA_SIZE; ++i) {
		result.data[i] = a.data[i] + b.data[i];
	}
	return result;
}
mat3 operator-(const mat3& a, const mat3& b) noexcept {
	mat3 result;
	for(unsigned char i=0; i<mat3::DATA_SIZE; ++i) {
		result.data[i] = a.data[i] - b.data[i];
	}
	return result;
}
mat3 operator*(float scalar, const mat3& m) noexcept {
	return m * scalar;
}
mat3 operator*(const mat3& m, float scalar) noexcept {
	mat3 result;
	for(unsigned char i=0; i<mat3::DATA_SIZE; ++i) {
		result.data[i] = m.data[i] * scalar;
	}
	return result;
}

bool operator==(const mat3& a, const mat3& b) noexcept {
	for(unsigned char i=0; i<mat3::DATA_SIZE; ++i) {
		if( a.data[i] != b.data[i] ) return false;
	}
	return true;
}
bool operator!=(const mat3& a, const mat3& b) noexcept {
	for(unsigned char i=0; i<mat3::DATA_SIZE; ++i) {
		if( a.data[i] != b.data[i] ) return true;
	}
	return false;
}

mat3& mat3::operator*=(const mat3& other) noexcept {
	*this = *this * other;
	return *this;
}
mat3 operator*(const mat3& a, const mat3& b) noexcept {
	mat3 out;
	for(unsigned char r=1; r<=3; ++r) {
		for(unsigned char c=1; c<=3; ++c) {
			#ifdef HAS_SIMD
			typedef simd::fixed_size_simd<float, 3> Sv;
			
			Sv sa{a.row(r).data, simd::unaligned};
			Sv sb{b.column(c).data, simd::unaligned};
			Sv sm = sa * sb;
			out.at(r,c) = simd::reduce(sm);
			#else
			auto v = vec::mul( a.row(r), b.column(c) );
			out.at(r,c) = v.x + v.y + v.z;
			#endif
		}
	}
	return out;
}

::vec::vec3 mat3::operator*(const ::vec::vec3& v) const noexcept {
	::vec::vec3 out;
	
	#ifdef HAS_SIMD
	typedef simd::fixed_size_simd<float, 3> Sv;
	
	Sv sv{v.data, simd::unaligned};
	Sv row1; SIMD_INIT3(row1, m00, m01, m02);
	Sv row2; SIMD_INIT3(row2, m10, m11, m12);
	Sv row3; SIMD_INIT3(row3, m20, m21, m22);
	
	out.x = simd::reduce(sv * row1);
	out.y = simd::reduce(sv * row2);
	out.z = simd::reduce(sv * row3);
	#else
	out.x = m00 * v.x + m01 * v.y + m02 * v.z;
	out.y = m10 * v.x + m11 * v.y + m12 * v.z;
	out.z = m20 * v.x + m21 * v.y + m22 * v.z;
	#endif
	
	return out;
}

::vec::vec3 operator*(const ::vec::vec3& v, const mat3& m) noexcept {
	::vec::vec3 out;
	
	#ifdef HAS_SIMD
	typedef simd::fixed_size_simd<float, 3> Sv;
	
	Sv sv{v.data, simd::unaligned};
	Sv col1; SIMD_INIT3(col1, m.m00, m.m10, m.m20);
	Sv col2; SIMD_INIT3(col2, m.m01, m.m11, m.m21);
	Sv col3; SIMD_INIT3(col3, m.m02, m.m12, m.m22);
	
	out.x = simd::reduce(sv * col1);
	out.y = simd::reduce(sv * col2);
	out.z = simd::reduce(sv * col3);
	#else
	out.x = m.m00 * v.x + m.m10 * v.y + m.m20 * v.z;
	out.y = m.m01 * v.x + m.m11 * v.y + m.m21 * v.z;
	out.z = m.m02 * v.x + m.m12 * v.y + m.m22 * v.z;
	#endif
	
	return out;
}

::vec::vec3 mat3::column(unsigned char c) const {
	if( c == 1 ) {
		return ::vec::vec3(m00, m10, m20);
	} else if( c == 2 ) {
		return ::vec::vec3(m01, m11, m21);
	} else if( c == 3 ) {
		return ::vec::vec3(m02, m12, m22);
	} else {
		throw std::out_of_range("c");
	}
}
::vec::vec3 mat3::row(unsigned char r) const {
	if( r == 1 ) {
		return ::vec::vec3(m00, m01, m02);
	} else if( r == 2 ) {
		return ::vec::vec3(m10, m11, m12);
	} else if( r == 3 ) {
		return ::vec::vec3(m20, m21, m22);
	} else {
		throw std::out_of_range("r");
	}
}
void mat3::column(unsigned char c, const ::vec::vec3& v) {
	if( c == 1 ) {
		m00 = v.x;
		m10 = v.y;
		m20 = v.z;
	} else if( c == 2 ) {
		m01 = v.x;
		m11 = v.y;
		m21 = v.z;
	} else if( c == 3 ) {
		m02 = v.x;
		m12 = v.y;
		m22 = v.z;
	} else {
		throw std::out_of_range("c");
	}
}
void mat3::row(unsigned char r, const ::vec::vec3& v) {
	if( r == 1 ) {
		m00 = v.x;
		m01 = v.y;
		m02 = v.z;
	} else if( r == 2 ) {
		m10 = v.x;
		m11 = v.y;
		m12 = v.z;
	} else if( r == 3 ) {
		m20 = v.x;
		m21 = v.y;
		m22 = v.z;
	} else {
		throw std::out_of_range("r");
	}
}

float& mat3::at(unsigned char row, unsigned char column) {
	unsigned char i = 0;
	#ifdef GEOMETRY_MATRIX_ROW_MAJOR
	i = (column-1) * 3 + (row-1);
	#else
	i = (row-1) * 3 + (column-1);
	#endif
	if( i >= DATA_SIZE ) {
		throw std::out_of_range("");
	}
	return data[i];
}
const float& mat3::at(unsigned char row, unsigned char column) const {
	unsigned char i = 0;
	#ifdef GEOMETRY_MATRIX_ROW_MAJOR
	i = (column-1) * 3 + (row-1);
	#else
	i = (row-1) * 3 + (column-1);
	#endif
	if( i >= DATA_SIZE ) {
		throw std::out_of_range("");
	}
	return data[i];
}

mat3 mat3::transpose() const noexcept {
	return mat3(m00, m10, m20, m01, m11, m21, m02, m12, m22);
}
mat3& mat3::transposed() noexcept {
	std::swap(m01, m10);
	std::swap(m20, m02);
	std::swap(m21, m12);
	return *this;
}

float mat3::det() const noexcept {
	#ifdef HAS_SIMD
	typedef simd::fixed_size_simd<float, 3> Mv;
	
	Mv triple1_p; SIMD_INIT3(triple1_p, m00, m01, m02);
	Mv triple2_p; SIMD_INIT3(triple2_p, m11, m12, m10);
	Mv triple3_p; SIMD_INIT3(triple3_p, m22, m20, m21);
	
	Mv triple1_n; SIMD_INIT3(triple1_n, m02, m01, m00);
	Mv triple2_n; SIMD_INIT3(triple2_n, m11, m10, m12);
	Mv triple3_n; SIMD_INIT3(triple3_n, m20, m22, m21);
	
	return
		simd::reduce(triple1_p * triple2_p * triple3_p)
		- simd::reduce(triple1_n * triple2_n * triple3_n);
	#else
	float result = 0.0f;
	for(unsigned char j=0; j<3; ++j) {
		result += at(1,j+1) * perm_sign(0, j) * minor_from_m3(*this, 0, j);
	}
	return result;
	#endif
}

std::optional<mat3> mat3::inv() const noexcept {
	float this_det = det();
	if( this_det == 0.0f ) {
		return std::nullopt;
	}
	
	mat3 result;
	auto a = column(1);
	auto b = column(2);
	auto c = column(3);
	result.row(1, ::vec::cross(b, c));
	result.row(2, ::vec::cross(c, a));
	result.row(3, ::vec::cross(a, b));
	return result * (1.0f / this_det);
}
	
};//! namespace mat


namespace mat {

mat4::mat4() noexcept :
	#ifdef GEOMETRY_MATRIX_ROW_MAJOR
	m00{0.0f}, m01{0.0f}, m02{0.0f}, m03{0.0f},
	m10{0.0f}, m11{0.0f}, m12{0.0f}, m13{0.0f},
	m20{0.0f}, m21{0.0f}, m22{0.0f}, m23{0.0f},
	m30{0.0f}, m31{0.0f}, m32{0.0f}, m33{0.0f}
	#else
	m00{0.0f}, m10{0.0f}, m20{0.0f}, m30{0.0f},
	m01{0.0f}, m11{0.0f}, m21{0.0f}, m31{0.0f},
	m02{0.0f}, m12{0.0f}, m22{0.0f}, m32{0.0f},
	m03{0.0f}, m13{0.0f}, m23{0.0f}, m33{0.0f}
	#endif
	{}

mat4::mat4(float _00, float _01, float _02, float _03,
					 float _10, float _11, float _12, float _13,
					 float _20, float _21, float _22, float _23,
					 float _30, float _31, float _32, float _33)
		noexcept :
		#ifdef GEOMETRY_MATRIX_ROW_MAJOR
		m00{_00}, m01{_01}, m02{_02}, m03{_03},
		m10{_10}, m11{_11}, m12{_12}, m13{_13},
		m20{_20}, m21{_21}, m22{_22}, m23{_23},
		m30{_30}, m31{_31}, m32{_32}, m33{_33}
		#else
		m00{_00}, m10{_10}, m20{_20}, m30{_30},
		m01{_01}, m11{_11}, m21{_21}, m31{_31},
		m02{_02}, m12{_12}, m22{_22}, m32{_32},
		m03{_03}, m13{_13}, m23{_23}, m33{_33}
		#endif
		{}

mat4 mat4::filled(float f) noexcept {
	return mat4(f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f);
}
mat4 mat4::diag(float f0, float f1, float f2, float f3) noexcept {
	return mat4(f0, 0.0f, 0.0f, 0.0f,
							0.0f, f1, 0.0f, 0.0f,
							0.0f, 0.0f, f2, 0.0f,
							0.0f, 0.0f, 0.0f, f3);
}
mat4 mat4::one() noexcept {
	return mat4(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
}
mat4 mat4::cols(const ::vec::vec4& c1, const ::vec::vec4& c2,
	const ::vec::vec4& c3, const ::vec::vec4& c4) noexcept {
	return mat4(c1.x, c2.x, c3.x, c4.x,
							c1.y, c2.y, c3.y, c4.y,
							c1.z, c2.z, c3.z, c4.z,
							c1.w, c2.w, c3.w, c4.w);
}
mat4 mat4::rows(const ::vec::vec4& r1, const ::vec::vec4& r2,
	const ::vec::vec4& r3, const ::vec::vec4& r4) noexcept {
	return mat4(r1.x, r1.y, r1.z, r1.w,
							r2.x, r2.y, r2.z, r2.w,
							r3.x, r3.y, r3.z, r3.w,
							r4.x, r4.y, r4.z, r4.w);
}

mat4& mat4::operator+=(const mat4& other) noexcept {
	for(unsigned char i=0; i<DATA_SIZE; ++i) {
		data[i] += other.data[i];
	}
	return *this;
}
mat4& mat4::operator-=(const mat4& other) noexcept {
	for(unsigned char i=0; i<DATA_SIZE; ++i) {
		data[i] -= other.data[i];
	}
	return *this;
}
mat4& mat4::operator*=(float scalar) noexcept {
	for(unsigned char i=0; i<DATA_SIZE; ++i) {
		data[i] *= scalar;
	}
	return *this;
}
mat4 mat4::operator-() noexcept {
	return {
		-m00, -m01, -m02, -m03,
		-m10, -m11, -m12, -m13,
		-m20, -m21, -m22, -m23,
		-m30, -m31, -m32, -m33
	};
}
mat4 operator+(const mat4& a, const mat4& b) noexcept {
	mat4 result;
	for(unsigned char i=0; i<mat4::DATA_SIZE; ++i) {
		result.data[i] = a.data[i] + b.data[i];
	}
	return result;
}
mat4 operator-(const mat4& a, const mat4& b) noexcept {
	mat4 result;
	for(unsigned char i=0; i<mat4::DATA_SIZE; ++i) {
		result.data[i] = a.data[i] - b.data[i];
	}
	return result;
}
mat4 operator*(float scalar, const mat4& m) noexcept {
	return m * scalar;
}
mat4 operator*(const mat4& m, float scalar) noexcept {
	mat4 result;
	for(unsigned char i=0; i<mat4::DATA_SIZE; ++i) {
		result.data[i] = m.data[i] * scalar;
	}
	return result;
}

bool operator==(const mat4& a, const mat4& b) noexcept {
	for(unsigned char i=0; i<mat4::DATA_SIZE; ++i) {
		if( a.data[i] != b.data[i] ) return false;
	}
	return true;
}
bool operator!=(const mat4& a, const mat4& b) noexcept {
	for(unsigned char i=0; i<mat4::DATA_SIZE; ++i) {
		if( a.data[i] != b.data[i] ) return true;
	}
	return false;
}

mat4& mat4::operator*=(const mat4& other) noexcept {
	*this = *this * other;
	return *this;
}
mat4 operator*(const mat4& a, const mat4& b) noexcept {
	mat4 out;
	for(unsigned char r=1; r<=4; ++r) {
		for(unsigned char c=1; c<=4; ++c) {
			#ifdef HAS_SIMD
			typedef simd::fixed_size_simd<float, 4> Sv;
			
			Sv sa{a.row(r).data, simd::unaligned};
			Sv sb{b.column(c).data, simd::unaligned};
			Sv sv = sa * sb;
			
			out.at(r,c) = simd::reduce(sv);
			#else
			auto v = vec::mul( a.row(r), a.column(c) );
			out.at(r,c) = v.x + v.y + v.z + v.w;
			#endif
		}
	}
	return out;
}

::vec::vec4 mat4::operator*(const ::vec::vec4& v) const noexcept {
	::vec::vec4 out;
	
	#ifdef HAS_SIMD
	typedef simd::fixed_size_simd<float, 4> Sv;
	
	Sv sv{v.data, simd::unaligned};
	Sv row1; SIMD_INIT4(row1, m00, m01, m02, m03);
	Sv row2; SIMD_INIT4(row2, m10, m11, m12, m13);
	Sv row3; SIMD_INIT4(row3, m20, m21, m22, m23);
	Sv row4; SIMD_INIT4(row4, m30, m31, m32, m33);
	
	out.x = simd::reduce(sv * row1);
	out.y = simd::reduce(sv * row2);
	out.z = simd::reduce(sv * row3);
	out.w = simd::reduce(sv * row4);
	#else
	out.x = m00 * v.x + m01 * v.y + m02 * v.z + m03 * v.w;
	out.y = m10 * v.x + m11 * v.y + m12 * v.z + m13 * v.w;
	out.z = m20 * v.x + m21 * v.y + m22 * v.z + m23 * v.w;
	out.w = m30 * v.x + m31 * v.y + m32 * v.z + m33 * v.w;
	#endif
	
	return out;
}

::vec::vec4 operator*(const ::vec::vec4& v, const mat4& m) noexcept {
	::vec::vec4 out;
	
	#ifdef HAS_SIMD
	typedef simd::fixed_size_simd<float, 4> Sv;
	
	Sv sv{v.data, simd::unaligned};
	Sv col1; SIMD_INIT4(col1, m.m00, m.m10, m.m20, m.m30);
	Sv col2; SIMD_INIT4(col2, m.m01, m.m11, m.m21, m.m31);
	Sv col3; SIMD_INIT4(col3, m.m02, m.m12, m.m22, m.m32);
	Sv col4; SIMD_INIT4(col4, m.m03, m.m13, m.m23, m.m33);
	
	out.x = simd::reduce(sv * col1);
	out.y = simd::reduce(sv * col2);
	out.z = simd::reduce(sv * col3);
	out.w = simd::reduce(sv * col4);
	#else
	out.x = m.m00 * v.x + m.m10 * v.y + m.m20 * v.z + m.m30 * v.w;
	out.y = m.m01 * v.x + m.m11 * v.y + m.m21 * v.z + m.m31 * v.w;
	out.z = m.m02 * v.x + m.m12 * v.y + m.m22 * v.z + m.m32 * v.w;
	out.w = m.m03 * v.x + m.m13 * v.y + m.m23 * v.z + m.m33 * v.w;
	#endif
	
	return out;
}

::vec::vec4 mat4::column(unsigned char c) const {
	if( c == 1 ) {
		return ::vec::vec4(m00, m10, m20, m30);
	} else if( c == 2 ) {
		return ::vec::vec4(m01, m11, m21, m31);
	} else if( c == 3 ) {
		return ::vec::vec4(m02, m12, m22, m32);
	} else if( c == 4 ) {
		return ::vec::vec4(m03, m13, m23, m33);
	} else {
		throw std::out_of_range("c");
	}
}
::vec::vec4 mat4::row(unsigned char r) const {
	if( r == 1 ) {
		return ::vec::vec4(m00, m01, m02, m03);
	} else if( r == 2 ) {
		return ::vec::vec4(m10, m11, m12, m13);
	} else if( r == 3 ) {
		return ::vec::vec4(m20, m21, m22, m23);
	} else if( r == 4 ) {
		return ::vec::vec4(m30, m31, m32, m33);
	} else {
		throw std::out_of_range("r");
	}
}
void mat4::column(unsigned char c, const ::vec::vec4& v) {
	if( c == 1 ) {
		m00 = v.x;
		m10 = v.y;
		m20 = v.z;
		m30 = v.w;
	} else if( c == 2 ) {
		m01 = v.x;
		m11 = v.y;
		m21 = v.z;
		m31 = v.w;
	} else if( c == 3 ) {
		m02 = v.x;
		m12 = v.y;
		m22 = v.z;
		m32 = v.w;
	} else if( c == 4 ) {
		m03 = v.x;
		m13 = v.y;
		m23 = v.z;
		m33 = v.w;
	} else {
		throw std::out_of_range("c");
	}
}
void mat4::row(unsigned char r, const ::vec::vec4& v) {
	if( r == 1 ) {
		m00 = v.x;
		m01 = v.y;
		m02 = v.z;
		m03 = v.w;
	} else if( r == 2 ) {
		m10 = v.x;
		m11 = v.y;
		m12 = v.z;
		m13 = v.w;
	} else if( r == 3 ) {
		m20 = v.x;
		m21 = v.y;
		m22 = v.z;
		m23 = v.w;
	} else if( r == 4 ) {
		m30 = v.x;
		m31 = v.y;
		m32 = v.z;
		m33 = v.w;
	} else {
		throw std::out_of_range("r");
	}
}

float& mat4::at(unsigned char row, unsigned char column) {
	unsigned char i = 0;
	#ifdef GEOMETRY_MATRIX_ROW_MAJOR
	i = (column-1) * 4 + (row-1);
	#else
	i = (row-1) * 4 + (column-1);
	#endif
	if( i >= DATA_SIZE ) {
		throw std::out_of_range("");
	}
	return data[i];
}
const float& mat4::at(unsigned char row, unsigned char column) const {
	unsigned char i = 0;
	#ifdef GEOMETRY_MATRIX_ROW_MAJOR
	i = (column-1) * 4 + (row-1);
	#else
	i = (row-1) * 4 + (column-1);
	#endif
	if( i >= DATA_SIZE ) {
		throw std::out_of_range("");
	}
	return data[i];
}

mat4 mat4::transpose() const noexcept {
	return mat4(m00, m10, m20, m30, m01, m11, m21, m31, m02, m12, m22, m32, m03, m13, m23, m33);
}
mat4& mat4::transposed() noexcept {
	std::swap(m01, m10);
	std::swap(m20, m02);
	std::swap(m21, m12);
	std::swap(m03, m30);
	std::swap(m13, m31);
	std::swap(m23, m32);
	return *this;
}

float mat4::det() const noexcept {
	#ifdef HAS_SIMD
	typedef simd::fixed_size_simd<float, 3> Mv;
	
	Mv t1_p, t2_p, t3_p, t1_n, t2_n, t3_n;
	float result = 0.0f;
	
	// column 1
	SIMD_INIT3(t1_p, m01, m21, m11); SIMD_INIT3(t1_n, m03, m02, m01);
	SIMD_INIT3(t2_p, m12, m02, m22); SIMD_INIT3(t2_n, m12, m11, m13);
	SIMD_INIT3(t3_p, m23, m13, m03); SIMD_INIT3(t3_n, m21, m23, m22);
	result -= m30 * (simd::reduce(t1_p * t2_p * t3_p) - simd::reduce(t1_n * t2_n * t3_n));
	
	// column 2
	SIMD_INIT3(t1_p, m00, m02, m03); SIMD_INIT3(t1_n, m03, m02, m00);
	SIMD_INIT3(t2_p, m12, m13, m10); SIMD_INIT3(t2_n, m12, m10, m13);
	SIMD_INIT3(t3_p, m23, m20, m22); SIMD_INIT3(t3_n, m20, m23, m22);
	result += m31 * (simd::reduce(t1_p * t2_p * t3_p) - simd::reduce(t1_n * t2_n * t3_n));
	
	// column 3
	SIMD_INIT3(t1_p, m00, m01, m03); SIMD_INIT3(t1_n, m03, m01, m00);
	SIMD_INIT3(t2_p, m11, m13, m10); SIMD_INIT3(t2_n, m11, m10, m13);
	SIMD_INIT3(t3_p, m23, m20, m21); SIMD_INIT3(t3_n, m20, m23, m21);
	result -= m32 * (simd::reduce(t1_p * t2_p * t3_p) - simd::reduce(t1_n * t2_n * t3_n));
	
	// column 4
	SIMD_INIT3(t1_p, m00, m01, m02); SIMD_INIT3(t1_n, m02, m01, m00);
	SIMD_INIT3(t2_p, m11, m12, m10); SIMD_INIT3(t2_n, m11, m10, m12);
	SIMD_INIT3(t3_p, m22, m20, m21); SIMD_INIT3(t3_n, m20, m22, m21);
	result += m33 * (simd::reduce(t1_p * t2_p * t3_p) - simd::reduce(t1_n * t2_n * t3_n));
	
	return result;
	#else
	float result = 0.0f;
	for(unsigned char j=0; j<4; ++j) {
		result += at(4,j+1) * perm_sign(3, j) * minor_from_m4(*this, 3, j);
	}
	return result;
	#endif
}

std::optional<mat4> mat4::inv() const noexcept {
	float this_det = det();
	if( this_det == 0.0f ) {
		return std::nullopt;
	}
	
	auto A = column(1); auto a = A.xyz(); auto x = A.w;
	auto B = column(2); auto b = B.xyz(); auto y = B.w;
	auto C = column(3); auto c = C.xyz(); auto z = C.w;
	auto D = column(4); auto d = D.xyz(); auto w = D.w;
	
	auto s = ::vec::cross(a, b);
	auto t = ::vec::cross(c, d);
	auto u = (y * a) - (x * b);
	auto v = (w * c) - (z * d);
	
	::vec::vec4 row1{::vec::cross(b,v) + (y*t), - ::vec::dot(b,t)};
	::vec::vec4 row2{::vec::cross(v,a) - (x*t), ::vec::dot(a,t)};
	::vec::vec4 row3{::vec::cross(d,u) + (w*s), - ::vec::dot(d,s)};
	::vec::vec4 row4{::vec::cross(u,c) - (z*s), ::vec::dot(c,s)};
	
	mat4 result = mat4::rows(row1, row2, row3, row4);
	return result * (1.0f / this_det);
}
	
};//! namespace mat



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


