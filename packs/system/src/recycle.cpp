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

bool move_to_bin(const std::filesystem::path& file_path) noexcept {
	#ifdef APP_SYSTEM_IS_LINUX
	GFile * file = g_file_new_for_path(file_path.c_str());
	gboolean ok = g_file_trash(file, nullptr, nullptr);
	g_object_unref((GObject*)file);
	return ok;
	#endif
	
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
	#endif
}
