#pragma once

#include "IRenderPrimitiveMesh.h"
#include "TRefCountPtr.h"
#include "SVertexGeneric.h"

class ZRenderDynamicMesh
{
public:
    TRefCountPtr<IRenderPrimitiveMesh> m_pRenderPrimitiveMesh;
    TArray<SVertexGeneric> m_aVertices;
    TArray<unsigned short> m_aIndices;
    float4 vMin;
    float4 vMax;
};
