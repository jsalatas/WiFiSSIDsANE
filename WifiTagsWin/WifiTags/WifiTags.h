#ifndef WIFITAGS_H_
#define WIFITAGS_H_


#include "FlashRuntimeExtensions.h"

extern "C"
{
	__declspec(dllexport) void initializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer);
	__declspec(dllexport) void finalizer(void* extData);
}

#endif /* WIFITAGS_H_ */
