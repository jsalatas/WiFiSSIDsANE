#include <stdlib.h>
#include <string>
#include <vector>
#include "WlanGetAvailableNetworkList.h"
#include "WifiTags.h"


extern "C" {

	FREObject getWifiTags(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]) {
		FREObject result;
		
		std::wstring tags = getTags();
		std::vector<uint8_t> tagsVector(tags.begin(), tags.end());
		uint8_t *pVector = &tagsVector[0];
		FRENewObjectFromUTF8(tags.size(), pVector, &result);

		return result;
	}

	FREObject isSupported(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]) {
		FREObject result;

		uint32_t isSupportedByWin = 1;
		FRENewObjectFromBool(isSupportedByWin, &result);

		return result;
	}

	void contextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx, uint32_t* numFunctions, const FRENamedFunction** functions) {
		*numFunctions = 2;
		FRENamedFunction* func = (FRENamedFunction*)malloc(sizeof(FRENamedFunction) * (*numFunctions));

		func[0].name = (const uint8_t*) "isSupported";
		func[0].functionData = NULL;
		func[0].function = &isSupported;
		*functions = func;

		func[1].name = (const uint8_t*) "getWifiTags";
		func[1].functionData = NULL;
		func[1].function = &getWifiTags;
		*functions = func;
	}

	void contextFinalizer(FREContext ctx) {
		return;
	}

	void initializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer) {
		*ctxInitializer = &contextInitializer;
		*ctxFinalizer = &contextFinalizer;
	}

	void finalizer(void* extData) {
		return;
	}

}
