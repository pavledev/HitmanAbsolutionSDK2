#pragma once

#include "ZRenderGraphNode.h"
#include "SSkinBlurPtrs.h"
#include "ZRenderDevice.h"
#include "SRenderPostfilterPreprocessOutput.h"
#include "SRenderPostfilterParameters.h"
#include "SRenderPostfilterCachedSizes.h"
#include "SRenderPostfilterPerScreenDecalParametersInternal.h"
#include "SRenderTexture2DAccess.h"
#include "SRenderTempTexture2DAccess.h"
#include "ZRenderPostfilterGlareDefinition.h"
#include "ZRenderUnorderedAccessView.h"

class ZRenderGraphNodePostfilterController : ZRenderGraphNode
{
    SSkinBlurPtrs m_Ptrs;
    ZRenderDevice* m_pDevice;
    bool m_bBuffersAllocated;
    SRenderPostfilterPreprocessOutput m_PreprocessOutput;
    SRenderPostfilterParameters m_Parameters;
    SRenderPostfilterCachedSizes m_CachedSizes;
    SRenderPostfilterPerScreenDecalParametersInternal m_ScreenDecalRingBuffer[64];
    unsigned int m_nScreenDecalRingBufferOffset;
    unsigned int m_nScreenDecalRingBufferNumElements;
    unsigned int m_nNumPostTranslucentFiltersEnabled;
    unsigned int m_nTempBufferIndex;
    SRenderTexture2DAccess m_ColorRGBE2x2;
    SRenderTexture2DAccess m_ColorRGBE4x4;
    SRenderTexture2DAccess m_Tonemapped2x2;
    SRenderTexture2DAccess m_Tonemapped4x4;
    SRenderTexture2DAccess m_Color4x4;
    SRenderTexture2DAccess m_ToneMap[3];
    SRenderTexture2DAccess m_LuminanceQuadrantCPU[4];
    float m_fLuminanceQuadrantAvgLum[4];
    float m_fAdaptedLuminance[2];
    SRenderTexture2DAccess m_BrightPass;
    SRenderTexture2DAccess m_Blur16x16;
    SRenderTexture2DAccess m_StarSource;
    SRenderTexture2DAccess m_GlareAccumulation;
    SRenderTexture2DAccess m_DepthCoC2x2;
    SRenderTempTexture2DAccess m_VolumeLight2x2;
    bool m_bDepthCoCTextureAllocated;
    ZRenderTexture2D* m_pDepth4x4Texture;
    ZRenderDepthStencilView* m_pDepth4x4DSV;
    unsigned int m_nHDRAdaptedLuminanceIndex;
    unsigned int m_nHDRLuminanceOffsetIndex;
    unsigned int m_nNumFramesAdaptationMeasured;
    ZRenderPostfilterGlareDefinition* m_pGlareDefinition;
    ZRenderTexture2D* m_pDepthOfFieldBackBufferHalf;
    ZRenderShaderResourceView* m_pDepthOfFieldBackBufferHalfSRV;
    ZRenderUnorderedAccessView* m_pDepthOfFieldBackBufferHalfUAV;
    ZRenderTexture2D* m_pDepthOfFieldBackBufferHalf2;
    ZRenderShaderResourceView* m_pDepthOfFieldBackBufferHalf2SRV;
    ZRenderUnorderedAccessView* m_pDepthOfFieldBackBufferHalf2UAV;
    ZRenderTexture2D* m_pDepthOfFieldBackBufferHalf3;
    ZRenderShaderResourceView* m_pDepthOfFieldBackBufferHalf3SRV;
    ZRenderUnorderedAccessView* m_pDepthOfFieldBackBufferHalf3UAV;
    ZRenderTargetView* m_pDepthOfFieldBackBufferHalf2RTV;
    ZRenderTexture2D* m_pDepthOfFieldBackBufferHalfR;
    ZRenderShaderResourceView* m_pDepthOfFieldBackBufferHalfRSRV;
    ZRenderUnorderedAccessView* m_pDepthOfFieldBackBufferHalfRUAV;
    ZRenderTexture2D* m_pDepthOfFieldBackBufferHalfR2;
    ZRenderShaderResourceView* m_pDepthOfFieldBackBufferHalfR2SRV;
    ZRenderUnorderedAccessView* m_pDepthOfFieldBackBufferHalfR2UAV;
    int m_nDoFComputeBuffersCreated;
    ZRenderTexture2D* m_pColorCorrectionPaletteTextures[2];
    ZRenderShaderResourceView* m_pColorCorrectionPaletteSRVs[2];
    unsigned int m_nColorCorrectionPaletteVersion;
    unsigned int m_nCurrentCorrectionPaletteIndex;
    ZRenderTexture2D* m_pVideoEffectsRandomTexture;
    ZRenderShaderResourceView* m_pVideoEffectsRandomSRV;
    ZRenderTexture2D* m_pRandBasesTexture;
    ZRenderShaderResourceView* m_pRandBasesSRV;
    SRenderTexture2DAccess m_Occlusion;
    bool m_bOcclusionBufferAllocated;
    SRenderTexture2DAccess m_StarTempR8x8RGBA8[2];
    SRenderTexture2DAccess m_DepthOfField[2];
    ZRenderTexture2D* m_pScreenDecalsDisabledTexture;
    ZRenderShaderResourceView* m_pScreenDecalsDisabledSRV;
    float4 m_vLastBlur;
    float4 m_vLastColor;
    ZRenderTexture2D* m_pNoiseTexture;
    ZRenderShaderResourceView* m_pNoiseSRV;
    ZRenderInputLayout* m_pNoiseInputLayout;
    ZRenderVertexBuffer* m_pNoiseVertexBuffers[2];
    ZRenderIndexBuffer* m_pNoiseIB;
    int m_nNoiseQuadsW;
    int m_nNoiseQuadsH;
    float m_fRcpAverageRealtime;
    float m_fDoubleVisionAngle1;
    float m_fDoubleVisionAngle2;
    float m_fDoubleVisionScaleAngle1;
    float m_fDoubleVisionScaleAngle2;
    float m_fDoubleVisionBlendAngle;
    SVector2 m_vDoubleVisionTrailVector;
    float4 m_vPrevEyeWorld;
};
