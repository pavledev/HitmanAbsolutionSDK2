#include "GameStatsInfo.h"

void GameStatsInfo::DrawWindow(bool* showHUDInfo)
{
	ImGui::SetNextWindowSize(ImVec2(640, 480), ImGuiCond_FirstUseEver);

	if (!ImGui::Begin("Game Stats Info", showHUDInfo))
	{
		ImGui::End();
		return;
	}

	static ZGameStatsManager* gameStatsManager = reinterpret_cast<ZGameStatsManager*>(Globals::g_pGameStatsManagerSingleton);

	ImGui::Text("Picked Up Disguise On CP: %s", FormatArrayData(gameStatsManager->m_bPickedUpDisguiseOnCP).c_str());

	TArray<int> killsByBodyPart = gameStatsManager->m_GameStats.m_aKillsByBodyPart;
	TArray<int> killsByWeapon = gameStatsManager->m_GameStats.m_aKillsByWeapon;
	TArray<int> killsBySituation = gameStatsManager->m_GameStats.m_aKillsBySituation;
	TArray<int> killsByVictim = gameStatsManager->m_GameStats.m_aKillsByVictim;
	TArray<int> actorDamageByBodyPart = gameStatsManager->m_GameStats.m_aActorDamageByBodyPart;
	TArray<int> actorDamageByWeapon = gameStatsManager->m_GameStats.m_aActorDamageByWeapon;
	TArray<int> stealthSituations = gameStatsManager->m_GameStats.m_aStealthSituations;
	TArray<int> explodingProps = gameStatsManager->m_GameStats.m_aExplodingProps;

	ImGui::Text("Kills By Body Part: %s", FormatArrayData(killsByBodyPart).c_str());
	ImGui::Text("Kills By Weapon: %s", FormatArrayData(killsByWeapon).c_str());
	ImGui::Text("Kills By Situation: %s", FormatArrayData(killsBySituation).c_str());
	ImGui::Text("Kills By Victim: %s", FormatArrayData(killsByVictim).c_str());
	ImGui::Text("Actor Damage By Body Part: %s", FormatArrayData(actorDamageByBodyPart).c_str());
	ImGui::Text("Actor Damage By Weapon: %s", FormatArrayData(actorDamageByWeapon).c_str());
	ImGui::Text("Stealth Situations: %s", FormatArrayData(stealthSituations).c_str());
	ImGui::Text("Exploding Props: %s", FormatArrayData(explodingProps).c_str());

	ImGui::Text("Total Shots Fired CP: %u", gameStatsManager->m_nTotalShotsFiredCP);
	ImGui::Text("Shots That Hit CP: %u", gameStatsManager->m_nShotsThatHitCP);

	string totalShotsFiredByWeaponClass = FormatArrayData(gameStatsManager->m_nTotalShotsFiredByWeaponClass);
	string shotsThatHitByWeaponClass = FormatArrayData(gameStatsManager->m_nShotsThatHitByWeaponClass);
	string totalShotsFiredByWeaponClassPS = FormatArrayData(gameStatsManager->m_nTotalShotsFiredByWeaponClassPS);
	string shotsThatHitByWeaponClassPS = FormatArrayData(gameStatsManager->m_nShotsThatHitByWeaponClassPS);

	ImGui::Text("Total Shots FiredBy Weapon Class: %u", totalShotsFiredByWeaponClass.c_str());
	ImGui::Text("Shots That Hit By Weapon Class: %u", shotsThatHitByWeaponClass.c_str());
	ImGui::Text("Shots That Hit CP: %u", totalShotsFiredByWeaponClassPS.c_str());
	ImGui::Text("Shots That Hit CP: %u", shotsThatHitByWeaponClassPS.c_str());

	ImGui::Text("Checkpoint Kills: %d", gameStatsManager->m_nCheckpointKills);
	ImGui::Text("Checkpoint Crowd Kills: %d", gameStatsManager->m_nCheckpointCrowdKills);
	ImGui::Text("Checkpoint Crowd Explosion Kills: %d", gameStatsManager->m_nCheckpointCrowdExplosionKills);

	ELevelIndex previousLevel = gameStatsManager->m_nPrevLevel;
	ImGui::Text("Previous Level: %s", GetLevel(previousLevel));

	ImGui::Text("Previous Checkpoint: %d", gameStatsManager->m_nPrevCheckpoint);
	ImGui::Text("CP Replay Count: %d", gameStatsManager->m_nCPReplayCount);
	ImGui::Text("Level Replay Count: %d", gameStatsManager->m_nLevelReplayCount);
	ImGui::Text("Notebook Opened Count: %d", gameStatsManager->m_nNotebookOpenedCount);

	if (gameStatsManager->m_bTrackingPerfectHit)
	{
		ImGui::Text("Tracking Perfect Hit: Yes");
	}
	else
	{
		ImGui::Text("Tracking Perfect Hit: No");
	}

	if (gameStatsManager->m_bHasPerfectHitRatio)
	{
		ImGui::Text("Has Perfect Hit Ratio: Yes");
	}
	else
	{
		ImGui::Text("Has Perfect Hit Ratio: No");
	}

	if (gameStatsManager->m_bAnyShotsFired)
	{
		ImGui::Text("Any Shots Fired: Yes");
	}
	else
	{
		ImGui::Text("Any Shots Fired: No");
	}

	if (gameStatsManager->m_bAnyDisguisesTaken)
	{
		ImGui::Text("Any Disguises Taken: Yes");
	}
	else
	{
		ImGui::Text("Any Disguises Taken: No");
	}

	if (gameStatsManager->m_bHitmanRunning)
	{
		ImGui::Text("Hitman Running: Yes");
	}
	else
	{
		ImGui::Text("Hitman Running: No");
	}

	if (gameStatsManager->m_bHitmanCrouching)
	{
		ImGui::Text("Hitman Crouching: Yes");
	}
	else
	{
		ImGui::Text("Hitman Crouching: No");
	}

	if (gameStatsManager->m_bSpottedOnCheckpoint)
	{
		ImGui::Text("Spotted On Checkpoint: Yes");
	}
	else
	{
		ImGui::Text("Spotted On Checkpoint: No");
	}

	if (gameStatsManager->m_bDebugKill)
	{
		ImGui::Text("Debug Kill: Yes");
	}
	else
	{
		ImGui::Text("Debug Kill: No");
	}

	if (gameStatsManager->m_bSeenDraggingBody)
	{
		ImGui::Text("Seen Dragging Body: Yes");
	}
	else
	{
		ImGui::Text("Seen Dragging Body: No");
	}

	if (gameStatsManager->m_bCaughtTrespassing)
	{
		ImGui::Text("Caught Trespassing: Yes");
	}
	else
	{
		ImGui::Text("Caught Trespassing: No");
	}

	ImGui::Separator();
	ImGui::Text("GameState");
	ImGui::Text("");

	static NearestActorsInfo nearestActorsInfo;
	ImGuiInputTextFlags flags = ImGuiInputTextFlags_EnterReturnsTrue;
	ImVec4 color = ImVec4(1.0f, 0.8f, 0.6f, 1.0f);

	AddAIGameStateInfo(&gameStatsManager->m_GameState, flags, color, nearestActorsInfo);

	ImGui::Separator();
	ImGui::Text("Old Game State");
	ImGui::Text("");

	AddAIGameStateInfo(&gameStatsManager->m_OldGameState, flags, color, nearestActorsInfo);

	ImGui::End();
}

