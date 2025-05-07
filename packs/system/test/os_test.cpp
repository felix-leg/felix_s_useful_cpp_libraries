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

