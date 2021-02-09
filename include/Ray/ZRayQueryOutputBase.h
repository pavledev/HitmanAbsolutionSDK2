#pragma once

#include "float4.h"
#include "TResourcePtr.h"
#include "ZRenderMaterialInstance.h"

class alignas(16) ZRayQueryOutputBase
{
public:
    float4 m_vPosition;
    float4 m_vNormal;
    float m_nT;
    TResourcePtr<ZRenderMaterialInstance> m_pBlockingMaterial;
    char m_nIntersectedBoneMeshId;
    bool m_bHasHit;
};
