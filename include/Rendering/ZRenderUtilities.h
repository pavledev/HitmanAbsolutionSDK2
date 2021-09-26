#pragma once

#include "TMap.h"
#include "ZRenderConstBufferRef.h"

struct SVector4;
class ZRenderContext;
class IRenderDestination;
class ZRenderBlendState;
class ZRenderDepthStencilView;
class ZRenderDevice;
class ZRenderShaderResourceView;
class ZRenderTargetView;
struct SRenderDestinationDesc;
struct SRenderMixedResolutionBuffers;
struct SRenderTexture2DAccess;
struct float4;

class ZRenderUtilities
{
public:
	enum
	{
		MAX_SAMPLES = 16
	};

	enum EDownSampleNumSamples
	{
		DOWNSAMPLE_NUM_SAMPLES_1P = 0,
		DOWNSAMPLE_NUM_SAMPLES_1 = 1,
		DOWNSAMPLE_NUM_SAMPLES_4 = 2,
		DOWNSAMPLE_NUM_SAMPLES_16 = 3
	};

	ZRenderDevice* m_pRenderDevice;
	TMap<unsigned int, SRenderMixedResolutionBuffers*> m_MRBsMap;
	ZRenderConstBufferRef m_ConstBufferGaussBlurV;
	ZRenderConstBufferRef m_ConstBufferDownSample2x2MinMaxV;
	unsigned int m_currentRenderDestId;
	TMap<unsigned int, IRenderDestination*> m_renderDestMap;

