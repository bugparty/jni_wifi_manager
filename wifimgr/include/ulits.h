#include "stdafx.h"
#ifdef _MSC_VER
#	define snprintf	_snprintf
#endif
#ifndef _ULITS_H
#define _ULITS_H
GUID stringToGUID(const std::string& guid);
GUID stringToGUID(const char* guid);
char* guidToChars(GUID guid, char* output, size_t bufsize);

#ifdef _DEBUG 
	#ifdef  _ENABLE_PRINTINFO
		#define printInfo(); printf("file: %s\n\tline %i\n", __FILE__, __LINE__);
	#else
		#define printInfo(); ;
	#endif
#else
	
#endif


#endif