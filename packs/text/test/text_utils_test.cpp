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

#include "../src/join.hpp"
#include "../src/case.hpp"
#include "../src/convert.hpp"
#include "../src/split.hpp"
#include "../src/just.hpp"
#include "../src/checks.hpp"

#include <string>
#include <vector>
#include <iomanip>

BOOST_AUTO_TEST_CASE( joining_string_vector ) {
	std::vector<std::string> vec{"abc", "def", "ghi"};
	std::string result = txt::join(vec.begin(), vec.end(), ", ");
	BOOST_TEST_REQUIRE( result == "abc, def, ghi" );
}

BOOST_AUTO_TEST_CASE( joining_int_vector ) {
	std::vector<int> vec{123, 456, 789};
	std::string result = txt::join(vec.begin(), vec.end(), ":");
	BOOST_TEST_REQUIRE( result == "123:456:789" );
}

BOOST_AUTO_TEST_CASE( joining_with_conversion ) {
	std::vector<int> vec{1,2,3};
	std::string result = txt::join(vec.begin(), vec.end(), " ", [](int i){ return i*i; });
	BOOST_TEST_REQUIRE( result == "1 4 9" );
}

BOOST_AUTO_TEST_CASE( uni_to_lower_char ) {
	BOOST_TEST_REQUIRE( (unicode::to_lower(U'Ą') == U'ą') );
	BOOST_TEST_REQUIRE( (unicode::to_lower(U'Ę') == U'ę') );
	BOOST_TEST_REQUIRE( (unicode::to_lower(U'Ś') == U'ś') );
	BOOST_TEST_REQUIRE( (unicode::to_lower(U'Ć') == U'ć') );
}

BOOST_AUTO_TEST_CASE( uni_to_upper_char ) {
	BOOST_TEST_REQUIRE( (unicode::to_upper(U'ą') == U'Ą') );
	BOOST_TEST_REQUIRE( (unicode::to_upper(U'ę') == U'Ę') );
	BOOST_TEST_REQUIRE( (unicode::to_upper(U'ś') == U'Ś') );
	BOOST_TEST_REQUIRE( (unicode::to_upper(U'ć') == U'Ć') );
}

BOOST_AUTO_TEST_CASE( uni_to_upper_string ) {
	std::u32string source{U"Straße"};
	std::u32string dest{U"STRASSE"};
	
	auto result = unicode::to_upper(source);
	BOOST_TEST_REQUIRE( (result == dest) );
}

BOOST_AUTO_TEST_CASE( convert_utf8_to_utf32 ) {
	std::string source = "z\u00df\u6c34\U0001F34C";
	
	std::u32string dest = txt::utf8_to_utf32(source);
	BOOST_TEST_REQUIRE( dest.size() == 4 );
	BOOST_TEST_REQUIRE( (dest[0] == U'z') );
	BOOST_TEST_REQUIRE( (dest[1] == 0x00df) );
	BOOST_TEST_REQUIRE( (dest[2] == 0x6c34) );
	BOOST_TEST_REQUIRE( (dest[3] == 0x0001f34c) );
}

BOOST_AUTO_TEST_CASE( convert_utf8_to_utf32_sv ) {
	std::string source = "z\u00df\u6c34\U0001F34C";
	
	std::u32string dest = txt::utf8_to_utf32(static_cast<std::string_view>(source));
	BOOST_TEST_REQUIRE( dest.size() == 4 );
	BOOST_TEST_REQUIRE( (dest[0] == U'z') );
	BOOST_TEST_REQUIRE( (dest[1] == 0x00df) );
	BOOST_TEST_REQUIRE( (dest[2] == 0x6c34) );
	BOOST_TEST_REQUIRE( (dest[3] == 0x0001f34c) );
}

BOOST_AUTO_TEST_CASE( convert_utf32_to_utf8 ) {
	std::u32string source = U"z\u00df\u6c34\U0001F34C";
	
	std::string dest = txt::utf32_to_utf8(source);
	BOOST_TEST_REQUIRE( dest.size() == 10 );
	BOOST_TEST_REQUIRE( (dest[0] == (char)0x7a) );
	BOOST_TEST_REQUIRE( (dest[1] == (char)0xc3) );
	BOOST_TEST_REQUIRE( (dest[2] == (char)0x9f) );
	BOOST_TEST_REQUIRE( (dest[3] == (char)0xe6) );
	BOOST_TEST_REQUIRE( (dest[4] == (char)0xb0) );
	BOOST_TEST_REQUIRE( (dest[5] == (char)0xb4) );
	BOOST_TEST_REQUIRE( (dest[6] == (char)0xf0) );
	BOOST_TEST_REQUIRE( (dest[7] == (char)0x9f) );
	BOOST_TEST_REQUIRE( (dest[8] == (char)0x8d) );
	BOOST_TEST_REQUIRE( (dest[9] == (char)0x8c) );
}

