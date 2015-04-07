/**
* Copyright (C) 2015 John Salatas (jsalatas@gmail.com)
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License v3 (LGPL-3)
* as published by the Free Software Foundation.
*
*/

#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <wlanapi.h>
#include <objbase.h>
#include <wtypes.h>

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>

// Need to link with Wlanapi.lib and Ole32.lib
#pragma comment(lib, "wlanapi.lib")
#pragma comment(lib, "ole32.lib")

std::wstring getTags() {

	// Declare and initialize variables.
	std::wstring json;
	wchar_t ssid_name[256];
	HANDLE hClient = NULL;
	DWORD dwMaxClient = 2; //
	DWORD dwCurVersion = 0;
	DWORD dwResult = 0;
	DWORD dwRetVal = 0;
	int iRet = 0;
	int first_enty = 1;

	WCHAR GuidString[39] = { 0 };

	unsigned int j, k;
	std::wstringstream wstr;

	/* variables used for WlanEnumInterfaces  */

	PWLAN_INTERFACE_INFO_LIST pIfList = NULL;
	PWLAN_INTERFACE_INFO pIfInfo = NULL;

	PWLAN_AVAILABLE_NETWORK_LIST pBssList = NULL;
	PWLAN_AVAILABLE_NETWORK pBssEntry = NULL;

	int iRSSI = 0;
	wstr << L"{\"ssids\":[";

	dwResult = WlanOpenHandle(dwMaxClient, NULL, &dwCurVersion, &hClient);
	if (dwResult != ERROR_SUCCESS) {

	}
	else {

		dwResult = WlanEnumInterfaces(hClient, NULL, &pIfList);
		if (dwResult == ERROR_SUCCESS) {
			if ((int)pIfList->dwNumberOfItems > 0) {
				// TODO: we always use first interface. Need improvemenr

				pIfInfo = (WLAN_INTERFACE_INFO *)&pIfList->InterfaceInfo[0];

				dwResult = WlanGetAvailableNetworkList(hClient,
					&pIfInfo->InterfaceGuid, 0, NULL, &pBssList);

				if (dwResult == ERROR_SUCCESS) {

					for (j = 0; j < pBssList->dwNumberOfItems; j++) {
						pBssEntry = (WLAN_AVAILABLE_NETWORK *)&pBssList->Network[j];
						if (first_enty) {
							first_enty = 0;
						}
						else {
							wstr << L", ";
						}
						wstr << L"{\"name\":\"";

						if (pBssEntry->dot11Ssid.uSSIDLength > 0)
							for (k = 0; k < pBssEntry->dot11Ssid.uSSIDLength && k < 256; k++) {
							swprintf_s(ssid_name, 256, L"%c", (int)pBssEntry->dot11Ssid.ucSSID[k]);
							wstr << ssid_name;
							}
						wstr << L"\", \"strength\":";
						if (pBssEntry->wlanSignalQuality == 0)
							iRSSI = -100;
						else if (pBssEntry->wlanSignalQuality == 100)
							iRSSI = -50;
						else
							iRSSI = -100 + (pBssEntry->wlanSignalQuality / 2);


						wstr << iRSSI;
						wstr << L", \"connected\":";

						if (pBssEntry->dwFlags) {
							if (pBssEntry->dwFlags & WLAN_AVAILABLE_NETWORK_CONNECTED) {
								wstr << L"true";
							}
							else {
								wstr << L"false";
							}
						}
						else {
							wstr << L"false";
						}

						wstr << L"}";
					}
				}
			}

		}
		if (pBssList != NULL) {
			WlanFreeMemory(pBssList);
			pBssList = NULL;
		}

		if (pIfList != NULL) {
			WlanFreeMemory(pIfList);
			pIfList = NULL;
		}
	}
	wstr << L"]}";
	json.append(wstr.str());

	return json;
}

