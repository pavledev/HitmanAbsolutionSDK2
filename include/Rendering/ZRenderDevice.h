#pragma once
#pragma warning(disable : 4005)

#include <D3D11.h>
#include <minwindef.h>

#include "ZRenderDeviceBase.h"
#include "SRenderDeviceCaps.h"
#include "SRenderViewport.h"
#include "ZRenderConstBufferRef.h"
#include "SRenderDisplayMode.h"
#include "ZGameTime.h"
#include "ERenderPrimitiveTopology.h"
#include "ERenderFormat.h"
#include "TArray.h"
#include "ZMutex.h"
#include "ZString.h"

class IAmdDxExtQuadBufferStereo;
class ZRenderEffect;
class ZRenderUnorderedAccessView;
struct SRenderUnorderedAccessViewDesc;
class ZRenderQuery;
struct SRenderQueryDesc;
class IRenderResource;
class ZRenderBlendState;
class ZRenderBufferDeferredUpdate;
class ZRenderDepthStencilState;
class ZRenderDepthStencilView;
class ZRenderIndexBuffer;
class ZRenderInputLayout;
class ZRenderRasterizerState;
class ZRenderShader;
class ZRenderShaderResourceView;
class ZRenderSwapChain;
class ZRenderTargetView3D;
class ZRenderTargetView;
class ZRenderTexture2D;
class ZRenderTexture3D;
class ZRenderVertexBuffer;
class ZStateManager;
class ZSubRenderBufferManager;
struct HWND__;
struct SRenderBlendStateDesc;
struct SRenderBufferDescription;
struct SRenderDepthStencilStateDesc;
struct SRenderDepthStencilViewDesc;
struct SRenderDestinationDesc;
struct SRenderInputElementDesc;
struct SRenderRasterizerStateDesc;
struct SRenderRecordedDrawCmdBuffer;
struct SRenderShaderResourceViewDesc;
struct SRenderSubResourceData;
struct SRenderTargetViewDesc;
struct SRenderTexture2DDesc;
struct SRenderTexture3DDesc;
struct float4;

class ZRenderDevice : public ZRenderDeviceBase
{
public:
	enum EForceAspectRatioType
	{
		AR_FORCE_NONE = 0,
		AR_FORCE_16x9_UI = 1,
		AR_FORCE_16x9_INGAME = 2
	};

	enum
	{
		MAX_BEGIN_VERTICES_SIZE = 524288
	};

