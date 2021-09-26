#include "NearestActorsInfo.h"
#include "ZHM5CCProfile.h"
#include "ZCrowdEntity.h"
#include "ZCrowdActorCore.h"
#include "ZCrowdActorState.h"
#include "ZHitman5.h"
#include "IHM5ItemWeapon.h"
#include "eWeaponOperation.h"
#include "ZHM5ActorControl.h"
#include "TListNode.h"
#include "IHM5Item.h"

void NearestActorsInfo::DrawWindow(bool* showNearestNearestActorsInfo)
{
	ImGui::SetNextWindowSize(ImVec2(500, 440), ImGuiCond_FirstUseEver);

	if (!ImGui::Begin("Nearest Actors Info", showNearestNearestActorsInfo))
	{
		ImGui::End();
		return;
	}

	if (ImGui::BeginTabBar("##Tabs", ImGuiTabBarFlags_None))
	{
		if (ImGui::BeginTabItem("Nearest Actors"))
		{
			AddNearestActorsInfo();

			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Nearest Crowd Actors"))
		{
			AddNearestCrowdActorsInfo();

			ImGui::EndTabItem();
		}

		ImGui::EndTabBar();
	}

	ImGui::End();
}

void NearestActorsInfo::AddNearestActorsInfo()
{
	static ZLevelManager* levelManager = Singletons::GetLevelManager();
	ZHitman5* player = levelManager->GetHitman().GetRawPointer();

	if (!player)
	{
		return;
	}

	TList<SNearEnemyCheckReq> list = player->GetActorControl()->m_NearEnemyChecks;
	static int selected = 0;

	ImGui::BeginChild("left pane", ImVec2(150, 0), true);

	for (unsigned int i = 0; i < list.Size(); i++)
	{
		char label[128];

		sprintf_s(label, "Actor %d", i);

		if (ImGui::Selectable(label, selected == i))
		{
			selected = i;
		}
	}

	ImGui::EndChild();
	ImGui::SameLine();

	ImGui::BeginGroup();
	ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()));

	if (ImGui::Button("Kill All Actors"))
	{
		KillAllActors(&list);
	}

	ImGui::Separator();

	ImGuiInputTextFlags flags = ImGuiInputTextFlags_EnterReturnsTrue;
	ImVec4 color = ImVec4(1.0f, 0.8f, 0.6f, 1.0f);

	ImGui::PushItemWidth(350);

	TListNode<SNearEnemyCheckReq>* current = list.m_list.m_pFirst;
	TListNode<SNearEnemyCheckReq>* last = list.m_list.m_pLast;
	TEntityRef<ZActor>* entityRef{};
	int i = 0;

	if (selected == 0)
	{
		AddNearestActorInfo(&current->m_data.m_pActor, flags, color, selected);
	}
	else
	{
		while ((current = current->m_pNext) != last)
		{
			if (i == selected)
			{
				entityRef = &current->m_data.m_pActor;

				break;
			}

			i++;
		}

		AddNearestActorInfo(entityRef, flags, color, selected);
	}

	ImGui::PopItemWidth();

	ImGui::EndChild();
	ImGui::EndGroup();
}

void NearestActorsInfo::AddNearestCrowdActorsInfo()
{
	static ZLevelManager* levelManager = Singletons::GetLevelManager();
	ZHitman5* player = levelManager->GetHitman().GetRawPointer();

	if (!player)
	{
		return;
	}

	TList<SNearEnemyCheckReq> list = player->m_pActorControl->m_NearEnemyChecks;
	static int selected = 0;

	ImGui::BeginChild("left pane", ImVec2(150, 0), true);

	for (unsigned int i = 0; i < list.Size(); i++)
	{
		char label[128];

		sprintf_s(label, "Actor %d", i);

		if (ImGui::Selectable(label, selected == i))
		{
			selected = i;
		}
	}

	ImGui::EndChild();
	ImGui::SameLine();

	ImGui::BeginGroup();
	ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()));

	ImGui::Separator();

	ImGuiInputTextFlags flags = ImGuiInputTextFlags_EnterReturnsTrue;
	ImVec4 color = ImVec4(1.0f, 0.8f, 0.6f, 1.0f);

	ImGui::PushItemWidth(350);

	TListNode<SNearEnemyCheckReq>* current = list.m_list.m_pFirst;
	TListNode<SNearEnemyCheckReq>* last = list.m_list.m_pLast;
	int i = 0;
	TEntityRef<ZCrowdActor>* entityRef{};

	if (selected == 0)
	{
		AddNearestCrowdActorInfo(&current->m_data.m_pCrowdActor, flags, color, selected);
	}
	else
	{
		while ((current = current->m_pNext) != last)
		{
			if (i == selected)
			{
				entityRef = &current->m_data.m_pCrowdActor;

				break;
			}

			i++;
		}

		AddNearestCrowdActorInfo(entityRef, flags, color, selected);
	}

	ImGui::PopItemWidth();

	ImGui::EndChild();
	ImGui::EndGroup();
}

void NearestActorsInfo::AddLocalPositionInputs(ZActor* actor, ImGuiInputTextFlags& flags, ImVec4& color, int actorIndex)
{
	ImGui::TextColored(color, "Local Position");

	float4 localPosition = actor->GetSpatialEntityPtr()->GetLocalPosition();

	ImGui::Text("X");
	ImGui::SameLine();

	static string label1 = "##localPositionX" + to_string(actorIndex);

	if (ImGui::InputFloat(label1.c_str(), &localPosition.x(), 0, 0, "%.3f", flags))
	{
		actor->GetSpatialEntityPtr()->SetLocalPosition(localPosition);
	}

	ImGui::SameLine();
	ImGui::Text("Y");
	ImGui::SameLine();

	static string label2 = "##localPositionY" + to_string(actorIndex);

	if (ImGui::InputFloat(label2.c_str(), &localPosition.y(), 0, 0, "%.3f", flags))
	{
		actor->GetSpatialEntityPtr()->SetLocalPosition(localPosition);
	}

	ImGui::SameLine();
	ImGui::Text("Z");
	ImGui::SameLine();

	static string label3 = "##localPositionZ" + to_string(actorIndex);

	if (ImGui::InputFloat(label3.c_str(), &localPosition.z(), 0, 0, "%.3f", flags))
	{
		actor->GetSpatialEntityPtr()->SetLocalPosition(localPosition);
	}

	ImGui::SameLine();
	ImGui::Text("W");
	ImGui::SameLine();

	static string label4 = "##localPositionW" + to_string(actorIndex);

	if (ImGui::InputFloat(label4.c_str(), &localPosition.w(), 0, 0, "%.3f", flags))
	{
		actor->GetSpatialEntityPtr()->SetLocalPosition(localPosition);
	}
}

