#include "stdafx.h"
#ifdef _MSC_VER
#	define snprintf	_snprintf
#endif
#ifndef _ULITS_H
#define _ULITS_H
GUID stringToGUID(const std::string& guid);
GUID stringToGUID(const char* guid);
char* guidToChars(GUID guid);
#endif