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
#include "halfturn.h"

#include <math.h>

float sin_ht(float turns) {
	#if __STDC_VERSION__ >= 202311L
	return sinpif(turns * 2);
	#else
	return sin(turns * 2 * acos(-1));
	#endif
}

float cos_ht(float turns) {
	#if __STDC_VERSION__ >= 202311L
	return cospif(turns * 2);
	#else
	return cos(turns * 2 * acos(-1));
	#endif
}

float tan_ht(float turns) {
	return sin_ht(turns) / cos_ht(turns);
}

bool can_use_c23() {
	#if __STDC_VERSION__ >= 202311L
	return true;
	#else
	return false;
	#endif
}

