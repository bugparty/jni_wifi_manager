#include "stdafx.h"
#include "ulits.h"

GUID stringToGUID(const std::string& guid) {
	GUID output;
	UINT32 four[8];

	const auto ret = sscanf(guid.c_str(), "{%8lx-%4hx-%4hx-%2hhx%2hhx-%2hhx%2hhx%2hhx%2hhx%2hhx%2hhx}", &output.Data1, &output.Data2, &output.Data3, &four[0], &four[1], &four[2], &four[3], &four[4], &four[5], &four[6], &four[7]);
	//const auto ret = sscanf(guid.c_str(), "{%8X-%4hX-%4hX-%2hX%2hX-%2hX%2hX%2hX%2hX%2hX%2hX}", &output.Data1, &output.Data2, &output.Data3, &output.Data4[0], &output.Data4[1], &output.Data4[2], &output.Data4[3], &output.Data4[4], &output.Data4[5], &output.Data4[6], &output.Data4[7]);
	for (int i = 0; i < 8; i++){
		output.Data4[i] = (unsigned char)(four[i]);
	}
	if (ret != 11)
		throw std::logic_error("Unvalid GUID, format should be {00000000-0000-0000-0000-000000000000}");
	return output;
}

GUID stringToGUID(const char* guidstr) {
	GUID output, o = { 0 };
	fprintf(stderr, "guid is %s\n", guidstr);
	/*
	typedef struct _GUID {
		unsigned long  Data1;
		unsigned short Data2;
		unsigned short Data3;
		unsigned char  Data4[ 8 ];
	} GUID;
	*/
	UINT32 four[8];
	
	const auto ret = sscanf(guidstr, "{%8lx-%4hx-%4hx-%2hhx%2hhx-%2hhx%2hhx%2hhx%2hhx%2hhx%2hhx}", &output.Data1, &output.Data2, &output.Data3, &four[0], &four[1], &four[2], &four[3], &four[4], &four[5], &four[6], &four[7]);
	for (int i = 0; i < 8; i++){
		output.Data4[i] = (unsigned char)(four[i]);
	}
	
	if (ret != 11){
		throw std::logic_error("Unvalid GUID, format should be {00000000-0000-0000-0000-000000000000}");
		
	}
		

	
	return o;
}