#pragma once

#include "ZRenderShader.h"

class GaussBlurSep5PassParameters
{
public:
    ZRenderShader* m_pFShader;
    ZRenderShader* m_pVShader;
    unsigned int m_TU_TLC0;
    unsigned __int64 m_nVSampleOffsetsGaussSep5;
};
