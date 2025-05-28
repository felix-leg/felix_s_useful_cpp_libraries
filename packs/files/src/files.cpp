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
#include "files.hpp"

#include <utility>
#ifdef APP_SYSTEM_IS_MSWIN
	#include <io.h>
	#define WIN32_LEAN_AND_MEAN
	#define NOMINMAX
	#include <windows.h>
#else
	#ifdef APP_SYSTEM_IS_LINUX
		#include <linux/limits.h>
	#endif
	#include <unistd.h>
#endif

#include <cstdio>

namespace files {
	
	Path::Path() noexcept : path_obj{} {}
	
	Path::Path(const std::filesystem::path& from_path) noexcept : path_obj{from_path} {}
	
	Path::Path(const std::string& from_str, bool is_native) noexcept :
		path_obj{
			from_str,
			is_native ? std::filesystem::path::format::native_format :
				std::filesystem::path::format::generic_format
		} {}
	
	Path::Path(const char* from_pstr, bool is_native) noexcept
		: Path(std::string(from_pstr), is_native) {}
	
	Path::Path(const Path& other) noexcept : path_obj{other.path_obj} {}
	
	Path::Path(Path&& other) noexcept : path_obj{std::move(other.path_obj)} {}
	
	Path& Path::operator=(const Path& other) noexcept {
		if( this != &other )
			path_obj = other.path_obj;
		return *this;
	}
	
	Path& Path::operator=(Path&& other) noexcept {
		if( this != &other )
			path_obj = std::move(other.path_obj);
		return *this;
	}
	
	#ifdef APP_SYSTEM_IS_MSWIN
	const wchar_t *
	#else
	const char *
	#endif
	Path::native() const noexcept {
		return path_obj.c_str();
	}
	
	std::string Path::str() const noexcept {
		return path_obj.generic_string();
	}
	
	std::filesystem::path Path::path() const noexcept {
		return path_obj;
	}
	
	size_t Path::hash() const noexcept {
		std::hash<std::filesystem::path> hash_fn;
		return hash_fn(path_obj);
	}
	
	Path Path::parent() const noexcept {
		return Path(path_obj.parent_path());
	}
	
	Path Path::absolute(bool strict) const noexcept {
		if( path_obj.is_absolute() ) {
			return *this;
		}
		if( path_obj.empty() ) {
			auto pp = std::filesystem::path(".", std::filesystem::path::format::generic_format);
			if( strict ) {
				return Path(std::filesystem::canonical(pp));
			}
			pp = std::filesystem::absolute(pp);
			return Path(pp.parent_path());
		}
		
		if( strict ) {
			return Path(std::filesystem::canonical(path_obj));
		} else {
			return Path(std::filesystem::absolute(path_obj));
		}
	}
	
	Path Path::relative_to(const Path& other) const noexcept {
		return Path(std::filesystem::relative(path_obj, other.path_obj));
	}
	
	bool Path::empty() const noexcept {
		return path_obj.empty();
	}
	
	bool Path::exists() const noexcept {
		return std::filesystem::exists(path_obj);
	}
	
	bool Path::is(Perms perm) const noexcept {
		if( ! exists() ) { return false; }
		#ifdef APP_SYSTEM_IS_MSWIN
		int mode;
		switch( perm ) {
			case READABLE:
				mode = 4;
				break;
			case WRITEABLE:
				mode = 2;
				break;
			case EXECUTABLE:
				return true; //impossible to check on MS Windows
			default:
				std::unreachable();
		}
		return (_waccess(native(), mode) != -1);
		#else
		int mode;
		switch( perm ) {
			case READABLE:
				mode = R_OK;
				break;
			case WRITEABLE:
				mode = W_OK;
				break;
			case EXECUTABLE:
				mode = X_OK;
				break;
			default:
				std::unreachable();
		}
		return (access(native(), mode) == 0);
		#endif
	}
	
	bool Path::is(FileType f_type) const noexcept {
		if( ! exists() ) { return false; }
		switch( f_type ) {
			case A_FILE:
				return ! std::filesystem::is_directory(path_obj);
			case A_DIR:
				return std::filesystem::is_directory(path_obj);
			case A_REGULAR_FILE:
				return std::filesystem::is_regular_file(path_obj);
			case A_BLOCK:
				return std::filesystem::is_block_file(path_obj);
			case A_CHAR:
				return std::filesystem::is_character_file(path_obj);
			case A_FIFO:
				return std::filesystem::is_fifo(path_obj);
			case A_SOCKET:
				return std::filesystem::is_socket(path_obj);
			case A_LINK:
				return std::filesystem::is_symlink(path_obj);
		}
		std::unreachable();
	}
	
	bool is_valid_name(const std::filesystem::path& elem) {
		#ifdef APP_SYSTEM_IS_MSWIN
		static const wchar_t FORBIDDEN_CHARACTERS[] = {
			0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
			11, 12, 13, 14, 15, 16, 17, 18, 19,
			20, 21, 22, 23, 24, 25, 26, 27, 28,
			29, 30, 31, L'\\', L'/', L'<', L'>', L':',
			L'"', L'|', L'?', L'*'
		};
		std::wstring name{elem.native()};
		
		if(name[name.size()-1] == L' ' || name[name.size()-1] == L'.') {
			// Filename shouldn't end with space or dot on MS Windows
			return false;
		}
		
		for (wchar_t c : FORBIDDEN_CHARACTERS) {
			if (name.find(c) != std::wstring::npos)
				return false;
		}
		return true;
		#else
		static const char FORBIDDEN_CHARACTERS[] = {
			0, '/'
			/*
			'#', '$', '%', '!', '&', '\'', '"', '{', '}',
			':', '\\', '@', '<', '>', '+', '`', '*', '|',
			'?', '=', '/' //*/
		};
		std::string name{elem.native()};
		
		for (char c : FORBIDDEN_CHARACTERS) {
			if (name.find(c) != std::string::npos)
				return false;
		}
		return true;
		#endif
	}
	
