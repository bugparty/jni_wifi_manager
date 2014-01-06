#include "stdafx.h"


JNIEXPORT jobject JNICALL Java_com_ifancc_wifimgr_Bean_WlanInterfaceState_getWlanInterfaceState(JNIEnv * env, jclass cls, jint value)
{
	DWORD val = (DWORD)value;
	
	jobject obj = wlan_interface_state_wrapper::get_object_by_value(env,val);


	return obj;
}

