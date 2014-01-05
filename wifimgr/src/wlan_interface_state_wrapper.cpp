#include "stdafx.h"
#include "wlan_interface_state_wrapper.h"



	//initialize the field and method values
	jfieldID wlan_interface_state_wrapper::wlan_interface_state_not_ready = 0;
	jfieldID wlan_interface_state_wrapper::wlan_interface_state_connected = 0;
	jfieldID wlan_interface_state_wrapper::wlan_interface_state_ad_hoc_network_formed = 0;
	jfieldID wlan_interface_state_wrapper::wlan_interface_state_disconnecting = 0;
	jfieldID wlan_interface_state_wrapper::wlan_interface_state_disconnected = 0;
	jfieldID wlan_interface_state_wrapper::wlan_interface_state_associating = 0;
	jfieldID wlan_interface_state_wrapper::wlan_interface_state_discovering = 0;
	jfieldID wlan_interface_state_wrapper::wlan_interface_state_authenticating = 0;

	jmethodID wlan_interface_state_wrapper::ordinal_ID = 0;
	jmethodID wlan_interface_state_wrapper::toString_ID = 0;
	jmethodID wlan_interface_state_wrapper::valueOf_ID = 0;
	jclass wlan_interface_state_wrapper::clazz = 0;

	jobject wlan_interface_state_wrapper::get_wlan_interface_state_not_ready(JNIEnv *env){
		return env->GetStaticObjectField(clazz, wlan_interface_state_not_ready);
	}
	jobject wlan_interface_state_wrapper::get_wlan_interface_state_connected(JNIEnv *env){
		return env->GetStaticObjectField(clazz, wlan_interface_state_connected);
	}
	jobject wlan_interface_state_wrapper::get_wlan_interface_state_ad_hoc_network_formed(JNIEnv *env){
		return env->GetStaticObjectField(clazz, wlan_interface_state_ad_hoc_network_formed);
	}
	jobject wlan_interface_state_wrapper::get_wlan_interface_state_disconnecting(JNIEnv *env){
		return env->GetStaticObjectField(clazz, wlan_interface_state_disconnecting);
	}
	jobject wlan_interface_state_wrapper::get_wlan_interface_state_disconnected(JNIEnv *env){
		return env->GetStaticObjectField(clazz, wlan_interface_state_disconnected);
	}
	jobject wlan_interface_state_wrapper::get_wlan_interface_state_associating(JNIEnv *env){
		return env->GetStaticObjectField(clazz, wlan_interface_state_associating);
	}
	jobject wlan_interface_state_wrapper::get_wlan_interface_state_discovering(JNIEnv *env){
		return env->GetStaticObjectField(clazz, wlan_interface_state_discovering);
	}
	jobject wlan_interface_state_wrapper::get_wlan_interface_state_authenticating(JNIEnv *env){
		return env->GetStaticObjectField(clazz, wlan_interface_state_authenticating);
	}
	jobject wlan_interface_state_wrapper::get_object_by_value(JNIEnv *env,int val){
		jobject obj;
		switch (val){
		case WLAN_INTERFACE_STATE::wlan_interface_state_not_ready:
			obj = wlan_interface_state_wrapper::get_wlan_interface_state_not_ready(env);
			break;
		case  WLAN_INTERFACE_STATE::wlan_interface_state_connected:
			obj = wlan_interface_state_wrapper::get_wlan_interface_state_connected(env);
			break;
		case  WLAN_INTERFACE_STATE::wlan_interface_state_ad_hoc_network_formed:
			obj = wlan_interface_state_wrapper::get_wlan_interface_state_ad_hoc_network_formed(env);
			break;
		case WLAN_INTERFACE_STATE::wlan_interface_state_disconnecting:
			obj = wlan_interface_state_wrapper::get_wlan_interface_state_disconnecting(env);
			break;
		case WLAN_INTERFACE_STATE::wlan_interface_state_disconnected:
			obj = wlan_interface_state_wrapper::get_wlan_interface_state_disconnected(env);
			break;
		case WLAN_INTERFACE_STATE::wlan_interface_state_associating:
			obj = wlan_interface_state_wrapper::get_wlan_interface_state_associating(env);
			break;
		case WLAN_INTERFACE_STATE::wlan_interface_state_discovering:
			obj = wlan_interface_state_wrapper::get_wlan_interface_state_discovering(env);
			break;
		case WLAN_INTERFACE_STATE::wlan_interface_state_authenticating:
			obj = wlan_interface_state_wrapper::get_wlan_interface_state_authenticating(env);
			break;
		default:
			obj = NULL;
		}
		assert(obj != NULL);
		return obj;
	}

	jint wlan_interface_state_wrapper::ordinal(JNIEnv *env, jobject enumObj)
	{
		return env->CallIntMethod(enumObj, ordinal_ID);
	}
	jstring wlan_interface_state_wrapper::toString(JNIEnv *env, jobject enumObj)
	{
		return reinterpret_cast<jstring>(env->CallObjectMethod(enumObj, toString_ID));
	}
	jobject wlan_interface_state_wrapper::valueOf(JNIEnv *env, jstring enumName)
	{
		return env->CallStaticObjectMethod(clazz, valueOf_ID, (jobject)enumName);
	}
	jint wlan_interface_state_wrapper::init(JavaVM *vm, void * reserved){
		JNIEnv* env = NULL;

		vm->AttachCurrentThread(reinterpret_cast<void**>(&env), NULL);

		jclass tmpclazz = reinterpret_cast<jclass> (env->FindClass("com/ifancc/wifimgr/Bean/WlanInterfaceState"));
		assert(tmpclazz != NULL);
		env->ExceptionClear();
		if (tmpclazz != 0)
		{
			wlan_interface_state_wrapper::clazz = reinterpret_cast<jclass> (env->NewGlobalRef(tmpclazz));
			assert(wlan_interface_state_wrapper::clazz != NULL);
			env->DeleteLocalRef(tmpclazz);
			wlan_interface_state_wrapper::wlan_interface_state_not_ready = env->GetStaticFieldID(
				wlan_interface_state_wrapper::clazz,
				"not_ready",
				"Lcom/ifancc/wifimgr/Bean/WlanInterfaceState;");
			assert(wlan_interface_state_wrapper::get_wlan_interface_state_not_ready != NULL);

			wlan_interface_state_wrapper::wlan_interface_state_connected = env->GetStaticFieldID(
				wlan_interface_state_wrapper::clazz,
				"connected",
				"Lcom/ifancc/wifimgr/Bean/WlanInterfaceState;");
			wlan_interface_state_wrapper::wlan_interface_state_ad_hoc_network_formed = env->GetStaticFieldID(
				wlan_interface_state_wrapper::clazz,
				"ad_hoc_network_formed",
				"Lcom/ifancc/wifimgr/Bean/WlanInterfaceState;");
			wlan_interface_state_wrapper::wlan_interface_state_disconnecting = env->GetStaticFieldID(
				wlan_interface_state_wrapper::clazz,
				"disconnecting",
				"Lcom/ifancc/wifimgr/Bean/WlanInterfaceState;");
			wlan_interface_state_wrapper::wlan_interface_state_disconnected = env->GetStaticFieldID(
				wlan_interface_state_wrapper::clazz,
				"disconnected",
				"Lcom/ifancc/wifimgr/Bean/WlanInterfaceState;");
			wlan_interface_state_wrapper::wlan_interface_state_associating = env->GetStaticFieldID(
				wlan_interface_state_wrapper::clazz,
				"associating",
				"Lcom/ifancc/wifimgr/Bean/WlanInterfaceState;");
			wlan_interface_state_wrapper::wlan_interface_state_discovering = env->GetStaticFieldID(
				wlan_interface_state_wrapper::clazz,
				"discovering",
				"Lcom/ifancc/wifimgr/Bean/WlanInterfaceState;");
			wlan_interface_state_wrapper::wlan_interface_state_authenticating = env->GetStaticFieldID(
				wlan_interface_state_wrapper::clazz,
				"authenticating",
				"Lcom/ifancc/wifimgr/Bean/WlanInterfaceState;");


			wlan_interface_state_wrapper::ordinal_ID = env->GetMethodID(
				wlan_interface_state_wrapper::clazz,
				"ordinal", "()I");
			assert(wlan_interface_state_wrapper::ordinal_ID != NULL);
			wlan_interface_state_wrapper::toString_ID = env->GetMethodID(
				wlan_interface_state_wrapper::clazz,
				"toString", "()Ljava/lang/String;");
			assert(wlan_interface_state_wrapper::toString_ID != NULL);

			wlan_interface_state_wrapper::valueOf_ID = env->GetStaticMethodID(
				wlan_interface_state_wrapper::clazz,
				"valueOf", 
				"(Ljava/lang/String;)Lcom/ifancc/wifimgr/Bean/WlanInterfaceState;");
			assert(wlan_interface_state_wrapper::valueOf_ID != NULL);
		}
		return JNI_VERSION_1_4;
	}
	void wlan_interface_state_wrapper::destroy(JavaVM *vm, void *reserved){

		JNIEnv* env = NULL;

		vm->AttachCurrentThread(reinterpret_cast<void**>(&env), NULL);
		if (env)
		{
			if (wlan_interface_state_wrapper::clazz != 0)
				env->DeleteGlobalRef(wlan_interface_state_wrapper::clazz);
		}
	}



