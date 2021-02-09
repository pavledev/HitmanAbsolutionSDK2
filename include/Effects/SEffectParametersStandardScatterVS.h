#pragma once

#include "SEffectParameters.h"
#include "SEffectOverrideBlock.h"

class SEffectParametersStandardScatterVS : public SEffectParameters
{
public:
    ZRenderEffectTechnique* m_pTStandardScatterVS;
    SEffectOverrideBlock m_DefaultVS;
    ZRenderShader* m_pFOverridenLayer[2];
    SEffectResourceLoader m_EffectLoader;
};
