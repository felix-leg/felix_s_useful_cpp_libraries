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
#ifndef FELIXS_PACK_MATH_UTILS_MOD_HPP
#define FELIXS_PACK_MATH_UTILS_MOD_HPP

#include <concepts>
#include <cmath>

namespace math {
	
	/*
	Truncated modulo:
	
		r = a - b * trunc(a/b)
	where: trunc(1.6) = 1 and trunc(-1.6) = -1
	
	Gives:
		 8 mod 5    = 3
		-8 mod 5    = -3
		 8 mod (-5) = 3
		-8 mod (-5) = -3
	
	Used in: C, C++, C#, Go, JavaScript, PHP, Swift, Visual Basic
	*/
	template<std::integral Int>
	Int trunc_mod(Int a, Int b) {
		return a - b * static_cast<Int>(static_cast<double>(a) / static_cast<double>(b));
	}
	
	
	/*
	Floor modulo:
	
		r = a - b * floor(a/b)
	
	Gives:
		 8 mod 5    = 3
		-8 mod 5    = 2
		 8 mod (-5) = -2
		-8 mod (-5) = -3
	
	Used in: Python, Lua, Perl, R, Ruby, Scratch, TCL, common spreadsheet apps
	*/
	template<std::integral Int>
	Int floor_mod(Int a, Int b) {
		return a - b * static_cast<Int>(std::floor(static_cast<double>(a) / static_cast<double>(b)));
	}
	
	
	/*
	Rounding modulo:
	
		r = a - b * round(a/b)
	
	Gives:
		 8 mod 5    = -2
		-8 mod 5    = 2
		 8 mod (-5) = -2
		-8 mod (-5) = 2
	
	Used in: C (within `remainder()` function)
	*/
	template<std::integral Int>
	Int round_mod(Int a, Int b) {
		return a - b * static_cast<Int>(std::round(static_cast<double>(a) / static_cast<double>(b)));
	}
	
	
	/*
	Euclid modulo (by R. T. Boute):
	
		r = a - |b| * floor(a/|b|)
	
	Gives:
		 8 mod 5    = 3
		-8 mod 5    = 2
		 8 mod (-5) = 3
		-8 mod (-5) = 2
	
	Used in: Dart, ABAP, Maple, Pascal (some implementations)
	*/
	template<std::integral Int>
	Int euclid_mod(Int a, Int b) {
		return a - std::abs(b) * static_cast<Int>(std::floor(static_cast<double>(a) / static_cast<double>(std::abs(b))));
	}
	
	
	
	// --------------- Transformations ---------------
	
	
	
	/*
	Algorithm E:
		
		r = r_T + I * b
		where:
		    ╭  0    if r_T >= 0
		I = ┤  1    if r_T < 0 and b > 0
		    ╰ -1    if r_T < 0 and b < 0
		r_T = trunc_mod(a,b)
	*/
	template<std::integral Int>
	Int E_mod(Int a, Int b) {
		auto r = trunc_mod(a,b);
		if( r < Int(0) ) {
			if( b > Int(0) ) {
				r += b;
			} else {
				r -= b;
			}
		}
		return r;
	}
	
	
	/*
	Algorithm F:
		
		r = r_T + I * b
		where:
		    ╭  1    if signum(r_T) != signum(b)
		I = ┤  
		    ╰ 0    otherwise
		r_T = trunc_mod(a,b)
		signum(n) = returns the sign of n
	*/
	template<std::integral Int>
	Int F_mod(Int a, Int b) {
		auto r = trunc_mod(a,b);
		if( (r > 0 && b < 0) || (r < 0 && b > 0) ) {
			r += b;
		}
		return r;
	}
	
};//! namespace math

#endif //! FELIXS_PACK_MATH_UTILS_MOD_HPP
