// wifimgr.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"


JNIEXPORT jobject JNICALL Java_com_ifancc_wifimgr_Manager_WlanEnumInterfaces
(JNIEnv *env, jobject cls){
	wlan_interface_info_list l = wlan_interface_info_list();
	return l.getJavaObj(env);
}