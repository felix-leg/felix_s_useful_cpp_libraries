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

/**
  * USAGE: if you want to disable some diagnostics from a compiler
  * then, before the section you want to "protect" put:
  * 	#define THE_DISABLE_MACRO_YOU_WANT
  * 	#include "disable_diag.hpp"
  * and after the section put:
  * 	#define THE_REENABLE_PART_OF_THE_DISABLE_MACRO
  * 	#include "disable_diag.hpp"
  */

#ifdef DISABLE_FLOAT_EQUAL_WARN
	#if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wfloat-equal"
	#endif
	#undef DISABLE_FLOAT_EQUAL_WARN
#endif
#ifdef REENABLE_FLOAT_EQUAL_WARN
	#if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
		#pragma GCC diagnostic pop
	#endif
	#undef REENABLE_FLOAT_EQUAL_WARN
#endif

#ifdef DISABLE_DOC_WARN
	#if defined(__clang__)
		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wdocumentation"
	#endif
	#undef DISABLE_DOC_WARN
#endif
#ifdef REENABLE_DOC_WARN
	#if defined(__clang__)
		#pragma GCC diagnostic pop
	#endif
	#undef REENABLE_DOC_WARN
#endif

