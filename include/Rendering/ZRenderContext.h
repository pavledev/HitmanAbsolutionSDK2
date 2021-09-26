#pragma once

#include "SMatrix.h"
#include "SRenderDrawMode.h"
#include "ERenderLayer.h"
#include "ERenderPrimitiveTopology.h"
#include "SRenderViewport.h"
#include "ZRenderConstBufferRef.h"
#include "float4.h"

class ZRenderSharedResources;
struct SRenderRuntimePrimitiveInstance;
struct SFPSLocalState;
class IRenderDestination;
class ZRenderBlendState;
class ZRenderDepthStencilState;
class ZRenderDevice;
class ZRenderGBuffer;
class ZRenderGraphNodeCamera;
class ZRenderQuery;
class ZRenderRasterizerState;
class ZRenderShader;
class ZRenderShaderResourceView;

class ZRenderContext
{
public:
	enum
	{
		MAX_NUM_LIGHTS = 256
	};

	enum
	{
		MAX_NUM_LIGHTS_PER_PASS = 1
	};

	enum
	{
		LIGHT_QUERY_FRAMES = 3
	};

	enum
	{
		LT_SHADOW = 1,
		LT_PROJMAP = 2,
		LT_FADE = 4,
		LT_SIMPLE = 8,
		LT_SIZE = 22
	};

	enum
	{
		LIGHT_PRIO_QUERY_INVALID_INDEX = -1
	};

	struct SLightPriorityQuery
	{
		void* m_pOwner;
		unsigned int m_nLastFrameUsed;
		unsigned int m_nNumFramesUsed;
		ZRenderQuery* m_pQuery[3];

		SLightPriorityQuery() = default;
		ZRenderQuery* GetCurrentQuery();
	};

	struct SLightQuery
	{
		int m_nLightType;
		int m_nLightTag;
		ZRenderQuery* m_pQuery;
	};

	struct SLightQueryList
	{
		unsigned int m_nLightCount;
		SLightQuery m_Queries[256];
	};

	struct SLightCascadeCSMData
	{
		float m_fOffsetX;
		float m_fOffsetY;
		float m_fScaleX;
		float m_fScaleY;
		float m_fZRangeMin;
		float m_fZRangeMax;
		float m_fZRangeFullHalf;
	};

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
	SRenderRuntimePrimitiveInstance* m_pRenderPrimitiveInstance;
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
	unsigned short m_nStartRoom;
	bool m_bUseSimpleRendering;
	bool m_bUseFPSLocalSpace;
	unsigned char m_nUsingLODIndex;
	float m_fSSAOFarDistance;
	float m_fGlowAmount;

