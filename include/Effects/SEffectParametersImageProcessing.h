#pragma once

#include "SEffectParameters.h"
#include "GaussBlurSep5PassParameters.h"
#include "SEffectTextureMergeParameters.h"
#include "DownSample2x2MinMaxPassParameters.h"

class alignas(8) SEffectParametersImageProcessing : public SEffectParameters
{
public:
    GaussBlurSep5PassParameters m_pGaussBlurSep5Parameters[3];
    ZRenderShader* m_GaussDownSample2x2P_VS;
    ZRenderShader* m_DownSample2x2P_PS;
    ZRenderShader* m_GaussDownSample2x2_VS;
    ZRenderShader* m_DownSample2x2_PS;
    ZRenderShader* m_GaussDownSample2x2_4Tap_VS;
    unsigned __int64 m_TexelSize_GaussDownSample2x2_4Tap_VS;
    ZRenderShader* m_DownSample2x2_4Tap_PS;
    ZRenderShader* m_DownSample4x4_PS;
    unsigned __int64 m_SampleOffsets_DownSample4x4_PS;
    ZRenderShader* m_DownSample2x2_4Tap_Max_PS;
    ZRenderShader* m_pGaussBlur5x5_PS;
    unsigned __int64 m_SampleOffsets_GaussBlur5x5_PS;
    unsigned __int64 m_SampleWeights_GaussBlur5x5_PS;
    unsigned int m_nGaussBlur5x5_TU_TLC0;
    ZRenderShader* m_GaussBlurSep15_PS;
    unsigned __int64 m_SampleOffsets_GaussBlurSep15_PS;
    unsigned __int64 m_SampleWeights_GaussBlurSep15_PS;
    ZRenderShader* m_HDRResolveToRGBE_PS;
    ZRenderShader* m_HDRResolveFromRGBE_PS;
    SEffectTextureMergeParameters m_TextureMergeParameters[10];
    ZRenderShader* m_TextureMergeNormal;
    ZRenderShader* m_pTextureMergeMono_PS;
    ZRenderShader* m_pTextureGamma_PS;
    unsigned __int64 m_SampleWeights_TextureMergeMono_PS;
    DownSample2x2MinMaxPassParameters m_pDownSample2x2MinMaxParameters[4];
    SEffectResourceLoader m_EffectLoader;
};
