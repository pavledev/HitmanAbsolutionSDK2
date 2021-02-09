#pragma once

#include "SVector3.h"
#include "TResourcePtr.h"
#include "ZWaveBankData.h"

class SSoundTriggerPoint
{
public:
    SVector3 m_vPosition;
    int m_nChannel;
    int m_nChannelFlags;
    float m_fAttenuation;
    float m_fPitch;
    float m_fLowpassCutoff;
    float m_fDelayTime;
    TResourcePtr<ZWaveBankData> m_pWavebank;
};
