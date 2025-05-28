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

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE geometry_test
#include <boost/test/unit_test.hpp>

#include <numbers>
#include <cmath>

constexpr float PI_2 = std::numbers::pi_v<float> / 2.0f;

#include "../src/geometry.hpp"


BOOST_AUTO_TEST_CASE( vec_init ) {
	vec::vec2 v2;
	vec::vec3 v3;
	vec::vec4 v4;
	vec::vec4 v4v{false};
	
	BOOST_TEST_REQUIRE( v2.x == 0.0f ); BOOST_TEST_REQUIRE( v2.y == 0.0f );
	BOOST_TEST_REQUIRE( v3.x == 0.0f ); BOOST_TEST_REQUIRE( v3.y == 0.0f );
		BOOST_TEST_REQUIRE( v3.z == 0.0f );
	BOOST_TEST_REQUIRE( v4.x == 0.0f ); BOOST_TEST_REQUIRE( v4.y == 0.0f );
		BOOST_TEST_REQUIRE( v4.z == 0.0f ); BOOST_TEST_REQUIRE( v4.w == 1.0f );
	BOOST_TEST_REQUIRE( v4v.x == 0.0f ); BOOST_TEST_REQUIRE( v4v.y == 0.0f );
		BOOST_TEST_REQUIRE( v4v.z == 0.0f ); BOOST_TEST_REQUIRE( v4v.w == 0.0f );
	
	BOOST_TEST_REQUIRE( v2.data[0] == 0.0f ); BOOST_TEST_REQUIRE( v2.data[1] == 0.0f );
	BOOST_TEST_REQUIRE( v3.data[0] == 0.0f ); BOOST_TEST_REQUIRE( v3.data[1] == 0.0f );
		BOOST_TEST_REQUIRE( v3.data[2] == 0.0f );
	BOOST_TEST_REQUIRE( v4.data[0] == 0.0f ); BOOST_TEST_REQUIRE( v4.data[1] == 0.0f );
		BOOST_TEST_REQUIRE( v4.data[2] == 0.0f ); BOOST_TEST_REQUIRE( v4.data[3] == 1.0f );
	BOOST_TEST_REQUIRE( v4v.data[0] == 0.0f ); BOOST_TEST_REQUIRE( v4v.data[1] == 0.0f );
		BOOST_TEST_REQUIRE( v4v.data[2] == 0.0f ); BOOST_TEST_REQUIRE( v4v.data[3] == 0.0f );
}

BOOST_AUTO_TEST_CASE( vec_dot ) {
	vec::vec2 v2a{1.0f, 2.0f}, v2b{2.0f, 1.0f};
	vec::vec3 v3a{1.0f, 2.0f, 3.0f}, v3b{3.0f, 2.0f, 1.0f};
	vec::vec4 v4a{1.0f, 2.0f, 3.0f, 4.0f}, v4b{4.0f, 3.0f, 2.0f, 1.0f};
	
	BOOST_TEST_REQUIRE( vec::dot(v2a, v2b) == 4.0f );
	BOOST_TEST_REQUIRE( vec::dot(v3a, v3b) == 10.0f );
	BOOST_TEST_REQUIRE( vec::dot(v4a, v4b) == 20.0f );
}

BOOST_AUTO_TEST_CASE( vec_cross ) {
	vec::vec3 a{1.0f, 2.0f, 3.0f}, b{3.0f, 2.0f, 1.0f};
	vec::vec3 out{ -4.0f, 8.0f, -4.0f };
	
	auto r = vec::cross(a, b);
	BOOST_TEST_REQUIRE( (r == out) );
}

BOOST_AUTO_TEST_CASE( vec_length ) {
	vec::vec2 v2{0.0f, 10.0f};
	vec::vec3 v3{0.0f, 0.0f, 10.0f};
	vec::vec4 v4{0.0f, 0.0f, 0.0f, 10.0f};
	
	BOOST_TEST_REQUIRE( v2.length() == 10.0f );
	BOOST_TEST_REQUIRE( v2.length_sq() == 100.0f );
	
	BOOST_TEST_REQUIRE( v3.length() == 10.0f );
	BOOST_TEST_REQUIRE( v3.length_sq() == 100.0f );
	
	BOOST_TEST_REQUIRE( v4.length() == 10.0f );
	BOOST_TEST_REQUIRE( v4.length_sq() == 100.0f );
}

