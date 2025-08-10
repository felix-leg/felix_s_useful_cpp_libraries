#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE text_utils_test
#include <boost/test/unit_test.hpp>

#include "../src/join.hpp"
#include "../src/utf32/case.hpp"
#include "../src/utf8/case.hpp"
#include "../src/ascii/case.hpp"
#include "../src/convert.hpp"
#include "../src/split.hpp"
#include "../src/just.hpp"
#include "../src/utf32/checks.hpp"
#include "../src/utf8/checks.hpp"
#include "../src/utf32/trim.hpp"
#include "../src/utf8/trim.hpp"
#include "../src/ascii/trim.hpp"
#include "../src/utf8/iter.hpp"

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

BOOST_AUTO_TEST_CASE( utf32_to_lower_char ) {
	BOOST_TEST_REQUIRE( (utf32::to_lower(U'Ą') == U'ą') );
	BOOST_TEST_REQUIRE( (utf32::to_lower(U'Ę') == U'ę') );
	BOOST_TEST_REQUIRE( (utf32::to_lower(U'Ś') == U'ś') );
	BOOST_TEST_REQUIRE( (utf32::to_lower(U'Ć') == U'ć') );
}

BOOST_AUTO_TEST_CASE( utf32_to_upper_char ) {
	BOOST_TEST_REQUIRE( (utf32::to_upper(U'ą') == U'Ą') );
	BOOST_TEST_REQUIRE( (utf32::to_upper(U'ę') == U'Ę') );
	BOOST_TEST_REQUIRE( (utf32::to_upper(U'ś') == U'Ś') );
	BOOST_TEST_REQUIRE( (utf32::to_upper(U'ć') == U'Ć') );
}

BOOST_AUTO_TEST_CASE( utf32_to_upper_string ) {
	std::u32string source{U"Straße"};
	std::u32string dest{U"STRASSE"};
	
	auto result = utf32::to_upper(source);
	BOOST_TEST_REQUIRE( (result == dest) );
}

BOOST_AUTO_TEST_CASE( utf8_to_lower_char ) {
	BOOST_TEST_REQUIRE( (utf8::to_lower("Ą") == "ą") );
	BOOST_TEST_REQUIRE( (utf8::to_lower("Ę") == "ę") );
	BOOST_TEST_REQUIRE( (utf8::to_lower("Ś") == "ś") );
	BOOST_TEST_REQUIRE( (utf8::to_lower("Ć") == "ć") );
}

BOOST_AUTO_TEST_CASE( utf8_to_upper_char ) {
	BOOST_TEST_REQUIRE( (utf8::to_upper("ą") == "Ą") );
	BOOST_TEST_REQUIRE( (utf8::to_upper("ę") == "Ę") );
	BOOST_TEST_REQUIRE( (utf8::to_upper("ś") == "Ś") );
	BOOST_TEST_REQUIRE( (utf8::to_upper("ć") == "Ć") );
}

BOOST_AUTO_TEST_CASE( utf8_to_upper_string ) {
	std::string source{"Straße"};
	std::string dest{"STRASSE"};
	
	auto result = utf8::to_upper(source);
	BOOST_TEST_REQUIRE( (result == dest) );
}

BOOST_AUTO_TEST_CASE( ascii_to_lower_char ) {
	BOOST_TEST_REQUIRE( (ascii::to_lower('A') == 'a') );
	BOOST_TEST_REQUIRE( (ascii::to_lower('E') == 'e') );
	BOOST_TEST_REQUIRE( (ascii::to_lower('S') == 's') );
	BOOST_TEST_REQUIRE( (ascii::to_lower('C') == 'c') );
}

BOOST_AUTO_TEST_CASE( ascii_to_upper_char ) {
	BOOST_TEST_REQUIRE( (ascii::to_upper('a') == 'A') );
	BOOST_TEST_REQUIRE( (ascii::to_upper('e') == 'E') );
	BOOST_TEST_REQUIRE( (ascii::to_upper('s') == 'S') );
	BOOST_TEST_REQUIRE( (ascii::to_upper('c') == 'C') );
}

