#pragma once

#include "STraversalRoomState.h"
#include "SOccluderPlaneStateSoA.h"
#include "STraversalGateVisit.h"
#include "STraversalRoomVisit.h"
#include "float4.h"
#include "STraversalClipPlanesOffset.h"
#include "STraversalArrayVisitDesc.h"
#include "ZRenderGraphNode.h"
#include "STraversalSortedIndex.h"
#include "SMatrix.h"
#include "SRoomInfoHeader.h"
#include "SGateInfoHeader.h"
#include "SVolumeBounds.h"
#include "SOccluder.h"
#include "IJob.h"
#include "ZMutex.h"
#include "IJobChain.h"

class alignas(16) STraversalTaskInput
{
    STraversalRoomState State;
    SOccluderPlaneStateSoA OccluderState;
    STraversalGateVisit* pGateVisits;
    STraversalRoomVisit* pRoomVisits;
    float4* pClipPlanesSOABuffer;
    STraversalClipPlanesOffset* pClipPlanesOffset;
    STraversalArrayVisitDesc* pVisitArray;
    ZRenderGraphNode** VisibleNodes;
    unsigned __int16* VisibleGates;
    STraversalSortedIndex* NodeSortIndices;
    SMatrix mWorldToViewProj;
    float4 vEyePoint;
    float4 vRoomPoint;
    float4 InitialClipPlanes[32];
    float4 aCSMClipPlanes[3][8];
    SRoomInfoHeader* pRoomHeaders;
    SGateInfoHeader* pGateHeaders;
    unsigned int nNumRoomHeaders;
    unsigned int nNumGateHeaders;
    SVolumeBounds* pExcludes;
    SVolumeBounds* pIncludes;
    unsigned int nNumExcludes;
    unsigned int nNumIncludes;
    SOccluder* pOccluders;
    float4* EdgeOccluders;
    unsigned __int16* ActiveOccluderIndices;
    unsigned int nNumOccluders;
    ZRenderGraphNode** RoomIgnores;
    unsigned int nNumRoomIgnores;
    ZRenderGraphNode** ParticleNodes;
    unsigned int nNumParticleNodes;
    unsigned int nInitialClipPlanes;
    float fGlobalGateClipDistance;
    float fGateClipDistanceScale;
    float fProjectedScreenAreaThreshold;
    float fCSMProjectedAreaCullingFactor;
    float fSlack;
    unsigned int nRequiredFlags;
    STraversalTaskInput* nSelfEa;
    unsigned int nBreakOnAccept;
    unsigned __int16 nMaxTraversalDepth;
    unsigned __int16 nRoomId;
    unsigned __int16 nOverrideStartRoomId;
    char nMaxOccluders;
    bool bReverseGates;
    char nEdgeOccluderFixup;
    bool bUseProjectedArea;
    bool bUsePortalClipplanes;
    char nBreakFlag;
    char nMode;
    bool bRemoveDuplicateOccluders;
    ZRenderGraphNode** ppNodes;
    IJob* pJob;
    ZMutex Mutex;
    IJobChain* JobChain;
    IJob* SubJobs[3];
};