BOOST_AUTO_TEST_CASE( vec_norm ) {
	vec::vec2 v2{0.0f, 3.0f};
	vec::vec3 v3{3.0f, 0.0f, 0.0f};
	vec::vec4 v4{0.0f, 0.0f, 3.0f, 0.0f};
	
	BOOST_TEST_REQUIRE( (v2.normalized() == vec::vec2(0.0f, 1.0f)) );
	BOOST_TEST_REQUIRE( (v3.normalized() == vec::vec3(1.0f, 0.0f, 0.0f)) );
	BOOST_TEST_REQUIRE( (v4.normalized() == vec::vec4(0.0f, 0.0f, 1.0f, 0.0f)) );
}

BOOST_AUTO_TEST_CASE( vec_component_wise_operations ) {
	vec::vec2 a2{1.0f, 2.0f}, b2{3.0f, 4.0f};
	vec::vec3 a3{1.0f, 2.0f, 3.0f}, b3{4.0f, 5.0f, 6.0f};
	vec::vec4 a4{1.0f, 2.0f, 3.0f, 4.0f}, b4{5.0f, 6.0f, 7.0f, 8.0f};
	
	BOOST_TEST_REQUIRE( vec::is(a2, vec::LESS, b2).all() );
	BOOST_TEST_REQUIRE( vec::is(a2, vec::LESS_EQ, b2).all() );
	BOOST_TEST_REQUIRE( vec::is(a2, vec::GREATER, b2).none() );
	BOOST_TEST_REQUIRE( vec::is(a2, vec::GREATER_EQ, b2).none() );
	BOOST_TEST_REQUIRE( vec::is(a2, vec::EQ, b2).none() );
	BOOST_TEST_REQUIRE( vec::is(a2, vec::NOT_EQ, b2).any() );
	BOOST_TEST_REQUIRE( (vec::mul(a2,b2) == vec::vec2(3.0f, 8.0f)) );
	BOOST_TEST_REQUIRE( (vec::div(a2,b2) == vec::vec2(1.0f/3.0f, 0.5f)) );
	
	BOOST_TEST_REQUIRE( vec::is(a3, vec::LESS, b3).all() );
	BOOST_TEST_REQUIRE( vec::is(a3, vec::LESS_EQ, b3).all() );
	BOOST_TEST_REQUIRE( vec::is(a3, vec::GREATER, b3).none() );
	BOOST_TEST_REQUIRE( vec::is(a3, vec::GREATER_EQ, b3).none() );
	BOOST_TEST_REQUIRE( vec::is(a3, vec::EQ, b3).none() );
	BOOST_TEST_REQUIRE( vec::is(a3, vec::NOT_EQ, b3).any() );
	BOOST_TEST_REQUIRE( (vec::mul(a3,b3) == vec::vec3(4.0f, 10.0f, 18.0f)) );
	BOOST_TEST_REQUIRE( (vec::div(a3,b3) == vec::vec3(0.25f, 2.0f/5.0f, 0.5f)) );
	
	BOOST_TEST_REQUIRE( vec::is(43, vec::LESS, b4).all() );
	BOOST_TEST_REQUIRE( vec::is(a4, vec::LESS_EQ, b4).all() );
	BOOST_TEST_REQUIRE( vec::is(a4, vec::GREATER, b4).none() );
	BOOST_TEST_REQUIRE( vec::is(a4, vec::GREATER_EQ, b4).none() );
	BOOST_TEST_REQUIRE( vec::is(a4, vec::EQ, b4).none() );
	BOOST_TEST_REQUIRE( vec::is(a4, vec::NOT_EQ, b4).any() );
	BOOST_TEST_REQUIRE( (vec::mul(a4,b4) == vec::vec4(5.0f, 12.0f, 21.0f, 32.0f)) );
	BOOST_TEST_REQUIRE( (vec::div(a4,b4) == vec::vec4(1.0f/5.0f, 1.0f/3.0f, 3.0f/7.0f, 0.5f)) );
}

