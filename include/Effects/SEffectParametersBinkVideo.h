#pragma once

#include "SEffectParameters.h"

struct SEffectParametersBinkVideo : SEffectParameters
{
	ZRenderEffectTechnique* m_pTBinkVideo_NoAlpha;
	ZRenderEffectTechnique* m_pTBinkVideo_RGBA;
	ZRenderShader* m_pShader_NoAlpha;
	ZRenderShader* m_pShader_RGBA;
	unsigned long long m_Alpha;
	unsigned int m_TBink_Yplane;
	unsigned int m_TBink_cRplane;
	unsigned int m_TBink_cBplane;
	unsigned int m_TBink_Aplane;
	SEffectResourceLoader m_EffectLoader;

	~SEffectParametersBinkVideo() override = default;
	void Update(ZRenderEffect* pEffect) override;

	SEffectParametersBinkVideo() = default;
	void Init();
	void RebindEffectResource();
};
