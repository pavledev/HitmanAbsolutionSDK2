#pragma once

#include "SVector3.h"
#include "SVector2.h"
#include "TArrayRef.h"
#include "SMatrix.h"

class SHM5ScopeParameters
{
public:
    SVector3 m_vBobbingAngleX;
    SVector3 m_vBobbingAngleY;
    SVector3 m_vBobbingFrequencyX;
    SVector3 m_vBobbingFrequencyY;
    float m_fPulseIncreaseOnShooting;
    float m_fDragCorrectionFraction;
    float m_fDragCorrectionInvTime;
    SVector2 m_vDragAngles;
    TArrayRef<SVector2> m_aScopeZoom;
    SMatrix m_mInvScope;
    SMatrix m_mCrossHair;
    float m_fZRecoilDistance;
    float m_fZRecoilTime;
    float m_fScopeFOV;
    float m_fCounterRotationFactor;
};
