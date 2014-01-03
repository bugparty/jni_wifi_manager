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
	ret = wlan_interface_state_wrapper::init(vm, reserved);
	ret = WifiEnumWrapper::init(vm, reserved);
	return ret;
}


JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved)
{
	wlan_interface_state_wrapper::destroy(vm, reserved);
	WifiEnumWrapper::destroy(vm, reserved);
}
