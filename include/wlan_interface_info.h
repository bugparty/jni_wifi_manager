#ifndef _WLAN_INTERFACE_INFO_H
#define _WLAN_INTERFACE_INFO_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <jni.h>

class wlan_interface_info
{
public:
	wlan_interface_info(WLAN_INTERFACE_INFO* info);
	jobject getJavaObj(JNIEnv *env);
	static jclass clazz;

	static jfieldID GUIDID;
	static jfieldID InterfaceInfoID;
	static jfieldID StateID;
	static jmethodID initID;
	


	static jint init(JavaVM * vm, void * reserved);
	static void destroy(JavaVM * vm, void * reserved);

	virtual ~wlan_interface_info();
private:
	WLAN_INTERFACE_INFO *info;
	char* pstrGUID;

};


#endif //_WLAN_INTERFACE_INFO_H