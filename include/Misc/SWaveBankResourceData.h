#pragma once

#include "EWaveBankMemoryLoadRTType.h"
#include "EWaveBankRTFormat.h"

struct SWaveBankResourceData
{
    int m_nTracks;
    EWaveBankMemoryLoadRTType m_eLoadType;
    EWaveBankRTFormat m_eFormat;
    int m_nIsPlaceholder;
    int m_nIsNotDucking;
    float m_fDuration;
    unsigned int m_nChannels;
    int m_nQuality;
};
