#pragma once

#include "SSituationInstance.h"
#include "ZSituationBase.h"

class ZActorManager;

class alignas(16) ZSituationManager
{
public:
    ZActorManager* m_actorManager;
    TArrayFixedHeap<SSituationInstance, 64> m_situationStorage;
    TMaxArray<SSituationInstance*, 64> m_situations;
    ZEvent<TEntityRef<ZSituationBase> const&, TEntityRef<ZActor> const&, ZEventNull, ZEventNull, ZEventNull> m_actorJoinEvent;
    ZEvent<TEntityRef<ZSituationBase> const&, TEntityRef<ZActor> const&, ZEventNull, ZEventNull, ZEventNull> m_actorLeaveEvent;
};
