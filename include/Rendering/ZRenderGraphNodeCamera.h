#pragma once

#include "ZRenderGraphNode.h"
#include "SMatrix.h"
#include "SRenderCameraSupportBuffers.h"
#include "TEntityRef.h"
#include "SQV.h"
#include "SRoomInsideOutsideInfo.h"
#include "SRenderTempTexture2DAccess.h"
#include "SVector3.h"
#include "TArray.h"
#include "ZGameTime.h"
#include "float4.h"

class ZRenderGraphNodeRainSurfaceSimulator;
class IJobChain;
class ZRenderContext;
class ZRenderDebugRenderBuffer;
class ZRenderGBuffer;
class ZRenderGraphNodePostfilterController;
class ZRenderGraphTraversal;
class ZRenderShaderResourceView;
class ZRenderTargetView;
class ZRenderTexture2D;
class ZRenderTraversalContext;
class ZRenderableEntity;
struct SRenderGatherContext;

class ZRenderGraphNodeCamera : public ZRenderGraphNode
{
public:
	enum
	{
		NUM_DEFERRED_BUFFERS = 5
	};

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
	unsigned short m_nStickyRoomId;
	unsigned short m_nNumOverlappingRooms;
	unsigned short m_aOverlappingRooms[32];
	unsigned short m_nInsideGate;
	bool m_bActive : 1;
	bool m_bAllocated : 1;
	bool m_bIsOrtho : 1;
	bool m_bCameraBufferAllocated : 1;
	bool m_bRainVisibleLastFrame : 1;
	bool m_bRainRefraction : 1;
	bool m_bSeperateFPSFov : 1;
	bool m_bGlowActive : 1;
	bool m_bHintsActive : 1;
	bool m_bFPSDrawLocal : 1;

	~ZRenderGraphNodeCamera() override = default;
	void Traverse(ZRenderGraphNode* pParent, ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderTraversalContext* pTraversalContext, ZRenderContext* pRenderContext) override;
	void Reflect(ZRenderableEntity* pRenderableEntity, IJobChain* pJobChain) override;

	ZRenderGraphNodeCamera() = default;
	ZRenderGraphNodeCamera(ZRenderGraphNode::TYPE eType);
	void TraverseInternal(ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderTraversalContext* pTraversalContext, ZRenderContext* pRenderContext);
	SMatrix GetCameraProjectionMatrix(ZRenderContext* pRenderContext);
	SMatrix GetFPSCameraProjectionMatrix(ZRenderContext* pRenderContext);
	void FreeTempAlloc();
	const SMatrix GetProjectionMatrix() const;
	const SMatrix GetFPSProjectionMatrix() const;
	float GetFarZ() const;
	float GetNearZ() const;
	ZRenderGBuffer* GetGBuffer() const;
	void ResetObjectToWorldPrev();
	SRenderTempTexture2DAccess* GetTextureAccess();
	void SetCurrentRTV(ZRenderTargetView* _pRTV);
	void WinAllocateBuffers(bool allowMsaa);
	void DrawGuiCallback(void* pState);
	void DrawInstinctGlow(ZRenderContext* pRenderContext, SRenderGatherContext* pGatherContext, ZRenderTraversalContext* pTraversalContext, ZRenderGraphTraversal* pRenderGraphTraversal, bool bUseStencilMask, unsigned int pass);
	void DrawGhostNodes(ZRenderContext* pRenderContext, SRenderGatherContext* pGatherContext, ZRenderGraphTraversal* pRenderGraphTraversal);
	void DrawGhostFeedback(ZRenderContext* pRenderContext, SRenderGatherContext* pGatherContext, ZRenderGraphTraversal* pRenderGraphTraversal);
	void ApplyGhostFeedback(ZRenderTargetView** pDest);
	bool UseOutsideGlobalLight();
	static bool GlobalLightSwap(bool bUseOutside, SRoomInsideOutsideInfo* pInsideOutsideInfo, float4& vGlobalUp, float4& vGlobalDown, float4& vGlobalBack, float4& vGlobalUpOutside, float4& vGlobalDownOutside, float4& vGlobalBackOutside);
	float4 GetGlobalLightAmbientUpCurrent();
	float4 GetGlobalLightAmbientDownCurrent();
	float4 GetGlobalLightAmbientBackCurrent();
	float4 GetGlobalLightAmbientUpCurrentOutside();
	float4 GetGlobalLightAmbientDownCurrentOutside();
	float4 GetGlobalLightAmbientBackCurrentOutside();
	SRoomInsideOutsideInfo GetCurrentInsideOutsideInfo();
	void SetRoomReferencePos(const float4& vPos);
	float GetGIIntensity();
	float GetFovY();
	float GetAspectWByH();
	unsigned short GetStickyRoomId();
	void AllocateBuffers();
	void FreeBuffers();
	void UpdateCharacterRain(TArray<ZRenderGraphNode*>& Nodes, SRenderGatherContext* pGatherContext, ZRenderGraphNodeRainSurfaceSimulator* pSimulator) const;
	void FadeCSM(unsigned short nFinalRoomID, const float4& vEyePoint, ZRenderContext* pRenderContext) const;
	static float CalculateLODZoomFactor(float fFovY);
	void UpdateCameraOverlappingRooms(unsigned int nNewRoomId);
};
