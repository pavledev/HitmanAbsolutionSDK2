#pragma warning(disable : 26812)

#include "PlayerInfo.h"
#include "ZHM5CCProfile.h"
#include "ZCrowdEntity.h"
#include "ZCheckPointManagerEntity.h"
#include "ZCheckPointEntity.h"
#include "ZGlobalOutfitKit.h"
#include "ZCrowdActorCore.h"
#include "ZCrowdActorState.h"
#include "ZHitman5.h"
#include "ZOutfitManagerEntity.h"
#include "ZTokenIDEntity.h"
#include "ZHM5BaseMovement.h"
#include "IHM5ItemWeapon.h"
#include "ZHM5BaseInventory.h"
#include "ZHM5SneakController.h"
#include "ZHM5ActorControl.h"
#include "ZHM5Outfit.h"
#include "ZHM5Health.h"
#include "ZHM5CameraBaseFunc.h"
#include "ZHM5MainCamera.h"
#include "TPair.h"
#include "ZHM5ActionManager.h"
#include "ZHM5SBTargetPropManager.h"

const char* PlayerInfo::GetMovementType(ZHitman5* player)
{
	const char* type{};

	switch (player->GetCurrentMovement()->GetType())
	{
	case eMovementNone:
		type = "Movement None";
		break;
	case eMovementDead:
		type = "Movement Dead";
		break;
	case eMovementLedgeHang:
		type = "Movement Ledge Hang";
		break;
	case eMovementLedgeWalk:
		type = "Movement Ledge Walk";
		break;
	case eMovementClimbWindow:
		type = "Movement Climb Window";
		break;
	case eMovementShootingBallet:
		type = "Movement Shooting Ballet";
		break;
	case eMovementCover:
		type = "Movement Cover";
		break;
	case eMovementLadder:
		type = "Movement Ladder";
		break;
	case eMovementPullVictimFromWindow:
		type = "Movement Pull Victim From Window";
		break;
	case eMovementFiberWireKill:
		type = "Movement Fiber Wire Kill";
		break;
	case eMovementThrowBodyOverRail:
		type = "Movement Throw Body Over Rail";
		break;
	case eMovementDumpBodyOverLedge:
		type = "Movement Dump Body Over Ledge";
		break;
	case eMovementDumpBody:
		type = "Movement Dump Body";
		break;
	case eMovementOperateCPDoor:
		type = "Movement Operate CP Door";
		break;
	case eMovementDisguiseSafeZone:
		type = "Movement Disguise Safe Zone";
		break;
	case eMovementHideInCloset:
		type = "Movement Hide In Closet";
		break;
	case eMovementHumanShield:
		type = "Movement Human Shield";
		break;
	case eMovementCloseCombat:
		type = "Movement Close Combat";
		break;
	case eMovementDisableFuseBox:
		type = "Movement Disable Fuse Box";
		break;
	case eMovementContextAction:
		type = "Movement Context Action";
		break;
	case eMovementInteractiveCutsequence:
		type = "Movement Interactive Cutsequence";
		break;
	case eMovementVentilatorShaft:
		type = "Movement Ventilator Shaft";
		break;
	case eMovementPushVictimThroughWindowAndRail:
		type = "Movement Push Victim Through Window And Rail";
		break;
	case eMovementKickVictimOverLedge:
		type = "Movement Kick Victim Over Ledge";
		break;
	case eMovementKeyCardReader:
		type = "Movement Key Card Reader";
		break;
	case eMovementDragBody:
		type = "Movement Drag Body";
		break;
	case eMovementTakeClothes:
		type = "Movement Take Clothes";
		break;
	case eMovementCarryCivilian:
		type = "Movement Carry Civilian";
		break;
	case eMovementToss:
		type = "Movement Toss";
		break;
	case eMovementSurrender:
		type = "Movement Surrender";
		break;
	case eMovementUseHealthStation:
		type = "Movement Use Health Station";
		break;
	case eMovementPickupItem:
		type = "Movement Pickup Item";
		break;
	case eMovementLocomotion:
		type = "Movement Locomotion";
		break;
	case eMovementLast:
		type = "Movement Last";
		break;
	}

	return type;
}

const char* PlayerInfo::GetGameInputFlag(ZHitman5* player)
{
	const char* type{};

	switch (player->GetCurrentMovement()->m_eMarkInputFlagAsConsumed)
	{
	case eGameInputActionPerform:
		type = "Game Input Action Perform";
		break;
	case eGameInputActionPickup:
		type = "Game Input Action Pickup";
		break;
	case eGameInputActionAbort:
		type = "Game Input Action Abort";
		break;
	case eGameInputActionDoor:
		type = "Game Input Action Door";
		break;
	case eGameInputWeaponZoomIn:
		type = "Game Input Weapon Zoom In";
		break;
	case eGameInputWeaponZoomOut:
		type = "Game Input Weapon Zoom Out";
		break;
	case eGameInputActionShoot:
		type = "Game Input Action Shoot";
		break;
	case eGameInputActionPrecisionShoot:
		type = "Game Input Action Precision Shoot";
		break;
	case eGameInputAimOTS:
		type = "Game Input Aim OTS";
		break;
	case eGameInputCoverAction:
		type = "Game Input Cover Action";
		break;
	case eGameInputCoverAlternativeAction:
		type = "Game Input Cover Alternative Action";
		break;
	case eGameInputInventoryAccept:
		type = "Game Input Inventory Accept";
		break;
	case eGameInputInventoryCancel:
		type = "Game Input Inventory Cancel";
		break;
	case eGameInputEquipCloseCombatProps:
		type = "Game Input Equip Close Combat Props";
		break;
	case eGameInputEquipCloseCombatPropsInverse:
		type = "Game Input Equip Close Combat Props Inverse";
		break;
	case eGameInputEquipShortRange:
		type = "Game Input Equip Short Range";
		break;
	case eGameInputEquipLongRange:
		type = "Game Input Equip Long Range";
		break;
	case eGameInputEquipWeapon1:
		type = "Game Input Equip Weapon1";
		break;
	case eGameInputEquipWeapon2:
		type = "Game Input Equip Weapon2";
		break;
	case eGameInputEquipWeapon3:
		type = "Game Input Equip Weapon3";
		break;
	case eGameInputEquipWeapon4:
		type = "Game Input Equip Weapon4";
		break;
	case eGameInputEquipWeapon5:
		type = "Game Input Equip Weapon5";
		break;
	case eGameInputEquipWeapon6:
		type = "Game Input Equip Weapon6";
		break;
	case eGameInputEquipWeapon7:
		type = "Game Input Equip Weapon7";
		break;
	case eGameInputEquipNextWeapon:
		type = "Game Input Equip Next Weapon";
		break;
	case eGameInputEquipPreviousWeapon:
		type = "Game Input Equip Previous Weapon";
		break;
	case eGameInputHolsterItem:
		type = "Game Input Holster Item";
		break;
	case eGameInputDropItem:
		type = "Game Input Drop Item";
		break;
	case eGameInputActivateProp:
		type = "Game Input Activate Prop";
		break;
	case eGameInputShootingBalletActivate:
		type = "Game Input Shooting Ballet Activate";
		break;
	case eGameInputShootingBalletExecute:
		type = "Game Input Shooting Ballet Execute";
		break;
	case eGameInputShootingBalletCancel:
		type = "Game Input Shooting Ballet Cancel";
		break;
	case eGameInputShootingBalletHMView:
		type = "Game Input Shooting Ballet HM View";
		break;
	case eGameInputGuideAction:
		type = "Game Input Guide Action";
		break;
	case eGameInputGuideActionSecondary:
		type = "Game Input Guide Action Secondary";
		break;
	case eGameInputGuideEnterWindow:
		type = "Game Input Guide Enter Window";
		break;
	case eGameInputGuideSneakPastWindow:
		type = "Game Input Guide Sneak Past Window";
		break;
	case eGameInputGuideKill:
		type = "Game Input Guide Kill";
		break;
	case eGameInputSlideLadder:
		type = "Game Input Slide Ladder";
		break;
	case eGameInputCloseCombat:
		type = "Game Input Close Combat";
		break;
	case eGameInputFiberwire:
		type = "Game Input Fiberwire";
		break;
	case eGameInputCloseCombatCounter:
		type = "Game Input Close Combat Counter";
		break;
	case eGameInputCloseCombatTakeDown:
		type = "Game Input Close Combat Take Down";
		break;
	case eGameInputCloseCombatDisarm:
		type = "Game Input Close Combat Disarm";
		break;
	case eGameInputInteractiveCutA:
		type = "Game Input Interactive Cut A";
		break;
	case eGameInputInteractiveCutX:
		type = "Game Input Interactive Cut X";
		break;
	case eGameInputInteractiveCutY:
		type = "Game Input Interactive Cut Y";
		break;
	case eGameInputInteractiveCutB:
		type = "Game Input Interactive Cut B";
		break;
	case eGameInputSurrender:
		type = "Game Input Surrender";
		break;
	case eGameInputReload:
		type = "Game Input Reload";
		break;
	case eGameInputTakeDisguise:
		type = "Game Input Take Disguise";
		break;
	case eGameInputDragDropBody:
		type = "Game Input Drag Drop Body";
		break;
	case eGameInputDumpBody:
		type = "Game Input Dump Body";
		break;
	case eGameInputSneakToggle:
		type = "Game Input Sneak Toggle";
		break;
	case eGameInputCamSwitch:
		type = "Game Input Cam Switch";
		break;
	case eGameInputActivateRun:
		type = "Game Input Activate Run";
		break;
	case eGameInputInstinctMode:
		type = "Game Input Instinct Mode";
		break;
	case eGameInputToggleAlternateFire:
		type = "Game Input Toggle Alternate Fire";
		break;
	case eGameInputToss:
		type = "Game Input Toss";
		break;
	case eGameInputContractsAddMark:
		type = "Game Input Contracts Add Mark";
		break;
	case eGameInputCloseCombatChainHigh:
		type = "Game Input Close Combat Chain High";
		break;
	case eGameInputCloseCombatChainLow:
		type = "Game Input Close Combat Chain Low";
		break;
	case eGameInputCloseCombatChainCounter:
		type = "Game Input Close Combat Chain Counter";
		break;
	case eGameInputTakeHumanShield:
		type = "Game Input Take Human Shield";
		break;
	case eGameInputSkipCutSequence:
		type = "Game Input Skip Cut Sequence";
		break;
	case eGameInputShowWeaponSelector:
		type = "Game Input Show Weapon Selector";
		break;
	case eGameInputCoverSwitchCoverAction:
		type = "Game Input Cover Switch Cover Action";
		break;
	case eGameInputActionsNUM:
		type = "Game Input Actions NUM";
		break;
	}

	return type;
}

