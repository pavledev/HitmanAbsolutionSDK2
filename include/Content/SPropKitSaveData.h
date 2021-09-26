#pragma once

#include "STokenID.h"
#include "SPropKitState.h"

struct SPropKitSaveData
{
	STokenID m_ID;
	SPropKitState m_State;

	SPropKitSaveData(const SPropKitSaveData& __that);
	SPropKitSaveData() = default;
	~SPropKitSaveData() = default;
	SPropKitSaveData& operator=(const SPropKitSaveData& __that);
};
