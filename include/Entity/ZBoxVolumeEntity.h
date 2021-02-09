#pragma once

#include "ZBoundedEntity.h"
#include "IBoxVolumeEntity.h"
#include "TSList.h"
#include "ZResourcePtr.h"

class ZBoxVolumeEntity : public ZBoundedEntity, public IBoxVolumeEntity
{
public:
    SVector3 m_vGlobalSize;
    TSList<ZDelegate<void __cdecl(ZEntityRef const&)>> m_ChangeHandlerList;
    ZResourcePtr m_pHelper;
};
