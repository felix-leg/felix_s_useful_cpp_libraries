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
#define BOOST_TEST_MODULE math_utils_test
#include <boost/test/unit_test.hpp>

#include <cmath>

#include "../src/angle.hpp"
#include "../src/ranges_calc.hpp"
#include "../src/gcd_lcm.hpp"

BOOST_AUTO_TEST_CASE( angle_compare ) {
	auto a1 = math::degrees(180.0f);
	auto a2 = math::degrees(0.0f);
	
	BOOST_TEST_REQUIRE( (a1 > a2) );
	BOOST_TEST_REQUIRE( (a1 >= a2) );
	BOOST_TEST_REQUIRE( !(a1 < a2) );
	BOOST_TEST_REQUIRE( !(a1 <= a2) );
	BOOST_TEST_REQUIRE( !(a1 == a2) );
	BOOST_TEST_REQUIRE( (a1 != a2) );
}

BOOST_AUTO_TEST_CASE( clamping ) {
	float valA = math::clamp_value(0.5f, 0.0f, 1.0f);
	float valB = math::clamp_value(-1.0f, 0.0f, 1.0f);
	float valC = math::clamp_value(2.0f, 0.0f, 1.0f);
	float valD = math::clamp_value(2.0f, 1.0f, 0.0f);
	
	BOOST_TEST_REQUIRE( valA == 0.5f );
	BOOST_TEST_REQUIRE( valB == 0.0f );
	BOOST_TEST_REQUIRE( valC == 1.0f );
	BOOST_TEST_REQUIRE( valD == 1.0f );
}

BOOST_AUTO_TEST_CASE( range_test ) {
	BOOST_TEST_REQUIRE( math::is_in_range(1,0,2) );
	BOOST_TEST_REQUIRE( !math::is_in_range(5,0,2) );
	BOOST_TEST_REQUIRE( math::is_in_range(1,2,0) );
	BOOST_TEST_REQUIRE( !math::is_in_range(5,2,0) );
}

BOOST_AUTO_TEST_CASE( lerp_test ) {
	float a = 1.0f;
	float b = 1e8f;
	
	BOOST_TEST_REQUIRE( (a == math::lerp(a,b, 0.0f)) );
	BOOST_TEST_REQUIRE( (b == math::lerp(a,b, 1.0f)) );
	BOOST_TEST_REQUIRE( (b == math::lerp(b,a, 0.0f)) );
	BOOST_TEST_REQUIRE( (a == math::lerp(b,a, 1.0f)) );
	
	BOOST_TEST_REQUIRE( math::lerp(a,b,INFINITY) == INFINITY );
}

BOOST_AUTO_TEST_CASE( map_range_test ) {
	BOOST_TEST_REQUIRE( math::map_range(1,0,2,-1,1) == 0 );
	BOOST_TEST_REQUIRE( math::map_range(INFINITY, 0.0f, 2.0f, -1.0f, 1.0f) == INFINITY );
}

BOOST_AUTO_TEST_CASE( gcd_calc ) {
	const int c_val = 14; //correct value
	
	auto gcd_0 = math::gcd<int>({});
	BOOST_TEST_REQUIRE( gcd_0 == 0 );
	
	auto gcd_1 = math::gcd({c_val});
	BOOST_TEST_REQUIRE( gcd_1 == c_val );
	
	auto gcd_2 = math::gcd({2 * c_val, 3 * c_val});
	BOOST_TEST_REQUIRE( gcd_2 == c_val );
	
	auto gcd_3 = math::gcd({2 * c_val, 3 * c_val, 5 * c_val});
	BOOST_TEST_REQUIRE( gcd_3 == c_val );
	
	auto gcd_4 = math::gcd({2 * c_val, 3 * c_val, 5 * c_val, 7 * c_val});
	BOOST_TEST_REQUIRE( gcd_4 == c_val );
	
	auto gcd_5 = math::gcd({2 * c_val, 3 * c_val, 5 * c_val, 7 * c_val, 11 * c_val});
	BOOST_TEST_REQUIRE( gcd_5 == c_val );
	
	auto gcd_6 = math::gcd({2 * c_val, 3 * c_val, 5 * c_val, 7 * c_val, 11 * c_val, 13 * c_val});
	BOOST_TEST_REQUIRE( gcd_6 == c_val );
}
