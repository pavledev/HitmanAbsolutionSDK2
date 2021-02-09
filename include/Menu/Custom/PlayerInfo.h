#pragma once

#include <iostream>
#include <string>
#include <map>
#include "imgui.h"
#include "ZCheckPointManager.h"
#include "ZLevelManager.h"
#include "ZOutfitConditionEntity.h"
#include "ZContentKitManager.h"
#include "TBinaryTreeIterator.h"
#include "TBinaryTreeNode.h"
#include "float4.h"
#include "ECameraMode.h"
#include "ZActorManager.h"
#include "ZKnowledge.h"
#include "ZHUDManager.h"
#include "SCameraState.h"
#include "ZHitman5Module.h"
#include "ZEntityManager.h"
#include "ZHM5ActionClient.h"
#include "ZConfigInt.h"
#include "TTypeIDHelper.h"
#include "EntityTypeHelper.h"
#include "Globals.h"
#include "NearestActorsInfo.h"

using namespace std;

struct PlayerInfo
{
	void DrawWindow(bool* showPlayerInfo);

	template<class T>
	void AddLocalPositionInputs(T* interfaceRef, ImGuiInputTextFlags& flags, ImVec4& color);

	template<class T>
	void AddWorldPositionInputs(T* interfaceRef, ImGuiInputTextFlags& flags, ImVec4& color);

	void AddGeneralInfo(ZHitman5* player);
	void AddActorInfo(TEntityRef<ZActor> entityRef, ImGuiInputTextFlags& flags, ImVec4& color);
	void AddCrowdEntityInfo(ZCrowdEntity* crowdEntity);
	void AddCrowdActorInfo(TEntityRef<ZCrowdActor> entityRef, ImVec4& color);
	void AddNearestActorsInfo(ImGuiInputTextFlags& flags, ImVec4& color, ZHitman5* player);
	void AddIHM5ItemInfo(IHM5Item* item);
	void AddBaseInventoryInfo(ImVec4& color, ZHitman5* player);
	void AddActorInvetoryInfo(TArray<TEntityRef<IHM5Item>> m_inventory);
	void AddInvetorySlotInfo(ZInventorySlot* inventorySlot);
	void AddCurrentWeaponInfo(TEntityRef<IHM5ItemWeapon> currentWeapon, ImVec4& color);

	const char* GetMovementType(ZHitman5* player);
	const char* GetGameInputFlag(ZHitman5* player);

	const char* GetActorCCPreset(EActorCCPreset m_eActorCCPreset);
	const char* GetActorType(EActorType m_eActorType);
	const char* GetActorRank(EActorRank m_eActorRank);
	const char* GetActorGroup(EActorGroup m_eActorGroup);
	const char* GetActorDeathType(EActorDeathType actorDeathType);

	const char* GetItemSize(eItemSize itemSize);
	const char* GetItemHands(eItemHands itemHands);
	const char* GetItemHandsCoverAnimLayer(eItemHands itemHands);
	const char* GetItemType(eItemType itemType);

	const char* GetInventorySlotType(EInventorySlotType m_eSlotType);

	const char* GetWeaponType(eWeaponType weaponType);
	const char* GetWeaponAnimationCategory(EWeaponAnimationCategory weaponAnimationCategory);

	const char* GetCameraMode(ECameraMode cameraMode);

	void GetTeleportLocations();
	void AddTeleportInfo(ZHitman5* player);
	void GetOutfits();
	void AddOutfitInfo(ZHitman5* player);
	TEntityRef<ZGlobalOutfitKit> GetGlobalOutfitKit(STokenID tokenID);

	template<class T>
	void AddBaseCharacterInfo(T* interfaceRef);

	/*void AddBaseCharacterInfo(TEntityRef<ZHitman5> hitman);
	void AddBaseCharacterInfo(TEntityRef<ZActor> actor);*/

	static char* Strdup(const char* s);
};
