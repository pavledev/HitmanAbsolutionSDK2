#pragma once

#include "SEffectParameters.h"
#include "SEffectResourceLoader.h"

struct SEffectParametersInternal : SEffectParameters
{
	ZRenderEffectTechnique* m_pTDrawQuadPS;
	ZRenderEffectTechnique* m_pTDrawQuadVS;
	ZRenderShader* m_pDrawQuadPS;
	ZRenderShader* m_pDrawQuadVS;
	ZRenderEffectTechnique* m_pTZPassPS;
	ZRenderShader* m_pZPassPS;
	ZRenderEffectTechnique* m_pTZPassVS_Standard;
	ZRenderShader* m_pZPassVS_StandardVS;
	ZRenderShader* m_pZPassVS_StandardPS;
	SEffectResourceLoader m_EffectLoader;

	~SEffectParametersInternal() override = default;
	void Update(ZRenderEffect* pEffect) override;

	SEffectParametersInternal() = default;
	void Init();
	void RebindEffectResource();
};
