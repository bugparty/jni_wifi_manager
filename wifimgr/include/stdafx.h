// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息
// Windows Header files: 
#include <windows.h>


#include <wlanapi.h>
#pragma comment(lib, "wlanapi.lib")
#pragma comment(lib, "ole32.lib")
#include <objbase.h>
#include <wtypes.h>
#include <tchar.h>
//Jni Header Files
#include <jni.h>

//C Lang Header Files
#include <assert.h>
#include <stdio.h>
#include <string>
#include <array>

// 在此处引用程序需要的其他头文件
#include "ulits.h"
#include "./java/com_ifancc_wifimgr_Manager.h"
#include "./java/com_ifancc_wifimgr_Bean_WlanInterfaceState.h"
#include "./java/com_ifancc_wifimgr_WlanInterfaceInfoTest.h"

#include "wifi_type_wrapper.h"
#include "wlan_interface_state_wrapper.h"
#include "wlan_interface_info_wraper.h"
#include "wlan_interface_info.h"
#include "wlan_interface_info_list.h"

