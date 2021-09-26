#pragma once

#include "TPriorityQueue.h"
#include "TQueue.h"
#include "TFixedArray.h"
#include "ERenderLayer.h"
#include "TArray.h"
#include "TBlockArray.h"
#include "ZRenderConstBufferRef.h"

struct SRenderShadowUpdateContext;
struct SRenderDrawFilterEntry;
struct SEffectParametersSimple;
class IRenderPrimitive;
struct S_cbSharedPerViewData;
class SDeferredLightTechniqueParameters;
struct S_cbSharedLightData;
class ZRenderGBuffer;
struct SRenderGatherContext;
struct SRenderCameraSupportBuffers;
struct SRenderTempTexture2DAccess;
struct SRenderTexture2DAccess;
class ZRenderContext;
class ZRenderDepthStencilView;
class ZRenderDevice;
class ZRenderGraphNode;
class ZRenderGraphNodeLight;
class ZRenderGraphTraversal;
class ZRenderShaderResourceView;
class ZRenderTargetView;
class ZRenderTexture2D;
class ZRenderTraversalContext;
struct SLightBundle;
struct SMatrix;
struct SRenderGraphNodeLight;
struct SRenderShadowMapInfo;
struct SRenderViewport;
struct float4;

class ZRenderGraphNodeRenderer
{
public:
	enum EStencilUpdateType
	{
		SVB_VOLUME_INCREMENT = 1,
		SVB_VOLUME_DECREMENT = 2
	};

	enum EDrawFaceFlags
	{
		DFF_BACK = 1,
		DFF_TWOSIDED = 2
	};

	enum ELightStencilRefs
	{
		SREF_LIGHT = 0
	};

	TPriorityQueue<SRenderGraphNodeLight, TArray<SRenderGraphNodeLight>> m_lights;
	TPriorityQueue<SRenderGraphNodeLight, TArray<SRenderGraphNodeLight>> m_darklights;
	TQueue<SRenderShadowMapInfo*, TBlockArray<SRenderShadowMapInfo*>> m_ShadowFadeQueue;
	TFixedArray<SLightBundle, 256> m_lightBundles;
	TFixedArray<SLightBundle, 256> m_reflectionLightBundles;
	TFixedArray<SLightBundle, 256> m_darklightBundles;
	unsigned int m_nDarkLightIndex;
	ZRenderDevice* m_pRenderDevice;
	ZRenderConstBufferRef m_ConstBufferLightingV;
	ZRenderConstBufferRef m_ConstBufferLightingF;
	ZRenderConstBufferRef m_PerViewSharedData;
	ZRenderConstBufferRef m_PerViewSharedData2;