string GameStatsInfo::FormatArrayData(TArray<int> array)
{
	string result = "";

	for (int i = 0; i < array.Size(); i++)
	{
		result += to_string(*array[i]) + ", ";
	}

	result.erase(result.size() - 2, 2);
	
	return result;
}

string GameStatsInfo::FormatArrayData(unsigned int array[])
{
	string result = "";

	for (int i = 0; i < IM_ARRAYSIZE(array); i++)
	{
		result += to_string(array[i]) + ", ";
	}

	result.erase(result.size() - 2, 2);

	return result;
}

string GameStatsInfo::FormatArrayData(bool array[])
{
	string result = "";

	for (int i = 0; i < IM_ARRAYSIZE(array); i++)
	{
		if (array[i])
		{
			result += "Yes, ";
		}
		else
		{
			result += "No, ";
		}
	}

	result.erase(result.size() - 2, 2);

	return result;
}

const char* GameStatsInfo::GetLevel(ELevelIndex levelIndex)
{
	const char* type{};

	switch (levelIndex)
	{
	case LEVELINDEX_INVALID:
		type = "Invalid";
		break;
	case eL01:
		type = "L01";
		break;
	case eL01B:
		type = "L01 B";
		break;
	case eL02B:
		type = "L02 B";
		break;
	case eL02C:
		type = "L02 C";
		break;
	case eL02D:
		type = "L02 D";
		break;
	case eL02E:
		type = "L02 E";
		break;
	case eL03:
		type = "L03";
		break;
	case eL04B:
		type = "L04 B";
		break;
	case eL04C:
		type = "L04 C";
		break;
	case eL04D:
		type = "L04 D";
		break;
	case eL04E:
		type = "L04 E";
		break;
	case eL05A:
		type = "L05 A";
		break;
	case eL05B:
		type = "L05 B";
		break;
	case eL05C:
		type = "L05 C";
		break;
	case eL06A:
		type = "L06 A";
		break;
	case eL06B:
		type = "L06 B";
		break;
	case eL06C:
		type = "L06 C";
		break;
	case eL06D:
		type = "L06 D";
		break;
	case eL07A:
		type = "L07 A";
		break;
	case eL07D:
		type = "L07 D";
		break;
	case eL07E:
		type = "L07 E";
		break;
	case eL08A:
		type = "L08 A";
		break;
	case eL08B:
		type = "L08 B";
		break;
	case eL08C:
		type = "L08 C";
		break;
	case eL09:
		type = "L09";
		break;
	case eL10:
		type = "L10";
		break;
	case eLS01:
		type = "L S01";
		break;
	case LEVELINDEX_GLOBAL:
		type = "Global";
		break;
	case eLS_TownOfNoHope:
		type = "Town Of No Hope";
		break;
	case eLDLC01:
		type = "DLC 01";
		break;
	case eLDLC02:
		type = "DLC 02";
		break;
	case eLDLC03:
		type = "DLC 03";
		break;
	case eLDLC04:
		type = "DLC 04";
		break;
	case eLDLC05:
		type = "DLC 05";
		break;
	case eLDLC06:
		type = "DLC 06";
		break;
	case eLDLC07:
		type = "DLC 07";
		break;
	case eLDLC08:
		type = "DLC 08";
		break;
	case eLDLC09:
		type = "DLC 09";
		break;
	case eLDLC10:
		type = "DLC 10";
		break;
	case eLDLC11:
		type = "DLC 11";
		break;
	case eLDLC12:
		type = "DLC 12";
		break;
	case eLDLC13:
		type = "DLC 13";
		break;
	case eLDLC14:
		type = "DLC 14";
		break;
	case eLDLC15:
		type = "DLC 15";
		break;
	case eLDLC16:
		type = "DLC 16";
		break;
	case eLDLC17:
		type = "DLC 17";
		break;
	case eLDLC18:
		type = "DLC 18";
		break;
	case eLDLC19:
		type = "DLC 19";
		break;
	case eLDLC20:
		type = "DLC 20";
		break;
	case LEVELINDEX_COUNT:
		type = "Count";
		break;
	}
	
	return type;
}