	IDXGIAdapter* m_pSelectedAdapter;
	ZStateManager* m_pStateManager;
	SRenderDeviceCaps m_DeviceCaps;
	ZRenderSwapChain* m_pSwapChain;
	SRenderViewport m_Viewport;
	ZRenderTargetView* m_pRenderTargetViews[8];
	ZRenderTargetView3D* m_pRenderTargetViews3D[8];
	ZRenderConstBufferRef m_ActiveSharedConstBuffer[4];
	ID3D11Device* m_pDirect3DDevice;
	ID3D11DeviceContext* m_pDeviceContextImmediate;
	HRESULT (*m_pD3D11Reflect)(const void* param1, unsigned long param2, const _GUID& param3, void** param4);
	D3D_FEATURE_LEVEL m_D3DFeatureLevel;
	ZRenderDepthStencilView* m_pDepthStencilView;
	ZRenderInputLayout* m_pInputLayout;
	unsigned char* m_pInputSignature;
	unsigned int m_nInputSignatureSize;
	ID3D11Buffer* m_pQuadVertexBuffer;
	ID3D11VertexShader* m_pQuadVertexShader;
	ID3D11InputLayout* m_pQuadInputLayout;
	ID3D11PixelShader* m_pResolveRTVPixelShader;
	ZRenderShader* m_pResolveRTVPixelShader2;
	ID3D11PixelShader* m_pResolveRTVPixelShaderMsaa2;
	ID3D11PixelShader* m_pResolveRTVPixelShaderMsaa4;
	ID3D11PixelShader* m_pResolveRTVPixelShaderMsaa8;
	ZRenderShader* m_pResolveRTVRenderShaderMsaa2;
	ZRenderShader* m_pResolveRTVRenderShaderMsaa4;
	ZRenderShader* m_pResolveRTVRenderShaderMsaa8;
	ID3D11PixelShader* m_pResolveRTVDepthPixelShaderMsaa2;
	ID3D11PixelShader* m_pResolveRTVDepthPixelShaderMsaa4;
	ID3D11PixelShader* m_pResolveRTVDepthPixelShaderMsaa8;
	ZRenderShader* m_pResolveRTVDepthRenderShaderMsaa2;
	ZRenderShader* m_pResolveRTVDepthRenderShaderMsaa4;
	ZRenderShader* m_pResolveRTVDepthRenderShaderMsaa8;
	ID3D11BlendState* m_pResolveRTVBlendState;
	ID3D11RasterizerState* m_pResolveRTVRasterizerState;
	ID3D11PixelShader* m_pResolveDSVPixelShaderMsaa2;
	ZRenderShader* m_pResolveDSVRenderShaderMsaa2;
	ID3D11PixelShader* m_pResolveDSVPixelShaderMsaa4;
	ZRenderShader* m_pResolveDSVRenderShaderMsaa4;
	ID3D11PixelShader* m_pResolveDSVPixelShaderMsaa8;
	ZRenderShader* m_pResolveDSVRenderShaderMsaa8;
	ID3D11BlendState* m_pResolveDSVBlendState;
	ID3D11RasterizerState* m_pResolveDSVRasterizerState;
	ID3D11Buffer* m_pBeginVerticesBuffer;
	unsigned int m_nBeginVerticesOffset;
	unsigned int m_nBeginVerticesStride;
	unsigned int m_nBeginVerticesCount;
	SRenderDisplayMode m_currentDisplayMode;
	bool m_bHardwareGammaCorrection;
	float m_fConvertedGamma;
	ZMutex m_deferredUpdateMutex;
	ZSubRenderBufferManager* m_pSubRenderBufferManager;
	TArray<ZRenderBufferDeferredUpdate*> m_deferredUpdates;
	unsigned int m_nStartIndex;
	int m_nBaseVertex;
	bool m_bOccluded;
	ZGameTime m_occludedTime;
	IAmdDxExtQuadBufferStereo* m_pAmdStereo;
	void* m_nvStereoHandle;
	bool m_bSupportsDepthBoundsTesting;
	bool m_bDepthBoundsTestEnabled;

