#pragma once

#include "STokenID.h"

struct SItemSaveData
{
	STokenID m_ID;

	SItemSaveData(const STokenID& id);
	SItemSaveData() = default;
	~SItemSaveData() = default;
};
