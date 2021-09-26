#pragma once

#include "SMatrix.h"
#include "ZRenderDevice.h"
#include "ZRenderRainPuddleSimulator.h"
#include "SRenderShadowMapInfo.h"
#include "ZLightPropagationVolume.h"
#include "SRenderShadowMap.h"
#include "IRenderPrimitiveMesh.h"
#include "SEffectParametersInternal.h"
#include "SEffectParametersSimple.h"
#include "SEffectParametersDeferred.h"
#include "SEffectParametersRain.h"
#include "SEffectParametersSkin.h"
#include "SEffectParametersGlow.h"
#include "SEffectParametersPostfilter.h"
#include "SEffectParametersMsaaEdgeDetect.h"
#include "SEffectParametersGlobalIllumination.h"
#include "SEffectParametersDepthOfFieldCS.h"
#include "SEffectParametersBokehCS.h"
#include "SEffectParametersBokehPS.h"
#include "SEffectParametersImageProcessing.h"
#include "SEffectParametersStandardVS.h"
#include "SEffectParametersStandardDecalVS.h"
#include "SEffectParametersStandardScatterVS.h"
#include "SEffectParametersBinkVideo.h"
#include "SEffectParametersFXAA.h"

class ZRenderSharedResources
{
public:
	enum
	{
		MAX_NUM_ENV_MAPS = 4
	};

	enum
	{
		RAIN_SHADOW_MAP_RESOLUTION = 128
	};

	enum
	{
		MAX_NUM_SHADOW_MAPS = 1
	};

	enum
	{
		MAX_NUM_LOW_RES_SHADOW_MAPS = 1
	};

	enum
	{
		MAX_NUM_CUBE_SHADOW_MAPS = 1
	};

	enum
	{
		MAX_NUM_CASCADED_SHADOW_MAPS = 1
	};

	enum
	{
		MAX_NUM_RAIN_SPRITES = 16382
	};

	enum
	{
		NUM_RAIN_PUDDLE_SIMULATORS = 2
	};

	enum
	{
		DITHER_MASK_DEPTH = 16
	};

	enum
	{
		ZRANGE_GRID_NUM_DS_STEPS = 4,
		ZRANGE_MINMAX_GRID_SIZE = 64,
		ZRANGE_UPDATE_SECTOR_SIZE = 4,
		ZRANGE_UPDATE_SECTOR_GRID_SIZE = 16,
		ZRANGE_NUM_DS_TEXTURES = 5,
		ZRANGE_NUM_CELLS = 256
	};

	enum
	{
		SHADOW_INDEX_INVALID = 255
	};

	enum
	{
		DEFAULT_MAX_NUM_SHADOWS_PER_FRAME = 4
	};

	enum
	{
		NUM_SHADOW_MAPS = 4
	};

	enum
	{
		MAX_NUM_PROJECTOR_MAPS = 16
	};

