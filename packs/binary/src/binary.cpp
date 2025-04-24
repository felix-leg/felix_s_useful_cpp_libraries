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
#include "binary.hpp"

#include <cstring>
#include <stdexcept>

#define SIZE_T_ZERO static_cast<std::size_t>(0)

binary::binary() noexcept : bin_data{nullptr}, bin_len{SIZE_T_ZERO} {}

binary::binary(const unsigned char* ptr, size_t len) noexcept {
	if( len == SIZE_T_ZERO || ptr == nullptr ) {
		bin_len = SIZE_T_ZERO;
		bin_data = nullptr;
	} else {
		bin_data = new unsigned char[len];
		bin_len = len;
		std::memcpy(bin_data, ptr, len);
	}
}

binary::binary(std::initializer_list<unsigned char> l) noexcept {
	if( std::empty(l) ) {
		bin_len = SIZE_T_ZERO;
		bin_data = nullptr;
	} else {
		bin_len = l.size();
		bin_data = new unsigned char[bin_len];
		size_t i = SIZE_T_ZERO;
		for(unsigned char v : l) {
			bin_data[i++] = v;
		}
	}
}

binary::binary(const binary& other) noexcept : bin_len{other.bin_len} {
	if( bin_len == SIZE_T_ZERO || other.bin_data == nullptr ) {
		bin_data = nullptr;
	} else {
		bin_data = new unsigned char[bin_len];
		std::memcpy(bin_data, other.bin_data, bin_len);
	}
}

binary::binary(binary&& other) noexcept : bin_data{other.bin_data}, bin_len{other.bin_len} {
	other.bin_data = nullptr;
	other.bin_len = SIZE_T_ZERO;
}

binary& binary::operator=(const binary& other) noexcept {
	if( this == &other ) return *this;

	delete[] bin_data;
	bin_len = other.bin_len;
	if( bin_len == SIZE_T_ZERO || other.bin_data == nullptr ) {
		bin_data = nullptr;
	} else {
		bin_data = new unsigned char[bin_len];
		std::memcpy(bin_data, other.bin_data, bin_len);
	}

	return *this;
}

binary& binary::operator=(binary&& other) noexcept {
	if( this == &other ) return *this;

	delete[] bin_data;
	bin_len = other.bin_len;
	bin_data = other.bin_data;

	other.bin_data = nullptr;
	other.bin_len = SIZE_T_ZERO;

	return *this;
}

binary::~binary() {
	delete[] bin_data;
}

binary binary::zeroes(size_t len) noexcept {
	binary output{};
	output.bin_len = len;
	output.bin_data = new unsigned char[len];
	std::memset(output.bin_data, 0, len);

	return output;
}

binary binary::move_into(unsigned char* ptr, size_t len) noexcept {
	binary output{};
	output.bin_len = len;
	output.bin_data = ptr;
	return output;
}

//-----------Basic operations------------

bool binary::is_empty() const noexcept {
	return (bin_data == nullptr);
}

size_t binary::length() const noexcept {
	return bin_len;
}

unsigned char* binary::data() noexcept {
	return bin_data;
}

const unsigned char* binary::data() const noexcept {
	return bin_data;
}

std::string binary::to_hex_string(bool upper) const noexcept {
	if( bin_len == SIZE_T_ZERO || bin_data == nullptr) {
		return "";
	}
	const size_t out_size = bin_len * 2 + (bin_len - 1);
	std::string output{out_size, ' ', std::string::allocator_type()};
	bool skip_space = false;
	std::size_t out_pos = SIZE_T_ZERO;
	
	const auto digits = (upper ?
		"0123456789ABCDEF" :
		"0123456789abcdef"
	);
	
	for(size_t i=SIZE_T_ZERO; i<bin_len; ++i) {
		if( skip_space ) {
			++out_pos;
		}
		output[out_pos++] = digits[ (bin_data[i] >> 4) & 0x0F ];
		output[out_pos++] = digits[ bin_data[i] & 0x0F ];
		skip_space = true;
	}
	
	return output;
}

