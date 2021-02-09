#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZSequenceActor.h"

class alignas(2) ZActorsSequence : public ZEntityImpl
{
public:
    TArray<TEntityRef<ZSequenceActor>> m_aActors;
    TEntityRef<ISequenceEntity> m_pSequence;
    TEntityRef<IBoolCondition> m_pStartCondition;
    bool m_bOneTimeOnly;
    bool m_bPreventItemGlow;
    __int8 m_bIsPlaying : 1;
    __int8 m_bHasPlayed : 1;
    __int8 m_bWasManuallyStarted : 1;
    __int8 m_bActive : 1;

    class StopReason
    {
        enum Enum : __int32
        {
            SequenceCompleted = 0x0,
            SequenceInterrupted = 0x1,
            BeingDeactivated = 0x2,
            FailedToStart = 0x3
        };
    };
};
