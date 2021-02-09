#pragma once

#include "ESBCamProfileBone.h"
#include "ESBPose.h"

class SSBCamHitmanProfile
{
public:
    float m_fHeight;
    float m_fStickLength;
    float m_fRadius;
    float m_fFOV;
    float m_fRoll;
    float m_fYawAngle;
    float m_fPitchAngle;
    ESBCamProfileBone m_eBone;
    ESBPose m_ePose;
};
