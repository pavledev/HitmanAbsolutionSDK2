#include "ActorsInfo.h"

void ActorsInfo::DrawWindow(bool* showActorsInfo)
{
	ImGui::SetNextWindowSize(ImVec2(500, 440), ImGuiCond_FirstUseEver);

	if (!ImGui::Begin("Actors Info", showActorsInfo))
	{
		ImGui::End();
		return;
	}

	static ZActorManager* actorManager = reinterpret_cast<ZActorManager*>(Globals::g_pActorManagerSingleton);

    if (ImGui::BeginTabBar("##Tabs", ImGuiTabBarFlags_None))
    {
        if (ImGui::BeginTabItem("Scene Actors (Max: 512)"))
        {
			static int selected = 0;
			ImGui::BeginChild("left pane", ImVec2(150, 0), true);

			for (unsigned int i = 0; i < actorManager->m_sceneActors.Size(); i++)
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

			ImGuiInputTextFlags flags = ImGuiInputTextFlags_EnterReturnsTrue;
			ImVec4 color = ImVec4(1.0f, 0.8f, 0.6f, 1.0f);

			if (ImGui::Button("Kill All Actors"))
			{
				KillAllActors(actorManager);
			}

			ImGui::Separator();

			TEntityRef<ZActor>* entityRef = actorManager->m_sceneActors[selected];

			ImGui::Text("Actor Name: %s", entityRef->m_pInterfaceRef->m_sActorName.m_chars);
			ImGui::Text("Actor Type: %s", GetActorType(entityRef->m_pInterfaceRef->m_eActorType));
			ImGui::Text("Actor Rank: %s", GetActorRank(entityRef->m_pInterfaceRef->m_eActorRank));
			ImGui::Text("Actor Group: %s", GetActorGroup(entityRef->m_pInterfaceRef->m_eActorGroup));

			ImGui::EndChild();
			ImGui::EndGroup();

            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Initialized Actors (Max: 100)"))
        {
			AddActorsInfo(actorManager->m_initializedActors, actorManager);

            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Enabled Actors (Max: 100)"))
        {
			AddActorsInfo(actorManager->m_enabledActors, actorManager);

            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Alive Actors (Max: 50)"))
        {
			AddActorsInfo(actorManager->m_aliveActors, actorManager);

            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Spawned Actors"))
        {
			AddActorsInfo(actorManager->m_SpawnedActors);

            ImGui::EndTabItem();
        }

		if (ImGui::BeginTabItem("Target Actors"))
		{
			AddActorsInfo(actorManager->m_aTargetList);

			ImGui::EndTabItem();
		}

        ImGui::EndTabBar();
    }

	ImGui::End();
}

template<class A, int B>
void ActorsInfo::AddActorsInfo(TMaxArray<A, B>& array, ZActorManager* actorManager)
{
    static int selected = 0;
    ImGui::BeginChild("left pane", ImVec2(150, 0), true);

    for (unsigned int i = 0; i < array.Size(); i++)
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
		KillAllActors(actorManager);
	}

	ImGui::Separator();

	ImGuiInputTextFlags flags = ImGuiInputTextFlags_EnterReturnsTrue;
	ImVec4 color = ImVec4(1.0f, 0.8f, 0.6f, 1.0f);

	ImGui::PushItemWidth(350);

	TEntityRef<ZActor>* entityRef = array[selected];
	AddActorInfo(entityRef, flags, color, selected);

	ImGui::PopItemWidth();

	ImGui::EndChild();
	ImGui::EndGroup();
}

void ActorsInfo::AddActorsInfo(TArray<TEntityRef<ZActor>>& array)
{
	static int selected = 0;
	ImGui::BeginChild("left pane", ImVec2(150, 0), true);

	for (int i = 0; i < array.Size(); i++)
	{
		char label[128];
		sprintf_s(label, "Actor %d", i);

		if (ImGui::Selectable(label, selected == i))
		{
			selected = i;
		}
	}

	ImGui::EndChild();

	ImGui::BeginGroup();
	ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()));

	static ImGuiInputTextFlags flags = ImGuiInputTextFlags_EnterReturnsTrue;
	static ImVec4 color = ImVec4(1.0f, 0.8f, 0.6f, 1.0f);

	TEntityRef<ZActor>* entityRef = array[selected];
	AddActorInfo(entityRef, flags, color, selected);

	ImGui::EndChild();
	ImGui::EndGroup();
}

void ActorsInfo::AddLocalPositionInputs(ZActor* actor, ImGuiInputTextFlags& flags, ImVec4& color, int actorIndex)
{
	ImGui::TextColored(color, "Local Position");

	float4 localPosition = {};
	actor->GetSpatialEntityPtr()->GetLocalPosition(&localPosition);

	ImGui::Text("X");
	ImGui::SameLine();

	string label1 = "##localPositionX" + to_string(actorIndex);

	if (ImGui::InputFloat(label1.c_str(), &localPosition.x(), 0, 0, "%.3f", flags))
	{
		actor->GetSpatialEntityPtr()->SetLocalPosition(&localPosition);
	}

	ImGui::SameLine();
	ImGui::Text("Y");
	ImGui::SameLine();

	string label2 = "##localPositionY" + to_string(actorIndex);

	if (ImGui::InputFloat(label2.c_str(), &localPosition.y(), 0, 0, "%.3f", flags))
	{
		actor->GetSpatialEntityPtr()->SetLocalPosition(&localPosition);
	}

	ImGui::SameLine();
	ImGui::Text("Z");
	ImGui::SameLine();

	string label3 = "##localPositionZ" + to_string(actorIndex);

	if (ImGui::InputFloat(label3.c_str(), &localPosition.z(), 0, 0, "%.3f", flags))
	{
		actor->GetSpatialEntityPtr()->SetLocalPosition(&localPosition);
	}

	ImGui::SameLine();
	ImGui::Text("W");
	ImGui::SameLine();

	string label4 = "##localPositionW" + to_string(actorIndex);

	if (ImGui::InputFloat(label4.c_str(), &localPosition.w(), 0, 0, "%.3f", flags))
	{
		actor->GetSpatialEntityPtr()->SetLocalPosition(&localPosition);
	}
}

void ActorsInfo::AddWorldPositionInputs(ZActor* actor, ImGuiInputTextFlags& flags, ImVec4& color, int actorIndex)
{
	ImGui::TextColored(color, "World Position");

	float4 worldPosition = {};
	actor->GetSpatialEntityPtr()->GetWorldPosition(&worldPosition);

	ImGui::Text("X");
	ImGui::SameLine();

	string label1 = "##wordPositionX" + to_string(actorIndex);

	if (ImGui::InputFloat(label1.c_str(), &worldPosition.x(), 0, 0, "%.3f", flags))
	{
		actor->GetSpatialEntityPtr()->SetWorldPosition(&worldPosition);
	}

	ImGui::SameLine();
	ImGui::Text("Y");
	ImGui::SameLine();

	string label2 = "##wordPositionY" + to_string(actorIndex);

	if (ImGui::InputFloat(label2.c_str(), &worldPosition.y(), 0, 0, "%.3f", flags))
	{
		actor->GetSpatialEntityPtr()->SetWorldPosition(&worldPosition);
	}

	ImGui::SameLine();
	ImGui::Text("Z");
	ImGui::SameLine();

	string label3 = "##wordPositionZ" + to_string(actorIndex);

	if (ImGui::InputFloat(label3.c_str(), &worldPosition.z(), 0, 0, "%.3f", flags))
	{
		actor->GetSpatialEntityPtr()->SetWorldPosition(&worldPosition);
	}

	ImGui::SameLine();
	ImGui::Text("W");
	ImGui::SameLine();

	string label4 = "##wordPositionW" + to_string(actorIndex);

	if (ImGui::InputFloat(label4.c_str(), &worldPosition.w(), 0, 0, "%.3f", flags))
	{
		actor->GetSpatialEntityPtr()->SetWorldPosition(&worldPosition);
	}
}

const char* ActorsInfo::GetActorCCPreset(EActorCCPreset m_eActorCCPreset)
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

const char* ActorsInfo::GetActorGroup(EActorGroup m_eActorGroup)
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

const char* ActorsInfo::GetActorRank(EActorRank m_eActorRank)
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

const char* ActorsInfo::GetActorType(EActorType m_eActorType)
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

const char* ActorsInfo::GetActorDeathType(EActorDeathType actorDeathType)
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

const char* ActorsInfo::GetItemSize(eItemSize itemSize)
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

const char* ActorsInfo::GetItemHands(eItemHands itemHands)
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

const char* ActorsInfo::GetItemHandsCoverAnimLayer(eItemHands itemHands)
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

const char* ActorsInfo::GetItemType(eItemType itemType)
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

void ActorsInfo::AddIHM5ItemInfo(IHM5Item* item)
{
	if (!item)
	{
		return;
	}

	ImGui::Text("Item Size: %s", GetItemSize(item->GetItemSize()));
	ImGui::Text("Item Hands: %s", GetItemHands(item->GetItemHands()));
	ImGui::Text("Item Hands Cover Anim Layer: %s", GetItemHandsCoverAnimLayer(item->GetItemHandsCoverAnimLayer()));
	ImGui::Text("Item Type: %s", GetItemType(item->GetItemType()));

	ZString itemTypeName = {};
	item->GetItemTypeName(&itemTypeName);

	ImGui::Text("Item Type Name: %s", itemTypeName.m_chars);

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

	ZString debugName = {};
	item->GetDebugName(&debugName);

	ImGui::Text("Debug Name: %s", debugName.m_chars);

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

const char* ActorsInfo::GetInventorySlotType(EInventorySlotType m_eSlotType)
{
	const char* type{};

	switch (m_eSlotType)
	{
	case eSilverBallerSlot:
		type = "Silver Baller Slot";
		break;
	case eHandgunSlot:
		type = "Handgun Slot";
		break;
	case eRevolverSlot:
		type = "Revolver Slot";
		break;
	case eRifleSlot:
		type = "Rifle Slot";
		break;
	case eSniperSlot:
		type = "Sniper Slot";
		break;
	case eSmgSlot:
		type = "Smg Slot";
		break;
	case eShotgunSlot:
		type = "Shotgun Slot";
		break;
	case eFiberwireSlot:
		type = "Fiberwire Slot";
		break;
	case eCCPropSlot:
		type = "CC Prop Slot";
		break;
	case eRemoteControlled:
		type = "Remote Controlled";
		break;
	case eOther:
		type = "Other";
		break;
	}

	return type;
}

const char* ActorsInfo::GetWeaponType(eWeaponType weaponType)
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

const char* ActorsInfo::GetWeaponAnimationCategory(EWeaponAnimationCategory weaponAnimationCategory)
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

void ActorsInfo::AddInvetorySlotInfo(ZInventorySlot* inventorySlot)
{
	if (!inventorySlot)
	{
		return;
	}

	const char* inventorySlotType = GetInventorySlotType(inventorySlot->m_eSlotType);
	ImGui::Text("Inventory Slot Type: %s", inventorySlotType);

	ImGui::Text("");

	ImGui::Text("Weapon Set");

	int itemsSize = IM_ARRAYSIZE(inventorySlot->m_WeaponSet.m_rItems);

	for (int i = 0; i < itemsSize; i++)
	{
		AddIHM5ItemInfo(inventorySlot->m_WeaponSet.m_rItems[i].m_pInterfaceRef);
	}

	ZHM5WeaponSet weaponSet = inventorySlot->m_WeaponSet;

	static bool canDualWield = static_cast<bool>(weaponSet.m_bCanDualWield);
	ImGui::Checkbox("Can Dual Wield", &canDualWield);

	weaponSet.m_bCanDualWield = canDualWield;

	static bool dualWieldMode = static_cast<bool>(weaponSet.m_bDualWieldMode);
	ImGui::Checkbox("Dual Wield Mode", &dualWieldMode);

	weaponSet.m_bDualWieldMode = dualWieldMode;
}

void ActorsInfo::AddCurrentWeaponInfo(TEntityRef<IHM5ItemWeapon> currentWeapon, ImVec4& color, int actorIndex)
{
	ImGui::TextColored(color, "Current Weapon");

	if (!currentWeapon.m_pInterfaceRef)
	{
		return;
	}

	if (currentWeapon.m_pInterfaceRef->IsFiring())
	{
		ImGui::Text("Is Firing: Yes");
	}
	else
	{
		ImGui::Text("Is Firing: No");
	}

	ImGui::Separator();

	static bool semiAutomatic, fullAutomatic;

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
		currentWeapon.m_pInterfaceRef->SetWeaponOperation(weaponOperation, true);
	}

	ImGui::Text("AI Near Combat Range: %f", currentWeapon.m_pInterfaceRef->GetAINearCombatRange());
	ImGui::Text("AI Far Combat Range: %f", currentWeapon.m_pInterfaceRef->GetAIFarCombatRange());

	ImGui::Text("Bullets In Magazine");
	ImGui::SameLine();

	string label = "##BulletsInMagazine" + to_string(actorIndex);

	static unsigned __int16 bulletsInMagazine = currentWeapon.m_pInterfaceRef->GetBulletsInMagazine();
	ImGui::InputScalar(label.c_str(), ImGuiDataType_U16, &bulletsInMagazine);

	currentWeapon.m_pInterfaceRef->SetBulletsInMagazine(bulletsInMagazine);

	if (currentWeapon.m_pInterfaceRef->IsCurrentClipLowOnAmmo())
	{
		ImGui::Text("Is Current Clip Low On Ammo: Yes");
	}
	else
	{
		ImGui::Text("Is Current Clip Low On Ammo: No");
	}

	if (currentWeapon.m_pInterfaceRef->GetFiringStarted())
	{
		ImGui::Text("Firing Started: Yes");
	}
	else
	{
		ImGui::Text("Firing Started: No");
	}

	if (currentWeapon.m_pInterfaceRef->IsHandGun())
	{
		ImGui::Text("Is HandGun: Yes");
	}
	else
	{
		ImGui::Text("Is HandGun: No");
	}

	if (currentWeapon.m_pInterfaceRef->IsRevolver())
	{
		ImGui::Text("Is Revolver: Yes");
	}
	else
	{
		ImGui::Text("Is Revolver: No");
	}

	if (currentWeapon.m_pInterfaceRef->IsSmg())
	{
		ImGui::Text("Is Smg: Yes");
	}
	else
	{
		ImGui::Text("Is Smg: No");
	}

	if (currentWeapon.m_pInterfaceRef->IsRifle())
	{
		ImGui::Text("Is Rifle: Yes");
	}
	else
	{
		ImGui::Text("Is Rifle: No");
	}

	if (currentWeapon.m_pInterfaceRef->IsRPG())
	{
		ImGui::Text("Is RPG: Yes");
	}
	else
	{
		ImGui::Text("Is RPG: No");
	}

	if (currentWeapon.m_pInterfaceRef->IsSniper())
	{
		ImGui::Text("Is Sniper: Yes");
	}
	else
	{
		ImGui::Text("Is Sniper: No");
	}

	if (currentWeapon.m_pInterfaceRef->IsShotgun())
	{
		ImGui::Text("Is Shotgun: Yes");
	}
	else
	{
		ImGui::Text("Is Shotgun: No");
	}

	if (currentWeapon.m_pInterfaceRef->IsFireArm())
	{
		ImGui::Text("Is FireArm: Yes");
	}
	else
	{
		ImGui::Text("Is FireArm: No");
	}

	if (currentWeapon.m_pInterfaceRef->IsProjectileWeapon())
	{
		ImGui::Text("Is Projectile Weapon: Yes");
	}
	else
	{
		ImGui::Text("Is Projectile Weapon: No");
	}

	if (currentWeapon.m_pInterfaceRef->IsCloseCombatWeapon())
	{
		ImGui::Text("Is Close Combat Weapon: Yes");
	}
	else
	{
		ImGui::Text("Is Close Combat Weapon: No");
	}

	if (currentWeapon.m_pInterfaceRef->IsFiberwire())
	{
		ImGui::Text("Is Fiberwire: Yes");
	}
	else
	{
		ImGui::Text("Is Fiberwire: No");
	}

	eWeaponType weaponType = currentWeapon.m_pInterfaceRef->GetWeaponType();
	ImGui::Text("Weapon Type: %s", GetWeaponType(weaponType));

	eItemType itemType = currentWeapon.m_pInterfaceRef->GetItemType();
	ImGui::Text("Weapon Type: %s", GetItemType(itemType));

	EWeaponAnimationCategory weaponAnimationCategory = currentWeapon.m_pInterfaceRef->GetAnimationCategory();
	ImGui::Text("Weapon Animation Category: %s", GetWeaponAnimationCategory(weaponAnimationCategory));

	if (currentWeapon.m_pInterfaceRef->NeedReloading())
	{
		ImGui::Text("Need Reloading: Yes");
	}
	else
	{
		ImGui::Text("Need Reloading: No");
	}

	if (currentWeapon.m_pInterfaceRef->IsAutoreloadEnabled())
	{
		ImGui::Text("Is Autoreload Enabled: Yes");
	}
	else
	{
		ImGui::Text("Is Autoreload Enabled: No");
	}
}

void ActorsInfo::AddActorInvetoryInfo(TArray<TEntityRef<IHM5Item>> m_inventory)
{
	TEntityRef<IHM5Item>* current = m_inventory.m_pStart;

	if (!current)
	{
		ImGui::Text("Inventory is empty.");

		return;
	}

	TEntityRef<IHM5Item>* end = m_inventory.m_pEnd;

	while (current != end)
	{
		IHM5Item* item = current->m_pInterfaceRef;
		AddIHM5ItemInfo(item);

		current++;
	}
}

void ActorsInfo::AddActorInfo(TEntityRef<ZActor>* entityRef, ImGuiInputTextFlags& flags, ImVec4& color, int actorIndex)
{
	if (!entityRef)
	{
		return;
	}

	ZActor* actor = entityRef->m_pInterfaceRef;

	if (!actor)
	{
		return;
	}

	ImGui::TextColored(color, "General");
	ImGui::Text("");

	if (ImGui::Button("Teleport Actor To Player"))
	{
		static ZLevelManager* levelManager = reinterpret_cast<ZLevelManager*>(Globals::g_pLevelManagerSingleton);
		ZHitman5* player = levelManager->m_rHitman.m_pInterfaceRef;

		if (player)
		{
			float4 playerLocalPosition = {};
			player->GetSpatialEntityPtr()->GetLocalPosition(&playerLocalPosition);

			actor->GetSpatialEntityPtr()->SetLocalPosition(&playerLocalPosition);
		}
	}

	ImGui::TextColored(color, "CC Profile");

	if (actor->m_rCCProfile.m_pInterfaceRef)
	{
		ImGui::Text("Attacks For TakeDown");
		ImGui::SameLine();

		string label1 = "##AttacksForTakeDown" + to_string(actorIndex);

		ImGui::InputInt(label1.c_str(), &actor->m_rCCProfile.m_pInterfaceRef->m_nAttacksForTakeDown);

		ImGui::Text("Hitman Damage");
		ImGui::SameLine();

		string label2 = "##HitmanDamage" + to_string(actorIndex);

		ImGui::InputFloat(label2.c_str(), &actor->m_rCCProfile.m_pInterfaceRef->m_fHitmanDamage);

		ImGui::Checkbox("Allow Attacking Hitman", &actor->m_rCCProfile.m_pInterfaceRef->m_bAllowAttackingHitman);
		ImGui::Text("Actor Preset: %s", GetActorCCPreset(actor->m_rCCProfile.m_pInterfaceRef->m_eActorCCPreset));
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

	ImGui::Text("Actor Name: %s", actor->m_sActorName.m_chars);
	ImGui::Text("Actor Type: %s", GetActorType(actor->m_eActorType));
	ImGui::Text("Actor Rank: %s", GetActorRank(actor->m_eActorRank));
	ImGui::Text("Actor Group: %s", GetActorGroup(actor->m_eActorGroup));

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
		static bool undefined = true, invisible = false, accident = false, pacified = false, pacifiedAccident = false, murder = false, bloodyMurder = false;
		static bool deathVisible = true;
		EActorDeathType actorDeathType;

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

	static bool dropWeapon;
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

		TEntityRef<IHM5ItemWeapon> currentWeapon = {};
		actor->GetCurrentWeapon(&currentWeapon);

		AddCurrentWeaponInfo(currentWeapon, color, actorIndex);

		ImGui::Separator();

		if (currentWeapon.m_pInterfaceRef)
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

	static bool switchToLeftHand;
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

	static bool tagged;
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

	bool haveTargets = false;

	if (ImGui::Button("Test All Targets Killed"))
	{
		actor->TestAllTargetsKilled(&haveTargets);
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

	ZString weaponName = {};
	actor->GetWeaponName(&weaponName);

	ImGui::Text("Weapon Name: %s", weaponName.m_chars);

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

	AddLocalPositionInputs(actor, flags, color, actorIndex);
	AddWorldPositionInputs(actor, flags, color, actorIndex);

	ImGui::Separator();
}

void ActorsInfo::AddBaseCharacterInfo(ZActor* actor)
{
	bool bodyColiEnabled = static_cast<bool>(actor->m_bBodyColiEnabled);
	ImGui::Checkbox("Body Coli Enabled", &bodyColiEnabled);

	actor->m_bBodyColiEnabled = bodyColiEnabled;

	bool bodyColiInitialized = static_cast<bool>(actor->m_bBodyColiInitialized);
	ImGui::Checkbox("Body Coli Initialized", &bodyColiInitialized);

	actor->m_bBodyColiInitialized = bodyColiInitialized;

	bool ignoreOnePositionChange = static_cast<bool>(actor->m_bIgnoreOnePositionChange);
	ImGui::Checkbox("Ignore One Position Change", &ignoreOnePositionChange);

	actor->m_bIgnoreOnePositionChange = ignoreOnePositionChange;

	bool bBaseCharInitialized = static_cast<bool>(actor->m_bBaseCharInitialized);

	if (bBaseCharInitialized)
	{
		ImGui::Text("Base Char Initialized: Yes");
	}
	else
	{
		ImGui::Text("Base Char Initialized: No");
	}

	bool shootColiPrimitiveActive = static_cast<bool>(actor->m_bShootColiPrimitiveActive);
	ImGui::Checkbox("Shoot Coli Primitive Active", &shootColiPrimitiveActive);

	actor->m_bShootColiPrimitiveActive = shootColiPrimitiveActive;

	bool shootColiSystemActive = static_cast<bool>(actor->m_bShootColiSystemActive);
	ImGui::Checkbox("Shoot Coli System Active", &shootColiSystemActive);

	actor->m_bShootColiSystemActive = shootColiSystemActive;

	bool initialized = static_cast<bool>(static_cast<ZHM5BaseCharacter*>(actor)->m_bInitialized);

	if (initialized)
	{
		ImGui::Text("Initialized: Yes");
	}
	else
	{
		ImGui::Text("Initialized: No");
	}

	bool initializingBaseCharacter = static_cast<bool>(actor->m_bInitializingBaseCharacter);

	if (initializingBaseCharacter)
	{
		ImGui::Text("Initializing Base Character: Yes");
	}
	else
	{
		ImGui::Text("Initializing Base Character: No");
	}

	bool isInCrowd = static_cast<bool>(actor->m_bIsInCrowd);

	if (isInCrowd)
	{
		ImGui::Text("Is In Crowd");
	}
	else
	{
		ImGui::Text("Is In Crowd");
	}

	bool isInLimitVisionAreaZone = static_cast<bool>(actor->m_bIsInLimitVisionAreaZone);
	ImGui::Checkbox("Is In Limit Vision Area Zone", &isInLimitVisionAreaZone);

	actor->m_bIsInLimitVisionAreaZone = isInLimitVisionAreaZone;

	bool isInsideLimitVisionArea = static_cast<bool>(actor->m_bIsInsideLimitVisionArea);
	ImGui::Checkbox("Is Inside Limit Vision Area", &isInsideLimitVisionArea);

	actor->m_bIsInsideLimitVisionArea = isInsideLimitVisionArea;

	bool isBlockedByLimitVisionArea = static_cast<bool>(actor->m_bIsBlockedByLimitVisionArea);
	ImGui::Checkbox("Is Blocked By Limit Vision Area", &isBlockedByLimitVisionArea);

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

	bool showCharacter = !actor->IsCharacterHidden();
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

void ActorsInfo::KillAllActors(ZActorManager* actorManager)
{
	for (unsigned int i = 0; i < actorManager->m_aliveActors.Size(); i++)
	{
		actorManager->m_aliveActors[i]->m_pInterfaceRef->KillActor(EActorDeathType::eADT_ACCIDENT, true);
	}
}

char* ActorsInfo::Strdup(const char* s)
{
	IM_ASSERT(s);
	size_t length = strlen(s) + 1;
	void* buffer = malloc(length);
	IM_ASSERT(buffer);

	return (char*)memcpy(buffer, (const void*)s, length);
}
