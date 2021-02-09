#include "ItemsInfo.h"

void ItemsInfo::DrawWindow(bool* showItemsInfo)
{
	ImGui::SetNextWindowSize(ImVec2(500, 440), ImGuiCond_FirstUseEver);

	if (!ImGui::Begin("Items Info", showItemsInfo))
	{
		ImGui::End();
		return;
	}

	int sharedKnowledgeCount = ZKnowledge::GetSharedKnowledgeCount();

	static int selected = 0;
	ImGui::BeginChild("left pane", ImVec2(150, 0), true);

	for (int i = 0; i < sharedKnowledgeCount; i++)
	{
		char label[128];
		sprintf_s(label, "Item %d", i);

		if (ImGui::Selectable(label, selected == i))
		{
			selected = i;
		}
	}

	ImGui::EndChild();
	ImGui::SameLine();

	ImGui::BeginGroup();
	ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()));

	ZSharedKnowledgeRef sharedKnowledgeRef = {};
	ZKnowledge::GetSharedKnowledgeByIndex(&sharedKnowledgeRef, selected);

	AddItemInfo(&sharedKnowledgeRef);

	ImGui::EndChild();
	ImGui::EndGroup();
	ImGui::End();
}

void ItemsInfo::AddItemInfo(ZSharedKnowledgeRef* sharedKnowledgeRef)
{
	EKnownEntityType knownEntityType = sharedKnowledgeRef->m_pSharedEntityKnowledge->m_type;
	bool perceptible = sharedKnowledgeRef->m_pSharedEntityKnowledge->m_bPerceptible;

	if (knownEntityType == EKnownEntityType::KET_ITEM && perceptible)
	{
		ZEntityRef entityRef = sharedKnowledgeRef->m_pSharedEntityKnowledge->m_pEntity;

		STypeID* typeID = TTypeIDHelper<ZHM5ItemWeapon>::GetTypeID(0x824C0);
		//ZEntityType** type = entityRef->QueryInterfacePtr(typeID);
		//ZHM5ItemWeapon* itemWeapon = reinterpret_cast<ZHM5ItemWeapon*>(type);

		/*if (itemWeapon)
		{
			AddZHM5ItemWeaponInfo(itemWeapon);
		}*/
	}
}

void ItemsInfo::AddZHM5ItemWeaponInfo(ZHM5ItemWeapon* itemWeapon)
{
	if (!itemWeapon)
	{
		return;
	}

	ImGui::Text("Item Size: %s", GetItemSize(itemWeapon->GetItemSize()));
	ImGui::Text("Item Hands: %s", GetItemHands(itemWeapon->GetItemHands()));
	ImGui::Text("Item Hands Cover Anim Layer: %s", GetItemHandsCoverAnimLayer(itemWeapon->GetItemHandsCoverAnimLayer()));
	ImGui::Text("Item Type: %s", GetItemType(static_cast<IHM5ItemWeapon*>(itemWeapon)->GetItemType()));

	ImGui::Text("Item Name: %s", itemWeapon->m_sItemName.m_chars);

	ZString itemTypeName = {};
	itemWeapon->GetItemTypeName(&itemTypeName);

	ImGui::Text("Item Type Name: %s", itemTypeName.m_chars);

	if (itemWeapon->IsInventoryItem())
	{
		ImGui::Text("Is Inventory Item: Yes");
	}
	else
	{
		ImGui::Text("Is Inventory Item: No");
	}

	if (itemWeapon->IsInspectItem())
	{
		ImGui::Text("Is Inspect Item: Yes");
	}
	else
	{
		ImGui::Text("Is Inspect Item: No");
	}

	if (itemWeapon->ItemHidden())
	{
		ImGui::Text("Item Hidden: Yes");
	}
	else
	{
		ImGui::Text("Item Hidden: No");
	}

	ZString debugName = {};
	itemWeapon->GetDebugName(&debugName);

	ImGui::Text("Debug Name: %s", debugName.m_chars);

	if (itemWeapon->IsThrown())
	{
		ImGui::Text("Is Thrown: Yes");
	}
	else
	{
		ImGui::Text("Is Thrown: No");
	}

	if (itemWeapon->IsPercievedAsWeapon())
	{
		ImGui::Text("Is Percieved As Weapon: Yes");
	}
	else
	{
		ImGui::Text("Is Percieved As Weapon: No");
	}

	if (itemWeapon->CanBeDualWielded())
	{
		ImGui::Text("Can Be Dual Wielded: Yes");
	}
	else
	{
		ImGui::Text("Can Be Dual Wielded: No");
	}

	ImGui::Text("");
}

const char* ItemsInfo::GetItemSize(eItemSize itemSize)
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

const char* ItemsInfo::GetItemHands(eItemHands itemHands)
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

const char* ItemsInfo::GetItemHandsCoverAnimLayer(eItemHands itemHands)
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

