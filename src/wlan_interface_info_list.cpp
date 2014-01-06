#include "stdafx.h"
#include "wlan_interface_info_list.h"
#include "java/com_ifancc_wifimgr_WlanInterfaceInfoListTest.h"
jclass wlan_interface_info_list::clazz = 0;
jclass wlan_interface_info_list::Cjlist = 0;

jmethodID wlan_interface_info_list::initID = 0;

jmethodID wlan_interface_info_list::MDjlist_init = 0;
jmethodID wlan_interface_info_list::MDjlist_add = 0;
jmethodID wlan_interface_info_list::MDifList_init = 0;
jobject wlan_interface_info_list::ParaIsize = 0;
jobject wlan_interface_info_list::ParaIindex = 0;
jobject wlan_interface_info_list::ParaAifInfo = 0;


jint wlan_interface_info_list::init(JavaVM * vm, void * reserved){

	JNIEnv* env = NULL;

	vm->AttachCurrentThread(reinterpret_cast<void**>(&env), NULL);

	jclass tmpclazz = reinterpret_cast<jclass> (env->FindClass("com/ifancc/wifimgr/Bean/WlanInterfaceInfoList"));
	assert(tmpclazz != NULL);
	env->ExceptionClear();
	if (tmpclazz != 0)
	{
		wlan_interface_info_list::clazz = reinterpret_cast<jclass> (env->NewGlobalRef(tmpclazz));
		assert(wlan_interface_info_list::clazz != NULL);
		env->DeleteLocalRef(tmpclazz);

		wlan_interface_info_list::MDifList_init = env->GetMethodID(wlan_interface_info_list::clazz,
			"<init>", "(II[Lcom/ifancc/wifimgr/Bean/WlanInterfaceInfo;)V");
		assert(wlan_interface_info_list::MDifList_init != NULL);

		Cjlist = env->FindClass("Ljava/util/ArrayList;");//获得ArrayList类引用
		assert(Cjlist != NULL);

		MDjlist_init = env->GetMethodID(Cjlist, "<init>", "()V");
		assert(MDjlist_init != NULL);

		
		//获得Arraylist类中的 add()方法ID，其方法原型为： boolean add(Object object) ;  
		jmethodID MDjlist_add = env->GetMethodID(Cjlist, "add", "(Ljava/lang/Object;)Z");

		assert(MDjlist_add != NULL);




	}

	return JNI_VERSION_1_4;

	
	
}
void wlan_interface_info_list::destroy(JavaVM * vm, void * reserved){
	JNIEnv* env = NULL;

	vm->AttachCurrentThread(reinterpret_cast<void**>(&env), NULL);
	if (env)
	{
		if (wlan_interface_info_list::clazz != 0)
			env->DeleteGlobalRef(wlan_interface_info_list::clazz);
	}
}


wlan_interface_info_list::wlan_interface_info_list(WLAN_INTERFACE_INFO_LIST list){
	
}
wlan_interface_info_list::wlan_interface_info_list(){

}


wlan_interface_info_list::~wlan_interface_info_list(){

}

jobject wlan_interface_info_list::getJavaObj(JNIEnv *env){

	jint size;
	jint index;
	jobjectArray arrWlanIf;
	printInfo();
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

	dwRet = WlanOpenHandle(dwMaxClient, NULL, &dwCurVersion, &hClient);
	if (dwRet != ERROR_SUCCESS){
		fwprintf(stderr, _T("Error in getting WlanHandle\n"));
		return NULL;
	}
	dwRet = WlanEnumInterfaces(hClient, NULL, &pIfList);
	if (dwRet != ERROR_SUCCESS){
		fwprintf(stderr, L"Error in getting Wlan Interfaces\n");
		return NULL;
	}
	else {
		printInfo();
		size = (jint)pIfList->dwNumberOfItems;
		index = (jint)pIfList->dwIndex;
		//create a java list object
		assert(wlan_interface_info::clazz != NULL);
		arrWlanIf = env->NewObjectArray(size, wlan_interface_info::clazz, NULL);
		assert(arrWlanIf != NULL);
		//fwprintf(stdout, L"Current Index: %lu\n", pIfList->dwIndex);
		printInfo();
		for (i = 0; i < (int)pIfList->dwNumberOfItems; i++) {
			pIfInfo = (WLAN_INTERFACE_INFO *)&pIfList->InterfaceInfo[i];
			jobject wlanIf;
			wlan_interface_info obj = wlan_interface_info(pIfInfo);
			printInfo();
			wlanIf = obj.getJavaObj(env);
			assert(wlanIf != NULL);
			printInfo();
			env->SetObjectArrayElement(arrWlanIf,(jint) i, wlanIf);
			printInfo();

;
		}
	}

	if (pIfList != NULL) {
		WlanFreeMemory(pIfList);
		pIfList = NULL;
	}

	jobject jobjWlanInterfaceInfoList;
	printInfo();
	assert(MDifList_init!= NULL);
	assert(clazz != NULL);
	jobjWlanInterfaceInfoList = env->NewObject(clazz, MDifList_init, size, index, arrWlanIf);
	assert(jobjWlanInterfaceInfoList != NULL);
	printInfo();
	return jobjWlanInterfaceInfoList;
}



/*
* Class:     com_ifancc_wifimgr_WlanInterfaceInfoListTest
* Method:    getWlanInterfaceInfoList
* Signature: ()Lcom/ifancc/wifimgr/Bean/WlanInterfaceInfoList;
*/
JNIEXPORT jobject JNICALL Java_com_ifancc_wifimgr_WlanInterfaceInfoListTest_getWlanInterfaceInfoList
(JNIEnv *env, jclass cls){
	wlan_interface_info_list l = wlan_interface_info_list();
	wprintf(L"into jni\n");
	return l.getJavaObj(env);
}

