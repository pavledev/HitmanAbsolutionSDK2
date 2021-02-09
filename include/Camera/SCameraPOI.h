#pragma once

#include "ECameraPOI.h"

class SCameraPOI
{
public:
    bool m_bAllowInterrupt;
    float m_fTimeOnPOI;
    float m_fBlendInTime;
    ECameraPOI m_ePOIType;
};
