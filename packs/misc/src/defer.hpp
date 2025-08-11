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
#ifndef FELIXS_PACK_MISC_DEFER_HPP
#define FELIXS_PACK_MISC_DEFER_HPP

#include <functional>

class DeferT final {
	private:
		std::function<void()> f;
		bool active;
	public:
		explicit(false) DeferT(std::function<void()> fn) noexcept;
		DeferT(const DeferT&) = delete;
		DeferT(DeferT&&) = delete;
		DeferT& operator=(const DeferT&) = delete;
		DeferT& operator=(DeferT&&) = delete;
		
		void set_active(bool value) noexcept;
		
		~DeferT() noexcept;
};

class DeferWhenExceptionT final {
	private:
		std::function<void()> f;
		bool active;
		bool when_exception;
		int exception_count;
	public:
		explicit(false) DeferWhenExceptionT(bool on_exception, std::function<void()> fn) noexcept;
		DeferWhenExceptionT(const DeferWhenExceptionT&) = delete;
		DeferWhenExceptionT(DeferWhenExceptionT&&) = delete;
		DeferWhenExceptionT& operator=(const DeferWhenExceptionT&) = delete;
		DeferWhenExceptionT& operator=(DeferWhenExceptionT&&) = delete;
		
		void set_active(bool value) noexcept;
		
		~DeferWhenExceptionT() noexcept;
};

#define DEFER_GLUE1(x, y) x##y
#define DEFER_GLUE2(x, y) DEFER_GLUE1(x, y)
#define DEFER_GLUE3(x) DEFER_GLUE2(x, __COUNTER__)

#define defer(code) DeferT DEFER_GLUE3(defer_var_){[&]()->void{code;}}
#define defer_named(name, code) DeferT name{[&]()->void{code;}}

#define defer_success(code) DeferWhenExceptionT DEFER_GLUE3(defer_success_var_){false, [&]()->void{code;}}
#define defer_success_named(name, code) DeferWhenExceptionT name{false, [&]()->void{code;}}

#define defer_fail(code) DeferWhenExceptionT DEFER_GLUE3(defer_fail_var_){true, [&]()->void{code;}}
#define defer_fail_named(name, code) DeferWhenExceptionT name{true, [&]()->void{code;}}

#endif //! FELIXS_PACK_MISC_DEFER_HPP
