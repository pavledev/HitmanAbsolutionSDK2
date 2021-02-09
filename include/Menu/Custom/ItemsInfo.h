#pragma once

#include <iostream>
#include <string>
#include "imgui.h"
#include "ZKnowledge.h"
#include "EntityTypeHelper.h"
#include "TTypeIDHelper.h"
#include "ZActorManager.h"
#include "Globals.h"

using namespace std;

struct ItemsInfo
{
	void DrawWindow(bool* showItemsInfo);

	void AddItemInfo(ZSharedKnowledgeRef* sharedKnowledgeRef);
	void AddZHM5ItemWeaponInfo(ZHM5ItemWeapon* itemWeapon);

	const char* GetItemSize(eItemSize itemSize);
	const char* GetItemHands(eItemHands itemHands);
	const char* GetItemHandsCoverAnimLayer(eItemHands itemHands);
	const char* GetItemType(eItemType itemType);
};
