#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZSequenceEntity.h"

class alignas(4) ZHM5LooseTargetEncounter : public ZEntityImpl
{
public:
    TEntityRef<ZSequenceEntity> m_rLooseSequence;
    bool m_bEnabled;
    __int8 m_bActivated : 1;
    __int8 m_bDeactivatingCheckpoint : 1;
    __int8 m_bLevelEnded : 1;
};
