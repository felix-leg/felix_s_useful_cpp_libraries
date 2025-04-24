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
#define BOOST_TEST_MODULE binary_test
#include <boost/test/unit_test.hpp>

#include "../src/binary.hpp"
#include <stdexcept>
#include <sstream>

BOOST_AUTO_TEST_CASE( basic_construction ) {
	binary empty_value{};
	auto txt = "test";
	binary txt_value{reinterpret_cast<const unsigned char*>(txt), 5};
	binary zero_value = binary::zeroes(3);

	BOOST_TEST_REQUIRE( empty_value.is_empty() );
	BOOST_TEST_REQUIRE( ! txt_value.is_empty() );
	BOOST_TEST_REQUIRE( txt_value.length() == 5 );

	BOOST_TEST_REQUIRE( txt_value.data() != nullptr );
	BOOST_TEST_REQUIRE( txt_value.data()[0] == 't' );
	BOOST_TEST_REQUIRE( txt_value.data()[1] == 'e' );
	BOOST_TEST_REQUIRE( txt_value.data()[2] == 's' );
	BOOST_TEST_REQUIRE( txt_value.data()[3] == 't' );
	BOOST_TEST_REQUIRE( txt_value.data()[4] == '\0' );

	BOOST_TEST_REQUIRE( ! zero_value.is_empty() );
	BOOST_TEST_REQUIRE( zero_value.length() == 3 );
	BOOST_TEST_REQUIRE( zero_value.data() != nullptr );
	BOOST_TEST_REQUIRE( zero_value.data()[0] == '\0' );
	BOOST_TEST_REQUIRE( zero_value.data()[1] == '\0' );
	BOOST_TEST_REQUIRE( zero_value.data()[2] == '\0' );
}

BOOST_AUTO_TEST_CASE( data_move ) {
	auto txt = "test";
	auto txt_copy = new unsigned char[5];
	for(int i=0; i<5; ++i) txt_copy[i] = txt[i];
	binary txt_value = binary::move_into(txt_copy, 5);

	BOOST_TEST_REQUIRE( txt_value.data() != nullptr );
	BOOST_TEST_REQUIRE( txt_value.data()[0] == 't' );
	BOOST_TEST_REQUIRE( txt_value.data()[1] == 'e' );
	BOOST_TEST_REQUIRE( txt_value.data()[2] == 's' );
	BOOST_TEST_REQUIRE( txt_value.data()[3] == 't' );
	BOOST_TEST_REQUIRE( txt_value.data()[4] == '\0' );
}

BOOST_AUTO_TEST_CASE( casting ) {
	binary int_bin = binary::zeroes(sizeof(int));

	BOOST_TEST_REQUIRE( *(int_bin.as_ptr<int>()) == 0 );
	BOOST_TEST_REQUIRE( int_bin.as<int>() == 0 );

	*(int_bin.as_ptr<int>()) = 4;
	BOOST_TEST_REQUIRE( *(int_bin.as_ptr<int>()) == 4 );
	BOOST_TEST_REQUIRE( int_bin.as<int>() == 4 );

	int_bin.as<int>() = 10;
	BOOST_TEST_REQUIRE( *(int_bin.as_ptr<int>()) == 10 );
	BOOST_TEST_REQUIRE( int_bin.as<int>() == 10 );
}

BOOST_AUTO_TEST_CASE( accessing_bytes ) {
	binary value = binary::zeroes(2);

	BOOST_TEST_REQUIRE( value.at(0) == '\0' );
	BOOST_TEST_REQUIRE( value.at(1) == '\0' );
	try {
		value.at(2);
		BOOST_ERROR("binary::at() hasn't detected index out of bounds access");
	} catch( const std::out_of_range& err ) { /* OK */ }

	value.at(0) = 127;
	BOOST_TEST_REQUIRE( value.at(0) == 127 );

	BOOST_TEST_REQUIRE( value.get(0, 10) == 127 );
	BOOST_TEST_REQUIRE( value.get(2, 10) == 10 );

	BOOST_TEST_REQUIRE( value.set(1, 200) );
	BOOST_TEST_REQUIRE( value.get(1, 0) == 200 );
	BOOST_TEST_REQUIRE( ! value.set(2, 100) );
}

BOOST_AUTO_TEST_CASE( hex_string_output ) {
	binary value{0x01, 0x02, 0x0d, 0xef};
	
	BOOST_TEST_REQUIRE( value.at(0) == 0x01 );
	BOOST_TEST_REQUIRE( value.at(1) == 0x02 );
	BOOST_TEST_REQUIRE( value.at(2) == 0x0d );
	BOOST_TEST_REQUIRE( value.at(3) == 0xef );
	BOOST_TEST_REQUIRE( value.to_hex_string() == "01 02 0d ef" );
	BOOST_TEST_REQUIRE( value.to_hex_string(true) == "01 02 0D EF");
}

