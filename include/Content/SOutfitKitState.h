#pragma once

#include "SContentKitBaseState.h"
#include "TArray.h"

class SOutfitKitState : public SContentKitBaseState
{
public:
    TArray<unsigned char> m_PickupState;
};
