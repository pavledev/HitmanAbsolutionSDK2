#pragma once

#include "ZEntityImpl.h"

class ZHM53rdPersonCamProfile : public ZEntityImpl
{
public:
    float m_fLevelOutThresholdTimeAim;
    float m_fLevelOutThresholdTimeStand;
    float m_fLevelOutThresholdTimeStickVert;
    float m_fLevelOutAngle;
    float m_fSideChangeTime;
};
