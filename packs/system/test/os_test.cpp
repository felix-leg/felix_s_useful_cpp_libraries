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
#define BOOST_TEST_MODULE system_test
#include <boost/test/unit_test.hpp>

#include "../src/memory.hpp"
#include "../src/recycle.hpp"
#include <fstream>
#include <filesystem>

BOOST_AUTO_TEST_CASE( total_and_free_memory ) {
	std::cout << "You have got " << memory::as_MB(memory::get_free_RAM()) << " MB of free memory" << std::endl;
	std::cout << "You have got " << memory::as_MB(memory::get_total_RAM()) << " MB of total memory" << std::endl;
}

BOOST_AUTO_TEST_CASE( trash_file ) {
	std::filesystem::path to_trash{__FILE__};
	to_trash = to_trash.parent_path();
	to_trash /= "pack_system_to_trash.txt";
	{
		std::ofstream f{to_trash};
		f << "CONTENT TO TRASH";
	}
	BOOST_TEST_REQUIRE( move_to_bin(to_trash) );
}

