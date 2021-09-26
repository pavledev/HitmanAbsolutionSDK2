#pragma once

#include "SEffectParameters.h"
#include "GaussBlurSep5PassParameters.h"
#include "SEffectTextureMergeParameters.h"

struct SEffectParametersImageProcessing : SEffectParameters
{
	enum
	{
		ETEXTURE_MERGE_SIZE = 10
	};

	enum
	{
		DOWNSAMPLE_2x2_MINMAX_MIN = 0,
		DOWNSAMPLE_2x2_MINMAX_MAX = 1,
		DOWNSAMPLE_2x2_MINMAX_D_MM = 2,
		DOWNSAMPLE_2x2_MINMAX_MM_MM = 3
	};

	struct GaussBlurSep5PassParameters
	{
		ZRenderShader* m_pFShader;
		ZRenderShader* m_pVShader;
		unsigned int m_TU_TLC0;
		unsigned long long m_nVSampleOffsetsGaussSep5;

		GaussBlurSep5PassParameters() = default;
	};

	struct DownSample2x2MinMaxPassParameters
	{
		ZRenderShader* m_pFShader;
		ZRenderShader* m_pVShader;
		unsigned int m_TU_TPC0;
		unsigned long long m_nVTexelSize;

		DownSample2x2MinMaxPassParameters() = default;
	};

	GaussBlurSep5PassParameters m_pGaussBlurSep5Parameters[3];
	ZRenderShader* m_GaussDownSample2x2P_VS;
	ZRenderShader* m_DownSample2x2P_PS;
	ZRenderShader* m_GaussDownSample2x2_VS;
	ZRenderShader* m_DownSample2x2_PS;
	ZRenderShader* m_GaussDownSample2x2_4Tap_VS;
	unsigned long long m_TexelSize_GaussDownSample2x2_4Tap_VS;
	ZRenderShader* m_DownSample2x2_4Tap_PS;
	ZRenderShader* m_DownSample4x4_PS;
	unsigned long long m_SampleOffsets_DownSample4x4_PS;
	ZRenderShader* m_DownSample2x2_4Tap_Max_PS;
	ZRenderShader* m_pGaussBlur5x5_PS;
	unsigned long long m_SampleOffsets_GaussBlur5x5_PS;
	unsigned long long m_SampleWeights_GaussBlur5x5_PS;
	unsigned int m_nGaussBlur5x5_TU_TLC0;
	ZRenderShader* m_GaussBlurSep15_PS;
	unsigned long long m_SampleOffsets_GaussBlurSep15_PS;
	unsigned long long m_SampleWeights_GaussBlurSep15_PS;
	ZRenderShader* m_HDRResolveToRGBE_PS;
	ZRenderShader* m_HDRResolveFromRGBE_PS;
	SEffectTextureMergeParameters m_TextureMergeParameters[10];
	ZRenderShader* m_TextureMergeNormal;
	ZRenderShader* m_pTextureMergeMono_PS;
	ZRenderShader* m_pTextureGamma_PS;
	unsigned long long m_SampleWeights_TextureMergeMono_PS;
	DownSample2x2MinMaxPassParameters m_pDownSample2x2MinMaxParameters[4];
	SEffectResourceLoader m_EffectLoader;

	static const unsigned int NumGaussBlurSep5Passes;
	static const unsigned int NumDownSample2x2MinMaxPasses;

	~SEffectParametersImageProcessing() override = default;
	void Update(ZRenderEffect* pEffect) override;

	SEffectParametersImageProcessing() = default;
	void Init();
	void RebindEffectResource();
};