	SMatrix m_mRainShadowMapWorldToRain;
	SMatrix m_mRainShadowMapProjection;
	ZRenderDevice* m_pRenderDevice;
	ZRenderRainPuddleSimulator* m_pRainPuddleSimulator[2];
	ZRenderTexture2D* m_pWhiteTexture;
	ZRenderShaderResourceView* m_pWhiteSRV;
	ZRenderTexture2D* m_pWhiteZeroAlphaTexture;
	ZRenderShaderResourceView* m_pWhiteZeroAlphaSRV;
	ZRenderTexture2D* m_pWhiteCubeTexture;
	ZRenderShaderResourceView* m_pWhiteCubeSRV;
	ZRenderTexture3D* m_pWhiteVolumeTexture;
	ZRenderShaderResourceView* m_pWhiteVolumeSRV;
	ZRenderTexture2D* m_pBlackTexture;
	ZRenderShaderResourceView* m_pBlackSRV;
	ZRenderTexture2D* m_pNormalTexture;
	ZRenderShaderResourceView* m_pNormalSRV;
	ZRenderTexture3D* m_pDitherMaskTexture;
	ZRenderShaderResourceView* m_pDitherMaskSRV;
	ZRenderTexture3D* m_pNoise32Texture;
	ZRenderShaderResourceView* m_pNoise32SRV;
	ZRenderTexture3D* m_pNoise8Texture;
	ZRenderShaderResourceView* m_pNoise8SRV;
	ZRenderTexture2D* m_pNoiseNormalTexture;
	ZRenderShaderResourceView* m_pNoiseNormalSRV;
	unsigned int m_nDitherMaskWidth;
	unsigned int m_nDitherMaskHeight;
	int SHADOW_MAP_RESOLUTION;
	int LOW_RES_SHADOW_MAP_RESOLUTION;
	unsigned int m_nMaxNumShadowMapsPerFrame;
	TArray<SRenderShadowMapInfo> m_aShadowMapInfo;
	ZRenderTexture2D* m_pShadowDepthTexture;
	ZRenderDepthStencilView* m_pShadowDepthDSV;
	ZRenderTexture2D* m_pShadowsTexture[4];
	ZRenderTargetView* m_pShadowsRTV[4];
	ZRenderShaderResourceView* m_pShadowsSRV[4];
	ZRenderShaderResourceView* m_pShadowDepthSRV;
	ZRenderTexture2D* m_pRSMNormalTexture[4];
	ZRenderTargetView* m_pRSMNormalRTV[4];
	ZRenderShaderResourceView* m_pRSMNormalSRV[4];
	ZRenderTexture2D* m_pRSMSmallNormalTexture[4];
	ZRenderTargetView* m_pRSMSmallNormalRTV[4];
	ZRenderShaderResourceView* m_pRSMSmallNormalSRV[4];
	ZRenderTexture2D* m_pRSMDiffuseTexture[4];
	ZRenderTargetView* m_pRSMDiffuseRTV[4];
	ZRenderShaderResourceView* m_pRSMDiffuseSRV[4];
	ZRenderTexture2D* m_pRSMSmallDiffuseTexture[4];
	ZRenderTargetView* m_pRSMSmallDiffuseRTV[4];
	ZRenderShaderResourceView* m_pRSMSmallDiffuseSRV[4];
	ZLightPropagationVolume* m_pLightPropagationVolume;
	bool m_bInitializedRSM;
	SRenderShadowMap m_pShadowMap;
	SRenderTexture2DAccess m_ShadowDSTailTexture[5];
	SRenderTexture2DAccess m_ShadowDSTailTextureTempFix[5];
	ZRenderTexture2D* m_pShadowDSTailTextureDepth;
	ZRenderDepthStencilView* m_pShadowDSTailTextureDSV;
	SRenderTexture2DAccess m_ShadowDSTailTextureCPU[3][2];
	ZRenderTexture2D* m_pLowResShadowDepthTexture;
	ZRenderDepthStencilView* m_pLowResShadowDepthDSV;
	SRenderShadowMap m_pShadowMapsCSM[3];
	ZRenderTexture2D* m_pRainShadowTexture;
	ZRenderTargetView* m_pRainShadowRTV;
	ZRenderShaderResourceView* m_pRainShadowSRV;
	SRenderShadowMap m_RainShadowMap;
	ZRenderTexture2D* m_pProjectorMapRoundTexture[16];
	ZRenderShaderResourceView* m_pProjectorMapRoundSRV[16];
	ZRenderTexture2D* m_pProjectorMapSquareTexture[16];
	ZRenderShaderResourceView* m_pProjectorMapSquareSRV[16];
	ZRenderTexture2D* m_pLightingModelTexture;
	ZRenderShaderResourceView* m_pLightingModelSRV;
	IRenderPrimitiveMesh* m_pPrimitiveSimpleBox;
	IRenderPrimitiveMesh* m_pPrimitiveSimplePyramid;
	IRenderPrimitiveMesh* m_pPrimitiveSimpleIcosahedron;
	IRenderPrimitiveMesh* m_pPrimitiveSimpleCone;
	IRenderPrimitiveMesh* m_pPrimitiveSimpleCylinder;
	IRenderPrimitiveMesh* m_pPrimitiveShadowMapCircleOuter;
	IRenderPrimitiveMesh* m_pPrimitiveShadowMapCircleInner;
	IRenderPrimitiveMesh* m_pPrimitiveCappedPyramid;
	IRenderPrimitive* m_pRainSpriteMesh;
	SEffectParametersInternal m_EffectParametersInternal;
	SEffectParametersSimple m_EffectParametersSimple;
	SEffectParametersDeferred m_EffectParametersDeferred;
	SEffectParametersRain m_EffectParametersRain;
	SEffectParametersSkin m_EffectParametersSkin;
	SEffectParametersGlow m_EffectParametersGlow;
	SEffectParametersPostfilter m_EffectParametersPostfilter;
	SEffectParametersMsaaEdgeDetect m_EffectParametersMsaaEdgeDetect2;
	SEffectParametersMsaaEdgeDetect m_EffectParametersMsaaEdgeDetect4;
	SEffectParametersMsaaEdgeDetect m_EffectParametersMsaaEdgeDetect8;
	SEffectParametersPostfilter m_EffectParametersPostfilterMsaa2;
	SEffectParametersPostfilter m_EffectParametersPostfilterMsaa4;
	SEffectParametersPostfilter m_EffectParametersPostfilterMsaa8;
	SEffectParametersDeferred m_EffectParametersDeferredMsaa2;
	SEffectParametersDeferred m_EffectParametersDeferredMsaa4;
	SEffectParametersDeferred m_EffectParametersDeferredMsaa8;
	SEffectParametersDeferred m_EffectParametersDeferredMsaa2_1;
	SEffectParametersDeferred m_EffectParametersDeferredMsaa4_1;
	SEffectParametersDeferred m_EffectParametersDeferredMsaa8_1;
	SEffectParametersGlobalIllumination m_EffectParametersGlobalIllumination;
	SEffectParametersDepthOfFieldCS m_EffectParametersDepthOfFieldCS;
	SEffectParametersBokehCS m_EffectParametersBokehCS;
	SEffectParametersBokehPS m_EffectParametersBokehPS;
	SEffectParametersImageProcessing m_EffectParametersImageProcessing;
	SEffectParametersStandardVS m_EffectParametersStandardVS;
	SEffectParametersStandardDecalVS m_EffectParametersStandardDecalVS;
	SEffectParametersStandardScatterVS m_EffectParametersStandardScatterVS;
	SEffectParametersBinkVideo m_EffectParametersBinkVideo;
	SEffectParametersFXAA m_EffectParametersFXAA;
	ZResourcePtr m_pPoissonVectorNoise;