void NearestActorsInfo::AddWorldPositionInputs(ZActor* actor, ImGuiInputTextFlags& flags, ImVec4& color, int actorIndex)
{
	ImGui::TextColored(color, "World Position");

	float4 worldPosition = actor->GetSpatialEntityPtr()->GetWorldPosition();

	ImGui::Text("X");
	ImGui::SameLine();

	static string label1 = "##wordPositionX" + to_string(actorIndex);

	if (ImGui::InputFloat(label1.c_str(), &worldPosition.x(), 0, 0, "%.3f", flags))
	{
		actor->GetSpatialEntityPtr()->SetWorldPosition(worldPosition);
	}

	ImGui::SameLine();
	ImGui::Text("Y");
	ImGui::SameLine();

	static string label2 = "##wordPositionY" + to_string(actorIndex);

	if (ImGui::InputFloat(label2.c_str(), &worldPosition.y(), 0, 0, "%.3f", flags))
	{
		actor->GetSpatialEntityPtr()->SetWorldPosition(worldPosition);
	}

	ImGui::SameLine();
	ImGui::Text("Z");
	ImGui::SameLine();

	static string label3 = "##wordPositionZ" + to_string(actorIndex);

	if (ImGui::InputFloat(label3.c_str(), &worldPosition.z(), 0, 0, "%.3f", flags))
	{
		actor->GetSpatialEntityPtr()->SetWorldPosition(worldPosition);
	}

	ImGui::SameLine();
	ImGui::Text("W");
	ImGui::SameLine();

	static string label4 = "##wordPositionW" + to_string(actorIndex);

	if (ImGui::InputFloat(label4.c_str(), &worldPosition.w(), 0, 0, "%.3f", flags))
	{
		actor->GetSpatialEntityPtr()->SetWorldPosition(worldPosition);
	}
}

const char* NearestActorsInfo::GetActorCCPreset(EActorCCPreset m_eActorCCPreset)
{
	const char* type{};

	switch (m_eActorCCPreset)
	{
	case ACCP_CivilianFemale:
		type = "Civilian Female";
		break;
	case ACCP_CivilianeMale:
		type = "Civiliane Male";
		break;
	case ACCP_GuardMale:
		type = "Guard Male";
		break;
	case ACCP_GuardMaleElite:
		type = "Guard Male Elite";
		break;
	case ACCP_GuardMaleSuperElite:
		type = "Guard Male Super Elite";
		break;
	case ACCP_BossDexter:
		type = "Boss Dexter";
		break;
	case ACCP_BossSanchez:
		type = "Boss Sanchez";
		break;
	case ACCP_BossLenny:
		type = "Boss Lenny";
		break;
	case ACCP_Ignore:
		type = "Ignore";
		break;
	case ACCP_None:
		type = "None";
		break;
	}

	return type;
}

const char* NearestActorsInfo::GetActorGroup(EActorGroup m_eActorGroup)
{
	const char* type{};

	switch (m_eActorGroup)
	{
	case eAG_Group_A:
		type = "Group_ A";
		break;
	case eAG_Group_B:
		type = "Group_ B";
		break;
	case eAG_Group_C:
		type = "Group_ C";
		break;
	case eAG_Group_D:
		type = "Group_ D";
		break;
	case eAG_Count:
		type = "Count";
		break;
	}

	return type;
}

const char* NearestActorsInfo::GetActorRank(EActorRank m_eActorRank)
{
	const char* type{};

	switch (m_eActorRank)
	{
	case AR_Default:
		type = "Default";
		break;
	case AR_Elite:
		type = "Elite";
		break;
	case AR_Cop:
		type = "Cop";
		break;
	case AR_Goon:
		type = "Goon";
		break;
	}

	return type;
}

const char* NearestActorsInfo::GetActorType(EActorType m_eActorType)
{
	const char* type{};

	switch (m_eActorType)
	{
	case eAT_Civilian:
		type = "Civilian";
		break;
	case eAT_Guard:
		type = "Guard";
		break;
	case eAT_Hitman:
		type = "Hitman";
		break;
	case eAT_Last:
		type = "Last";
		break;
	}

	return type;
}

const char* NearestActorsInfo::GetActorDeathType(EActorDeathType actorDeathType)
{
	const char* type{};

	switch (actorDeathType)
	{
	case eADT_UNDEFINED:
		type = "Undefined";
		break;
	case eADT_INVISIBLE:
		type = "Invisible";
		break;
	case eADT_ACCIDENT:
		type = "Accident";
		break;
	case eADT_PACIFIED:
		type = "Pacified";
		break;
	case eADT_PACIFIEDACCIDENT:
		type = "Pacified Accident";
		break;
	case eADT_MURDER:
		type = "Murder";
		break;
	case eADT_BLOODY_MURDER:
		type = "Bloody Murder";
		break;
	}

	return type;
}

const char* NearestActorsInfo::GetItemSize(eItemSize itemSize)
{
	const char* type{};

	switch (itemSize)
	{
	case ITEMSIZE_SMALL:
		type = "Small";
		break;
	case ITEMSIZE_LARGE:
		type = "Large";
		break;
	case ITEMSIZE_HUGE:
		type = "Huge";
		break;
	}

	return type;
}

const char* NearestActorsInfo::GetItemHands(eItemHands itemHands)
{
	const char* type{};

	switch (itemHands)
	{
	case IH_NONE:
		type = "None";
		break;
	case IH_ONEHANDED:
		type = "One-handed";
		break;
	case IH_TWOHANDED:
		type = "Two-handed";
		break;
	}

	return type;
}

const char* NearestActorsInfo::GetItemHandsCoverAnimLayer(eItemHands itemHands)
{
	const char* type{};

	switch (itemHands)
	{
	case IH_NONE:
		type = "None";
		break;
	case IH_ONEHANDED:
		type = "One-handed";
		break;
	case IH_TWOHANDED:
		type = "Two-handed";
		break;
	}

	return type;
}

