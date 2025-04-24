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


/* ------------------- Function attributes ---------------------- */
#define FORCE_INLINE [[gnu::always_inline, clang::always_inline, msvc::forceinline]]
#define FORBID_INLINE [[gnu::noinline, clang::noinline, msvc::noinline]]

#define FN_EXEC_UNLIKELY [[gnu::cold]]
#define FN_EXEC_LIKELY [[gnu::hot]]

/// prepend line one wants clang not to warn about some violation
#define SUPPRESS_WARN [[clang::suppress]]

#ifdef APP_COMPILER_IS_MSVC
	#define DLL_IMPORT __declspec( dllimport )
	#define DLL_EXPORT __declspec( dllexport )
	// calling conventions
	#define FN_CDECL __cdecl
	#define FN_FASTCALL __fastcall
	#define FN_STDCALL __stdcall
	#define FN_THISCALL __thiscall
	#define FN_VECTORCALL __vectorcall
	
	#define PURE_FN _CRTIMP_PURE
#else
	#define DLL_IMPORT [[gnu::dllimport]]
	#define DLL_EXPORT [[gnu::dllexport]]
	// calling conventions
	#define FN_CDECL [[gnu::cdecl]]
	#define FN_FASTCALL [[gnu::fastcall]]
	#define FN_STDCALL [[gnu::stdcall]]
	#define FN_THISCALL [[gnu::thiscall]]
	#define FN_VECTORCALL [[clang::vectorcall]]
	
	#define PURE_FN [[gnu::pure]]
#endif

#ifdef APP_COMPILER_IS_CLANG
	/// if <cond> is true emit <msg> at function call (as a warning)
	#define DIAGNOSE_IF_W(cond, msg) __attribute__((diagnose_if(cond, msg, "warning")))
	/// if <cond> is true emit <msg> at function call (as an error)
	#define DIAGNOSE_IF_E(cond, msg) __attribute__((diagnose_if(cond, msg, "error")))
#else
	#define DIAGNOSE_IF_W(cond, msg)
	#define DIAGNOSE_IF_E(cond, msg)
#endif

/* ------------------- Variable attributes ---------------------- */

/** Used for vars declared with "char", "signed char" or "unsigned char"
  * when they aren't supposed to contain text data ending with
  * the NUL character.
  */
#define NON_STRING [[gnu::nonstring]]

/// This pointer variable can't be null
#define NON_NULL [[gnu::objc_nullability("nonnull")]]
/// This pointer variable can sometimes be null
#define NULLABLE [[gnu::objc_nullability("nullable")]]

/// Forbids compiler to add extra align bytes to a field
#define PACKED [[gnu::packed]]
/// Specify a precise value of alignment
#define PACKED_WITH(a) [[gnu::packed, gnu::aligned(a)]]

/// For dummy variables/parameters
#define VAR_UNUSED [[gnu::unused]]
/// This static variable/field must exist, even if it appears to be unused
#define VAR_USED [[gnu::used]]

/* ------------------- Type attributes ---------------------- */

#define PACKED_TYPE [[gnu::packed]]

#ifdef APP_COMPILER_IS_CLANG
	//must be put between "struct"/"class" keyword and the type's name
	
	#define SINGLE_INHERITANCE __single_inheritance
	#define MULTIPLE_INHERITANCE __multiple_inheritance
	#define VIRTUAL_INHERITANCE __virtual_inheritance
	#define UNSPECIFIED_INHERITANCE __unspecified_inheritance
	
	//enums
	/// variable of this type can has got only values specified by this enumeration
	#define CLOSED_ENUM __attribute__((enum_extensibility(closed)))
	/// variable of this type can sometimes has got values outside of the enumeration
	#define OPEN_ENUM __attribute__((enum_extensibility(open)))
	/// this enum specifies combinable flags. Allowed values are closed
	#define CLOSED_FLAG_ENUM __attribute__((enum_extensibility(closed),flag_enum))
	/// this enum specifies combinable flags, including values outside of specified
	#define OPEN_FLAG_ENUM __attribute__((enum_extensibility(open),flag_enum))
#else
	#define SINGLE_INHERITANCE
	#define MULTIPLE_INHERITANCE
	#define VIRTUAL_INHERITANCE
	#define UNSPECIFIED_INHERITANCE
	
	#define CLOSED_ENUM
	#define OPEN_ENUM
	#define CLOSED_FLAG_ENUM
	#define OPEN_FLAG_ENUM
#endif

#ifdef APP_COMPILER_IS_MSVC
	///use Empty Base Optimalization on MSVC when applied to classes
	#define USE_EBO __declspec(empty_bases)
	///declare a struct that shouldn't have got its own virtual table
	#define INTERFACE struct __declspec(novtable)
#else
	#define USE_EBO
	#define INTERFACE struct
#endif

/* ------------------- Statement attributes ---------------------- */

#define TAIL_RETURN [[gnu::musttail, clang::musttail]] return

/* ------------------- Standard C++ attributes ---------------------- */

// [[noreturn]]
// [[carries_dependency]]
// [[deprecated, deprecated("reason")]]
// [[fallthrough]]
// [[maybe_unused]]
// [[nodiscard, nodiscard("reason")]]
// [[likely]] [[unlikely]]
// [[no_unique_address]]
// [[assume(expression)]]
// [[indeterminate]]
// [[optimize_for_synchronized]]

/* Note:
	If you also compile on MSVC with /W3, it will fire warning 5030 (unrecognized attribute) for attributes intended for other compilers such as [[gnu::hot]], so you need to add /wd5030 (warning disable: 5030).
*/