template <class T>
void PlayerInfo::AddLocalPositionInputs(T* interfaceRef, ImGuiInputTextFlags& flags, ImVec4& color)
{
	ImGui::TextColored(color, "Local Position");

	float4 localPosition = interfaceRef->GetSpatialEntityPtr()->GetLocalPosition();

	ImGui::Text("X");
	ImGui::SameLine();

	if (ImGui::InputFloat("##localPositionX", &localPosition.x(), 0, 0, "%.3f", flags))
	{
		interfaceRef->GetSpatialEntityPtr()->SetLocalPosition(localPosition);
	}

	ImGui::SameLine();
	ImGui::Text("Y");
	ImGui::SameLine();

	if (ImGui::InputFloat("##localPositionY", &localPosition.y(), 0, 0, "%.3f", flags))
	{
		interfaceRef->GetSpatialEntityPtr()->SetLocalPosition(localPosition);
	}

	ImGui::SameLine();
	ImGui::Text("Z");
	ImGui::SameLine();

	if (ImGui::InputFloat("##localPositionZ", &localPosition.z(), 0, 0, "%.3f", flags))
	{
		interfaceRef->GetSpatialEntityPtr()->SetLocalPosition(localPosition);
	}

	ImGui::SameLine();
	ImGui::Text("W");
	ImGui::SameLine();

	if (ImGui::InputFloat("##localPositionW", &localPosition.w(), 0, 0, "%.3f", flags))
	{
		interfaceRef->GetSpatialEntityPtr()->SetLocalPosition(localPosition);
	}
}

template <class T>
void PlayerInfo::AddWorldPositionInputs(T* interfaceRef, ImGuiInputTextFlags& flags, ImVec4& color)
{
	ImGui::TextColored(color, "World Position");

	float4 worldPosition = interfaceRef->GetSpatialEntityPtr()->GetWorldPosition();

	ImGui::Text("X");
	ImGui::SameLine();

	if (ImGui::InputFloat("##wordPositionX", &worldPosition.x(), 0, 0, "%.3f", flags))
	{
		interfaceRef->GetSpatialEntityPtr()->SetWorldPosition(worldPosition);
	}

	ImGui::SameLine();
	ImGui::Text("Y");
	ImGui::SameLine();

	if (ImGui::InputFloat("##wordPositionY", &worldPosition.y(), 0, 0, "%.3f", flags))
	{
		interfaceRef->GetSpatialEntityPtr()->SetWorldPosition(worldPosition);
	}

	ImGui::SameLine();
	ImGui::Text("Z");
	ImGui::SameLine();

	if (ImGui::InputFloat("##wordPositionZ", &worldPosition.z(), 0, 0, "%.3f", flags))
	{
		interfaceRef->GetSpatialEntityPtr()->SetWorldPosition(worldPosition);
	}

	ImGui::SameLine();
	ImGui::Text("W");
	ImGui::SameLine();

	if (ImGui::InputFloat("##wordPositionW", &worldPosition.w(), 0, 0, "%.3f", flags))
	{
		interfaceRef->GetSpatialEntityPtr()->SetWorldPosition(worldPosition);
	}
}

const char* PlayerInfo::GetActorCCPreset(EActorCCPreset m_eActorCCPreset)
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

const char* PlayerInfo::GetActorGroup(EActorGroup m_eActorGroup)
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

const char* PlayerInfo::GetActorRank(EActorRank m_eActorRank)
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

const char* PlayerInfo::GetActorType(EActorType m_eActorType)
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

const char* PlayerInfo::GetActorDeathType(EActorDeathType actorDeathType)
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

const char* PlayerInfo::GetItemSize(eItemSize itemSize)
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

const char* PlayerInfo::GetItemHands(eItemHands itemHands)
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

const char* PlayerInfo::GetItemHandsCoverAnimLayer(eItemHands itemHands)
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

const char* PlayerInfo::GetItemType(eItemType itemType)
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

void PlayerInfo::AddIHM5ItemInfo(IHM5Item* item)
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

const char* PlayerInfo::GetInventorySlotType(ZInventorySlot::EInventorySlotType m_eSlotType)
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

const char* PlayerInfo::GetWeaponType(eWeaponType weaponType)
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

const char* PlayerInfo::GetWeaponAnimationCategory(EWeaponAnimationCategory weaponAnimationCategory)
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

const char* PlayerInfo::GetCameraMode(ECameraMode cameraMode)
{
	const char* type{};

	switch (cameraMode)
	{
	case eUnknownCamera:
		type = "Unknown Camera";
		break;
	case e3rdPersonCamera:
		type = "3rd Person Camera";
		break;
	case eShootingBalletCamera:
		type = "Shooting Ballet Camera";
		break;
	case eAnimCamera:
		type = "Anim Camera";
		break;
	case eClosetCamera:
		type = "Closet Camera";
		break;
	case eVentilatorCamera:
		type = "Ventilator Camera";
		break;
	}

	return type;
}

void PlayerInfo::AddInvetorySlotInfo(ZInventorySlot* inventorySlot)
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
		AddIHM5ItemInfo(inventorySlot->m_WeaponSet.m_rItems[i].GetRawPointer());
	}

	ZHM5WeaponSet weaponSet = inventorySlot->m_WeaponSet;

	static bool canDualWield = weaponSet.m_bCanDualWield;
	static bool dualWieldMode = weaponSet.m_bDualWieldMode;

	ImGui::Checkbox("Can Dual Wield", &canDualWield);
	ImGui::Checkbox("Dual Wield Mode", &dualWieldMode);

	weaponSet.m_bCanDualWield = canDualWield;
	weaponSet.m_bDualWieldMode = dualWieldMode;
}

void PlayerInfo::AddCurrentWeaponInfo(TEntityRef<IHM5ItemWeapon> currentWeapon, ImVec4& color)
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

	static eWeaponOperation weaponOperation;

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

	static unsigned short bulletsInMagazine = weapon->GetBulletsInMagazine();

	ImGui::InputScalar("##BulletsInMagazine", ImGuiDataType_U16, &bulletsInMagazine);

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

