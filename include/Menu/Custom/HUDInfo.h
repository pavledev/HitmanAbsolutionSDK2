#pragma once

#include <iostream>
#include <string>
#include "imgui.h"
#include "ZHUDManager.h"
#include "Globals.h"

using namespace std;
using namespace UserFBInventoryInfoNamesp;

struct HUDInfo
{
	char inputBuffer[256] = { 0 };

	void DrawWindow(bool* showHUDInfo);

	const char* GetCrossHairType(ECrossHairType crossHairType);
	const char* GetItemType(eItemType itemType);
	const char* GetOperationMode(EOperationMode operationMode);

	void AddWeaponStatusInfo(SWeaponStatus* weaponStatus, int index);

	void DisplayText(ZHUDManager* hudManager);
};
