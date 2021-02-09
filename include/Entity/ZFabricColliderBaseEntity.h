#pragma once

#include "ZBoundedEntity.h"
#include "IFabricColliderEntity.h"
#include "IFabricEntity.h"

class ZFabricColliderBaseEntity : public ZBoundedEntity, public IFabricColliderEntity
{
public:
    bool m_bEnabled;
    bool m_bGlobal;
    TArray<TEntityRef<IFabricEntity>> m_FabricEntities;
    __int8 m_bActivated : 1;
    __int32 m_type : 3;
};
