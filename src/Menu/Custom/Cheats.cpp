#include "Cheats.h"

void Cheats::DrawWindow(bool* showCheats)
{
	ImGui::SetNextWindowSize(ImVec2(500, 440), ImGuiCond_FirstUseEver);

	if (!ImGui::Begin("Cheats", showCheats))
	{
		ImGui::End();
		return;
	}

	static ZUIOptions* uiOptions = reinterpret_cast<ZUIOptions*>(Globals::g_pUIOptionsSingleton);

	static bool godMode = false, invisibility = false, infiniteAmmo = false, infiniteClip = false, infiniteFocus = false,
		alwaysShowCrossHair = false, cameraAutoCorrection = false, invertCameraVer = false, actionCamera = false;

	ImGui::Checkbox("God Mode", &godMode);
	ImGui::Checkbox("Invisibility", &invisibility);
	ImGui::Checkbox("Infinite Ammo", &infiniteAmmo);
	ImGui::Checkbox("Infinite Clip", &infiniteClip);
	ImGui::Checkbox("Infinite Focus", &infiniteFocus);
	ImGui::Checkbox("Always Show CrossHair", &alwaysShowCrossHair);
	ImGui::Checkbox("Camera Auto Correction", &cameraAutoCorrection);
	ImGui::Checkbox("Invert Camera Ver", &invertCameraVer);
	ImGui::Checkbox("Action Camera", &actionCamera);

	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_CHEAT_GOD, godMode);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_CHEAT_INVISIBLE, invisibility);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_CHEAT_INF_AMMO, infiniteAmmo);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_CHEAT_INF_CLIP, infiniteClip);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_CHEAT_INF_FOCUS, infiniteFocus);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_CHEAT_ALWAYS_SHOW_CROSSHAIR, alwaysShowCrossHair);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_CHEAT_CAMERA_AUTOCORRECTION, cameraAutoCorrection);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_CHEAT_INVERT_CAM_VER, invertCameraVer);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_CHEAT_ACTION_CAMERA, actionCamera);

	ImGui::End();
}
