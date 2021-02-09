#include "HUDInfo.h"

static ImVector<__int16> textIDList;

void HUDInfo::DrawWindow(bool* showHUDInfo)
{
	ImGui::SetNextWindowSize(ImVec2(640, 480), ImGuiCond_FirstUseEver);

	if (!ImGui::Begin("HUD Info", showHUDInfo))
	{
		ImGui::End();
		return;
	}

	ZHUDManager* hudManager = reinterpret_cast<ZHUDManager*>(Globals::g_pHUDManagerSingleton);

	if (hudManager)
	{
		if (hudManager->m_bPCRetail)
		{
			ImGui::Text("PC Retail: Yes");
		}
		else
		{
			ImGui::Text("PC Retail: No");
		}

		ImGui::Text("Cross Hair Depth");
		ImGui::SameLine();

		ImGui::InputFloat("##CrossHairDepth", &hudManager->m_fCrossHairDepth);

		ImGui::Checkbox("HUD Visible On Game Start", &hudManager->m_bHUDVisibleOnGameStart);
		ImGui::Checkbox("Display HUD", &hudManager->m_bDisplayHUD);
		ImGui::Checkbox("Cutscene Should Stop", &hudManager->m_bCutsceneShouldStop);

		ImGui::Text("Next Level Path: %s", hudManager->m_sNextLevelPath.m_chars);

		if (hudManager->m_bDisguiseChanged)
		{
			ImGui::Text("Disguise Changed: Yes");
		}
		else
		{
			ImGui::Text("Disguise Changed: No");
		}

		ECrossHairType scaleformCrossHairType = hudManager->m_eScaleformCrossHair;
		ECrossHairType crossHairType = hudManager->m_eCrossHair;

		ImGui::Text("Scaleform Cross Hair Type: %s", GetCrossHairType(scaleformCrossHairType));
		ImGui::Text("Cross Hair Type: %s", GetCrossHairType(crossHairType));

		ImGui::Text("Cross Hair Scale");
		ImGui::SameLine();

		ImGui::InputFloat("##CrossHairScale", &hudManager->m_fCrossHairScale);

		ImGui::Text("Health Percentage");
		ImGui::SameLine();
		ImGui::InputFloat("##HealthPercentage", &hudManager->m_fHealthPercentage);

		ImGui::Text("Scaleform Health Percentage");
		ImGui::SameLine();
		ImGui::InputFloat("##ScaleformHealthPercentage", &hudManager->m_fScaleformHealthPercentage);

		ImGui::Text("Boss Health");
		ImGui::SameLine();
		ImGui::InputFloat("##BossHealth", &hudManager->m_fBossHealth);

		ImGui::Text("Boss Timer");
		ImGui::SameLine();
		ImGui::InputFloat("##BossTimer", &hudManager->m_fBossTimer);

		ImGui::Separator();

		ImGui::Text("New Weapon Status");
		ImGui::Text("");

		AddWeaponStatusInfo(&hudManager->m_NewWeaponStatus, 0);

		ImGui::Separator();

		ImGui::Text("Weapon Status");
		ImGui::Text("");

		AddWeaponStatusInfo(&hudManager->m_WeaponStatus, 1);

		ImGui::Separator();

		if (hudManager->m_bPlayingReloadAnimation)
		{
			ImGui::Text("Playing Reload Animation: Yes");
		}
		else
		{
			ImGui::Text("Playing Reload Animation: No");
		}

		ImGui::Checkbox("Current Ammo Dirty Flag", &hudManager->m_bCurrentAmmoDirtyFlag);
		ImGui::Text("Current Ammo Name: %s", hudManager->m_sCurrentAmmoName.m_chars);

		ImGui::Text("Current Ammo Picked");
		ImGui::SameLine();
		ImGui::InputScalar("##CurrentAmmoPicked", ImGuiDataType_S16, &hudManager->m_iCurrentAmmoPicked);

		if (hudManager->m_bTrespassing)
		{
			ImGui::Text("Trespassing: Yes");
		}
		else
		{
			ImGui::Text("Trespassing: No");
		}

		if (ImGui::Button("Clear Disguise"))
		{
			hudManager->ClearDisguise();
		}

		ImGui::Separator();

		static bool showCrossHair;

		if (ImGui::Checkbox("Show CrossHair", &showCrossHair))
		{
			if (showCrossHair)
			{
				hudManager->ShowCrossHair();
			}
			else
			{
				hudManager->HideCrossHair();
			}
		}

		static bool showTrespassingIcon;

		if (ImGui::Checkbox("Show Trespassing Icon", &showTrespassingIcon))
		{
			hudManager->ShowTrespassingIcon(showTrespassingIcon);
		}

		static bool showThreatRadar;

		if (ImGui::Checkbox("Show Threat Radar", &showThreatRadar))
		{
			hudManager->ShowThreatRadar(showThreatRadar);
		}

		if (ImGui::Button("Update Health"))
		{
			hudManager->UpdateHealth();
		}

		if (hudManager->HitmanExists())
		{
			ImGui::Text("Hitman Exists: Yes");
		}
		else
		{
			ImGui::Text("Hitman Exists: No");
		}

		static bool setDialogActive;

		if (ImGui::Checkbox("Set Dialog Active", &setDialogActive))
		{
			hudManager->SetDialogActive(setDialogActive);
		}

		ImGui::Separator();

		DisplayText(hudManager);

		//DisplayCustomButton(EControllerButton nButton, ZString * sButtonText, bool bShow);
	}

	ImGui::End();
}

