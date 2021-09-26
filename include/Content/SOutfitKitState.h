#pragma once

#include "SContentKitBaseState.h"
#include "TArray.h"

struct SOutfitKitState : SContentKitBaseState
{
	TArray<unsigned char> m_PickupState;

	SOutfitKitState(const SOutfitKitState& __that);
	SOutfitKitState() = default;
	bool SetPickedUp(int lvl, int cp);
	bool WasPickedUp(int lvl, int cp);
	~SOutfitKitState() = default;
	SOutfitKitState& operator=(const SOutfitKitState& __that);
};
