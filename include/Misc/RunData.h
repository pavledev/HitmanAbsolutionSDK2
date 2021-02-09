#pragma once

#include "TArray.h"
#include "TEntityRef.h"
#include "ISequenceTrack.h"

class alignas(8) RunData
{
public:
    TArray<TEntityRef<ISequenceTrack>> m_aTracks;
    TArray<TEntityRef<ISequenceTrack>> m_aStartedTracks;
    ZGameTime m_effectiveSequenceTime;
    int m_nCurrentLoop;
};
