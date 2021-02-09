#pragma once

#include "imgui.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_win32.h"

#include "ZInputActionManager.h"
#include "ZInputDeviceManager.h"

#include "DebugConsole.h"
#include "PlayerInfo.h"
#include "Globals.h"
#include "ActorsInfo.h"
#include "ItemsInfo.h"
#include "HUDInfo.h"
#include "GameStatsInfo.h"
#include "Cheats.h"
#include "UIOptions.h"

class Menu
{
public:
	bool isOpen = false;
	bool showDebugConsole = false;
	bool showPlayerInfo = false;
	bool showActorsInfo = false;
	bool showItemsInfo = false;
	bool showHUDInfo = false;
	bool showGameStatsInfo = false;
	bool showCheats = false;
	bool showUIOptions = false;
	static DebugConsole console;
	static PlayerInfo playerInfo;
	static ActorsInfo actorsInfo;
	static ItemsInfo itemsInfo;
	static HUDInfo hudInfo;
	static GameStatsInfo gameStatsInfo;
	static Cheats cheats;
	static UIOptions uiOptions;

	void Render();
};
