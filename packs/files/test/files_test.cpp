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
#define BOOST_TEST_MODULE files_test
#include <boost/test/unit_test.hpp>

#include "../src/files.hpp"

BOOST_AUTO_TEST_CASE( file_existence ) {
	auto this_file = files::Path(__FILE__, true);
	
	BOOST_TEST_REQUIRE( this_file.exists() );
	BOOST_TEST_REQUIRE( !((this_file / "nothing").exists()) );
}

BOOST_AUTO_TEST_CASE( file_access ) {
	auto this_file = files::Path(__FILE__, true);
	
	BOOST_TEST_REQUIRE( this_file.is(files::READABLE) );
	BOOST_TEST_REQUIRE( this_file.is(files::WRITEABLE) );
	if constexpr (files::IS_POSIX) {
		BOOST_TEST_REQUIRE( ! this_file.is(files::EXECUTABLE) );
	}
}

BOOST_AUTO_TEST_CASE( file_type ) {
	auto this_file = files::Path(__FILE__, true);
	
	BOOST_TEST_REQUIRE( this_file.is(files::A_FILE) );
	BOOST_TEST_REQUIRE( this_file.is(files::A_REGULAR_FILE) );
	BOOST_TEST_REQUIRE( ! this_file.is(files::A_DIR) );
	BOOST_TEST_REQUIRE( ! this_file.is(files::A_BLOCK) );
	BOOST_TEST_REQUIRE( ! this_file.is(files::A_CHAR) );
	BOOST_TEST_REQUIRE( ! this_file.is(files::A_FIFO) );
	BOOST_TEST_REQUIRE( ! this_file.is(files::A_SOCKET) );
	BOOST_TEST_REQUIRE( ! this_file.is(files::A_LINK) );
}

BOOST_AUTO_TEST_CASE( relative_path ) {
	using namespace files::literals;
	auto test_path = "the_test"_path;
	auto cwd_path = "."_path.absolute();
	auto rel_path = cwd_path / test_path;
	
	BOOST_TEST_REQUIRE( (rel_path.relative_to(cwd_path) == test_path) );
}

BOOST_AUTO_TEST_CASE( touch_and_remove ) {
	auto tmp_file = files::get_tmp_dir() / "test_file";
	
	tmp_file.touch();
	BOOST_TEST_REQUIRE( tmp_file.exists() );
	tmp_file.remove(false);
	BOOST_TEST_REQUIRE( ! tmp_file.exists() );
}

#ifdef APP_SYSTEM_IS_MSWIN
BOOST_AUTO_TEST_CASE( invalid_filenames ) {
	auto this_file = files::Path(__FILE__, true);
	auto invalid_name = this_file / "ign?or*";
	
	BOOST_TEST_REQUIRE( this_file.is_valid() );
	BOOST_TEST_REQUIRE( ! invalid_name.is_valid() );
}
#endif

