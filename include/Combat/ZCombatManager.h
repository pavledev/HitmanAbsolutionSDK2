#pragma once

#include "TArray.h"
#include "TEntityRef.h"
#include "ZActor.h"
#include "ZCombatActEntity.h"
#include "ZCombatAttractorEntity.h"

class ZCombatManager
{
public:
    TArray<TEntityRef<ZActor>> m_aCombatActListenerActors;
    TArray<ZDelegate<void __cdecl(TEntityRef<ZCombatActEntity> const&, int)>> m_aCombatActListenerDelegates;
    TArray<TEntityRef<ZCombatAttractorEntity>> m_aAttractorEntities;
    TArray<TEntityRef<ZCombatActEntity>> m_aActEntities;
    TArray<ZGameTime> m_aActQuarantineEndTime;

    virtual ~ZCombatManager();
};