BOOST_AUTO_TEST_CASE( vec_theta ) {
	vec::vec2 a2{0.0f, 1.0f}, b2{1.0f, 0.0f};
	vec::vec3 a3{0.0f, 1.0f, 0.0f}, b3{1.0f, 0.0f, 1.0f};
	vec::vec4 a4{0.0f, 1.0f, 0.0f, 0.0f}, b4{1.0f, 0.0f, 1.0f, 0.0f};
	
	BOOST_TEST_REQUIRE( vec::theta(a2, b2).value() == std::numbers::pi_v<float>/2.0f );
	BOOST_TEST_REQUIRE( vec::theta(a3, b3).value() == std::numbers::pi_v<float>/2.0f );
	BOOST_TEST_REQUIRE( vec::theta(a4, b4).value() == std::numbers::pi_v<float>/2.0f );
	
	BOOST_TEST_REQUIRE( vec::sin(a3, b3).value() == 1.0f );
}

BOOST_AUTO_TEST_CASE( vec_projection ) {
	vec::vec2 p2{2.0f, 3.0f},
		p2x{1.0f, 0.0f}, p2y{0.0f, 1.0f};
	vec::vec3 p3{2.0f, 3.0f, 4.0f},
		p3x{1.0f, 0.0f, 0.0f}, p3y{0.0f, 1.0f, 0.0f}, p3z{0.0f, 0.0f, 1.0f};
	vec::vec4 p4{2.0f, 3.0f, 4.0f, 5.0f},
		p4x{1.0f, 0.0f, 0.0f, 0.0f}, p4y{0.0f, 1.0f, 0.0f, 0.0f},
			p4z{0.0f, 0.0f, 1.0f, 0.0f}, p4w{0.0f, 0.0f, 0.0f, 1.0f};
	
	BOOST_TEST_REQUIRE( (vec::projection(p2,p2x).value() == p2x * 2.0f) );
	BOOST_TEST_REQUIRE( (vec::projection(p2,p2y).value() == p2y * 3.0f) );
	
	BOOST_TEST_REQUIRE( (vec::projection(p3,p3x).value() == p3x * 2.0f) );
	BOOST_TEST_REQUIRE( (vec::projection(p3,p3y).value() == p3y * 3.0f) );
	BOOST_TEST_REQUIRE( (vec::projection(p3,p3z).value() == p3z * 4.0f) );
	
	BOOST_TEST_REQUIRE( (vec::projection(p4,p4x).value() == p4x * 2.0f) );
	BOOST_TEST_REQUIRE( (vec::projection(p4,p4y).value() == p4y * 3.0f) );
	BOOST_TEST_REQUIRE( (vec::projection(p4,p4z).value() == p4z * 4.0f) );
	BOOST_TEST_REQUIRE( (vec::projection(p4,p4w).value() == p4w * 5.0f) );
}

BOOST_AUTO_TEST_CASE( vec_rejection ) {
	vec::vec2 p2{2.0f, 3.0f},
		p2x{1.0f, 0.0f}, p2y{0.0f, 1.0f};
	
	BOOST_TEST_REQUIRE( (vec::rejection(p2,p2x).value() == p2y * 3.0f) );
	BOOST_TEST_REQUIRE( (vec::rejection(p2,p2y).value() == p2x * 2.0f) );
}

