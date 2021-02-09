#pragma once

#include "float4.h"
#include "EAimMode.h"

class SSBAimInfo
{
public:
    unsigned int m_nAimPose;
    unsigned int m_nAimPoseGrips;
    float4 m_vAimPos;
    float m_fAimWeight;
    float m_fPoseWeight;
    bool m_bStorePose;
    EAimMode m_eAimMode;
};
