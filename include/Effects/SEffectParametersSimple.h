#pragma once

#include "SEffectParameters.h"

class SEffectParametersSimple : SEffectParameters
{
    ZRenderShader* m_pSimpleSingleVShader;
    ZRenderShader* m_pSimpleSingleFShader;
    ZRenderShader* m_pSimpleSingleColorVShader;
    ZRenderShader* m_pSimpleSingleColorFShader;
    ZRenderShader* m_pSimpleSingleVShaderP1;
    ZRenderShader* m_pSimpleSingleFShaderP1;
    ZRenderShader* m_pSimpleQuadVShader;
    ZRenderShader* m_pSimpleQuadFShader;
    ZRenderShader* m_pStandardSingleVShader;
    ZRenderShader* m_pStandardSingleFShader;
    ZRenderShader* m_pSimpleOneFShader;
    SEffectResourceLoader m_EffectLoader;
};