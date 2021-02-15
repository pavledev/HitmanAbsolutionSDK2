#include "Cheats.h"

void Cheats::DrawWindow(bool* showCheats)
{
	ImGui::SetNextWindowSize(ImVec2(500, 440), ImGuiCond_FirstUseEver);

	if (!ImGui::Begin("Cheats", showCheats))
	{
		ImGui::End();
		return;
	}

	static bool godMode = false, invisibility = false, infiniteAmmo = false, refillFocus = false;

	ImGui::Checkbox("God Mode", &godMode);
	ImGui::Checkbox("Invisibility", &invisibility);
	ImGui::Checkbox("Infinite Ammo", &infiniteAmmo);
	ImGui::Checkbox("Refill Focus", &refillFocus);

	static int* g_GodMode = reinterpret_cast<int*>(BaseAddresses::hitman5Dll + 0xBCF290);
	static int* g_Invisible = reinterpret_cast<int*>(BaseAddresses::hitman5Dll + 0xBD5C64);
	static int* g_InfAmmo = reinterpret_cast<int*>(BaseAddresses::hitman5Dll + 0xBCD218);

	*g_GodMode = godMode;
	*g_Invisible = invisibility;
	*g_InfAmmo = infiniteAmmo;

	static ZLevelManager* levelManager = reinterpret_cast<ZLevelManager*>(Globals::g_pLevelManagerSingleton);

	if (levelManager)
	{
		static ZHitman5* player = levelManager->m_rHitman.m_pInterfaceRef;

		if (player)
		{
			if (refillFocus)
			{
				float* focus = player->m_pFocusController->m_pFocus;
				*focus = 1.0f;
			}
		}
	}

	ImGui::End();
}
