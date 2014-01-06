#ifndef WIFI_TYPE_WRAPPER_H
#define WIFI_TYPE_WRAPPER_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <jni.h>

class WifiEnumWrapper
{
	WifiEnumWrapper(JavaVM *vm, void *reserved);
public:
	// Field IDs:
	static jfieldID  NONE_ID;
	static jfieldID  PSK_ID;
	static jfieldID  WEP_ID;


	// Method IDs:
	static jmethodID ordinal_ID;
	static jmethodID toString_ID;
	static jmethodID valueOf_ID;

	static jclass clazz;


	static jobject getNONE(JNIEnv *env);
	static jobject getPSK(JNIEnv *env);
	static jobject getWEP(JNIEnv *env);
	

	// Returns the ordinal value of Enum Object
	static jint ordinal(JNIEnv *env, jobject enumObj);
	// Returns the name of Enum Object
	static jstring toString(JNIEnv *env, jobject enumObj);
	// Returns Enum Object by name
	static jobject valueOf(JNIEnv *env, jstring enumName);
	static jint init(JavaVM * vm, void * reserved);
	static void destroy(JavaVM * vm, void * reserved);
	virtual ~WifiEnumWrapper(){};

};

#endif //  WIFI_TYPE_WRAPPER_H
