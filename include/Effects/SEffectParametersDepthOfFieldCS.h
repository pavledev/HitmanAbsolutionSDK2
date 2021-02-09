#pragma once

#include "SGBufferUsingEffectParametersBase.h"

class SEffectParametersDepthOfFieldCS : public SGBufferUsingEffectParametersBase
{
public:
    ZRenderShader* m_pDepthOfFieldH_CS;
    ZRenderShader* m_pDepthOfFieldV_CS;
    SEffectResourceLoader m_EffectLoader;
};
