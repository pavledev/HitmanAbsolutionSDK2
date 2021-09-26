#pragma once

#include "SContentKitBaseState.h"
#include "TArray.h"

struct SPropKitState : SContentKitBaseState
{
	bool m_bUnlocked;
	TArray<unsigned char> m_PickupState;

	SPropKitState(const SPropKitState& __that);
	SPropKitState() = default;
	bool SetPickedUp(int lvl, int cp);
	bool WasPickedUp(int lvl, int cp);
	~SPropKitState() = default;
	SPropKitState& operator=(const SPropKitState& __that);
};
