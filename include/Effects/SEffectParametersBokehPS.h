#pragma once

#include "SGBufferUsingEffectParametersBase.h"

class alignas(8) SEffectParametersBokehPS : public SGBufferUsingEffectParametersBase
{
public:
    ZRenderShader* m_pBokeh_VS;
    ZRenderShader* m_pBokeh_PS;
    ZRenderShader* m_pApplySeparable_PS;
    ZRenderShader* m_pApplyBokeh_PS;
    unsigned __int64 m_pInputSize[3];
    unsigned __int64 m_pOutputSize[3];
    unsigned __int64 m_pViewRemap[3];
    unsigned __int64 m_pCoCParams[3];
    unsigned __int64 m_pBlurriness[3];
    SEffectResourceLoader m_EffectLoader;
};
