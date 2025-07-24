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
#define BOOST_TEST_MODULE geometry_other_test
#include <boost/test/unit_test.hpp>

#include <cmath>

#include "../src/elements.hpp"

using namespace geometry::elements;

BOOST_AUTO_TEST_CASE( distance_2d_point ) {
	line2d lin{{0.0f, 0.0f}, {1.0f, 0.0f}};
	vec::vec2 point{1.0f, 1.0f};
	
	auto dist = lin.distance_to(point);
	BOOST_TEST_REQUIRE( dist == 1.0f );
}

BOOST_AUTO_TEST_CASE( distance_3d_point ) {
	line3d lin{{0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 0.0f}};
	vec::vec3 point{1.0f, 1.0f, 1.0f};
	
	auto dist = lin.distance_to(point);
	BOOST_TEST_REQUIRE( dist == 1.0f );
}

BOOST_AUTO_TEST_CASE( distance_2d_line ) {
	line2d lA{{0.0f, 0.0f}, {1.0f, 0.0f}};
	line2d lB{{0.0f, 1.0f}, {1.0f, 0.0f}};
	line2d lC{{0.0f, 1.0f}, {1.0f, -1.0f}};
	
	auto dist = lA.distance_to(lB);
	BOOST_TEST_REQUIRE( dist == 1.0f );
	dist = lA.distance_to(lC);
	BOOST_TEST_REQUIRE( dist == 0.0f );
}

BOOST_AUTO_TEST_CASE( distance_3d_line ) {
	line3d lA{{0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 1.0f}};
	line3d lB{{0.0f, 1.0f, 1.0f}, {1.0f, 0.0f, -1.0f}};
	
	auto dist = lA.distance_to(lB);
	BOOST_TEST_REQUIRE( dist == 1.0f );
}


