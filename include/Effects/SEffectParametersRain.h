#pragma once

#include "SGBufferUsingEffectParametersBase.h"

struct SEffectParametersRain : SGBufferUsingEffectParametersBase
{
	ZRenderShader* m_pAntiRain_VS;
	ZRenderShader* m_pAntiRain_PS;
	ZRenderShader* m_pRainTest_VS;
	ZRenderShader* m_pRainTest_PS;
	ZRenderShader* m_pRippleShader_PS;
	ZRenderShader* m_pRippleToNormalShader_VS;
	ZRenderShader* m_pRippleToNormalShader_PS;
	ZRenderShader* m_pRunningWaterShader_VS;
	ZRenderShader* m_pRunningWaterShader_PS;
	ZRenderShader* m_pRainParticle_VS;
	ZRenderShader* m_pRainParticle_PS;
	ZRenderShader* m_pRainParticleRefract_VS;
	ZRenderShader* m_pRainParticleRefract_PS;
	ZRenderShader* m_pInterpolateNormalMaps_PS;
	ZRenderShader* m_pCharacterRain_PS;
	unsigned long long m_pVEyeLowerLeft_Offset_RainTest_PS;
	unsigned long long m_pVEyeLowerRight_Offset_RainTest_PS;
	unsigned long long m_pVEyeUpperLeft_Offset_RainTest_PS;
	unsigned long long m_pVEyeUpperRight_Offset_RainTest_PS;
	unsigned long long m_CharacterRainParams;
	unsigned int m_nTPC0_sampler_InterpolateNormalMaps_PS;
	unsigned int m_nTPC1_sampler_InterpolateNormalMaps_PS;
	unsigned int m_nSLastRainTex_sampler_RippleShader_PS;
	unsigned int m_nSLastRainTex_sampler_RunningWaterShader_PS;
	unsigned int m_nSLastRainTex_sampler_RippleToNormalShader_PS;
	unsigned int m_nSNoiseTex_sampler_RippleShader_PS;
	unsigned int m_nSNoiseTex_sampler_RunningWaterShader_PS;
	unsigned int m_nSRainCubeReflection_sampler_RainTest_PS;
	unsigned int m_nSRainCubeReflection_sampler_RainParticle_PS;
	unsigned int m_nSRainCubeReflection_sampler_RainParticleRefract_PS;
	unsigned int m_nSRainNormalTex_sampler_RainTest_PS;
	unsigned int m_nSRainNormalTex_sampler_RainParticle_PS;
	unsigned int m_nSRainNormalTex_sampler_RainParticleRefract_PS;
	unsigned int m_nSRainNormalTex2_sampler_RainTest_PS;
	unsigned int m_nVar_mapRainTex_sampler_RainParticle_PS;
	unsigned int m_nVar_mapRainTex_sampler_RainParticleRefract_PS;
	unsigned int m_nVar_mapRainDepth_sampler_RainParticle_VS;
	unsigned int m_nVMapRainRefract_sampler_RainParticleRefract_PS;
	unsigned int m_nDeferred0_sampler_RainTest_PS;
	unsigned int m_nDeferred1_sampler_RainTest_PS;
	unsigned int m_nDeferred0_sampler_AntiRain_PS;
	unsigned int m_LightProjectorMap0_sampler_CharacterRain_PS;
	unsigned int m_ShadowColorPointSampled_sampler_CharacterRain_PS;
	unsigned int m_LightCubeProjectorMap0_sampler_CharacterRain_PS;
	SEffectResourceLoader m_EffectLoader;

	~SEffectParametersRain() override = default;
	void Update(ZRenderEffect* pEffect) override;

	SEffectParametersRain() = default;
	void Init();
	void RebindEffectResource();
};
