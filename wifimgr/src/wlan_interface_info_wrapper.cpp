#include "stdafx.h"
#include "wlan_interface_info_wraper.h"

wlan_interface_info_wrapper::wlan_interface_info_wrapper(
	const char* guidStr, const WCHAR* interfaceInfo, WLAN_INTERFACE_STATE state){
	info = new WLAN_INTERFACE_INFO;
	GUID g = stringToGUID(guidStr);

	info->InterfaceGuid = g;

	lstrcpy(info->strInterfaceDescription, interfaceInfo);

	info->isState = state;


}

wlan_interface_info_wrapper::wlan_interface_info_wrapper(
	GUID guid, const WCHAR* interfaceInfo, WLAN_INTERFACE_STATE state){
	info = new WLAN_INTERFACE_INFO;


	info->InterfaceGuid = guid;

	lstrcpy(info->strInterfaceDescription, interfaceInfo);

	info->isState = state;


}

WLAN_INTERFACE_INFO* wlan_interface_info_wrapper::getInfo(){
	return info;
}
wlan_interface_info_wrapper::~wlan_interface_info_wrapper(){
	delete info;
}