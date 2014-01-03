#include "stdafx.h"
#include "wifi_type_wrapper.h"
jfieldID  WifiEnumWrapper::NONE_ID = 0;
jfieldID  WifiEnumWrapper::WEP_ID = 0;
jfieldID  WifiEnumWrapper::PSK_ID = 0;

jmethodID WifiEnumWrapper::ordinal_ID = 0;
jmethodID WifiEnumWrapper::toString_ID = 0;
jmethodID WifiEnumWrapper::valueOf_ID = 0;
jclass WifiEnumWrapper::clazz = 0;

jobject WifiEnumWrapper::getNONE(JNIEnv *env)
{
	return env->GetStaticObjectField(clazz, NONE_ID);
}
jobject WifiEnumWrapper::getPSK(JNIEnv *env)
{
	return env->GetStaticObjectField(clazz, PSK_ID);
}
jobject WifiEnumWrapper::getWEP(JNIEnv *env)
{
	return env->GetStaticObjectField(clazz, WEP_ID);
}

jint WifiEnumWrapper::ordinal(JNIEnv *env, jobject enumObj)
{
	return env->CallIntMethod(enumObj, ordinal_ID);
}
jstring WifiEnumWrapper::toString(JNIEnv *env, jobject enumObj)
{
	return reinterpret_cast<jstring>(env->CallObjectMethod(enumObj, toString_ID));
}
jobject WifiEnumWrapper::valueOf(JNIEnv *env, jstring enumName)
{
	return env->CallStaticObjectMethod(clazz, valueOf_ID, (jobject)enumName);
}
jint WifiEnumWrapper::init(JavaVM *vm, void *reserved){
	JNIEnv* env = NULL;

	vm->AttachCurrentThread(reinterpret_cast<void**>(&env), NULL);


	jclass tmpclazz = reinterpret_cast<jclass> (env->FindClass("com/ifancc/wifimgr/Bean/Wifi$WifiType"));
	env->ExceptionClear();
	if (tmpclazz != 0)
	{
		WifiEnumWrapper::clazz = reinterpret_cast<jclass> (env->NewGlobalRef(tmpclazz));
		env->DeleteLocalRef(tmpclazz);
		WifiEnumWrapper::NONE_ID = env->GetStaticFieldID(WifiEnumWrapper::clazz, "NONE", "Lcom/ifancc/wifimgr/Bean/Wifi$WifiType;");
		WifiEnumWrapper::WEP_ID = env->GetStaticFieldID(WifiEnumWrapper::clazz, "WEP", "Lcom/ifancc/wifimgr/Bean/Wifi$WifiType;");
		WifiEnumWrapper::PSK_ID = env->GetStaticFieldID(WifiEnumWrapper::clazz, "PSK", "Lcom/ifancc/wifimgr/Bean/Wifi$WifiType;");

		WifiEnumWrapper::ordinal_ID = env->GetMethodID(WifiEnumWrapper::clazz, "ordinal", "()I");
		WifiEnumWrapper::toString_ID = env->GetMethodID(WifiEnumWrapper::clazz, "toString", "()Ljava/lang/String;");
		WifiEnumWrapper::valueOf_ID = env->GetStaticMethodID(WifiEnumWrapper::clazz, "valueOf", "(Ljava/lang/String;)Lcom/ifancc/wifimgr/Bean/Wifi$WifiType;");
	}
	return JNI_VERSION_1_4;
}

void WifiEnumWrapper::destroy(JavaVM *vm, void *reserved){
	JNIEnv* env = NULL;

	vm->AttachCurrentThread(reinterpret_cast<void**>(&env), NULL);
	if (env)
	{
		if (WifiEnumWrapper::clazz != 0)
			env->DeleteGlobalRef(WifiEnumWrapper::clazz);
	}
}
