#pragma once

class alignas(4) SHM5GameCamAngleLimits
{
public:
    float m_fPitchAngleMax;
    float m_fPitchAngleMin;
    float m_fYawOffset;
    float m_fYawAngle;
    bool m_bEnableSmootingAtLimits;
};
