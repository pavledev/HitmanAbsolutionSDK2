#pragma once

#include "STokenID.h"
#include "SFireArmKitState.h"

struct SFireArmKitSaveData
{
	STokenID m_ID;
	SFireArmKitState m_State;

	SFireArmKitSaveData(const SFireArmKitSaveData& __that);
	SFireArmKitSaveData() = default;
	~SFireArmKitSaveData() = default;
	SFireArmKitSaveData& operator=(const SFireArmKitSaveData& __that);
};
