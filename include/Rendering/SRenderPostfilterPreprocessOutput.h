#pragma once

#include "ZRenderShaderResourceView.h"
#include "ZRenderTexture2D.h"

class SRenderPostfilterPreprocessOutput
{
public:
    ZRenderShaderResourceView* m_pGlareAccumulationSRV;
    ZRenderTexture2D* m_pGlareAccumulationTexture;
};