void PlayerInfo::AddBaseInventoryInfo(ImVec4& color, ZHitman5* player)
{
	TEntityRef<IHM5Item>* current;
	TEntityRef<IHM5Item>* end;

	ImGui::TextColored(color, "Items");

	ZHM5BaseInventory* baseInventory = player->GetBaseInventory();

	if (baseInventory->m_Items.m_pStart)
	{
		current = baseInventory->m_Items.m_pStart;
		end = baseInventory->m_Items.m_pEnd;

		while (current != end)
		{
			IHM5Item* item = current->GetRawPointer();

			AddIHM5ItemInfo(item);

			current++;
		}
	}
	else
	{
		ImGui::Text("Items are empty.");
	}

	ImGui::Separator();

	ImGui::TextColored(color, "Remote Controlled Items");

	if (baseInventory->m_RemoteControlledItems.m_pStart)
	{
		current = baseInventory->m_RemoteControlledItems.m_pStart;
		end = baseInventory->m_RemoteControlledItems.m_pEnd;

		while (current != end)
		{
			IHM5Item* item = current->GetRawPointer();

			AddIHM5ItemInfo(item);

			current++;
		}
	}
	else
	{
		ImGui::Text("Remote controlled items are empty.");
	}

	ImGui::Separator();

	ImGui::TextColored(color, "Ammo In Pocket");

	if (baseInventory->m_nAmmoInPocket)
	{
		for (int i = 0; i < IM_ARRAYSIZE(baseInventory->m_nAmmoInPocket); i++)
		{
			string label = "##Ammo" + to_string(i);

			ImGui::Text("Ammo %d", i);
			ImGui::InputScalar(label.c_str(), ImGuiDataType_U32, &baseInventory->m_nAmmoInPocket[i]);
		}
	}
	else
	{
		ImGui::Text("Ammo in pocket is empty.");
	}

	ImGui::Separator();

	ImGui::TextColored(color, "Stored Slot Data");

	ZHM5BaseInventory::SStoredSlotData storedSlotData = baseInventory->m_StoredSlot;

	if (storedSlotData.m_pStoredInventorySlot)
	{
		AddInvetorySlotInfo(storedSlotData.m_pStoredInventorySlot);
	}

	ImGui::Separator();

	static bool itemsStored = storedSlotData.m_bItemsStored;
	static bool restoreItems = storedSlotData.m_bRestoreItems;
	static bool signalWeaponSoundManager = storedSlotData.m_bSignalWeaponSoundManager;
	static bool playEquipAnimation = storedSlotData.m_bPlayEquipAnimation;

	ImGui::Checkbox("Items Stored", &itemsStored);
	ImGui::Checkbox("Restore Items", &restoreItems);
	ImGui::Checkbox("Signal Weapon Sound Manager", &signalWeaponSoundManager);
	ImGui::Checkbox("Play Equip Animation", &playEquipAnimation);

	storedSlotData.m_bItemsStored = itemsStored;
	storedSlotData.m_bItemsStored = restoreItems;
	storedSlotData.m_bSignalWeaponSoundManager = signalWeaponSoundManager;
	storedSlotData.m_bPlayEquipAnimation = playEquipAnimation;

	ImGui::Separator();
	ImGui::Text("Weapon Slots");

	if (baseInventory->m_WeaponSlots)
	{
		for (int i = 0; i < IM_ARRAYSIZE(baseInventory->m_WeaponSlots); i++)
		{
			AddInvetorySlotInfo(&baseInventory->m_WeaponSlots[i]);
			ImGui::Separator();
		}
	}

	ImGui::Separator();
	ImGui::Text("Equipped Inventory Slot");

	AddInvetorySlotInfo(baseInventory->m_pEquippedInventorySlot);

	ImGui::Separator();
	ImGui::Text("Shooting Ballet Candidate Slot");

	AddInvetorySlotInfo(baseInventory->m_pShootingBalletCandidateSlot);

	ImGui::Separator();
	ImGui::Text("Selected Slot");

	const char* inventorySlotType = GetInventorySlotType(baseInventory->m_SelectedSlot.m_eSlotType);

	ImGui::Text("Inventory Slot Type: %s", inventorySlotType);
	ImGui::Checkbox("Dual Wielded", &baseInventory->m_SelectedSlot.m_bDualWielded);

	ImGui::Separator();
	ImGui::Text("Last Equipped Slot");

	inventorySlotType = GetInventorySlotType(baseInventory->m_eLastEquippedSlot);

	ImGui::Text("Inventory Slot Type: %s", inventorySlotType);
	ImGui::Separator();
	ImGui::Text("Dual Slot When Disabled");

	inventorySlotType = GetInventorySlotType(baseInventory->m_eDualSlotWhenDisabled);

	ImGui::Text("Inventory Slot Type: %s", inventorySlotType);
	ImGui::Separator();
	ImGui::Text("Slot Bonus Weapon");

	inventorySlotType = GetInventorySlotType(baseInventory->m_eSlotBonusWeapon);

	ImGui::Text("Inventory Slot Type: %s", inventorySlotType);
}

void PlayerInfo::AddActorInvetoryInfo(TArray<TEntityRef<IHM5Item>> m_inventory)
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
		IHM5Item* item = current->GetRawPointer();

		AddIHM5ItemInfo(item);

		current++;
	}
}

void PlayerInfo::AddCrowdEntityInfo(ZCrowdEntity* crowdEntity)
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

		ImGui::InputFloat("##AllowRunRadius", &crowdEntity->m_nAllowRunRadius);

		ImGui::Checkbox("Crowd Affect NPCs", &crowdEntity->m_bCrowdAffectNPCs);
		ImGui::Checkbox("Do High LOD Separation", &crowdEntity->m_bDoHighLODSeparation);

		ImGui::Text("Separation Max LOD");
		ImGui::SameLine();

		ImGui::InputScalar("##SeparationMaxLOD", ImGuiDataType_U32, &crowdEntity->m_nSeparationMaxLOD);

		ImGui::Text("Animation Blend Max LOD");
		ImGui::SameLine();

		ImGui::InputScalar("##AnimationBlendMaxLOD", ImGuiDataType_U32, &crowdEntity->m_nAnimationBlendMaxLOD);

		ImGui::Checkbox("Smoothen Exit Flows", &crowdEntity->m_bSmoothenExitFlows);

		ImGui::Text("Paniced Actor Remove Factor");
		ImGui::SameLine();

		ImGui::InputFloat("##PanicedActorRemoveFactor", &crowdEntity->m_nPanicedActorRemoveFactor);

		ImGui::Text("Paniced Actor Exit Factor");
		ImGui::SameLine();

		ImGui::InputFloat("##PanicedActorExitFactor", &crowdEntity->m_nPanicedActorExitFactor);

		ImGui::Text("Panic Debris Factor");
		ImGui::SameLine();

		ImGui::InputFloat("##PanicDebrisFactor", &crowdEntity->m_nPanicDebrisFactor);

		ImGui::Text("Panic Debris Time");
		ImGui::SameLine();

		ImGui::InputFloat("##PanicDebrisTime", &crowdEntity->m_nPanicDebrisTime);

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

