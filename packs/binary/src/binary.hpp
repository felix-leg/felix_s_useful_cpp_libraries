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
#pragma once
#ifndef FELIXS_PACK_BINARY
#define FELIXS_PACK_BINARY

#include <cstdint>
#include <initializer_list>
#include <span>
#include <string>

class binary {
	private:
		uint8_t* bin_data;
		size_t bin_len;
	public:
		explicit(false) binary() noexcept;
		explicit(true) binary(const uint8_t* ptr, const size_t len) noexcept;
		binary(std::initializer_list<uint8_t> l) noexcept;
		binary(const binary& other) noexcept;
		binary(binary&& other) noexcept;
		binary& operator=(const binary& other) noexcept;
		binary& operator=(binary&& other) noexcept;
		~binary();
		
		[[nodiscard]] static binary zeroes(size_t len) noexcept;
		[[nodiscard]] static binary move_into(uint8_t* ptr, size_t len) noexcept;
		
		// @group Basic set
		// @{
		[[nodiscard]] bool is_empty() const noexcept;
		[[nodiscard]] size_t length() const noexcept;
		[[nodiscard]] uint8_t* data() noexcept;
		[[nodiscard]] const uint8_t* data() const noexcept;
		[[nodiscard]] std::string to_hex_string(bool upper = false) const noexcept;
		[[nodiscard]] std::string to_bin_string() const noexcept;
		[[nodiscard]] std::string stringify() const noexcept;
		// @}
		
		// @group Casting
		// @{
		template<typename OUT>
		[[nodiscard]] OUT* as_ptr() noexcept {
			return reinterpret_cast<OUT*>(bin_data);
		}
		template<typename OUT>
		[[nodiscard]] const OUT* as_ptr() const noexcept {
			return reinterpret_cast<const OUT*>(bin_data);
		}
		
		template<typename OUT = uint8_t>
		[[nodiscard]] std::span<OUT> as_span() noexcept {
			return std::span<OUT>(reinterpret_cast<OUT*>(bin_data), bin_len / sizeof(OUT));
		}
		
		template<typename OUT>
		[[nodiscard]] OUT& as() {
			return * reinterpret_cast<OUT*>(bin_data);
		}
		template<typename OUT>
		[[nodiscard]] const OUT& as() const {
			return * reinterpret_cast<const OUT*>(bin_data);
		}
		// @}
		
		// @group Value access
		// @{
		uint8_t& at(size_t index);
		const uint8_t& at(size_t index) const;
		
		uint8_t get(size_t index, uint8_t default_value) const noexcept;
		bool set(size_t index, uint8_t value) noexcept;
		// @}
		
		// @group Iterators
		// @{
		uint8_t* begin() noexcept;
		const uint8_t* begin() const noexcept;
		
		uint8_t* end() noexcept;
		const uint8_t* end() const noexcept;
		// @}
		
		// @group Operators
		// @{
		friend binary operator+(const binary& lhs, const binary& rhs) noexcept;
		friend binary operator*(const binary& bm, int mul) noexcept;
		friend binary operator*(int mul, const binary& bm) noexcept;
		binary& operator+=(const binary& add) noexcept;
		binary& operator*=(int mul) noexcept;
		// @}
};

#endif //! FELIXS_PACK_BINARY
