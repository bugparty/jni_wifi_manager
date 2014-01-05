// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
{
	jint ret;
	
	ret = WifiEnumWrapper::init(vm, reserved);
	ret = wlan_interface_state_wrapper::init(vm, reserved);
	ret = wlan_interface_info::init(vm, reserved);
	ret = wlan_interface_info_list::init(vm, reserved);
	return ret;
}


JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved)
{
	
	WifiEnumWrapper::destroy(vm, reserved);
	wlan_interface_state_wrapper::destroy(vm, reserved);
	wlan_interface_info::destroy(vm, reserved);
	wlan_interface_info_list::destroy(vm, reserved);
}