	bool Path::is_valid() const noexcept {
		auto pp = path_obj.relative_path();
		for(auto elem : pp) {
			if( elem.empty() ) continue;
			if( ! is_valid_name(elem) ) return false;
		}
		return true;
	}
	
	void Path::touch() const noexcept {
		if( exists() ) { return; }
		parent().mkdir(true);
		
		#ifdef APP_SYSTEM_IS_MSWIN
		std::FILE * f = _wfopen(native(), L"wb");
		#else
		std::FILE * f = std::fopen(native(), "wb");
		#endif
		std::fclose(f);
	}
	
	bool Path::mkdir(bool recursive) const noexcept try {
		if( recursive ) {
			return std::filesystem::create_directories(path_obj);
		} else {
			return std::filesystem::create_directory(path_obj);
		}
	}
	catch(const std::filesystem::filesystem_error& e) {
		return false;
	}
	
	bool Path::remove(bool recursive) const noexcept try {
		if( recursive ) {
			std::uintmax_t removed = std::filesystem::remove_all(path_obj);
			return (removed != 0);
		} else {
			return std::filesystem::remove(path_obj);
		}
	}
	catch(const std::filesystem::filesystem_error& e) {
		return false;
	}
	
	Path& Path::operator/=(const Path& other) noexcept {
		path_obj /= other.path_obj;
		return *this;
	}
	
	Path& Path::operator/=(const std::string& other) noexcept {
		path_obj /= other;
		return *this;
	}
	
	Path& Path::operator+=(const std::string& other) noexcept {
		path_obj += other;
		return *this;
	}
	
	Path operator/(const Path& lhs, const Path& rhs) noexcept {
		return Path(lhs.path_obj / rhs.path_obj);
	}
	
	Path operator/(const Path& lhs, const std::string& rhs) noexcept {
		return Path(lhs.path_obj / rhs);
	}
	
	Path operator+(const Path& lhs, const std::string& rhs) noexcept {
		auto r = lhs.path_obj;
		r += rhs;
		return Path(r);
	}
	
	bool operator==(const Path& lhs, const Path& rhs) noexcept {
		return lhs.path_obj == rhs.path_obj;
	}
	
	bool operator!=(const Path& lhs, const Path& rhs) noexcept {
		return !(lhs.path_obj == rhs.path_obj);
	}
	
	std::strong_ordering operator<=>(const Path& lhs, const Path& rhs) noexcept {
		return (lhs.path_obj <=> rhs.path_obj);
	}
	
	Path get_cwd() noexcept try {
		return Path(std::filesystem::current_path());
	}
	catch(const std::filesystem::filesystem_error& e) {
		return Path();
	}
	
	Path get_tmp_dir() noexcept try {
		return Path(std::filesystem::temp_directory_path());
	}
	catch(const std::filesystem::filesystem_error& e) {
		return Path();
	}
	
	#ifdef APP_SYSTEM_IS_MSWIN
	std::string mswin_to_utf8(const wchar_t* from_ptr, DWORD from_size) noexcept {
		char* result = nullptr;
		int required_size = WideCharToMultiByte(
			CP_UTF8, 0, from_ptr, from_size,
			nullptr, 0, nullptr, nullptr
		);
		if( required_size > 0 ) {
			result = new char[required_size];
			int status = WideCharToMultiByte(
				CP_UTF8, 0, from_ptr, from_size,
				result, required_size, nullptr, nullptr
			);
			if( status == 0 ) {//error
				delete[] result;
				return "";
			} else {
				std::string result_str{result, static_cast<uint64_t>(required_size)};
				delete[] result;
				return result_str;
			}
		} else { //conversion error
			return "";
		}
	}
	#endif
	
	Path get_exe_path(bool full) noexcept {
		#ifdef APP_SYSTEM_IS_MSWIN
		wchar_t w_result[ MAX_PATH ];
		DWORD result_size = GetModuleFileNameW( nullptr, w_result, MAX_PATH );
		auto result = std::filesystem::path(mswin_to_utf8(w_result, result_size), std::filesystem::path::format::native_format);
		#else
		char c_result[ PATH_MAX ];
		ssize_t count = readlink( "/proc/self/exe", c_result, PATH_MAX ); //Linux
		if( count == -1 ) {
			count = readlink( "/proc/curproc/file", c_result, PATH_MAX ); //FreeBSD
			if( count == -1 ) {
				count = readlink( "/proc/self/path/a.out", c_result, PATH_MAX ); //Solaris
				if( count == -1 ) {
					count = 0; //give up
				}
			}
		}
		
		auto result = std::filesystem::path(
			std::string( c_result, count ),
			std::filesystem::path::format::native_format
		);
		#endif
		
		if( ! full ) {
			result = result.parent_path();
		}
		return Path( result );
	}
	
}//! namespace files
