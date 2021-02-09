#include "UIOptions.h"

void UIOptions::DrawWindow(bool* showUIOptions)
{
	ImGui::SetNextWindowSize(ImVec2(500, 440), ImGuiCond_FirstUseEver);

	if (!ImGui::Begin("UI Options", showUIOptions))
	{
		ImGui::End();
		return;
	}

	static ZUIOptions* uiOptions = reinterpret_cast<ZUIOptions*>(Globals::g_pUIOptionsSingleton);

	static bool uiOptionGameVibration, uiOptionGameAimAssist, uiOptionGameAimCausal, uiOptionGameInvertX, uiOptionGameInvertMouseX,
		uiOptionGameInvertMouseY, uiOptionGameInvertY, uiOptionGameControlScheme, uiOptionGameFastTarget,
		uiOptionGameTriggerShoot, uiOptionGameShootingBalletAuto, uiOptionGameSwitchSneakAndCamera, uiOptionGameLeftHandedControls,
		uiOptionGameInstinctPaths, uiOptionGameInstinctNpcglow, uiOptionGameHintsTutorial, uiOptionGameHintsInstinct,
		uiOptionGameCoverToggle, uiOptionGraphicsSubtitles, uiOptionDisplayFullscreen, uiOptionDisplayExclusive,
		uiOptionDisplayVsync, uiOptionDisplayStereoscopic, uiOptionGraphicsSsgi, uiOptionGraphicsLpv,
		uiOptionCheatGod, uiOptionCheatInvisible, uiOptionCheatInfAmmo, uiOptionCheatInfClip, uiOptionCheatInfFocus,
		uiOptionCheatAlwaysShowCrosshair, uiOptionCheatCameraAutocorrection, uiOptionCheatInvertCamVer, uiOptionCheatActionCamera,
		uiOptionDebugShowDebug, uiOptionDebugPrintLowFps, uiOptionDebugUiDisableHud, uiOptionDebugUiThreatRadar,
		uiOptionDebugHudInventory, uiOptionDebugScreenshot, uiOptionDebugDisableRooms;

	static int uiOptionGameDifficulty, uiOptionGameLangAudio, uiOptionGameLangText, uiOptionGameWeaponSelector,
		uiOptionDisplayResolution, uiOptionDisplayRefreshrate, uiOptionDisplayMonitor, uiOptionDisplayQuality,
		uiOptionDisplayAspect, uiOptionDisplayMsaa, uiOptionGraphicsQuality, uiOptionGraphicsShadowQuality,
		uiOptionGraphicsShadowResolution, uiOptionGraphicsTextureQuality, uiOptionGraphicsTextureFilter, uiOptionGraphicsSsao,
		uiOptionGraphicsTessellation, uiOptionGraphicsMirrors, uiOptionGraphicsAntiAliasing, uiOptionGraphicsLod,
		uiOptionGraphicsBokeh, uiOptionGraphicsBloom;
	static float uiOptionGameCameraSensitivityHorz, uiOptionGameCameraSensitivityVert, uiOptionGameMouseSensitivity,
		uiOptionSoundVolumeMaster, uiOptionSoundVolumeEffects, uiOptionSoundVolumeMusic, uiOptionSoundVolumeVoice,
		uiOptionGraphicsGamma, uiOptionGraphicsSafeAreaX, uiOptionGraphicsSafeAreaY, uiOptionDisplayStereoDepth,
		uiOptionDisplayStereoStrength, uiOptionDebugForceLodIndex;

	ImGui::PushItemWidth(200);

	ImGui::Checkbox("Game Vibration", &uiOptionGameVibration);
	ImGui::Checkbox("Game Aim Assist", &uiOptionGameAimAssist);
	ImGui::Checkbox("Game Aim Causal", &uiOptionGameAimCausal);
	ImGui::Checkbox("Game Invert X", &uiOptionGameInvertX);
	ImGui::Checkbox("Game Invert Mouse X", &uiOptionGameInvertMouseX);
	ImGui::Checkbox("Game Invert Mouse Y", &uiOptionGameInvertMouseY);
	ImGui::Checkbox("Game Invert Y", &uiOptionGameInvertY);
	ImGui::Checkbox("Game Control Scheme", &uiOptionGameControlScheme);
	ImGui::Checkbox("Game Fast Target", &uiOptionGameFastTarget);

	ImGui::Text("Game Difficulty");
	ImGui::SameLine();
	ImGui::InputInt("##GameDifficulty", &uiOptionGameDifficulty);

	ImGui::Checkbox("Game Trigger Shoot", &uiOptionGameTriggerShoot);
	ImGui::Checkbox("Game Shooting Ballet Auto", &uiOptionGameShootingBalletAuto);
	ImGui::Checkbox("Game Switch Sneak And Camera", &uiOptionGameSwitchSneakAndCamera);
	ImGui::Checkbox("Game Left Handed Controls", &uiOptionGameLeftHandedControls);

	ImGui::Text("Game Camera Sensitivity Horz");
	ImGui::SameLine();
	ImGui::InputFloat("##GameCameraSensitivityHorz", &uiOptionGameCameraSensitivityHorz);

	ImGui::Text("Game Camera Sensitivity Vert");
	ImGui::SameLine();
	ImGui::InputFloat("##GameCameraSensitivityVert", &uiOptionGameCameraSensitivityVert);

	ImGui::Text("Game Mouse Sensitivity");
	ImGui::SameLine();
	ImGui::InputFloat("##GameMouseSensitivity", &uiOptionGameMouseSensitivity);

	ImGui::Checkbox("Game Instinct Paths", &uiOptionGameInstinctPaths);
	ImGui::Checkbox("Game Instinct Npcglow", &uiOptionGameInstinctNpcglow);
	ImGui::Checkbox("Game Hints Tutorial", &uiOptionGameHintsTutorial);
	ImGui::Checkbox("Game Hints Instinct", &uiOptionGameHintsInstinct);

	ImGui::Text("Game Lang Audio");
	ImGui::SameLine();
	ImGui::InputInt("##GameLangAudio", &uiOptionGameLangAudio);

	ImGui::Text("Game Lang Text");
	ImGui::SameLine();
	ImGui::InputInt("##GameLangText", &uiOptionGameLangText);

	ImGui::Checkbox("Game Cover Toggle", &uiOptionGameCoverToggle);

	ImGui::Text("Game Weapon Selector");
	ImGui::SameLine();
	ImGui::InputInt("##GameWeaponSelector", &uiOptionGameWeaponSelector);

	ImGui::Text("Sound Volume Master");
	ImGui::SameLine();
	ImGui::InputFloat("##SoundVolumeMaster", &uiOptionSoundVolumeMaster);

	ImGui::Text("Sound Volume Effects");
	ImGui::SameLine();
	ImGui::InputFloat("##SoundVolumeEffects", &uiOptionSoundVolumeEffects);

	ImGui::Text("Sound Volume Music");
	ImGui::SameLine();
	ImGui::InputFloat("##SoundVolumeMusic", &uiOptionSoundVolumeMusic);

	ImGui::Text("Sound Volume Voice");
	ImGui::SameLine();
	ImGui::InputFloat("##SoundVolumeVoice", &uiOptionSoundVolumeVoice);

	ImGui::Checkbox("Graphics Subtitles", &uiOptionGraphicsSubtitles);

	ImGui::Text("Graphics Gamma");
	ImGui::SameLine();
	ImGui::InputFloat("##GraphicsGamma", &uiOptionGraphicsGamma);

	ImGui::Text("Graphics Safe Area X");
	ImGui::SameLine();
	ImGui::InputFloat("##GraphicsSafeAreaX", &uiOptionGraphicsSafeAreaX);

	ImGui::Text("Graphics Safe Area Y");
	ImGui::SameLine();
	ImGui::InputFloat("##GraphicsSafeAreaY", &uiOptionGraphicsSafeAreaY);

	ImGui::Text("Display Resolution");
	ImGui::SameLine();
	ImGui::InputInt("##DisplayResolution", &uiOptionDisplayResolution);

	ImGui::Text("Display Refreshrat");
	ImGui::SameLine();
	ImGui::InputInt("##DisplayRefreshrat", &uiOptionDisplayRefreshrate);

	ImGui::Checkbox("Display Fullscreen", &uiOptionDisplayFullscreen);
	ImGui::Checkbox("Display Exclusive", &uiOptionDisplayExclusive);
	ImGui::Checkbox("Display Vsync", &uiOptionDisplayVsync);

	ImGui::Text("Display Monitor");
	ImGui::SameLine();
	ImGui::InputInt("##DisplayMonitor", &uiOptionDisplayMonitor);

	ImGui::Text("Display Quality");
	ImGui::SameLine();
	ImGui::InputInt("##DisplayQuality", &uiOptionDisplayQuality);

	ImGui::Text("Display Aspect");
	ImGui::SameLine();
	ImGui::InputInt("##DisplayAspect", &uiOptionDisplayAspect);

	ImGui::Checkbox("Display Stereoscopic", &uiOptionDisplayStereoscopic);

	ImGui::Text("Display Stereo Depth");
	ImGui::SameLine();
	ImGui::InputFloat("##DisplayStereoDepth", &uiOptionDisplayStereoDepth);

	ImGui::Text("Display Stereo Strength");
	ImGui::SameLine();
	ImGui::InputFloat("##DisplayStereoStrength", &uiOptionDisplayStereoStrength);

	ImGui::Text("Display Msaa");
	ImGui::SameLine();
	ImGui::InputInt("##DisplayMsaa", &uiOptionDisplayMsaa);

	ImGui::Text("Graphics Quality");
	ImGui::SameLine();
	ImGui::InputInt("##GraphicsQuality", &uiOptionGraphicsQuality);

	ImGui::Text("Graphics Shadow Quality");
	ImGui::SameLine();
	ImGui::InputInt("##GraphicsShadowQuality", &uiOptionGraphicsShadowQuality);

	ImGui::Text("Graphics Shadow Resolution");
	ImGui::SameLine();
	ImGui::InputInt("##GraphicsShadowResolution", &uiOptionGraphicsShadowResolution);

	ImGui::Text("Graphics Texture Quality");
	ImGui::SameLine();
	ImGui::InputInt("##GraphicsTextureQuality", &uiOptionGraphicsTextureQuality);

	ImGui::Text("Graphics Texture Filter");
	ImGui::SameLine();
	ImGui::InputInt("##GraphicsTextureFilter", &uiOptionGraphicsTextureFilter);

	ImGui::Text("Graphics Ssao");
	ImGui::SameLine();
	ImGui::InputInt("##GraphicsSsao", &uiOptionGraphicsSsao);

	ImGui::Checkbox("Graphics Ssgi", &uiOptionGraphicsSsgi);
	ImGui::Checkbox("Graphics Lpv", &uiOptionGraphicsLpv);

	ImGui::Text("Graphics Tessellation");
	ImGui::SameLine();
	ImGui::InputInt("##GraphicsTessellation", &uiOptionGraphicsTessellation);

	ImGui::Text("Graphics Mirrors");
	ImGui::SameLine();
	ImGui::InputInt("##GraphicsMirrors", &uiOptionGraphicsMirrors);

	ImGui::Text("Graphics Anti Aliasing");
	ImGui::SameLine();
	ImGui::InputInt("##GraphicsAntiAliasing", &uiOptionGraphicsAntiAliasing);

	ImGui::Text("Graphics Lod");
	ImGui::SameLine();
	ImGui::InputInt("##GraphicsLod", &uiOptionGraphicsLod);

	ImGui::Text("Graphics Bokeh");
	ImGui::SameLine();
	ImGui::InputInt("##GraphicsBokeh", &uiOptionGraphicsBokeh);

	ImGui::Text("Graphics Bloom");
	ImGui::SameLine();
	ImGui::InputInt("##GraphicsBloom", &uiOptionGraphicsBloom);

	ImGui::Checkbox("Cheat God", &uiOptionCheatGod);
	ImGui::Checkbox("Cheat Invisible", &uiOptionCheatInvisible);
	ImGui::Checkbox("Cheat Inf Ammo", &uiOptionCheatInfAmmo);
	ImGui::Checkbox("Cheat Inf Clip", &uiOptionCheatInfClip);
	ImGui::Checkbox("Cheat Inf Focus", &uiOptionCheatInfFocus);
	ImGui::Checkbox("Cheat Always Show Crosshair", &uiOptionCheatAlwaysShowCrosshair);
	ImGui::Checkbox("Cheat Camera Autocorrection", &uiOptionCheatCameraAutocorrection);
	ImGui::Checkbox("Cheat Invert Cam Ver", &uiOptionCheatInvertCamVer);
	ImGui::Checkbox("Cheat Action Camera", &uiOptionCheatActionCamera);
	ImGui::Checkbox("Debug Show Debug", &uiOptionDebugShowDebug);
	ImGui::Checkbox("Debug Print Low Fps", &uiOptionDebugPrintLowFps);
	ImGui::Checkbox("Debug Ui Disable Hud", &uiOptionDebugUiDisableHud);
	ImGui::Checkbox("Debug Ui Threat Radar", &uiOptionDebugUiThreatRadar);
	ImGui::Checkbox("Debug Hud Inventory", &uiOptionDebugHudInventory);

	ImGui::Text("Debug Force Lod Index");
	ImGui::SameLine();
	ImGui::InputFloat("##DebugForceLodIndex", &uiOptionDebugForceLodIndex);

	ImGui::Checkbox("Debug Screenshot", &uiOptionDebugScreenshot);
	ImGui::Checkbox("Debug Disable Rooms", &uiOptionDebugDisableRooms);

	ImGui::PopItemWidth();

	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_GAME_VIBRATION, uiOptionGameVibration);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_GAME_AIM_ASSIST, uiOptionGameAimAssist);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_GAME_AIM_CAUSAL, uiOptionGameAimCausal);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_GAME_INVERT_X, uiOptionGameInvertX);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_GAME_INVERT_MOUSE_X, uiOptionGameInvertMouseX);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_GAME_INVERT_MOUSE_Y, uiOptionGameInvertMouseY);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_GAME_INVERT_Y, uiOptionGameInvertY);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_GAME_CONTROL_SCHEME, uiOptionGameControlScheme);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_GAME_FAST_TARGET, uiOptionGameFastTarget);
	uiOptions->SetInt(_EUIOptionKey::UI_OPTION_GAME_DIFFICULTY, uiOptionGameDifficulty);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_GAME_TRIGGER_SHOOT, uiOptionGameTriggerShoot);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_GAME_SHOOTING_BALLET_AUTO, uiOptionGameShootingBalletAuto);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_GAME_SWITCH_SNEAK_AND_CAMERA, uiOptionGameSwitchSneakAndCamera);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_GAME_LEFT_HANDED_CONTROLS, uiOptionGameLeftHandedControls);
	uiOptions->SetFloat(_EUIOptionKey::UI_OPTION_GAME_CAMERA_SENSITIVITY_HORZ, uiOptionGameCameraSensitivityHorz);
	uiOptions->SetFloat(_EUIOptionKey::UI_OPTION_GAME_CAMERA_SENSITIVITY_VERT, uiOptionGameCameraSensitivityVert);
	uiOptions->SetFloat(_EUIOptionKey::UI_OPTION_GAME_MOUSE_SENSITIVITY, uiOptionGameMouseSensitivity);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_GAME_INSTINCT_PATHS, uiOptionGameInstinctPaths);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_GAME_INSTINCT_NPCGLOW, uiOptionGameInstinctNpcglow);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_GAME_HINTS_TUTORIAL, uiOptionGameHintsTutorial);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_GAME_HINTS_INSTINCT, uiOptionGameHintsInstinct);
	uiOptions->SetInt(_EUIOptionKey::UI_OPTION_GAME_LANG_AUDIO, uiOptionGameLangAudio);
	uiOptions->SetInt(_EUIOptionKey::UI_OPTION_GAME_LANG_TEXT, uiOptionGameLangText);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_GAME_COVER_TOGGLE, uiOptionGameCoverToggle);
	uiOptions->SetInt(_EUIOptionKey::UI_OPTION_GAME_WEAPON_SELECTOR, uiOptionGameWeaponSelector);
	uiOptions->SetFloat(_EUIOptionKey::UI_OPTION_SOUND_VOLUME_MASTER, uiOptionSoundVolumeMaster);
	uiOptions->SetFloat(_EUIOptionKey::UI_OPTION_SOUND_VOLUME_EFFECTS, uiOptionSoundVolumeEffects);
	uiOptions->SetFloat(_EUIOptionKey::UI_OPTION_SOUND_VOLUME_MUSIC, uiOptionSoundVolumeMusic);
	uiOptions->SetFloat(_EUIOptionKey::UI_OPTION_SOUND_VOLUME_VOICE, uiOptionSoundVolumeVoice);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_GRAPHICS_SUBTITLES, uiOptionGraphicsSubtitles);
	uiOptions->SetFloat(_EUIOptionKey::UI_OPTION_GRAPHICS_GAMMA, uiOptionGraphicsGamma);
	uiOptions->SetFloat(_EUIOptionKey::UI_OPTION_GRAPHICS_SAFE_AREA_X, uiOptionGraphicsSafeAreaX);
	uiOptions->SetFloat(_EUIOptionKey::UI_OPTION_GRAPHICS_SAFE_AREA_Y, uiOptionGraphicsSafeAreaY);
	uiOptions->SetInt(_EUIOptionKey::UI_OPTION_DISPLAY_RESOLUTION, uiOptionDisplayResolution);
	uiOptions->SetInt(_EUIOptionKey::UI_OPTION_DISPLAY_REFRESHRATE, uiOptionDisplayRefreshrate);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_DISPLAY_FULLSCREEN, uiOptionDisplayFullscreen);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_DISPLAY_EXCLUSIVE, uiOptionDisplayExclusive);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_DISPLAY_VSYNC, uiOptionDisplayVsync);
	uiOptions->SetInt(_EUIOptionKey::UI_OPTION_DISPLAY_MONITOR, uiOptionDisplayMonitor);
	uiOptions->SetInt(_EUIOptionKey::UI_OPTION_DISPLAY_QUALITY, uiOptionDisplayQuality);
	uiOptions->SetInt(_EUIOptionKey::UI_OPTION_DISPLAY_ASPECT, uiOptionDisplayAspect);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_DISPLAY_STEREOSCOPIC, uiOptionDisplayStereoscopic);
	uiOptions->SetFloat(_EUIOptionKey::UI_OPTION_DISPLAY_STEREO_DEPTH, uiOptionDisplayStereoDepth);
	uiOptions->SetFloat(_EUIOptionKey::UI_OPTION_DISPLAY_STEREO_STRENGTH, uiOptionDisplayStereoStrength);
	uiOptions->SetInt(_EUIOptionKey::UI_OPTION_DISPLAY_MSAA, uiOptionDisplayMsaa);
	uiOptions->SetInt(_EUIOptionKey::UI_OPTION_GRAPHICS_QUALITY, uiOptionGraphicsQuality);
	uiOptions->SetInt(_EUIOptionKey::UI_OPTION_GRAPHICS_SHADOW_QUALITY, uiOptionGraphicsShadowQuality);
	uiOptions->SetInt(_EUIOptionKey::UI_OPTION_GRAPHICS_SHADOW_RESOLUTION, uiOptionGraphicsShadowResolution);
	uiOptions->SetInt(_EUIOptionKey::UI_OPTION_GRAPHICS_TEXTURE_QUALITY, uiOptionGraphicsTextureQuality);
	uiOptions->SetInt(_EUIOptionKey::UI_OPTION_GRAPHICS_TEXTURE_FILTER, uiOptionGraphicsTextureFilter);
	uiOptions->SetInt(_EUIOptionKey::UI_OPTION_GRAPHICS_SSAO, uiOptionGraphicsSsao);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_GRAPHICS_SSGI, uiOptionGraphicsSsgi);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_GRAPHICS_LPV, uiOptionGraphicsLpv);
	uiOptions->SetInt(_EUIOptionKey::UI_OPTION_GRAPHICS_TESSELLATION, uiOptionGraphicsTessellation);
	uiOptions->SetInt(_EUIOptionKey::UI_OPTION_GRAPHICS_MIRRORS, uiOptionGraphicsMirrors);
	uiOptions->SetInt(_EUIOptionKey::UI_OPTION_GRAPHICS_ANTI_ALIASING, uiOptionGraphicsAntiAliasing);
	uiOptions->SetInt(_EUIOptionKey::UI_OPTION_GRAPHICS_LOD, uiOptionGraphicsLod);
	uiOptions->SetInt(_EUIOptionKey::UI_OPTION_GRAPHICS_BOKEH, uiOptionGraphicsBokeh);
	uiOptions->SetInt(_EUIOptionKey::UI_OPTION_GRAPHICS_BLOOM, uiOptionGraphicsBloom);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_CHEAT_GOD, uiOptionCheatGod);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_CHEAT_INVISIBLE, uiOptionCheatInvisible);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_CHEAT_INF_AMMO, uiOptionCheatInfAmmo);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_CHEAT_INF_CLIP, uiOptionCheatInfClip);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_CHEAT_INF_FOCUS, uiOptionCheatInfFocus);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_CHEAT_ALWAYS_SHOW_CROSSHAIR, uiOptionCheatAlwaysShowCrosshair);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_CHEAT_CAMERA_AUTOCORRECTION, uiOptionCheatCameraAutocorrection);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_CHEAT_INVERT_CAM_VER, uiOptionCheatInvertCamVer);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_CHEAT_ACTION_CAMERA, uiOptionCheatActionCamera);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_DEBUG_SHOW_DEBUG, uiOptionDebugShowDebug);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_DEBUG_PRINT_LOW_FPS, uiOptionDebugPrintLowFps);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_DEBUG_UI_DISABLE_HUD, uiOptionDebugUiDisableHud);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_DEBUG_UI_THREAT_RADAR, uiOptionDebugUiThreatRadar);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_DEBUG_HUD_INVENTORY, uiOptionDebugHudInventory);
	uiOptions->SetFloat(_EUIOptionKey::UI_OPTION_DEBUG_FORCE_LOD_INDEX, uiOptionDebugForceLodIndex);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_DEBUG_SCREENSHOT, uiOptionDebugScreenshot);
	uiOptions->SetBool(_EUIOptionKey::UI_OPTION_DEBUG_DISABLE_ROOMS, uiOptionDebugDisableRooms);

	ImGui::End();
}
