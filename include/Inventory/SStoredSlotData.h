#pragma once

#include "ZInventorySlot.h"

struct alignas(4) SStoredSlotData
{
    ZInventorySlot* m_pStoredInventorySlot;
    unsigned __int8 m_iStoreReason;
    
    union
    {
        unsigned __int8 unionInt;

        struct
        {
            __int8 m_bItemsStored : 1;
            __int8 m_bRestoreItems : 1;
            __int8 m_bSignalWeaponSoundManager : 1;
            __int8 m_bPlayEquipAnimation : 1;
        };
    };
};
