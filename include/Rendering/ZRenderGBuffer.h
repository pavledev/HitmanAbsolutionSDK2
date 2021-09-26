#pragma once

#include "ZString.h"
#include "SRenderTempTexture2DAccess.h"

class SGBufferUsingTechniqueParameters;
class ZRenderDepthStencilView;
class ZRenderDevice;
class ZRenderShaderResourceView;
class ZRenderTargetView;
class ZRenderTexture2D;
struct SRenderTexture2DAccess;

class ZRenderGBuffer
{
public:
	enum
	{
		NUM_G_BUFFERS = 3
	};

	enum ERenderTargetSetupType
	{
		RTST_ZPASS = 0,
		RTST_GBUFFER_FILL = 1,
		RTST_GBUFFER_FILL_WITH_ZPASS = 2
	};

	unsigned int m_nWidth;
	unsigned int m_nHeight;
	ZString m_sName;
	ZRenderDevice* m_pRenderDevice;
	unsigned int m_nMultisampleCount;
	ZRenderTexture2D* m_pDepthTexture;
	ZRenderDepthStencilView* m_pDepthDSV;
	SRenderTempTexture2DAccess m_pGBufferAccess[3];
	ZRenderShaderResourceView* m_pOcclusionSRV;
	bool m_bMsaa;
	ZRenderTexture2D* m_pMsaaDsTexture;
	ZRenderDepthStencilView* m_pMsaaDsDSV;
	ZRenderTexture2D* m_pMsDepthTexture;
	ZRenderTargetView* m_pMsDepthTextureRTV;
	ZRenderShaderResourceView* m_pMsDepthTextureSRV;
	ZRenderTexture2D* m_pSsDepthTexture;
	ZRenderTargetView* m_pSsDepthTextureRTV;
	ZRenderShaderResourceView* m_pSsDepthTextureSRV;
	ZRenderTexture2D* m_pDepthTexture2x;
	ZRenderTargetView* m_pDepthTexture2xRTV;
	ZRenderShaderResourceView* m_pDepthTexture2xSRV;

	ZRenderGBuffer() = default;
	ZRenderGBuffer(unsigned int nWidth, unsigned int nHeight, ZString sName, ZRenderDevice* pRenderDevice, unsigned int nMultiSampleCount);
	~ZRenderGBuffer() = default;
	ZRenderShaderResourceView* GetDepthSRV() const;
	ZRenderDepthStencilView* GetDepthDSV() const;
	SRenderTexture2DAccess* GetGBufferAccess(unsigned int nIndex) const;
	void SetupSRV(SGBufferUsingTechniqueParameters& params, char* pMappedFragmentConstBuffer);
	void SetOcclusionSRV(ZRenderShaderResourceView* pOcclusionSRV);
	void SetupOcclusionSRV(SGBufferUsingTechniqueParameters& params);
	void Allocate();
	void Free(const unsigned int nUsageMask);
	void AllocateDepth();
	void FreeDepth();
	ZRenderTexture2D* GetDepthTexture() const;
	void EnableMsaa(bool bMsaa);
	ZRenderTexture2D* GetMultiSampleDsTexture();
	ZRenderTexture2D* GetSingleSampleDsTexture();
	ZRenderDepthStencilView* GetSingleSampleDSV() const;
	ZRenderShaderResourceView* GetHalfResDepthSRV() const;
	ZRenderShaderResourceView* GetSingleSampleDepthSRV() const;
	ZRenderTargetView* GetHalfResDepthRTV() const;
	ZRenderTargetView* GetSingleSampleDepthRTV() const;
	ZRenderTargetView* GetMultiSampleDepthRTV() const;
	ZRenderTargetView* GetDepthRTV() const;
};
