#pragma once

#include "ZEntityImpl.h"
#include "IHM5ActionEntityListener.h"
#include "EBCState.h"
#include "eBCCloseMode.h"
#include "EBCAnimSet.h"
#include "EBCBodyMode.h"
#include "IDynamicPhysics.h"
#include "SGameUpdateEvent.h"

class ZActor;

class alignas(16) ZHM5BodyContainer : public ZEntityImpl, public IHM5ActionEntityListener
{
public:
    EBCState m_eBCState;
    TEntityRef<ZSpatialEntity> m_rBCLid;
    TEntityRef<ISequenceEntity> m_rSequenceEntity;
    TEntityRef<ZSpatialEntity> m_rStartPos;
    eBCCloseMode m_BCCloseMode;
    EBCAnimSet m_eBCAnimSet;
    EBCBodyMode m_eBodyMode;
    bool m_bEnabled;
    TEntityRef<ZHM5Action> m_rAction;
    TEntityRef<IDynamicPhysics> m_rLidPhysics;
    TEntityRef<ZActor> m_rVictims[2];
    unsigned int m_iNumVictims;
    float m_fLidAutoCloseTime;
    float4 m_vBCDir;
    bool m_bLastShowTargetsMustBeDeadSent;
    bool m_bDisabledHack;
    ZEvent<TEntityRef<ZHM5BodyContainer>, TEntityRef<ZActor>, ZEventNull, ZEventNull, ZEventNull> m_BodyDumpedEvent;

    enum UnkEnum : __int32
    {
        MAX_VICTIMS = 0x2
    };

    virtual void FrameUpdate(const SGameUpdateEvent*);
};
