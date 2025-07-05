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
#ifndef FELIXS_PACK_FILES
#define FELIXS_PACK_FILES

#include <filesystem>
#include <string>
#include <compare>

namespace files {
	
	#ifdef APP_SYSTEM_IS_MSWIN
	constexpr bool IS_POSIX = false;
	#else
	constexpr bool IS_POSIX = true;
	#endif
	
	enum Perms {
		READABLE,
		WRITEABLE,
		EXECUTABLE
	};
	
	enum FileType {
		A_FILE,
		A_DIR,
		A_REGULAR_FILE,
		A_BLOCK,
		A_CHAR,
		A_FIFO,
		A_SOCKET,
		A_LINK
	};
	
	enum class AttributeState : unsigned char {
		SET,
		UNSET,
		NOT_IMPLEMENTED,
		FILE_DOES_NOT_EXIST
	};
	
	enum class SpecialAttribute {
		ARCHIVE, //mswin
		HIDDEN, //mswin
		SYSTEM, //mswin
		READ_ONLY, //mswin
		COMPRESSED, //mswin
		ENCRYPTED, //mswin
		NOT_INDEXED, //mswin
		OFFLINE, //mswin
		SPARSE, //mswin
		TEMPORARY, //mswin
		IMMUTABLE, //linux
		APPEND_ONLY, //linux
		SYNC_WRITE, //linux
		NO_UPDATE_ACCESS_TIME, //linux
		NO_DUMP, //linux
		NO_SYMLINKS //linux
	};
	
	class Path {
	private:
		std::filesystem::path path_obj;
	public:
		Path() noexcept;
		explicit Path(const std::filesystem::path& from_path) noexcept;
		explicit Path(const std::string& from_str, bool is_native = false) noexcept;
		explicit Path(const char* from_pstr, bool is_native = false) noexcept;
		Path(const Path& other) noexcept;
		Path(Path&& other) noexcept;
		
		Path& operator=(const Path& other) noexcept;
		Path& operator=(Path&& other) noexcept;
		
		[[nodiscard]]
		#ifdef APP_SYSTEM_IS_MSWIN
		const wchar_t *
		#else
		const char *
		#endif
			native() const noexcept;
		
		[[nodiscard]] std::string str() const noexcept;
		[[nodiscard]] std::filesystem::path path() const noexcept;
		[[nodiscard]] size_t hash() const noexcept;
		
		[[nodiscard]] Path parent() const noexcept;
		[[nodiscard]] Path absolute(bool strict = true) const noexcept;
		[[nodiscard]] Path relative_to(const Path& other) const noexcept;
		
		[[nodiscard]] bool empty() const noexcept;
		[[nodiscard]] bool exists() const noexcept;
		[[nodiscard]] bool is(Perms perm) const noexcept;
		[[nodiscard]] bool is(FileType f_type) const noexcept;
		[[nodiscard]] AttributeState get_special_attr(SpecialAttribute attr) const noexcept;
		/// checks if path contains only valid characters
		[[nodiscard]] bool is_valid() const noexcept;
		
		void touch() const noexcept;
		bool mkdir(bool recursive = true) const noexcept;
		
		bool remove(bool recursive = false) const noexcept;
		
		Path& operator/=(const Path& other) noexcept;
		Path& operator/=(const std::string& other) noexcept;
		Path& operator+=(const std::string& other) noexcept;
		friend Path operator/(const Path&, const Path&) noexcept;
		friend Path operator/(const Path&, const std::string&) noexcept;
		friend Path operator+(const Path&, const std::string&) noexcept;
		
		friend bool operator==(const Path&, const Path&) noexcept;
		friend bool operator!=(const Path&, const Path&) noexcept;
		friend std::strong_ordering operator<=>(const Path&, const Path&) noexcept;
	};//! class Path
	
	[[nodiscard]] Path operator/(const Path& lhs, const Path& rhs) noexcept;
	[[nodiscard]] Path operator/(const Path& lhs, const std::string& rhs) noexcept;
	[[nodiscard]] Path operator+(const Path& lhs, const std::string& rhs) noexcept;
	
	[[nodiscard]] bool operator==(const Path& lhs, const Path& rhs) noexcept;
	[[nodiscard]] bool operator!=(const Path& lhs, const Path& rhs) noexcept;
	[[nodiscard]] std::strong_ordering operator<=>(const Path& lhs, const Path& rhs) noexcept;
	
	[[nodiscard]] Path get_cwd() noexcept;
	[[nodiscard]] Path get_tmp_dir() noexcept;
	[[nodiscard]] Path get_exe_path(bool full = true) noexcept;
	
	namespace literals {
		
		inline Path operator""_path(const char* l, size_t s) {
			return Path(std::string(l,s), false);
		}
		
		inline Path operator""_npath(const char* l, size_t s) {
			return Path(std::string(l,s), true);
		}
		
	}
	
}//! namespace files

namespace std {
	
	template<>
	struct hash<files::Path> {
		size_t operator()(const files::Path& p) const {
			return p.hash();
		}
	};
	
}//! namespace std

#endif //! FELIXS_PACK_FILES

