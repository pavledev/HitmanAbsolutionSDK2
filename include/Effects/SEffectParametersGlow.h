#pragma once

#include "SEffectParameters.h"
#include "SEffectParametersGlowParams.h"

struct SEffectParametersGlow : SEffectParameters
{
	ZRenderShader* m_pGlowFShader;
	SEffectParametersGlowParams m_GlowParamOffsets;
	ZRenderShader* m_pGlowRimFShader;
	SEffectParametersGlowParams m_GlowRimParamOffsets;
	ZRenderShader* m_pGhostBlur;
	unsigned long long m_GhostBlurColorWeightOffset;
	unsigned long long m_GhostBlurConstOffset;
	ZRenderShader* m_pShaderV[3];
	ZRenderShader* m_pShaderWSV[3];
	SEffectResourceLoader m_EffectLoader;

	~SEffectParametersGlow() override = default;
	void Update(ZRenderEffect* pEffect) override;

	SEffectParametersGlow() = default;
	void Init();
	void RebindEffectResource();
};
