#pragma once

#include "ZSpatialEntity.h"
#include "EBystanderPointType.h"
#include "ZActor.h"
#include "ZResourcePtr.h"

class ZBystanderPointEntity : public ZSpatialEntity
{
public:
    EBystanderPointType m_eType;
    TEntityRef<ZActor> m_pPreferredActor;
    ZResourcePtr m_pGizmo;
    bool m_bHideOnStart;
    bool m_bPreferredActorIgnoreDanger;
    bool m_bEnabled;
    TEntityRef<ZActor> m_pReservedBy;
};
