#pragma once

#include "ZSpatialEntity.h"
#include "ZResourcePtr.h"

class alignas(4) ZCombatAttractorEntity : public ZSpatialEntity
{
public:
    ZResourcePtr m_pGizmo;
    bool m_bActivateOnStart;
    float m_fRange;
    bool m_bIsActive;
};
