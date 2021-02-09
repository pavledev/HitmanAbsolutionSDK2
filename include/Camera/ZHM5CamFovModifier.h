#pragma once

#include "ECamFov.h"

class ZHM5CamFovModifier
{
public:
    float m_fStateTime;
    float m_fFovOffset1;
    float m_fFovOffset2;
    float m_afStateTimes[4];
    ECamFov m_eState;
};
