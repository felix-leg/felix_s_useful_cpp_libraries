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

#include "transform.hpp"

#include <cmath>

namespace transform {
	
	mat::mat2 rotation_m2(float theta) noexcept {
		float sin_t = std::sin(theta);
		float cos_t = std::cos(theta);
		return mat::mat2(
			cos_t, -sin_t,
			sin_t, cos_t
		);
	}
	
	mat::mat3 translation_m3(float x, float y) noexcept {
		return mat::mat3(
			1.0f, 0.0f, x,
			0.0f, 1.0f, y,
			0.0f, 0.0f, 1.0f
		);
	}
	
	mat::mat3 translation_m3(const vec::vec2& v) noexcept {
		return translation_m3(v.x, v.y);
	}
	
	mat::mat3 rotation_m3_x(float theta) noexcept {
		float sin_t = std::sin(theta);
		float cos_t = std::cos(theta);
		return mat::mat3(
			1.0f, 0.0f, 0.0f,
			0.0f, cos_t, -sin_t,
			0.0f, sin_t, cos_t
		);
	}
	
	mat::mat3 rotation_m3_y(float theta) noexcept {
		float sin_t = std::sin(theta);
		float cos_t = std::cos(theta);
		return mat::mat3(
			cos_t, 0.0f, sin_t,
			0.0f, 1, 0.0f,
			-sin_t, 0.0f, cos_t
		);
	}
	
	mat::mat3 rotation_m3_z(float theta) noexcept {
		float sin_t = std::sin(theta);
		float cos_t = std::cos(theta);
		return mat::mat3(
			cos_t, -sin_t, 0.0f,
			sin_t, cos_t, 0.0f,
			0.0f, 0.0f, 1
		);
	}
	
	mat::mat3 rotation_m3_a(vec::vec3 a, float theta) noexcept {
		a.normalize();
		float c = std::cos(theta);
		float s = std::sin(theta);
		float c1 = 1 - c;
		
		float ax2 = a.x * a.x;
		float ay2 = a.y * a.y;
		float az2 = a.z * a.z;
		
		float axay = a.x * a.y;
		float axaz = a.x * a.z;
		float ayaz = a.y * a.z;
		
		return mat::mat3(
			c + c1*ax2, c1*axay - s*a.z, c1*axaz + s*a.y,
			c1*axay + s*a.z, c + c1*ay2, c1*ayaz - s*a.x,
			c1*axaz - s*a.y, c1*ayaz + s*a.x, c + c1*az2
		);
	}
	
	mat::mat3 mirror_m3(vec::vec3 n) noexcept {
		n.normalize();
		
		float nx2 = 1 - 2*(n.x * n.x);
		float ny2 = 1 - 2*(n.y * n.y);
		float nz2 = 1 - 2*(n.z * n.z);
		
		float nxny = -2*(n.x * n.y);
		float nxnz = -2*(n.x * n.z);
		float nynz = -2*(n.y * n.z);
		
		return mat::mat3(
			nx2, nxny, nxnz,
			nxny, ny2, nynz,
			nxnz, nynz, nz2
		);
	}
	
	mat::mat3 involution_m3(vec::vec3 n) noexcept {
		return - mirror_m3(n);
	}
	
	mat::mat3 scale_m3(float s) noexcept {
		return scale_m3(s, s, s);
	}
	
	mat::mat3 scale_m3(float sx, float sy, float sz) noexcept {
		return mat::mat3(
			sx, 0.0f, 0.0f,
			0.0f, sy, 0.0f,
			0.0f, 0.0f, sz
		);
	}
	
	mat::mat3 scale_m3(const vec::vec3& v) noexcept {
		return scale_m3(v.x, v.y, v.z);
	}
	
	mat::mat3 scale_m3(const vec::vec3& a, float s) noexcept {
		s = s-1;
		float ax2 = s * a.x * a.x + 1;
		float ay2 = s * a.y * a.y + 1;
		float az2 = s * a.z * a.z + 1;
		
		float axay = s * a.x * a.y;
		float axaz = s * a.x * a.z;
		float ayaz = s * a.y * a.z;
		
		return mat::mat3(
			ax2, axay, axaz,
			axay, ay2, ayaz,
			axaz, ayaz, az2
		);
	}
	
	mat::mat3 skew_m3(float theta, const vec::vec3& in_dir, const vec::vec3& perp) noexcept {
		float t = std::tan(theta);
		
		return mat::mat3(
			in_dir.x * perp.x * t + 1, in_dir.x * perp.y * t, in_dir.x * perp.z * t,
			in_dir.y * perp.x * t, in_dir.y * perp.y * t + 1, in_dir.y * perp.z * t,
			in_dir.z * perp.x * t, in_dir.z * perp.y * t, in_dir.z * perp.z * t + 1
		);
	}
	
	mat::mat4 translation_m4(float x, float y, float z) noexcept {
		return mat::mat4(
			1.0f, 0.0f, 0.0f, x,
			0.0f, 1.0f, 0.0f, y,
			0.0f, 0.0f, 1.0f, z,
			0.0f, 0.0f, 0.0f, 1.0f
		);
	}
	
	mat::mat4 translation_m4(const vec::vec3& v) noexcept {
		return translation_m4(v.x, v.y, v.z);
	}
	
	#define EXPAND_TO_M4(M) \
		mat::mat4( \
			M.m00, M.m01, M.m02, 0.0f, \
			M.m10, M.m11, M.m12, 0.0f, \
			M.m20, M.m21, M.m22, 0.0f, \
			0.0f, 0.0f, 0.0f, 1.0f \
		)
	
	mat::mat4 rotation_m4_x(float theta) noexcept {
		auto m3 = rotation_m3_x(theta);
		return EXPAND_TO_M4(m3);
	}
	
	mat::mat4 rotation_m4_y(float theta) noexcept {
		auto m3 = rotation_m3_y(theta);
		return EXPAND_TO_M4(m3);
	}
	
	mat::mat4 rotation_m4_z(float theta) noexcept {
		auto m3 = rotation_m3_z(theta);
		return EXPAND_TO_M4(m3);
	}
	
	mat::mat4 rotation_m4_a(vec::vec3 a, float theta) noexcept {
		auto m3 = rotation_m3_a(a, theta);
		return EXPAND_TO_M4(m3);
	}
	
	mat::mat4 mirror_m4(vec::vec3 n) noexcept {
		auto m3 = mirror_m3(n);
		return EXPAND_TO_M4(m3);
	}
	
	mat::mat4 involution_m4(vec::vec3 n) noexcept {
		auto m3 = involution_m3(n);
		return EXPAND_TO_M4(m3);
	}
	
	mat::mat4 scale_m4(float s) noexcept {
		return scale_m4(s, s, s);
	}
	
	mat::mat4 scale_m4(float sx, float sy, float sz) noexcept {
		auto m3 = scale_m3(sx, sy, sz);
		return EXPAND_TO_M4(m3);
	}
	
	mat::mat4 scale_m4(const vec::vec3& v) noexcept {
		return scale_m4(v.x, v.y, v.z);
	}
	
	mat::mat4 scale_m4(const vec::vec3& a, float s) noexcept {
		auto m3 = scale_m3(a, s);
		return EXPAND_TO_M4(m3);
	}
	
	mat::mat4 skew_m4(float theta, const vec::vec3& in_dir, const vec::vec3& perp) noexcept {
		auto m3 = skew_m3(theta, in_dir, perp);
		return EXPAND_TO_M4(m3);
	}
	
	#undef EXPAND_TO_M4
	
} //! namespace transform

