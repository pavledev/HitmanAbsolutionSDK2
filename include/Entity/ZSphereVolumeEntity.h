#pragma once

#include "ZBoundedEntity.h"
#include "ITriggerVolume.h"
#include "TSList.h"
#include "ZResourcePtr.h"

class ZSphereVolumeEntity : public ZBoundedEntity, public ITriggerVolume
{
public:
    float m_fRadius;
    TSList<ZDelegate<void __cdecl(ZEntityRef const&)>> m_ChangeHandlerList;
    ZResourcePtr m_pHelper;
};
