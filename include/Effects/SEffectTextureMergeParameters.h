#pragma once

#include "SEffectConstantHelper.h"

struct SEffectTextureMergeParameters : SEffectConstantHelper<1, 9, 0>
{
	SEffectTextureMergeParameters() = default;
	~SEffectTextureMergeParameters() = default;
	void Init(ZRenderShader* pShader);
};