BOOST_AUTO_TEST_CASE( convert_utf32_to_utf8_sv ) {
	std::u32string source = U"z\u00df\u6c34\U0001F34C";
	
	std::string dest = txt::utf32_to_utf8(static_cast<std::u32string_view>(source));
	BOOST_TEST_REQUIRE( dest.size() == 10 );
	BOOST_TEST_REQUIRE( (dest[0] == (char)0x7a) );
	BOOST_TEST_REQUIRE( (dest[1] == (char)0xc3) );
	BOOST_TEST_REQUIRE( (dest[2] == (char)0x9f) );
	BOOST_TEST_REQUIRE( (dest[3] == (char)0xe6) );
	BOOST_TEST_REQUIRE( (dest[4] == (char)0xb0) );
	BOOST_TEST_REQUIRE( (dest[5] == (char)0xb4) );
	BOOST_TEST_REQUIRE( (dest[6] == (char)0xf0) );
	BOOST_TEST_REQUIRE( (dest[7] == (char)0x9f) );
	BOOST_TEST_REQUIRE( (dest[8] == (char)0x8d) );
	BOOST_TEST_REQUIRE( (dest[9] == (char)0x8c) );
}

BOOST_AUTO_TEST_CASE( split_text_with_str_sep ) {
	std::string source{"a, bb, ccc"};
	
	auto vec = txt::split(source, ", ");
	BOOST_TEST_REQUIRE( vec.size() == 3 );
	BOOST_TEST_REQUIRE( vec[0] == "a" );
	BOOST_TEST_REQUIRE( vec[1] == "bb" );
	BOOST_TEST_REQUIRE( vec[2] == "ccc" );
}

BOOST_AUTO_TEST_CASE( split_text_with_str_sep_at_end ) {
	std::string source{"a, bb, ccc, "};
	
	auto vec = txt::split(source, ", ");
	BOOST_TEST_REQUIRE( vec.size() == 4 );
	BOOST_TEST_REQUIRE( vec[0] == "a" );
	BOOST_TEST_REQUIRE( vec[1] == "bb" );
	BOOST_TEST_REQUIRE( vec[2] == "ccc" );
	BOOST_TEST_REQUIRE( vec[3] == "" );
}

BOOST_AUTO_TEST_CASE( split_text_with_str_sep_at_begin ) {
	std::string source{", a, bb, ccc"};
	
	auto vec = txt::split(source, ", ");
	BOOST_TEST_REQUIRE( vec.size() == 4 );
	BOOST_TEST_REQUIRE( vec[0] == "" );
	BOOST_TEST_REQUIRE( vec[1] == "a" );
	BOOST_TEST_REQUIRE( vec[2] == "bb" );
	BOOST_TEST_REQUIRE( vec[3] == "ccc" );
}

BOOST_AUTO_TEST_CASE( split_text_with_char_sep ) {
	std::string source{"a.bb.ccc"};
	
	auto vec = txt::split(source, '.');
	BOOST_TEST_REQUIRE( vec.size() == 3 );
	BOOST_TEST_REQUIRE( vec[0] == "a" );
	BOOST_TEST_REQUIRE( vec[1] == "bb" );
	BOOST_TEST_REQUIRE( vec[2] == "ccc" );
}

BOOST_AUTO_TEST_CASE( split_text_with_char_sep_at_end ) {
	std::string source{"a.bb.ccc."};
	
	auto vec = txt::split(source, '.');
	BOOST_TEST_REQUIRE( vec.size() == 4 );
	BOOST_TEST_REQUIRE( vec[0] == "a" );
	BOOST_TEST_REQUIRE( vec[1] == "bb" );
	BOOST_TEST_REQUIRE( vec[2] == "ccc" );
	BOOST_TEST_REQUIRE( vec[3] == "" );
}

BOOST_AUTO_TEST_CASE( split_text_with_char_sep_at_begin ) {
	std::string source{".a.bb.ccc"};
	
	auto vec = txt::split(source, '.');
	BOOST_TEST_REQUIRE( vec.size() == 4 );
	BOOST_TEST_REQUIRE( vec[0] == "" );
	BOOST_TEST_REQUIRE( vec[1] == "a" );
	BOOST_TEST_REQUIRE( vec[2] == "bb" );
	BOOST_TEST_REQUIRE( vec[3] == "ccc" );
}

BOOST_AUTO_TEST_CASE( split_text_with_str_sep_sv ) {
	std::string source{"a, bb, ccc"};
	
	auto vec = txt::split_sv(source, ", ");
	BOOST_TEST_REQUIRE( vec.size() == 3 );
	BOOST_TEST_REQUIRE( vec[0] == "a" );
	BOOST_TEST_REQUIRE( vec[1] == "bb" );
	BOOST_TEST_REQUIRE( vec[2] == "ccc" );
}

