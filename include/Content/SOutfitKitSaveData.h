#pragma once

#include "STokenID.h"
#include "SOutfitKitState.h"

struct SOutfitKitSaveData
{
	STokenID m_ID;
	SOutfitKitState m_State;

	SOutfitKitSaveData(const SOutfitKitSaveData& __that);
	SOutfitKitSaveData() = default;
	~SOutfitKitSaveData() = default;
	SOutfitKitSaveData& operator=(const SOutfitKitSaveData& __that);
};
