#pragma once

#include "ZSituationGroup.h"
#include "ZCombatZoneEntity.h"

class ZGuardPointGroup : public ZSituationGroup
{
public:
    bool m_bGroupEngaged;
    TEntityRef<ZCombatZoneEntity> m_combatZone;
    TEntityRef<ZGuardPointEntity> m_guardPointEntity;
    ZGameTime m_tGroupTime;
};
