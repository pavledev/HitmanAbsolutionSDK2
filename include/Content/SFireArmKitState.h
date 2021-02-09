#pragma once

#include "SContentKitBaseState.h"
#include "TFixedArray.h"
#include "TArray.h"

class SFireArmKitState : public SContentKitBaseState
{
public:
    unsigned int m_iUpgUnLocked;
    TFixedArray<signed char, 4> m_iUpgInstalled;
    unsigned __int8 m_iUpgUnlockedSlots;
    unsigned __int8 m_iUpgradesNum;
    TArray<unsigned char> m_PickupState;

    enum
    {
        eSAVEGAME_NOT_VALID = 0xFF
    };
};
