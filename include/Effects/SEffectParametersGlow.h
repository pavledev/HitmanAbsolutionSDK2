#pragma once

#include "SEffectParameters.h"
#include "SEffectParametersGlowParams.h"

class alignas(8) SEffectParametersGlow : SEffectParameters
{
    ZRenderShader* m_pGlowFShader;
    SEffectParametersGlowParams m_GlowParamOffsets;
    ZRenderShader* m_pGlowRimFShader;
    SEffectParametersGlowParams m_GlowRimParamOffsets;
    ZRenderShader* m_pGhostBlur;
    unsigned __int64 m_GhostBlurColorWeightOffset;
    unsigned __int64 m_GhostBlurConstOffset;
    ZRenderShader* m_pShaderV[3];
    ZRenderShader* m_pShaderWSV[3];
    SEffectResourceLoader m_EffectLoader;
};
