#pragma once

#include <string>
#include "imgui.h"
#include "ZActorManager.h"
#include "ZInventorySlot.h"
#include "ZLevelManager.h"
#include "Globals.h"

using namespace std;

struct ActorsInfo
{
	void DrawWindow(bool* showActorsInfo);

	template<class A, int B>
	void AddActorsInfo(TMaxArray<A, B>& array, ZActorManager* actorManager);

	void AddActorsInfo(TArray<TEntityRef<ZActor>>& array);

	void AddLocalPositionInputs(ZActor* actor, ImGuiInputTextFlags& flags, ImVec4& color, int actorIndex);
	void AddWorldPositionInputs(ZActor* actor, ImGuiInputTextFlags& flags, ImVec4& color, int actorIndex);

	void AddActorInfo(TEntityRef<ZActor>* entityRef, ImGuiInputTextFlags& flags, ImVec4& color, int actorIndex);
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

	void KillAllActors(ZActorManager* actorManager);

	static char* Strdup(const char* s);
};