BOOST_AUTO_TEST_CASE( ascii_to_upper_string ) {
	std::string source{"\tabcdef\n"};
	std::string dest{"\tABCDEF\n"};
	
	auto result = ascii::to_upper(source);
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

BOOST_AUTO_TEST_CASE( utf32_is_alpha ) {
	BOOST_TEST_REQUIRE( utf32::is_alpha(U'a') );
	BOOST_TEST_REQUIRE( utf32::is_alpha(U'A') );
	BOOST_TEST_REQUIRE( utf32::is_alpha(U'ą') );
	BOOST_TEST_REQUIRE( utf32::is_alpha(U'Ą') );
	
	BOOST_TEST_REQUIRE( ! utf32::is_alpha(U'1') );
	BOOST_TEST_REQUIRE( ! utf32::is_alpha(U' ') );
	BOOST_TEST_REQUIRE( ! utf32::is_alpha(U'&') );
}

BOOST_AUTO_TEST_CASE( utf32_is_ascii ) {
	BOOST_TEST_REQUIRE( utf32::is_ascii(U'a') );
	BOOST_TEST_REQUIRE( utf32::is_ascii(U'A') );
	BOOST_TEST_REQUIRE( utf32::is_ascii(U'1') );
	BOOST_TEST_REQUIRE( utf32::is_ascii(U' ') );
	BOOST_TEST_REQUIRE( utf32::is_ascii(U'&') );
	
	BOOST_TEST_REQUIRE( ! utf32::is_ascii(U'ą') );
	BOOST_TEST_REQUIRE( ! utf32::is_ascii(U'Ą') );
}

BOOST_AUTO_TEST_CASE( utf32_is_digit ) {
	BOOST_TEST_REQUIRE( utf32::is_digit(U'1') );
	BOOST_TEST_REQUIRE( utf32::is_digit(U'5') );
	BOOST_TEST_REQUIRE( utf32::is_digit(U'0') );
	
	BOOST_TEST_REQUIRE( ! utf32::is_digit(U'A') );
	BOOST_TEST_REQUIRE( ! utf32::is_digit(U'ą') );
}

BOOST_AUTO_TEST_CASE( utf32_is_numeric ) {
	BOOST_TEST_REQUIRE( utf32::is_numeric(U'1') );
	BOOST_TEST_REQUIRE( utf32::is_numeric(U'5') );
	BOOST_TEST_REQUIRE( utf32::is_numeric(U'0') );
	
	BOOST_TEST_REQUIRE( ! utf32::is_numeric(U'A') );
	BOOST_TEST_REQUIRE( ! utf32::is_numeric(U'ą') );
}

BOOST_AUTO_TEST_CASE( utf32_is_print ) {
	BOOST_TEST_REQUIRE( utf32::is_print(U'A') );
	BOOST_TEST_REQUIRE( utf32::is_print(U'a') );
	BOOST_TEST_REQUIRE( utf32::is_print(U'2') );
	
	BOOST_TEST_REQUIRE( ! utf32::is_print(static_cast<char32_t>(5)) );
}

BOOST_AUTO_TEST_CASE( utf32_is_space ) {
	BOOST_TEST_REQUIRE( utf32::is_space(U' ') );
	BOOST_TEST_REQUIRE( utf32::is_space(U'\t') );
	BOOST_TEST_REQUIRE( utf32::is_space(U'\n') );
	
	BOOST_TEST_REQUIRE( ! utf32::is_space(U'A') );
	BOOST_TEST_REQUIRE( ! utf32::is_space(U'ą') );
}

BOOST_AUTO_TEST_CASE( utf32_is_lower_case ) {
	BOOST_TEST_REQUIRE( utf32::is_lower_case(U'a') );
	BOOST_TEST_REQUIRE( utf32::is_lower_case(U'ą') );
	
	BOOST_TEST_REQUIRE( ! utf32::is_lower_case(U'A') );
	BOOST_TEST_REQUIRE( ! utf32::is_lower_case(U'Ą') );
}

BOOST_AUTO_TEST_CASE( utf32_is_upper_case ) {
	BOOST_TEST_REQUIRE( utf32::is_upper_case(U'A') );
	BOOST_TEST_REQUIRE( utf32::is_upper_case(U'Ą') );
	
	BOOST_TEST_REQUIRE( ! utf32::is_upper_case(U'a') );
	BOOST_TEST_REQUIRE( ! utf32::is_upper_case(U'ą') );
}

BOOST_AUTO_TEST_CASE( utf32_is_title_case ) {
	BOOST_TEST_REQUIRE( utf32::is_title_case(U'A') );
	BOOST_TEST_REQUIRE( utf32::is_title_case(U'Ą') );
	
	BOOST_TEST_REQUIRE( ! utf32::is_title_case(U'a') );
	BOOST_TEST_REQUIRE( ! utf32::is_title_case(U'ą') );
}

BOOST_AUTO_TEST_CASE( utf8_is_alpha ) {
	BOOST_TEST_REQUIRE( utf8::is_alpha("a") );
	BOOST_TEST_REQUIRE( utf8::is_alpha("A") );
	BOOST_TEST_REQUIRE( utf8::is_alpha("ą") );
	BOOST_TEST_REQUIRE( utf8::is_alpha("Ą") );
	
	BOOST_TEST_REQUIRE( ! utf8::is_alpha("1") );
	BOOST_TEST_REQUIRE( ! utf8::is_alpha(" ") );
	BOOST_TEST_REQUIRE( ! utf8::is_alpha("&") );
}

BOOST_AUTO_TEST_CASE( utf8_is_ascii ) {
	BOOST_TEST_REQUIRE( utf8::is_ascii("a") );
	BOOST_TEST_REQUIRE( utf8::is_ascii("A") );
	BOOST_TEST_REQUIRE( utf8::is_ascii("1") );
	BOOST_TEST_REQUIRE( utf8::is_ascii(" ") );
	BOOST_TEST_REQUIRE( utf8::is_ascii("&") );
	
	BOOST_TEST_REQUIRE( ! utf8::is_ascii("ą") );
	BOOST_TEST_REQUIRE( ! utf8::is_ascii("Ą") );
}

BOOST_AUTO_TEST_CASE( utf8_is_digit ) {
	BOOST_TEST_REQUIRE( utf8::is_digit("1") );
	BOOST_TEST_REQUIRE( utf8::is_digit("5") );
	BOOST_TEST_REQUIRE( utf8::is_digit("0") );
	
	BOOST_TEST_REQUIRE( ! utf8::is_digit("A") );
	BOOST_TEST_REQUIRE( ! utf8::is_digit("ą") );
}

BOOST_AUTO_TEST_CASE( utf8_is_numeric ) {
	BOOST_TEST_REQUIRE( utf8::is_numeric("1") );
	BOOST_TEST_REQUIRE( utf8::is_numeric("5") );
	BOOST_TEST_REQUIRE( utf8::is_numeric("0") );
	
	BOOST_TEST_REQUIRE( ! utf8::is_numeric("A") );
	BOOST_TEST_REQUIRE( ! utf8::is_numeric("ą") );
}

BOOST_AUTO_TEST_CASE( utf8_is_print ) {
	BOOST_TEST_REQUIRE( utf8::is_print("A") );
	BOOST_TEST_REQUIRE( utf8::is_print("a") );
	BOOST_TEST_REQUIRE( utf8::is_print("2") );
	
	BOOST_TEST_REQUIRE( ! utf8::is_print("\x05") );
}

BOOST_AUTO_TEST_CASE( utf8_is_space ) {
	BOOST_TEST_REQUIRE( utf8::is_space(" ") );
	BOOST_TEST_REQUIRE( utf8::is_space("\t") );
	BOOST_TEST_REQUIRE( utf8::is_space("\n") );
	
	BOOST_TEST_REQUIRE( ! utf8::is_space("A") );
	BOOST_TEST_REQUIRE( ! utf8::is_space("ą") );
}

BOOST_AUTO_TEST_CASE( utf8_is_lower_case ) {
	BOOST_TEST_REQUIRE( utf8::is_lower_case("a") );
	BOOST_TEST_REQUIRE( utf8::is_lower_case("ą") );
	
	BOOST_TEST_REQUIRE( ! utf8::is_lower_case("A") );
	BOOST_TEST_REQUIRE( ! utf8::is_lower_case("Ą") );
}

BOOST_AUTO_TEST_CASE( utf8_is_upper_case ) {
	BOOST_TEST_REQUIRE( utf8::is_upper_case("A") );
	BOOST_TEST_REQUIRE( utf8::is_upper_case("Ą") );
	
	BOOST_TEST_REQUIRE( ! utf8::is_upper_case("a") );
	BOOST_TEST_REQUIRE( ! utf8::is_upper_case("ą") );
}

BOOST_AUTO_TEST_CASE( utf8_is_title_case ) {
	BOOST_TEST_REQUIRE( utf8::is_title_case("A") );
	BOOST_TEST_REQUIRE( utf8::is_title_case("Ą") );
	
	BOOST_TEST_REQUIRE( ! utf8::is_title_case("a") );
	BOOST_TEST_REQUIRE( ! utf8::is_title_case("ą") );
}
