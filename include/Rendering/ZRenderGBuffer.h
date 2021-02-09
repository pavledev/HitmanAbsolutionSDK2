#pragma once

#include "ZString.h"
#include "ZRenderDevice.h"
#include "SRenderTempTexture2DAccess.h"

class ZRenderGBuffer
{
public:
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

    enum ERenderTargetSetupType
    {
        RTST_ZPASS = 0x0,
        RTST_GBUFFER_FILL = 0x1,
        RTST_GBUFFER_FILL_WITH_ZPASS = 0x2
    };
};
