#include "stdafx.h"


JNIEXPORT jobject JNICALL Java_com_ifancc_wifimgr_Bean_WlanInterfaceState_getWlanInterfaceState(JNIEnv * env, jclass cls, jint value)
{
	DWORD val = (DWORD)value;
	jobject obj;
	switch (val){
	case wlan_interface_state_not_ready:
		obj = wlan_interface_state_wrapper::get_wlan_interface_state_not_ready(env);
		break;
	case wlan_interface_state_connected:
		obj = wlan_interface_state_wrapper::get_wlan_interface_state_connected(env);
		break;
	case wlan_interface_state_ad_hoc_network_formed:
		obj = wlan_interface_state_wrapper::get_wlan_interface_state_ad_hoc_network_formed(env);
		break;
	case wlan_interface_state_disconnecting:
		obj = wlan_interface_state_wrapper::get_wlan_interface_state_disconnecting(env);
		break;
	case wlan_interface_state_disconnected:
		obj = wlan_interface_state_wrapper::get_wlan_interface_state_disconnected(env);
		break;
	case wlan_interface_state_associating:
		obj = wlan_interface_state_wrapper::get_wlan_interface_state_associating(env);
		break;
	case wlan_interface_state_discovering:
		obj = wlan_interface_state_wrapper::get_wlan_interface_state_discovering(env);
		break;
	case wlan_interface_state_authenticating:
		obj = wlan_interface_state_wrapper::get_wlan_interface_state_authenticating(env);
		break;
	default:
		obj = NULL;
	}
	assert(obj != NULL);
	return obj;
}