	ZRenderGraphNodeRenderer() = default;
	ZRenderGraphNodeRenderer(ZRenderDevice* pRenderDevice);
	~ZRenderGraphNodeRenderer() = default;
	void ResolveGBuffer(ZRenderGBuffer* pGBuffer);
	unsigned int GetNumDarkLightBundles();
	void UpdateReflectionTexture(ZRenderGBuffer* pGBuffer, const SRenderViewport& vp, ZRenderTargetView* pReflectionRTV, ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderTraversalContext* pParentTraversalContext, ZRenderContext* pRenderContext, TArray<ZRenderGraphNode*>& nodes);
	unsigned int CalculateLightBundles(SRenderGatherContext* pGatherContext, ZRenderContext* pRenderContext, ZRenderGraphTraversal* pRenderGraphTraversal);
	void DrawShadowMap(SRenderShadowUpdateContext* pShadowContext);
	void BeginShadowMapGetVisible(const SMatrix& mProjection, const SMatrix& mWorldToLight, TArray<ZRenderGraphNode*>& CameraVisibleNodes, ZRenderGraphNodeLight* pLight, ZRenderContext* pRenderContext, ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderTraversalContext* pTraversalContextCasters, unsigned int nClipPlanes, float4* pCSMData);
	void EndShadowMapGetVisible(ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderTraversalContext* pContext);
	void KickLightShadow2DTraversal(ZRenderGraphNode* pNode, ZRenderTraversalContext* pTraversalContext, ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderContext* pRenderContext);
	void KickLightShadowOmniTraversal(ZRenderGraphNode* pNode, ZRenderTraversalContext* pTraversalContext, ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderContext* pRenderContext);
	void KickLightShadowCSMTraversal(ZRenderGraphNode* pNode, ZRenderTraversalContext* pTraversalContext, ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderContext* pRenderContext);
	unsigned int UpdateLightShadow2D(ZRenderGraphNode* pNode, ZRenderTraversalContext* pTraversalContext, ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderContext* pRenderContext, ZRenderConstBufferRef SharedLightDataConstBuffer);
	unsigned int UpdateLightShadowOmni(ZRenderGraphNode* pNode, ZRenderTraversalContext* pTraversalContext, ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderContext* pRenderContext, ZRenderConstBufferRef SharedLightDataConstBuffer);
	unsigned int UpdateLightShadowCSM(ZRenderGraphNode* pNode, ZRenderTraversalContext* pTraversalContext, ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderContext* pRenderContext, ZRenderConstBufferRef SharedLightDataConstBuffer);
	unsigned int CalculateCSMZRange_SLOW(ZRenderGraphNode* pNode, ZRenderTraversalContext* pTraversalContext, ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderContext* pRenderContext);
	void DrawLightingLayer(unsigned int nNumBundles, ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderTraversalContext* pTraversalContext, ZRenderContext* pRenderContext, ZRenderTargetView* pRTV, ZRenderDepthStencilView* pDSV, bool bDarkLight, bool bGlobalLightFirst);
	void DrawFPS(SRenderDrawFilterEntry* pFPSDrawList, unsigned int nNumFPSEntries, ZRenderContext* pRenderContext, ZRenderGraphTraversal* pRenderGraphTraversal, unsigned int nDrawMask, ZRenderTraversalContext* pTraversalContext, ERenderLayer eRenderLayer);
	void DrawFPSDecals(SRenderDrawFilterEntry* pFPSDrawList, unsigned int nNumFPSEntries, ZRenderContext* pRenderContext, ZRenderGraphTraversal* pRenderGraphTraversal, unsigned int nDrawMask, ZRenderTraversalContext* pTraversalContext, ERenderLayer eRenderLayer);
	void ClearBackground(ZRenderContext* pRenderContext, SRenderViewport& vp, const float4& vClearColor) const;
	void CalculateBoundingRect(float4& vDeviceMin, float4& vDeviceMax, const float4* pViewVertices, unsigned int nNumVertices, const SMatrix& mProjection, const SRenderViewport& viewport) const;
	void CalculateCornerEyeVectorsVS(float4& vEyeUpperLeft, float4& vEyeLowerRight, const SMatrix& mProjection, float fNearPlane) const;
	void DrawStencilVolume(SEffectParametersSimple& pEffect, IRenderPrimitive* pRenderPrimitive, unsigned int nStencilUpdateType, unsigned int nInsideFlag, unsigned int nStencilRef, ZRenderContext* pRenderContext) const;
	void RenderRefractive(SRenderDrawFilterEntry* pInputEntries, unsigned int nNumInputEntries, ZRenderContext* pRenderContext, ZRenderTraversalContext* pTraversalContext, ZRenderGraphTraversal* pRenderGraphTraversal, const SRenderViewport& vp, ZRenderShaderResourceView* pSRV, ZRenderTargetView** pRTV, ZRenderDepthStencilView* pDSV, ZRenderTexture2D*& pRefractionTexture, ZRenderShaderResourceView*& pRefractionSRV, bool bRainRefraction, SRenderGatherContext* pGatherContext);
	void RenderDeferredParticles(ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderTraversalContext* pTraversalContext, ZRenderContext* pRenderContext);
	void RenderRainDeferred(ZRenderGBuffer* pGBuffer, ZRenderShaderResourceView* pGbuffer0SRV, ZRenderContext* pRenderContext, ZRenderTraversalContext* pTraversalContext, ZRenderGraphTraversal* pRenderGraphTraversal, SRenderGatherContext* pGatherContext, ZRenderTargetView* pRTV, ZRenderDepthStencilView* pDSV);
	void RenderRainParticles(ZRenderGBuffer* pGBuffer, ZRenderContext* pRenderContext, ZRenderTraversalContext* pTraversalContext, ZRenderGraphTraversal* pRenderGraphTraversal, SRenderGatherContext* pGatherContext, ZRenderTargetView* pRTV, ZRenderDepthStencilView* pDSV, ZRenderShaderResourceView* _pRefractionSRV);
	void RenderCharacterRain(TArray<ZRenderGraphNode*>& RainCharacterNodes, ZRenderContext* pRenderContext, ZRenderTraversalContext* pTraversalContext, ZRenderGraphTraversal* pRenderGraphTraversal, const SRenderViewport& vp, ZRenderShaderResourceView* pSRV, ZRenderTargetView** pRTV, ZRenderDepthStencilView* pDSV, ZRenderShaderResourceView* pGbuffer0SRV, SRenderGatherContext* pGatherContext);
	void RenderLetterbox(ZRenderContext* pRenderContext, const float4& vColor);
	void RenderFade(ZRenderContext* pRenderContext, const float4& vColor);
	void DrawOSD(ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderContext* pRenderContext, TArray<ZRenderGraphNode*>& OSDNodes, S_cbSharedPerViewData* pSharedPerViewdata);
	static void DrawScaleform(ZRenderDevice* pRenderDevice, ZRenderContext* pContext);
	void DrawOSDAndScaleformNoRT(ZRenderContext* pRenderContext, TArray<ZRenderGraphNode*>& OSDNodes, ZRenderGraphTraversal* pRenderGraphTraversal, S_cbSharedPerViewData* pSharedPerViewData);
	void DrawOSDAndScaleform(ZRenderContext* pRenderContext, ZRenderTargetView* pRTV, ZRenderDepthStencilView* pDSV, TArray<ZRenderGraphNode*>& OSDNodes, ZRenderGraphTraversal* pRenderGraphTraversal);
	void RenderMsaaEdgeDetect(ZRenderContext* pRenderContext);
	void RenderDrawRed(ZRenderContext* pRenderContext);
	void RenderDrawGreen(ZRenderContext* pRenderContext);
	void RenderGlobalLight(ZRenderContext* pRenderContext, bool bUseOutsideGlobal, const float4& vAmbientUp0, const float4& vAmbientUp1, const float4& vAmbientDown0, const float4& vAmbientDown1, const float4& vBackColor0, const float4& vBackColor1, ZRenderShaderResourceView* pOcclusionSRV, ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderTargetView* pRTV, ZRenderDepthStencilView* pDSV, ZRenderShaderResourceView* pDSRV, SRenderCameraSupportBuffers* pCameraSupportBuffers, bool bGlobalLightFirst);
	void RenderVolumeLight(ZRenderContext* pRenderContext, ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderTargetView* pRTV, ZRenderDepthStencilView* pDSV, SRenderGatherContext* pGatherContext, SRenderCameraSupportBuffers* pCameraSupportBuffers, SRenderTempTexture2DAccess* pHalfResTexture, float fTonemapScale, SRenderTexture2DAccess* pFinalQuarterRezTex, bool bGlare);
	void SetupSharedPerViewData(ZRenderContext* pRenderContext) const;
	void SetupSharedPerViewData(ZRenderContext* pRenderContext, S_cbSharedPerViewData* pPerSharedViewData) const;
	static void SetRenderContextOSD(ZRenderContext* pRenderContext);
	void DrawGates(ZRenderTraversalContext* pTraversalContext, ZRenderContext* pRenderContext, float fGateClipDistanceScale);
	void GenerateCameraSupportBuffers(SRenderCameraSupportBuffers* pCameraSupportBuffers, ZRenderContext* pRenderContext);
	void GenerateAmbientOcclusionBuffers(ZRenderTargetView* pRTV, SRenderCameraSupportBuffers* pCameraSupportBuffers, ZRenderContext* pRenderContext);
	void GenerateSSGIBuffers(SRenderTempTexture2DAccess* pBackbuffer, ZRenderTexture2D* pSSGIBackbuffer, ZRenderShaderResourceView* pSSGIBackbufferSRV, ZRenderContext* pRenderContext);
	void ClearShadowFadeQueue();
	void SetLightTechniqueParameters(SDeferredLightTechniqueParameters& shaderParams, ZRenderContext* pRenderContext);
	void SetupSharedLightData(ZRenderGraphNodeLight* pLight, S_cbSharedLightData* pSharedLightData, ZRenderContext* pRenderContext, unsigned int nDataIndex, bool bUseLightRestrict);
	void SetupProjectorMap(ZRenderGraphNodeLight* pLight, unsigned int nDataIndex);
	void SetupShadowMap(ZRenderGraphNodeLight* pLight, ZRenderContext* pRenderContext, unsigned int nDataIndex);
	void SetupDeferredLightPerObjectData(ZRenderGraphNodeLight* pLight, ZRenderContext* pRenderContext);
	void CalculateMinimumEnclosingScreenBoundsLight(ZRenderGraphNodeLight* pLight, float4& vMin, float4& vMax, const SMatrix& mObjectToView, ZRenderContext* pRenderContext) const;
	void CalculateMinimumEnclosingScreenBoundsProxies(ZRenderGraphNodeLight* pLight, float4& vMin, float4& vMax, const SMatrix& mWorldToView, ZRenderContext* pRenderContext, const TArray<ZRenderGraphNode*>& VisibilityProxyNodes) const;
	void CalculateLightDepthBounds(ZRenderGraphNodeLight* pLight, float& fMin, float& fMax, ZRenderContext* pRenderContext) const;
	void DrawLightSourceStencil(ZRenderGraphNodeLight* pLight, SEffectParametersSimple& pEffect, IRenderPrimitive* pPrimitive, ZRenderContext* pRenderContext, unsigned int nInsideFlag);
	void DrawVisibilityProxiesStencil(SEffectParametersSimple& pEffect, ZRenderContext* pRenderContext, const TArray<ZRenderGraphNode*>& VisibilityProxyNodes, bool bAntiProxy) const;
	bool CalculateDirectionalCascadeData(const ZRenderGraphNodeLight* pLight, ZRenderContext* pRenderContext, const SMatrix& mCameraProjection, const SMatrix& mCameraToLightDir, const SMatrix& mLightDirProj, SMatrix* pmShadowProj, SMatrix* pmShadowPanProj, SMatrix* pmShadowInnerProj, unsigned int nSplit, unsigned int nUseOptimalZRange);
	unsigned int InsertDefaultLight(TFixedArray<SLightBundle, 256>& lightBundles, ZRenderContext* pRenderContext, ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderGraphNode** pTransLitNodes, unsigned int nNumTransLitNodes) const;
};
