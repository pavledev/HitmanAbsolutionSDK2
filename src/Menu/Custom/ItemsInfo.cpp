#pragma warning(disable : 26812)

#include <vector>
#include "ItemsInfo.h"
#include "SInterfaceData.h"
#include "ZEntityType.h"
#include "IType.h"
#include "ZSpatialEntity.h"
#include "ZLevelManager.h"
#include "ZHitman5.h"
#include "ZHM5BaseInventory.h"

ItemsInfo::ItemsInfo()
{
	flags = ImGuiInputTextFlags_EnterReturnsTrue;
	color = ImVec4(1.0f, 0.8f, 0.6f, 1.0f);
}

void ItemsInfo::DrawWindow(bool* showItemsInfo)
{
	ImGui::SetNextWindowSize(ImVec2(766, 440), ImGuiCond_FirstUseEver);

	if (!ImGui::Begin("Items Info", showItemsInfo))
	{
		ImGui::End();

		return;
	}

	static ZHM5ActionManager* actionManager = Singletons::GetHM5ActionManager();
	unsigned int itemsSize = actionManager->m_Actions.m_nSize;

	if (itemsSize == 0)
	{
		ImGui::End();

		return;
	}

	TSListIterator<ZHM5ActionManager::SActionTreeEntry> actionIterator = actionManager->m_Actions.Begin();
	vector<ZHM5Action*> actions;

	for (unsigned i = 0; i < itemsSize; i++)
	{
		ZHM5Action* action = actionIterator.m_pCurrent->m_pNodeAction;
		EActionType actionType = action->GetActionType();

		if (actionType == EActionType::AT_PICKUP)
		{
			actions.push_back(action);
		}

		actionIterator.operator++();
	}

	static int selected = 0;
	int count = actions.size();

	ImGui::BeginChild("left pane", ImVec2(150, 0), true);

	for (int i = 0; i < count; i++)
	{
		char label[128];
		ZHM5Action* action = actions[i];
		string typeName = GetTypeName(action);

		if (typeName == "ZHM5ItemWeapon")
		{
			sprintf_s(label, "ItemWeapon %d", i);
		}
		else if (typeName == "ZHM5ItemCCWeapon")
		{
			sprintf_s(label, "ItemCCWeapon %d", i);
		}
		else if (typeName == "ZHM5ItemAmmo")
		{
			sprintf_s(label, "ItemAmmo %d", i);
		}
		else
		{
			sprintf_s(label, "Item %d", i);
		}

		if (ImGui::Selectable(label, selected == i))
		{
			selected = i;
		}
	}

	ImGui::EndChild();
	ImGui::SameLine();

	ImGui::BeginGroup();
	ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()));

	ImGui::AlignTextToFramePadding();
	ImGui::PushItemWidth(100);

	ZHM5Action* action = actions[selected];
	string typeName = GetTypeName(action);

	STypeID* typeID = TTypeIDHelper<ZHM5ItemWeapon>::GetTypeID();
	ZEntityType** type = reinterpret_cast<ZEntityType**>(action->m_Object.QueryInterfacePtr(typeID));
	ZHM5ItemWeapon* itemWeapon = reinterpret_cast<ZHM5ItemWeapon*>(type);

	if (itemWeapon)
	{
		AddItemWeaponInfo(itemWeapon, &action->m_Object, selected);
	}
	else
	{
		typeID = TTypeIDHelper<ZHM5ItemCCWeapon>::GetTypeID();
		type = reinterpret_cast<ZEntityType**>(action->m_Object.QueryInterfacePtr(typeID));

		ZHM5ItemCCWeapon* itemCCWeapon = reinterpret_cast<ZHM5ItemCCWeapon*>(type);

		if (itemCCWeapon)
		{
			AddItemCCWeaponInfo(itemCCWeapon, &action->m_Object, selected);
		}
		else
		{
			typeID = TTypeIDHelper<ZHM5ItemAmmo>::GetTypeID();
			type = reinterpret_cast<ZEntityType**>(action->m_Object.QueryInterfacePtr(typeID));

			ZHM5ItemAmmo* itemAmmo = reinterpret_cast<ZHM5ItemAmmo*>(type);

			if (itemAmmo)
			{
				AddItemAmmoInfo(itemAmmo, &action->m_Object, selected);
			}
			else
			{
				typeID = TTypeIDHelper<IHM5Item>::GetTypeID();
				type = reinterpret_cast<ZEntityType**>(action->m_Object.QueryInterfacePtr(typeID));

				IHM5Item* item = reinterpret_cast<IHM5Item*>(type);

				if (item)
				{
					AddItemInfo(item, &action->m_Object, selected);
				}
			}
		}
	}

	ImGui::PopItemWidth();

	ImGui::EndChild();
	ImGui::EndGroup();
	ImGui::End();
}