BOOST_AUTO_TEST_CASE( vec_swizzle ) {
	vec::vec2 v2{1.0f, 2.0f};
	vec::vec3 v3{1.0f, 2.0f, 3.0f};
	vec::vec4 v4{1.0f, 2.0f, 3.0f, 4.0f};
	
	vec::vec2 V2{0.0f, 0.0f};
	vec::vec3 V3{0.0f, 0.0f, 0.0f};
	vec::vec4 V4{0.0f, 0.0f, 0.0f, 0.0f};
	
	V2.swizzle2_in<vec::_y, vec::_x>() = v2.swizzle2_out<vec::_x, vec::_x>();
	BOOST_TEST_REQUIRE( (V2.x == 1.0f) );
	BOOST_TEST_REQUIRE( (V2.y == 1.0f) );
	
	V2.swizzle2_in<vec::_x, vec::_y>() = v3.swizzle2_out<vec::_z, vec::_y>();
	BOOST_TEST_REQUIRE( (V2.x == 3.0f) );
	BOOST_TEST_REQUIRE( (V2.y == 2.0f) );
	
	V3.swizzle3_in<vec::_x, vec::_y, vec::_z>() = v3.swizzle3_out<vec::_z, vec::_y, vec::_x>();
	BOOST_TEST_REQUIRE( (V3.x == 3.0f) );
	BOOST_TEST_REQUIRE( (V3.y == 2.0f) );
	BOOST_TEST_REQUIRE( (V3.z == 1.0f) );
	
	V4.swizzle4_in<vec::_x, vec::_y, vec::_z, vec::_w>() = v4.swizzle4_out<vec::_w, vec::_z, vec::_y, vec::_x>();
	BOOST_TEST_REQUIRE( (V4.x == 4.0f) );
	BOOST_TEST_REQUIRE( (V4.y == 3.0f) );
	BOOST_TEST_REQUIRE( (V4.z == 2.0f) );
	BOOST_TEST_REQUIRE( (V4.w == 1.0f) );
}


BOOST_AUTO_TEST_CASE( mat_add ) {
	mat::mat2 a2 = mat::mat2::filled(1.0f), b2 = mat::mat2::filled(2.0f);
	mat::mat3 a3 = mat::mat3::filled(1.0f), b3 = mat::mat3::filled(2.0f);
	mat::mat4 a4 = mat::mat4::filled(1.0f), b4 = mat::mat4::filled(2.0f);
	
	auto r2 = a2 + b2;
	for(unsigned char i=0; i<mat::mat2::DATA_SIZE; ++i) {
		BOOST_TEST_REQUIRE( r2.data[i] == 3.0f );
	}
	r2 += a2;
	for(unsigned char i=0; i<mat::mat2::DATA_SIZE; ++i) {
		BOOST_TEST_REQUIRE( r2.data[i] == 4.0f );
	}
	
	auto r3 = a3 + b3;
	for(unsigned char i=0; i<mat::mat3::DATA_SIZE; ++i) {
		BOOST_TEST_REQUIRE( r3.data[i] == 3.0f );
	}
	r3 += a3;
	for(unsigned char i=0; i<mat::mat3::DATA_SIZE; ++i) {
		BOOST_TEST_REQUIRE( r3.data[i] == 4.0f );
	}
	
	auto r4 = a4 + b4;
	for(unsigned char i=0; i<mat::mat4::DATA_SIZE; ++i) {
		BOOST_TEST_REQUIRE( r4.data[i] == 3.0f );
	}
	r4 += a4;
	for(unsigned char i=0; i<mat::mat4::DATA_SIZE; ++i) {
		BOOST_TEST_REQUIRE( r4.data[i] == 4.0f );
	}
}

