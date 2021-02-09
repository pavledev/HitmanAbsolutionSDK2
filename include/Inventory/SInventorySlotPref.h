#pragma once

#include "EInventorySlotType.h"

class alignas(4) SInventorySlotPref
{
public:
    EInventorySlotType m_eSlotType;
    bool m_bDualWielded;
};
