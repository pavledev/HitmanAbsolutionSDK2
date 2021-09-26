#include "Cheats.h"
#include "ZHitman5.h"
#include "BaseAddresses.h"
#include "ZHM5FocusController.h"

void Cheats::DrawWindow(bool* showCheats)
{
	ImGui::SetNextWindowSize(ImVec2(500, 440), ImGuiCond_FirstUseEver);

	if (!ImGui::Begin("Cheats", showCheats))
	{
		ImGui::End();
		return;
	}

	static bool godMode = false, invisibility = false, infiniteAmmo = false;

	ImGui::Checkbox("God Mode", &godMode);
	ImGui::Checkbox("Invisibility", &invisibility);
	ImGui::Checkbox("Infinite Ammo", &infiniteAmmo);

	static int* g_GodMode = reinterpret_cast<int*>(BaseAddresses::hitman5Dll + 0xBCF290);
	static int* g_Invisible = reinterpret_cast<int*>(BaseAddresses::hitman5Dll + 0xBD5C64);
	static int* g_InfAmmo = reinterpret_cast<int*>(BaseAddresses::hitman5Dll + 0xBCD218);

	*g_GodMode = godMode;
	*g_Invisible = invisibility;
	*g_InfAmmo = infiniteAmmo;

	if (ImGui::Button("Refill Focus"))
	{
		static ZLevelManager* levelManager = Singletons::GetLevelManager();

		if (levelManager)
		{
			static ZHitman5* player = levelManager->GetHitman().GetRawPointer();

			if (player)
			{
				player->GetFocusController()->SetFocus(1.0f);
			}
		}
	}

	ImGui::End();
}
