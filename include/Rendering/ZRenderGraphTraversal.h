#pragma once

#include "float4.h"
#include "ZRenderDevice.h"
#include "ZRenderContext.h"
#include "ZRenderTraversalContext.h"
#include "SClipPlanes4.h"
#include "SRenderGatherContext.h"
#include "SRenderPrimitiveEntry.h"
#include "TMaxArray.h"

class alignas(16) ZRenderGraphTraversal
{
public:
    unsigned int m_nNumClipPlanes;
    float4 m_avClipPlanes[32];
    ZRenderDevice* m_pRenderDevice;
    ZRenderContext* m_pRenderContext;
    ZRenderTraversalContext* m_pTraversalContext;
    TArray<ZRenderGraphNode*> m_VisibleNodes;
    TFixedArray<SClipPlanes4, 8> m_aClipPlanes4;
    unsigned int m_nNumClipPlanesSoA;
    SRenderGatherContext* m_pGatherContext;
    TArray<SRenderPrimitiveEntry> m_TempPrimitiveEntries;
    TArray<ZRenderGraphNode*> m_TempRGNPtrArray;
    TMaxArray<STraversalTaskInput*, 32> m_TraversalTaskInput;
    IJobChain* m_JobChain;
    IJob* m_pCollectOpaqueJobs[4];
};