BOOST_AUTO_TEST_CASE( mat_sub ) {
	mat::mat2 a2 = mat::mat2::filled(3.0f), b2 = mat::mat2::filled(1.0f);
	mat::mat3 a3 = mat::mat3::filled(3.0f), b3 = mat::mat3::filled(1.0f);
	mat::mat4 a4 = mat::mat4::filled(3.0f), b4 = mat::mat4::filled(1.0f);
	
	auto r2 = a2 - b2;
	for(unsigned char i=0; i<mat::mat2::DATA_SIZE; ++i) {
		BOOST_TEST_REQUIRE( r2.data[i] == 2.0f );
	}
	r2 -= b2;
	for(unsigned char i=0; i<mat::mat2::DATA_SIZE; ++i) {
		BOOST_TEST_REQUIRE( r2.data[i] == 1.0f );
	}
	
	auto r3 = a3 - b3;
	for(unsigned char i=0; i<mat::mat3::DATA_SIZE; ++i) {
		BOOST_TEST_REQUIRE( r3.data[i] == 2.0f );
	}
	r3 -= b3;
	for(unsigned char i=0; i<mat::mat3::DATA_SIZE; ++i) {
		BOOST_TEST_REQUIRE( r3.data[i] == 1.0f );
	}
	
	auto r4 = a4 - b4;
	for(unsigned char i=0; i<mat::mat4::DATA_SIZE; ++i) {
		BOOST_TEST_REQUIRE( r4.data[i] == 2.0f );
	}
	r4 -= b4;
	for(unsigned char i=0; i<mat::mat4::DATA_SIZE; ++i) {
		BOOST_TEST_REQUIRE( r4.data[i] == 1.0f );
	}
}

BOOST_AUTO_TEST_CASE( mat_mul_scalar ) {
	mat::mat2 m2 = mat::mat2::filled(1.0f);
	mat::mat3 m3 = mat::mat3::filled(1.0f);
	mat::mat4 m4 = mat::mat4::filled(1.0f);
	
	auto r2 = m2 * 2.0f;
	for(unsigned char i=0; i<mat::mat2::DATA_SIZE; ++i) {
		BOOST_TEST_REQUIRE( r2.data[i] == 2.0f );
	}
	m2 *= 3.0f;
	for(unsigned char i=0; i<mat::mat2::DATA_SIZE; ++i) {
		BOOST_TEST_REQUIRE( m2.data[i] == 3.0f );
	}
	
	auto r3 = m3 * 2.0f;
	for(unsigned char i=0; i<mat::mat3::DATA_SIZE; ++i) {
		BOOST_TEST_REQUIRE( r3.data[i] == 2.0f );
	}
	m3 *= 3.0f;
	for(unsigned char i=0; i<mat::mat3::DATA_SIZE; ++i) {
		BOOST_TEST_REQUIRE( m3.data[i] == 3.0f );
	}
	
	auto r4 = m4 * 2.0f;
	for(unsigned char i=0; i<mat::mat4::DATA_SIZE; ++i) {
		BOOST_TEST_REQUIRE( r4.data[i] == 2.0f );
	}
	m4 *= 3.0f;
	for(unsigned char i=0; i<mat::mat4::DATA_SIZE; ++i) {
		BOOST_TEST_REQUIRE( m4.data[i] == 3.0f );
	}
}

