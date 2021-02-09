#pragma once

#include "ZRenderTexture2D.h"
#include "ZRenderTargetView.h"
#include "ZRenderDepthStencilView.h"

class ZRender2DRenderTarget
{
public:
    unsigned int m_nWidth;
    unsigned int m_nHeight;
    ZRenderTexture2D* m_pTexture;
    ZRenderTargetView* m_pRTV;
    ZRenderShaderResourceView* m_pSRV;
    ZRenderTexture2D* m_pDepthTexture;
    ZRenderDepthStencilView* m_pDSV;
};