	ZRenderUtilities() = default;
	ZRenderUtilities(ZRenderDevice* pRenderDevice);
	~ZRenderUtilities() = default;
	void ClearMRBOnDemand();
	SRenderMixedResolutionBuffers* GetMixedResolutionBuffers(unsigned int nWidth, unsigned int nHeight);
	static void GetSampleOffsetsDownScale2x2(const SVector4& vSrcVP, SVector4* pSampleOffsets);
	static void GetSampleOffsetsDownScale4x4(unsigned int nWidth, unsigned int nHeight, SVector4* pSampleOffsets);
	static void RenderSetTexture(ZRenderDevice* pDevice, unsigned int nTexUnit, ZRenderShaderResourceView* pSRV);
	static void RenderSetVertexTexture(ZRenderDevice* pDevice, unsigned int nTexUnit, ZRenderShaderResourceView* pSRV);
	void DownSample(SRenderTexture2DAccess* pSrc, SRenderTexture2DAccess* pDst, EDownSampleNumSamples eNumSamples);
	void DownSample2x2Max(ZRenderShaderResourceView* pSrcSRV, const SVector4& vSrcVP, ZRenderTargetView* pDstRTV, const SVector4& vDstVP);
	void DownSample2x2MinMax(SRenderTexture2DAccess* pInput, SRenderTexture2DAccess* pOutput, unsigned int nPassIndex);
	void DownSample2x2MinMaxIter(SRenderTexture2DAccess* pTexture2DAccess, unsigned int nPassIndex);
	void GaussBlur5x5(ZRenderShaderResourceView* pSrcSRV, const SVector4& vSrcVP, ZRenderTargetView* pDstRTV, const SVector4& vDstVP, float fOffsetScale);
	void GaussBlurSep5(ZRenderShaderResourceView* pSRV, ZRenderTargetView* pRTV, ZRenderShaderResourceView* pTempSRV, ZRenderTargetView* pTempRTV, ZRenderDepthStencilView* pDSV, const SVector4& vVP);
	void GaussBlurSepHor5(ZRenderShaderResourceView* pSrcSRV, const SVector4& vSrcVP, ZRenderTargetView* pDstRTV, ZRenderDepthStencilView* pDSV, const SVector4& vDstVP);
	void GaussBlurSepVert5(ZRenderShaderResourceView* pSrcSRV, const SVector4& vSrcVP, ZRenderTargetView* pDstRTV, ZRenderDepthStencilView* pDSV, const SVector4& vDstVP);
	void GaussBlurSep5_2xFP16(ZRenderShaderResourceView* pSRV, ZRenderTargetView* pRTV, ZRenderShaderResourceView* pTempSRV, ZRenderTargetView* pTempRTV, ZRenderDepthStencilView* pDSV, const SVector4& vVP, ZRenderContext* pRenderContext, bool bDrawCircle);
	void GaussBlurSepHor5_2xFP16(ZRenderShaderResourceView* pSrcSRV, const SVector4& vSrcVP, ZRenderTargetView* pDstRTV, ZRenderDepthStencilView* pDSV, const SVector4& vDstVP, ZRenderContext* pRenderContext, bool bDrawCircle);
	void GaussBlurSepVert5_2xFP16(ZRenderShaderResourceView* pSrcSRV, const SVector4& vSrcVP, ZRenderTargetView* pDstRTV, ZRenderDepthStencilView* pDSV, const SVector4& vDstVP, ZRenderContext* pRenderContext, bool bDrawCircle);
	void GaussBlurSepHor5_Min(ZRenderShaderResourceView* pSrcSRV, const SVector4& vSrcVP, ZRenderTargetView* pDstRTV, ZRenderDepthStencilView* pDSV, const SVector4& vDstVP);
	void GaussBlurSepVert5_Min(ZRenderShaderResourceView* pSrcSRV, const SVector4& vSrcVP, ZRenderTargetView* pDstRTV, ZRenderDepthStencilView* pDSV, const SVector4& vDstVP);
	void GaussBlurSepHor15(ZRenderShaderResourceView* pSrcSRV, const SVector4& vSrcVP, ZRenderTargetView* pDstRTV, const SVector4& vDstVP, float fMultiplier);
	void GaussBlurSepVert15(ZRenderShaderResourceView* pSrcSRV, const SVector4& vSrcVP, ZRenderTargetView* pDstRTV, const SVector4& vDstVP, float fMultiplier);
	void ResolveRGBE(ZRenderShaderResourceView* pSrcSRV, const SVector4& vSrcVP, ZRenderTargetView* pDstRTV, ZRenderDepthStencilView* pDstDSV, const SVector4& vDstVP, bool bFrom);
	void TextureMerge(const unsigned int nNumTextures, float4* avSampleWeightsCustom, ZRenderShaderResourceView** ppSrvSRV, const SVector4& vSrcVP, ZRenderTargetView* pDstRTV, const SVector4& vDstVP, bool bUsePoint, ZRenderBlendState* pBlendState);
	void TextureMergeNormal(ZRenderShaderResourceView** ppSrvSRV, const SVector4& vSrcVP, ZRenderTargetView* pDstRTV, const SVector4& vDstVP);
	void TextureMergeMono(const float4& vSampleWeight, ZRenderShaderResourceView* pSrcSRV, ZRenderTargetView* pDstRTV, const SVector4& vDstVP);
	void TextureGamma(ZRenderShaderResourceView** ppSrvSRV, const SVector4& vSrcVP, ZRenderTargetView* pDstRTV, const SVector4& vDstVP);
	void ClearMRBsMap();
	unsigned int CreateRenderDestination(const SRenderDestinationDesc& desc);
	void DestroyRenderDestination(unsigned int id);
	IRenderDestination* GetRenderDestination(unsigned int id);
	void GaussBlur5x5Internal(ZRenderShaderResourceView* pSrcSRV, const SVector4& vSrcVP, ZRenderTargetView* pDstRTV, const SVector4& vDstVP, float fOffsetScale);
	void GaussBlurSep5Internal(unsigned int nPassIndex, const float4& vOffsets, ZRenderShaderResourceView* pSrcSRV, ZRenderTargetView* pDstRTV, ZRenderDepthStencilView* pDSV, const SVector4& vDstVP, ZRenderContext* pRenderContext, bool bDrawCircle);
	void GaussBlurSep15Internal(SVector4* avSampleOffsets, float4* avSampleWeights, ZRenderShaderResourceView* pSrcSRV, ZRenderTargetView* pDstRTV, const SVector4& vDstVP);
};