	~ZRenderDevice() override = default;
	ZRenderTexture2D* CreateTexture2D(const SRenderTexture2DDesc* pDescription, const SRenderSubResourceData* pData) override;
	ZRenderTexture3D* CreateTexture3D(const SRenderTexture3DDesc* pDescription, const SRenderSubResourceData* pData) override;
	void SetGamma(float fGamma) override;
	virtual ZRenderSwapChain* GetSwapChain();
	virtual void Reset(const SRenderDestinationDesc* pDescription, bool bForce);
	virtual bool Recover();
	virtual void GetInternalParameters(void** parameter1, void** parameter2);
	virtual void GetViewport(SRenderViewport* pViewport);
	virtual void SetViewport(const SRenderViewport& vp);
	virtual bool BeginScene();
	virtual void EndScene();
	virtual void Present();
	virtual void ApplyCustomGammaCorrection();
	virtual void SetPrimitiveTopology(ERenderPrimitiveTopology ePrimitiveTopology);
	virtual void DrawIndexed(unsigned int nStartIndex, unsigned int nNumIndices, int nBaseVertex, unsigned int nNumVertices);
	virtual void DrawIndexedInstanced(unsigned int nIndexCountPerInstance, unsigned int nInstanceCount, unsigned int nStartIndex, int nBaseVertex, unsigned int nStartInstanceLocation, unsigned int nNumVertices);
	virtual void DrawQuadNew(float x, float y, float w, float h, const float4& vColor, float fZValue, float tx, float ty, float wtx, float wty, bool bUseDefaultVS, ZRenderShader* pFragmentShader_, ZRenderShader* pVertexShader_, const ZRenderConstBufferRef ConstBufferF, const ZRenderConstBufferRef ConstBufferV);
	virtual void DrawPrimitives(ERenderPrimitiveTopology ePrimitiveTopology, const void* pVertices, unsigned int nNumPrimitives, unsigned int nVertexSize, const bool bAddToStats);
	virtual void BeginVertices(ERenderPrimitiveTopology ePrimitiveTopology, unsigned int nVertexCount, unsigned int nVertexStride, void** ppVertexData, const bool bAddToStats);
	virtual void EndVertices();
	virtual void Dispatch(unsigned int nThreadGroupsX, unsigned int nThreadGroupsY, unsigned int nThreadGroupsZ, ZRenderShader* pComputeShader, const ZRenderConstBufferRef ConstBufferC);
	virtual void SetVertexBuffers(unsigned int nStartSlot, unsigned int nNumBuffers, ZRenderVertexBuffer** pVertexBuffers, const unsigned char* pStrides);
	virtual void SetVertexBuffer(ZRenderVertexBuffer* pVertexBuffers, const unsigned char nStride);
	virtual void SetIndexBuffer(ZRenderIndexBuffer* pIndexBuffer, ERenderFormat eFormat, unsigned int nOffset);
	virtual void SetInputLayout(ZRenderInputLayout* pInputLayout);
	virtual void SetBlendState(ZRenderBlendState* pBlendState, float fBlendFactor);
	virtual void SetRasterizerState(ZRenderRasterizerState* pRasterizerState);
	virtual void SetDepthStencilState(ZRenderDepthStencilState* pDepthStencilState, unsigned int nStencilRef);
	virtual void GetRenderTargets3D(unsigned int nNumViews, ZRenderTargetView3D** ppRenderTargetViews3D);
	virtual void SetRenderTargets3D(unsigned int nNumViews, ZRenderTargetView3D** ppRenderTargetViews3D, unsigned int nClearFlags, const float4* pClearColors);
	virtual void GetRenderTargets(unsigned int nNumViews, ZRenderTargetView** ppRenderTargetViews, ZRenderDepthStencilView** ppDepthStencilView);
	virtual void SetRenderTargets(unsigned int nNumViews, ZRenderTargetView** ppRenderTargetViews, ZRenderDepthStencilView* pDepthStencilView, unsigned int nClearFlags, const float4* pClearColors, float fDepthValue, unsigned int nStencilValue);
	virtual void ClearRenderTargets(unsigned int nNumViews, unsigned int nClearFlags, const float4* pClearColors, float fDepthValue, unsigned int nStencilValue);
	virtual void ClearHiStencil(unsigned int nFlags, unsigned int nStencilValue);
	virtual void ResolveRTV(ZRenderTargetView* pDstRTV, ZRenderTargetView* pSrcRTV);
	virtual void ResolveDSV(ZRenderDepthStencilView* pDstDSV, ZRenderDepthStencilView* pSrcDSV);
	virtual void CopyResource(IRenderResource* pDstResource, IRenderResource* pSrcResource);
	virtual const SRenderDeviceCaps& GetDeviceCaps() const;

