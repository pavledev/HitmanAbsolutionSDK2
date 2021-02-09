#pragma once

#include "SEffectParameters.h"

class SEffectParametersFXAA : public SEffectParameters
{
public:
    ZRenderEffectTechnique* m_pTechniqueFXAA;
    ZRenderShader* m_pShader_FXAA_PS;
    unsigned __int64 m_rcpFrame;
    unsigned int m_TLC0;
    SEffectResourceLoader m_EffectLoader;
};
