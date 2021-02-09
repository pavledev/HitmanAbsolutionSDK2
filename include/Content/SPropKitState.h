#pragma once

#include "SContentKitBaseState.h"
#include "TArray.h"

class SPropKitState : public SContentKitBaseState
{
public:
    bool m_bUnlocked;
    TArray<unsigned char> m_PickupState;
};
