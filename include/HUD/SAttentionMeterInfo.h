#pragma once

#include "ZEntityRef.h"
#include "EGameTension.h"
#include "EThreatType.h"
#include "float4.h"
#include "EAttentionMeterState.h"
#include "ZGameTime.h"

class SAttentionMeterInfo
{
public:
    ZEntityRef m_rThreat;
    float m_fAttention;
    EGameTension m_eGameTension;
    EThreatType m_eThreatType;
    bool m_bInSight;
    bool m_bShowAttention;
    float4 m_vPosition;
    float m_fAlpha;
    float m_fOldAttention;
    EGameTension m_eOldGameTension;
    EAttentionMeterState m_eState;
    bool m_bResetted;
    ZGameTime m_timeOfTouch;
};
