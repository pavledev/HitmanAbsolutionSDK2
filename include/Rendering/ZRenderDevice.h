#pragma once
#pragma warning(disable : 4005)

#include "ZRenderDeviceBase.h"
#include "D3D11.h"
#include "ZStateManager.h"
#include "SRenderDeviceCaps.h"
#include "SRenderViewport.h"
#include "ZRenderTargetView.h"
#include "ZRenderTargetView3D.h"
#include "ZRenderConstBufferRef.h"
#include "ZRenderDepthStencilView.h"
#include "ZRenderInputLayout.h"
#include "ZRenderShader.h"
#include "SRenderDisplayMode.h"
#include "ZSubRenderBufferManager.h"
#include "ZRenderBufferDeferredUpdate.h"
#include "ZGameTime.h"
#include "ERenderPrimitiveTopology.h"
#include "float4.h"
#include "ZRenderVertexBuffer.h"
#include "ZRenderIndexBuffer.h"
#include "SRenderDestinationDesc.h"
#include "ZRenderSwapChain.h"

//class ZRenderSwapChain;

class alignas(8) ZRenderDevice : public ZRenderDeviceBase
{
public:
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
    HRESULT(__stdcall* m_pD3D11Reflect)(const void*, unsigned int, const _GUID*, void**);
    D3D_FEATURE_LEVEL m_D3DFeatureLevel;
    ZRenderDepthStencilView* m_pDepthStencilView;
    ZRenderInputLayout* m_pInputLayout;
    unsigned __int8* m_pInputSignature;
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
    struct IAmdDxExtQuadBufferStereo* m_pAmdStereo;
    void* m_nvStereoHandle;
    bool m_bSupportsDepthBoundsTesting;
    bool m_bDepthBoundsTestEnabled;

    enum UnkEnum : __int32
    {
        MAX_BEGIN_VERTICES_SIZE = 0x80000
    };

    virtual ZRenderSwapChain* GetSwapChain();
    virtual void Reset(const SRenderDestinationDesc*, bool);
    virtual bool Recover();
    virtual void GetInternalParameters(void**, void**);
    virtual void GetViewport(SRenderViewport*);
    virtual void SetViewport(const SRenderViewport*);
    virtual bool BeginScene();
    virtual void EndScene();
    virtual void Present();
    virtual void ApplyCustomGammaCorrection();
    virtual void SetPrimitiveTopology(ERenderPrimitiveTopology);
    virtual void DrawIndexed(unsigned int, unsigned int, int, unsigned int);
    virtual void DrawIndexedInstanced(unsigned int, unsigned int, unsigned int, int, unsigned int, unsigned int);
    virtual void DrawQuadNew(float, float, float, float, const float4*, float, float, float, float, float, bool, ZRenderShader*, ZRenderShader*, const ZRenderConstBufferRef, const ZRenderConstBufferRef);
    virtual void DrawPrimitives(ERenderPrimitiveTopology, const void*, unsigned int, unsigned int, const bool);
    virtual void BeginVertices(ERenderPrimitiveTopology, unsigned int, unsigned int, void**, const bool);
    virtual void EndVertices();
    virtual void Dispatch(unsigned int, unsigned int, unsigned int, ZRenderShader*, const ZRenderConstBufferRef);
    virtual void SetVertexBuffers(unsigned int, unsigned int, ZRenderVertexBuffer* const*, const unsigned __int8*);
    virtual void SetVertexBuffer(ZRenderVertexBuffer*, const unsigned __int8);
    virtual void SetIndexBuffer(ZRenderIndexBuffer*, ERenderFormat, unsigned int);
    virtual void SetInputLayout(ZRenderInputLayout*);
    virtual void SetBlendState(ZRenderBlendState*, float);
    virtual void SetRasterizerState(ZRenderRasterizerState*);
    virtual void SetDepthStencilState(ZRenderDepthStencilState*, unsigned int);
    virtual void GetRenderTargets3D(unsigned int, ZRenderTargetView3D**);
    virtual void SetRenderTargets3D(unsigned int, ZRenderTargetView3D**, unsigned int, const float4*);
    virtual void GetRenderTargets(unsigned int, ZRenderTargetView**, ZRenderDepthStencilView**);
    virtual void SetRenderTargets(unsigned int, ZRenderTargetView**, ZRenderDepthStencilView*, unsigned int, const float4*, float, unsigned int);
    virtual void ClearRenderTargets(unsigned int, unsigned int, const float4*, float, unsigned int);
    virtual void ClearHiStencil(unsigned int, unsigned int);
    virtual void ResolveRTV(ZRenderTargetView*, ZRenderTargetView*);
    virtual void ResolveDSV(ZRenderDepthStencilView*, ZRenderDepthStencilView*);
    virtual void CopyResource(IRenderResource*, IRenderResource*);
    virtual const SRenderDeviceCaps* GetDeviceCaps();
};