BOOST_AUTO_TEST_CASE( bin_string_output ) {
	binary value{0b00000111, 0b10100101};
	
	BOOST_TEST_REQUIRE( value.to_bin_string() == "00000111 10100101" );
}

BOOST_AUTO_TEST_CASE( joining_binaries ) {
	binary val1{0x01, 0x02};
	binary val2{0x0d, 0xef};
	auto value = val1 + val2;
	
	BOOST_TEST_REQUIRE( value.length() == 4 );
	BOOST_TEST_REQUIRE( value.at(0) == 0x01 );
	BOOST_TEST_REQUIRE( value.at(1) == 0x02 );
	BOOST_TEST_REQUIRE( value.at(2) == 0x0d );
	BOOST_TEST_REQUIRE( value.at(3) == 0xef );
}

BOOST_AUTO_TEST_CASE( double_binary ) {
	binary val{0x01, 0x02};
	auto value = val * 2;
	
	BOOST_TEST_REQUIRE( value.length() == 4 );
	BOOST_TEST_REQUIRE( value.at(0) == 0x01 );
	BOOST_TEST_REQUIRE( value.at(1) == 0x02 );
	BOOST_TEST_REQUIRE( value.at(2) == 0x01 );
	BOOST_TEST_REQUIRE( value.at(3) == 0x02 );
}

BOOST_AUTO_TEST_CASE( triple_binary ) {
	binary val{0x01, 0x02};
	auto value = 3 * val;
	
	BOOST_TEST_REQUIRE( value.length() == 6 );
	BOOST_TEST_REQUIRE( value.at(0) == 0x01 );
	BOOST_TEST_REQUIRE( value.at(1) == 0x02 );
	BOOST_TEST_REQUIRE( value.at(2) == 0x01 );
	BOOST_TEST_REQUIRE( value.at(3) == 0x02 );
	BOOST_TEST_REQUIRE( value.at(4) == 0x01 );
	BOOST_TEST_REQUIRE( value.at(5) == 0x02 );
}

BOOST_AUTO_TEST_CASE( joining_binaries_inplace ) {
	binary value{0x01, 0x02};
	binary val_add{0x0d, 0xef};
	value += val_add;
	
	BOOST_TEST_REQUIRE( value.length() == 4 );
	BOOST_TEST_REQUIRE( value.at(0) == 0x01 );
	BOOST_TEST_REQUIRE( value.at(1) == 0x02 );
	BOOST_TEST_REQUIRE( value.at(2) == 0x0d );
	BOOST_TEST_REQUIRE( value.at(3) == 0xef );
}

BOOST_AUTO_TEST_CASE( triple_binary_inplace ) {
	binary value{0x01, 0x02};
	value *= 3;
	
	BOOST_TEST_REQUIRE( value.length() == 6 );
	BOOST_TEST_REQUIRE( value.at(0) == 0x01 );
	BOOST_TEST_REQUIRE( value.at(1) == 0x02 );
	BOOST_TEST_REQUIRE( value.at(2) == 0x01 );
	BOOST_TEST_REQUIRE( value.at(3) == 0x02 );
	BOOST_TEST_REQUIRE( value.at(4) == 0x01 );
	BOOST_TEST_REQUIRE( value.at(5) == 0x02 );
}

BOOST_AUTO_TEST_CASE( binary_span ) {
	binary value{0, 1, 2, 3};
	
	auto s = value.as_span();
	BOOST_TEST_REQUIRE( s.size() == 4 );
	BOOST_TEST_REQUIRE( s[0] == 0 );
	BOOST_TEST_REQUIRE( s[1] == 1 );
	BOOST_TEST_REQUIRE( s[2] == 2 );
	BOOST_TEST_REQUIRE( s[3] == 3 );
	
	s[0] = 4;
	BOOST_TEST_REQUIRE( s[0] == 4 );
	BOOST_TEST_REQUIRE( value.at(0) == 4 );
}

BOOST_AUTO_TEST_CASE( binary_iterators ) {
	std::ostringstream os;
	binary value{0, 1, 2, 3};
	
	for(auto ch : value) {
		os << (int)ch << ' ';
	}
	BOOST_TEST_REQUIRE( (os.str() == "0 1 2 3 ") );
}