const char* NearestActorsInfo::GetItemType(eItemType itemType)
{
	const char* type{};

	switch (itemType)
	{
	case eCC_FireExtinguisher_01:
		type = "Fire Extinguisher_01";
		break;
	case eCC_Knife:
		type = "Knife";
		break;
	case eCC_Axe:
		type = "Axe";
		break;
	case eCC_PetrolCan:
		type = "Petrol Can";
		break;
	case eCC_Shovel:
		type = "Shovel";
		break;
	case eCC_Hammer:
		type = "Hammer";
		break;
	case eCC_Cleaver:
		type = "Cleaver";
		break;
	case eCC_AntitankMine:
		type = "Antitank Mine";
		break;
	case eCC_C4Brick:
		type = "C4 Brick";
		break;
	case eCC_RemoteExplosive:
		type = "Remote Explosive";
		break;
	case eDetonator:
		type = "Detonator";
		break;
	case eCC_Wrench:
		type = "Wrench";
		break;
	case eCC_Dildo:
		type = "Dildo";
		break;
	case eCC_Bottle:
		type = "Bottle";
		break;
	case eCC_Saw:
		type = "Saw";
		break;
	case eCC_Screwdriver:
		type = "Screwdriver";
		break;
	case eCC_MetalPipe:
		type = "Metal Pipe";
		break;
	case eCC_Gavel:
		type = "Gavel";
		break;
	case eCC_Radio:
		type = "Radio";
		break;
	case eCC_Bong:
		type = "Bong";
		break;
	case eCC_Statue_Bust_A:
		type = "Statue_ Bust_ A";
		break;
	case eGun_44AutoMag:
		type = "Gun_44 Auto Mag";
		break;
	case eGun_44AutoMagSilenced:
		type = "Gun_44 Auto Mag Silenced";
		break;
	case eGun_Derringer:
		type = "Gun_ Derringer";
		break;
	case eGun_Glock:
		type = "Gun_ Glock";
		break;
	case eGun_GlockDirty:
		type = "Gun_ Glock Dirty";
		break;
	case eGun_GlockSilenced:
		type = "Gun_ Glock Silenced";
		break;
	case eGun_HardBaller_01:
		type = "Gun_ Hard Baller_01";
		break;
	case eGun_HardBallerSilenced:
		type = "Gun_ Hard Baller Silenced";
		break;
	case eGun_Sig226:
		type = "Gun_ Sig226";
		break;
	case eGun_Sig226Silenced:
		type = "Gun_ Sig226 Silenced";
		break;
	case eGun_Sphinx3000:
		type = "Gun_ Sphinx3000";
		break;
	case eGun_Taurus24_7:
		type = "Gun_ Taurus24_7";
		break;
	case eGun_Taurus24_7Silenced:
		type = "Gun_ Taurus24_7 Silenced";
		break;
	case eGun_Spotter:
		type = "Gun_ Spotter";
		break;
	case eOther_MG:
		type = "Other_ MG";
		break;
	case eOther_RPG:
		type = "Other_ RPG";
		break;
	case eRevolver_PoliceRevolver:
		type = "Revolver_ Police Revolver";
		break;
	case eRevolver_Snubnosed:
		type = "Revolver_ Snubnosed";
		break;
	case eRevolver_Taurus:
		type = "Revolver_ Taurus";
		break;
	case eRifle_HK416:
		type = "Rifle_ H K416";
		break;
	case eRifle_HK416Scope:
		type = "Rifle_ H K416 Scope";
		break;
	case eRifle_HK416Silenced:
		type = "Rifle_ H K416 Silenced";
		break;
	case eRifle_PumpRifle:
		type = "Rifle_ Pump Rifle";
		break;
	case eRifle_SG552:
		type = "Rifle_ S G552";
		break;
	case eRifle_SG552Scope:
		type = "Rifle_ S G552 Scope";
		break;
	case eShotgun_M500:
		type = "Shotgun_ M500";
		break;
	case eShotgun_M500New:
		type = "Shotgun_ M500 New";
		break;
	case eSMG_HK_UMP:
		type = "SM G_ H K_ UMP";
		break;
	case eSMG_HK_UMPFlashlight:
		type = "SM G_ H K_ UMP Flashlight";
		break;
	case eSMG_HK_UMPScope:
		type = "SM G_ H K_ UMP Scope";
		break;
	case eSMG_HK_UMPSilenced:
		type = "SM G_ H K_ UMP Silenced";
		break;
	case eSMG_TMP:
		type = "SM G_ TMP";
		break;
	case eSniper_AS50:
		type = "Sniper_ A S50";
		break;
	case eSniper_Remington700:
		type = "Sniper_ Remington700";
		break;
	case eSniper_SakoTRG:
		type = "Sniper_ Sako TRG";
		break;
	case eSniper_SakoTRGSilenced:
		type = "Sniper_ Sako TRG Silenced";
		break;
	case eItemAmmo:
		type = "Item Ammo";
		break;
	case eCC_FiberWire:
		type = "Fiber Wire";
		break;
	case eOther_ZippoLighter:
		type = "Other_ Zippo Lighter";
		break;
	case eOther_Keycard_A:
		type = "Other_ Keycard_ A";
		break;
	case eOther_SecurityTape:
		type = "Other_ Security Tape";
		break;
	case eCC_PowerCord:
		type = "Power Cord";
		break;
	case eCC_PoliceBaton:
		type = "Police Baton";
		break;
	case eCC_Scissor:
		type = "Scissor";
		break;
	case eOther_ContractEnvelope:
		type = "Other_ Contract Envelope";
		break;
	case eItemIrrelevantWeapon:
		type = "Item Irrelevant Weapon";
		break;
	case eCC_BaseballBat:
		type = "Baseball Bat";
		break;
	case eCC_GlassShiv:
		type = "Glass Shiv";
		break;
	case eCC_PoolCue:
		type = "Pool Cue";
		break;
	case eCC_Rake:
		type = "Rake";
		break;
	case eCC_ToyCar:
		type = "Toy Car";
		break;
	case eCC_Crutch:
		type = "Crutch";
		break;
	case eCC_Guitar:
		type = "Guitar";
		break;
	case eCC_Iron:
		type = "Iron";
		break;
	case eRifle_Beretta_ARX160:
		type = "Rifle_ Beretta_ AR X160";
		break;
	case eShotgun_Spas12:
		type = "Shotgun_ Spas12";
		break;
	case eShotgun_Spas12_Compact:
		type = "Shotgun_ Spas12_ Compact";
		break;
	case eShotgun_Silenced:
		type = "Shotgun_ Silenced";
		break;
	case eSMG_AK74u:
		type = "SM G_ A K74u";
		break;
	case eSMG_STK:
		type = "SM G_ STK";
		break;
	case eDLC_TEST_FireArm_01:
		type = "DL C_ TES T_ Fire Arm_01";
		break;
	case eDLC_TEST_FireArm_02:
		type = "DL C_ TES T_ Fire Arm_02";
		break;
	case eDLC_TEST_Prop_01:
		type = "DL C_ TES T_ Prop_01";
		break;
	case eDLC_TEST_Prop_02:
		type = "DL C_ TES T_ Prop_02";
		break;
	case eHotSauceBarrel:
		type = "Hot Sauce Barrel";
		break;
	case eOther_GenericPickup:
		type = "Other_ Generic Pickup";
		break;
	case eCC_SledgeHammer:
		type = "Sledge Hammer";
		break;
	case eCC_Katana:
		type = "Katana";
		break;
	case eCC_Brick:
		type = "Brick";
		break;
	case cCC_Book_A:
		type = "Book_ A";
		break;
	case eUnknownItemType:
		type = "Unknown Item Type";
		break;
	}

	return type;
}

void NearestActorsInfo::AddIHM5ItemInfo(IHM5Item* item)
{
	if (!item)
	{
		return;
	}

	ImGui::Text("Item Size: %s", GetItemSize(item->GetItemSize()));
	ImGui::Text("Item Hands: %s", GetItemHands(item->GetItemHands()));
	ImGui::Text("Item Hands Cover Anim Layer: %s", GetItemHandsCoverAnimLayer(item->GetItemHandsCoverAnimLayer()));
	ImGui::Text("Item Type: %s", GetItemType(item->GetItemType()));

	ZString itemTypeName = item->GetItemTypeName();

	ImGui::Text("Item Type Name: %s", itemTypeName.ToCString());

	if (item->IsInventoryItem())
	{
		ImGui::Text("Is Inventory Item: Yes");
	}
	else
	{
		ImGui::Text("Is Inventory Item: No");
	}

	if (item->IsInspectItem())
	{
		ImGui::Text("Is Inspect Item: Yes");
	}
	else
	{
		ImGui::Text("Is Inspect Item: No");
	}

	if (item->ItemHidden())
	{
		ImGui::Text("Item Hidden: Yes");
	}
	else
	{
		ImGui::Text("Item Hidden: No");
	}

	ZString debugName = item->GetDebugName();

	ImGui::Text("Debug Name: %s", debugName.ToCString());

	if (item->IsThrown())
	{
		ImGui::Text("Is Thrown: Yes");
	}
	else
	{
		ImGui::Text("Is Thrown: No");
	}

	if (item->IsPercievedAsWeapon())
	{
		ImGui::Text("Is Percieved As Weapon: Yes");
	}
	else
	{
		ImGui::Text("Is Percieved As Weapon: No");
	}

	if (item->CanBeDualWielded())
	{
		ImGui::Text("Can Be Dual Wielded: Yes");
	}
	else
	{
		ImGui::Text("Can Be Dual Wielded: No");
	}

	ImGui::Text("");
}

