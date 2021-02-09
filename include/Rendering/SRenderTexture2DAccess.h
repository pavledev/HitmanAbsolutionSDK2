#pragma once

#include "ZRenderShaderResourceView.h"
#include "ZRenderTargetView.h"

struct SRenderTexture2DAccess
{
    ZRenderShaderResourceView* m_pSRV;
    ZRenderTargetView* m_pRTV;
    ZRenderTexture2D* m_pTexture;
};
