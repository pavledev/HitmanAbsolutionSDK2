#pragma once

#include "SEffectParameters.h"
#include "SEffectOverrideBlock.h"

struct SEffectParametersStandardDecalVS : SEffectParameters
{
	enum
	{
		OVERRIDE_LAYER_SIMPLE = 0,
		OVERRIDE_LAYER_WIREFRAME = 1,
		NUM_OVERRIDDEN_LAYERS = 2
	};

	ZRenderEffectTechnique* m_pTStandardDecalVS;
	ZRenderEffectTechnique* m_pTStandardDecalLinkedVS;
	ZRenderEffectTechnique* m_pTStandardDecalWeightedVS;
	SEffectOverrideBlock m_DefaultVS;
	ZRenderShader* m_pFOverridenLayer[2];
	SEffectResourceLoader m_EffectLoader;

	~SEffectParametersStandardDecalVS() override = default;
	void Update(ZRenderEffect* pEffect) override;

	SEffectParametersStandardDecalVS() = default;
	void Init();
	void RebindEffectResource();
};
