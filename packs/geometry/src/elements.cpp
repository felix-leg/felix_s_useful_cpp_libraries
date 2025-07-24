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

#include "elements.hpp"

#include <cmath>

inline float sq(float a) { return a * a; }

namespace geometry::elements {
	
	::vec::vec2 line2d::get_point(float t) const noexcept {
		return base + t * direction;
	}
	
	::vec::vec3 line3d::get_point(float t) const noexcept {
		return base + t * direction;
	}
	
	float line2d::distance_to(const ::vec::vec2& point) const noexcept {
		::vec::vec3 u{point - base, 0.0f};
		auto nom = sq(vec::cross(u, direction.to_vec3()).length());
		auto den = sq(direction.length());
		return std::sqrt(nom / den);
	}
	
	float line3d::distance_to(const ::vec::vec3& point) const noexcept {
		::vec::vec3 u{point - base};
		auto nom = sq(vec::cross(u, direction).length());
		auto den = sq(direction.length());
		return std::sqrt(nom / den);
	}
	
	float line2d::distance_to(const line2d& other_line) const noexcept {
		float scale = sq(::vec::dot(direction, other_line.direction)) - direction.length_sq() * other_line.direction.length_sq();
		if( scale != 0.0f ) {
			return 0.0f;
		}
		return distance_to(other_line.base);
	}
	
	float line3d::distance_to(const line3d& other_line) const noexcept {
		float d_v1_v2 = ::vec::dot(direction, other_line.direction);
		auto d_p1_p2 = other_line.base - base;
		float scale = sq(d_v1_v2) - direction.length_sq() * other_line.direction.length_sq();
		if( scale == 0.0f ) {
			return distance_to(other_line.base);
		}
		scale = 1.0f / scale;
		
		::mat::mat2 A{
			- other_line.direction.length_sq(), d_v1_v2,
			- d_v1_v2, direction.length_sq()
		};
		::vec::vec2 B{
			::vec::dot(d_p1_p2, direction),
			::vec::dot(d_p1_p2, other_line.direction)
		};
		auto T = scale * (A * B);
		return (other_line.get_point(T.y) - get_point(T.x)).length();
	}
	
} //! namespace lines

