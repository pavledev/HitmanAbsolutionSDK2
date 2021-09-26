#pragma once

#include "SGBufferUsingEffectParametersBase.h"

struct SEffectParametersBokehCS : SGBufferUsingEffectParametersBase
{
	ZRenderShader* m_pDownsampleCoC_CS;
	ZRenderShader* m_pFindLargestCoCInRangeH_CS;
	ZRenderShader* m_pFindLargestCoCInRangeV_CS;
	ZRenderShader* m_pBokeh_CS;
	SEffectResourceLoader m_EffectLoader;

	~SEffectParametersBokehCS() override = default;
	void Update(ZRenderEffect* pEffect) override;

	SEffectParametersBokehCS() = default;
	void Init();
	void RebindEffectResource();
};
