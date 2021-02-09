#pragma once

#include "SEffectParameters.h"
#include "SEffectOverrideBlock.h"

class SEffectParametersStandardDecalVS : public SEffectParameters
{
public:
    ZRenderEffectTechnique* m_pTStandardDecalVS;
    ZRenderEffectTechnique* m_pTStandardDecalLinkedVS;
    ZRenderEffectTechnique* m_pTStandardDecalWeightedVS;
    SEffectOverrideBlock m_DefaultVS;
    ZRenderShader* m_pFOverridenLayer[2];
    SEffectResourceLoader m_EffectLoader;
};
