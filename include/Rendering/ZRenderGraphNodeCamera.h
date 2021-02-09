#pragma once

#include "ZRenderGraphNode.h"
#include "SMatrix.h"
#include "ZRenderGraphNodePostfilterController.h"
#include "SRenderCameraSupportBuffers.h"
#include "ZRenderGBuffer.h"
#include "TEntityRef.h"
#include "ZRenderableEntity.h"
#include "SQV.h"
#include "SRoomInsideOutsideInfo.h"
#include "ZRenderDebugRenderBuffer.h"

class ZRenderGraphNodeCamera : public ZRenderGraphNode
{
public:
    SMatrix m_mObjectToWorldPrev;
    SMatrix m_mProjection;
    SMatrix m_mFPSProjection;
    float4 m_vClearColor;
    float4 m_vCurrentRoomReferencePos;
    unsigned int m_nWidth;
    unsigned int m_nHeight;
    int m_nEnableMsaa;
    int m_nEnableDOFOverride;
    float m_fFovY;
    float m_fBaseFovY;
    float m_fGateClipDistanceScale;
    float m_fStableFovY;
    float m_fLODZoomFactor;
    float m_fWidth;
    float m_fAspectWByH;
    float m_fNearZ;
    float m_fFarZ;
    float m_fMaxDistToNearPlane;
    ZRenderGraphNodePostfilterController* m_pPostfilter;
    TArray<ZRenderGraphNode*> m_OSDNodes;
    SRenderTempTexture2DAccess m_RenderTarget;
    bool m_bReallocate;
    unsigned int m_nUnused;
    ZRenderTargetView* m_CurrentRTV;
    SRenderTempTexture2DAccess m_RenderTargetMsaa;
    ZRenderTexture2D* m_pRefractionTexture;
    ZRenderTargetView* m_pRefractionRTV;
    ZRenderShaderResourceView* m_pRefractionSRV;
    ZRenderTexture2D* m_pReflectionTexture;
    ZRenderTargetView* m_pReflectionRTV;
    ZRenderShaderResourceView* m_pReflectionSRV;
    ZRenderTexture2D* m_pSSGIBackbuffer;
    ZRenderShaderResourceView* m_pSSGIBackBufferSRV;
    ZRenderTexture2D* m_pGhostTexture;
    ZRenderTargetView* m_pGhostRTV;
    ZRenderShaderResourceView* m_pGhostSRV;
    ZRenderTexture2D* m_pGhostPongTexture;
    ZRenderTargetView* m_pGhostPongRTV;
    ZRenderShaderResourceView* m_pGhostPongSRV;
    SRenderCameraSupportBuffers m_SupportBuffers;
    ZRenderGBuffer* m_pGBuffer;
    ZRenderDebugRenderBuffer* m_pRenderDebugRenderBuffer;
    TEntityRef<ZRenderableEntity> m_pPostfilterControllerEntity;
    ZGameTime m_globalLightFadeStart;
    SVector3 m_vGlobalLightPrevAmbientUp;
    SVector3 m_vGlobalLightPrevAmbientDown;
    SVector3 m_vGlobalLightPrevBackColor;
    SVector3 m_vGlobalPrevLitFactor;
    SVector3 m_vGlobalLightAmbientUp;
    SVector3 m_vGlobalLightAmbientDown;
    SVector3 m_vGlobalLightBackColor;
    SVector3 m_vGlobalLitFactor;
    SVector3 m_vGlobalLightAmbientUpCurrent;
    SVector3 m_vGlobalLightAmbientDownCurrent;
    SVector3 m_vGlobalLightBackColorCurrent;
    SVector3 m_vGlobalLightPrevAmbientUpOutside;
    SVector3 m_vGlobalLightPrevAmbientDownOutside;
    SVector3 m_vGlobalLightPrevBackColorOutside;
    SVector3 m_vGlobalLightAmbientUpOutside;
    SVector3 m_vGlobalLightAmbientDownOutside;
    SVector3 m_vGlobalLightBackColorOutside;
    SVector3 m_vGlobalLightAmbientUpCurrentOutside;
    SVector3 m_vGlobalLightAmbientDownCurrentOutside;
    SVector3 m_vGlobalLightBackColorCurrentOutside;
    SVector3 m_vGlobalLitFactorCurrent;
    float m_fGIIntensity;
    SQV m_CameraCutLasTransform;
    SRoomInsideOutsideInfo m_InsideOutsideInfo;
    SRoomInsideOutsideInfo m_LastInsideOutsideInfo;
    float m_fGlowAmount;
    unsigned __int16 m_nStickyRoomId;
    unsigned __int16 m_nNumOverlappingRooms;
    unsigned __int16 m_aOverlappingRooms[32];
    unsigned __int16 m_nInsideGate;
    __int8 m_bActive : 1;
    __int8 m_bAllocated : 1;
    __int8 m_bIsOrtho : 1;
    __int8 m_bCameraBufferAllocated : 1;
    __int8 m_bRainVisibleLastFrame : 1;
    __int8 m_bRainRefraction : 1;
    __int8 m_bSeperateFPSFov : 1;
    __int8 m_bGlowActive : 1;
    __int8 m_bHintsActive : 1;
    __int8 m_bFPSDrawLocal : 1;
};
