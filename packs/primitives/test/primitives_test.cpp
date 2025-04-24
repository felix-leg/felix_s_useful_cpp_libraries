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
#define BOOST_TEST_MODULE primitives_test
#include <boost/test/unit_test.hpp>

#include "../src/primitives.hpp"


BOOST_AUTO_TEST_CASE( i_abs_value ) {
	BOOST_TEST_REQUIRE( SByte::abs(3) == SByte::abs(-3) );
	BOOST_TEST_REQUIRE( Short::abs(1000) == Short::abs(-1000) );
	BOOST_TEST_REQUIRE( Int::abs(60'000) == Int::abs(-60'000) );
	BOOST_TEST_REQUIRE( Long::abs(1234) == Long::abs(-1234) );
	BOOST_TEST_REQUIRE( LongLong::abs(1234) == LongLong::abs(-1234) );
}

BOOST_AUTO_TEST_CASE( wrapped_add ) {
	#define TT(un,si) \
	BOOST_TEST_REQUIRE( un::add_wrapped(un::max_value - 2, 3) == 0 ); \
	BOOST_TEST_REQUIRE( si::add_wrapped(si::max_value - 2, 3) == si::min_value ); \
	BOOST_TEST_REQUIRE( si::add_wrapped(si::min_value + 2, -3) == si::max_value );
	
	TT(UByte, SByte)
	TT(UShort, Short)
	TT(UInt, Int)
	TT(ULong, Long)
	TT(ULongLong, LongLong)
	
	#undef TT
}

BOOST_AUTO_TEST_CASE( wrapped_sub ) {
	#define TT(un,si) \
	BOOST_TEST_REQUIRE( un::sub_wrapped(2, 3) == un::max_value ); \
	BOOST_TEST_REQUIRE( si::sub_wrapped(si::min_value + 2, 3) == si::max_value ); \
	BOOST_TEST_REQUIRE( si::sub_wrapped(si::max_value - 2, -3) == si::min_value );
	
	TT(UByte, SByte)
	TT(UShort, Short)
	TT(UInt, Int)
	TT(ULong, Long)
	TT(ULongLong, LongLong)
	
	#undef TT
}

BOOST_AUTO_TEST_CASE( clamped_add ) {
	#define TT(un,si) \
	BOOST_TEST_REQUIRE( un::add_clamped(un::max_value - 2, 3) == un::max_value ); \
	BOOST_TEST_REQUIRE( si::add_clamped(si::max_value - 2, 3) == si::max_value ); \
	BOOST_TEST_REQUIRE( si::add_clamped(si::min_value + 2, -3) == si::min_value );
	
	TT(UByte, SByte)
	TT(UShort, Short)
	TT(UInt, Int)
	TT(ULong, Long)
	TT(ULongLong, LongLong)
	
	#undef TT
}

BOOST_AUTO_TEST_CASE( clamped_sub ) {
	#define TT(un,si) \
	BOOST_TEST_REQUIRE( un::sub_clamped(2, 3) == 0 ); \
	BOOST_TEST_REQUIRE( si::sub_clamped(si::min_value + 2, 3) == si::min_value ); \
	BOOST_TEST_REQUIRE( si::sub_clamped(si::max_value - 2, -3) == si::max_value );
	
	TT(UByte, SByte)
	TT(UShort, Short)
	TT(UInt, Int)
	TT(ULong, Long)
	TT(ULongLong, LongLong)
	
	#undef TT
}

BOOST_AUTO_TEST_CASE( i_to_binary_string ) {
	BOOST_TEST_REQUIRE( UByte::to_bin(7) == "111" );
	BOOST_TEST_REQUIRE( UByte::to_bin(7, true) == "00000111" );
	BOOST_TEST_REQUIRE( SByte::to_bin(7) == "111" );
	BOOST_TEST_REQUIRE( SByte::to_bin(7, true) == "00000111" );
	BOOST_TEST_REQUIRE( SByte::to_bin(-7) == "-111" );
	BOOST_TEST_REQUIRE( SByte::to_bin(-7, true) == "-00000111" );
	
	BOOST_TEST_REQUIRE( UShort::to_bin(7) == "111" );
	BOOST_TEST_REQUIRE( UShort::to_bin(7, true) == "0000000000000111" );
	BOOST_TEST_REQUIRE( Short::to_bin(7) == "111" );
	BOOST_TEST_REQUIRE( Short::to_bin(7, true) == "0000000000000111" );
	BOOST_TEST_REQUIRE( Short::to_bin(-7) == "-111" );
	BOOST_TEST_REQUIRE( Short::to_bin(-7, true) == "-0000000000000111" );
	
	BOOST_TEST_REQUIRE( UInt::to_bin(7) == "111" );
	BOOST_TEST_REQUIRE( UInt::to_bin(7, true) == "00000000000000000000000000000111" );
	BOOST_TEST_REQUIRE( Int::to_bin(7) == "111" );
	BOOST_TEST_REQUIRE( Int::to_bin(7, true) == "00000000000000000000000000000111" );
	BOOST_TEST_REQUIRE( Int::to_bin(-7) == "-111" );
	BOOST_TEST_REQUIRE( Int::to_bin(-7, true) == "-00000000000000000000000000000111" );
	
	BOOST_TEST_REQUIRE( ULong::to_bin(7) == "111" );
	BOOST_TEST_REQUIRE( ULong::to_bin(7, true) == "0000000000000000000000000000000000000000000000000000000000000111" );
	BOOST_TEST_REQUIRE( Long::to_bin(7) == "111" );
	BOOST_TEST_REQUIRE( Long::to_bin(7, true) == "0000000000000000000000000000000000000000000000000000000000000111" );
	BOOST_TEST_REQUIRE( Long::to_bin(-7) == "-111" );
	BOOST_TEST_REQUIRE( Long::to_bin(-7, true) == "-0000000000000000000000000000000000000000000000000000000000000111" );
	
	if constexpr( sizeof(long long) == 16 ) {
	BOOST_TEST_REQUIRE( ULongLong::to_bin(7) == "111" );
	BOOST_TEST_REQUIRE( ULongLong::to_bin(7, true) == "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111" );
	BOOST_TEST_REQUIRE( LongLong::to_bin(7) == "111" );
	BOOST_TEST_REQUIRE( LongLong::to_bin(7, true) == "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111" );
	BOOST_TEST_REQUIRE( LongLong::to_bin(-7) == "-111" );
	BOOST_TEST_REQUIRE( LongLong::to_bin(-7, true) == "-00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111" );
	}
	if constexpr( sizeof(long long) == 8 ) {
	BOOST_TEST_REQUIRE( ULongLong::to_bin(7) == "111" );
	BOOST_TEST_REQUIRE( ULongLong::to_bin(7, true) == "0000000000000000000000000000000000000000000000000000000000000111" );
	BOOST_TEST_REQUIRE( LongLong::to_bin(7) == "111" );
	BOOST_TEST_REQUIRE( LongLong::to_bin(7, true) == "0000000000000000000000000000000000000000000000000000000000000111" );
	BOOST_TEST_REQUIRE( LongLong::to_bin(-7) == "-111" );
	BOOST_TEST_REQUIRE( LongLong::to_bin(-7, true) == "-0000000000000000000000000000000000000000000000000000000000000111" );
	}
}

