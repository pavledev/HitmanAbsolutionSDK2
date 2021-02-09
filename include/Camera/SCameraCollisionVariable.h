#pragma once

#include "ZMapPoly.h"

class SCameraCollisionVariable
{
public:
    float m_fCollisionVariable;
    float m_fDelayTime;
    float m_fDelayDuration;
    float m_fMaxVelocity;
    bool m_bBlending;
    bool m_bColliding;
    ZMapPoly m_MapPoly;
};