	ZRenderDevice() = default;
	void CreateSwapChain(const SRenderDestinationDesc* pDescription, bool* pExclusiveFullScreen);
	ZRenderEffect* CreateEffect(const void* pEffectData, const unsigned int nEffectSize, const ZString& sName);
	ZRenderVertexBuffer* CreateVertexBuffer(const SRenderBufferDescription* pDescription, const void* pData);
	ZRenderIndexBuffer* CreateIndexBuffer(const SRenderBufferDescription* pDescription, const void* pData);
	ZRenderInputLayout* CreateInputLayout(const SRenderInputElementDesc* pElements, unsigned int nNumElements);
	ZRenderTargetView3D* CreateRenderTargetView(const SRenderTargetViewDesc* pDescription, ZRenderTexture3D* pTexture);
	ZRenderTargetView* CreateRenderTargetView(const SRenderTargetViewDesc* pDescription, ZRenderTexture2D* pTexture);
	ZRenderShaderResourceView* CreateShaderResourceView(const SRenderShaderResourceViewDesc* pDescription, IRenderResource* pResource);
	ZRenderUnorderedAccessView* CreateUnorderedAccessView(const SRenderUnorderedAccessViewDesc* pDescription, IRenderResource* pResource);
	ZRenderDepthStencilView* CreateDepthStencilView(const SRenderDepthStencilViewDesc* pDescription, ZRenderTexture2D* pTexture);
	ZRenderBlendState* CreateBlendState(const SRenderBlendStateDesc* pDescription);
	ZRenderDepthStencilState* CreateDepthStencilState(const SRenderDepthStencilStateDesc* pDescription);
	ZRenderRasterizerState* CreateRasterizerState(const SRenderRasterizerStateDesc* pDescription);
	ZRenderQuery* CreateQuery(const SRenderQueryDesc* pDescription);
	void DrawIndexed(unsigned int nStartIndex, unsigned int nNumIndices, int nBaseVertex, unsigned int nNumVertices, ZRenderShader* pFragmentShader_, ZRenderShader* pGeometryShader_, ZRenderShader* pVertexShader_, ZRenderShader* pHullShader, ZRenderShader* pDomainShader, const ZRenderConstBufferRef ConstBufferF, const ZRenderConstBufferRef ConstBufferG, const ZRenderConstBufferRef ConstBufferV, const ZRenderConstBufferRef ConstBufferH);
	void DrawIndexed(unsigned int nStartIndex, unsigned int nNumIndices, int nBaseVertex, unsigned int nNumVertices, ZRenderShader* pFragmentShader_, ZRenderShader* pVertexShader_, const ZRenderConstBufferRef ConstBufferF, const ZRenderConstBufferRef ConstBufferV);
	void DrawPrimitives(ERenderPrimitiveTopology ePrimitiveTopology, const void* pVertices, unsigned int nNumPrimitives, unsigned int nVertexSize, ZRenderShader* pFragmentShader_, ZRenderShader* pVertexShader_, const ZRenderConstBufferRef ConstBufferF, const ZRenderConstBufferRef ConstBufferV, const bool bAddToStats);
	void BeginVertices(ERenderPrimitiveTopology ePrimitiveTopology, unsigned int nVertexCount, unsigned int nVertexStride, void** ppVertexData, ZRenderShader* pFragmentShader_, ZRenderShader* pVertexShader_, const ZRenderConstBufferRef ConstBufferF, const ZRenderConstBufferRef ConstBufferV, const bool bAddToStats);
	void EndVertices(ZRenderShader* pFragmentShader_, ZRenderShader* pVertexShader_, const ZRenderConstBufferRef ConstBufferF, const ZRenderConstBufferRef ConstBufferV);
	void SetDepthBounds(bool bEnable, float fZMin, float fZMax);
	void ResolveRTVDepth(ZRenderTargetView* pDstRTV, ZRenderTargetView* pSrcRTV);
	void CopySRV2DSV(ZRenderDepthStencilView* pDstDSV, ZRenderShaderResourceView* pSrcSRV, unsigned int nMsaa);
	void CopyDSV2RTV(ZRenderTargetView* pDstRTV, ZRenderTexture2D* pSrcDSV);
	static void BeginEvent(unsigned int nColor, const char* pszName);
	static void EndEvent();
	void EnterScaleForm();
	void LeaveScaleForm();
	void ClearRTV(unsigned int nNumViews, ZRenderTargetView3D** ppRenderTargetViews3D, const float4* pClearColors);
	void BindShaders(ZRenderShader* pFragmentShader, ZRenderShader* pGeometryShader, ZRenderShader* pVertexShader, ZRenderShader* pHullShader, ZRenderShader* pDomainShader, const ZRenderConstBufferRef ConstBufferF, const ZRenderConstBufferRef ConstBufferG, const ZRenderConstBufferRef ConstBufferV, const ZRenderConstBufferRef ConstBufferH, bool bSetInputLayout);
	void UnbindShaders();
	void DrawPoints(unsigned int nNumPoints, ZRenderShader* pFragmentShader, ZRenderShader* pGeometryShader, ZRenderShader* pVertexShader, const ZRenderConstBufferRef ConstBufferF, const ZRenderConstBufferRef ConstBufferG, const ZRenderConstBufferRef ConstBufferV);
	void Flush();
	auto GetD3DReflectProcAddress() -> HRESULT (*)(const void* param1, unsigned long param2, const _GUID& param3, void** param4);
	void SetSharedConstBuffer(unsigned int nSharedBufferId, unsigned int nSlot, ZRenderConstBufferRef pBuffer);
	ZRenderConstBufferRef GetSharedConstBuffer(unsigned int nSlot);
	void SetTexture(unsigned int nTexUnit, ZRenderShaderResourceView* pShaderResourceView);
	void SetVertexTexture(unsigned int nTexUnit, ZRenderShaderResourceView* pShaderResourceView);
	void SetComputeTexture(unsigned int nTexUnit, ZRenderShaderResourceView* pShaderResourceView);
	void SetUAV(unsigned int nIndex, ZRenderUnorderedAccessView* pShaderResourceView);
	void GetTextureStats(int* pOutTotal, int* pOutFree, int* pOutNeeded);
	ID3D11Device* GetDirect3DDevice() const;
	void SetInputSignature(unsigned char* pInputSignature, unsigned int nInputSignatureSize);
	ID3D11DeviceContext* GetImmediateContext() const;
	ZString GetFeatureLevelString() const;
	void PlayRecordedDrawCommandBuffer(SRenderRecordedDrawCmdBuffer* DrawCmds);
	void DumpScreenShot();
	void GetPrimaryViewportRect(unsigned int& nRectLeft, unsigned int& nRectTop, unsigned int& nRectWidth, unsigned int& nRectHeight, EForceAspectRatioType force16x9AspectRatio);
	const SRenderDisplayMode& GetCurrentDisplayMode();
	bool IsFullScreen();
	IAmdDxExtQuadBufferStereo* GetAMDStereoDriver();
	void* GetNVIDIA3DVisionHandle() const;
	IDXGIAdapter* GetAdapter() const;
	bool SupportsDepthBoundsTesting() const;
	bool ApplyAPIStereoValues(HWND__* hWnd, bool bEnabled, float fSeparationPercentage);
	bool IsFeatureLevelActive(int iMinLevel, int iMaxLevel) const;
	bool HasSwapChain();
	bool IsHardwareGammaCorrectionEnabled() const;
	void ResetStateManager();
	ZSubRenderBufferManager* GetSubRenderBufferManager();
	void ScheduleDeferredBufferUpdate(ZRenderBufferDeferredUpdate* pUpdate);
	void ProcessDeferredUpdates();
	bool IsOccluded();
	const ZGameTime& GetOccludedTime() const;
	void ClearDepthStencil(ZRenderDepthStencilView* pDepthStencilView, unsigned int nClearFlags, float fDepthValue, unsigned int nStencilValue);
	void UpdateDisplayMode(const SRenderDestinationDesc* pDescription);
	bool IsNVAPILoaded() const;
	bool CreateNVAPI(DXGI_ADAPTER_DESC& pAdapter);
	void DestroyNVAPI();
};
