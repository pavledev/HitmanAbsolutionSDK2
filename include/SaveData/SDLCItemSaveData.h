#pragma once

#include "STokenID.h"

struct SDLCItemSaveData
{
	enum EDiscoverState
	{
		DS_DISCOVERED = 0,
		DS_REMOVED = 1
	};

	EDiscoverState m_eState;
	STokenID m_TokenID;

	SDLCItemSaveData() = default;
	~SDLCItemSaveData() = default;
};
