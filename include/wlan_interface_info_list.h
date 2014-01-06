#ifndef _WLAN_INTERFACE_INFO_LIST_H
#define _WLAN_INTERFACE_INFO_LIST_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "stdafx.h"

class wlan_interface_info_list
{
public:
	wlan_interface_info_list(WLAN_INTERFACE_INFO_LIST list);
	wlan_interface_info_list();
	jobject getJavaObj(JNIEnv *env);

	static jclass clazz;
	static jclass Cjlist;
	static jmethodID MDjlist_init;
	static jmethodID MDjlist_add;
	static jmethodID MDifList_init;
	static jobject ParaIsize;
	static jobject ParaIindex;
	static jobject ParaAifInfo;
	static jfieldID GUIDID;
	static jfieldID InterfaceInfoID;
	static jfieldID StateID;

	static jmethodID initID;

	jobjectArray jarray;

	static jint init(JavaVM * vm, void * reserved);
	static void destroy(JavaVM * vm, void * reserved);

	virtual ~wlan_interface_info_list();
private:
	WLAN_INTERFACE_INFO **infoList;

};


#endif //_WLAN_INTERFACE_INFO_LIST_H