#pragma once

#include "SEffectParameters.h"
#include "SEffectOverrideBlock.h"

struct SEffectParametersStandardScatterVS : SEffectParameters
{
	enum
	{
		OVERRIDE_LAYER_SIMPLE = 0,
		OVERRIDE_LAYER_WIREFRAME = 1,
		NUM_OVERRIDDEN_LAYERS = 2
	};

	ZRenderEffectTechnique* m_pTStandardScatterVS;
	SEffectOverrideBlock m_DefaultVS;
	ZRenderShader* m_pFOverridenLayer[2];
	SEffectResourceLoader m_EffectLoader;

	~SEffectParametersStandardScatterVS() override = default;
	void Update(ZRenderEffect* pEffect) override;

	SEffectParametersStandardScatterVS() = default;
	void Init();
	void RebindEffectResource();
};
