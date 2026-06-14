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
#if __has_include(<simd>)
#	include <simd>
#	define HAS_SIMD
#endif

#ifdef HAS_SIMD
namespace simd {
	using vec2 = std::simd::vec<float, 2>;
	using vec3 = std::simd::vec<float, 3>;
	using vec4 = std::simd::vec<float, 4>;
	
	using std::simd::reduce;
}
# define SIMD_INIT2(var,val1,val2) do { float load[2] = {(val1),(val2)}; var = ::simd::vec2{load}; } while(false)
# define SIMD_INIT3(var,val1,val2,val3) do { float load[3] = {(val1),(val2),(val3)}; var = ::simd::vec3{load}; } while(false)
# define SIMD_INIT4(var,val1,val2,val3,val4) do { float load[4] = {(val1),(val2),(val3),(val4)}; var = ::simd::vec4{load}; } while(false)
#endif