	ZRenderContext() = default;
	~ZRenderContext() = default;
	void SetRenderDevice(ZRenderDevice* pRenderDevice);
	ZRenderDevice* GetRenderDevice() const;
	void SetRenderSharedResources(ZRenderSharedResources* pRenderSharedResources);
	ZRenderSharedResources* GetRenderSharedResources() const;
	void SetRenderGBuffer(ZRenderGBuffer* pGBuffer);
	ZRenderGBuffer* GetRenderGBuffer() const;
	void SetRenderDestination(IRenderDestination* pRenderDestination);
	IRenderDestination* GetRenderDestination() const;
	void SetRefractionSRV(ZRenderShaderResourceView* pRefractionSRV);
	void SetRefractionMaskSRV(ZRenderShaderResourceView* pRefractionMaskSRV);
	void SetReflectionSRV(ZRenderShaderResourceView* pReflectionSRV);
	void SetRenderDrawMode(const SRenderDrawMode& drawMode);
	const SRenderDrawMode& GetRenderDrawMode() const;
	void SetDeferredRendering(bool bDeferredRendering);
	bool IsDeferredRendering() const;
	void SetMirrorRendering(bool bMirrorRendering);
	bool IsMirrorRendering() const;
	void SetActiveCamera(ZRenderGraphNodeCamera* pCamera);
	ZRenderGraphNodeCamera* GetActiveCamera() const;
	void SetCSMDisabled(float fCSMDisabled);
	float IsCSMDisabled() const;
	float CalcCSMRangeScale() const;
	void SetPerObjectSimpleColor(const float4& vColor);
	float4 GetPerObjectSimpleColor() const;
	void SetViewToWorldMatrix(const SMatrix& mViewToWorld);
	const SMatrix GetViewToWorldMatrix() const;
	void SetWorldToViewMatrix(const SMatrix& mWorldToView);
	const SMatrix GetWorldToViewMatrix() const;
	void SetWorldToViewPrevMatrix(const SMatrix& mWorldToViewPrev);
	void SetViewToProjectionMatrix(const SMatrix& ViewToProjectionMatrix);
	const SMatrix GetViewToProjectionMatrix() const;
	void SetFPSViewToProjectionMatrix(const SMatrix& ViewToProjectionMatrix);
	const SMatrix GetFPSViewToProjectionMatrix() const;
	void SetViewport(const SRenderViewport& viewport);
	const SRenderViewport& GetViewport() const;
	void SetEyePoint(const float4& vEyePoint);
	const float4 GetEyePoint() const;
	void OverrideStartRoom(unsigned short nRoomId);
	const unsigned short GetOverrideStartRoom();
	void SetEyeRadius(const float& fEyeRadius);
	float GetEyeRadius() const;
	void SetFovY(const float& fFovY);
	float GetFovY() const;
	void SetStableFovY(const float& fFovY);
	float GetStableFovY() const;
	void SetNearZ(float fNearZ);
	float GetNearZ() const;
	void SetFarZ(float fFarZ);
	float GetFarZ() const;
	void SetClipDistanceScale(const float fClipDistanceScale);
	float GetClipDistanceScale() const;
	void SetLODZoomFactor(const float& fLODZoomFactor);
	float4 GetLODZoomFactor() const;
	unsigned int GetStencilRef() const;
	void SetRenderLayer(const ERenderLayer& eRenderLayer);
	const ERenderLayer& GetRenderLayer() const;
	void SetCSMProj(unsigned int nSplit, const SMatrix& mCSMProj);
	const SMatrix GetCSMProj() const;
	void SetUseSimpleRendering(bool bUseSimpleRendering);
	bool GetUseSimpleRendering() const;
	void AllocateLightPriorityQueries(ZRenderDevice* pDevice);
	void ReleaseLightPriorityQueries();
	int TryAllocLightPriorityQuery(void* pOwner);
	void BumpAllocLightPriorityQuery(int nIndex);
	SLightPriorityQuery* GetLightPriorityQuery(unsigned int nIndex);
	void ClearLightPriorityQueries();
	void FreeUnusedPriorityQueries();
	void SetShaderF(ZRenderShader* pShader);
	ZRenderShader* GetShaderF();
	void SetShaderV(ZRenderShader* pShader);
	ZRenderShader* GetShaderV();
	void SetConstBufferV(ZRenderConstBufferRef cb);
	ZRenderConstBufferRef GetConstBufferV();
	void SetConstBufferF(ZRenderConstBufferRef cb);
	ZRenderConstBufferRef GetConstBufferF();
	void OverrideBlendState(ZRenderBlendState* s);
	void OverrideRasterizerState(ZRenderRasterizerState* s);
	void OverrideDepthStencilState(ZRenderDepthStencilState* s, unsigned int nStencilRef);
	ZRenderRasterizerState* GetOverrideRasterizerState();
	ZRenderDepthStencilState* GetOverrideDepthStencilState();
	ZRenderBlendState* GetOverrideBlendState();
	void SetGlobalLitFactor(const float4& vGlobalLitFactor);
	float4 GetGlobalLitFactor() const;
	bool IsMainRenderTarget() const;
	void SetIsMainRenderTarget(bool bIsMain);
	void SetPrimitiveTopology(ERenderPrimitiveTopology ePrimitiveTopology);
	ERenderPrimitiveTopology GetPrimitiveTopology() const;
	void SetSSAOFarDistance(float f);
	float GetSSAOFarDistance() const;
	SLightCascadeCSMData& CSMCascadeData(unsigned int nIndex);
	int GetNumOverlappingRooms() const;
	unsigned int GetOverlappingRoom(unsigned int nIndex) const;
	void SetOverlappingRooms(unsigned short* pOverlappingRooms, unsigned int nNumOverlappingRooms);
	void PushFPSLocal(SFPSLocalState& State);
	void PopFPSLocal(SFPSLocalState& State);
	void SetFPSDrawLocal(bool bFPSLocal);
	void SetMirrorClipPlane(const float4& vViewClipPlane, const float4& vWorldClipPlane);
	float4 GetMirrorClipPlaneView();
	float4 GetMirrorClipPlaneWorld();
	bool GetEmissiveOnly();
	bool GetDrawCrowd();
	bool GetDrawScatter();
	unsigned int GetGateTraversalDepth();
	void SetEmissiveOnly(bool bEmissiveOnly);
	void SetDrawCrowd(bool bDrawCrowd);
	void SetDrawScatter(bool bDrawScatter);
	void SetGateTraversalDepth(unsigned int nDepth);
	void SetGlowAmount(float fGlowAmount);
	void SetStereoscopic(bool bStereo);
	bool IsStereoscopic();
	void SetStereoLeftEye(bool bEye);
	bool IsStereoLeftEye();
};