const char* NearestActorsInfo::GetInventorySlotType(ZInventorySlot::EInventorySlotType m_eSlotType)
{
	const char* type{};

	switch (m_eSlotType)
	{
	case ZInventorySlot::EInventorySlotType::eSilverBallerSlot:
		type = "Silver Baller Slot";
		break;
	case ZInventorySlot::EInventorySlotType::eHandgunSlot:
		type = "Handgun Slot";
		break;
	case ZInventorySlot::EInventorySlotType::eRevolverSlot:
		type = "Revolver Slot";
		break;
	case ZInventorySlot::EInventorySlotType::eRifleSlot:
		type = "Rifle Slot";
		break;
	case ZInventorySlot::EInventorySlotType::eSniperSlot:
		type = "Sniper Slot";
		break;
	case ZInventorySlot::EInventorySlotType::eSmgSlot:
		type = "Smg Slot";
		break;
	case ZInventorySlot::EInventorySlotType::eShotgunSlot:
		type = "Shotgun Slot";
		break;
	case ZInventorySlot::EInventorySlotType::eFiberwireSlot:
		type = "Fiberwire Slot";
		break;
	case ZInventorySlot::EInventorySlotType::eCCPropSlot:
		type = "CC Prop Slot";
		break;
	case ZInventorySlot::EInventorySlotType::eRemoteControlled:
		type = "Remote Controlled";
		break;
	case ZInventorySlot::EInventorySlotType::eOther:
		type = "Other";
		break;
	}

	return type;
}

const char* NearestActorsInfo::GetWeaponType(eWeaponType weaponType)
{
	const char* type{};

	switch (weaponType)
	{
	case WT_HANDGUN:
		type = "Handgun";
		break;
	case WT_SLOWGUN:
		type = "Slowgun";
		break;
	case WT_ASSAULTRIFLE:
		type = "Assault Riffle";
		break;
	case WT_SMG:
		type = "SMG";
		break;
	case WT_SNIPER:
		type = "Sniper";
		break;
	case WT_RPG:
		type = "RPG";
		break;
	case WT_KNIFE:
		type = "Knife";
		break;
	case WT_SHOTGUN:
		type = "Shotgun";
		break;
	case WT_SPOTTER:
		type = "Spotter";
		break;
	}

	return type;
}

const char* NearestActorsInfo::GetWeaponAnimationCategory(EWeaponAnimationCategory weaponAnimationCategory)
{
	const char* type{};

	switch (weaponAnimationCategory)
	{
	case eWAC_Undefined:
		type = "Undefined";
		break;
	case eWAC_Pistol:
		type = "Pistol";
		break;
	case eWAC_Revolver:
		type = "Revolver";
		break;
	case eWAC_SMG_2H:
		type = "SMG_2H";
		break;
	case eWAC_SMG_1H:
		type = "SMG_1H";
		break;
	case eWAC_Rifle:
		type = "Rifle";
		break;
	case eWAC_Sniper:
		type = "Sniper";
		break;
	case eWAC_Shotgun_Pump:
		type = "Shotgun_Pump";
		break;
	case eWAC_Shotgun_Semi:
		type = "Shotgun_Semi";
		break;
	}

	return type;
}

void NearestActorsInfo::AddInvetorySlotInfo(ZInventorySlot* inventorySlot)
{
	if (!inventorySlot)
	{
		return;
	}

	const char* inventorySlotType = GetInventorySlotType(inventorySlot->GetType());

	ImGui::Text("Inventory Slot Type: %s", inventorySlotType);
	ImGui::Text("");
	ImGui::Text("Weapon Set");

	ZHM5WeaponSet weaponSet = inventorySlot->GetWeaponSet();
	int itemsSize = IM_ARRAYSIZE(weaponSet.m_rItems);

	for (int i = 0; i < itemsSize; i++)
	{
		AddIHM5ItemInfo(weaponSet.m_rItems[i].GetRawPointer());
	}

	static bool canDualWield = weaponSet.m_bCanDualWield;
	static bool dualWieldMode = weaponSet.m_bDualWieldMode;

	ImGui::Checkbox("Can Dual Wield", &canDualWield);
	ImGui::Checkbox("Dual Wield Mode", &dualWieldMode);

	weaponSet.m_bCanDualWield = canDualWield;
	weaponSet.m_bDualWieldMode = dualWieldMode;
}

void NearestActorsInfo::AddCurrentWeaponInfo(TEntityRef<IHM5ItemWeapon> currentWeapon, ImVec4& color, int actorIndex)
{
	ImGui::TextColored(color, "Current Weapon");

	IHM5ItemWeapon* weapon = currentWeapon.GetRawPointer();

	if (!weapon)
	{
		return;
	}

	if (weapon->IsFiring())
	{
		ImGui::Text("Is Firing: Yes");
	}
	else
	{
		ImGui::Text("Is Firing: No");
	}

	ImGui::Separator();

	static bool semiAutomatic = false, fullAutomatic = false;

	ImGui::RadioButton("Semi-Automatic", &semiAutomatic);
	ImGui::RadioButton("Full-Automatic", &fullAutomatic);

	eWeaponOperation weaponOperation;

	if (semiAutomatic)
	{
		weaponOperation = eWeaponOperation::WO_SEMI_AUTO;
	}
	else if (fullAutomatic)
	{
		weaponOperation = eWeaponOperation::WO_FULL_AUTO;
	}

	if (ImGui::Button("Set Weapon Operation"))
	{
		weapon->SetWeaponOperation(weaponOperation, true);
	}

	ImGui::Text("AI Near Combat Range: %f", weapon->GetAINearCombatRange());
	ImGui::Text("AI Far Combat Range: %f", weapon->GetAIFarCombatRange());

	ImGui::Text("Bullets In Magazine");
	ImGui::SameLine();

	static string label = "##BulletsInMagazine" + to_string(actorIndex);
	static unsigned short bulletsInMagazine = weapon->GetBulletsInMagazine();

	ImGui::InputScalar(label.c_str(), ImGuiDataType_U16, &bulletsInMagazine);

	weapon->SetBulletsInMagazine(bulletsInMagazine);

	if (weapon->IsCurrentClipLowOnAmmo())
	{
		ImGui::Text("Is Current Clip Low On Ammo: Yes");
	}
	else
	{
		ImGui::Text("Is Current Clip Low On Ammo: No");
	}

	if (weapon->GetFiringStarted())
	{
		ImGui::Text("Firing Started: Yes");
	}
	else
	{
		ImGui::Text("Firing Started: No");
	}

	if (weapon->IsHandGun())
	{
		ImGui::Text("Is HandGun: Yes");
	}
	else
	{
		ImGui::Text("Is HandGun: No");
	}

	if (weapon->IsRevolver())
	{
		ImGui::Text("Is Revolver: Yes");
	}
	else
	{
		ImGui::Text("Is Revolver: No");
	}

	if (weapon->IsSmg())
	{
		ImGui::Text("Is Smg: Yes");
	}
	else
	{
		ImGui::Text("Is Smg: No");
	}

	if (weapon->IsRifle())
	{
		ImGui::Text("Is Rifle: Yes");
	}
	else
	{
		ImGui::Text("Is Rifle: No");
	}

	if (weapon->IsRPG())
	{
		ImGui::Text("Is RPG: Yes");
	}
	else
	{
		ImGui::Text("Is RPG: No");
	}

	if (weapon->IsSniper())
	{
		ImGui::Text("Is Sniper: Yes");
	}
	else
	{
		ImGui::Text("Is Sniper: No");
	}

	if (weapon->IsShotgun())
	{
		ImGui::Text("Is Shotgun: Yes");
	}
	else
	{
		ImGui::Text("Is Shotgun: No");
	}

	if (weapon->IsFireArm())
	{
		ImGui::Text("Is FireArm: Yes");
	}
	else
	{
		ImGui::Text("Is FireArm: No");
	}

	if (weapon->IsProjectileWeapon())
	{
		ImGui::Text("Is Projectile Weapon: Yes");
	}
	else
	{
		ImGui::Text("Is Projectile Weapon: No");
	}

	if (weapon->IsCloseCombatWeapon())
	{
		ImGui::Text("Is Close Combat Weapon: Yes");
	}
	else
	{
		ImGui::Text("Is Close Combat Weapon: No");
	}

	if (weapon->IsFiberwire())
	{
		ImGui::Text("Is Fiberwire: Yes");
	}
	else
	{
		ImGui::Text("Is Fiberwire: No");
	}

	eWeaponType weaponType = weapon->GetWeaponType();
	eItemType itemType = weapon->GetItemType();
	EWeaponAnimationCategory weaponAnimationCategory = weapon->GetAnimationCategory();

	ImGui::Text("Weapon Type: %s", GetWeaponType(weaponType));
	ImGui::Text("Weapon Type: %s", GetItemType(itemType));
	ImGui::Text("Weapon Animation Category: %s", GetWeaponAnimationCategory(weaponAnimationCategory));

	if (weapon->NeedReloading())
	{
		ImGui::Text("Need Reloading: Yes");
	}
	else
	{
		ImGui::Text("Need Reloading: No");
	}

	if (weapon->IsAutoreloadEnabled())
	{
		ImGui::Text("Is Autoreload Enabled: Yes");
	}
	else
	{
		ImGui::Text("Is Autoreload Enabled: No");
	}
}