	ZRenderSharedResources() = default;
	ZRenderSharedResources(ZRenderDevice* pRenderDevice);
	~ZRenderSharedResources() = default;
	ZRenderShaderResourceView* GetWhiteSRV() const;
	ZRenderShaderResourceView* GetWhiteZeroAlphaSRV() const;
	ZRenderShaderResourceView* GetWhiteCubeSRV() const;
	ZRenderShaderResourceView* GetWhiteVolumeSRV() const;
	ZRenderShaderResourceView* GetBlackSRV() const;
	ZRenderShaderResourceView* GetNormalSRV() const;
	ZRenderShaderResourceView* GetNoise8SRV() const;
	ZRenderShaderResourceView* GetDitherMaskSRV() const;
	ZRenderShaderResourceView* GetPoissonVectorNoiseSRV() const;
	ZRenderTexture2D* GetWhiteTexture() const;
	ZRenderTexture2D* GetBlackTexture() const;
	IRenderPrimitive* GetRainSpriteMesh() const;
	bool RainUpdated(const SMatrix& mWorldToRain, const SMatrix& mProjection);
	void AllocateRainMesh();
	void FreeRainMesh();
	unsigned int GetDitherMaskWidth() const;
	unsigned int GetDitherMaskHeight() const;
	ZRenderShaderResourceView* GetLightProjectorMap(float fHotSpotPct, bool bSquare) const;
	SRenderShadowMap* GetShadowMap2D();
	SRenderShadowMap* GetShadowMapCSM(unsigned int nSplit);
	SRenderTexture2DAccess* GetShadowDSTail(unsigned int nIndex);
	SRenderTexture2DAccess* GetShadowDSTailTempFix(unsigned int nIndex);
	SRenderTexture2DAccess* GetShadowDSTailCPU(unsigned int nFrameIndex, unsigned int nIndex);
	ZRenderDepthStencilView* GetShadowDSTailDSV() const;
	SRenderShadowMapInfo* GetShadowMapInfo(unsigned int nIndex);
	unsigned char TryAllocShadowInfo(void* pOwner);
	void FreeUnusedShadowMaps();
	SRenderShadowMap* GetRainShadowMap2D();
	ZLightPropagationVolume* GetLightPropagationVolume();
	bool LPVReadyForUse();
	ZRenderRainPuddleSimulator* GetRainPuddleSimulator(int nIndex);
	IRenderPrimitiveMesh* GetPrimitiveSimpleBox() const;
	IRenderPrimitiveMesh* GetPrimitiveSimplePyramid() const;
	IRenderPrimitiveMesh* GetPrimitiveSimpleIcosahedron() const;
	IRenderPrimitiveMesh* GetPrimitiveSimpleCone() const;
	IRenderPrimitiveMesh* GetPrimitiveSimpleCylinder() const;
	IRenderPrimitiveMesh* GetPrimitiveShadowMapCircleOuter() const;
	IRenderPrimitiveMesh* GetPrimitiveShadowMapCircleInner() const;
	IRenderPrimitiveMesh* GetPrimitiveCappedPyramid() const;
	ZRenderShaderResourceView* GetLightingModelSRV() const;
	SEffectParametersInternal& GetEffectParametersInternal();
	SEffectParametersSimple& GetEffectParametersSimple();
	SEffectParametersDeferred& GetEffectParametersDeferred();
	SEffectParametersPostfilter& GetEffectParametersPostfilter();
	SEffectParametersRain& GetEffectParametersRain();
	SEffectParametersSkin& GetEffectParametersSkin();
	SEffectParametersGlow& GetEffectParametersGlow();
	SEffectParametersDeferred& GetEffectParametersDeferredMsaa2();
	SEffectParametersDeferred& GetEffectParametersDeferredMsaa4();
	SEffectParametersDeferred& GetEffectParametersDeferredMsaa8();
	SEffectParametersDeferred& GetEffectParametersDeferredMsaa2_1();
	SEffectParametersDeferred& GetEffectParametersDeferredMsaa4_1();
	SEffectParametersDeferred& GetEffectParametersDeferredMsaa8_1();
	SEffectParametersMsaaEdgeDetect& GetEffectParametersMsaaEdgeDetect2();
	SEffectParametersMsaaEdgeDetect& GetEffectParametersMsaaEdgeDetect4();
	SEffectParametersMsaaEdgeDetect& GetEffectParametersMsaaEdgeDetect8();
	SEffectParametersGlobalIllumination& GetEffectParametersGlobalIllumination();
	SEffectParametersDepthOfFieldCS& GetEffectParametersDepthOfFieldCS();
	SEffectParametersBokehCS& GetEffectParametersBokehCS();
	SEffectParametersBokehPS& GetEffectParametersBokehPS();
	SEffectParametersImageProcessing& GetEffectParametersImageProcessing();
	SEffectParametersStandardVS& GetEffectParametersStandardVS();
	SEffectParametersStandardDecalVS& GetEffectParametersStandardDecalVS();
	SEffectParametersStandardScatterVS& GetEffectParametersStandardScatterVS();
	SEffectParametersBinkVideo& GetEffectParametersBinkVideo();
	SEffectParametersFXAA& GetEffectParametersFXAA();
	void RebindEffectParameters();
	void CheckConfigSettings();
	void UpdateShadowMaps(const int nResolution, const bool bReflectiveMaps);
	const int GetShadowMapResolution() const;
	const int GetLowResShadowMapResolution() const;
	bool IsShadowMapIndexValid(unsigned int nShadowMapIndex);
	void SetMaxNumShadowMapsPerFrame(unsigned int nNumShadowMaps);
	const unsigned int GetMaxNumShadowMapsPerFrame() const;
	void Allocate();
	void ResetShadowInformation();
	void ForceShadowFadeDone();
	void Free();
	void InitializeShadowInformation(unsigned int nMaxNumShadowMapsPerFrame);
	void UninitializeShadowInformation();
	void InitializeShadowBuffers(const bool bCreateReflectiveMaps);
	void UninitializeShadowBuffers();
	void InitializeLightPropagationVolume();
	void UninitializeLightPropagationVolume();
	void CreateBlackAndWhiteTextures();
};
