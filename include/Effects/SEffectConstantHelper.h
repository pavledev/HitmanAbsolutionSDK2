#pragma once

#include "ZRenderShader.h"

template<int A, int B, int C>
struct alignas(8) SEffectConstantHelper
{
    ZRenderShader* m_pShader;
    unsigned __int64 m_nParamOffset[A];
    unsigned int m_nTextureUnits[B];
};