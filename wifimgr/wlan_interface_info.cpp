#include "stdafx.h"
#include "wlan_interface_info.h"
#include "com_ifancc_wifimgr_Bean_WlanInterfaceInfo.h"

jclass wlan_interface_info::clazz = 0;

jfieldID wlan_interface_info::GUIDID = 0;
jfieldID wlan_interface_info::InterfaceInfoID = 0;
jfieldID wlan_interface_info::StateID = 0;

wlan_interface_info::wlan_interface_info(WLAN_INTERFACE_INFO *info)
{
	this->info = info;

}
jobject wlan_interface_info::getJavaObj(JNIEnv *env){
	
	wlan_interface_info::InterfaceInfoID = env->GetFieldID(wlan_interface_info::clazz,
		"InterfaceInfo", "Ljava/lang/String;");
	assert(wlan_interface_info::InterfaceInfoID != NULL);

	wlan_interface_info::GUIDID = env->GetFieldID(wlan_interface_info::clazz,
		"GUID", "Ljava/lang/String;");
	assert(wlan_interface_info::GUIDID != NULL);

	wlan_interface_info::StateID = env->GetFieldID(wlan_interface_info::clazz,
		"State", "Lcom/ifancc/wifimgr/Bean/WlanInterfaceState;");
	assert(wlan_interface_info::StateID != NULL);
	return NULL;
}
jmethodID wlan_interface_info::initID = 0;
jobject wlan_interface_info::getJavaObj(jclass cls,JNIEnv *env){
	
	wlan_interface_info::InterfaceInfoID = env->GetFieldID(cls,
		"InterfaceInfo", "Ljava/lang/String;");
	assert(wlan_interface_info::InterfaceInfoID != NULL);

	wlan_interface_info::GUIDID = env->GetFieldID(cls,
		"GUID", "Ljava/lang/String;");
	assert(wlan_interface_info::GUIDID != NULL);

	wlan_interface_info::StateID = env->GetFieldID(cls,
		"State", "Lcom/ifancc/wifimgr/Bean/WlanInterfaceState;");
	assert(wlan_interface_info::StateID != NULL);

	wlan_interface_info::initID = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;Ljava/lang/String;Lcom/ifancc/wifimgr/Bean/WlanInterfaceState;)V");
	assert(wlan_interface_info::initID != NULL);
	jstring interfaceInfo = env->NewString((const jchar*)(info->strInterfaceDescription),(jsize)sizeof(info->strInterfaceDescription));
	jstring GUID = env->NewString((const jchar*)guidToChars(info->InterfaceGuid),40);
	jobject state = wlan_interface_state_wrapper::get_object_by_value(env, info->isState);
	jobject obj = env->NewObject(cls, initID, GUID, interfaceInfo, state );



	return obj;
}

wlan_interface_info::~wlan_interface_info()
{
}


jint wlan_interface_info::init(JavaVM * vm, void * reserved){
	JNIEnv* env = NULL;

	vm->AttachCurrentThread(reinterpret_cast<void**>(&env), NULL);

	jclass tmpclazz = reinterpret_cast<jclass> (env->FindClass("com/ifancc/wifimgr/Bean/WlanInterfaceState"));
	assert(tmpclazz != NULL);
	env->ExceptionClear();
	if (tmpclazz != 0)
	{
		wlan_interface_info::clazz = reinterpret_cast<jclass> (env->NewGlobalRef(tmpclazz));
		assert(wlan_interface_info::clazz != NULL);
		env->DeleteLocalRef(tmpclazz);

		/*
		wlan_interface_info::InterfaceInfoID = env->GetFieldID(wlan_interface_info::clazz,
			"InterfaceInfo", "Ljava/lang/String;");
		assert(wlan_interface_info::InterfaceInfoID != NULL);

		wlan_interface_info::GUIDID = env->GetFieldID(wlan_interface_info::clazz,
			"GUID", "Ljava/lang/String;");
		assert(wlan_interface_info::GUIDID != NULL);

		wlan_interface_info::StateID = env->GetFieldID(wlan_interface_info::clazz,
			"State", "Lcom/ifancc/wifimgr/Bean/WlanInterfaceState;");
		assert(wlan_interface_info::StateID != NULL);
		*/


	}
	return JNI_VERSION_1_4;

}
void wlan_interface_info::destroy(JavaVM * vm, void * reserved){
	JNIEnv* env = NULL;

	vm->AttachCurrentThread(reinterpret_cast<void**>(&env), NULL);
	if (env)
	{
		if (wlan_interface_info::clazz != 0)
			env->DeleteGlobalRef(wlan_interface_info::clazz);
	}
}

JNIEXPORT jobject JNICALL Java_com_ifancc_wifimgr_Bean_WlanInterfaceInfo_getWlanInterfaceInfo
(JNIEnv *env, jclass cls ){
	/*Interface Index[0]:	 0
		InterfaceGUID[0] : {90903451 - 342D - 4A01 - BB90 - 13A762F4BE1C}
	Interface Description[0] : Intel(R) Centrino(R) Advanced - N 6200 AGN
		Interface State[0] : Connected*/
	WLAN_INTERFACE_INFO *info = new WLAN_INTERFACE_INFO;
	GUID g = stringToGUID("{90903451-342D-4A01-BB90-13A762F4BE1C}");
	
	info->InterfaceGuid = g;
	
	lstrcpy(info->strInterfaceDescription, L"Intel(R) Centrino(R) Advanced - N 6200 AGN");

	info->isState = wlan_interface_state_connected;
		

	wlan_interface_info obj = wlan_interface_info(info);
	
	return obj.getJavaObj(cls,env);
}