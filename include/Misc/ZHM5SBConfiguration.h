#pragma once

#include "ZEntityImpl.h"

class ZHM5SBConfiguration : public ZEntityImpl
{
public:
    float m_fDuration;
    float m_fEaseOutTime;
    float m_fStartMultiplier;
    float m_fEndMultiplier;
};
