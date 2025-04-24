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
#define BOOST_TEST_MODULE text_utils_test
#include <boost/test/unit_test.hpp>

#include "../src/math_utils.hpp"

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


