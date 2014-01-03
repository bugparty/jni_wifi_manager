
#define BUILD_DLL

#include "main.h"
#include "example_Jni.h"
// a sample exported function
//void DLL_EXPORT SomeFunction(const LPCSTR sometext)
//{
//    MessageBoxA(0, sometext, "DLL Message", MB_OK | MB_ICONINFORMATION);
//}


JNIEXPORT void JNICALL Java_example_Jni_displayHello(JNIEnv* env, jclass jcls){
	MessageBoxA(0, "hello msg", "hello title", MB_OK | MB_ICONINFORMATION);
	
}
JNIEXPORT jstring JNICALL Java_example_Jni_getAnsiString
(JNIEnv *env, jclass jcls){
	char *str = "hello";
	jstring jStr = env->NewStringUTF(str);
	return jStr;
}
JNIEXPORT void JNICALL Java_example_Jni_printString
(JNIEnv *env, jclass jcls, jstring jstr){
	const char *str;
	str = env->GetStringUTFChars(jstr,NULL);
	printf("%s", str);
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		// attach to process
		// return FALSE to fail DLL load
		break;

	case DLL_PROCESS_DETACH:
		// detach from process
		
		break;

	case DLL_THREAD_ATTACH:
		// attach to thread
		break;

	case DLL_THREAD_DETACH:
		// detach from thread
		break;
	}
	return TRUE; // succesful
}