BOOST_AUTO_TEST_CASE( i_to_octal_string ) {
	BOOST_TEST_REQUIRE( UByte::to_oct(8) == "10" );
	BOOST_TEST_REQUIRE( SByte::to_oct(8) == "10" );
	BOOST_TEST_REQUIRE( SByte::to_oct(-8) == "-10" );
	
	BOOST_TEST_REQUIRE( UShort::to_oct(8) == "10" );
	BOOST_TEST_REQUIRE( Short::to_oct(8) == "10" );
	BOOST_TEST_REQUIRE( Short::to_oct(-8) == "-10" );
	
	BOOST_TEST_REQUIRE( UInt::to_oct(8) == "10" );
	BOOST_TEST_REQUIRE( Int::to_oct(8) == "10" );
	BOOST_TEST_REQUIRE( Int::to_oct(-8) == "-10" );
	
	BOOST_TEST_REQUIRE( ULong::to_oct(8) == "10" );
	BOOST_TEST_REQUIRE( Long::to_oct(8) == "10" );
	BOOST_TEST_REQUIRE( Long::to_oct(-8) == "-10" );
	
	BOOST_TEST_REQUIRE( ULongLong::to_oct(8) == "10" );
	BOOST_TEST_REQUIRE( LongLong::to_oct(8) == "10" );
	BOOST_TEST_REQUIRE( LongLong::to_oct(-8) == "-10" );
}