void HUDInfo::DisplayText(ZHUDManager* hudManager)
{
	ImGui::Text("Display Text");
	ImGui::Text("");

	ImGui::Text("Text:");
	ImGui::SameLine();
	ImGui::InputText("##Text", inputBuffer, IM_ARRAYSIZE(inputBuffer));
	ImGui::Text("");

	ImGui::PushItemWidth(200);

	static int offsetX = 0, offsetY = 0;

	ImGui::Text("Offset X:");
	ImGui::SameLine();
	ImGui::InputInt("##OffsetX", &offsetX);

	ImGui::Text("Offset Y:");
	ImGui::SameLine();
	ImGui::InputInt("##OffsetY", &offsetY);
	ImGui::Text("");

	static const char* currentScreenAnchorItem{};
	const char* screenAnchorItems[] = { "Top Left", "Top Center", "Top Right", "Middle Left", "Middle Center", "Middle Right", "Bottom Left",
		"Bottom Center", "Bottom Right" };
	static EScreenAnchor screenAnchor;

	ImGui::Text("Screen Anchor:");
	ImGui::SameLine();

	if (ImGui::BeginCombo("##ScreenAnchor", currentScreenAnchorItem))
	{
		for (int i = 0; i < IM_ARRAYSIZE(screenAnchorItems); i++)
		{
			bool isSelected = currentScreenAnchorItem == screenAnchorItems[i];

			if (ImGui::Selectable(screenAnchorItems[i], isSelected))
			{
				currentScreenAnchorItem = screenAnchorItems[i];
			}

			isSelected = currentScreenAnchorItem == screenAnchorItems[i];

			if (isSelected)
			{
				ImGui::SetItemDefaultFocus();

				string selectedItem = currentScreenAnchorItem;

				if (selectedItem == "Top Left")
				{
					screenAnchor = EScreenAnchor::SCREEN_ANCHOR_TOP_LEFT;
				}
				else if (selectedItem == "Top Center")
				{
					screenAnchor = EScreenAnchor::SCREEN_ANCHOR_TOP_CENTER;
				}
				else if (selectedItem == "Top Right")
				{
					screenAnchor = EScreenAnchor::SCREEN_ANCHOR_TOP_RIGHT;
				}
				else if (selectedItem == "Middle Left")
				{
					screenAnchor = EScreenAnchor::SCREEN_ANCHOR_MIDDLE_LEFT;
				}
				else if (selectedItem == "Middle Center")
				{
					screenAnchor = EScreenAnchor::SCREEN_ANCHOR_MIDDLE_CENTER;
				}
				else if (selectedItem == "Middle Right")
				{
					screenAnchor = EScreenAnchor::SCREEN_ANCHOR_MIDDLE_RIGHT;
				}
				else if (selectedItem == "Bottom Left")
				{
					screenAnchor = EScreenAnchor::SCREEN_ANCHOR_BOTTOM_LEFT;
				}
				else if (selectedItem == "Bottom Center")
				{
					screenAnchor = EScreenAnchor::SCREEN_ANCHOR_BOTTOM_CENTER;
				}
				else if (selectedItem == "Bottom Right")
				{
					screenAnchor = EScreenAnchor::SCREEN_ANCHOR_BOTTOM_RIGHT;
				}
			}
		}

		ImGui::EndCombo();
	}

	static float size = 18;

	ImGui::Text("Text Size:");
	ImGui::SameLine();
	ImGui::InputFloat("##TextSize", &size);
	ImGui::Text("");

	ImGui::Text("Color:");
	ImGui::SameLine();

	static ImVec4 color = ImVec4(1.0f, 0.8f, 0.6f, 1.0f);
	//static float color[4];
	//static ImU32 color = ImColor(100, 10, 10, 1);
	ImGui::ColorEdit4("##Color", reinterpret_cast<float*>(&color), ImGuiColorEditFlags_InputRGB);
	ImGui::Text("");

	static const char* currentTextAlignmentItem{};
	const char* textAlignmentItems[] = { "Left", "Center", "Right" };
	static ETextAlignment textAlignment;

	ImGui::Text("Text Alignment:");
	ImGui::SameLine();

	if (ImGui::BeginCombo("##TextAlignment", currentTextAlignmentItem))
	{
		for (int i = 0; i < IM_ARRAYSIZE(textAlignmentItems); i++)
		{
			bool isSelected = currentTextAlignmentItem == textAlignmentItems[i];

			if (ImGui::Selectable(textAlignmentItems[i], isSelected))
			{
				currentTextAlignmentItem = textAlignmentItems[i];
			}

			isSelected = currentTextAlignmentItem == textAlignmentItems[i];

			if (isSelected)
			{
				ImGui::SetItemDefaultFocus();

				string selectedItem = currentTextAlignmentItem;

				if (selectedItem == "Left")
				{
					textAlignment = ETextAlignment::TEXT_ALIGN_LEFT;
				}
				else if (selectedItem == "Center")
				{
					textAlignment = ETextAlignment::TEXT_ALIGN_CENTER;
				}
				else if (selectedItem == "Right")
				{
					textAlignment = ETextAlignment::TEXT_ALIGN_RIGHT;
				}
			}
		}

		ImGui::EndCombo();
	}

	ImGui::PopItemWidth();
	ImGui::Text("");

	static __int16 textID = -1;

	if (ImGui::Button("Display Text"))
	{
		ZString text = {};
		text.m_chars = inputBuffer;
		text.m_length = IM_ARRAYSIZE(inputBuffer);

		ImU32 color2 = ImGui::ColorConvertFloat4ToU32(color);

		textID = hudManager->AddText(&text, offsetX, offsetY, screenAnchor, size, color2, textAlignment, 0, false);
		textIDList.push_back(textID);
	}

	if (textIDList.size() > 0)
	{
		if (ImGui::Button("Remove Text"))
		{
			__int16 id = textIDList.back();
			hudManager->RemoveText(id);

			textIDList.pop_back();
		}
	}
}