void ItemsInfo::AddItemInfo(IHM5Item* item, ZEntityRef* entityRef, int itemIndex)
{
	ImGui::Text("Item Size: %s", GetItemSize(item->GetItemSize()));
	ImGui::Text("Item Hands: %s", GetItemHands(item->GetItemHands()));
	ImGui::Text("Item Hands Cover Anim Layer: %s", GetItemHandsCoverAnimLayer(item->GetItemHandsCoverAnimLayer()));
	ImGui::Text("Item Type: %s", GetItemType(item->GetItemType()));
	ImGui::Text("Item Name: %s", item->GetItemName().ToCString());
	ImGui::Text("Item Type Name: %s", item->GetItemTypeName().ToCString());

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

	AddLocalPositionInputs(item->GetSpatialEntity().GetRawPointer(), itemIndex);
	AddWorldPositionInputs(item->GetSpatialEntity().GetRawPointer(), itemIndex);

	if (ImGui::Button("Teleport Item To Player"))
	{
		static ZLevelManager* levelManager = Singletons::GetLevelManager();
		ZHitman5* player = levelManager->GetHitman().GetRawPointer();

		if (player)
		{
			float4 playerLocalPosition = player->GetSpatialEntityPtr()->GetWorldPosition();
			float4 correct = { 0, -0.5f, 0.05f, 0 };

			item->GetSpatialEntity().GetRawPointer()->SetWorldPosition(playerLocalPosition + correct);
		}
	}

	if (ImGui::Button("Add Weapon To Inventory"))
	{
		static ZLevelManager* levelManager = Singletons::GetLevelManager();
		ZHitman5* player = levelManager->GetHitman().GetRawPointer();

		if (player)
		{
			TEntityRef<IHM5Item> entityRef2 = {};

			entityRef2.m_entityRef = *entityRef;
			entityRef2.m_pInterfaceRef = item;

			//player->AddItemToInventory(const_cast<TEntityRef<IHM5Item>&>(entityRef2));
			player->GetBaseInventory()->AddItemToInventory(const_cast<TEntityRef<IHM5Item>&>(entityRef2), false, false);
		}
	}

	if (ImGui::Button("Pickup Weapon"))
	{
		static ZLevelManager* levelManager = Singletons::GetLevelManager();
		ZHitman5* player = levelManager->GetHitman().GetRawPointer();

		if (player)
		{
			TEntityRef<IHM5Item> entityRef2 = {};

			entityRef2.m_entityRef = *entityRef;
			entityRef2.m_pInterfaceRef = item;

			player->PickupItem(entityRef2);
		}
	}
}

void ItemsInfo::AddItemWeaponInfo(IHM5ItemWeapon* itemWeapon, ZEntityRef* entityRef, int itemIndex)
{
	ImGui::Text("Bullets In Magazine");
	ImGui::SameLine();

	static string label1 = "##BulletsInMagazine" + to_string(itemIndex);
	unsigned short numberOfBulletsInMagazine = itemWeapon->GetBulletsInMagazine();

	if (ImGui::InputScalar(label1.c_str(), ImGuiDataType_U16, &numberOfBulletsInMagazine, 0, 0, 0, flags))
	{
		itemWeapon->SetBulletsInMagazine(numberOfBulletsInMagazine);
	}

	if (itemWeapon->IsHandGun())
	{
		ImGui::Text("Is HandGun: Yes");
	}
	else
	{
		ImGui::Text("Is HandGun: No");
	}

	if (itemWeapon->IsRevolver())
	{
		ImGui::Text("Is Revolver: Yes");
	}
	else
	{
		ImGui::Text("Is Revolver: No");
	}

	if (itemWeapon->IsSmg())
	{
		ImGui::Text("Is Smg: Yes");
	}
	else
	{
		ImGui::Text("Is Smg: No");
	}

	if (itemWeapon->IsRifle())
	{
		ImGui::Text("Is Rifle: Yes");
	}
	else
	{
		ImGui::Text("Is Rifle: No");
	}

	if (itemWeapon->IsRPG())
	{
		ImGui::Text("Is RPG: Yes");
	}
	else
	{
		ImGui::Text("Is RPG: No");
	}

	if (itemWeapon->IsSniper())
	{
		ImGui::Text("Is Sniper: Yes");
	}
	else
	{
		ImGui::Text("Is Sniper: No");
	}

	if (itemWeapon->IsShotgun())
	{
		ImGui::Text("Is Shotgun: Yes");
	}
	else
	{
		ImGui::Text("Is Shotgun: No");
	}

	if (itemWeapon->IsFireArm())
	{
		ImGui::Text("Is Fire Arm: Yes");
	}
	else
	{
		ImGui::Text("Is Fire Arm: No");
	}

	if (itemWeapon->IsProjectileWeapon())
	{
		ImGui::Text("Is Projectile Weapon: Yes");
	}
	else
	{
		ImGui::Text("Is Projectile Weapon: No");
	}

	if (itemWeapon->IsCloseCombatWeapon())
	{
		ImGui::Text("Is Close Combat Weapon: Yes");
	}
	else
	{
		ImGui::Text("Is Close Combat Weapon: No");
	}
}

