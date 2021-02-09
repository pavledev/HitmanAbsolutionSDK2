#pragma once

#include "float4.h"
#include "SMatrix.h"
#include "SOccluderPlaneStateSoA.h"
#include "SVector3.h"
#include "SMatrix43.h"
#include "SGateInfoHeader.h"

class SCrowdCullingContext
{
public:
    bool m_bHasValidCrowdData;
    float m_nVisualRadius;
    float m_nVisualLargeRadius;
    float m_nCrowdRenderDist;
    float4 m_vCrowdLODDistances;
    unsigned int m_nMaxNumVisibleCharacters;
    unsigned int m_nMaxLODCounts[4];
    SMatrix m_mCrowdWorldMatrix;
    float4 m_vCrowdSpaceToLocalSpace;
    bool m_bHasValidCameraData;
    float4 m_vEyePoint;
    float4 m_vLODZoomFactor;
    float4 m_aFrustumPlanes[6];
    SOccluderPlaneStateSoA m_OccluderPlaneState;
    bool m_bInCrowdRoom;
    SVector3 m_vOBBCenter;
    SVector3 m_vOBBHalfSize;
    SMatrix43 m_mOBBTransform;
    unsigned int m_nGates;
    SGateInfoHeader m_aCrowdGates[4];
};
