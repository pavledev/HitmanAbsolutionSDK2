#pragma once

#include "SEffectConstantHelper.h"

struct SEffectParametersPrechainMergeParameters : SEffectConstantHelper<6, 7, 0>
{
	SEffectParametersPrechainMergeParameters() = default;
	~SEffectParametersPrechainMergeParameters() = default;
	void Init(ZRenderShader* pShader);
};
