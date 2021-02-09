#pragma once

#include <string>
#include "imgui.h"
#include "ZActor.h"
#include "ZInventorySlot.h"
#include "SNearEnemyCheckReq.h"
#include "ZLevelManager.h"
#include "Globals.h"

using namespace std;

struct NearestActorsInfo
{
	void DrawWindow(bool* showNearestActorsInfo);

	void AddNearestActorsInfo();
	void AddNearestCrowdActorsInfo();

	void AddLocalPositionInputs(ZActor* actor, ImGuiInputTextFlags& flags, ImVec4& color, int actorIndex);
	void AddWorldPositionInputs(ZActor* actor, ImGuiInputTextFlags& flags, ImVec4& color, int actorIndex);

	void AddNearestActorInfo(TEntityRef<ZActor>* entityRef, ImGuiInputTextFlags& flags, ImVec4& color, int actorIndex);
	void AddNearestCrowdActorInfo(TEntityRef<ZCrowdActor>* entityRef, ImGuiInputTextFlags& flags, ImVec4& color, int crowdActorIndex);
	void AddCrowdEntityInfo(ZCrowdEntity* crowdEntity, int crowdActorIndex);
	void AddIHM5ItemInfo(IHM5Item* item);
	void AddActorInvetoryInfo(TArray<TEntityRef<IHM5Item>> m_inventory);
	void AddInvetorySlotInfo(ZInventorySlot* inventorySlot);
	void AddCurrentWeaponInfo(TEntityRef<IHM5ItemWeapon> currentWeapon, ImVec4& color, int actorIndex);

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

	void AddBaseCharacterInfo(ZActor* actor);

	void KillAllActors(TList<SNearEnemyCheckReq>* list);

	static char* Strdup(const char* s);
};