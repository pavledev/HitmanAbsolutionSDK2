#pragma once

#include "ZRenderShader.h"

class DownSample2x2MinMaxPassParameters
{
public:
    ZRenderShader* m_pFShader;
    ZRenderShader* m_pVShader;
    unsigned int m_TU_TPC0;
    unsigned __int64 m_nVTexelSize;
};
