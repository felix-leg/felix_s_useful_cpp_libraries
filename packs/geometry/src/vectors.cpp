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

#include "vectors.hpp"

#include <utility>
#include <cmath>
#include <format>

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
vec3::vec3(const vec2& v2, float _z) noexcept : x{v2.x}, y{v2.y}, z{_z} {}

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

std::ostream& operator<<(std::ostream& os, const bvec2& bv) noexcept {
	os << "{" << std::format("{}, {}", bv.x, bv.y) << "}";
	return os;
}

std::ostream& operator<<(std::ostream& os, const bvec3& bv) noexcept {
	os << "{" << std::format("{}, {}, {}", bv.x, bv.y, bv.z) << "}";
	return os;
}

std::ostream& operator<<(std::ostream& os, const bvec4& bv) noexcept {
	os << "{" << std::format("{}, {}, {}, {}", bv.x, bv.y, bv.z, bv.w) << "}";
	return os;
}

std::ostream& operator<<(std::ostream& os, const vec2& v) noexcept {
	os << "{" << std::format("{}, {}", v.x, v.y) << "}";
	return os;
}

std::ostream& operator<<(std::ostream& os, const vec3& v) noexcept {
	os << "{" << std::format("{}, {}, {}", v.x, v.y, v.z) << "}";
	return os;
}

std::ostream& operator<<(std::ostream& os, const vec4& v) noexcept {
	os << "{" << std::format("{}, {}, {}, {}", v.x, v.y, v.z, v.w) << "}";
	return os;
}

};//! namespace vec
