#pragma once

#include "ESoundPlayParameters.h"
#include "TArray.h"
#include "SLayerRepeatCountLimit.h"

class ZSoundSelector
{
public:
    ESoundPlayParameters m_eSelectionMode;
    int m_nNoRepeatsCount;
    TArray<SLayerRepeatCountLimit> m_aSubSoundRepeatCounts;
    int m_nSubsoundCount;
    unsigned int m_nLastPlayed;
    TArray<unsigned char> m_aLastPlayed;
    int m_nShuffleIndex;
};
