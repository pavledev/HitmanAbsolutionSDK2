#pragma once

#include "SVector3.h"

class alignas(4) sLedgeInfo
{
public:
    SVector3 m_vPelvisPushDir;
    float m_fClavRot;
    bool m_bRetargetFeet;
};