void ItemsInfo::AddItemWeaponInfo(ZHM5ItemWeapon* itemWeapon, ZEntityRef* entityRef, int itemIndex)
{
	AddItemInfo(itemWeapon, entityRef, itemIndex);
	AddItemWeaponInfo(static_cast<IHM5ItemWeapon*>(itemWeapon), entityRef, itemIndex);
}

void ItemsInfo::AddItemCCWeaponInfo(ZHM5ItemCCWeapon* itemCCWeapon, ZEntityRef* entityRef, int itemIndex)
{
	AddItemInfo(itemCCWeapon, entityRef, itemIndex);
	AddItemWeaponInfo(itemCCWeapon, entityRef, itemIndex);
}

void ItemsInfo::AddItemAmmoInfo(ZHM5ItemAmmo* itemAmmo, ZEntityRef* entityRef, int itemIndex)
{
	AddItemInfo(itemAmmo, entityRef, itemIndex);

	if (itemAmmo->IsInfinite())
	{
		ImGui::Text("Is Infinite: Yes");
	}
	else
	{
		ImGui::Text("Is Infinite: No");
	}

	ImGui::Text("Ammo");
	ImGui::SameLine();

	static string label1 = "##Ammo" + to_string(itemIndex);
	int numberOfAmmo = itemAmmo->GetNumberOfAmmo();

	if (ImGui::InputInt(label1.c_str(), &numberOfAmmo, 0, 0, flags))
	{
		itemAmmo->SetNumberOfAmmo(numberOfAmmo);
	}
}

void ItemsInfo::AddLocalPositionInputs(ZSpatialEntity* spatialEntity, int itemIndex)
{
	ImGui::TextColored(color, "Local Position");

	float4 localPosition = spatialEntity->GetLocalPosition();

	ImGui::Text("X");
	ImGui::SameLine();

	static string label1 = "##localPositionX" + to_string(itemIndex);

	if (ImGui::InputFloat(label1.c_str(), &localPosition.x(), 0, 0, "%.3f", flags))
	{
		spatialEntity->SetLocalPosition(localPosition);
	}

	ImGui::SameLine();
	ImGui::Text("Y");
	ImGui::SameLine();

	static string label2 = "##localPositionY" + to_string(itemIndex);

	if (ImGui::InputFloat(label2.c_str(), &localPosition.y(), 0, 0, "%.3f", flags))
	{
		spatialEntity->SetLocalPosition(localPosition);
	}

	ImGui::SameLine();
	ImGui::Text("Z");
	ImGui::SameLine();

	static string label3 = "##localPositionZ" + to_string(itemIndex);

	if (ImGui::InputFloat(label3.c_str(), &localPosition.z(), 0, 0, "%.3f", flags))
	{
		spatialEntity->SetLocalPosition(localPosition);
	}

	ImGui::SameLine();
	ImGui::Text("W");
	ImGui::SameLine();

	static string label4 = "##localPositionW" + to_string(itemIndex);

	if (ImGui::InputFloat(label4.c_str(), &localPosition.w(), 0, 0, "%.3f", flags))
	{
		spatialEntity->SetLocalPosition(localPosition);
	}
}

void ItemsInfo::AddWorldPositionInputs(ZSpatialEntity* spatialEntity, int itemIndex)
{
	ImGui::TextColored(color, "World Position");

	float4 worldPosition = spatialEntity->GetWorldPosition();

	ImGui::Text("X");
	ImGui::SameLine();

	static string label1 = "##wordPositionX" + to_string(itemIndex);

	if (ImGui::InputFloat(label1.c_str(), &worldPosition.x(), 0, 0, "%.3f", flags))
	{
		spatialEntity->SetWorldPosition(worldPosition);
	}

	ImGui::SameLine();
	ImGui::Text("Y");
	ImGui::SameLine();

	static string label2 = "##wordPositionY" + to_string(itemIndex);

	if (ImGui::InputFloat(label2.c_str(), &worldPosition.y(), 0, 0, "%.3f", flags))
	{
		spatialEntity->SetWorldPosition(worldPosition);
	}

	ImGui::SameLine();
	ImGui::Text("Z");
	ImGui::SameLine();

	static string label3 = "##wordPositionZ" + to_string(itemIndex);

	if (ImGui::InputFloat(label3.c_str(), &worldPosition.z(), 0, 0, "%.3f", flags))
	{
		spatialEntity->SetWorldPosition(worldPosition);
	}

	ImGui::SameLine();
	ImGui::Text("W");
	ImGui::SameLine();

	static string label4 = "##wordPositionW" + to_string(itemIndex);

	if (ImGui::InputFloat(label4.c_str(), &worldPosition.w(), 0, 0, "%.3f", flags))
	{
		spatialEntity->SetWorldPosition(worldPosition);
	}
}

string ItemsInfo::GetTypeName(ZHM5Action* action)
{
	TArray<SInterfaceData> interfaceDataArray = *action->m_Object.m_pEntityTypePtrPtr[0]->m_pInterfaceData;
	string typeName = interfaceDataArray[0]->m_Type->pTypeInfo->pszTypeName;

	return typeName;
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