const char* ItemsInfo::GetItemType(eItemType itemType)
{
	const char* type{};

	switch (itemType)
	{
	case eCC_FireExtinguisher_01:
		type = "Fire Extinguisher 01";
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
		type = "Statue Bust A";
		break;
	case eGun_44AutoMag:
		type = "Gun 44 Auto Mag";
		break;
	case eGun_44AutoMagSilenced:
		type = "Gun 44 Auto Mag Silenced";
		break;
	case eGun_Derringer:
		type = "Gun Derringer";
		break;
	case eGun_Glock:
		type = "Gun Glock";
		break;
	case eGun_GlockDirty:
		type = "Gun Glock Dirty";
		break;
	case eGun_GlockSilenced:
		type = "Gun Glock Silenced";
		break;
	case eGun_HardBaller_01:
		type = "Gun Hard Baller 01";
		break;
	case eGun_HardBallerSilenced:
		type = "Gun Hard Baller Silenced";
		break;
	case eGun_Sig226:
		type = "Gun Sig226";
		break;
	case eGun_Sig226Silenced:
		type = "Gun Sig226 Silenced";
		break;
	case eGun_Sphinx3000:
		type = "Gun Sphinx3000";
		break;
	case eGun_Taurus24_7:
		type = "Gun Taurus24 7";
		break;
	case eGun_Taurus24_7Silenced:
		type = "Gun Taurus24 7 Silenced";
		break;
	case eGun_Spotter:
		type = "Gun Spotter";
		break;
	case eOther_MG:
		type = "Other MG";
		break;
	case eOther_RPG:
		type = "Other RPG";
		break;
	case eRevolver_PoliceRevolver:
		type = "Revolver Police Revolver";
		break;
	case eRevolver_Snubnosed:
		type = "Revolver Snubnosed";
		break;
	case eRevolver_Taurus:
		type = "Revolver Taurus";
		break;
	case eRifle_HK416:
		type = "Rifle HK416";
		break;
	case eRifle_HK416Scope:
		type = "Rifle HK416 Scope";
		break;
	case eRifle_HK416Silenced:
		type = "Rifle HK416 Silenced";
		break;
	case eRifle_PumpRifle:
		type = "Rifle Pump Rifle";
		break;
	case eRifle_SG552:
		type = "Rifle SG552";
		break;
	case eRifle_SG552Scope:
		type = "Rifle SG552 Scope";
		break;
	case eShotgun_M500:
		type = "Shotgun M500";
		break;
	case eShotgun_M500New:
		type = "Shotgun M500 New";
		break;
	case eSMG_HK_UMP:
		type = "SMG HK UMP";
		break;
	case eSMG_HK_UMPFlashlight:
		type = "SMG HK UMP Flashlight";
		break;
	case eSMG_HK_UMPScope:
		type = "SMG HK UMP Scope";
		break;
	case eSMG_HK_UMPSilenced:
		type = "SMG HK UMP Silenced";
		break;
	case eSMG_TMP:
		type = "SMG TMP";
		break;
	case eSniper_AS50:
		type = "Sniper AS50";
		break;
	case eSniper_Remington700:
		type = "Sniper Remington700";
		break;
	case eSniper_SakoTRG:
		type = "Sniper Sako TRG";
		break;
	case eSniper_SakoTRGSilenced:
		type = "Sniper Sako TRG Silenced";
		break;
	case eItemAmmo:
		type = "Item Ammo";
		break;
	case eCC_FiberWire:
		type = "Fiber Wire";
		break;
	case eOther_ZippoLighter:
		type = "Other Zippo Lighter";
		break;
	case eOther_Keycard_A:
		type = "Other Keycard A";
		break;
	case eOther_SecurityTape:
		type = "Other Security Tape";
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
		type = "Other Contract Envelope";
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
		type = "Rifle Beretta ARX160";
		break;
	case eShotgun_Spas12:
		type = "Shotgun Spas12";
		break;
	case eShotgun_Spas12_Compact:
		type = "Shotgun Spas12 Compact";
		break;
	case eShotgun_Silenced:
		type = "Shotgun Silenced";
		break;
	case eSMG_AK74u:
		type = "SMG AK74u";
		break;
	case eSMG_STK:
		type = "SMG STK";
		break;
	case eDLC_TEST_FireArm_01:
		type = "DLC TEST Fire Arm 01";
		break;
	case eDLC_TEST_FireArm_02:
		type = "DLC TEST Fire Arm 02";
		break;
	case eDLC_TEST_Prop_01:
		type = "DLC TEST Prop 01";
		break;
	case eDLC_TEST_Prop_02:
		type = "DLC TEST Prop 02";
		break;
	case eHotSauceBarrel:
		type = "Hot Sauce Barrel";
		break;
	case eOther_GenericPickup:
		type = "Other Generic Pickup";
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
		type = "Book A";
		break;
	case eUnknownItemType:
		type = "Unknown Item Type";
		break;
	}

	return type;
}
