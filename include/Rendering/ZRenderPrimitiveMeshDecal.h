#pragma once

#include "IRenderPrimitiveMesh.h"

class alignas(16) ZRenderPrimitiveMeshDecal : public IRenderPrimitiveMesh
{
public:
    unsigned __int16 m_nDecalSlot;
    IRenderPrimitiveMesh* m_pAttachedTo;
};
