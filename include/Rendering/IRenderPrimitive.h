#pragma once

#include "IRenderRefCount.h"
#include "TRenderReferencedCountedImpl.h"
#include "float4.h"
#include "TResourcePtr.h"
#include "ZRenderMaterialInstance.h"
#include "SRenderPrimitiveMeshDesc.h"
#include "ZRenderContext.h"
#include "ZAnimationBonePose.h"
#include "ZAnimationBoneData.h"

class IRenderPrimitive : public TRenderReferencedCountedImpl<IRenderRefCount, 0>
{
public:
    float4 m_vPosScale;
    float4 m_vPosBias;
    float4 m_vTexScaleBias;
    float4 m_vMin;
    float4 m_vMax;
    TResourcePtr<ZRenderMaterialInstance> m_pMaterial;
    ZRenderMaterialInstance* m_pMaterialInstance;
    unsigned int m_nNumIndicesToDraw;
    unsigned int m_nWireColor;
    TBag<ZDelegate<void __cdecl(void)>, TArray<ZDelegate<void __cdecl(void)>>> m_ChangedEventHandlers;
    unsigned __int8 m_nLODMask;
    unsigned __int8 m_nZBias;
    unsigned __int8 m_nZOffset;
    unsigned __int8 m_nAxisLockedMask : 3;
    __int8 m_bUseMaterialStatusChangedCallbacks : 1;
    __int8 m_bInsideBeginUpdate : 1;
    unsigned __int8 m_nType;
    ZRenderVertexBuffer* m_pVertexBuffers[3];
    ZRenderIndexBuffer* m_pIndexBuffer;
    ZRenderInputLayout* m_pInputLayout;
    SRenderPrimitiveMeshDesc m_Description;

    virtual void DrawNew(ZRenderContext*);
    //virtual void DrawDebug(ZDebugRender*, const SMatrix*, bool, const ZAnimationBonePose*, const ZAnimationBoneData*, const bool*);
    virtual void DrawDebug(void*, const SMatrix*, bool, const ZAnimationBonePose*, const ZAnimationBoneData*, const bool*);
};