std::string binary::to_bin_string() const noexcept {
	if( bin_len == SIZE_T_ZERO || bin_data == nullptr) {
		return "";
	}
	const size_t out_size = bin_len * 8 + (bin_len - 1);
	std::string output{out_size, ' ', std::string::allocator_type()};
	bool skip_space = false;
	size_t out_pos = SIZE_T_ZERO;
	
	for(std::size_t i=SIZE_T_ZERO; i<bin_len; ++i) {
		if( skip_space ) {
			++out_pos;
		}
		for(int b=0; b<8; ++b) {
			output[out_pos++] = ((bin_data[i] << b) & 0x80) ? '1' : '0';
		}
		skip_space = true;
	}
	
	return output;
}

//-----------Accessors------------

unsigned char& binary::at(size_t index) {
	if( index >= bin_len ) {
		throw std::out_of_range{"index"};
	}
	return bin_data[index];
}

const unsigned char& binary::at(size_t index) const {
	if( index >= bin_len ) {
		throw std::out_of_range{"index"};
	}
	return bin_data[index];
}

unsigned char binary::get(size_t index, unsigned char default_value) const noexcept {
	if( index >= bin_len ) {
		return default_value;
	} else {
		return bin_data[index];
	}
}

bool binary::set(size_t index, unsigned char value) noexcept {
	if( index >= bin_len ) {
		return false;
	} else {
		bin_data[index] = value;
		return true;
	}
}

// --------------Iterators--------------

unsigned char* binary::begin() noexcept {
	return bin_data;
}

const unsigned char* binary::begin() const noexcept {
	return bin_data;
}

unsigned char* binary::end() noexcept {
	return bin_data + bin_len;
}

const unsigned char* binary::end() const noexcept {
	return bin_data + bin_len;
}

// --------------Operators--------------

binary operator+(const binary& lhs, const binary& rhs) noexcept {
	const auto new_size = lhs.bin_len + rhs.bin_len;
	if( new_size == SIZE_T_ZERO ) {
		return {};
	}
	binary output{};
	output.bin_len = new_size;
	output.bin_data = new unsigned char[new_size];
	size_t pos = SIZE_T_ZERO;
	
	if( ! lhs.is_empty() ) {
		std::memcpy(output.bin_data, lhs.bin_data, lhs.bin_len);
		pos = lhs.bin_len;
	}
	if( ! rhs.is_empty() ) {
		std::memcpy( output.bin_data + pos, rhs.bin_data, rhs.bin_len);
	}
	
	return output;
}

binary operator*(const binary& bm, int mul) noexcept {
	if( bm.is_empty() || mul < 1 ) {
		return {};
	}
	binary output{};
	const auto new_size = bm.bin_len * mul;
	size_t pos = SIZE_T_ZERO;
	
	output.bin_len = new_size;
	output.bin_data = new unsigned char[new_size];
	while( pos < new_size ) {
		std::memcpy(output.bin_data + pos, bm.bin_data, bm.bin_len);
		pos += bm.bin_len;
	}
	
	return output;
}

binary operator*(int mul, const binary& bm) noexcept {
	return bm * mul;
}

binary& binary::operator+=(const binary& add) noexcept {
	if( add.is_empty() ) return *this;
	
	auto new_len = bin_len + add.bin_len;
	auto new_data = new unsigned char[new_len];
	size_t pos = SIZE_T_ZERO;
	
	if( bin_len > SIZE_T_ZERO ) {
		std::memcpy(new_data, bin_data, bin_len);
		pos = bin_len;
	}
	std::memcpy(new_data + pos, add.bin_data, add.bin_len);
	
	delete[] bin_data;
	bin_data = new_data;
	bin_len = new_len;
	
	return *this;
}

binary& binary::operator*=(int mul) noexcept {
	if( bin_len == SIZE_T_ZERO || bin_data == nullptr || mul < 2) {
		return *this;
	}
	
	auto new_size = bin_len * mul;
	auto new_data = new unsigned char[new_size];
	size_t pos = SIZE_T_ZERO;
	while( pos < new_size ) {
		std::memcpy( new_data + pos, bin_data, bin_len);
		pos += bin_len;
	}
	delete[] bin_data;
	bin_data = new_data;
	bin_len = new_size;
	
	return *this;
}
