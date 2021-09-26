#pragma once

#include "SGBufferUsingEffectParametersBase.h"
#include "SDeferredLightTechniqueParameters.h"

struct SEffectParametersDeferred : SGBufferUsingEffectParametersBase
{
	enum
	{
		MAX_DEFERRED_LIGHT_TECHNIQUES = 17
	};

	enum
	{
		GLOBAL_LIGHT_PASS_OLD_SSAO = 0,
		GLOBAL_LIGHT_PASS_NEW_SSAO = 1,
		GLOBAL_LIGHT_PASS_OLD_SSAO_OUTSIDE = 2,
		GLOBAL_LIGHT_NUM_PASSES = 3
	};

	enum ELightEffectOffset
	{
		LIGHT_EFFECT_OFFSET_SHADOW = 1,
		LIGHT_EFFECT_OFFSET_PROJECTOR = 2,
		LIGHT_EFFECT_OFFSET_SIMPLE = 4,
		LIGHT_EFFECT_OFFSET_RESTRICT = 8,
		LIGHT_EFFECT_OFFSET_DARK = 16
	};

	SDeferredLightTechniqueParameters m_DeferredLightsParams[3][17][7];
	SDeferredLightTechniqueParameters m_DirLightsWithFadeParams[3][2];
	SDeferredLightTechniqueParameters m_DebugDirectionalCSMParams[3];
	SDeferredLightTechniqueParameters m_DirectionalCSMParams[3][8];
	ZRenderShader* m_pFDeferredClearFB;
	ZRenderShader* m_pVGlobalLight;
	ZRenderShader* m_pFGlobalLight[3];
	unsigned int m_Deferred0_FGlobalLight[3];
	unsigned int m_Deferred1_FGlobalLight[3];
	unsigned int m_Deferred2_FGlobalLight[3];
	unsigned int m_Deferred3_FGlobalLight[3];
	unsigned int m_Occlusion_FGlobalLight[3];
	unsigned int m_Depth_FGlobalLight[3];
	unsigned int m_LightModel_FGlobalLight[3];
	unsigned int m_STLC0_GlobalLightPS[3];
	unsigned int m_GlobalLight_NSSAO_TPC1_PS;
	unsigned int m_GlobalLight_NSSAO_TPC2_PS;
	unsigned int m_GlobalLight_NSSAO_TPC3_PS;
	unsigned int m_GlobalLight_NSSAO_TPC4_PS;
	unsigned int m_GlobalLight_NSSAO_TPC5_PS;
	unsigned long long m_nVGlobalLight_Params0_PS[3];
	unsigned long long m_nVGlobalLight_ParamsPC_PS[3];
	unsigned long long m_nMGlobalLight_ProjectionTI_PS[3];
	unsigned long long m_nVGlobalLight_EyeUpperLeft_VS;
	unsigned long long m_nVGlobalLight_EyeLowerRight_VS;
	unsigned long long m_GlobalLight_NSSAO_Params1_PS;
	unsigned long long m_GlobalLight_NSSAO_Params2_PS;
	unsigned long long m_GlobalLight_NSSAO_Params3_PS;
	bool m_bIsInit;
	bool m_bRebind;
	SEffectResourceLoader m_EffectLoader;

	~SEffectParametersDeferred() override = default;
	void Update(ZRenderEffect* pEffect) override;

	SEffectParametersDeferred() = default;
	void Update(int nMsaa, bool bSampleAll);
	void Init(int nMsaa, bool bSampleAll);
	void RebindEffectResource();
	SDeferredLightTechniqueParameters GetDeferredLightTechniqueParameters(bool bLightCastShadows, unsigned int nLightType, bool bWithFade, bool bProjectorMapEnabled, bool bSimpleLight, bool bDarkLight, bool bLightRestrict, unsigned int nPass, unsigned int nCSMPass);
	void UpdateParamsForShader(SDeferredLightTechniqueParameters& parameters, ZRenderEffect* pEffect, const ZString& sTechnique, unsigned int nPass);
	void SetupLightShaderParams(ZRenderGraphNodeLight::ELightType type, ZRenderEffect* pEffect, unsigned int pass, const char** pszShaderName, const char* pszTrail, int* nLightIndices, int nOffset, int nItems, int nCopyOffset, int nCopyItems);
};