BOOST_AUTO_TEST_CASE( mat_row_column_access ) {
	mat::mat2 o2 = mat::mat2::one();
	mat::mat3 o3 = mat::mat3::one();
	mat::mat4 o4 = mat::mat4::one();
	
	BOOST_TEST_REQUIRE( (o2.column(1) == vec::vec2(1.0f, 0.0f)) );
	BOOST_TEST_REQUIRE( (o2.column(2) == vec::vec2(0.0f, 1.0f)) );
	BOOST_TEST_REQUIRE( (o2.row(1) == vec::vec2(1.0f, 0.0f)) );
	BOOST_TEST_REQUIRE( (o2.row(2) == vec::vec2(0.0f, 1.0f)) );
	
	BOOST_REQUIRE_THROW( [[maybe_unused]] auto c = o2.column(3), std::out_of_range );
	BOOST_REQUIRE_THROW( [[maybe_unused]] auto r = o2.row(3), std::out_of_range );
	
	BOOST_TEST_REQUIRE( o2.at(1,1) == 1.0f ); BOOST_TEST_REQUIRE( o2.at(1,2) == 0.0f );
	BOOST_TEST_REQUIRE( o2.at(2,1) == 0.0f ); BOOST_TEST_REQUIRE( o2.at(2,2) == 1.0f );
	
	BOOST_TEST_REQUIRE( (o3.column(1) == vec::vec3(1.0f, 0.0f, 0.0f)) );
	BOOST_TEST_REQUIRE( (o3.column(2) == vec::vec3(0.0f, 1.0f, 0.0f)) );
	BOOST_TEST_REQUIRE( (o3.column(3) == vec::vec3(0.0f, 0.0f, 1.0f)) );
	BOOST_TEST_REQUIRE( (o3.row(1) == vec::vec3(1.0f, 0.0f, 0.0f)) );
	BOOST_TEST_REQUIRE( (o3.row(2) == vec::vec3(0.0f, 1.0f, 0.0f)) );
	BOOST_TEST_REQUIRE( (o3.row(3) == vec::vec3(0.0f, 0.0f, 1.0f)) );
	
	BOOST_REQUIRE_THROW( [[maybe_unused]] auto c = o3.column(4), std::out_of_range );
	BOOST_REQUIRE_THROW( [[maybe_unused]] auto r = o3.row(4), std::out_of_range );
	
	BOOST_TEST_REQUIRE( o3.at(1,1) == 1.0f );
		BOOST_TEST_REQUIRE( o3.at(1,2) == 0.0f );
			BOOST_TEST_REQUIRE( o3.at(1,3) == 0.0f );
	BOOST_TEST_REQUIRE( o3.at(2,1) == 0.0f );
		BOOST_TEST_REQUIRE( o3.at(2,2) == 1.0f );
			BOOST_TEST_REQUIRE( o3.at(2,3) == 0.0f );
	BOOST_TEST_REQUIRE( o3.at(3,1) == 0.0f );
		BOOST_TEST_REQUIRE( o3.at(3,2) == 0.0f );
			BOOST_TEST_REQUIRE( o3.at(3,3) == 1.0f );
	
	BOOST_TEST_REQUIRE( (o4.column(1) == vec::vec4(1.0f, 0.0f, 0.0f, 0.0f)) );
	BOOST_TEST_REQUIRE( (o4.column(2) == vec::vec4(0.0f, 1.0f, 0.0f, 0.0f)) );
	BOOST_TEST_REQUIRE( (o4.column(3) == vec::vec4(0.0f, 0.0f, 1.0f, 0.0f)) );
	BOOST_TEST_REQUIRE( (o4.column(4) == vec::vec4(0.0f, 0.0f, 0.0f, 1.0f)) );
	BOOST_TEST_REQUIRE( (o4.row(1) == vec::vec4(1.0f, 0.0f, 0.0f, 0.0f)) );
	BOOST_TEST_REQUIRE( (o4.row(2) == vec::vec4(0.0f, 1.0f, 0.0f, 0.0f)) );
	BOOST_TEST_REQUIRE( (o4.row(3) == vec::vec4(0.0f, 0.0f, 1.0f, 0.0f)) );
	BOOST_TEST_REQUIRE( (o4.row(4) == vec::vec4(0.0f, 0.0f, 0.0f, 1.0f)) );
	
	BOOST_REQUIRE_THROW( [[maybe_unused]] auto c = o4.column(5), std::out_of_range );
	BOOST_REQUIRE_THROW( [[maybe_unused]] auto r = o4.row(5), std::out_of_range );
	
	BOOST_TEST_REQUIRE( o4.at(1,1) == 1.0f );
		BOOST_TEST_REQUIRE( o4.at(1,2) == 0.0f );
			BOOST_TEST_REQUIRE( o4.at(1,3) == 0.0f );
				BOOST_TEST_REQUIRE( o4.at(1,4) == 0.0f );
	BOOST_TEST_REQUIRE( o4.at(2,1) == 0.0f );
		BOOST_TEST_REQUIRE( o4.at(2,2) == 1.0f );
			BOOST_TEST_REQUIRE( o4.at(2,3) == 0.0f );
				BOOST_TEST_REQUIRE( o4.at(2,4) == 0.0f );
	BOOST_TEST_REQUIRE( o4.at(3,1) == 0.0f );
		BOOST_TEST_REQUIRE( o4.at(3,2) == 0.0f );
			BOOST_TEST_REQUIRE( o4.at(3,3) == 1.0f );
				BOOST_TEST_REQUIRE( o4.at(3,4) == 0.0f );
	BOOST_TEST_REQUIRE( o4.at(4,1) == 0.0f );
		BOOST_TEST_REQUIRE( o4.at(4,2) == 0.0f );
			BOOST_TEST_REQUIRE( o4.at(4,3) == 0.0f );
				BOOST_TEST_REQUIRE( o4.at(4,4) == 1.0f );
}

