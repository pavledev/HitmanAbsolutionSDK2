#pragma once

#include <iostream>
#include <string>
#include "imgui.h"
#include "Singletons.h"
#include "ZSpatialEntity.h"

using namespace std;

struct PropsInfo
{
	ImGuiInputTextFlags flags;
	ImVec4 color;

	PropsInfo();

	void DrawWindow(bool* showItemsInfo);

	void AddPropInfo(ZSpatialEntity* spatialEntity, int propIndex);

	void AddLocalPositionInputs(ZSpatialEntity* spatialEntity, int propIndex);
	void AddWorldPositionInputs(ZSpatialEntity* spatialEntity, int propIndex);
	void SetLocalPositionOfProp(float4 localPosition, int propIndex);
	void SetWorldPositionOfProp(float4 worldPosition, int propIndex);
};
