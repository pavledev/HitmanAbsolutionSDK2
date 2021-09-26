#pragma once

#include "SEffectParameters.h"

struct SEffectParametersMsaaEdgeDetect : SEffectParameters
{
	ZRenderEffectTechnique* m_pTechniqueMsaaEdgeDetect;
	ZRenderShader* m_pShader_MsaaEdgeDetect_PS;
	ZRenderShader* m_pShader_DrawRed_PS;
	ZRenderShader* m_pShader_DrawGreen_PS;
	unsigned long long m_rcpPI;
	unsigned int m_NormalTex;
	unsigned int m_DepthTex;
	bool m_bIsInit;
	bool m_bRebind;
	SEffectResourceLoader m_EffectLoader;

	~SEffectParametersMsaaEdgeDetect() override = default;
	void Update(ZRenderEffect* pEffect) override;

	SEffectParametersMsaaEdgeDetect() = default;
	void Init(unsigned int numSamples);
	void RebindEffectResource();
	void Update(int nMsaa);
};
