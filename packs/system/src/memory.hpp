#pragma once
#ifndef FELIXS_PACK_SYSTEM_MEMORY_HPP
#define FELIXS_PACK_SYSTEM_MEMORY_HPP

namespace memory {
	
	[[nodiscard]] unsigned long long get_free_RAM() noexcept;
	[[nodiscard]] unsigned long long get_total_RAM() noexcept;
	
	constexpr unsigned long long KB(unsigned long long kb_m) {
		return kb_m * 1024ull;
	}
	constexpr unsigned long long MB(unsigned long long mb_m) {
		return mb_m * 1024ull * 1024ull;
	}
	constexpr unsigned long long GB(unsigned long long gb_m) {
		return gb_m * 1024ull * 1024ull * 1024ull;
	}
	constexpr unsigned long long TB(unsigned long long tb_m) {
		return tb_m * 1024ull * 1024ull * 1024ull * 1024ull;
	}
	
	constexpr double as_KB(unsigned long long kb_m) {
		return kb_m / static_cast<double>(1024ull);
	}
	constexpr double as_MB(unsigned long long mb_m) {
		return mb_m / static_cast<double>(1024ull * 1024ull);
	}
	constexpr double as_GB(unsigned long long gb_m) {
		return gb_m / static_cast<double>(1024ull * 1024ull * 1024ull);
	}
	constexpr double as_TB(unsigned long long tb_m) {
		return tb_m / static_cast<double>(1024ull * 1024ull * 1024ull * 1024ull);
	}
	
} //! namespace memory

#endif //! FELIXS_PACK_SYSTEM_MEMORY_HPP

