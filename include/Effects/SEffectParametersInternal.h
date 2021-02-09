#pragma once

#include "SEffectParameters.h"
#include "SEffectResourceLoader.h"

class SEffectParametersInternal : public SEffectParameters
{
    ZRenderEffectTechnique* m_pTDrawQuadPS;
    ZRenderEffectTechnique* m_pTDrawQuadVS;
    ZRenderShader* m_pDrawQuadPS;
    ZRenderShader* m_pDrawQuadVS;
    ZRenderEffectTechnique* m_pTZPassPS;
    ZRenderShader* m_pZPassPS;
    ZRenderEffectTechnique* m_pTZPassVS_Standard;
    ZRenderShader* m_pZPassVS_StandardVS;
    ZRenderShader* m_pZPassVS_StandardPS;
    SEffectResourceLoader m_EffectLoader;
};
