#pragma once

#include "float4.h"
#include "eCornerSide.h"

class alignas(16) sCoverCorner
{
public:
    float4 m_vCornerPoint;
    eCornerSide m_eSide;
    __int8 m_bValid : 1;
    __int8 m_bHighCoverCorner : 1;
    __int8 m_bWindowCorner : 1;
    __int8 m_bDisabled : 1;
};
