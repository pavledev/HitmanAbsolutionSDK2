#pragma once

#include "eInputRepeaterMode.h"
#include "ZGameTime.h"

class ZHM5WeaponControlInputRepeater
{
public:
    eInputRepeaterMode m_eMode;
    ZGameTime m_tLastModeChange;
    ZGameTime m_tINTERVAL_PASS;
    ZGameTime m_tINTERVAL_CUT;
};
