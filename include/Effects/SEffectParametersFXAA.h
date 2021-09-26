#pragma once

#include "SEffectParameters.h"

struct SEffectParametersFXAA : SEffectParameters
{
	ZRenderEffectTechnique* m_pTechniqueFXAA;
	ZRenderShader* m_pShader_FXAA_PS;
	unsigned long long m_rcpFrame;
	unsigned int m_TLC0;
	SEffectResourceLoader m_EffectLoader;

	~SEffectParametersFXAA() override = default;
	void Update(ZRenderEffect* pEffect) override;

	SEffectParametersFXAA() = default;
	void Init();
	void RebindEffectResource();
};
