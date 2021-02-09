#pragma once

#include "SEffectParameters.h"

class SEffectParametersMsaaEdgeDetect : public SEffectParameters
{
public:
    ZRenderEffectTechnique* m_pTechniqueMsaaEdgeDetect;
    ZRenderShader* m_pShader_MsaaEdgeDetect_PS;
    ZRenderShader* m_pShader_DrawRed_PS;
    ZRenderShader* m_pShader_DrawGreen_PS;
    unsigned __int64 m_rcpPI;
    unsigned int m_NormalTex;
    unsigned int m_DepthTex;
    bool m_bIsInit;
    bool m_bRebind;
    SEffectResourceLoader m_EffectLoader;
};
