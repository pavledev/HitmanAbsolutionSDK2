#pragma once

#include "SEffectParameters.h"

struct SEffectParametersSimple : SEffectParameters
{
	ZRenderShader* m_pSimpleSingleVShader;
	ZRenderShader* m_pSimpleSingleFShader;
	ZRenderShader* m_pSimpleSingleColorVShader;
	ZRenderShader* m_pSimpleSingleColorFShader;
	ZRenderShader* m_pSimpleSingleVShaderP1;
	ZRenderShader* m_pSimpleSingleFShaderP1;
	ZRenderShader* m_pSimpleQuadVShader;
	ZRenderShader* m_pSimpleQuadFShader;
	ZRenderShader* m_pStandardSingleVShader;
	ZRenderShader* m_pStandardSingleFShader;
	ZRenderShader* m_pSimpleOneFShader;
	SEffectResourceLoader m_EffectLoader;

	~SEffectParametersSimple() override = default;
	void Update(ZRenderEffect* pEffect) override;

	SEffectParametersSimple() = default;
	void Init();
	void RebindEffectResource();
};
