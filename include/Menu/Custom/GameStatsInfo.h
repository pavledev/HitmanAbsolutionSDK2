#pragma once

#include <iostream>
#include <string>
#include "imgui.h"
#include "ZGameStatsManager.h"
#include "NearestActorsInfo.h"
#include "Singletons.h"

using namespace std;

struct GameStatsInfo
{
	void DrawWindow(bool* showHUDInfo);

	string FormatArrayData(TArray<int> array);
	string FormatArrayData(unsigned int array[]);
	string FormatArrayData(bool array[]);

	const char* GetLevel(ELevelIndex levelIndex);

	void AddAIGameStateInfo(ZAIGameState* gameState, ImGuiInputTextFlags& flags, ImVec4& color, NearestActorsInfo nearestActorsInfo);
};
