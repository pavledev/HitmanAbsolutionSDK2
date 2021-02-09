#pragma once

#include "SGBufferUsingEffectParametersBase.h"

class SEffectParametersBokehCS : public SGBufferUsingEffectParametersBase
{
public:
    ZRenderShader* m_pDownsampleCoC_CS;
    ZRenderShader* m_pFindLargestCoCInRangeH_CS;
    ZRenderShader* m_pFindLargestCoCInRangeV_CS;
    ZRenderShader* m_pBokeh_CS;
    SEffectResourceLoader m_EffectLoader;
};
