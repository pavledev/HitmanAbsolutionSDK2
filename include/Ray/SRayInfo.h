#pragma once

#include "float4.h"
#include "ZEntityRef.h"
#include "TEntityRef.h"
#include "ZSpatialEntity.h"
#include "TResourcePtr.h"
#include "ZRenderMaterialInstance.h"

class SRayInfo
{
public:
    float4 m_vFromLocal;
    float4 m_vToLocal;
    float4 m_vPosition;
    float4 m_vNormal;
    float4 m_vDecalPosition;
    float4 m_vDecalNormal;
    ZEntityRef m_rBlockingEntity;
    TEntityRef<ZSpatialEntity> m_rBlockingSpatialEntity;
    TResourcePtr<ZRenderMaterialInstance> m_pBlockingMaterial;
};
