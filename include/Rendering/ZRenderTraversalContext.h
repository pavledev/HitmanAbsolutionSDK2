#pragma once

#include "STraversalSortedIndex.h"
#include "float4.h"
#include "SMatrix.h"
#include "STraversalTaskInput.h"

class ZRenderTraversalContext
{
    STraversalSortedIndex m_SortedIndices[32];
    float4 m_avClipPlanes[32];
    float4 m_vEyePoint;
    float4 m_vRoomPoint;
    SMatrix mViewToProjectionMatrix;
    SMatrix mWorldToView;
    unsigned __int64 m_nBookmark;
    STraversalTaskInput* m_pTaskInput;
    unsigned int m_nNumClipPlanes;
    float m_fProjectedAreaCullingFactor;
    unsigned int m_nMaxTraversalDepth;
    unsigned __int16 m_nRoomID;
    unsigned __int16 m_nOverrideStartRoomId;
    bool m_bMainCameraTraversal;
    bool m_bAsyncTraversalStarted;
    bool m_bUsePortalClipplanes;
    bool m_bSimpleTraversal;
    bool m_bTraversalStarted;
    TArray<ZRenderGraphNode*> m_visibleNodes;
    TArray<ZRenderGraphNode*> m_Nodes;
    TArray<unsigned short> m_VisibleGates;
    SOccluderPlaneStateSoA m_OccluderPlaneState;
};