void PlayerInfo::AddCrowdActorInfo(TEntityRef<ZCrowdActor> entityRef, ImVec4& color)
{
	ZCrowdActor* crowdActor = entityRef.GetRawPointer();

	if (!crowdActor)
	{
		return;
	}

	ZCrowdActorCore* crowdActorCore = crowdActor->GetCore();

	if (crowdActorCore)
	{
		ImGui::TextColored(color, "Crowd Actor Position");

		float4 position = crowdActorCore->GetPosition();

		ImGui::Text("X");
		ImGui::SameLine();

		if (ImGui::InputFloat("##crowdActorPositionX", &position.x()))
		{
			crowdActorCore->SetPosition(position);
		}

		ImGui::SameLine();
		ImGui::Text("Y");
		ImGui::SameLine();

		if (ImGui::InputFloat("##crowdActorPositionY", &position.y()))
		{
			crowdActorCore->SetPosition(position);
		}

		ImGui::SameLine();
		ImGui::Text("Z");
		ImGui::SameLine();

		if (ImGui::InputFloat("##crowdActorPositionZ", &position.z()))
		{
			crowdActorCore->SetPosition(position);
		}

		ImGui::SameLine();
		ImGui::Text("W");
		ImGui::SameLine();

		if (ImGui::InputFloat("##crowdActorPositionW", &position.w()))
		{
			crowdActorCore->SetPosition(position);
		}

		float4 forward = crowdActorCore->GetForward();

		ImGui::Text("X");
		ImGui::SameLine();

		if (ImGui::InputFloat("##crowdActorForwardX", &forward.x()))
		{
			crowdActorCore->SetForward(position);
		}

		ImGui::SameLine();
		ImGui::Text("Y");

		if (ImGui::InputFloat("##crowdActorForwardY", &forward.y()))
		{
			crowdActorCore->SetForward(position);
		}

		ImGui::SameLine();
		ImGui::Text("Z");

		if (ImGui::InputFloat("##crowdActorForwardZ", &forward.z()))
		{
			crowdActorCore->SetForward(position);
		}

		ImGui::SameLine();
		ImGui::Text("W");

		if (ImGui::InputFloat("##crowdActorForwardW", &forward.w()))
		{
			crowdActorCore->SetForward(position);
		}

		ImGui::SameLine();
		ImGui::Text("Speed");

		ImGui::InputFloat("##crowdActorSpeed", &crowdActorCore->m_nSpeed);

		AddCrowdEntityInfo(crowdActor->GetCrowdEntity().GetRawPointer());

		if (crowdActor->m_pCurState)
		{
			if (crowdActor->m_pCurState->CollidesWithHitman(entityRef))
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

void PlayerInfo::AddGeneralInfo(ZHitman5* player)
{
	ImGui::Checkbox("Story Mode Fiber Wire", &player->m_bStoryModeFiberWire);
	ImGui::Text("Streamable Weapon ID - High: %d, Low: %d", &player->m_StreamableWeaponID.m_IDHigh,
		&player->m_StreamableWeaponID.m_IDLow);
	ImGui::Checkbox("Streamable Weapon Give", &player->m_bStreamableWeaponGive);
	ImGui::Checkbox("Streamable Weapon Dual Wield", &player->m_bStreamableWeaponDualWield);
	ImGui::Checkbox("Streamable Disguise Give", &player->m_bStreamableDisguiseGive);
	ImGui::Text("Initial Outfit ID - High: %d, Low: %d", &player->m_InitialOutfitID.m_IDHigh,
		&player->m_InitialOutfitID.m_IDLow);
	ImGui::Checkbox("Player Collision Enabled", &player->m_bPlayerCollisionEnabled);
	ImGui::Checkbox("Player NPC Collision Enabled", &player->m_bPlayerNPCCollisionEnabled);
	ImGui::Checkbox("Gravity Enabled", &player->m_bGravityEnabled);
	ImGui::Checkbox("Falling", &player->m_bFalling);

	ImGui::Text("Fall Velocity");
	ImGui::SameLine();

	//ImGui::AlignTextToFramePadding();
	//ImGui::PushItemWidth(100);

	ImGui::InputFloat("##fallVelocity", &player->m_fFallVelocity);

	AddTeleportInfo(player);
	AddOutfitInfo(player);

	ImGui::Separator();

	if (ImGui::Button("Teleport All Actors To Player"))
	{
		TeleportAllActorsToPlayer();
	}

	if (ImGui::Button("Teleport All Items To Player"))
	{
		TeleportAllItemsToPlayer();
	}

	if (ImGui::Button("Teleport All Props To Player"))
	{
		TeleportAllPropsToPlayer();
	}

	if (player->IsDead())
	{
		ImGui::Text("Is Dead: Yes");
	}
	else
	{
		ImGui::Text("Is Dead: No");
	}

	if (ImGui::Button("Holster Current Weapons"))
	{
		player->HolsterCurrentWeapons();
	}

	if (player->IsUsingKeyCardReader())
	{
		ImGui::Text("Is Using Key Card Reader: Yes");
	}
	else
	{
		ImGui::Text("Is Using Key Card Reader: No");
	}

	if (ImGui::Button("Draw Hitman In FPS Mode"))
	{
		player->DrawHitmanInFPSMode();
	}

	if (player->IsEnteringCloset())
	{
		ImGui::Text("Is Entering Closet: Yes");
	}
	else
	{
		ImGui::Text("Is Entering Closet: No");
	}

	if (player->IsInDisguise())
	{
		ImGui::Text("Is In Disguise: Yes");
	}
	else
	{
		ImGui::Text("Is In Disguise: No");
	}

	if (player->IsTakingSecurityTape())
	{
		ImGui::Text("Is Taking Security Tape: Yes");
	}
	else
	{
		ImGui::Text("Is Taking Security Tape: No");
	}

	if (player->IsFireArmEquipped())
	{
		ImGui::Text("Is Fire Arm Equipped: Yes");
	}
	else
	{
		ImGui::Text("Is Fire Arm Equipped: No");
	}

	if (player->IsPushVictimPossible())
	{
		ImGui::Text("Is Push Victim Possible: Yes");
	}
	else
	{
		ImGui::Text("Is Push Victim Possible: No");
	}

	if (player->IsPullVictimPossible())
	{
		ImGui::Text("Is Pull Victim Possible: Yes");
	}
	else
	{
		ImGui::Text("Is Pull Victim Possible: No");
	}

	static const char* btnPlayerCollisionText{};

	if (player->m_bPlayerCollisionEnabled)
	{
		btnPlayerCollisionText = "Disable Player Collision";
	}
	else
	{
		btnPlayerCollisionText = "Enable Player Collision";
	}

	if (ImGui::Button(btnPlayerCollisionText))
	{
		player->EnablePlayerCollision(!player->m_bPlayerCollisionEnabled);
	}

	static const char* btnPlayerNPCCollisionText{};

	if (player->m_bPlayerNPCCollisionEnabled)
	{
		btnPlayerNPCCollisionText = "Disable Player NPC Collision";
	}
	else
	{
		btnPlayerNPCCollisionText = "Enable Player NPC Collision";
	}

	if (ImGui::Button(btnPlayerNPCCollisionText))
	{
		player->EnablePlayerNPCCollision(!player->m_bPlayerNPCCollisionEnabled);
	}

	if (player->IsGuidesListEmpty())
	{
		ImGui::Text("Is Guides List Empty: Yes");
	}
	else
	{
		ImGui::Text("Is Guides List Empty: No");
	}

	if (player->IsInSBExecutionMode())
	{
		ImGui::Text("Is In SB Execution Mode: Yes");
	}
	else
	{
		ImGui::Text("Is In SB Execution Mode: No");
	}

	if (player->IsInSafeZoneMovement())
	{
		ImGui::Text("Is In Safe Zone Movement: Yes");
	}
	else
	{
		ImGui::Text("Is In Safe Zone Movement: No");
	}

	if (player->IsDisablingFuseBox())
	{
		ImGui::Text("Is Disabling Fuse Box: Yes");
	}
	else
	{
		ImGui::Text("Is Disabling Fuse Box: No");
	}

	if (ImGui::Button("Debug Display Bones"))
	{
		player->DebugDisplayBones();
	}

	if (player->IsInDisguiseSafeZone())
	{
		ImGui::Text("Is In Disguise Safe Zone: Yes");
	}
	else
	{
		ImGui::Text("Is In Disguise Safe Zone: No");
	}

	if (player->IsChangingClothes())
	{
		ImGui::Text("Is Changing Clothes: Yes");
	}
	else
	{
		ImGui::Text("Is Changing Clothes: No");
	}

	static const char* btnDecriminalizedShootingText{};

	if (player->m_bDecriminalizedShooting)
	{
		btnDecriminalizedShootingText = "Disable Decriminalized Shooting";
	}
	else
	{
		btnDecriminalizedShootingText = "Enable Decriminalized Shooting";
	}

	if (ImGui::Button(btnDecriminalizedShootingText))
	{
		player->SetDecriminalizedShooting(!player->m_bDecriminalizedShooting);
	}

	static const char* btnDecriminalizedWeaponsText{};

	if (player->m_bDecriminalizedWeapons)
	{
		btnDecriminalizedWeaponsText = "Disable Decriminalized Weapons";
	}
	else
	{
		btnDecriminalizedWeaponsText = "Enable Decriminalized Weapons";
	}

	if (ImGui::Button(btnDecriminalizedWeaponsText))
	{
		player->SetDecriminalizedWeapons(!player->m_bDecriminalizedWeapons);
	}

	static const char* btnm_bDecriminalizedAimingText{};

	if (player->m_bDecriminalizedAiming)
	{
		btnm_bDecriminalizedAimingText = "Disable Decriminalized Aiming";
	}
	else
	{
		btnm_bDecriminalizedAimingText = "Enable Decriminalized Aiming";
	}

	if (ImGui::Button(btnm_bDecriminalizedAimingText))
	{
		player->SetDecriminalizedAiming(!player->m_bDecriminalizedAiming);
	}

	static const char* btnDecriminalizedCloseCombatText{};

	if (player->m_bDecriminalizedCloseCombat)
	{
		btnDecriminalizedCloseCombatText = "Disable Decriminalized Close Combat";
	}
	else
	{
		btnDecriminalizedCloseCombatText = "Enable Decriminalized Close Combat";
	}

	if (ImGui::Button(btnDecriminalizedCloseCombatText))
	{
		player->SetDecriminalizedCloseCombat(!player->m_bDecriminalizedCloseCombat);
	}

	static const char* btnDecriminalizedCrossdressingText{};

	if (player->m_bDecriminalizedCrossdressing)
	{
		btnDecriminalizedCrossdressingText = "Disable Decriminalized Crossdressing";
	}
	else
	{
		btnDecriminalizedCrossdressingText = "Enable Decriminalized Crossdressing";
	}

	if (ImGui::Button(btnDecriminalizedCrossdressingText))
	{
		player->SetDecriminalizedCloseCombat(!player->m_bDecriminalizedCrossdressing);
	}

	if (player->IsWalking())
	{
		ImGui::Text("Is Walking: Yes");
	}
	else
	{
		ImGui::Text("Is Walking: No");
	}

	if (player->IsWalkingFast())
	{
		ImGui::Text("Is Walking Fast: Yes");
	}
	else
	{
		ImGui::Text("Is Walking Fast: No");
	}

	if (player->IsWalkingSlowly())
	{
		ImGui::Text("Is Walking Slowly: Yes");
	}
	else
	{
		ImGui::Text("Is Walking Slowly: No");
	}

	if (player->IsRifleEquipped())
	{
		ImGui::Text("Is Rifle Equipped: Yes");
	}
	else
	{
		ImGui::Text("Is Rifle Equipped: No");
	}

	if (player->IsItemsEnabled())
	{
		ImGui::Text("Is Items Enabled: Yes");
	}
	else
	{
		ImGui::Text("Is Items Enabled: No");
	}

	if (player->IsKnifeKilling())
	{
		ImGui::Text("Is Knife Killing: Yes");
	}
	else
	{
		ImGui::Text("Is Knife Killing: No");
	}

	if (player->IsKnifingFromBehind())
	{
		ImGui::Text("Is Knifing From Behind: Yes");
	}
	else
	{
		ImGui::Text("Is Knifing From Behind: No");
	}

	if (player->IsStrafing())
	{
		ImGui::Text("Is Strafing: Yes");
	}
	else
	{
		ImGui::Text("Is Strafing: No");
	}

	if (player->IsTakingKeycard())
	{
		ImGui::Text("Is Taking Keycard: Yes");
	}
	else
	{
		ImGui::Text("Is Taking Keycard: No");
	}

	if (player->IsDoingCoverToCoverMove())
	{
		ImGui::Text("Is Doing Cover To Cover Move: Yes");
	}
	else
	{
		ImGui::Text("Is Doing Cover To Cover Move: No");
	}

	if (player->IsSurendering())
	{
		ImGui::Text("Is Surendering: Yes");
	}
	else
	{
		ImGui::Text("Is Surendering: No");
	}

	if (player->HasFocus())
	{
		ImGui::Text("Has Focus: Yes");
	}
	else
	{
		ImGui::Text("Has Focus: No");
	}

	if (player->IsEquipFiberWireReady())
	{
		ImGui::Text("Is Equip Fiber Wire Ready: Yes");
	}
	else
	{
		ImGui::Text("Is Equip Fiber Wire Ready: No");
	}

	if (player->IsMovingOnLedge())
	{
		ImGui::Text("Is Moving On Ledge: Yes");
	}
	else
	{
		ImGui::Text("Is Moving On Ledge: No");
	}

	if (player->IsFiberWireEquipped())
	{
		ImGui::Text("Is Fiber Wire Equipped: Yes");
	}
	else
	{
		ImGui::Text("Is Fiber Wire Equipped: No");
	}

	if (player->ReadyForArrest())
	{
		ImGui::Text("Ready For Arrest: Yes");
	}
	else
	{
		ImGui::Text("Ready For Arrest: No");
	}

	if (player->IsThrowingSomething())
	{
		ImGui::Text("Is Throwing Something: Yes");
	}
	else
	{
		ImGui::Text("Is Throwing Something: No");
	}

	if (player->IsInVentilatorShaft())
	{
		ImGui::Text("Is In Ventilator Shaft: Yes");
	}
	else
	{
		ImGui::Text("Is In Ventilator Shaft: No");
	}

	if (player->IsCurrentOutfitReady())
	{
		ImGui::Text("Is Current Outfit Ready: Yes");
	}
	else
	{
		ImGui::Text("Is Current Outfit Ready: No");
	}

	if (player->IsFiberWireKillPossible())
	{
		ImGui::Text("Is Fiber Wire Kill Possible: Yes");
	}
	else
	{
		ImGui::Text("Is Fiber Wire Kill Possible: No");
	}

	if (player->IsVentilatorShaftPeekPossible())
	{
		ImGui::Text("Is Ventilator Shaft Peek Possible: Yes");
	}
	else
	{
		ImGui::Text("Is Ventilator Shaft Peek Possible: No");
	}

	if (player->IsStanding())
	{
		ImGui::Text("Is Standing: Yes");
	}
	else
	{
		ImGui::Text("Is Standing: No");
	}

	if (player->IsEnteringVent())
	{
		ImGui::Text("Is Entering Vent: Yes");
	}
	else
	{
		ImGui::Text("Is Entering Vent: No");
	}

	if (player->IsNonFireArmEquipped())
	{
		ImGui::Text("Is Non Fire Arm Equipped: Yes");
	}
	else
	{
		ImGui::Text("Is Non Fire Arm Equipped: No");
	}

	if (ImGui::Button("Reload Current Outfit"))
	{
		player->ReloadCurrentOutfit();
	}

	if (player->IsPerformingTakedown())
	{
		ImGui::Text("Is Performing Takedown: Yes");
	}
	else
	{
		ImGui::Text("Is Performing Takedown: No");
	}

	if (player->RightSideAim())
	{
		ImGui::Text("Right Side Aim: Yes");
	}
	else
	{
		ImGui::Text("Right Side Aim: No");
	}

	if (player->IsKnifingFromBehind())
	{
		ImGui::Text("Is Knifing From Behind: Yes");
	}
	else
	{
		ImGui::Text("Is Knifing From Behind: No");
	}

	if (player->IsKillingByKick())
	{
		ImGui::Text("Is Killing By Kick: Yes");
	}
	else
	{
		ImGui::Text("Is Killing By Kick: No");
	}

	if (player->IsOperatingCheckPointDoor())
	{
		ImGui::Text("Is Operating Check Point Door: Yes");
	}
	else
	{
		ImGui::Text("Is Operating Check Point Door: No");
	}

	if (player->IsMountingLedge())
	{
		ImGui::Text("Is Mounting Ledge: Yes");
	}
	else
	{
		ImGui::Text("Is Mounting Ledge: No");
	}

	if (player->IsThrowingExplosives())
	{
		ImGui::Text("Is Throwing Explosives: Yes");
	}
	else
	{
		ImGui::Text("Is Throwing Explosives: No");
	}

	if (player->IsKickVictimPossible())
	{
		ImGui::Text("Is Kick Victim Possible: Yes");
	}
	else
	{
		ImGui::Text("Is Kick Victim Possible: No");
	}

	if (player->IsInSequence())
	{
		ImGui::Text("Is In Sequence: Yes");
	}
	else
	{
		ImGui::Text("Is In Sequence: No");
	}

	if (player->IsFiberWiring())
	{
		ImGui::Text("Is Fiber Wiring: Yes");
	}
	else
	{
		ImGui::Text("Is Fiber Wiring: No");
	}

	if (player->IsShootingInCover())
	{
		ImGui::Text("Is Shooting In Cover: Yes");
	}
	else
	{
		ImGui::Text("Is Shooting In Cover: No");
	}

	if (player->IsExitingCloset())
	{
		ImGui::Text("Is Exiting Closet: Yes");
	}
	else
	{
		ImGui::Text("Is Exiting Closet: No");
	}

	if (ImGui::Button("Debug Display Status"))
	{
		player->DebugDisplayStatus();
	}

	static const char* btnGravityText{};

	if (player->m_bGravityEnabled)
	{
		btnGravityText = "Disable Gravity";
	}
	else
	{
		btnGravityText = "Enable Gravity";
	}

	if (ImGui::Button(btnGravityText))
	{
		player->EnableGravity(!player->m_bGravityEnabled);
	}

	if (player->IsInCarryCivilianMovement())
	{
		ImGui::Text("Is In Carry Civilian Movement: Yes");
	}
	else
	{
		ImGui::Text("Is In Carry Civilian Movement: No");
	}

	if (player->IsEnteringWindow())
	{
		ImGui::Text("Is Entering Window: Yes");
	}
	else
	{
		ImGui::Text("Is Entering Window: No");
	}

	if (player->IsVentilatorShaftExitPossible())
	{
		ImGui::Text("Is Ventilator Shaft Exit Possible: Yes");
	}
	else
	{
		ImGui::Text("Is Ventilator Shaft Exit Possible: No");
	}

	if (player->CanStartCloseCombat())
	{
		ImGui::Text("Can Start Close Combat: Yes");
	}
	else
	{
		ImGui::Text("Can Start Close Combat: No");
	}

	if (player->IsWalking())
	{
		ImGui::Text("Is Walking: Yes");
	}
	else
	{
		ImGui::Text("Is Walking: No");
	}

	if (player->IsInInteractiveCutsequence())
	{
		ImGui::Text("Is In Interactive Cutsequence: Yes");
	}
	else
	{
		ImGui::Text("Is In Interactive Cutsequence: No");
	}

	if (player->GetIsInInstinctMode())
	{
		ImGui::Text("Get Is In Instinct Mode: Yes");
	}
	else
	{
		ImGui::Text("Get Is In Instinct Mode: No");
	}

	if (player->IsBlindFiring())
	{
		ImGui::Text("Is Blind Firing: Yes");
	}
	else
	{
		ImGui::Text("Is Blind Firing: No");
	}

	if (player->IsDualEquipped())
	{
		ImGui::Text("Is Dual Equipped: Yes");
	}
	else
	{
		ImGui::Text("Is Dual Equipped: No");
	}

	if (player->IsExitingVent())
	{
		ImGui::Text("Is Exiting Vent: Yes");
	}
	else
	{
		ImGui::Text("Is Exiting Vent: No");
	}

	if (player->CanSkipSequence())
	{
		ImGui::Text("Can Skip Sequence: Yes");
	}
	else
	{
		ImGui::Text("Can Skip Sequence: No");
	}

	if (player->IsClosetPeekPossible())
	{
		ImGui::Text("Is Closet Peek Possible: Yes");
	}
	else
	{
		ImGui::Text("Is Closet Peek Possible: No");
	}

	if (player->IsInMinigame())
	{
		ImGui::Text("Is In Minigame: Yes");
	}
	else
	{
		ImGui::Text("Is In Minigame: No");
	}

	if (player->CanBeArrested())
	{
		ImGui::Text("Can Be Arrested: Yes");
	}
	else
	{
		ImGui::Text("Can Be Arrested: No");
	}

	if (player->IsRunning())
	{
		ImGui::Text("Is Running: Yes");
	}
	else
	{
		ImGui::Text("Is Running: No");
	}

	static const char* btnSneakingText{};

	if (player->GetSneakController()->IsSneakActivated())
	{
		btnSneakingText = "Disable Sneaking";
	}
	else
	{
		btnSneakingText = "Enable Sneaking";
	}

	if (ImGui::Button(btnSneakingText))
	{
		player->SetSneaking(!player->GetSneakController()->IsSneakActivated());
	}

	if (player->IsDoingDeadlyThrow())
	{
		ImGui::Text("Is Doing Deadly Throw: Yes");
	}
	else
	{
		ImGui::Text("Is Doing Deadly Throw: No");
	}

	if (player->IsKillingByPull())
	{
		ImGui::Text("Is Killing By Pull: Yes");
	}
	else
	{
		ImGui::Text("Is Killing By Pull: No");
	}

	if (player->IsDumpingBody())
	{
		ImGui::Text("Is Dumping Body: Yes");
	}
	else
	{
		ImGui::Text("Is Dumping Body: No");
	}

	if (player->IsInSBTagMode())
	{
		ImGui::Text("Is In SB Tag Mode: Yes");
	}
	else
	{
		ImGui::Text("Is In SB Tag Mode: No");
	}

	if (player->IsAiming())
	{
		ImGui::Text("Is Aiming: Yes");
	}
	else
	{
		ImGui::Text("Is Aiming: No");
	}

	if (player->BlockedByCrowd())
	{
		ImGui::Text("Blocked By Crowd: Yes");
	}
	else
	{
		ImGui::Text("Blocked By Crowd: No");
	}

	ImGui::Separator();

	AddBaseCharacterInfo(player);
}

void PlayerInfo::AddActorInfo(TEntityRef<ZActor> entityRef, ImGuiInputTextFlags& flags, ImVec4& color)
{
	ZActor* actor = entityRef.GetRawPointer();

	if (!actor)
	{
		return;
	}

	ImGui::TextColored(color, "General");
	ImGui::Text("");

	ImGui::TextColored(color, "CC Profile");

	ZHM5CCProfile* profile = actor->m_rCCProfile.GetRawPointer();

	if (profile)
	{
		ImGui::Text("Attacks For TakeDown");
		ImGui::SameLine();

		ImGui::InputInt("##AttacksForTakeDown", &profile->m_nAttacksForTakeDown);

		ImGui::Text("Hitman Damage");
		ImGui::SameLine();

		ImGui::InputFloat("##HitmanDamage", &profile->m_fHitmanDamage);

		ImGui::Checkbox("Allow Attacking Hitman", &profile->m_bAllowAttackingHitman);
		ImGui::Text(GetActorCCPreset(profile->m_eActorCCPreset));
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

	if (ImGui::Button("Kill Actor"))
	{
		actor->KillActor(EActorDeathType::eADT_BLOODY_MURDER, true);
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

	if (actor->HasHandGun())
	{
		ImGui::Text("Has HandGun: Yes");
	}
	else
	{
		ImGui::Text("Has Hand Gun: No");
	}

	if (actor->IsWeaponFiring())
	{
		ImGui::Text("Is Weapon Firing: Yes");
	}
	else
	{
		ImGui::Text("Is Weapon Firing: No");
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

	ImGui::Separator();

	TEntityRef<IHM5ItemWeapon> currentWeapon = actor->GetCurrentWeapon();

	AddCurrentWeaponInfo(currentWeapon, color);

	ImGui::Separator();

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

	AddLocalPositionInputs(actor, flags, color);
	AddWorldPositionInputs(actor, flags, color);

	ImGui::Separator();
}

void PlayerInfo::AddNearestActorsInfo(ImGuiInputTextFlags& flags, ImVec4& color, ZHitman5* player)
{
	ZHM5ActorControl* actorControl = player->GetActorControl();

	if (ImGui::TreeNode("Nearest Enemy"))
	{
		AddActorInfo(actorControl->GetNearestEnemy(), flags, color);
		ImGui::TreePop();
	}

	if (ImGui::TreeNode("Nearest Dead Actor"))
	{
		AddActorInfo(actorControl->GetNearestDeadActor(), flags, color);
		ImGui::TreePop();
	}

	if (ImGui::TreeNode("Nearest Outfit Actor"))
	{
		AddActorInfo(actorControl->GetNearestOutfitActor(), flags, color);
		ImGui::TreePop();
	}

	if (ImGui::TreeNode("Nearest Crowd Actor"))
	{
		AddCrowdActorInfo(actorControl->m_pNearestCrowdActor, color);
		ImGui::TreePop();
	}

	if (ImGui::TreeNode("Most Facing Near Crowd Actor"))
	{
		AddCrowdActorInfo(actorControl->GetMostFacingNearCrowdActor(), color);
		ImGui::TreePop();
	}

	if (ImGui::TreeNode("Nearest Back facing CrowdActor"))
	{
		AddCrowdActorInfo(actorControl->GetNearestBackfacingCrowdActor(), color);
		ImGui::TreePop();
	}
}

void PlayerInfo::GetTeleportLocations()
{
	ZCheckPointManager* checkPointManager = Singletons::GetCheckPointManager();
	
	if (!checkPointManager)
	{
		return;
	}

	ZCheckPointManagerEntity* checkPointManagerEntity = checkPointManager->GetCheckPointManagerEntity().GetRawPointer();
	//TEntityRef<ZCheckPointManagerEntity> entityRef = {};
	//checkPointManager->GetCheckPointManagerEntity(&entityRef);
	//ZCheckPointManagerEntity* checkPointManagerEntity = entityRef.m_pInterfaceRef;
	TArray<TEntityRef<ZCheckPointEntity>> checkPoints = checkPointManagerEntity->m_aCheckPoints;

	TEntityRef<ZCheckPointEntity>* current = checkPoints.m_pStart;

	if (!current)
	{
		return;
	}

	TEntityRef<ZCheckPointEntity>* end = checkPoints.m_pEnd;

	while (current != end)
	{
		ZCheckPointEntity* checkPointEntity = current->GetRawPointer();

		if (checkPointEntity)
		{
			TArray<TEntityRef<ZSpatialEntity>> m_aJumpPoints = checkPointEntity->m_aJumpPoints;

			TEntityRef<ZSpatialEntity>* current2 = m_aJumpPoints.m_pStart;

			if (current2)
			{
				TEntityRef<ZSpatialEntity>* end2 = m_aJumpPoints.m_pEnd;

				while (current2 != end2)
				{
					ZSpatialEntity* spatialEntity = current2->GetRawPointer();

					if (spatialEntity)
					{
						float4 localPosition = spatialEntity->GetLocalPosition();
						string location = "X: " + to_string(localPosition.x()) + " " + " Y: " + to_string(localPosition.y())
							+ " Z: " + to_string(localPosition.z());

						teleportLocations.push_back(Strdup(location.c_str()));

						current2++;
					}
				}
			}
		}

		current++;
	}
}

void PlayerInfo::AddTeleportInfo(ZHitman5* player)
{
	ImGui::Text("Teleport");
	ImGui::SameLine();

	static const char* currentItem{};

	ImGui::PushItemWidth(350);

	if (ImGui::BeginCombo("##teleport", currentItem))
	{
		for (int i = 0; i < teleportLocations.Size; i++)
		{
			bool isSelected = currentItem == teleportLocations[i];

			if (ImGui::Selectable(teleportLocations[i], isSelected))
			{
				currentItem = teleportLocations[i];
			}

			isSelected = currentItem == teleportLocations[i];

			if (isSelected)
			{
				ImGui::SetItemDefaultFocus();

				string teleportLocation = teleportLocations[i];
				float4 localPosition;

				size_t start = teleportLocation.find("X: ") + 3;
				size_t count = teleportLocation.find(" Y:") - start - 1;

				localPosition.x() = stof(teleportLocation.substr(start, count));

				start = teleportLocation.find("Y: ") + 3;
				count = teleportLocation.find(" Z:") - start - 1;

				localPosition.y() = stof(teleportLocation.substr(start, count));

				start = teleportLocation.find("Z: ") + 3;

				localPosition.z() = stof(teleportLocation.substr(start));

				player->GetSpatialEntityPtr()->SetLocalPosition(localPosition);
			}
		}

		ImGui::EndCombo();
	}

	ImGui::PopItemWidth();
}

void PlayerInfo::TeleportAllActorsToPlayer()
{
	static ZActorManager* actorManager = Singletons::GetActorManager();
	static ZLevelManager* levelManager = Singletons::GetLevelManager();
	ZHitman5* player = levelManager->GetHitman().GetRawPointer();

	if (player)
	{
		float4 playerLocalPosition = player->GetSpatialEntityPtr()->GetLocalPosition();
		float4 correct = { 0, -0.5f, 0.05f, 0 };

		for (unsigned int i = 0; i < actorManager->m_aliveActors.Size(); i++)
		{
			ZActor* actor = actorManager->m_aliveActors[i]->GetRawPointer();

			actor->GetSpatialEntityPtr()->SetLocalPosition(playerLocalPosition + correct);
		}
	}
}

void PlayerInfo::TeleportAllItemsToPlayer()
{
	static ZLevelManager* levelManager = Singletons::GetLevelManager();
	ZHitman5* player = levelManager->GetHitman().GetRawPointer();

	if (player)
	{
		float4 playerLocalPosition = player->GetSpatialEntityPtr()->GetWorldPosition();
		float4 correct = { 0, -0.5f, 0.05f, 0 };

		static ZHM5ActionManager* actionManager = Singletons::GetHM5ActionManager();
		unsigned itemsSize = actionManager->m_Actions.m_nSize;

		TSListIterator<ZHM5ActionManager::SActionTreeEntry> actionIterator = actionManager->m_Actions.Begin();

		for (unsigned i = 0; i < itemsSize; i++)
		{
			ZHM5Action* action = actionIterator.m_pCurrent->m_pNodeAction;
			EActionType actionType = action->GetActionType();

			if (actionType == EActionType::AT_PICKUP)
			{
				STypeID* typeID = TTypeIDHelper<IHM5Item>::GetTypeID();
				ZEntityType** type = reinterpret_cast<ZEntityType**>(action->m_Object.QueryInterfacePtr(typeID));
				IHM5Item* item = reinterpret_cast<IHM5Item*>(type);

				TEntityRef<ZSpatialEntity> itemSpatialEntity = item->GetSpatialEntity();
				float4 itemPosition = itemSpatialEntity.GetRawPointer()->GetWorldPosition();

				item->GetSpatialEntity()->SetWorldPosition(playerLocalPosition + correct);
			}
		}
	}
}

void PlayerInfo::TeleportAllPropsToPlayer()
{
	static ZLevelManager* levelManager = Singletons::GetLevelManager();
	ZHitman5* player = levelManager->GetHitman().GetRawPointer();

	if (player)
	{
		float4 playerLocalPosition = player->GetSpatialEntityPtr()->GetWorldPosition();
		float4 correct = { 1, -5, 0, 0 };

		static ZHM5SBTargetPropManager* targetPropManager = Singletons::GetSBTargetPropManager();
		int propsSize = targetPropManager->m_registeredProps.m_nSize;

		TBinaryTreeIterator<TEntityRef<ZSpatialEntity> const> propIterator = targetPropManager->m_registeredProps.Begin();
		TBinaryTreeNode<TEntityRef<ZSpatialEntity> const>* node;

		for (int i = 0; i < propsSize; i++)
		{
			node = &propIterator.Node();

			if (!node)
			{
				propIterator.operator++();

				continue;
			}

			node->m_data->SetWorldPosition(playerLocalPosition + correct);

			propIterator.operator++();
		}
	}
}

void PlayerInfo::GetOutfits()
{
	ZContentKitManager* contentKitManager = Singletons::GetContentKitManager();

	typedef TPair<STokenID const, TEntityRef<ZGlobalOutfitKit>> Pair;
	typedef TBinaryTreeNode<Pair> Node;

	Node* node = &contentKitManager->m_GlobalOutfitKits.Begin().Node();
	Node* endNode = &contentKitManager->m_GlobalOutfitKits.End().Node();

	ZLevelManager* levelManager = Singletons::GetLevelManager();

	if (levelManager)
	{
		ZOutfitManagerEntity* outfitManagerEntity = levelManager->GetOutfitManager().GetRawPointer();

		if (outfitManagerEntity)
		{
			while (true)
			{
				Pair p = Pair(node->Data().m_key, node->Data().m_value);
				TEntityRef<ZHM5Outfit> entityRef = outfitManagerEntity->GetOutfit(p.m_key);
				ZHM5Outfit* outfit = entityRef.GetRawPointer();

				if (outfit)
				{
					TArray<TEntityRef<ZTokenIDEntity>> outfitTokens = outfit->m_aOutfitTokens;
					TEntityRef<ZTokenIDEntity>* current = outfitTokens.m_pStart;

					if (!current)
					{
						continue;
					}

					TEntityRef<ZTokenIDEntity>* end = outfitTokens.m_pEnd;

					while (current != end)
					{
						ZTokenIDEntity* tokenIDEntity = current->GetRawPointer();
						const char* name = tokenIDEntity->m_sName.m_chars;
						STokenID tokenID = tokenIDEntity->m_TokenIDCached;

						if (tokenID.m_iValue == p.m_key.m_iValue)
						{
							outfits.insert(pair<const char*, STokenID>(name, tokenID));
							break;
						}

						current++;
					}
				}

				if (node == endNode)
				{
					break;
				}

				node = Node::GetNextNode(node);
			}
		}
	}
}

TEntityRef<ZGlobalOutfitKit> PlayerInfo::GetGlobalOutfitKit(STokenID tokenID)
{
	ZContentKitManager* contentKitManager = Singletons::GetContentKitManager();

	if (!contentKitManager)
	{
		return {};
	}

	typedef TPair<STokenID const, TEntityRef<ZGlobalOutfitKit>> Pair;
	typedef TBinaryTreeNode<Pair> Node;

	Node* node = &contentKitManager->m_GlobalOutfitKits.Begin().Node();
	Node* endNode = &contentKitManager->m_GlobalOutfitKits.End().Node();

	while (true)
	{
		Pair p = Pair(node->Data().m_key, node->Data().m_value);

		if (p.m_key.m_iValue == tokenID.m_iValue)
		{
			return p.m_value;
		}

		if (node == endNode)
		{
			break;
		}

		node = Node::GetNextNode(node);
	}

	return {};
}

void PlayerInfo::AddOutfitInfo(ZHitman5* player)
{
	ImGui::Text("Outfit");
	ImGui::SameLine();

	static const char* currentItem{};

	ImGui::PushItemWidth(350);

	if (ImGui::BeginCombo("##outfit", currentItem))
	{
		map<const char*, STokenID>::iterator it;

		for (it = outfits.begin(); it != outfits.end(); it++)
		{
			bool isSelected = currentItem == it->first;

			if (ImGui::Selectable(it->first, isSelected))
			{
				currentItem = it->first;
			}

			isSelected = currentItem == it->first;

			if (isSelected)
			{
				ImGui::SetItemDefaultFocus();

				ZLevelManager* levelManager = Singletons::GetLevelManager();

				if (levelManager)
				{
					ZOutfitManagerEntity* outfitManagerEntity = levelManager->GetOutfitManager().GetRawPointer();

					if (outfitManagerEntity)
					{
						TEntityRef<ZHM5Outfit> outfit = outfitManagerEntity->GetOutfit(it->second);
						TEntityRef<IHM5Outfit> outfit2 = {};

						outfit2.m_entityRef = outfit.m_entityRef;
						outfit2.m_pInterfaceRef = outfit.m_pInterfaceRef;

						TEntityRef<ZGlobalOutfitKit> globalOufitKit = GetGlobalOutfitKit(it->second);

						player->EquipOutfitResource(globalOufitKit.m_pInterfaceRef->m_OutfitResource1, outfit2, false, false);
					}
				}
			}
		}

		ImGui::EndCombo();
	}

	ImGui::PopItemWidth();
}

template <class T>
void PlayerInfo::AddBaseCharacterInfo(T* interfaceRef)
{
	static bool bodyColiEnabled = interfaceRef->m_bBodyColiEnabled;
	static bool bodyColiInitialized = interfaceRef->m_bBodyColiInitialized;
	static bool ignoreOnePositionChange = interfaceRef->m_bIgnoreOnePositionChange;
	static bool bBaseCharInitialized = interfaceRef->m_bBaseCharInitialized;
	static bool shootColiPrimitiveActive = interfaceRef->m_bShootColiPrimitiveActive;
	static bool shootColiSystemActive = interfaceRef->m_bShootColiSystemActive;
	static bool initialized = static_cast<ZHM5BaseCharacter*>(interfaceRef)->m_bInitialized;
	static bool initializingBaseCharacter = interfaceRef->m_bInitializingBaseCharacter;
	static bool isInCrowd = interfaceRef->m_bIsInCrowd;
	static bool isInLimitVisionAreaZone = interfaceRef->m_bIsInLimitVisionAreaZone;
	static bool isInsideLimitVisionArea = interfaceRef->m_bIsInsideLimitVisionArea;
	static bool isBlockedByLimitVisionArea = interfaceRef->m_bIsBlockedByLimitVisionArea;

	ImGui::Checkbox("Body Coli Enabled", &bodyColiEnabled);
	ImGui::Checkbox("Body Coli Initialized", &bodyColiInitialized);
	ImGui::Checkbox("Ignore One Position Change", &ignoreOnePositionChange);

	if (bBaseCharInitialized)
	{
		ImGui::Text("Base Char Initialized: Yes");
	}
	else
	{
		ImGui::Text("Base Char Initialized: No");
	}

	ImGui::Checkbox("Shoot Coli Primitive Active", &shootColiPrimitiveActive);
	ImGui::Checkbox("Shoot Coli System Active", &shootColiSystemActive);

	if (initialized)
	{
		ImGui::Text("Initialized: Yes");
	}
	else
	{
		ImGui::Text("Initialized: No");
	}

	if (initializingBaseCharacter)
	{
		ImGui::Text("Initializing Base Character: Yes");
	}
	else
	{
		ImGui::Text("Initializing Base Character: No");
	}

	if (isInCrowd)
	{
		ImGui::Text("Is In Crowd");
	}
	else
	{
		ImGui::Text("Is In Crowd");
	}

	ImGui::Checkbox("Is In Limit Vision Area Zone", &isInLimitVisionAreaZone);
	ImGui::Checkbox("Is Inside Limit Vision Area", &isInsideLimitVisionArea);
	ImGui::Checkbox("Is Blocked By Limit Vision Area", &isBlockedByLimitVisionArea);

	interfaceRef->m_bBodyColiEnabled = bodyColiEnabled;
	interfaceRef->m_bBodyColiInitialized = bodyColiInitialized;
	interfaceRef->m_bIgnoreOnePositionChange = ignoreOnePositionChange;
	interfaceRef->m_bShootColiPrimitiveActive = shootColiPrimitiveActive;
	interfaceRef->m_bShootColiSystemActive = shootColiSystemActive;
	interfaceRef->m_bIsInLimitVisionAreaZone = isInLimitVisionAreaZone;
	interfaceRef->m_bIsInsideLimitVisionArea = isInsideLimitVisionArea;
	interfaceRef->m_bIsBlockedByLimitVisionArea = isBlockedByLimitVisionArea;

	if (interfaceRef->IsHandsEmpty())
	{
		ImGui::Text("Is Hands Empty: Yes");
	}
	else
	{
		ImGui::Text("Is Hands Empty: No");
	}

	if (interfaceRef->IsHoldingWeapon())
	{
		ImGui::Text("Is Holding Weapon: Yes");
	}
	else
	{
		ImGui::Text("Is Holding Weapon: No");
	}

	if (interfaceRef->IsArmed())
	{
		ImGui::Text("Is Armed: Yes");
	}
	else
	{
		ImGui::Text("Is Armed: No");
	}

	static bool showCharacter = !interfaceRef->IsCharacterHidden();

	ImGui::Checkbox("ShowCharacter", &showCharacter);

	if (showCharacter == interfaceRef->IsCharacterHidden())
	{
		interfaceRef->ShowCharacter(showCharacter);
	}

	if (interfaceRef->IsCharacterHidden())
	{
		ImGui::Text("Is Character Hidden: Yes");
	}
	else
	{
		ImGui::Text("Is Character Hidden: No");
	}

	if (interfaceRef->IsPoweredRagdoll())
	{
		ImGui::Text("Is Powered Ragdoll: Yes");
	}
	else
	{
		ImGui::Text("Is Powered Ragdoll: No");
	}

	if (interfaceRef->IsPoweredRagdollStopping())
	{
		ImGui::Text("Is Powered Ragdoll Stopping: Yes");
	}
	else
	{
		ImGui::Text("Is Powered Ragdoll Stopping: No");
	}

	if (interfaceRef->IsRagdollGrabbed())
	{
		ImGui::Text("Is Ragdoll Grabbed: Yes");
	}
	else
	{
		ImGui::Text("Is Ragdoll Grabbed: No");
	}

	if (interfaceRef->IsRagdollControlled())
	{
		ImGui::Text("Is Ragdoll Controlled: Yes");
	}
	else
	{
		ImGui::Text("Is Ragdoll Controlled: No");
	}

	if (interfaceRef->IsWearingOutfit())
	{
		ImGui::Text("Is Wearing Outfit: Yes");
	}
	else
	{
		ImGui::Text("Is Wearing Outfit: No");
	}

	if (interfaceRef->IsDead())
	{
		ImGui::Text("Is Dead: Yes");
	}
	else
	{
		ImGui::Text("Is Dead: No");
	}

	if (interfaceRef->CanBeDragged())
	{
		ImGui::Text("Can Be Dragged: Yes");
	}
	else
	{
		ImGui::Text("Can Be Dragged: No");
	}

	if (ImGui::Button("Reset Character"))
	{
		interfaceRef->ResetCharacter();
	}
}

void PlayerInfo::DrawWindow(bool* showPlayerInfo)
{
	ImGui::SetNextWindowSize(ImVec2(640, 480), ImGuiCond_FirstUseEver);

	if (!ImGui::Begin("Player Info", showPlayerInfo))
	{
		ImGui::End();

		return;
	}

	if (teleportLocations.Size == 0)
	{
		GetTeleportLocations();
	}

	if (outfits.size() == 0)
	{
		GetOutfits();
	}

	static ZLevelManager* levelManager = Singletons::GetLevelManager();
	ZHitman5* player = levelManager->GetHitman().GetRawPointer();

	if (player)
	{
		ImGuiInputTextFlags flags = ImGuiInputTextFlags_EnterReturnsTrue;

		ImGui::AlignTextToFramePadding();
		ImGui::PushItemWidth(100);

		if (ImGui::CollapsingHeader("General"))
		{
			AddGeneralInfo(player);
		}

		ImVec4 color = ImVec4(1.0f, 0.8f, 0.6f, 1.0f);

		if (ImGui::CollapsingHeader("Movement"))
		{
			ImGui::Text("Base Movement Type: %s", GetMovementType(player));
			ImGui::Text("Game Input Flag: %s", GetGameInputFlag(player));
		}

		if (ImGui::CollapsingHeader("Health"))
		{
			ImGui::Checkbox("Refill Health", &player->m_pHealth->m_bRefillHealth);
			ImGui::Checkbox("Drain Health", &player->m_pHealth->m_bDrainHealth);

			ImGui::Text("Hit Points");
			ImGui::SameLine();

			ImGui::InputFloat("##hitPoints", &player->m_pHealth->m_fHitPoints);

			ImGui::Text("Max Hit Points");
			ImGui::SameLine();

			ImGui::InputFloat("##maxHitPoints", &player->m_pHealth->m_fMaxHitPoints);

			ImGui::Text("Sound State Hit Points");
			ImGui::SameLine();

			ImGui::InputFloat("##soundStateHitpoints", &player->m_pHealth->m_fSoundStateHitpoints);
		}

		if (ImGui::CollapsingHeader("Max Ammo"))
		{
			ImGui::Text("Max Gun Ammo");
			ImGui::SameLine();
			ImGui::InputInt("##MaxGunAmmo", &player->m_nMaxGunAmmo);

			ImGui::Text("Max Revolver Ammo");
			ImGui::SameLine();
			ImGui::InputInt("##MaxRevolverAmmo", &player->m_nMaxRevolverAmmo);

			ImGui::Text("Max SMG Ammo");
			ImGui::SameLine();
			ImGui::InputInt("##MaxSMGAmmo", &player->m_nMaxSMGAmmo);

			ImGui::Text("Max Rifle Ammo");
			ImGui::SameLine();
			ImGui::InputInt("##MaxRifleAmmo", &player->m_nMaxRifleAmmo);

			ImGui::Text("Max Sniper Ammo");
			ImGui::SameLine();
			ImGui::InputInt("##MaxSniperAmmo", &player->m_nMaxSniperAmmo);

			ImGui::Text("Max MG Ammo");
			ImGui::SameLine();
			ImGui::InputInt("##MaxMGAmmo", &player->m_nMaxMGAmmo);

			ImGui::Text("Max RPG Ammo");
			ImGui::SameLine();
			ImGui::InputInt("##MaxRPGAmmo", &player->m_nMaxRPGAmmo);

			ImGui::Text("Max Shotgun Ammo");
			ImGui::SameLine();
			ImGui::InputInt("##MaxShotgunAmmo", &player->m_nMaxShotgunAmmo);
		}

		if (ImGui::CollapsingHeader("Position"))
		{
			AddLocalPositionInputs(player, flags, color);
			AddWorldPositionInputs(player, flags, color);
		}

		if (ImGui::CollapsingHeader("Base Inventory Info"))
		{
			AddBaseInventoryInfo(color, player);
		}

		if (ImGui::CollapsingHeader("Nearest Actors Info"))
		{
			if (player->GetActorControl()->m_NearEnemyChecks.Size() > 0)
			{
				if (ImGui::Button("Show Nearest Actors List"))
				{
					showNearestActorsInfo = true;
				}

				if (showNearestActorsInfo)
				{
					nearestActorsInfo.DrawWindow(&showNearestActorsInfo);
				}

				AddNearestActorsInfo(flags, color, player);
			}
			else
			{
				showNearestActorsInfo = false;
				ImGui::Text("No nearest actors found.");
			}
		}

		if (ImGui::CollapsingHeader("Camera"))
		{
			ZHM5CameraBaseFunc* currentCamera = player->GetMainCamera()->GetCurrentCamera();
			ECameraMode cameraMode = currentCamera->GetCameraType();

			ImGui::Text("Camera Mode: %s", GetCameraMode(cameraMode));

			ImGui::Text("Angle Yaw");
			ImGui::SameLine();
			ImGui::InputFloat("##AngleYaw", &currentCamera->m_fAngleYaw);

			ImGui::Text("Angle Pitch");
			ImGui::SameLine();
			ImGui::InputFloat("##AnglePitch", &currentCamera->m_fAnglePitch);

			ImGui::Text("FOV");
			ImGui::SameLine();

			static float fieldOfView = currentCamera->m_fFOV;

			if (ImGui::InputFloat("##FOV", &fieldOfView, 0, 0, "%.3f", flags))
			{
				currentCamera->SetCameraFOV(fieldOfView);
			}
		}

		ImGui::PopItemWidth();
	}
	else
	{
		ImGui::Text("Player isn't created yet.");
	}

	ImGui::End();
}

char* PlayerInfo::Strdup(const char* s)
{
	IM_ASSERT(s);
	size_t length = strlen(s) + 1;
	void* buffer = malloc(length);
	IM_ASSERT(buffer);

	return (char*)memcpy(buffer, (const void*)s, length);
}
