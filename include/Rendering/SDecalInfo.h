#pragma once

#include "ZRenderGraphNodePrimitiveContainer.h"
#include "IRenderPrimitiveMesh.h"
#include "ZDecalControllerEntity.h"
#include "ZRenderPrimitiveMeshDecal.h"

class alignas(16) SDecalInfo
{
public:
    unsigned int nIdxSize;
    unsigned __int16 nInstallSlot;
    unsigned int nVtxAllocOffset;
    unsigned int nVtxAllocSize;
    unsigned int nIdxOffset;
    unsigned int nVtxOffset;
    unsigned __int16 nNumIdx;
    unsigned __int16 nNext;
    unsigned __int16 nPrev;
    unsigned __int16 nNodeNext;
    unsigned __int16 nNodePrev;
    ZRenderGraphNodePrimitiveContainer* pRGN;
    IRenderPrimitiveMesh* pAttachedTo;
    ZDecalControllerEntity* pDecalController;
    ZRenderPrimitiveInstance RenderPrimitiveInstance;
    ZRenderPrimitiveMeshDecal DecalMesh;
    float fFadeTimeLeft;
    float fCurScaleTime;
    unsigned int nColor;
    __int8 nList : 1;
    __int8 bFading : 1;
    __int8 bStale : 1;
    __int8 bActive : 1;
};