BOOST_AUTO_TEST_CASE( split_text_with_str_sep_at_end_sv ) {
	std::string source{"a, bb, ccc, "};
	
	auto vec = txt::split_sv(source, ", ");
	BOOST_TEST_REQUIRE( vec.size() == 4 );
	BOOST_TEST_REQUIRE( vec[0] == "a" );
	BOOST_TEST_REQUIRE( vec[1] == "bb" );
	BOOST_TEST_REQUIRE( vec[2] == "ccc" );
	BOOST_TEST_REQUIRE( vec[3] == "" );
}

BOOST_AUTO_TEST_CASE( split_text_with_str_sep_at_begin_sv ) {
	std::string source{", a, bb, ccc"};
	
	auto vec = txt::split_sv(source, ", ");
	BOOST_TEST_REQUIRE( vec.size() == 4 );
	BOOST_TEST_REQUIRE( vec[0] == "" );
	BOOST_TEST_REQUIRE( vec[1] == "a" );
	BOOST_TEST_REQUIRE( vec[2] == "bb" );
	BOOST_TEST_REQUIRE( vec[3] == "ccc" );
}

BOOST_AUTO_TEST_CASE( split_text_with_char_sep_sv ) {
	std::string source{"a.bb.ccc"};
	
	auto vec = txt::split_sv(source, '.');
	BOOST_TEST_REQUIRE( vec.size() == 3 );
	BOOST_TEST_REQUIRE( vec[0] == "a" );
	BOOST_TEST_REQUIRE( vec[1] == "bb" );
	BOOST_TEST_REQUIRE( vec[2] == "ccc" );
}

BOOST_AUTO_TEST_CASE( split_text_with_char_sep_at_end_sv ) {
	std::string source{"a.bb.ccc."};
	
	auto vec = txt::split_sv(source, '.');
	BOOST_TEST_REQUIRE( vec.size() == 4 );
	BOOST_TEST_REQUIRE( vec[0] == "a" );
	BOOST_TEST_REQUIRE( vec[1] == "bb" );
	BOOST_TEST_REQUIRE( vec[2] == "ccc" );
	BOOST_TEST_REQUIRE( vec[3] == "" );
}

BOOST_AUTO_TEST_CASE( split_text_with_char_sep_at_begin_sv ) {
	std::string source{".a.bb.ccc"};
	
	auto vec = txt::split_sv(source, '.');
	BOOST_TEST_REQUIRE( vec.size() == 4 );
	BOOST_TEST_REQUIRE( vec[0] == "" );
	BOOST_TEST_REQUIRE( vec[1] == "a" );
	BOOST_TEST_REQUIRE( vec[2] == "bb" );
	BOOST_TEST_REQUIRE( vec[3] == "ccc" );
}

BOOST_AUTO_TEST_CASE( ljust_text ) {
	std::string short_txt{"1234"};
	std::string long_txt{"123456789"};
	
	auto result_str_short = txt::ljust(short_txt, 7);
	auto result_str_long = txt::ljust(long_txt, 7);
	BOOST_TEST_REQUIRE( result_str_short == "1234   " );
	BOOST_TEST_REQUIRE( result_str_long == long_txt );
	
	auto result_sv_short = txt::ljust(static_cast<std::string_view>(short_txt), 7);
	auto result_sv_long = txt::ljust(static_cast<std::string_view>(long_txt), 7);
	BOOST_TEST_REQUIRE( result_sv_short == "1234   " );
	BOOST_TEST_REQUIRE( result_sv_long == long_txt );
}

BOOST_AUTO_TEST_CASE( rjust_text ) {
	std::string short_txt{"1234"};
	std::string long_txt{"123456789"};
	
	auto result_str_short = txt::rjust(short_txt, 7);
	auto result_str_long = txt::rjust(long_txt, 7);
	BOOST_TEST_REQUIRE( result_str_short == "   1234" );
	BOOST_TEST_REQUIRE( result_str_long == long_txt );
	
	auto result_sv_short = txt::rjust(static_cast<std::string_view>(short_txt), 7);
	auto result_sv_long = txt::rjust(static_cast<std::string_view>(long_txt), 7);
	BOOST_TEST_REQUIRE( result_sv_short == "   1234" );
	BOOST_TEST_REQUIRE( result_sv_long == long_txt );
}

BOOST_AUTO_TEST_CASE( center_text ) {
	std::string short_txt{"1234"};
	std::string long_txt{"123456789"};
	
	auto result_str_short = txt::center(short_txt, 8);
	auto result_str_long = txt::center(long_txt, 8);
	BOOST_TEST_REQUIRE( result_str_short == "  1234  " );
	BOOST_TEST_REQUIRE( result_str_long == long_txt );
	
	auto result_sv_short = txt::center(static_cast<std::string_view>(short_txt), 8);
	auto result_sv_long = txt::center(static_cast<std::string_view>(long_txt), 8);
	BOOST_TEST_REQUIRE( result_sv_short == "  1234  " );
	BOOST_TEST_REQUIRE( result_sv_long == long_txt );
}

