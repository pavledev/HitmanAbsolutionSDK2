#pragma once

#include "ZRenderGraphNode.h"
#include "TArray.h"
#include "ZRenderPrimitiveInstance.h"

class alignas(16) ZRenderGraphNodePrimitiveContainer : public ZRenderGraphNode
{
public:
    unsigned __int16 m_nRuntimeDecal;
    TArray<ZRenderPrimitiveInstance> m_PrimitiveInstances;
    unsigned int m_nPrimitiveChangeCounter;
    char m_nPrimitiveFlags;
    char m_nMaxLODIndex;
    char m_nGlowType;
    char m_nGlowAmount;
    float m_fLODScale;
    float m_fLODOffset;
    TArray<ZRenderGraphNodeMaterial*> m_pMaterialModifiers;
    ZRenderGraphNodeMaterial* m_pOverrideMaterial;
    ZRenderGraphNodePrimitiveContainer* m_pNextPendingUpdate;
};