BOOST_AUTO_TEST_CASE( mat_transpose ) {
	mat::mat2 m2{1.0f, 2.0f,/**/ 3.0f, 4.0f};
	mat::mat3 m3{1.0f, 2.0f, 3.0f,/**/ 4.0f, 5.0f, 6.0f, /**/ 7.0f, 8.0f, 9.0f};
	mat::mat4 m4{1.0f, 2.0f, 3.0f, 4.0f,
							 5.0f, 6.0f, 7.0f, 8.0f,
							 9.0f, 10.0f, 11.0f, 12.0f,
							 13.0f, 14.0f, 15.0f, 16.0f};
	
	auto r2 = m2.transpose();
	BOOST_TEST_REQUIRE( (r2.row(1) == vec::vec2(1.0f, 3.0f)) );
	BOOST_TEST_REQUIRE( (r2.row(2) == vec::vec2(2.0f, 4.0f)) );
	m2.transposed();
	BOOST_TEST_REQUIRE( (m2.row(1) == vec::vec2(1.0f, 3.0f)) );
	BOOST_TEST_REQUIRE( (m2.row(2) == vec::vec2(2.0f, 4.0f)) );
	
	auto r3 = m3.transpose();
	BOOST_TEST_REQUIRE( (r3.row(1) == vec::vec3(1.0f, 4.0f, 7.0f)) );
	BOOST_TEST_REQUIRE( (r3.row(2) == vec::vec3(2.0f, 5.0f, 8.0f)) );
	BOOST_TEST_REQUIRE( (r3.row(3) == vec::vec3(3.0f, 6.0f, 9.0f)) );
	m3.transposed();
	BOOST_TEST_REQUIRE( (m3.row(1) == vec::vec3(1.0f, 4.0f, 7.0f)) );
	BOOST_TEST_REQUIRE( (m3.row(2) == vec::vec3(2.0f, 5.0f, 8.0f)) );
	BOOST_TEST_REQUIRE( (m3.row(3) == vec::vec3(3.0f, 6.0f, 9.0f)) );
	
	auto r4 = m4.transpose();
	BOOST_TEST_REQUIRE( (r4.row(1) == vec::vec4(1.0f, 5.0f, 9.0f, 13.0f)) );
	BOOST_TEST_REQUIRE( (r4.row(2) == vec::vec4(2.0f, 6.0f, 10.0f, 14.0f)) );
	BOOST_TEST_REQUIRE( (r4.row(3) == vec::vec4(3.0f, 7.0f, 11.0f, 15.0f)) );
	BOOST_TEST_REQUIRE( (r4.row(4) == vec::vec4(4.0f, 8.0f, 12.0f, 16.0f)) );
	m4.transposed();
	BOOST_TEST_REQUIRE( (m4.row(1) == vec::vec4(1.0f, 5.0f, 9.0f, 13.0f)) );
	BOOST_TEST_REQUIRE( (m4.row(2) == vec::vec4(2.0f, 6.0f, 10.0f, 14.0f)) );
	BOOST_TEST_REQUIRE( (m4.row(3) == vec::vec4(3.0f, 7.0f, 11.0f, 15.0f)) );
	BOOST_TEST_REQUIRE( (m4.row(4) == vec::vec4(4.0f, 8.0f, 12.0f, 16.0f)) );
}

