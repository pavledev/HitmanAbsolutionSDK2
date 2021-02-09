#pragma once

#include "SEffectParameters.h"

class SEffectParametersSkin : public SEffectParameters
{
    ZRenderShader* m_pSkinBlurX_VS;
    ZRenderShader* m_pSkinBlurY_VS;
    ZRenderShader* m_pSkinBlur_PS;
    ZRenderShader* m_pSkin_VS;
    ZRenderShader* m_pSkinCopy_PS;
    ZRenderShader* m_pSkinCopyMasked_PS;
    ZRenderShader* m_pSkinApplyAndFade;
    unsigned __int64 m_TexKernelXOffset_SkinBlurX_VS;
    unsigned __int64 m_TexKernelYOffset_SkinBlurY_VS;
    unsigned __int64 m_BlurWeightOffset_SkinBlur_PS;
    unsigned __int64 m_BlurWeightSumOffset_SkinBlur_PS;
    unsigned __int64 m_SkinParams_SkinApplyAndFade;
    unsigned int m_SamplerSkinColor_SkinBlur_PS;
    unsigned int m_SamplerSkinColor_SkinCopy_PS;
    unsigned int m_SamplerSkinColor_SkinCopyMasked_PS;
    SEffectResourceLoader m_EffectLoader;
};