void NearestActorsInfo::AddActorInvetoryInfo(TArray<TEntityRef<IHM5Item>> inventory)
{
	TEntityRef<IHM5Item>* current = inventory.m_pStart;

	if (!current)
	{
		ImGui::Text("Inventory is empty.");

		return;
	}

	TEntityRef<IHM5Item>* end = inventory.m_pEnd;

	while (current != end)
	{
		IHM5Item* item = current->GetRawPointer();

		AddIHM5ItemInfo(item);

		current++;
	}
}

void NearestActorsInfo::AddNearestActorInfo(TEntityRef<ZActor>* entityRef, ImGuiInputTextFlags& flags, ImVec4& color, int actorIndex)
{
	if (!entityRef)
	{
		return;
	}

	ZActor* actor = entityRef->GetRawPointer();

	if (!actor)
	{
		return;
	}

	ImGui::TextColored(color, "General");
	ImGui::Text("");

	if (ImGui::Button("Teleport Actor To Player"))
	{
		static ZLevelManager* levelManager = Singletons::GetLevelManager();
		ZHitman5* player = levelManager->GetHitman().GetRawPointer();

		if (player)
		{
			float4 playerLocalPosition = player->GetSpatialEntityPtr()->GetLocalPosition();

			actor->GetSpatialEntityPtr()->SetLocalPosition(playerLocalPosition);
		}
	}

	ImGui::TextColored(color, "CC Profile");

	ZHM5CCProfile* profile = actor->m_rCCProfile.GetRawPointer();

	if (profile)
	{
		ImGui::Text("Attacks For TakeDown");
		ImGui::SameLine();

		static string label1 = "##AttacksForTakeDown" + to_string(actorIndex);

		ImGui::InputInt(label1.c_str(), &profile->m_nAttacksForTakeDown);

		ImGui::Text("Hitman Damage");
		ImGui::SameLine();

		static string label2 = "##HitmanDamage" + to_string(actorIndex);

		ImGui::InputFloat(label2.c_str(), &profile->m_fHitmanDamage);

		ImGui::Checkbox("Allow Attacking Hitman", &profile->m_bAllowAttackingHitman);
		ImGui::Text("Actor Preset: %s", GetActorCCPreset(profile->m_eActorCCPreset));
	}
	else
	{
		ImGui::Text("No CC Profile info available.");
	}

	ImGui::Separator();

	ImGui::Checkbox("Start Enabled", &actor->m_bStartEnabled);
	ImGui::Checkbox("Preferred Investigator", &actor->m_bPreferredInvestigator);
	ImGui::Checkbox("Start Agitated", &actor->m_bStartAgitated);
	ImGui::Checkbox("Allow Agitated Ambient", &actor->m_bAllowAgitatedAmbient);
	ImGui::Checkbox("Can Call For Help", &actor->m_bCanCallForHelp);
	ImGui::Checkbox("Drop Weapons", &actor->m_bDropWeapons);
	ImGui::Checkbox("Preferred Accident Investigator", &actor->m_bPreferredAccidentInvestigator);
	ImGui::Checkbox("Accident Shy", &actor->m_bAccidentShy);

	ImGui::Separator();

	ImGui::Text("Actor Name: %s", actor->GetActorName().ToCString());
	ImGui::Text("Actor Type: %s", GetActorType(actor->GetActorType()));
	ImGui::Text("Actor Rank: %s", GetActorRank(actor->GetActorRank()));
	ImGui::Text("Actor Group: %s", GetActorGroup(actor->GetActorGroup()));

	ImGui::Separator();

	ImGui::Checkbox("Contracts Eligible", &actor->m_bContractsEligible);
	ImGui::Checkbox("Difficulty_Level1", &actor->m_eDifficulty_Level1);
	ImGui::Checkbox("Difficulty_Level2", &actor->m_eDifficulty_Level2);
	ImGui::Checkbox("Difficulty_Level3", &actor->m_eDifficulty_Level3);
	ImGui::Checkbox("Difficulty_Level4", &actor->m_eDifficulty_Level4);

	ImGui::Separator();

	ImGui::Checkbox("Enable Face Mood In Sequence", &actor->m_bEnableFaceMoodInSequence);
	ImGui::Checkbox("Noticed When Killed", &actor->m_bNoticedWhenKilled);

	if (actor->IsAlive())
	{
		static bool undefined = true, invisible = false, accident = false, pacified = false, pacifiedAccident = false, murder = false,
			bloodyMurder = false;
		static bool deathVisible = true;
		static EActorDeathType actorDeathType;

		ImGui::RadioButton("Undefined", &undefined);
		ImGui::RadioButton("Invisiable", &invisible);
		ImGui::RadioButton("Accident", &accident);
		ImGui::RadioButton("Pacified", &pacified);
		ImGui::RadioButton("Pacified Accident", &pacifiedAccident);
		ImGui::RadioButton("Murder", &murder);
		ImGui::RadioButton("Bloody Murder", &bloodyMurder);

		ImGui::Checkbox("Death Visible", &deathVisible);

		if (undefined)
		{
			actorDeathType = EActorDeathType::eADT_UNDEFINED;
		}
		else if (invisible)
		{
			actorDeathType = EActorDeathType::eADT_INVISIBLE;
		}
		else if (accident)
		{
			actorDeathType = EActorDeathType::eADT_ACCIDENT;
		}
		else if (pacified)
		{
			actorDeathType = EActorDeathType::eADT_PACIFIED;
		}
		else if (pacifiedAccident)
		{
			actorDeathType = EActorDeathType::eADT_PACIFIEDACCIDENT;
		}
		else if (murder)
		{
			actorDeathType = EActorDeathType::eADT_MURDER;
		}
		else if (bloodyMurder)
		{
			actorDeathType = EActorDeathType::eADT_BLOODY_MURDER;
		}

		if (ImGui::Button("Kill Actor"))
		{
			actor->KillActor(actorDeathType, deathVisible);
		}
	}

	if (actor->HasBeenPacified())
	{
		ImGui::Text("Has Been Pacified: Yes");
	}
	else
	{
		ImGui::Text("Has Been Pacified: No");
	}

	if (actor->IsDeadTarget())
	{
		ImGui::Text("Is Dead Target: Yes");
	}
	else
	{
		ImGui::Text("Is Dead Target: No");
	}

	if (actor->IsPacified())
	{
		ImGui::Text("Is Pacified: Yes");
	}
	else
	{
		ImGui::Text("Is Pacified: No");
	}

	if (ImGui::Button("Attach Weapons To Holsters"))
	{
		actor->AttachWeaponsToHolsters();
	}

	ImGui::Separator();

	static bool dropWeapon = false;

	ImGui::Checkbox("Drop Weapon", &dropWeapon);

	if (ImGui::Button("Drop Attached Items"))
	{
		actor->DropAttachedItems(dropWeapon);
	}

	ImGui::Separator();

	if (actor->m_runtimeInventory.m_pStart)
	{
		if (actor->HasHandGun())
		{
			ImGui::Text("Has HandGun: Yes");
		}
		else
		{
			ImGui::Text("Has Hand Gun: No");
		}
	}

	if (ImGui::Button("Holster Weapon"))
	{
		actor->HolsterWeapon();
	}

	if (ImGui::Button("Reload"))
	{
		actor->Reload();
	}

	if (ImGui::Button("Hide Attached Non Weapons"))
	{
		actor->HideAttachedNonWeapons();
	}

	if (!actor->IsHandsEmpty())
	{
		ImGui::Separator();

		TEntityRef<IHM5ItemWeapon> currentWeapon = actor->GetCurrentWeapon();

		AddCurrentWeaponInfo(currentWeapon, color, actorIndex);

		ImGui::Separator();

		if (currentWeapon.GetRawPointer())
		{
			if (actor->IsWeaponFiring())
			{
				ImGui::Text("Is Weapon Firing: Yes");
			}
			else
			{
				ImGui::Text("Is Weapon Firing: No");
			}
		}
	}

	if (ImGui::Button("Shoot Enemy"))
	{
		actor->ShootEnemy();
	}

	ImGui::Separator();

	static bool switchToLeftHand = false;

	ImGui::Checkbox("Switch To Left Hand", &switchToLeftHand);

	if (ImGui::Button("Switch Weapon Hand"))
	{
		actor->SwitchWeaponHand(switchToLeftHand);
	}

	ImGui::Separator();

	//IMPLEMENT void StartShooting(ZPositionTarget* rTarget, bool bIgnoreLOF, bool bBlindFire);

	if (actor->HasFullClip())
	{
		ImGui::Text("Has Full Clip: Yes");
	}
	else
	{
		ImGui::Text("Has Full Clip: No");
	}

	if (actor->IsAlive())
	{
		ImGui::Text("Is Alive: Yes");
	}
	else
	{
		ImGui::Text("Is Alive: No");
	}

	if (actor->NeedReload())
	{
		ImGui::Text("Need Reload: Yes");
	}
	else
	{
		ImGui::Text("Need Reload: No");
	}

	if (actor->IsLeaningAtWindow())
	{
		ImGui::Text("Is Leaning At Window: Yes");
	}
	else
	{
		ImGui::Text("Is Leaning At Window: No");
	}

	if (actor->IsHitTarget())
	{
		ImGui::Text("Is Hit Target: Yes");
	}
	else
	{
		ImGui::Text("Is Hit Target: No");
	}

	ImGui::Separator();

	static bool tagged = false;

	ImGui::Checkbox("Tagged", &tagged);

	if (ImGui::Button("Set SB Kill Tagged"))
	{
		actor->SetSBKillTagged(tagged);
	}

	ImGui::Separator();

	if (actor->IsNude())
	{
		ImGui::Text("Is Nude: Yes");
	}
	else
	{
		ImGui::Text("Is Nude: No");
	}

	if (actor->IsBeingDragged())
	{
		ImGui::Text("Is Being Dragged: Yes");
	}
	else
	{
		ImGui::Text("Is Being Dragged: No");
	}

	EActorDeathType actorDeathType = actor->GetDeathType();

	ImGui::Text("Actor Death Type: %s", GetActorDeathType(actorDeathType));

	if (ImGui::Button("Flag Death As Accident"))
	{
		actor->FlagDeathAsAccident();
	}

	if (ImGui::Button("Flag Death As Murder"))
	{
		actor->FlagDeathAsMurder();
	}

	//IMPLEMENT void UnholsterWeapon(TEntityRef<IHM5ItemWeapon>* rWeapon);

	if (ImGui::Button("Release Human Shield"))
	{
		actor->ReleaseHumanShield();
	}

	static bool haveTargets = false;

	if (ImGui::Button("Test All Targets Killed"))
	{
		//actor->TestAllTargetsKilled(&haveTargets);
	}

	if (haveTargets)
	{
		ImGui::Text("Have Targets: Yes");
	}
	else
	{
		ImGui::Text("Have Targets: No");
	}

	if (actor->IsShootingRequested())
	{
		ImGui::Text("Is Shooting Requested: Yes");
	}
	else
	{
		ImGui::Text("Is Shooting Requested: No");
	}

	//IMPLEMENT ZShootTargetInfo* GetShootTargetInfo();

	if (actor->IsFemale())
	{
		ImGui::Text("Is Female: Yes");
	}
	else
	{
		ImGui::Text("Is Female: No");
	}

	if (actor->IsBodyHidden())
	{
		ImGui::Text("Is Body Hidden: Yes");
	}
	else
	{
		ImGui::Text("Is Body Hidden: No");
	}

	if (actor->IsAboutToDie())
	{
		ImGui::Text("Is About To Die: Yes");
	}
	else
	{
		ImGui::Text("Is About To Die: No");
	}

	if (ImGui::Button("Change To Nude"))
	{
		actor->ChangeToNude();
	}

	if (actor->IsBoss())
	{
		ImGui::Text("Is Boss: Yes");
	}
	else
	{
		ImGui::Text("Is Boss: No");
	}

	ZString weaponName = actor->GetWeaponName();

	ImGui::Text("Weapon Name: %s", weaponName.ToCString());

	if (ImGui::Button("Unholster Weapon"))
	{
		actor->UnholsterWeapon();
	}

	if (ImGui::Button("Release Carry Civilian"))
	{
		actor->ReleaseCarryCivilian();
	}

	if (actor->GetSBKillTagged())
	{
		ImGui::Text("SB Kill Tagged: Yes");
	}
	else
	{
		ImGui::Text("SB Kill Tagged: No");
	}

	ImGui::Separator();

	ImGui::TextColored(color, "Inventory");
	ImGui::Text("");

	AddActorInvetoryInfo(actor->m_inventory);

	ImGui::Separator();
	ImGui::TextColored(color, "Runtime Inventory");

	AddActorInvetoryInfo(actor->m_runtimeInventory);

	ImGui::Separator();
	ImGui::TextColored(color, "Position");
	ImGui::Text("");

	ImGui::PushItemWidth(100);

	AddLocalPositionInputs(actor, flags, color, actorIndex);
	AddWorldPositionInputs(actor, flags, color, actorIndex);

	ImGui::PopItemWidth();

	ImGui::Separator();
}

