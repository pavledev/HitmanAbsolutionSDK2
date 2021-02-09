#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZBoxVolumeEntity.h"
#include "ZSpawnPointEntity.h"
#include "ZAgitatedGuardPointEntity.h"
#include "ZGuardPointEntity.h"
#include "ZBystanderPointEntity.h"
#include "ZAgitatedPatrolEntity.h"
#include "ECombatZoneState.h"

class alignas(8) ZCombatZoneEntity : public ZEntityImpl
{
public:
    int m_nZoneIndex;
    bool m_bNoStanddown;
    bool m_bWarZone;
    TArray<TEntityRef<ZBoxVolumeEntity>> m_Volumes;
    TArray<TEntityRef<ZSpawnPointEntity>> m_spawnPoints;
    TArray<TEntityRef<ZAgitatedGuardPointEntity>> m_agitatedGuardPoints;
    TArray<TEntityRef<ZGuardPointEntity>> m_guardPoints;
    TArray<TEntityRef<ZBystanderPointEntity>> m_bystanderPoints;
    TArray<TEntityRef<ZAgitatedPatrolEntity>> m_PatrolRoutes;
    bool m_bActivated;
    ZGameTime m_triggerTime;
    ZGameTime m_engageTime;
    ECombatZoneState m_eZoneState;
};
