#pragma once

#include <iostream>
#include <string>
#include "imgui.h"
#include "ZKnowledge.h"
#include "EntityTypeHelper.h"
#include "TTypeIDHelper.h"
#include "ZHM5ActionManager.h"
#include "ZHM5ItemWeapon.h"
#include "ZHM5ItemCCWeapon.h"
#include "ZHM5ItemAmmo.h"
#include "Singletons.h"

using namespace std;

struct ItemsInfo
{
	ImGuiInputTextFlags flags;
	ImVec4 color;

	ItemsInfo();

	void DrawWindow(bool* showItemsInfo);

	void AddItemInfo(IHM5Item* item, ZEntityRef* entityRef, int itemIndex);
	void AddItemWeaponInfo(IHM5ItemWeapon* itemWeapon, ZEntityRef* entityRef, int itemIndex);
	void AddItemWeaponInfo(ZHM5ItemWeapon* itemWeapon, ZEntityRef* entityRef, int itemIndex);
	void AddItemCCWeaponInfo(ZHM5ItemCCWeapon* itemCCWeapon, ZEntityRef* entityRef, int itemIndex);
	void AddItemAmmoInfo(ZHM5ItemAmmo* itemAmmo, ZEntityRef* entityRef, int itemIndex);

	void AddLocalPositionInputs(ZSpatialEntity* spatialEntity, int itemIndex);
	void AddWorldPositionInputs(ZSpatialEntity* spatialEntity, int itemIndex);

	string GetTypeName(ZHM5Action* action);
	const char* GetItemSize(eItemSize itemSize);
	const char* GetItemHands(eItemHands itemHands);
	const char* GetItemHandsCoverAnimLayer(eItemHands itemHands);
	const char* GetItemType(eItemType itemType);
};
