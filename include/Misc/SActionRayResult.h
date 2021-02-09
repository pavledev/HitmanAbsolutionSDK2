#pragma once

#include "ZGameTime.h"
#include "EQueryState.h"

class alignas(8) SActionRayResult
{
public:
    ZGameTime m_tLastQuery;
    EQueryState m_eState;
    float m_fDistanceSq;
    unsigned __int8 m_iRayStyle;
    unsigned __int8 m_iRayResults;
};