void NearestActorsInfo::AddNearestCrowdActorInfo(TEntityRef<ZCrowdActor>* entityRef, ImGuiInputTextFlags& flags, ImVec4& color, int crowdActorIndex)
{
	ZCrowdActor* crowdActor = entityRef->GetRawPointer();

	if (!crowdActor)
	{
		return;
	}

	ZCrowdActorCore* crowdActorCore = crowdActor->GetCore();

	if (crowdActorCore)
	{
		ImGui::TextColored(color, "Crowd Actor Position");

		ImGui::Text("X");
		ImGui::SameLine();

		static string label1 = "##crowdActorPositionX" + to_string(crowdActorIndex);

		float4 position = crowdActorCore->GetPosition();

		if (ImGui::InputFloat(label1.c_str(), &position.x()))
		{
			crowdActorCore->SetPosition(position);
		}

		ImGui::SameLine();
		ImGui::Text("Y");
		ImGui::SameLine();

		label1 = "##crowdActorPositionY" + to_string(crowdActorIndex);

		if (ImGui::InputFloat(label1.c_str(), &position.y()))
		{
			crowdActorCore->SetPosition(position);
		}

		ImGui::SameLine();
		ImGui::Text("Z");
		ImGui::SameLine();

		label1 = "##crowdActorPositionZ" + to_string(crowdActorIndex);

		if (ImGui::InputFloat(label1.c_str(), &position.z()))
		{
			crowdActorCore->SetPosition(position);
		}

		ImGui::SameLine();
		ImGui::Text("W");
		ImGui::SameLine();

		label1 = "##crowdActorPositionW" + to_string(crowdActorIndex);

		if (ImGui::InputFloat(label1.c_str(), &position.w()))
		{
			crowdActorCore->SetPosition(position);
		}

		ImGui::Text("X");
		ImGui::SameLine();

		label1 = "##crowdActorForwardX" + to_string(crowdActorIndex);

		float4 forward = crowdActorCore->GetForward();

		if (ImGui::InputFloat(label1.c_str(), &forward.x()))
		{
			crowdActorCore->SetForward(forward);
		}

		ImGui::SameLine();
		ImGui::Text("Y");

		label1 = "##crowdActorForwardY" + to_string(crowdActorIndex);

		if (ImGui::InputFloat(label1.c_str(), &forward.y()))
		{
			crowdActorCore->SetForward(forward);
		}

		ImGui::SameLine();
		ImGui::Text("Z");

		label1 = "##crowdActorForwardZ" + to_string(crowdActorIndex);

		if (ImGui::InputFloat(label1.c_str(), &forward.z()))
		{
			crowdActorCore->SetForward(forward);
		}

		ImGui::SameLine();
		ImGui::Text("W");

		label1 = "##crowdActorForwardW" + to_string(crowdActorIndex);

		if (ImGui::InputFloat(label1.c_str(), &forward.w()))
		{
			crowdActorCore->SetForward(forward);
		}

		ImGui::Text("Speed");

		label1 = "##crowdActorSpeed" + to_string(crowdActorIndex);

		ImGui::InputFloat(label1.c_str(), &crowdActorCore->m_nSpeed);

		AddCrowdEntityInfo(crowdActor->GetCrowdEntity().GetRawPointer(), crowdActorIndex);

		ZCrowdActorState* crowdActorState = crowdActor->GetCurrentState();

		if (crowdActorState)
		{
			if (crowdActorState->CollidesWithHitman(*entityRef))
			{
				ImGui::Text("Collides With Hitman: Yes");
			}
			else
			{
				ImGui::Text("Collides With Hitman: No");
			}
		}

		ImGui::SameLine();
		ImGui::Text("Time In State");

		ImGui::InputFloat("##TimeInState", &crowdActor->m_nTimeInState);

		static bool beingPushed = crowdActor->m_bBeingPushed;
		static bool stopFlag = crowdActor->m_bStopFlag;
		static bool wasScaredByRegion = crowdActor->m_bWasScaredByRegion;
		static bool neverFlee = crowdActor->m_bNeverFlee;
		static bool selected = crowdActor->m_bSelected;
		static bool allowRandomStateChanges = crowdActor->m_bAllowRandomStateChanges;

		ImGui::Checkbox("Being Pushed", &beingPushed);
		ImGui::Checkbox("Stop Flag", &stopFlag);
		ImGui::Checkbox("Was Scared By Region", &wasScaredByRegion);
		ImGui::Checkbox("Never Flee", &neverFlee);
		ImGui::Checkbox("Selected", &selected);
		ImGui::Checkbox("Allow RandomState Changes", &allowRandomStateChanges);

		crowdActor->m_bBeingPushed = beingPushed;
		crowdActor->m_bStopFlag = stopFlag;
		crowdActor->m_bWasScaredByRegion = wasScaredByRegion;
		crowdActor->m_bNeverFlee = neverFlee;
		crowdActor->m_bSelected = selected;
		crowdActor->m_bAllowRandomStateChanges = allowRandomStateChanges;
	}
}

