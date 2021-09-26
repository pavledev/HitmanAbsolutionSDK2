#pragma once

#include "SEffectParameters.h"
#include "SEffectOverrideBlock.h"

struct SEffectParametersStandardVS : SEffectParameters
{
	enum
	{
		OVERRIDE_LAYER_SHADOWMAP = 0,
		OVERRIDE_LAYER_SHADOWMAPDITHER = 1,
		OVERRIDE_LAYER_SHADOWMAPZ = 2,
		OVERRIDE_LAYER_SHADOWMAPZDITHER = 3,
		OVERRIDE_LAYER_RAINMAP = 4,
		OVERRIDE_LAYER_SIMPLE = 5,
		OVERRIDE_LAYER_WIREFRAME = 6,
		NUM_OVERRIDDEN_LAYERS = 7
	};

	ZRenderEffectTechnique* m_pTStandardVS;
	ZRenderEffectTechnique* m_pTStandardLinkedVS;
	ZRenderEffectTechnique* m_pTStandardWeightedVS;
	SEffectOverrideBlock m_DefaultVS;
	ZRenderShader* m_pFOverridenLayer[7];
	SEffectResourceLoader m_EffectLoader;

	~SEffectParametersStandardVS() override = default;
	void Update(ZRenderEffect* pEffect) override;

	SEffectParametersStandardVS() = default;
	void Init();
	void RebindEffectResource();
	bool SetupDefaultFragmentShader(SRenderRecordedDrawCmdBuffer& DrawCmds, ERenderLayer eLayer);
};