const char* HUDInfo::GetCrossHairType(ECrossHairType crossHairType)
{
	const char* type{};

	switch (crossHairType)
	{
	case CROSSHAIR_NONE:
		type = "None";
		break;
	case CROSSHAIR_PISTOL:
		type = "Pistol";
		break;
	case CROSSHAIR_REVOLVER:
		type = "Revolver";
		break;
	case CROSSHAIR_SMG:
		type = "SMG";
		break;
	case CROSSHAIR_RIFLE:
		type = "Rifle";
		break;
	case CROSSHAIR_SHOTGUN:
		type = "Shotgun";
		break;
	case CROSSHAIR_SNIPER:
		type = "Sniper";
		break;
	case CROSSHAIR_HARDBALLER:
		type = "Hardballer";
		break;
	case CROSSHAIR_UNAIMED:
		type = "Unaimed";
		break;
	}

	return type;
}

const char* HUDInfo::GetItemType(eItemType itemType)
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

const char* HUDInfo::GetOperationMode(EOperationMode operationMode)
{
	const char* type{};

	switch (operationMode)
	{
	case WEAPON_MODE_SEMI_AUTO:
		type = "Semi Auto";
		break;
	case WEAPON_MODE_FULL_AUTO:
		type = "Full Auto";
		break;
	case WEAPON_MODE_SILENCED_SEMI_AUTO:
		type = "Silenced Semi Auto";
		break;
	case WEAPON_MODE_BURST_FIRE:
		type = "Burst Fire";
		break;
	case WEAPON_MODE_CLOSECOMBAT:
		type = "Close Combat";
		break;
	case WEAPON_MODE_INVALID:
		type = "Invalid";
		break;
	}

	return type;
}

void HUDInfo::AddWeaponStatusInfo(SWeaponStatus* weaponStatus, int index)
{
	eItemType rightHandItemType = weaponStatus->eRightHandItemType;

	ImGui::Text("Right Hand Item Type: %s", GetItemType(rightHandItemType));

	static string label1 = "##LoadedAmmoLeft" + to_string(index);

	ImGui::Text("Loaded Ammo Left");
	ImGui::SameLine();
	ImGui::InputScalar(label1.c_str(), ImGuiDataType_S16, &weaponStatus->nLoadedAmmoLeft);

	static string label2 = "##LoadedAmmoRight" + to_string(index);

	ImGui::Text("Loaded Ammo Right");
	ImGui::SameLine();
	ImGui::InputScalar(label2.c_str(), ImGuiDataType_S16, &weaponStatus->nLoadedAmmoRight);

	static string label3 = "##ReserveAmmo" + to_string(index);

	ImGui::Text("Reserve Ammo");
	ImGui::SameLine();
	ImGui::InputScalar(label3.c_str(), ImGuiDataType_S16, &weaponStatus->nReserveAmmo);

	static string label4 = "##ClipSize" + to_string(index);

	ImGui::Text("Clip Size");
	ImGui::SameLine();
	ImGui::InputScalar(label4.c_str(), ImGuiDataType_S16, &weaponStatus->nClipSize);

	EOperationMode operationMode = weaponStatus->eOperationMode;

	ImGui::Text("Operation Mode: %s", GetOperationMode(operationMode));

	ImGui::Checkbox("Holstered", &weaponStatus->bHolstered);
	ImGui::Checkbox("DualWield", &weaponStatus->bDualWield);
	ImGui::Checkbox("Switched Weapon", &weaponStatus->bSwitchedWeapon);
}
