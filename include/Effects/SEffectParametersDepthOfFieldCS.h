#pragma once

#include "SGBufferUsingEffectParametersBase.h"

struct SEffectParametersDepthOfFieldCS : SGBufferUsingEffectParametersBase
{
	ZRenderShader* m_pDepthOfFieldH_CS;
	ZRenderShader* m_pDepthOfFieldV_CS;
	SEffectResourceLoader m_EffectLoader;

	~SEffectParametersDepthOfFieldCS() override = default;
	void Update(ZRenderEffect* pEffect) override;

	SEffectParametersDepthOfFieldCS() = default;
	void Init();
	void RebindEffectResource();
};
