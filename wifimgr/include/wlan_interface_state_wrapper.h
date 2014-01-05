#ifndef WIFI_INTERFACE_STATE_WRAPPER_H
#define WIFI_INTERFACE_STATE_WRAPPER_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <jni.h>
#include <wlanapi.h>

class wlan_interface_state_wrapper
{
	wlan_interface_state_wrapper(){};
public:
	// Field IDs:

	static jfieldID wlan_interface_state_not_ready;
	static jfieldID wlan_interface_state_connected;
	static jfieldID wlan_interface_state_ad_hoc_network_formed;
	static jfieldID wlan_interface_state_disconnecting;
	static jfieldID wlan_interface_state_disconnected;
	static jfieldID wlan_interface_state_associating;
	static jfieldID wlan_interface_state_discovering;
	static jfieldID wlan_interface_state_authenticating;


	// Method IDs:
	static jmethodID ordinal_ID;
	static jmethodID toString_ID;
	static jmethodID valueOf_ID;

	// wlan_interface_state object
	static jclass clazz;

	// functions to get the enum object
	static jobject get_wlan_interface_state_not_ready(JNIEnv *env);
	static jobject get_wlan_interface_state_connected(JNIEnv *env);
	static jobject get_wlan_interface_state_ad_hoc_network_formed(JNIEnv *env);
	static jobject get_wlan_interface_state_disconnecting(JNIEnv *env);
	static jobject get_wlan_interface_state_disconnected(JNIEnv *env);
	static jobject get_wlan_interface_state_associating(JNIEnv *env);
	static jobject get_wlan_interface_state_discovering(JNIEnv *env);
	static jobject get_wlan_interface_state_authenticating(JNIEnv *env);

	// get the wlan_interface_state enum object by the integer value
	static jobject wlan_interface_state_wrapper::get_object_by_value(JNIEnv *env, int val);



	// Returns the ordinal value of Enum Object
	static jint ordinal(JNIEnv *env, jobject enumObj);
	// Returns the name of Enum Object
	static jstring toString(JNIEnv *env, jobject enumObj);
	// Returns Enum Object by name
	static jobject valueOf(JNIEnv *env, jstring enumName);
	static jint init(JavaVM * vm, void * reserved);
	static void destroy(JavaVM * vm, void * reserved);
	virtual ~wlan_interface_state_wrapper(){};

};



#endif //  WIFI_INTERFACE_STATE_WRAPPER_H
