#pragma once

#include "float4.h"
#include "TEntityRef.h"
#include "ZSpatialEntity.h"

class alignas(16) SInternalIndicator
{
public:
    float4 m_vPos;
    TEntityRef<ZSpatialEntity> m_rSpatialEntity;
    __int8 m_bActor : 1;
};
