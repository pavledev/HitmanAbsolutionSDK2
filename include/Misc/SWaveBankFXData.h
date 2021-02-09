#pragma once

#include "TArray.h"
#include "SFaceFXAnimationRef.h"
#include "SSubtitleRef.h"

class SWaveBankFXData
{
public:
    TArray<SFaceFXAnimationRef> m_aFaceFXAnimationRefs;
    TArray<SSubtitleRef> m_aSubtitleRefs;
};
