// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
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

// �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include "ulits.h"
#include "./java/com_ifancc_wifimgr_Manager.h"
#include "./java/com_ifancc_wifimgr_Bean_WlanInterfaceState.h"
#include "./java/com_ifancc_wifimgr_WlanInterfaceInfoTest.h"

#include "wifi_type_wrapper.h"
#include "wlan_interface_state_wrapper.h"
#include "wlan_interface_info_wraper.h"
#include "wlan_interface_info.h"
#include "wlan_interface_info_list.h"

