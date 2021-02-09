#pragma once

#include "ZRenderGraphNode.h"
#include "SMatrix.h"
#include "float4.h"
#include "TArray.h"
#include "SVector3.h"
#include "SVector4.h"
#include "SVector2.h"
#include "ZRuntimeResourceID.h"
#include "TResourcePtr.h"
#include "ZRenderTextureResource.h"
#include "SLightMinMaxGrid.h"

class alignas(16) ZRenderGraphNodeLight : public ZRenderGraphNode
{
public:
    SMatrix m_mShadowProjection;
    float4 m_vDiffuseColor;
    float4 m_vNearFarAttenuation;
    float4 m_vProjectorMapTilingAndOffset;
    float4 m_vProjectionBoxHalfSize;
    TArray<ZRenderGraphNode*> m_VisibilityProxyNodes;
    TArray<ZRenderGraphNode*> m_AntiProxyNodes;
    unsigned int m_nLightDescMask;
    float m_fLightFadeIntentity;
    float m_fLightSimplificationFactor;
    float m_fMaxRange;
    float m_fMinAngle;
    float m_fMaxAngle;
    SVector3 m_vBoxHalfSize;
    SVector3 m_vBoxFadeNeg;
    SVector3 m_vBoxFadePos;
    SVector4 m_vCSMCascadeSplits;
    SVector3 m_vCSMSplitFades;
    SVector3 m_vDirectionalRotation;
    SVector2 m_vProjectorMapUVVelocity;
    float m_fAspectXByY;
    float m_fShadowFadeDistance;
    float m_fRcpShadowFadeLength;
    float m_fLightBleedingReduction;
    float m_fLightFadeDistance;
    float m_fRcpLightFadeLength;
    float m_fLightSimplificationDistance;
    float m_fRcpLightSimplificationLength;
    float m_fCapsuleHalfHeight;
    float m_fProjectedAreaCullingFactor;
    ZRuntimeResourceID m_idProjectorMap;
    TResourcePtr<ZRenderTextureResource> m_pProjectorMap;
    ZRenderShaderResourceView* m_pProjectorMapSRV;
    SLightMinMaxGrid* m_pMinMaxGrid;
    unsigned __int16 m_nLightIndex;
    __int16 m_nProjectorMapIndex;
    __int16 m_nPriorityQueryIndex;
    char m_nShadowMapIndex;
    bool m_bEnableGI;
    float m_fGIIntensity;

    struct
    {
        union
        {
            struct
            {
                unsigned __int16 nFlag;
                unsigned __int16 Rooms[3];
            } Static;

            struct
            {
                unsigned __int16 nFlag;
                unsigned __int16 AllocatedSize;
                unsigned __int16* AllocatedRoomPtr;
            } Dynamic;
        };

    } m_DynamicRooms;
};