BOOST_AUTO_TEST_CASE( i_to_dec_string ) {
	BOOST_TEST_REQUIRE( UByte::to_dec(123) == "123" );
	BOOST_TEST_REQUIRE( SByte::to_dec(123) == "123" );
	BOOST_TEST_REQUIRE( SByte::to_dec(-123) == "-123" );
	
	BOOST_TEST_REQUIRE( UShort::to_dec(1'230) == "1230" );
	BOOST_TEST_REQUIRE( Short::to_dec(1'230) == "1230" );
	BOOST_TEST_REQUIRE( Short::to_dec(-1'230) == "-1230" );
	
	BOOST_TEST_REQUIRE( UInt::to_dec(123'000) == "123000" );
	BOOST_TEST_REQUIRE( Int::to_dec(123'000) == "123000" );
	BOOST_TEST_REQUIRE( Int::to_dec(-123'000) == "-123000" );
	
	BOOST_TEST_REQUIRE( ULong::to_dec(123'000'000) == "123000000" );
	BOOST_TEST_REQUIRE( Long::to_dec(123'000'000) == "123000000" );
	BOOST_TEST_REQUIRE( Long::to_dec(-123'000'000) == "-123000000" );
	
	BOOST_TEST_REQUIRE( ULongLong::to_dec(123'000'000'000) == "123000000000" );
	BOOST_TEST_REQUIRE( LongLong::to_dec(123'000'000'000) == "123000000000" );
	BOOST_TEST_REQUIRE( LongLong::to_dec(-123'000'000'000) == "-123000000000" );
}

BOOST_AUTO_TEST_CASE( i_to_hex_string ) {
	BOOST_TEST_REQUIRE( UByte::to_hex(0x5f) == "5f" );
	BOOST_TEST_REQUIRE( UByte::to_hex(0x0f, true) == "0f" );
	BOOST_TEST_REQUIRE( SByte::to_hex(0x2f) == "2f" );
	BOOST_TEST_REQUIRE( SByte::to_hex(0x0f, true) == "0f" );
	BOOST_TEST_REQUIRE( SByte::to_hex(-0x2f) == "-2f" );
	BOOST_TEST_REQUIRE( SByte::to_hex(-0x0f, true) == "-0f" );
	
	BOOST_TEST_REQUIRE( UShort::to_hex(0x5f) == "5f" );
	BOOST_TEST_REQUIRE( UShort::to_hex(0x5f, true) == "005f" );
	BOOST_TEST_REQUIRE( Short::to_hex(0x2f) == "2f" );
	BOOST_TEST_REQUIRE( Short::to_hex(0x2f, true) == "002f" );
	BOOST_TEST_REQUIRE( Short::to_hex(-0x2f) == "-2f" );
	BOOST_TEST_REQUIRE( Short::to_hex(-0x2f, true) == "-002f" );
	
	BOOST_TEST_REQUIRE( UInt::to_hex(0x5f) == "5f" );
	BOOST_TEST_REQUIRE( UInt::to_hex(0x5f, true) == "0000005f" );
	BOOST_TEST_REQUIRE( Int::to_hex(0x2f) == "2f" );
	BOOST_TEST_REQUIRE( Int::to_hex(0x2f, true) == "0000002f" );
	BOOST_TEST_REQUIRE( Int::to_hex(-0x2f) == "-2f" );
	BOOST_TEST_REQUIRE( Int::to_hex(-0x2f, true) == "-0000002f" );
	
	BOOST_TEST_REQUIRE( ULong::to_hex(0x5f) == "5f" );
	BOOST_TEST_REQUIRE( ULong::to_hex(0x5f, true) == "000000000000005f" );
	BOOST_TEST_REQUIRE( Long::to_hex(0x2f) == "2f" );
	BOOST_TEST_REQUIRE( Long::to_hex(0x2f, true) == "000000000000002f" );
	BOOST_TEST_REQUIRE( Long::to_hex(-0x2f) == "-2f" );
	BOOST_TEST_REQUIRE( Long::to_hex(-0x2f, true) == "-000000000000002f" );
	
	if constexpr( sizeof(long long) == 16 ) {
	BOOST_TEST_REQUIRE( ULongLong::to_hex(0x5f) == "5f" );
	BOOST_TEST_REQUIRE( ULongLong::to_hex(0x5f, true) == "0000000000000000000000000000005f" );
	BOOST_TEST_REQUIRE( LongLong::to_hex(0x2f) == "2f" );
	BOOST_TEST_REQUIRE( LongLong::to_hex(0x2f, true) == "0000000000000000000000000000002f" );
	BOOST_TEST_REQUIRE( LongLong::to_hex(-0x2f) == "-2f" );
	BOOST_TEST_REQUIRE( LongLong::to_hex(-0x2f, true) == "-0000000000000000000000000000002f" );
	}
	if constexpr( sizeof(long long) == 8 ) {
	BOOST_TEST_REQUIRE( ULongLong::to_hex(0x5f) == "5f" );
	BOOST_TEST_REQUIRE( ULongLong::to_hex(0x5f, true) == "000000000000005f" );
	BOOST_TEST_REQUIRE( LongLong::to_hex(0x2f) == "2f" );
	BOOST_TEST_REQUIRE( LongLong::to_hex(0x2f, true) == "000000000000002f" );
	BOOST_TEST_REQUIRE( LongLong::to_hex(-0x2f) == "-2f" );
	BOOST_TEST_REQUIRE( LongLong::to_hex(-0x2f, true) == "-000000000000002f" );
	}
}

BOOST_AUTO_TEST_CASE( i_from_bin_string ) {
	BOOST_TEST_REQUIRE( UByte::from_bin("111") == 7 );
	BOOST_TEST_REQUIRE( SByte::from_bin("111") == 7 );
	BOOST_TEST_REQUIRE( SByte::from_bin("-111") == -7 );
	
	BOOST_TEST_REQUIRE( UShort::from_bin("111") == 7 );
	BOOST_TEST_REQUIRE( Short::from_bin("111") == 7 );
	BOOST_TEST_REQUIRE( Short::from_bin("-111") == -7 );
	
	BOOST_TEST_REQUIRE( UInt::from_bin("111") == 7 );
	BOOST_TEST_REQUIRE( Int::from_bin("111") == 7 );
	BOOST_TEST_REQUIRE( Int::from_bin("-111") == -7 );
	
	BOOST_TEST_REQUIRE( ULong::from_bin("111") == 7 );
	BOOST_TEST_REQUIRE( Long::from_bin("111") == 7 );
	BOOST_TEST_REQUIRE( Long::from_bin("-111") == -7 );
	
	BOOST_TEST_REQUIRE( ULongLong::from_bin("111") == 7 );
	BOOST_TEST_REQUIRE( LongLong::from_bin("111") == 7 );
	BOOST_TEST_REQUIRE( LongLong::from_bin("-111") == -7 );
}

BOOST_AUTO_TEST_CASE( i_from_oct_string ) {
	BOOST_TEST_REQUIRE( UByte::from_oct("10") == 8 );
	BOOST_TEST_REQUIRE( SByte::from_oct("10") == 8 );
	BOOST_TEST_REQUIRE( SByte::from_oct("-10") == -8 );
	
	BOOST_TEST_REQUIRE( UShort::from_oct("10") == 8 );
	BOOST_TEST_REQUIRE( Short::from_oct("10") == 8 );
	BOOST_TEST_REQUIRE( Short::from_oct("-10") == -8 );
	
	BOOST_TEST_REQUIRE( UInt::from_oct("10") == 8 );
	BOOST_TEST_REQUIRE( Int::from_oct("10") == 8 );
	BOOST_TEST_REQUIRE( Int::from_oct("-10") == -8 );
	
	BOOST_TEST_REQUIRE( ULong::from_oct("10") == 8 );
	BOOST_TEST_REQUIRE( Long::from_oct("10") == 8 );
	BOOST_TEST_REQUIRE( Long::from_oct("-10") == -8 );
	
	BOOST_TEST_REQUIRE( ULongLong::from_oct("10") == 8 );
	BOOST_TEST_REQUIRE( LongLong::from_oct("10") == 8 );
	BOOST_TEST_REQUIRE( LongLong::from_oct("-10") == -8 );
}

BOOST_AUTO_TEST_CASE( i_from_dec_string ) {
	BOOST_TEST_REQUIRE( UByte::from_dec("10") == 10 );
	BOOST_TEST_REQUIRE( SByte::from_dec("10") == 10 );
	BOOST_TEST_REQUIRE( SByte::from_dec("-10") == -10 );
	
	BOOST_TEST_REQUIRE( UShort::from_dec("10") == 10 );
	BOOST_TEST_REQUIRE( Short::from_dec("10") == 10 );
	BOOST_TEST_REQUIRE( Short::from_dec("-10") == -10 );
	
	BOOST_TEST_REQUIRE( UInt::from_dec("10") == 10 );
	BOOST_TEST_REQUIRE( Int::from_dec("10") == 10 );
	BOOST_TEST_REQUIRE( Int::from_dec("-10") == -10 );
	
	BOOST_TEST_REQUIRE( ULong::from_dec("10") == 10 );
	BOOST_TEST_REQUIRE( Long::from_dec("10") == 10 );
	BOOST_TEST_REQUIRE( Long::from_dec("-10") == -10 );
	
	BOOST_TEST_REQUIRE( ULongLong::from_dec("10") == 10 );
	BOOST_TEST_REQUIRE( LongLong::from_dec("10") == 10 );
	BOOST_TEST_REQUIRE( LongLong::from_dec("-10") == -10 );
}

BOOST_AUTO_TEST_CASE( i_from_hex_string ) {
	BOOST_TEST_REQUIRE( UByte::from_hex("1a") == 0x1a );
	BOOST_TEST_REQUIRE( SByte::from_hex("1a") == 0x1a );
	BOOST_TEST_REQUIRE( SByte::from_hex("-1a") == -0x1a );
	
	BOOST_TEST_REQUIRE( UShort::from_hex("1a") == 0x1a );
	BOOST_TEST_REQUIRE( Short::from_hex("1a") == 0x1a );
	BOOST_TEST_REQUIRE( Short::from_hex("-1a") == -0x1a );
	
	BOOST_TEST_REQUIRE( UInt::from_hex("1a") == 0x1a );
	BOOST_TEST_REQUIRE( Int::from_hex("1a") == 0x1a );
	BOOST_TEST_REQUIRE( Int::from_hex("-1a") == -0x1a );
	
	BOOST_TEST_REQUIRE( ULong::from_hex("1a") == 0x1a );
	BOOST_TEST_REQUIRE( Long::from_hex("1a") == 0x1a );
	BOOST_TEST_REQUIRE( Long::from_hex("-1a") == -0x1a );
	
	BOOST_TEST_REQUIRE( ULongLong::from_hex("1a") == 0x1a );
	BOOST_TEST_REQUIRE( LongLong::from_hex("1a") == 0x1a );
	BOOST_TEST_REQUIRE( LongLong::from_hex("-1a") == -0x1a );
}

BOOST_AUTO_TEST_CASE( i_from_bin_string_with_default ) {
	BOOST_TEST_REQUIRE( UByte::from_bin("wrong", 7) == 7 );
	BOOST_TEST_REQUIRE( SByte::from_bin("wrong", 7) == 7 );
	BOOST_TEST_REQUIRE( SByte::from_bin("wrong", -7) == -7 );
	
	BOOST_TEST_REQUIRE( UShort::from_bin("wrong", 7) == 7 );
	BOOST_TEST_REQUIRE( Short::from_bin("wrong", 7) == 7 );
	BOOST_TEST_REQUIRE( Short::from_bin("wrong", -7) == -7 );
	
	BOOST_TEST_REQUIRE( UInt::from_bin("wrong", 7) == 7 );
	BOOST_TEST_REQUIRE( Int::from_bin("wrong", 7) == 7 );
	BOOST_TEST_REQUIRE( Int::from_bin("wrong", -7) == -7 );
	
	BOOST_TEST_REQUIRE( ULong::from_bin("wrong", 7) == 7 );
	BOOST_TEST_REQUIRE( Long::from_bin("wrong", 7) == 7 );
	BOOST_TEST_REQUIRE( Long::from_bin("wrong", -7) == -7 );
	
	BOOST_TEST_REQUIRE( ULongLong::from_bin("wrong", 7) == 7 );
	BOOST_TEST_REQUIRE( LongLong::from_bin("wrong", 7) == 7 );
	BOOST_TEST_REQUIRE( LongLong::from_bin("wrong", -7) == -7 );
}

BOOST_AUTO_TEST_CASE( i_from_oct_string_with_default ) {
	BOOST_TEST_REQUIRE( UByte::from_oct("wrong", 8) == 8 );
	BOOST_TEST_REQUIRE( SByte::from_oct("wrong", 8) == 8 );
	BOOST_TEST_REQUIRE( SByte::from_oct("wrong", -8) == -8 );
	
	BOOST_TEST_REQUIRE( UShort::from_oct("wrong", 8) == 8 );
	BOOST_TEST_REQUIRE( Short::from_oct("wrong", 8) == 8 );
	BOOST_TEST_REQUIRE( Short::from_oct("wrong", -8) == -8 );
	
	BOOST_TEST_REQUIRE( UInt::from_oct("wrong", 8) == 8 );
	BOOST_TEST_REQUIRE( Int::from_oct("wrong", 8) == 8 );
	BOOST_TEST_REQUIRE( Int::from_oct("wrong", -8) == -8 );
	
	BOOST_TEST_REQUIRE( ULong::from_oct("wrong", 8) == 8 );
	BOOST_TEST_REQUIRE( Long::from_oct("wrong", 8) == 8 );
	BOOST_TEST_REQUIRE( Long::from_oct("wrong", -8) == -8 );
	
	BOOST_TEST_REQUIRE( ULongLong::from_oct("wrong", 8) == 8 );
	BOOST_TEST_REQUIRE( LongLong::from_oct("wrong", 8) == 8 );
	BOOST_TEST_REQUIRE( LongLong::from_oct("wrong", -8) == -8 );
}

BOOST_AUTO_TEST_CASE( i_from_dec_string_with_default ) {
	BOOST_TEST_REQUIRE( UByte::from_dec("wrong", 10) == 10 );
	BOOST_TEST_REQUIRE( SByte::from_dec("wrong", 10) == 10 );
	BOOST_TEST_REQUIRE( SByte::from_dec("wrong", -10) == -10 );
	
	BOOST_TEST_REQUIRE( UShort::from_dec("wrong", 10) == 10 );
	BOOST_TEST_REQUIRE( Short::from_dec("wrong", 10) == 10 );
	BOOST_TEST_REQUIRE( Short::from_dec("wrong", -10) == -10 );
	
	BOOST_TEST_REQUIRE( UInt::from_dec("wrong", 10) == 10 );
	BOOST_TEST_REQUIRE( Int::from_dec("wrong", 10) == 10 );
	BOOST_TEST_REQUIRE( Int::from_dec("wrong", -10) == -10 );
	
	BOOST_TEST_REQUIRE( ULong::from_dec("wrong", 10) == 10 );
	BOOST_TEST_REQUIRE( Long::from_dec("wrong", 10) == 10 );
	BOOST_TEST_REQUIRE( Long::from_dec("wrong", -10) == -10 );
	
	BOOST_TEST_REQUIRE( ULongLong::from_dec("wrong", 10) == 10 );
	BOOST_TEST_REQUIRE( LongLong::from_dec("wrong", 10) == 10 );
	BOOST_TEST_REQUIRE( LongLong::from_dec("wrong", -10) == -10 );
}

BOOST_AUTO_TEST_CASE( i_from_hex_string_with_default ) {
	BOOST_TEST_REQUIRE( UByte::from_hex("wrong", 0x1a) == 0x1a );
	BOOST_TEST_REQUIRE( SByte::from_hex("wrong", 0x1a) == 0x1a );
	BOOST_TEST_REQUIRE( SByte::from_hex("wrong", -0x1a) == -0x1a );
	
	BOOST_TEST_REQUIRE( UShort::from_hex("wrong", 0x1a) == 0x1a );
	BOOST_TEST_REQUIRE( Short::from_hex("wrong", 0x1a) == 0x1a );
	BOOST_TEST_REQUIRE( Short::from_hex("wrong", -0x1a) == -0x1a );
	
	BOOST_TEST_REQUIRE( UInt::from_hex("wrong", 0x1a) == 0x1a );
	BOOST_TEST_REQUIRE( Int::from_hex("wrong", 0x1a) == 0x1a );
	BOOST_TEST_REQUIRE( Int::from_hex("wrong", -0x1a) == -0x1a );
	
	BOOST_TEST_REQUIRE( ULong::from_hex("wrong", 0x1a) == 0x1a );
	BOOST_TEST_REQUIRE( Long::from_hex("wrong", 0x1a) == 0x1a );
	BOOST_TEST_REQUIRE( Long::from_hex("wrong", -0x1a) == -0x1a );
	
	BOOST_TEST_REQUIRE( ULongLong::from_hex("wrong", 0x1a) == 0x1a );
	BOOST_TEST_REQUIRE( LongLong::from_hex("wrong", 0x1a) == 0x1a );
	BOOST_TEST_REQUIRE( LongLong::from_hex("wrong", -0x1a) == -0x1a );
}

BOOST_AUTO_TEST_CASE( i_real_rounding ) {
	#define RR(ns) \
	BOOST_TEST_REQUIRE( ns::round_real_f(123.45) == 123 ); \
	BOOST_TEST_REQUIRE( ns::round_real_d(123.45) == 123 ); \
	BOOST_TEST_REQUIRE( ns::round_real_l(123.45) == 123 );
	
	RR(UByte)
	RR(SByte)
	RR(UShort)
	RR(Short)
	RR(UInt)
	RR(Int)
	RR(ULong)
	RR(Long)
	RR(ULongLong)
	RR(LongLong)
	
	#undef RR
}

BOOST_AUTO_TEST_CASE( i_real_rounding_with_cut ) {
	#define RR(ns) \
	BOOST_TEST_REQUIRE( ns::round_real_f(123.45f, 2) == 100 ); \
	BOOST_TEST_REQUIRE( ns::round_real_d(123.45, 2) == 100 ); \
	BOOST_TEST_REQUIRE( ns::round_real_l(123.45l, 2) == 100 );
	
	RR(UByte)
	RR(SByte)
	RR(UShort)
	RR(Short)
	RR(UInt)
	RR(Int)
	RR(ULong)
	RR(Long)
	RR(ULongLong)
	RR(LongLong)
	
	#undef RR
}

BOOST_AUTO_TEST_CASE( fdl_sanity_test_nan ) {
	BOOST_TEST_REQUIRE( Float::is_nan(Float::qNaN) );
	BOOST_TEST_REQUIRE( Float::is_nan(Float::sNaN) );
	
	BOOST_TEST_REQUIRE( Double::is_nan(Double::qNaN) );
	BOOST_TEST_REQUIRE( Double::is_nan(Double::sNaN) );
	
	BOOST_TEST_REQUIRE( LongDouble::is_nan(LongDouble::qNaN) );
	BOOST_TEST_REQUIRE( LongDouble::is_nan(LongDouble::sNaN) );
}

BOOST_AUTO_TEST_CASE( fdl_sanity_test_inf ) {
	BOOST_TEST_REQUIRE( Float::is_inf(Float::pos_inf) );
	BOOST_TEST_REQUIRE( Float::is_inf(Float::neg_inf) );
	
	BOOST_TEST_REQUIRE( Double::is_inf(Double::pos_inf) );
	BOOST_TEST_REQUIRE( Double::is_inf(Double::neg_inf) );
	
	BOOST_TEST_REQUIRE( LongDouble::is_inf(LongDouble::pos_inf) );
	BOOST_TEST_REQUIRE( LongDouble::is_inf(LongDouble::neg_inf) );
}

BOOST_AUTO_TEST_CASE( fdl_abs_test ) {
	BOOST_TEST_REQUIRE( Float::abs(3.0f) == 3.0f );
	BOOST_TEST_REQUIRE( Float::abs(-3.0f) == 3.0f );
	
	BOOST_TEST_REQUIRE( Double::abs(3.0) == 3.0 );
	BOOST_TEST_REQUIRE( Double::abs(-3.0) == 3.0 );
	
	BOOST_TEST_REQUIRE( LongDouble::abs(3.0l) == 3.0l );
	BOOST_TEST_REQUIRE( LongDouble::abs(-3.0l) == 3.0l );
}

BOOST_AUTO_TEST_CASE( fdl_same_value_test ) {
	BOOST_TEST_REQUIRE( Float::is_same_value(Float::qNaN, Float::qNaN) );
	BOOST_TEST_REQUIRE( Float::is_same_value(Float::qNaN, Float::sNaN) );
	BOOST_TEST_REQUIRE( Float::is_same_value(Float::pos_inf, Float::pos_inf) );
	BOOST_TEST_REQUIRE( Float::is_same_value(Float::neg_inf, Float::neg_inf) );
	BOOST_TEST_REQUIRE( ! Float::is_same_value(Float::pos_inf, Float::neg_inf) );
	BOOST_TEST_REQUIRE( Float::is_same_value(3.0f, 3.0f) );
	BOOST_TEST_REQUIRE( ! Float::is_same_value(3.0f, -3.0f) );
	
	BOOST_TEST_REQUIRE( Double::is_same_value(Double::qNaN, Double::qNaN) );
	BOOST_TEST_REQUIRE( Double::is_same_value(Double::qNaN, Double::sNaN) );
	BOOST_TEST_REQUIRE( Double::is_same_value(Double::pos_inf, Double::pos_inf) );
	BOOST_TEST_REQUIRE( Double::is_same_value(Double::neg_inf, Double::neg_inf) );
	BOOST_TEST_REQUIRE( ! Double::is_same_value(Double::pos_inf, Double::neg_inf) );
	BOOST_TEST_REQUIRE( Double::is_same_value(3.0, 3.0) );
	BOOST_TEST_REQUIRE( ! Double::is_same_value(3.0, -3.0) );
	
	BOOST_TEST_REQUIRE( LongDouble::is_same_value(LongDouble::qNaN, LongDouble::qNaN) );
	BOOST_TEST_REQUIRE( LongDouble::is_same_value(LongDouble::qNaN, LongDouble::sNaN) );
	BOOST_TEST_REQUIRE( LongDouble::is_same_value(LongDouble::pos_inf, LongDouble::pos_inf) );
	BOOST_TEST_REQUIRE( LongDouble::is_same_value(LongDouble::neg_inf, LongDouble::neg_inf) );
	BOOST_TEST_REQUIRE( ! LongDouble::is_same_value(LongDouble::pos_inf, LongDouble::neg_inf) );
	BOOST_TEST_REQUIRE( LongDouble::is_same_value(3.0l, 3.0l) );
	BOOST_TEST_REQUIRE( ! LongDouble::is_same_value(3.0l, -3.0l) );
}

BOOST_AUTO_TEST_CASE( fdl_comparisons ) {
	BOOST_TEST_REQUIRE( Float::Cmp::exact().compare(1.0f, 1.0f) );
	BOOST_TEST_REQUIRE( Double::Cmp::exact().compare(1.0, 1.0) );
	BOOST_TEST_REQUIRE( LongDouble::Cmp::exact().compare(1.0l, 1.0l) );
	
	BOOST_TEST_REQUIRE( ! Float::Cmp::exact().compare(1.0f, 2.0f) );
	BOOST_TEST_REQUIRE( ! Double::Cmp::exact().compare(1.0, 2.0) );
	BOOST_TEST_REQUIRE( ! LongDouble::Cmp::exact().compare(1.0l, 2.0l) );
	
	BOOST_TEST_REQUIRE( Float::Cmp::abs(3.0f).compare(1.0f, 2.0f) );
	BOOST_TEST_REQUIRE( Double::Cmp::abs(3.0f).compare(1.0, 2.0) );
	BOOST_TEST_REQUIRE( LongDouble::Cmp::abs(3.0f).compare(1.0l, 2.0l) );
	
	BOOST_TEST_REQUIRE( ! Float::Cmp::abs(3.0f).compare(1.0f, 5.0f) );
	BOOST_TEST_REQUIRE( ! Double::Cmp::abs(3.0f).compare(1.0, 5.0) );
	BOOST_TEST_REQUIRE( ! LongDouble::Cmp::abs(3.0f).compare(1.0l, 5.0l) );
	
	BOOST_TEST_REQUIRE( Float::Cmp::rel(0.1f).compare(1.0f, 1.1f) );
	BOOST_TEST_REQUIRE( Double::Cmp::rel(0.1f).compare(1.0, 1.1) );
	BOOST_TEST_REQUIRE( LongDouble::Cmp::rel(0.1f).compare(1.0l, 1.1l) );
	
	BOOST_TEST_REQUIRE( ! Float::Cmp::rel(0.1f).compare(1.0f, 2.0f) );
	BOOST_TEST_REQUIRE( ! Double::Cmp::rel(0.1f).compare(1.0, 2.0) );
	BOOST_TEST_REQUIRE( ! LongDouble::Cmp::rel(0.1f).compare(1.0l, 2.0l) );
	
	BOOST_TEST_REQUIRE( Float::Cmp::abs_rel(2.0f, 0.1f).compare(1.0f, 1.1f) );
	BOOST_TEST_REQUIRE( Double::Cmp::abs_rel(2.0, 0.1f).compare(1.0, 1.1) );
	BOOST_TEST_REQUIRE( LongDouble::Cmp::abs_rel(2.0l, 0.1f).compare(1.0l, 1.1l) );
	
	BOOST_TEST_REQUIRE( ! Float::Cmp::abs_rel(2.0f, 0.1f).compare(1.0f, 5.0f) );
	BOOST_TEST_REQUIRE( ! Double::Cmp::abs_rel(2.0, 0.1f).compare(1.0, 5.0) );
	BOOST_TEST_REQUIRE( ! LongDouble::Cmp::abs_rel(2.0l, 0.1f).compare(1.0l, 5.0l) );
	
	BOOST_TEST_REQUIRE( Float::Cmp::gen(0.1f).compare(1.0f, 1.1f) );
	BOOST_TEST_REQUIRE( Double::Cmp::gen(0.1f).compare(1.0, 1.1) );
	BOOST_TEST_REQUIRE( LongDouble::Cmp::gen(0.1f).compare(1.0l, 1.1l) );
	
	BOOST_TEST_REQUIRE( ! Float::Cmp::gen(0.1f).compare(1.0f, 2.0f) );
	BOOST_TEST_REQUIRE( ! Double::Cmp::gen(0.1f).compare(1.0, 2.0) );
	BOOST_TEST_REQUIRE( ! LongDouble::Cmp::gen(0.1f).compare(1.0l, 2.0l) );
}

BOOST_AUTO_TEST_CASE( fdl_to_string_conversion ) {
	BOOST_TEST_REQUIRE( Float::to_scientific( 3.14159f ) == "3.14159e+00" );
	BOOST_TEST_REQUIRE( Float::to_general( 3.14159f ) == "3.14159" );
	BOOST_TEST_REQUIRE( Float::to_fixed( 3.14159f ) == "3.14159" );
	BOOST_TEST_REQUIRE( Float::to_hex( 3.14159f ) == "1.921fap+1" );
	
	BOOST_TEST_REQUIRE( Double::to_scientific( 3.14159 ) == "3.14159e+00" );
	BOOST_TEST_REQUIRE( Double::to_general( 3.14159 ) == "3.14159" );
	BOOST_TEST_REQUIRE( Double::to_fixed( 3.14159 ) == "3.14159" );
	BOOST_TEST_REQUIRE( Double::to_hex( 3.14159 ) == "1.921f9f01b866ep+1" );
	
	BOOST_TEST_REQUIRE( LongDouble::to_scientific( 3.14159l ) == "3.14159e+00" );
	BOOST_TEST_REQUIRE( LongDouble::to_general( 3.14159l ) == "3.14159" );
	BOOST_TEST_REQUIRE( LongDouble::to_fixed( 3.14159l ) == "3.14159" );
	BOOST_TEST_REQUIRE( LongDouble::to_hex( 3.14159l ) == "c.90fcf80dc33721dp-2" );
}

BOOST_AUTO_TEST_CASE( fdl_to_string_conversion_with_precision ) {
	BOOST_TEST_REQUIRE( Float::to_scientific( 3.14159f, 2 ) == "3.14e+00" );
	BOOST_TEST_REQUIRE( Float::to_general( 3.14159f, 3 ) == "3.14" );
	BOOST_TEST_REQUIRE( Float::to_fixed( 3.14159f, 2 ) == "3.14" );
	BOOST_TEST_REQUIRE( Float::to_hex( 3.14159f, 2 ) == "1.92p+1" );
	
	BOOST_TEST_REQUIRE( Double::to_scientific( 3.14159, 2 ) == "3.14e+00" );
	BOOST_TEST_REQUIRE( Double::to_general( 3.14159, 3 ) == "3.14" );
	BOOST_TEST_REQUIRE( Double::to_fixed( 3.14159, 2 ) == "3.14" );
	BOOST_TEST_REQUIRE( Double::to_hex( 3.14159, 2 ) == "1.92p+1" );
	
	BOOST_TEST_REQUIRE( LongDouble::to_scientific( 3.14159l, 2 ) == "3.14e+00" );
	BOOST_TEST_REQUIRE( LongDouble::to_general( 3.14159l, 3 ) == "3.14" );
	BOOST_TEST_REQUIRE( LongDouble::to_fixed( 3.14159l, 2 ) == "3.14" );
	BOOST_TEST_REQUIRE( LongDouble::to_hex( 3.14159l, 2 ) == "c.91p-2" );
}

BOOST_AUTO_TEST_CASE( fdl_from_string_conversion ) {
	BOOST_TEST_REQUIRE( Float::from_scientific( "3.14159e+00" ) ==  3.14159f );
	BOOST_TEST_REQUIRE( Float::from_fixed( "3.14159" ) ==  3.14159f );
	BOOST_TEST_REQUIRE( Float::from_general( "3.14159e+00" ) ==  3.14159f );
	BOOST_TEST_REQUIRE( Float::from_general( "3.14159" ) ==  3.14159f );
	BOOST_TEST_REQUIRE( Float::from_hex( "1.921fap+1" ) ==  3.14159f );
	
	BOOST_TEST_REQUIRE( Double::from_scientific( "3.14159e+00" ) ==  3.14159 );
	BOOST_TEST_REQUIRE( Double::from_fixed( "3.14159" ) ==  3.14159 );
	BOOST_TEST_REQUIRE( Double::from_general( "3.14159e+00" ) ==  3.14159 );
	BOOST_TEST_REQUIRE( Double::from_general( "3.14159" ) ==  3.14159 );
	BOOST_TEST_REQUIRE( Double::from_hex( "1.921f9f01b866ep+1" ) ==  3.14159 );
	
	BOOST_TEST_REQUIRE( LongDouble::from_scientific( "3.14159e+00" ) ==  3.14159l );
	BOOST_TEST_REQUIRE( LongDouble::from_fixed( "3.14159" ) ==  3.14159l );
	BOOST_TEST_REQUIRE( LongDouble::from_general( "3.14159e+00" ) ==  3.14159l );
	BOOST_TEST_REQUIRE( LongDouble::from_general( "3.14159" ) ==  3.14159l );
	BOOST_TEST_REQUIRE( LongDouble::from_hex( "c.90fcf80dc33721dp-2" ) ==  3.14159l );
}

BOOST_AUTO_TEST_CASE( fdl_from_string_conversion_with_wrong_text ) {
	BOOST_TEST_REQUIRE( Float::from_scientific( "wrong", 3.14159f ) ==  3.14159f );
	BOOST_TEST_REQUIRE( Float::from_fixed( "wrong", 3.14159f ) ==  3.14159f );
	BOOST_TEST_REQUIRE( Float::from_general( "wrong", 3.14159f ) ==  3.14159f );
	BOOST_TEST_REQUIRE( Float::from_general( "wrong", 3.14159f ) ==  3.14159f );
	BOOST_TEST_REQUIRE( Float::from_hex( "wrong", 3.14159f ) ==  3.14159f );
	
	BOOST_TEST_REQUIRE( Double::from_scientific( "wrong", 3.14159 ) ==  3.14159 );
	BOOST_TEST_REQUIRE( Double::from_fixed( "wrong", 3.14159 ) ==  3.14159 );
	BOOST_TEST_REQUIRE( Double::from_general( "wrong", 3.14159 ) ==  3.14159 );
	BOOST_TEST_REQUIRE( Double::from_general( "wrong", 3.14159 ) ==  3.14159 );
	BOOST_TEST_REQUIRE( Double::from_hex( "wrong", 3.14159 ) ==  3.14159 );
	
	BOOST_TEST_REQUIRE( LongDouble::from_scientific( "wrong", 3.14159l ) ==  3.14159l );
	BOOST_TEST_REQUIRE( LongDouble::from_fixed( "wrong", 3.14159l ) ==  3.14159l );
	BOOST_TEST_REQUIRE( LongDouble::from_general( "wrong", 3.14159l ) ==  3.14159l );
	BOOST_TEST_REQUIRE( LongDouble::from_general( "wrong", 3.14159l ) ==  3.14159l );
	BOOST_TEST_REQUIRE( LongDouble::from_hex( "wrong", 3.14159l ) ==  3.14159l );
}

BOOST_AUTO_TEST_CASE( fdl_rounding ) {
	#define IS_EQ(a,b) ((a) - (b)) <= 0.0001
	
	BOOST_TEST_REQUIRE( IS_EQ(Float::round(123.456f) , 123.0f) );
	BOOST_TEST_REQUIRE( IS_EQ(Double::round(123.456) , 123.0) );
	BOOST_TEST_REQUIRE( IS_EQ(LongDouble::round(123.456l) , 123.0l) );
	
	BOOST_TEST_REQUIRE( IS_EQ(Float::round(123.456f, 2) , 123.46f) );
	BOOST_TEST_REQUIRE( IS_EQ(Double::round(123.456, 2) , 123.46) );
	BOOST_TEST_REQUIRE( IS_EQ(LongDouble::round(123.456l, 2) , 123.46l) );
	
	BOOST_TEST_REQUIRE( IS_EQ(Float::round(123.456f, -2) , 100.0f) );
	BOOST_TEST_REQUIRE( IS_EQ(Double::round(123.456, -2) , 100.0) );
	BOOST_TEST_REQUIRE( IS_EQ(LongDouble::round(123.456l, -2) , 100.0l) );
	
	#undef IS_EQ
}

