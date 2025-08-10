#include "trim.hpp"

#include "checks.hpp"

namespace ascii {
	
	std::string_view ltrim(std::string_view text) noexcept {
		for(size_t i=0; i<text.length(); ++i) {
			if( ! ascii::is_space(text[i]) ) {
				text.remove_prefix(i);
				return text;
			}
		}
		return std::string_view("");
	}
	
	std::string_view rtrim(std::string_view text) noexcept {
		for(size_t i=text.length(); i>0; --i) {
			if( ! ascii::is_space(text[i-1]) ) {
				text.remove_suffix(text.length() - i);
				return text;
			}
		}
		return std::string_view("");
	}
	
	std::string_view trim(std::string_view text) noexcept {
		size_t i;
		
		for(i=0; i<text.length(); ++i) {
			if( ! ascii::is_space(text[i]) ) {
				text.remove_prefix(i);
				break;
			}
		}
		if( i == text.length() ) { return std::string_view(""); }
		
		for(i=text.length(); i>0; --i) {
			if( ! ascii::is_space(text[i-1]) ) {
				text.remove_suffix(text.length() - i);
				break;
			}
		}
		
		return text;
	}
	
} //! namespace ascii
