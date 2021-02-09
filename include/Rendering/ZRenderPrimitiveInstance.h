#pragma once

#include "IRenderPrimitive.h"
#include "ZRenderGraphNodeMaterial.h"

class ZRenderPrimitiveInstance
{
public:
    IRenderPrimitive* m_pRenderPrimitive;
    ZRenderGraphNodeMaterial* m_pOverrideMaterial;
    unsigned int m_nLayerMask;
    char m_nLODMask;
    unsigned __int16 m_nTransparencyMask;
};
