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
#include "recycle.hpp"

#ifdef APP_SYSTEM_IS_LINUX
#     include <glib-object.h>
#     include <gio/gio.h>
#endif

#ifdef APP_SYSTEM_IS_MSWIN
#     include <objbase.h> //CoInitialize
#     include <combaseapi.h> //CoUninitialize
#     include <Shobjidl.h> //SHCreateItemFromParsingName

struct COM_error {};
#endif

#ifdef APP_SYSTEM_IS_MACOS
#     include <CoreFoundation/CoreFoundation.h>
#     include <objc/objc.h>
#     include <objc/objc-runtime.h>

#include <string>
#endif

bool move_to_bin(const std::filesystem::path& file_path) noexcept {
	#ifdef APP_SYSTEM_IS_LINUX
	GFile * file = g_file_new_for_path(file_path.c_str());
	gboolean ok = g_file_trash(file, nullptr, nullptr);
	g_object_unref((GObject*)file);
	return ok;
	#endif /* ! APP_SYSTEM_IS_LINUX */
	
	#ifdef APP_SYSTEM_IS_MSWIN
	bool uninit_com = true;
	HRESULT result;
	
	result = CoInitialize(nullptr);
	if( result == S_FALSE ) {
		uninit_com = false;
	} else if( result != S_OK ) {
		return false;
	}
	
	bool fn_result;
	try {
		// https://stackoverflow.com/questions/44741999/how-can-i-delete-a-file-and-send-it-to-the-recycle-bin-in-vista-7-using-ifileope
		
		IFileOperation *pfo;
		
		result = CoCreateInstance(CLSID_FileOperation, nullptr, CLSCTX_ALL, IID_PPV_ARGS(&pfo));
		if(!SUCCEEDED(result)) {
			throw COM_error();
		}
		
		result = pfo->SetOperationFlags(FOF_ALLOWUNDO | FOF_NO_UI);
		if(!SUCCEEDED(result)) {
			pfo->Release();
			throw COM_error();
		}
		
		IShellItem *deleteItem = nullptr;
		result = SHCreateItemFromParsingName(file_path.c_str(), nullptr, IID_PPV_ARGS(&deleteItem));
		if(!SUCCEEDED(result)) {
			pfo->Release();
			throw COM_error();
		}
		
		result = pfo->DeleteItem(deleteItem, nullptr);
		if( deleteItem != nullptr ) {
			deleteItem->Release();
		}
		if(!SUCCEEDED(result)) {
			pfo->Release();
			throw COM_error();
		}
		
		result = pfo->PerformOperations();
		if(!SUCCEEDED(result)) {
			pfo->Release();
			throw COM_error();
		}
		
		pfo->Release();
		
		fn_result = true;
	} catch(COM_error) {
		fn_result = false;
	}
	
	if(uninit_com) {
		CoUninitialize();
	}
	return fn_result;
	#endif /* ! APP_SYSTEM_IS_MSWIN */
	
	#ifdef APP_SYSTEM_IS_MACOS
	//XXX: not tested!
	static SEL fm_default_manager_sel = sel_registerName("defaultManager");
	static SEL fm_trash_url_sel = sel_registerName("trashItemAtURL:resultingItemURL:error:");
	static SEL ns_url_make_sel = sel_registerName("fileURLWithPath:");
	
	id file_manager_class = reinterpret_cast<id>(objc_getClass("NSFileManager"));
	id file_manager = reinterpret_cast<id (*)(id,SEL)>(objc_msgSend)\
		(file_manager_class, fm_default_manager_sel);
	
	std::string file_path_url = file_path.generic_string();
	file_path_url = "file://" + file_path_url;
	CFStringRef file_path_cstr = CFStringCreateWithCString(
		nullptr, file_path_url.c_str(), kCFStringEncodingUTF8
	);
	
	id nsUrl = reinterpret_cast<id>(objc_getClass("NSURL"));
	id file_url = reinterpret_cast<id (*)(id,SEL,CFStringRef)>(objc_msgSend)\
		(nsUrl,ns_url_make_sel,file_path_cstr);
	
	bool op_result = reinterpret_cast<bool (*)(id,SEL,id,id,id)>(objc_msgSend)\
		(file_manager, fm_trash_url_sel, file_url, Nil, Nil);
	
	CFRelease(file_url);
	CFRelease(file_path_cstr);// ???
	
	return op_result;
	#endif /* ! APP_SYSTEM_IS_MACOS */
}