BOOST_AUTO_TEST_CASE( txt_is_alpha ) {
	BOOST_TEST_REQUIRE( txt::is_alpha(U'a') );
	BOOST_TEST_REQUIRE( txt::is_alpha(U'A') );
	BOOST_TEST_REQUIRE( txt::is_alpha(U'ą') );
	BOOST_TEST_REQUIRE( txt::is_alpha(U'Ą') );
	
	BOOST_TEST_REQUIRE( ! txt::is_alpha(U'1') );
	BOOST_TEST_REQUIRE( ! txt::is_alpha(U' ') );
	BOOST_TEST_REQUIRE( ! txt::is_alpha(U'&') );
}

BOOST_AUTO_TEST_CASE( txt_is_ascii ) {
	BOOST_TEST_REQUIRE( txt::is_ascii(U'a') );
	BOOST_TEST_REQUIRE( txt::is_ascii(U'A') );
	BOOST_TEST_REQUIRE( txt::is_ascii(U'1') );
	BOOST_TEST_REQUIRE( txt::is_ascii(U' ') );
	BOOST_TEST_REQUIRE( txt::is_ascii(U'&') );
	
	BOOST_TEST_REQUIRE( ! txt::is_ascii(U'ą') );
	BOOST_TEST_REQUIRE( ! txt::is_ascii(U'Ą') );
}

BOOST_AUTO_TEST_CASE( txt_is_digit ) {
	BOOST_TEST_REQUIRE( txt::is_digit(U'1') );
	BOOST_TEST_REQUIRE( txt::is_digit(U'5') );
	BOOST_TEST_REQUIRE( txt::is_digit(U'0') );
	
	BOOST_TEST_REQUIRE( ! txt::is_digit(U'A') );
	BOOST_TEST_REQUIRE( ! txt::is_digit(U'ą') );
}

BOOST_AUTO_TEST_CASE( txt_is_numeric ) {
	BOOST_TEST_REQUIRE( txt::is_numeric(U'1') );
	BOOST_TEST_REQUIRE( txt::is_numeric(U'5') );
	BOOST_TEST_REQUIRE( txt::is_numeric(U'0') );
	
	BOOST_TEST_REQUIRE( ! txt::is_numeric(U'A') );
	BOOST_TEST_REQUIRE( ! txt::is_numeric(U'ą') );
}

BOOST_AUTO_TEST_CASE( txt_is_print ) {
	BOOST_TEST_REQUIRE( txt::is_print(U'A') );
	BOOST_TEST_REQUIRE( txt::is_print(U'a') );
	BOOST_TEST_REQUIRE( txt::is_print(U'2') );
	
	BOOST_TEST_REQUIRE( ! txt::is_print(static_cast<char32_t>(5)) );
}

BOOST_AUTO_TEST_CASE( txt_is_space ) {
	BOOST_TEST_REQUIRE( txt::is_space(U' ') );
	BOOST_TEST_REQUIRE( txt::is_space(U'\t') );
	BOOST_TEST_REQUIRE( txt::is_space(U'\n') );
	
	BOOST_TEST_REQUIRE( ! txt::is_space(U'A') );
	BOOST_TEST_REQUIRE( ! txt::is_space(U'ą') );
}

BOOST_AUTO_TEST_CASE( txt_is_lower_case ) {
	BOOST_TEST_REQUIRE( txt::is_lower_case(U'a') );
	BOOST_TEST_REQUIRE( txt::is_lower_case(U'ą') );
	
	BOOST_TEST_REQUIRE( ! txt::is_lower_case(U'A') );
	BOOST_TEST_REQUIRE( ! txt::is_lower_case(U'Ą') );
}

BOOST_AUTO_TEST_CASE( txt_is_upper_case ) {
	BOOST_TEST_REQUIRE( txt::is_upper_case(U'A') );
	BOOST_TEST_REQUIRE( txt::is_upper_case(U'Ą') );
	
	BOOST_TEST_REQUIRE( ! txt::is_upper_case(U'a') );
	BOOST_TEST_REQUIRE( ! txt::is_upper_case(U'ą') );
}

BOOST_AUTO_TEST_CASE( txt_is_title_case ) {
	BOOST_TEST_REQUIRE( txt::is_title_case(U'A') );
	BOOST_TEST_REQUIRE( txt::is_title_case(U'Ą') );
	
	BOOST_TEST_REQUIRE( ! txt::is_title_case(U'a') );
	BOOST_TEST_REQUIRE( ! txt::is_title_case(U'ą') );
}

