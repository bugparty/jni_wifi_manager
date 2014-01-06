#include "stdafx.h"
#include "wlan_interface_info.h"
using namespace std;
//static vars initialize
jclass wlan_interface_info::clazz = 0;

jfieldID wlan_interface_info::GUIDID = 0;
jfieldID wlan_interface_info::InterfaceInfoID = 0;
jfieldID wlan_interface_info::StateID = 0;

jmethodID wlan_interface_info::initID = 0;

/*
// struct WLAN_INTERFACE_INFO defines the basic information for an interface
typedef struct _WLAN_INTERFACE_INFO {
    GUID InterfaceGuid;
    WCHAR strInterfaceDescription[WLAN_MAX_NAME_LENGTH];
    WLAN_INTERFACE_STATE isState;
} WLAN_INTERFACE_INFO, *PWLAN_INTERFACE_INFO;
*/
wlan_interface_info::wlan_interface_info(WLAN_INTERFACE_INFO *info)
{
	pstrGUID = new char[100];
	this->info = info;

}
wlan_interface_info::~wlan_interface_info()
{
	//delete[]pstrGUID;
	//pstrGUID = NULL;
}

jobject wlan_interface_info::getJavaObj(JNIEnv *env){
	/*Give myself a lession
// struct WLAN_INTERFACE_INFO defines the basic information for an interface
typedef struct _WLAN_INTERFACE_INFO {
    GUID InterfaceGuid;
    WCHAR strInterfaceDescription[WLAN_MAX_NAME_LENGTH];
    WLAN_INTERFACE_STATE isState;
} WLAN_INTERFACE_INFO, *PWLAN_INTERFACE_INFO;
	*/
	
	jstring interfaceInfo = env->NewString((const jchar*)(info->strInterfaceDescription),(jsize)lstrlen(info->strInterfaceDescription));
	if (guidToChars(info->InterfaceGuid, pstrGUID, 100) == NULL){
		fprintf(stderr, "error in guidToChars");
		printInfo();
	}
	
	//pstrGUID = guidToChars(info->InterfaceGuid);

	//fix: memery leak or other things occors, stack obj was coupted or so on
	jstring GUID = env->NewStringUTF(pstrGUID);
	
	jobject state = wlan_interface_state_wrapper::get_object_by_value(env, info->isState);

	jobject obj = env->NewObject(wlan_interface_info::clazz, initID, GUID, interfaceInfo, state );

	assert(obj != NULL);

	return obj;
}



jint wlan_interface_info::init(JavaVM * vm, void * reserved){
	JNIEnv* env = NULL;

	vm->AttachCurrentThread(reinterpret_cast<void**>(&env), NULL);

	jclass tmpclazz = reinterpret_cast<jclass> (env->FindClass("com/ifancc/wifimgr/Bean/WlanInterfaceInfo"));
	assert(tmpclazz != NULL);
	env->ExceptionClear();
	if (tmpclazz != 0)
	{
		wlan_interface_info::clazz = reinterpret_cast<jclass> (env->NewGlobalRef(tmpclazz));
		assert(wlan_interface_info::clazz != NULL);
		env->DeleteLocalRef(tmpclazz);
	
		
		wlan_interface_info::InterfaceInfoID = env->GetFieldID(wlan_interface_info::clazz,
			"InterfaceInfo", "Ljava/lang/String;");
		assert(wlan_interface_info::InterfaceInfoID != NULL);

		wlan_interface_info::GUIDID = env->GetFieldID(wlan_interface_info::clazz,
			"GUID", "Ljava/lang/String;");
		assert(wlan_interface_info::GUIDID != NULL);

		wlan_interface_info::StateID = env->GetFieldID(wlan_interface_info::clazz,
			"State", "Lcom/ifancc/wifimgr/Bean/WlanInterfaceState;");
		assert(wlan_interface_info::StateID != NULL);

		wlan_interface_info::initID = env->GetMethodID(wlan_interface_info::clazz, "<init>", "(Ljava/lang/String;Ljava/lang/String;Lcom/ifancc/wifimgr/Bean/WlanInterfaceState;)V");
		assert(wlan_interface_info::initID != NULL);
		


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

JNIEXPORT jobject JNICALL Java_com_ifancc_wifimgr_WlanInterfaceInfoTest_getWlanInterfaceInfo
(JNIEnv *env , jclass cls)
{
	/*
	Interface Index[0]:	 0
		InterfaceGUID[0] : {90903451 - 342D - 4A01 - BB90 - 13A762F4BE1C}
	Interface Description[0] : Intel(R) Centrino(R) Advanced - N 6200 AGN
		Interface State[0] : Connected
	*/

	WLAN_INTERFACE_INFO *info;

	wlan_interface_info_wrapper w = wlan_interface_info_wrapper("{90903451-342D-4A01-BB90-13A762F4BE1C}",
		L"Intel(R) Centrino(R) Advanced - N 6200 AGN",
		wlan_interface_state_connected);

	info = w.getInfo();

	assert(info != NULL);
	wlan_interface_info obj = wlan_interface_info(info);
	
	jobject ret = obj.getJavaObj(env);
	assert(ret != NULL);
	return ret;
}