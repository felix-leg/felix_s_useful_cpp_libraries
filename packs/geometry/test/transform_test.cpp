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
#define BOOST_TEST_MODULE geometry_transform_test
#include <boost/test/unit_test.hpp>

#include <numbers>
//#include <ios>
#include <cmath>

#include "../src/transform.hpp"

constexpr float PI_2 = std::numbers::pi_v<float> / 2.0f;

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
mat::mat3 round_errors(mat::mat3 m) {
	for(int i=0; i<mat::mat3::DATA_SIZE; ++i) {
		m.data[i] = round_error(m.data[i]);
	}
	return m;
}

BOOST_AUTO_TEST_CASE( basic_rotations ) {
	vec::vec3 X{1.0f, 0.0f, 0.0f};
	vec::vec3 Y{0.0f, 1.0f, 0.0f};
	vec::vec3 Z{0.0f, 0.0f, 1.0f};
	
	auto r3x = transform::rotation_m3_x(PI_2);
	auto r3y = transform::rotation_m3_y(PI_2);
	auto r3z = transform::rotation_m3_z(PI_2);
	
	auto should_be_y = round_errors(r3x * -Z);
	auto should_be_x = round_errors(r3y * Z);
	auto should_be_y2 = round_errors(r3z * X);
	
	BOOST_TEST_REQUIRE( (should_be_y == Y) );
	BOOST_TEST_REQUIRE( (should_be_x == X) );
	BOOST_TEST_REQUIRE( (should_be_y2 == Y) );
}

BOOST_AUTO_TEST_CASE( axis_rotation ) {
	vec::vec3 X{1.0f, 0.0f, 0.0f};
	vec::vec3 Y{0.0f, 1.0f, 0.0f};
	vec::vec3 Z{0.0f, 0.0f, 1.0f};
	
	auto r3x = round_errors(transform::rotation_m3_x(PI_2));
	auto r3y = round_errors(transform::rotation_m3_y(PI_2));
	auto r3z = round_errors(transform::rotation_m3_z(PI_2));
	
	auto tr_x = round_errors(transform::rotation_m3_a(X, PI_2));
	BOOST_TEST_REQUIRE( (tr_x == r3x) );
	auto tr_y = round_errors(transform::rotation_m3_a(Y, PI_2));
	BOOST_TEST_REQUIRE( (tr_y == r3y) );
	auto tr_z = round_errors(transform::rotation_m3_a(Z, PI_2));
	BOOST_TEST_REQUIRE( (tr_z == r3z) );
}

BOOST_AUTO_TEST_CASE( axis_mirror ) {
	vec::vec3 X{1.0f, 0.0f, 0.0f};
	vec::vec3 Y{0.0f, 1.0f, 0.0f};
	vec::vec3 Z{0.0f, 0.0f, 1.0f};
	auto tr = transform::mirror_m3(X);
	
	BOOST_TEST_REQUIRE( (tr * X == -X) );
	BOOST_TEST_REQUIRE( (tr * Y == Y) );
	BOOST_TEST_REQUIRE( (tr * Z == Z) );
}

BOOST_AUTO_TEST_CASE( axis_involution ) {
	vec::vec3 X{1.0f, 0.0f, 0.0f};
	vec::vec3 Y{0.0f, 1.0f, 0.0f};
	vec::vec3 Z{0.0f, 0.0f, 1.0f};
	auto tr = transform::involution_m3(X);
	
	BOOST_TEST_REQUIRE( (tr * X == X) );
	BOOST_TEST_REQUIRE( (tr * Y == -Y) );
	BOOST_TEST_REQUIRE( (tr * Z == -Z) );
}

BOOST_AUTO_TEST_CASE( scaling ) {
	auto tr = transform::scale_m3({1.0f, 0.0f, 0.0f}, 4.0f);
	auto tr_c = transform::scale_m3(4.0f, 1.0f, 1.0f);
	
	BOOST_TEST_REQUIRE( (tr == tr_c) );
}

BOOST_AUTO_TEST_CASE( normal_transform ) {
	vec::vec3 n{1.0f, 1.0f, 0.0f};
	n.normalize();
	mat::mat4 M = transform::scale_m4(2.0f, 1.0f, 1.0f);
	
	auto calculated = transform::normal_transform(n, M).value();
	auto correct = n; correct.x /= 2.0f;
	
	BOOST_TEST_REQUIRE( (calculated == correct) );
}


