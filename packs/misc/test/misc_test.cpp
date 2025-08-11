#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE misc_test
#include <boost/test/unit_test.hpp>

#include "../src/defer.hpp"

BOOST_AUTO_TEST_CASE( defering_code ) {
	int v = 0;
	BOOST_TEST_REQUIRE( v == 0 );
	{
		v = 1;
		defer( v = 2 );
		BOOST_TEST_REQUIRE( v == 1 );
	}
	BOOST_TEST_REQUIRE( v == 2 );
}

BOOST_AUTO_TEST_CASE( defering_with_exceptions ) {
	bool success = false;
	bool fail = false;
	try{
		defer_success( success = true );
		defer_fail( fail = true );
		throw 0;
	}
	catch(const int& e) {}
	BOOST_TEST_REQUIRE( success == false );
	BOOST_TEST_REQUIRE( fail == true );
}

