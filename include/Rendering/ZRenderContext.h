#pragma once

#include "SMatrix.h"
#include "ZRenderDevice.h"
#include "IRenderDestination.h"
#include "SRenderDrawMode.h"
#include "ERenderLayer.h"
#include "ZRenderGBuffer.h"
#include "ZRenderGraphNodeCamera.h"
#include "SLightCascadeCSMData.h"
#include "SLightPriorityQuery.h"

class ZRenderSharedResources;

class ZRenderContext
{
public:
    SMatrix m_ScaleformProjectionMatrix;
    ZRenderDevice* m_pRenderDevice;
    ZRenderSharedResources* m_pRenderSharedResources;
    ZRenderShaderResourceView* m_pRefractionSRV;
    ZRenderShaderResourceView* m_pRefractionMaskSRV;
    ZRenderShaderResourceView* m_pReflectionSRV;
    IRenderDestination* m_pRenderDestination;
    SRenderDrawMode m_DrawMode;
    bool m_bDeferredRendering;
    bool m_bMirrorRendering;
    bool m_bIsMainRenderTarget;
    bool m_bMaterialHasVertexShader;
    float m_fCSMDisabled;
    ERenderLayer m_eRenderLayer;
    ERenderPrimitiveTopology m_ePrimitiveTopology;
    //SRenderRuntimePrimitiveInstance* m_pRenderPrimitiveInstance;
    void* m_pRenderPrimitiveInstance;
    ZRenderGBuffer* m_pGBuffer;
    ZRenderShader* m_pShaderF;
    ZRenderShader* m_pShaderV;
    ZRenderConstBufferRef m_ConstBufferF;
    ZRenderConstBufferRef m_ConstBufferV;
    ZRenderConstBufferRef m_PerViewConstBuffer;
    ZRenderRasterizerState* m_OverrideRasterizerState;
    ZRenderDepthStencilState* m_OverrideDepthStencilState;
    ZRenderBlendState* m_OverrideBlendState;
    ZRenderGraphNodeCamera* m_pActiveCamera;
    unsigned int m_nLightIndex[1];
    SMatrix m_mViewToWorld;
    SMatrix m_mWorldToView;
    SMatrix m_mWorldToViewPrev;
    SMatrix m_mViewToProjection;
    SMatrix m_mFPSViewToProjection;
    SRenderViewport m_Viewport;
    float4 m_vEyePoint;
    float4 m_vGlobalLitFactor;
    float m_fEyeRadius;
    float m_fFovY;
    float m_fStableFovY;
    float m_fNearZ;
    float m_fFarZ;
    float m_fClipDistanceScale;
    float m_fLightIntensity;
    float4 m_vLODZoomFactor;
    float4 m_vPerObjectSimpleColor;
    unsigned int m_nStencilRef;
    int m_nNumOverlappingRooms;
    unsigned int m_nOverlappingRooms[32];
    float4 m_vViewClipPlane;
    float4 m_vWorldClipPlane;
    unsigned int m_nGateTraversalDepth;
    bool m_bEmissiveOnly;
    bool m_bDrawCrowd;
    bool m_bDrawScatter;
    bool m_bStereoLeftEye;
    bool m_bStereoscopic;
    SLightCascadeCSMData m_CSMCascadeData[3];
    SMatrix m_mCSMProj;
    SLightPriorityQuery m_PriorityQueries[256];
    unsigned __int16 m_nStartRoom;
    bool m_bUseSimpleRendering;
    bool m_bUseFPSLocalSpace;
    char m_nUsingLODIndex;
    float m_fSSAOFarDistance;
    float m_fGlowAmount;
};
