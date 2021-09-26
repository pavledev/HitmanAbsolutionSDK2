#pragma once

#include "ZRenderGraphNode.h"
#include "SRenderPostfilterPreprocessOutput.h"
#include "SRenderPostfilterParameters.h"
#include "SRenderPostfilterCachedSizes.h"
#include "SRenderPostfilterPerScreenDecalParametersInternal.h"
#include "SRenderTexture2DAccess.h"
#include "SRenderTempTexture2DAccess.h"
#include "ZRenderUtilities.h"
#include "SVector2.h"
#include "ZRenderConstBufferRef.h"
#include "float4.h"

class ZRenderGraphNodeCamera;
struct SRenderGatherContext;
struct SRenderPostfilterContext;
struct SBorderGateInfo;
class ZRenderGBuffer;
class IJobChain;
class ZRenderContext;
class ZRenderDepthStencilView;
class ZRenderDevice;
class ZRenderGraphTraversal;
class ZRenderIndexBuffer;
class ZRenderInputLayout;
class ZRenderPostfilterGlareDefinition;
class ZRenderShader;
class ZRenderShaderResourceView;
class ZRenderTargetView;
class ZRenderTexture2D;
class ZRenderTraversalContext;
class ZRenderUnorderedAccessView;
class ZRenderVertexBuffer;
class ZRenderableEntity;
struct SMatrix;

class ZRenderGraphNodePostfilterController : public ZRenderGraphNode
{
public:
	enum ESourceTexture
	{
		ST_SOURCE = 0,
		ST_SCALE_2X2 = 1,
		ST_SCALE_4X4 = 2,
		ST_SCALE_8X8 = 3,
		ST_SCALE_16X16 = 4,
		ST_TARGET = 5
	};

	enum
	{
		MAX_SAMPLES = 16
	};

	enum
	{
		NUM_PALETTE_TEXTURES = 3
	};

	enum
	{
		POSTFILTER_PASS_IS_FIRST = 1024
	};

	enum
	{
		LUMINANCE_CPU_SIZE = 8
	};

	enum
	{
		NUM_TONEMAP_TEXTURES = 3
	};

	enum
	{
		NUM_COLOR_CORRECTION_TEXTURES = 2
	};

	enum
	{
		RENDER_POSTFILTER_DOF_BUFFER_2x2 = 0,
		RENDER_POSTFILTER_DOF_BUFFER_DEPTH_4x4 = 1
	};

	enum EPostfilterNoiseParameters
	{
		POSTFILTER_NOISE_TEXTURE_SIZE = 64
	};

	enum ENoiseVertexBuffer
	{
		NOISE_STATIC_BUFFER = 0,
		NOISE_DYNAMIC_BUFFER = 1
	};

	struct SSkinBlurPtrs
	{
		float* pBlurWeights;
		float* pKernelX;
		float* pKernelY;
		float* pWeight;
	};

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

	~ZRenderGraphNodePostfilterController() override = default;
	void Reflect(ZRenderableEntity* pRenderableEntity, IJobChain* pJobChain) override;