void NearestActorsInfo::AddCrowdEntityInfo(ZCrowdEntity* crowdEntity, int crowdActorIndex)
{
	if (crowdEntity)
	{
		ImGui::Checkbox("Use Crowd Camera Profile", &crowdEntity->m_bUseCrowdCameraProfile);
		ImGui::Checkbox("Allow CC", &crowdEntity->m_bAllowCC);
		ImGui::Checkbox("Allow Human Shield", &crowdEntity->m_bAllowHumanShield);
		ImGui::Checkbox("Allow AI Crowd Shooting", &crowdEntity->m_bAllowAICrowdShooting);
		ImGui::Checkbox("Allow Fast Walk", &crowdEntity->m_bAllowFastWalk);
		ImGui::Checkbox("Allow Run", &crowdEntity->m_bAllowRun);

		ImGui::Text("Allow Run Radius");
		ImGui::SameLine();

		static string label1 = "##AllowRunRadius" + to_string(crowdActorIndex);

		ImGui::InputFloat(label1.c_str(), &crowdEntity->m_nAllowRunRadius);

		ImGui::Checkbox("Crowd Affect NPCs", &crowdEntity->m_bCrowdAffectNPCs);
		ImGui::Checkbox("Do High LOD Separation", &crowdEntity->m_bDoHighLODSeparation);

		ImGui::Text("Separation Max LOD");
		ImGui::SameLine();

		label1 = "##SeparationMaxLOD" + to_string(crowdActorIndex);

		ImGui::InputScalar(label1.c_str(), ImGuiDataType_U32, &crowdEntity->m_nSeparationMaxLOD);

		ImGui::Text("Animation Blend Max LOD");
		ImGui::SameLine();

		label1 = "##AnimationBlendMaxLOD" + to_string(crowdActorIndex);

		ImGui::InputScalar(label1.c_str(), ImGuiDataType_U32, &crowdEntity->m_nAnimationBlendMaxLOD);

		ImGui::Checkbox("Smoothen Exit Flows", &crowdEntity->m_bSmoothenExitFlows);

		ImGui::Text("Paniced Actor Remove Factor");
		ImGui::SameLine();

		label1 = "##PanicedActorRemoveFactor" + to_string(crowdActorIndex);

		ImGui::InputFloat(label1.c_str(), &crowdEntity->m_nPanicedActorRemoveFactor);

		ImGui::Text("Paniced Actor Exit Factor");
		ImGui::SameLine();

		label1 = "##PanicedActorExitFactor" + to_string(crowdActorIndex);

		ImGui::InputFloat(label1.c_str(), &crowdEntity->m_nPanicedActorExitFactor);

		ImGui::Text("Panic Debris Factor");
		ImGui::SameLine();

		label1 = "##PanicDebrisFactor" + to_string(crowdActorIndex);

		ImGui::InputFloat(label1.c_str(), &crowdEntity->m_nPanicDebrisFactor);

		ImGui::Text("Panic Debris Time");
		ImGui::SameLine();

		label1 = "##PanicDebrisTime" + to_string(crowdActorIndex);

		ImGui::InputFloat(label1.c_str(), &crowdEntity->m_nPanicDebrisTime);

		ImGui::Checkbox("Draw Debug", &crowdEntity->m_bDrawDebug);
		ImGui::Checkbox("Draw Grid Debug", &crowdEntity->m_bDrawGridDebug);
		ImGui::Checkbox("Draw Actors Debug", &crowdEntity->m_bDrawActorsDebug);
		ImGui::Checkbox("Draw Behavior Debug", &crowdEntity->m_bDrawBehaviorDebug);
		ImGui::Checkbox("Draw Region Debug", &crowdEntity->m_bDrawRegionDebug);
		ImGui::Checkbox("Draw Flow Debug", &crowdEntity->m_bDrawFlowDebug);
		ImGui::Checkbox("Look at Debug", &crowdEntity->m_bLookatDebug);
		ImGui::Checkbox("Warzone Debug", &crowdEntity->m_bWarzoneDebug);
	}
}

