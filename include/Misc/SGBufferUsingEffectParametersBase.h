#pragma once

#include "SEffectParameters.h"

struct SGBufferUsingEffectParametersBase : SEffectParameters
{
	~SGBufferUsingEffectParametersBase() override = default;
	void Update(ZRenderEffect* pEffect) override;

	SGBufferUsingEffectParametersBase() = default;
	void Update(SGBufferUsingTechniqueParameters& params, ZRenderShader* pVShader, ZRenderShader* pFShader);
};
