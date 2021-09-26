#pragma once

#include "ZRenderShader.h"

template <int A, int B, int C>
struct SEffectConstantHelper
{
	ZRenderShader* m_pShader;
	unsigned long long m_nParamOffset[A];
	unsigned int m_nTextureUnits[B];

	SEffectConstantHelper() = default;
	~SEffectConstantHelper() = default;
};