void NearestActorsInfo::AddBaseCharacterInfo(ZActor* actor)
{
	static bool bodyColiEnabled = actor->m_bBodyColiEnabled;
	static bool bodyColiInitialized = actor->m_bBodyColiInitialized;
	static bool ignoreOnePositionChange = actor->m_bIgnoreOnePositionChange;
	static bool baseCharInitialized = actor->m_bBaseCharInitialized;

	ImGui::Checkbox("Body Coli Enabled", &bodyColiEnabled);
	ImGui::Checkbox("Body Coli Initialized", &bodyColiInitialized);
	ImGui::Checkbox("Ignore One Position Change", &ignoreOnePositionChange);

	actor->m_bBodyColiEnabled = bodyColiEnabled;
	actor->m_bBodyColiInitialized = bodyColiInitialized;
	actor->m_bIgnoreOnePositionChange = ignoreOnePositionChange;

	if (baseCharInitialized)
	{
		ImGui::Text("Base Char Initialized: Yes");
	}
	else
	{
		ImGui::Text("Base Char Initialized: No");
	}

	static bool shootColiPrimitiveActive = actor->m_bShootColiPrimitiveActive;
	static bool shootColiSystemActive = actor->m_bShootColiSystemActive;
	static bool initialized = static_cast<ZHM5BaseCharacter*>(actor)->m_bInitialized;

	ImGui::Checkbox("Shoot Coli Primitive Active", &shootColiPrimitiveActive);
	ImGui::Checkbox("Shoot Coli System Active", &shootColiSystemActive);

	actor->m_bShootColiPrimitiveActive = shootColiPrimitiveActive;
	actor->m_bShootColiSystemActive = shootColiSystemActive;

	if (initialized)
	{
		ImGui::Text("Initialized: Yes");
	}
	else
	{
		ImGui::Text("Initialized: No");
	}

	static bool initializingBaseCharacter = actor->m_bInitializingBaseCharacter;

	if (initializingBaseCharacter)
	{
		ImGui::Text("Initializing Base Character: Yes");
	}
	else
	{
		ImGui::Text("Initializing Base Character: No");
	}

	static bool isInCrowd = actor->m_bIsInCrowd;

	if (isInCrowd)
	{
		ImGui::Text("Is In Crowd");
	}
	else
	{
		ImGui::Text("Is In Crowd");
	}

	static bool isInLimitVisionAreaZone = actor->m_bIsInLimitVisionAreaZone;
	static bool isInsideLimitVisionArea = actor->m_bIsInsideLimitVisionArea;
	static bool isBlockedByLimitVisionArea = actor->m_bIsBlockedByLimitVisionArea;

	ImGui::Checkbox("Is In Limit Vision Area Zone", &isInLimitVisionAreaZone);
	ImGui::Checkbox("Is Inside Limit Vision Area", &isInsideLimitVisionArea);
	ImGui::Checkbox("Is Blocked By Limit Vision Area", &isBlockedByLimitVisionArea);

	actor->m_bIsInLimitVisionAreaZone = isInLimitVisionAreaZone;
	actor->m_bIsInsideLimitVisionArea = isInsideLimitVisionArea;
	actor->m_bIsBlockedByLimitVisionArea = isBlockedByLimitVisionArea;

	if (actor->IsHandsEmpty())
	{
		ImGui::Text("Is Hands Empty: Yes");
	}
	else
	{
		ImGui::Text("Is Hands Empty: No");
	}

	if (actor->IsHoldingWeapon())
	{
		ImGui::Text("Is Holding Weapon: Yes");
	}
	else
	{
		ImGui::Text("Is Holding Weapon: No");
	}

	if (actor->IsArmed())
	{
		ImGui::Text("Is Armed: Yes");
	}
	else
	{
		ImGui::Text("Is Armed: No");
	}

	static bool showCharacter = !actor->IsCharacterHidden();

	ImGui::Checkbox("ShowCharacter", &showCharacter);

	if (showCharacter == actor->IsCharacterHidden())
	{
		actor->ShowCharacter(showCharacter);
	}

	if (actor->IsCharacterHidden())
	{
		ImGui::Text("Is Character Hidden: Yes");
	}
	else
	{
		ImGui::Text("Is Character Hidden: No");
	}

	if (actor->IsPoweredRagdoll())
	{
		ImGui::Text("Is Powered Ragdoll: Yes");
	}
	else
	{
		ImGui::Text("Is Powered Ragdoll: No");
	}

	if (actor->IsPoweredRagdollStopping())
	{
		ImGui::Text("Is Powered Ragdoll Stopping: Yes");
	}
	else
	{
		ImGui::Text("Is Powered Ragdoll Stopping: No");
	}

	if (actor->IsRagdollGrabbed())
	{
		ImGui::Text("Is Ragdoll Grabbed: Yes");
	}
	else
	{
		ImGui::Text("Is Ragdoll Grabbed: No");
	}

	if (actor->IsRagdollControlled())
	{
		ImGui::Text("Is Ragdoll Controlled: Yes");
	}
	else
	{
		ImGui::Text("Is Ragdoll Controlled: No");
	}

	if (actor->IsWearingOutfit())
	{
		ImGui::Text("Is Wearing Outfit: Yes");
	}
	else
	{
		ImGui::Text("Is Wearing Outfit: No");
	}

	if (actor->IsDead())
	{
		ImGui::Text("Is Dead: Yes");
	}
	else
	{
		ImGui::Text("Is Dead: No");
	}

	if (actor->CanBeDragged())
	{
		ImGui::Text("Can Be Dragged: Yes");
	}
	else
	{
		ImGui::Text("Can Be Dragged: No");
	}

	if (ImGui::Button("Reset Character"))
	{
		actor->ResetCharacter();
	}
}

void NearestActorsInfo::KillAllActors(TList<SNearEnemyCheckReq>* list)
{
	for (unsigned int i = 0; i < list->Size(); i++)
	{
		TListNode<SNearEnemyCheckReq>* current = list->m_list.m_pFirst;
		TListNode<SNearEnemyCheckReq>* last = list->m_list.m_pLast;

		ZActor* actor = current->m_data.m_pActor.GetRawPointer();

		actor->KillActor(EActorDeathType::eADT_ACCIDENT, true);

		while ((current = current->m_pNext) != last)
		{
			actor = current->m_data.m_pActor.GetRawPointer();
			actor->KillActor(EActorDeathType::eADT_ACCIDENT, true);
		}

		actor = current->m_data.m_pActor.GetRawPointer();
		actor->KillActor(EActorDeathType::eADT_ACCIDENT, true);
	}
}

char* NearestActorsInfo::Strdup(const char* s)
{
	IM_ASSERT(s);
	size_t length = strlen(s) + 1;
	void* buffer = malloc(length);
	IM_ASSERT(buffer);

	return (char*)memcpy(buffer, (const void*)s, length);
}