	ZRenderGraphNodePostfilterController() = default;
	void Apply(ZRenderGraphNodeCamera* pCamera, ZRenderContext* pRenderContext, ZRenderGraphTraversal* pRenderGraphTraversal, unsigned int nFlags, SRenderGatherContext* pGatherContext);
	ZRenderShaderResourceView* ApplySSAO(ZRenderGraphNodeCamera* pCamera, ZRenderContext* pRenderContext, ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderTraversalContext* pTraversalContext, ZRenderTargetView* pRenderTargetView, ZRenderTargetView* pRenderTargetViewSSAA, ZRenderGBuffer* pGBuffer, bool bDarkLights);
	void DrawGateHack(const SMatrix& matPT, const SMatrix& matP, SRenderPostfilterContext& context, SRenderTempTexture2DAccess* pTextureAccess, ZRenderContext* pRenderContext, ZRenderTraversalContext* pTraversalContext, unsigned short nRoomID, const float4& vCameraDir);
	void DrawBorderGates(const SMatrix& matPT, SRenderPostfilterContext& context, ZRenderContext* pRenderContext, ZRenderTraversalContext* pTraversalContext, const SBorderGateInfo* pBorderGates, unsigned int nNumBorderGates);
	void DrawBorderGatesBoxFade(const SMatrix& matPT, SRenderPostfilterContext& context, ZRenderContext* pRenderContext, ZRenderTraversalContext* pTraversalContext, const SBorderGateInfo* pBorderGates, unsigned int nNumBorderGates);
	void ResetAdaptation(float fLuminance);
	const unsigned int GetPostfilterGBufferUsageMask() const;
	float GetSSAOFarDistance() const;
	bool NeedForegroundCoc(float fNear, float fThreshhold);
	void AllocateOcclusionBuffer();
	void FreeOcclusionBuffer();
	void AllocateDepthCoCBuffer();
	void FreeDepthCoCBuffer();
	void DrawBarrelCullMesh(ZRenderContext* pRenderContext);
	static SSkinBlurPtrs GetSkinBlur(const float4& vSkinBlur, const float4& vSkinColor, unsigned int nWidth, unsigned int nHeight);
	static float GaussianDistribution(float x, float y, float fRho, float fAmplitude);
	static void SetGaussianFloat4(float* p, float x, float y, const float4& vRho, const float4& vColor, float alpha);
	void AllocateBuffers();
	void FreeBuffers();
	void BlurUp(SRenderPostfilterContext* pContext, ESourceTexture eSource, unsigned int nSourceIndex, unsigned int nTargetIndex);
	void Blur(SRenderPostfilterContext* pContext, ESourceTexture eSource, unsigned int nSourceIndex, unsigned int nTargetIndex);
	void CombineUpBlur(SRenderPostfilterContext* pContext, ESourceTexture eSource, unsigned int nSourceIndexHighBlur, unsigned int nTargetIndex, float fBlurriness);
	void CombineUp(SRenderPostfilterContext* pContext, ESourceTexture eSource, unsigned int nSourceIndexHighBlur, unsigned int nTargetIndex, float fBlurriness);
	void ScaleUp(SRenderPostfilterContext* pContext, ZRenderShaderResourceView* pSrcSRV);
	void ScaleDown(SRenderPostfilterContext* pContext, ESourceTexture eSource, unsigned int nSourceIndex, unsigned int nTargetIndex);
	void ScaleDownx2(SRenderPostfilterContext* pContext, ESourceTexture eSource, unsigned int nSourceIndex, unsigned int nTargetIndex, ZRenderUtilities::EDownSampleNumSamples eNumSamples);
	void MeasureLuminance(SRenderPostfilterContext* pContext);
	void CalculateAdaptation();
	void RenderGlare(SRenderPostfilterContext* pContext);
	void UpdateColorCorrectionPaletteTexture(SRenderPostfilterContext* pContext);
	void UpdateNoiseTexture();
	void UpdateVertexBuffers();
	void DrawNoiseQuads(ZRenderShader* pShaderF, ZRenderShader* pShaderV, ZRenderConstBufferRef ConstBufferF, ZRenderConstBufferRef ConstBufferV);
	void UpdateScreenDecalBuffer(SRenderPostfilterContext* pContext);
	void FlipTemps(SRenderPostfilterContext* pContext, unsigned int nFlags);
	void ApplyPreprocess(SRenderPostfilterContext* pContext, SRenderGatherContext* pGatherContext, SRenderTexture2DAccess* pOptimizedRadialBlurTempTexture);
	void ApplyPreChainMerge(SRenderPostfilterContext* pContext, SRenderGatherContext* pGatherContext, SRenderTexture2DAccess* pOptimizedRadialBlurTempTexture);
	void ApplyHQDepthOfField(SRenderPostfilterContext* pContext);
	void ApplyPostChainMerge(SRenderPostfilterContext* pContext);
	void ApplyDistortionWobble(SRenderPostfilterContext* pContext);
	void ApplyDoubleVision(SRenderPostfilterContext* pContext);
	void ApplyFog(SRenderPostfilterContext* pContext, SRenderGatherContext* pGatherContext, bool bBeforeTonemap);
	void ScaleUpSniper(SRenderPostfilterContext* pContext, SRenderGatherContext* pGatherContext, float fBlendFactor, ZRenderShaderResourceView* pSrcSRV);
	void DrawSniperMask(SRenderPostfilterContext* pContext, SRenderGatherContext* pGatherContext, unsigned int nWidth, unsigned int nHeight, ZRenderShader* pFragmentShader);
	void ApplyGaussianBlur(SRenderPostfilterContext* pContext, SRenderGatherContext* pGatherContext, float fBlurriness, bool bSniperBlur);
	void ApplyRadialBlur(SRenderPostfilterContext* pContext);
	void CalculateOptimizedRadialBlur(SRenderPostfilterContext* pContext, ZRenderShaderResourceView* pDownScaledBufferSRV, ZRenderTargetView* pDest, ZRenderShaderResourceView* pColorBufferSRV, SRenderTexture2DAccess* pOptimizedRadialBlurTempTexture);
	void ApplySkin(SRenderPostfilterContext* pContext, SRenderGatherContext* pGatherContext, const float4& vSkinBlur, const float4& vSkinColor, float fSkinIntensity, float fSkinScale, bool bSkinFade, float fSkinFadeScale, float fSkinFadeOffset);
	void ApplySpatialBlur(SRenderPostfilterContext* pContext);
	void ApplyVideoEffects(SRenderPostfilterContext* pContext);
	void ApplyFXAA(SRenderPostfilterContext* pContext);
	float CalcTonemapScale();
	void Init(SRenderPostfilterContext& context, ZRenderGraphNodeCamera* pCamera, ZRenderContext* pRenderContext, ZRenderGraphTraversal* pRenderGraphTraversal);
	void ManageDoFComputeBuffers();
	void ReleaseDoFComputeBuffers();
};
