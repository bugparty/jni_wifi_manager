#include "stdafx.h"
#ifndef _GUID_WRAPPER_H
#define _GUID_WRAPPER_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class wlan_interface_info_wrapper{
public:
	wlan_interface_info_wrapper(GUID guid,const WCHAR* interfaceInfo,WLAN_INTERFACE_STATE state);
	
	wlan_interface_info_wrapper(const char* guidStr, const WCHAR* interfaceInfo, WLAN_INTERFACE_STATE state);

	WLAN_INTERFACE_INFO* getInfo();
	virtual ~wlan_interface_info_wrapper();
private:
	WLAN_INTERFACE_INFO *info;
	jstring guidStr;
	jstring interfaceInfo;
	jobject state;



};


#endif