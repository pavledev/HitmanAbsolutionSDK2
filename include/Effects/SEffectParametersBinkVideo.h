#pragma once

#include "SEffectParameters.h"

class alignas(8) SEffectParametersBinkVideo : public SEffectParameters
{
public:
    ZRenderEffectTechnique* m_pTBinkVideo_NoAlpha;
    ZRenderEffectTechnique* m_pTBinkVideo_RGBA;
    ZRenderShader* m_pShader_NoAlpha;
    ZRenderShader* m_pShader_RGBA;
    unsigned __int64 m_Alpha;
    unsigned int m_TBink_Yplane;
    unsigned int m_TBink_cRplane;
    unsigned int m_TBink_cBplane;
    unsigned int m_TBink_Aplane;
    SEffectResourceLoader m_EffectLoader;
};
