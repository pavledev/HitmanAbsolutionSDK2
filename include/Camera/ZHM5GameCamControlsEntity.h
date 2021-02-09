#pragma once

#include "ZEntityImpl.h"
#include "ECameraControls.h"

class ZHM5GameCamControlsEntity : public ZEntityImpl
{
public:
    float m_fYawSpeed;
    float m_fYawSpeedFast;
    float m_fPitchSpeed;
    float m_fPitchSpeedFast;
    float m_fFastSpeedDelay;
    float m_fFastSpeedBlendInTime;
    ECameraControls m_eCameraControls;
};