void GameStatsInfo::AddAIGameStateInfo(ZAIGameState* gameState, ImGuiInputTextFlags& flags, ImVec4& color, NearestActorsInfo nearestActorsInfo)
{
	if (ImGui::TreeNode("Max Facing Alertable Actor"))
	{
		TEntityRef<ZActor> maxFacingAlertableActor = gameState->m_ActorInfo.m_pMaxFacingAlertableActor;
		nearestActorsInfo.AddNearestActorInfo(&maxFacingAlertableActor, flags, color, 0);
		ImGui::TreePop();
	}

	if (ImGui::TreeNode("Closest Alertable Actor"))
	{
		TEntityRef<ZActor> closestAlertableActor = gameState->m_ActorInfo.m_pClosestAlertableActor;
		nearestActorsInfo.AddNearestActorInfo(&closestAlertableActor, flags, color, 1);
		ImGui::TreePop();
	}

	if (ImGui::TreeNode("Closest Alertable Guard"))
	{
		TEntityRef<ZActor> closestAlertableGuard = gameState->m_ActorInfo.m_pClosestAlertableGuard;
		nearestActorsInfo.AddNearestActorInfo(&closestAlertableGuard, flags, color, 2);
		ImGui::TreePop();
	}

	if (ImGui::TreeNode("Closest Engaged Actor"))
	{
		TEntityRef<ZActor> closestEngagedActor = gameState->m_ActorInfo.m_pClosestEngagedActor;
		nearestActorsInfo.AddNearestActorInfo(&closestEngagedActor, flags, color, 3);
		ImGui::TreePop();
	}

	ImGui::Text("");
	ImGui::Text("Alerted: %d", gameState->m_ActorCounts.nAlerted);
	ImGui::Text("Alerted Armed: %d", gameState->m_ActorCounts.nAlertedArmed);
	ImGui::Text("Engaged: %d", gameState->m_ActorCounts.nEngaged);
	ImGui::Text("In Combat: %d", gameState->m_ActorCounts.nInCombat);
	ImGui::Text("Alertable Actor On Screen: %d", gameState->m_ActorCounts.nAlertableActorOnScreen);
	ImGui::Text("Alertable Guard On Screen: %d", gameState->m_ActorCounts.nAlertableGuardOnScreen);

	ImGui::Text("Alive Enemy Count: %d", gameState->m_nAliveEnemyCount);
	ImGui::Text("Alive Guard Count: %d", gameState->m_nAliveGuardCount);
	ImGui::Text("Attention Max: %f", gameState->m_fAttentionMax);
	ImGui::Text("Attention Max Pan: %f", gameState->m_fAttentionMaxPan);

	ImGui::Text("Trespassing Attention Max: %f", gameState->m_fTrespassingAttentionMax);
	ImGui::Text("Trespassing Attention Max Pan: %f", gameState->m_fTrespassingAttentionMaxPan);
	ImGui::Text("Disguise Attention Max: %f", gameState->m_fDisguiseAttentionMax);
	ImGui::Text("Disguise Attention Max Pan: %f", gameState->m_fDisguiseAttentionMaxPan);
	ImGui::Text("Disguise Heat: %f", gameState->m_fDisguiseHeat);
	ImGui::Text("Disguise Heat Pan: %f", gameState->m_fDisguiseHeatPan);

	if (gameState->m_bDisguiseSameOutfit)
	{
		ImGui::Text("Disguise Same Outfit: Yes");
	}
	else
	{
		ImGui::Text("Disguise Same Outfit: No");
	}

	ImGui::Text("Disguise Heat Rating: %d", gameState->m_nDisguiseHeatRating);
	ImGui::Text("");

	if (ImGui::TreeNode("Attention Max Actor"))
	{
		TEntityRef<ZActor> attentionMaxActor = gameState->m_pAttentionMaxActor;
		nearestActorsInfo.AddNearestActorInfo(&attentionMaxActor, flags, color, 4);
		ImGui::TreePop();
	}

	if (ImGui::TreeNode("Trespassing Attention Max Actor"))
	{
		TEntityRef<ZActor> trespassingAttentionMaxActor = gameState->m_pTrespassingAttentionMaxActor;
		nearestActorsInfo.AddNearestActorInfo(&trespassingAttentionMaxActor, flags, color, 5);
		ImGui::TreePop();
	}

	if (ImGui::TreeNode("Disguise Attention Max Actor"))
	{
		TEntityRef<ZActor> disguiseAttentionMaxActor = gameState->m_pDisguiseAttentionMaxActor;
		nearestActorsInfo.AddNearestActorInfo(&disguiseAttentionMaxActor, flags, color, 6);
		ImGui::TreePop();
	}

	if (ImGui::TreeNode("Disguise Heat Actor"))
	{
		TEntityRef<ZActor> disguiseHeatActor = gameState->m_pDisguiseHeatActor;
		nearestActorsInfo.AddNearestActorInfo(&disguiseHeatActor, flags, color, 7);
		ImGui::TreePop();
	}

	ImGui::Text("");

	bool outfitBroken = static_cast<bool>(gameState->m_bOutfitBroken);
	ImGui::Checkbox("Outfit Broken", &outfitBroken);

	gameState->m_bOutfitBroken = outfitBroken;

	bool outfitSuspicious = static_cast<bool>(gameState->m_bOutfitSuspicious);
	ImGui::Checkbox("Outfit Suspicious", &outfitSuspicious);

	gameState->m_bOutfitSuspicious = outfitSuspicious;

	bool inDisguise = static_cast<bool>(gameState->m_bInDisguise);
	ImGui::Checkbox("In Disguise", &inDisguise);

	gameState->m_bInDisguise = inDisguise;

	bool hitmanInCombat = static_cast<bool>(gameState->m_bHitmanInCombat);
	ImGui::Checkbox("Hitman In Combat", &hitmanInCombat);

	gameState->m_bHitmanInCombat = hitmanInCombat;

	bool bulletFlyBy = static_cast<bool>(gameState->m_bBulletFlyBy);
	ImGui::Checkbox("Bullet Fly By", &bulletFlyBy);

	gameState->m_bBulletFlyBy = bulletFlyBy;

	bool isHitmanStealthKilling = static_cast<bool>(gameState->m_bIsHitmanStealthKilling);
	ImGui::Checkbox("Is Hitman Stealth Killing", &isHitmanStealthKilling);

	gameState->m_bIsHitmanStealthKilling = isHitmanStealthKilling;

	bool hitmanTrespassing = static_cast<bool>(gameState->m_bHitmanTrespassing);
	ImGui::Checkbox("Hitman Trespassing", &hitmanTrespassing);

	gameState->m_bHitmanTrespassing = hitmanTrespassing;

	bool hitmanDeepTrespassing = static_cast<bool>(gameState->m_bHitmanDeepTrespassing);
	ImGui::Checkbox("Hitman Deep Trespassing", &hitmanDeepTrespassing);

	gameState->m_bHitmanDeepTrespassing = hitmanDeepTrespassing;

	bool hitmanNearDeadBody = static_cast<bool>(gameState->m_bHitmanNearDeadBody);
	ImGui::Checkbox("Hitman Near Dead Body", &hitmanNearDeadBody);

	gameState->m_bHitmanNearDeadBody = hitmanNearDeadBody;

	bool hitmanIllegalWeapon = static_cast<bool>(gameState->m_bHitmanIllegalWeapon);
	ImGui::Checkbox("Hitman Illegal Weapon", &hitmanIllegalWeapon);

	gameState->m_bHitmanIllegalWeapon = hitmanIllegalWeapon;

	bool hitmanChangingOutfit = static_cast<bool>(gameState->m_bHitmanChangingOutfit);
	ImGui::Checkbox("Hitman Changing Outfit", &hitmanChangingOutfit);

	gameState->m_bHitmanChangingOutfit = hitmanChangingOutfit;

	bool attentionOSDVisible = static_cast<bool>(gameState->m_bAttentionOSDVisible);
	ImGui::Checkbox("Attention OSD Visible", &attentionOSDVisible);

	gameState->m_bAttentionOSDVisible = attentionOSDVisible;

	bool bodyFound = static_cast<bool>(gameState->m_bBodyFound);
	ImGui::Checkbox("Body Found", &bodyFound);

	gameState->m_bBodyFound = bodyFound;

	bool bloodPoolFound = static_cast<bool>(gameState->m_bBloodPoolFound);
	ImGui::Checkbox("Blood Pool Found", &bloodPoolFound);

	gameState->m_bBloodPoolFound = bloodPoolFound;

	bool canOpenCPDoor = static_cast<bool>(gameState->m_bCanOpenCPDoor);
	ImGui::Checkbox("Can Open CP Door", &canOpenCPDoor);

	gameState->m_bCanOpenCPDoor = canOpenCPDoor;

	bool isHitmanHunted = static_cast<bool>(gameState->m_bIsHitmanHunted);
	ImGui::Checkbox("Is Hitman Hunted", &isHitmanHunted);

	gameState->m_bIsHitmanHunted = isHitmanHunted;

	bool spottedEnteringCloset = static_cast<bool>(gameState->m_bSpottedEnteringCloset);
	ImGui::Checkbox("Spotted Entering Closet", &spottedEnteringCloset);

	gameState->m_bSpottedEnteringCloset = spottedEnteringCloset;

	bool anyGuardsAlive = static_cast<bool>(gameState->m_bAnyGuardsAlive);
	ImGui::Checkbox("Any Guards Alive", &anyGuardsAlive);

	gameState->m_bAnyGuardsAlive = anyGuardsAlive;
}
