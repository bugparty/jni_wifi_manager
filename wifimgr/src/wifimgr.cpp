// wifimgr.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

#define DEBUG

JNIEXPORT jobjectArray JNICALL Java_com_ifancc_wifimgr_Manager_getWifiList
(JNIEnv *env, jobject obj){
	jobjectArray jarray = NULL;
	jclass wifi;
	jclass list_cls;
	jmethodID list_init;
	jclass wifi_type;
	
	jmethodID wifi_init;
	  
	wifi = env->FindClass("com/ifancc/wifimgr/Bean/Wifi");
	wifi_init = env->GetMethodID(wifi, "<init>", "(Ljava/lang/String;Lcom/ifancc/wifimgr/Bean/Wifi$WifiType;)V");
	wifi_type = env->FindClass("Lcom/ifancc/wifimgr/Bean/Wifi$WifiType;");

	list_cls  = env->FindClass("Ljava/util/ArrayList;");//获得ArrayList类引用
	list_init = env->GetMethodID(list_cls, "<init>", "()V");

	assert(wifi != NULL);
	assert(wifi_init != NULL);
	assert(wifi_type != NULL);
	
	
	assert(list_cls != NULL);
	assert(list_init != NULL);

	

	jobject WEP = WifiEnumWrapper::getWEP(env);
	assert(WEP != NULL);
	jobject list_obj = env->NewObject(list_cls, list_init);
	//获得Arraylist类中的 add()方法ID，其方法原型为： boolean add(Object object) ;  
	jmethodID list_add = env->GetMethodID(list_cls, "add", "(Ljava/lang/Object;)Z");
	jarray = env->NewObjectArray((jsize)3, wifi, NULL);
	//-----------------------------------------
	// Declare and initialize variables
	DWORD dwRet;
	PHANDLE phClientHandle = NULL;
	PDWORD pdwNegotiatedVersion = NULL;
	// Declare and initialize variables.

	HANDLE hClient = NULL;
	DWORD dwMaxClient = 2;   //    
	DWORD dwCurVersion = 0;
	DWORD dwResult = 0;
	int iRet = 0;

	WCHAR GuidString[40] = { 0 };

	int i;

	/* variables used for WlanEnumInterfaces  */

	PWLAN_INTERFACE_INFO_LIST pIfList = NULL;
	PWLAN_INTERFACE_INFO pIfInfo = NULL;

	dwRet = WlanOpenHandle(dwMaxClient,NULL,&dwCurVersion,&hClient);
	if (dwRet != ERROR_SUCCESS){
		fwprintf(stderr, _T("Error in getting WlanHandle\n"));
		return NULL;
	}
	dwRet =  WlanEnumInterfaces(hClient,NULL,&pIfList);
	if (dwRet != ERROR_SUCCESS){
		fwprintf(stderr, L"Error in getting Wlan Interfaces\n");
		return NULL;
	}
	else {
		wprintf(L"Num Entries: %lu\n", pIfList->dwNumberOfItems);
		wprintf(L"Current Index: %lu\n", pIfList->dwIndex);
		for ( i = 0; i < (int)pIfList->dwNumberOfItems; i++) {
			pIfInfo = (WLAN_INTERFACE_INFO *)&pIfList->InterfaceInfo[i];
			wprintf(L"  Interface Index[%d]:\t %lu\n", i, i);
			dwRet = StringFromGUID2(pIfInfo->InterfaceGuid, (LPOLESTR)&GuidString, 39);
			if (dwRet == 0){
				LPWSTR buf = NULL;
				FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER, NULL, dwRet, LANG_SYSTEM_DEFAULT, buf, NULL, NULL);
				fwprintf(stderr, L"StringFromGUID2 failed %s\n",buf);
				LocalFree(buf);
			}
				
			
			else {
				wprintf(L"  InterfaceGUID[%d]: %ws\n", i, GuidString);
			}
			wprintf(L"  Interface Description[%d]: %ws", i,
				pIfInfo->strInterfaceDescription);
			wprintf(L"\n");
			wprintf(L"  Interface State[%d]:\t ", i);
			switch (pIfInfo->isState) {
			case wlan_interface_state_not_ready:
				wprintf(L"Not ready\n");
				break;
			case wlan_interface_state_connected:
				wprintf(L"Connected\n");
				break;
			case wlan_interface_state_ad_hoc_network_formed:
				wprintf(L"First node in a ad hoc network\n");
				break;
			case wlan_interface_state_disconnecting:
				wprintf(L"Disconnecting\n");
				break;
			case wlan_interface_state_disconnected:
				wprintf(L"Not connected\n");
				break;
			case wlan_interface_state_associating:
				wprintf(L"Attempting to associate with a network\n");
				break;
			case wlan_interface_state_discovering:
				wprintf(L"Auto configuration is discovering settings for the network\n");
				break;
			case wlan_interface_state_authenticating:
				wprintf(L"In process of authenticating\n");
				break;
			default:
				wprintf(L"Unknown state %ld\n", pIfInfo->isState);
				break;
			}
			wprintf(L"\n");
		}
	}

	if (pIfList != NULL) {
		WlanFreeMemory(pIfList);
		pIfList = NULL;
	}
	for (int i = 0; i < 3; i++){
		jstring wifi_name = env->NewStringUTF("cmcc");
		jobject wifi_obj = env->NewObject(wifi, wifi_init, wifi_name, WEP);
		env->SetObjectArrayElement(jarray, i, wifi_obj);
	}

	return jarray;

}