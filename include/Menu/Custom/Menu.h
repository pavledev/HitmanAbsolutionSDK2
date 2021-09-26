#pragma once

#include "imgui.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_win32.h"

#include "ZInputActionManager.h"
#include "ZInputDeviceManager.h"
#include "ZHM5CollisionManager.h"

#include "DebugConsole.h"
#include "PlayerInfo.h"
#include "Globals.h"
#include "ActorsInfo.h"
#include "ItemsInfo.h"
#include "PropsInfo.h"
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
	bool showPropsInfo = false;
	bool showHUDInfo = false;
	bool showGameStatsInfo = false;
	bool showCheats = false;
	bool showUIOptions = false;
	inline static DebugConsole console;
	inline static PlayerInfo playerInfo;
	inline static ActorsInfo actorsInfo;
	inline static ItemsInfo itemsInfo;
	inline static PropsInfo propsInfo;
	inline static HUDInfo hudInfo;
	inline static GameStatsInfo gameStatsInfo;
	inline static Cheats cheats;
	inline static UIOptions uiOptions;

	void Render();
};
