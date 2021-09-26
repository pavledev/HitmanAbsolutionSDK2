#pragma once

#include "SGBufferUsingEffectParametersBase.h"

struct SEffectParametersBokehPS : SGBufferUsingEffectParametersBase
{
	ZRenderShader* m_pBokeh_VS;
	ZRenderShader* m_pBokeh_PS;
	ZRenderShader* m_pApplySeparable_PS;
	ZRenderShader* m_pApplyBokeh_PS;
	unsigned long long m_pInputSize[3];
	unsigned long long m_pOutputSize[3];
	unsigned long long m_pViewRemap[3];
	unsigned long long m_pCoCParams[3];
	unsigned long long m_pBlurriness[3];
	SEffectResourceLoader m_EffectLoader;

	~SEffectParametersBokehPS() override = default;
	void Update(ZRenderEffect* pEffect) override;

	SEffectParametersBokehPS() = default;
	void Init();
	void RebindEffectResource();
};
