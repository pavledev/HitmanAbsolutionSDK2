#pragma once

#include "float4.h"
#include "SMatrix.h"

class alignas(16) SHM5LookAtInfo
{
public:
    float4 m_vLookAtPos;
    SMatrix m_mRotationBase;
    float m_fBlendSpeedFactor;
    float m_fLookAtTargetWeight;
    float m_fLookAtWeight;
    float m_fPoseWeight;
    bool m_bPoseChanged;
    const float* m_pHorizontalWeights;
    const float* m_pVerticalWeights;
};