BOOST_AUTO_TEST_CASE( mat_mul_mm ) {
	mat::mat2 m2 = mat::mat2::one();
	mat::mat3 m3 = mat::mat3::one();
	mat::mat4 m4 = mat::mat4::one();
	
	BOOST_TEST_REQUIRE( (m2 * m2 == m2) );
	BOOST_TEST_REQUIRE( (m3 * m3 == m3) );
	BOOST_TEST_REQUIRE( (m4 * m4 == m4) );
}

BOOST_AUTO_TEST_CASE( mat_mul_by_vec ) {
	mat::mat2 m2 = mat::mat2::one(); vec::vec2 v2{2.0f, 3.0f};
	mat::mat3 m3 = mat::mat3::one(); vec::vec3 v3{2.0f, 3.0f, 4.0f};
	mat::mat4 m4 = mat::mat4::one(); vec::vec4 v4{2.0f, 3.0f, 4.0f, 5.0f};
	
	BOOST_TEST_REQUIRE( (m2 * v2 == v2) );
	BOOST_TEST_REQUIRE( (m3 * v3 == v3) );
	BOOST_TEST_REQUIRE( (m4 * v4 == v4) );
}

BOOST_AUTO_TEST_CASE( mat_det ) {
	mat::mat2 m2 = mat::mat2::one();
	mat::mat3 m3 = mat::mat3::one();
	mat::mat4 m4 = mat::mat4::one();
	
	BOOST_TEST_REQUIRE( m2.det() == 1.0f );
	BOOST_TEST_REQUIRE( m3.det() == 1.0f );
	BOOST_TEST_REQUIRE( m4.det() == 1.0f );
}

BOOST_AUTO_TEST_CASE( mat_inv ) {
	mat::mat2 m2 = mat::mat2::one();
	mat::mat3 m3 = mat::mat3::one();
	mat::mat4 m4 = mat::mat4::one();
	
	auto m2i = m2.inv();
	BOOST_TEST_REQUIRE( m2i.has_value() );
	BOOST_TEST_REQUIRE( (m2i.value() == m2) );
	
	auto m3i = m3.inv();
	BOOST_TEST_REQUIRE( m3i.has_value() );
	BOOST_TEST_REQUIRE( (m3i.value() == m3) );
	
	auto m4i = m4.inv();
	BOOST_TEST_REQUIRE( m4i.has_value() );
	BOOST_TEST_REQUIRE( (m4i.value() == m4) );
}


BOOST_AUTO_TEST_CASE( quaternion_inv ) {
	quat::Quaternion q{4.0f};
	quat::Quaternion qi{1.0f/4.0f};
	quat::Quaternion one{1.0f};
	
	auto i = q.inv();
	BOOST_TEST_REQUIRE( i.has_value() );
	BOOST_TEST_REQUIRE( (i.value() == qi) );
	BOOST_TEST_REQUIRE( (i.value() * q == one) );
}

BOOST_AUTO_TEST_CASE( quaternion_div ) {
	quat::Quaternion q{4.0f};
	quat::Quaternion one{1.0f};
	
	BOOST_TEST_REQUIRE( (q / q == one) );
}

float round_error(float v) {
	if( v == -0.0f ) return 0.0f;
	if( v > 0.0f && v < 1.0e-5f ) return 0.0f;
	if( v < 0.0f && v > -1.0e-5f ) return 0.0f;
	if( v > 0.0f && std::fabs(1.0f - v) < 1.0e-5f ) return 1.0f;
	if( v < 0.0f && std::fabs(-1.0f - v) < 1.0e-5f ) return -1.0f;
	return v;
}

vec::vec3 round_errors(const vec::vec3& v) {
	return vec::vec3(round_error(v.x), round_error(v.y), round_error(v.z));
}

BOOST_AUTO_TEST_CASE( quaternion_rotation ) {
	vec::vec3 X{1.0f, 0.0f, 0.0f}, Y{0.0f, 1.0f, 0.0f}, Z{0.0f, 0.0f, 1.0f};
	auto rq = quat::rotation_as_quat(Z, PI_2);
	auto must_be_Y = round_errors(quat::rotate(rq, X));
	
	BOOST_TEST_REQUIRE( (must_be_Y == Y) );
}


