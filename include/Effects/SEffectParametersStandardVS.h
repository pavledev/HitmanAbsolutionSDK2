#pragma once

#include "SEffectParameters.h"
#include "SEffectOverrideBlock.h"

class SEffectParametersStandardVS : public SEffectParameters
{
public:
    ZRenderEffectTechnique* m_pTStandardVS;
    ZRenderEffectTechnique* m_pTStandardLinkedVS;
    ZRenderEffectTechnique* m_pTStandardWeightedVS;
    SEffectOverrideBlock m_DefaultVS;
    ZRenderShader* m_pFOverridenLayer[7];
    SEffectResourceLoader m_EffectLoader;
};
