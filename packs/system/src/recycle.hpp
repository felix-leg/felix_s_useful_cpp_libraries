#pragma once
#ifndef FELIXS_PACK_SYSTEM_RECYCLE_HPP
#define FELIXS_PACK_SYSTEM_RECYCLE_HPP
#include <filesystem>

[[nodiscard]] bool move_to_bin(const std::filesystem::path& file_path) noexcept;

#endif //! FELIXS_PACK_SYSTEM_RECYCLE_HPP

